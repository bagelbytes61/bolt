#include "decoder.hh"

#include "tstate.hh"

#include <array>
#include <cassert>
#include <iostream>
#include <string>

using namespace bolt;

auto gb_decoder::clk(gb_control_signals &ctrl_signals, uint64_t cycle) -> void {
    const word_t opcode = ir;

    //std::cout << cycle << std::endl;

    if (cycle % ((1 << 20) * 4) == 0) {
        //std::cout << "4.something Million Cycles" << std::endl;
    }

    switch (opcode) {
        case 0x00: /* NOP */
            ctrl_signals.nop_00h = 1;
            break;
        case 0x36: /* LD (HL),n */
            break;
        case 0x0a: /* LD A,(BC) */
            break;
        case 0x1a: /* LD A,(DE) */
            break;
        case 0x3a: /* LD A,(nn) */
            break;
        case 0x02: /* LD (BC),A */
            break;
        case 0x12: /* LD (DE),A */
            break;
        case 0x32: /* LD (nn),A */ 
            break;
        case 0xc3: /* JP nn*/
            ctrl_signals.jp_nn_c3h = 1;
            break;
        default:
            if ((opcode & 0x70) == 0x70) {  /*LD r,(HL) */
                const auto src = opcode & 7;

                //std::cout << "src: " << register_name(src) << std::endl;
            } else if ((opcode & 0x06) == 0x06) { /* LD r,n */
                const auto dst = opcode >> 3 & 7;

                //std::cout << "dst: " << register_name(dst) << std::endl;

                //ctrl_signals.reg_select = dst;
                //ctrl_signals.flags = gb_control_signal_flags::reg_en_wr;
            } else if ((opcode & 0x40) == 0x40) { /* LD r,r'*/
                const auto src = opcode & 7;
                const auto dst = opcode >> 3 & 7;

                //std::cout << "src: " << register_name(src) << std::endl;
                //std::cout << "dst: " << register_name(dst) << std::endl;
            } else if ((opcode & 0x46) == 0x46) { /* LD (HL),r */
                const auto dst = opcode >> 3 & 7;

                //std::cout << "dst: " << register_name(dst) << std::endl;
            } else { 
                std::puts("!!!INSTRUCTION NOT IMPLEMENTED!!!");
                //std::printf("PC: %#06x\n", tstate.addr_bus);
                //std::printf("Instruction: %#04x\n", tstate.data_bus);
                std::abort();
            }
    }

    //ctrl_signals.m1 = 1;
 }

gb_control_unit::gb_control_unit()
    : is_fetch_cycle(true) {

}

auto gb_control_unit::clk(gb_control_signals &ctrl_signals, uint64_t cycle, gb_clock_state state) -> void {
    static int k = 0;
    
    if (is_fetch_cycle) {
        switch ((cycle - k) % 4u) {
            case 0:
                if (state == gb_clock_state::rising) {
                    ctrl_signals.m1 = 1;
                } else if (state == gb_clock_state::falling) {
                    ctrl_signals.mreq = 1;
                    ctrl_signals.rd = 1;
                    ctrl_signals.en_wz_rd_addr_bus = 0;
                    ctrl_signals.en_pc_rd_addr_bus = 0;
                    ctrl_signals.en_idu_inc_pc = 1;
                } else {
                    if (ctrl_signals.en_wz_rd_addr_bus == 0) {
                        ctrl_signals.en_pc_rd_addr_bus = 1;
                    }
                }
                break;
            case 1:
                ctrl_signals.en_idu_inc_pc = 0;
                break;
            case 2:
                if (state == gb_clock_state::rising) {
                    ctrl_signals.m1 = 0;
                    ctrl_signals.mreq = 0;
                    ctrl_signals.rd = 0;
                } else if (state == gb_clock_state::falling) {
                    ctrl_signals.en_ir_wr = 1;
                    ctrl_signals.en_ir_rd_decoder = 1;
                }
                break;
            case 3:
                ctrl_signals.en_z_wr = 0;
                ctrl_signals.en_w_wr = 0;
                ctrl_signals.en_ir_wr = 0;
                ctrl_signals.en_ir_rd_decoder = 0;
                is_fetch_cycle = false;
                is_exec_cycle = true;
                break;
            default:
                break;
        }
    }

    if (is_exec_cycle) { 
        if (ctrl_signals.nop_00h) {
            k = cycle + 1u;

            if (state == gb_clock_state::falling) {
                ctrl_signals.nop_00h = 0;
                is_fetch_cycle = true;
                is_exec_cycle = false;
            }
            //if (half_cycle) {
                //is_fetch_cycle = true;
                //is_exec_cycle = false;
            //}
        } else if (ctrl_signals.jp_nn_c3h) {
            switch ((cycle - k) % gb_control_signals::k) {
                case 4:
                    if (state == gb_clock_state::rising) {

                    } else if (state == gb_clock_state::falling) {
                        ctrl_signals.mreq = 1;
                        ctrl_signals.rd = 1;
                        ctrl_signals.en_pc_rd_addr_bus = 0;
                        ctrl_signals.en_idu_inc_pc = 1;

                    } else {
                        ctrl_signals.en_pc_rd_addr_bus = 1;
                    }
                    //if (half_cycle) {
                        //ctrl_signals.en_idu_inc_pc = 1;
                    //} else {
                        //ctrl_signals.en_pc_rd_addr_bus = 1;
                    //}
                    break;
                case 5:
                    ctrl_signals.en_idu_inc_pc = 0;
                    break;
                case 6:
                    if (state == gb_clock_state::falling) {
                        ctrl_signals.en_z_wr = 1;
                    }
                    break;
                case 7:
                    ctrl_signals.en_z_wr = 0;
                    break;
                case 8:
                    if (state == gb_clock_state::rising) {

                    } else if (state == gb_clock_state::falling) {
                        ctrl_signals.mreq = 1;
                        ctrl_signals.rd = 1;
                        ctrl_signals.en_pc_rd_addr_bus = 0;
                        ctrl_signals.en_idu_inc_pc = 1;

                    } else {
                        ctrl_signals.en_pc_rd_addr_bus = 1;
                    }
                    break;
                case 9:
                    ctrl_signals.en_idu_inc_pc = 0;
                    break;
                case 10:
                    if (state == gb_clock_state::falling) {
                        ctrl_signals.en_w_wr = 1;
                    }
                    break;
                case 11:
                    ctrl_signals.en_w_wr = 0;
                    if (state == gb_clock_state::falling) {
                        k = cycle + 1u;
                        ctrl_signals.en_wz_rd_addr_bus = 1;
                        ctrl_signals.jp_nn_c3h = 0;
                        is_fetch_cycle = true;
                        is_exec_cycle = false;
                    }
                    break;
                default:
                    break;
            }
        }
    }

    return;
}