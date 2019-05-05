#ifndef BOLT_INSTRUCTION_H_
#define BOLT_INSTRUCTION_H_

#pragma once

#include "addressing_mode.h"
#include "instruction_meta_data.h"

namespace bolt {
    class nes_cpu;

    template<uint8_t opcode>
    class nes_instruction {
    public:
        static constexpr size_t bytes = nes_instruction_meta_data<opcode>::get_bytes();
        static constexpr size_t cycles = nes_instruction_meta_data<opcode>::get_cycles();
    };
}

#endif