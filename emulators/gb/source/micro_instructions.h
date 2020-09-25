#ifndef BOLT_GB_MICRO_INSTRUCTIONS_H_
#define BOLT_GB_MICRO_INSTRUCTIONS_H_

#pragma once

#include "cpu.h"
#include "micro_instruction_types.h"

#include <array>
#include <cassert>

namespace bolt {
    using gb_micro_instruction_fn = void(*)(gb_cpu::gb_register_bus *, gb_bus *);

    template<gb_micro_instruction_type>
    void gb_micro_instruction(gb_cpu::gb_register_bus *register_bus, gb_bus *bus) {
        
        static_assert(false, "template<gb_micro_instruction_type> void gb_micro_instruction(gb_cpu *, gb_bus *) must have an explicit specialization!");
                             
    }
    
#define GB_MICRO_INSTRUCTION(instruction) \
    gb_micro_instruction<instruction>

#define GB_MICRO_INSTRUCTION_PROTOTYPE(instruction)     \
    template<>                                          \
    void GB_MICRO_INSTRUCTION(instruction)(gb_cpu::gb_register_bus *register_bus, gb_bus *peripheral_bus)

#define GB_MICRO_INSTRUCTION_DEFINITION(instruction)    \
    template<>                                          \
    void GB_MICRO_INSTRUCTION(instruction)(gb_cpu::gb_register_bus *register_bus, gb_bus *peripheral_bus)
  
    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::not_implemented);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::internal_delay);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::decode_pc);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::fetch_pch);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::fetch_pcl);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::push_pch);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::push_pcl);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::pop_pch);

    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::pop_pcl);
}

#endif