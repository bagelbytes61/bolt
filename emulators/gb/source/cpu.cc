#include "cpu.hh"

#include "alu.h"
#include "cartridge.h"
#include "instruction.hh"
#include "micro_instruction_table.h"

#include <iostream>

using namespace bolt;

constexpr std::array<gb_micro_instruction_fn, 0xffu> gb_micro_instruction_table = gb_generate_micro_instr_jump_table();

//static void print_ir(gb_instruction_register_t ir) {
    //std::printf("Micro instruction sequence length: %llu\n", GB_DECODE_MICRO_INSTR_SEQU_LEN(ir));
    //std::printf("Micro instruction sequence 5: %llu\n", GB_DECODE_MICRO_INSTR_SEQU_5(ir));
    //std::printf("Micro instruction sequence 4: %llu\n", GB_DECODE_MICRO_INSTR_SEQU_4(ir));
    //std::printf("Micro instruction sequence 3: %llu\n", GB_DECODE_MICRO_INSTR_SEQU_3(ir));
    //std::printf("Micro instruction sequence 2: %llu\n", GB_DECODE_MICRO_INSTR_SEQU_2(ir));
    //std::printf("Micro instruction sequence 1: %llu\n", GB_DECODE_MICRO_INSTR_SEQU_1(ir));
    //std::printf("Micro instruction sequence position: %llu\n", GB_DECODE_MICRO_INSTR_SEQU_POS(ir));
//}

gb_cpu::gb_cpu(gb_cartridge &cartridge)
    : decoder(bus.get_data_bus())
    , register_file(bus.get_address_bus(), bus.get_data_bus())
    , idu(register_file)
    , control_signals({ }) {

    bus.register_memory_region(&cartridge, gb_cartridge::addr_range);

    /* Fetch the initial instruction */

    //control_signals.m1 = 1;
    //control_signals.mreq = 1;
    //control_signals.rd = 1;

    //tstate.addr_bus = 0x100;
    //tstate.m1 = 1;
    //tstate.mreq = 1;
    //tstate.wr = 1;
}

gb_cpu::~gb_cpu() {
    
}

auto gb_cpu::clk(uint64_t cycle, gb_clock_state state) -> void {
    //std::cout << "clk: " << cycle << std::endl;

    //std::cout << "addr bus=" << bus.get_address_bus() << std::endl;
    //std::cout << "data bus=" << int(bus.get_data_bus()) << std::endl;

    control_unit.clk(control_signals, cycle, state);

    if (control_signals.en_ir_rd_decoder) {
        decoder.clk(control_signals, cycle);
    }

    bus.clk(control_signals, cycle);

    idu.clk(control_signals, cycle);

    register_file.update(control_signals);
}

 //const auto micro_instr_sequ_pos = gb_instr_micro_instr_sequ_pos(ir);

 //const auto micro_instr_sequ = gb_instr_micro_instr_sequ(ir, micro_instr_sequ_pos);

 //const auto micro_instr = gb_micro_instruction_table.at(micro_instr_sequ);

 //tstate = micro_instr(&register_file, bus.get(), nullptr, tstate);