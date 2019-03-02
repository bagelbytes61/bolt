#ifndef BOLT_INSTRUCTION_H_
#define BOLT_INSTRUCTION_H_

#pragma once

#include "addressing_mode.h"
#include "cpu.h"

#include <array>

namespace bolt {
    //using nes_micro_instruction = void(*)(nes_cpu&);

    template<typename addressing_mode, template<typename> typename nes_micro_instruction, int... micro_instructions>
    class nes_instruction {
    public:

    };
}

#endif