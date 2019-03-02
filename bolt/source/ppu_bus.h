#ifndef BOLT_PPU_BUS_H_
#define BOLT_PPU_BUS_H_

#pragma once

#include "bus.h"

namespace bolt {
    class nes_cpu;

    struct nes_ppu_io {};
    struct nes_ppu_vid_mem {};

    template<typename T>
    class nes_data_bus {
    public:

    };

    template<>
    class nes_data_bus<nes_cpu> : public nes_bus {
    public:
        uint8_t read() const {
            return m_data;
        }

        void write(uint8_t data) {
            m_data = data;
        }

    private:
        uint8_t m_data;
    };

    template<>
    class nes_data_bus<nes_ppu_io> : public nes_bus {
    public:

    };

    template<>
    class nes_data_bus<nes_ppu_vid_mem> : public nes_bus {
    public:
    };
}

#endif