#ifndef BOLT_GB_INSTRUCTION_TABLE_H_
#define BOLT_GB_INSTRUCTION_TABLE_H_

#pragma once

#include "alu.h"
#include "instruction_encoding.h"
#include "micro_instructions.h"

#include <array>
#include <cstdint>

namespace bolt {
#define GB_INSTRUCTION_NOP_00h (0x00)
#define GB_INSTRUCTION_JP_c3h  (0xc3)
#define GB_INSTRUCTION_XOR_afh (0xaf)

    constexpr std::array<uint64_t, 0xff> gb_generate_instr_encode_table() {
        std::array<uint64_t, 0xff> table = {};

        table[GB_INSTRUCTION_NOP_00h] = GB_ENCODE_MICRO_INSTR_SEQU_LEN(1) |
            GB_ENCODE_MICRO_INSTR_SEQU_1(GB_MICRO_INSTR_DECODE_PC) |
            GB_ENCODE_ALU_OP(GB_ALU_OP_NOP) |
            GB_ENCODE_INSTR_UPDATE_PC(1) | 
            GB_ENCODE_INSTR_LEN(1) |
            GB_INSTRUCTION_NOP_00h;
        table[GB_INSTRUCTION_JP_c3h] = GB_ENCODE_MICRO_INSTR_SEQU_LEN(4) |
            GB_ENCODE_MICRO_INSTR_SEQU_1(GB_MICRO_INSTR_FETCH_PCL) |
            GB_ENCODE_MICRO_INSTR_SEQU_2(GB_MICRO_INSTR_FETCH_PCH) |
            GB_ENCODE_MICRO_INSTR_SEQU_3(GB_MICRO_INSTR_INTERNAL_DELAY) |
            GB_ENCODE_MICRO_INSTR_SEQU_4(GB_MICRO_INSTR_DECODE_PC) |
            GB_ENCODE_ALU_OP(GB_ALU_OP_NOP) |
            GB_ENCODE_INSTR_UPDATE_PC(0) | 
            GB_ENCODE_INSTR_LEN(4) |
            GB_INSTRUCTION_JP_c3h;
        table[GB_INSTRUCTION_XOR_afh] = GB_ENCODE_MICRO_INSTR_SEQU_LEN(1) |
            GB_ENCODE_MICRO_INSTR_SEQU_1(GB_MICRO_INSTR_DECODE_PC) |
            GB_ENCODE_ALU_OP(GB_ALU_OP_XOR) |
            GB_ENCODE_INSTR_UPDATE_PC(1) | 
            GB_ENCODE_INSTR_LEN(1) |
            GB_INSTRUCTION_XOR_afh;

        return table;
    }

    inline constexpr std::array<uint64_t, 0xff> gb_instr_table = gb_generate_instr_encode_table();
}

#endif