#ifndef BOLT_PPU_BUS_H_
#define BOLT_PPU_BUS_H_

#pragma once

#include "bus.h"

#include <cstddef>
#include <cstdint>

namespace bolt {
    struct nes_ppu_io {};
    struct nes_ppu_vid_mem {};

    template<typename T>
    class nes_ppu_bus {};

    template<>
    class nes_ppu_bus<nes_ppu_io> : public nes_bus {
    public:
        std::byte read(uint16_t address) { return std::byte(); }
    };

    template<>
    class nes_ppu_bus<nes_ppu_vid_mem> : public nes_bus {
    public:
    };
}

#endif