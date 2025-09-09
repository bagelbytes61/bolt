#ifndef BOLT_GB_MICRO_INSTRUCTIONS_H_
#define BOLT_GB_MICRO_INSTRUCTIONS_H_

#pragma once

#include "cpu.hh"
#include "micro_instruction_types.h"

#include <array>
#include <cassert>

namespace bolt {
    class gb_alu;

    using gb_micro_instruction_fn = gb_tstate(*)(gb_register_file *, gb_bus *, gb_alu *, const gb_tstate &);

    template<gb_micro_instruction_type>
    auto gb_micro_instruction(gb_register_file *, gb_bus *, gb_alu *, const gb_tstate &) -> gb_tstate {
        static_assert(false, "template<gb_micro_instruction_type> void gb_micro_instruction(gb_cpu *, gb_bus *) must have an explicit specialization!");
    
        return { };
    }
    
#define GB_MICRO_INSTRUCTION(instruction) \
    gb_micro_instruction<instruction>

#define GB_MICRO_INSTRUCTION_PROTOTYPE(instruction)     \
    template<>                                          \
    auto GB_MICRO_INSTRUCTION(instruction)(gb_register_file * reg_file, gb_bus *bus, gb_alu *alu, const gb_tstate &tstate) -> gb_tstate

#define GB_MICRO_INSTRUCTION_DEFINITION(instruction)    \
    template<>                                          \
    auto GB_MICRO_INSTRUCTION(instruction)(gb_register_file *reg_file, gb_bus *bus, gb_alu *alu, const gb_tstate &tstate) -> gb_tstate
  
    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::not_implemented);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::internal_delay);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::fetch);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::decode);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::fetch_pch);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::fetch_pcl);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::push_pch);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::push_pcl);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::pop_pch);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::pop_pcl);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::load_msb);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::load_lsb);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::store_msb);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::store_lsb);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::jump_rel);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::increment);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::decrement);
}

#endif