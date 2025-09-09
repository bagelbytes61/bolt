#ifndef BOLT_PPU_REGISTER_H_
#define BOLT_PPU_REGISTER_H_

#pragma once

#include "hardware.h"

#include <cstddef>
#include <cstdint>

namespace bolt {
    class nes_ppu_registers : public nes_hardware {
    public:
        static constexpr uint16_t address_begin = 0x2000;
        static constexpr uint16_t address_end = 0x2007;

    private:
        static constexpr uint16_t ppuctrl_address = 0x2000;
        static constexpr uint16_t ppumask_address = 0x2001;
        static constexpr uint16_t ppustatus_address = 0x2002;
        static constexpr uint16_t oamaddr_address = 0x2003;
        static constexpr uint16_t oamdata_address = 0x2004;
        static constexpr uint16_t ppuscroll_address = 0x2005;
        static constexpr uint16_t ppuaddr_address = 0x2006;
        static constexpr uint16_t ppudata_address = 0x2007;

    public:
        virtual ~nes_ppu_registers() override final;

        virtual std::byte on_read(uint16_t address) override final;

        virtual void on_write(uint16_t address, std::byte value) override final;

    private:
        std::byte ppuctrl;
        std::byte ppumask;
        std::byte ppustatus;

        std::byte oamaddr;
        std::byte oamdata;

        std::byte ppuscroll;
        std::byte ppuaddr;
        std::byte ppudata;
    };

    inline nes_ppu_registers::~nes_ppu_registers() {

    }
}

#endif