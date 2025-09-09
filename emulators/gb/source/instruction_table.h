#ifndef BOLT_GB_INSTRUCTION_TABLE_H_
#define BOLT_GB_INSTRUCTION_TABLE_H_

#pragma once

#include "alu_operation_types.h"
#include "instruction.hh"

#include <array>
#include <cstdint>

namespace bolt {
    inline constexpr auto gb_generate_instr_encode_table(void) -> std::array<gb_instruction_t, 0xff> {
       std::array<gb_instruction_t, 0xffu> instr_encode_table = {};

       gb_instruction_builder instr_builder;
        
       ///* NOP */
       // instr_encode_table[0x00] = instr_builder
       //     .encode_micro_instr_sequ(1u, gb_micro_instruction_type::fetch)
       //     .encode_micro_instr_sequ(2u, gb_micro_instruction_type::decode)
       //     .encode_opcode(0x00)
       //     .encode_update_pc(true)
       //     .encode_length(1u)
       //     .build();
       // /* DEC B */
       // instr_encode_table[0x05] = instr_builder
       //     .encode_micro_instr_sequ(1u, gb_micro_instruction_type::fetch)
       //     .encode_opcode(0x05)
       //     .encode_update_pc(true)
       //     .encode_length(1u)
       //     .encode_source(gb_instruction_operand_type::b)
       //     .encode_destination(gb_instruction_operand_type::b)
       //     .encode_alu_operation(gb_alu_op_type::_dec)
       //     .build();
       // /* DEC D */
       // instr_encode_table[0x0d] = instr_builder
       //     .encode_micro_instr_sequ(1u, gb_micro_instruction_type::fetch)
       //     .encode_opcode(0x0d)
       //     .encode_update_pc(true)
       //     .encode_length(1u)
       //     .encode_source(gb_instruction_operand_type::d)
       //     .encode_destination(gb_instruction_operand_type::d)
       //     .encode_alu_operation(gb_alu_op_type::_dec)
       //     .build();
       // /* LD H,B */
       // instr_encode_table[0x06] = instr_builder
       //     .encode_micro_instr_sequ(1u, gb_micro_instruction_type::load_msb)
       //     .encode_micro_instr_sequ(2u, gb_micro_instruction_type::fetch)
       //     .encode_opcode(0x06)
       //     .encode_update_pc(true)
       //     .encode_length(1u)
       //     .encode_source(gb_instruction_operand_type::h)
       //     .encode_destination(gb_instruction_operand_type::d)
       //     .build();
       // /* LDH C,d8 */
       // instr_encode_table[0x0e] = instr_builder
       //     .encode_micro_instr_sequ(1u, gb_micro_instruction_type::load_lsb)
       //     .encode_micro_instr_sequ(2u, gb_micro_instruction_type::fetch)
       //     .encode_opcode(0x0e)
       //     .encode_update_pc(true)
       //     .encode_length(2u)
       //     .encode_destination(gb_instruction_operand_type::c)
       //     .encode_source(gb_instruction_operand_type::d8)
       //     .build();
       // /* RRCA */
       // instr_encode_table[0x0f] = instr_builder
       //     .encode_micro_instr_sequ(1u, gb_micro_instruction_type::fetch)
       //     .encode_opcode(0x0f)
       //     .encode_update_pc(true)
       //     .encode_length(1u)
       //     .encode_source(gb_instruction_operand_type::a)
       //     .encode_destination(gb_instruction_operand_type::a)
       //     .encode_alu_operation(gb_alu_op_type::_rrca)
       //     .build();
       // /* INC D */
       // instr_encode_table[0x14] = instr_builder
       //     .encode_micro_instr_sequ(1u, gb_micro_instruction_type::fetch)
       //     .encode_opcode(0x14)
       //     .encode_update_pc(true)
       //     .encode_length(1u)
       //     .encode_alu_operation(gb_alu_op_type::_inc)
       //     .encode_source(gb_instruction_operand_type::d)
       //     .build();
       // /* JR NZ,r8 */
       // instr_encode_table[0x20] = instr_builder
       //     .encode_micro_instr_sequ(1u, gb_micro_instruction_type::jump_rel)
       //     .encode_micro_instr_sequ(2u, gb_micro_instruction_type::internal_delay)
       //     .encode_micro_instr_sequ(3u, gb_micro_instruction_type::fetch)
       //     .encode_opcode(0x20)
       //     .encode_update_pc(true)
       //     .encode_length(2u)
       //     .encode_cc(gb_instruction_cc::nz)
       //     .build();
       // /* LD HL,d16 */
       // instr_encode_table[0x21] = instr_builder
       //     .encode_micro_instr_sequ(1u, gb_micro_instruction_type::load_lsb)
       //     .encode_micro_instr_sequ(2u, gb_micro_instruction_type::load_msb)
       //     .encode_micro_instr_sequ(3u, gb_micro_instruction_type::fetch)
       //     .encode_opcode(0x21)
       //     .encode_update_pc(true)
       //     .encode_length(3u)
       //     .encode_source(gb_instruction_operand_type::d16)
       //     .encode_destination(gb_instruction_operand_type::hl)
       //     .build();
       // /* LD (HL-),A */
       // instr_encode_table[0x32] = instr_builder
       //     .encode_micro_instr_sequ(1u, gb_micro_instruction_type::load_msb)
       //     .encode_micro_instr_sequ(2u, gb_micro_instruction_type::decrement)
       //     .encode_micro_instr_sequ(3u, gb_micro_instruction_type::fetch)
       //     .encode_opcode(0x32)
       //     .encode_update_pc(true)
       //     .encode_length(1u)
       //     .encode_source(gb_instruction_operand_type::a)
       //     .encode_destination(gb_instruction_operand_type::hl | gb_instruction_operand_flag::indirect)
       //     .build();
       // /* LD A,d8 */
       // instr_encode_table[0x3e] = instr_builder
       //     .encode_micro_instr_sequ(1u, gb_micro_instruction_type::load_msb)
       //     .encode_micro_instr_sequ(2u, gb_micro_instruction_type::fetch)
       //     .encode_opcode(0x3e)
       //     .encode_update_pc(true)
       //     .encode_length(2u)
       //     .encode_source(gb_instruction_operand_type::d8)
       //     .encode_destination(gb_instruction_operand_type::a)
       //     .build();
       // /* LD B,d8 */
       // instr_encode_table[0x60] = instr_builder
       //     .encode_micro_instr_sequ(1u, gb_micro_instruction_type::load_lsb)
       //     .encode_opcode(0x60)
       //     .encode_update_pc(true)
       //     .encode_length(1u)
       //     .encode_source(gb_instruction_operand_type::d8)
       //     .encode_destination(gb_instruction_operand_type::b)
       //     .build();
       // /* JP a16 */
       // instr_encode_table[0xc3] = instr_builder
       //    .encode_micro_instr_sequ(1u, gb_micro_instruction_type::fetch_pcl)
       //    .encode_micro_instr_sequ(2u, gb_micro_instruction_type::fetch_pch)
       //    .encode_micro_instr_sequ(3u, gb_micro_instruction_type::internal_delay)
       //    .encode_micro_instr_sequ(4u, gb_micro_instruction_type::fetch)
       //    .encode_opcode(0xc3)
       //    .encode_update_pc(false)
       //    .encode_length(3u)
       //    .build();
       // /* XOR A */
       // instr_encode_table[0xaf] = instr_builder
       //    .encode_micro_instr_sequ(1u, gb_micro_instruction_type::fetch)
       //    .encode_opcode(0xaf)
       //    .encode_update_pc(true) 
       //    .encode_length(1u)
       //    .encode_source(gb_instruction_operand_type::a)
       //    .encode_destination(gb_instruction_operand_type::a)
       //    .encode_alu_operation(gb_alu_op_type::_xor)
       //    .build();
       // /* LDH (a8),A */
       // instr_encode_table[0xe0] = instr_builder
       //     .encode_micro_instr_sequ(1u, gb_micro_instruction_type::load_lsb)
       //     .encode_micro_instr_sequ(2u, gb_micro_instruction_type::store_lsb)
       //     .encode_micro_instr_sequ(3u, gb_micro_instruction_type::fetch)
       //     .encode_opcode(0xe0)
       //     .encode_update_pc(true)
       //     .encode_length(2u)
       //     .encode_source(gb_instruction_operand_type::a)
       //     .encode_destination(gb_instruction_operand_type::a8)
       //     .build();
       // /* LDH A,(a8) */
       // instr_encode_table[0xf0] = instr_builder
       //     .encode_micro_instr_sequ(1u, gb_micro_instruction_type::fetch)
       //     .encode_opcode(0xf0)
       //     .encode_update_pc(true)
       //     .encode_length(2u)
       //     .encode_source(gb_instruction_operand_type::a8)
       //     .encode_destination(gb_instruction_operand_type::a)
       //     .build();
       // /* DI */
       // instr_encode_table[0xf3] = instr_builder
       //     .encode_micro_instr_sequ(1u, gb_micro_instruction_type::fetch)
       //     .encode_opcode(0xf3)
       //     .encode_update_pc(true)
       //     .encode_length(1u)
       //     .build();

       return instr_encode_table;
    }

    //inline constexpr std::array<uint64_t, 0xff> gb_instr_table = gb_generate_instr_encode_table();
}

#endif