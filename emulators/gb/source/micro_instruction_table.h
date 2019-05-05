#ifndef BOLT_GB_MICRO_INSTRUCTION_TABLE_H_
#define BOLT_GB_MICRO_INSTRUCTION_TABLE_H_

#pragma once

#include "micro_instructions.h"

#include <array>

namespace bolt {
    constexpr std::array<gb_micro_instruction_fn, 0xff> gb_generate_micro_instr_jump_table() {
        std::array<gb_micro_instruction_fn, 0xff> table = {};
        
        table[GB_MICRO_INSTR_NOT_IMPL]       = &GB_MICRO_INSTR(GB_MICRO_INSTR_NOT_IMPL);
        table[GB_MICRO_INSTR_INTERNAL_DELAY] = &GB_MICRO_INSTR(GB_MICRO_INSTR_INTERNAL_DELAY);
        table[GB_MICRO_INSTR_DECODE_PC]      = &GB_MICRO_INSTR(GB_MICRO_INSTR_DECODE_PC);
        table[GB_MICRO_INSTR_FETCH_PCH]      = &GB_MICRO_INSTR(GB_MICRO_INSTR_FETCH_PCH);
        table[GB_MICRO_INSTR_FETCH_PCL]      = &GB_MICRO_INSTR(GB_MICRO_INSTR_FETCH_PCL);
        table[GB_MICRO_INSTR_PUSH_PCH]       = &GB_MICRO_INSTR(GB_MICRO_INSTR_PUSH_PCH);
        table[GB_MICRO_INSTR_PUSH_PCL]       = &GB_MICRO_INSTR(GB_MICRO_INSTR_PUSH_PCL);
        table[GB_MICRO_INSTR_POP_PCH]        = &GB_MICRO_INSTR(GB_MICRO_INSTR_POP_PCH);
        table[GB_MICRO_INSTR_POP_PCL]        = &GB_MICRO_INSTR(GB_MICRO_INSTR_POP_PCL);

        return table;
    }
}

#endif