#ifndef BOLT_NES_CPU_H_
#define BOLT_NES_CPU_H_

#pragma once

#include "cpu_bus.h"
#include "instruction_set.h"

#include <array>
#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

namespace bolt {
#define NES_PC(cpu) (static_cast<uint16_t>((cpu)->pch) >> 8 | (cpu)->pcl)

    class nes_cpu {
        friend class nes_micro_instruction;
    public:
        nes_cpu(nes_cpu_bus* bus);
        ~nes_cpu();
        
        void cycle();

        void handle_interrupts();

    private:
        uint8_t fetch_next_opcode() const;
        
    private:
        uint8_t         a;

        uint8_t         x;
        uint8_t         y;

        uint8_t         sp;

        uint8_t         pch;
        uint8_t         pcl;

        uint8_t         p;

        uint8_t         dl;

        uint8_t         pd;

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