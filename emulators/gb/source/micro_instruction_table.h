#ifndef BOLT_GB_MICRO_INSTRUCTION_TABLE_H_
#define BOLT_GB_MICRO_INSTRUCTION_TABLE_H_

#pragma once

#include "micro_instructions.h"

#include <array>

namespace bolt {
    constexpr std::array<gb_micro_instruction_fn, 0xffu> gb_generate_micro_instr_jump_table() {
        std::array<gb_micro_instruction_fn, 0xffu> micro_instr_jump_table = {};
        
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::not_implemented)] = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::not_implemented);
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::internal_delay)]  = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::internal_delay);
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::decode)]       = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::decode);
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::fetch_pch)]       = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::fetch_pch);
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::fetch_pcl)]       = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::fetch_pcl);
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::push_pch)]        = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::push_pch);
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::push_pcl)]        = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::push_pcl);
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::pop_pch)]         = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::pop_pch);
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::pop_pcl)]         = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::pop_pcl);
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::load_msb)]        = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::load_msb);
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::load_lsb)]        = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::load_lsb);
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::store_msb)]       = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::store_msb);
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::store_lsb)]       = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::store_lsb);
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::jump_rel)]        = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::jump_rel);
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::decrement)]       = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::decrement);
        micro_instr_jump_table[static_cast<size_t>(gb_micro_instruction_type::increment)]       = &GB_MICRO_INSTRUCTION(gb_micro_instruction_type::increment);

        return micro_instr_jump_table;
    }
}

#endif