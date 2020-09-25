#ifndef BOLT_GB_INSTRUCTION_TABLE_H_
#define BOLT_GB_INSTRUCTION_TABLE_H_

#pragma once

#include "alu_operation_types.h"
#include "instruction.h"

#include <array>
#include <cstdint>

namespace bolt {
    static constexpr uint8_t gb_instruction_nop_00h = 0x00u;
    static constexpr uint8_t gb_instruction_xor_afh = 0xafu;
    static constexpr uint8_t gb_instruction_jp_c3h = 0xc3u;

    auto gb_generate_instr_encode_table(void)->std::array<gb_instruction_t, 0xffu>{
       std::array<uint64_t, 0xffu> instr_encode_table = {};

       gb_instruction_builder instr_builder;

       instr_encode_table[gb_instruction_nop_00h] = instr_builder
           .encode_micro_instr_sequ_len(1u)
           .encode_micro_instr_sequ(1u, gb_micro_instruction_type::decode_pc)
           .encode_opcode(gb_instruction_nop_00h)
           .encode_update_pc(true)
           .encode_length(1u)
           .build();

       instr_encode_table[gb_instruction_jp_c3h] = instr_builder
           .encode_micro_instr_sequ_len(4u)
           .encode_micro_instr_sequ(1u, gb_micro_instruction_type::fetch_pcl)
           .encode_micro_instr_sequ(2u, gb_micro_instruction_type::fetch_pch)
           .encode_micro_instr_sequ(3u, gb_micro_instruction_type::internal_delay)
           .encode_micro_instr_sequ(4u, gb_micro_instruction_type::decode_pc)
           .encode_opcode(gb_instruction_jp_c3h)
           .encode_update_pc(false)
           .encode_length(4u)
           .encode_cc(gb_instruction_cc::none)
           .build();

       instr_encode_table[gb_instruction_xor_afh] = instr_builder
           .encode_micro_instr_sequ_len(1u)
           .encode_micro_instr_sequ(1u, gb_micro_instruction_type::decode_pc)
           .encode_opcode(gb_instruction_xor_afh)
           .encode_update_pc(true)
           .encode_length(1u)
           .encode_source(gb_instruction_register_type::direct_a)
           .encode_destination(gb_instruction_register_type::direct_a)
           .encode_alu_operation(gb_alu_operation_type::_xor)
           .build();

       return instr_encode_table;
    }

    //inline constexpr std::array<uint64_t, 0xff> gb_instr_table = gb_generate_instr_encode_table();
}

#endif