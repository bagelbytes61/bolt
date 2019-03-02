#ifndef BOLT_NES_CPU_H_
#define BOLT_NES_CPU_H_

#pragma once

#include "cpu_bus.h"

#include <array>
#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

namespace bolt {
    class nes_cpu {
        friend class nes_micro_instruction;
    public:
        nes_cpu(nes_cpu_bus* bus);
        ~nes_cpu();
        
    private:
        uint8_t         a;

        uint8_t         x;
        uint8_t         y;

        uint8_t         sp;

        uint16_t        pc;

        uint8_t         p;

        uint8_t         ir;

        nes_cpu_bus*    bus;
    };

    inline nes_cpu::nes_cpu(nes_cpu_bus* bus)
        : bus(bus) {

    }

    inline nes_cpu::~nes_cpu() {

    }
}

#endif