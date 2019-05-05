#ifndef BOLT_CARTRDIGE_H_
#define BOLT_CARTRIDGE_H_

#pragma once

#include "hardware.h"

#include <array>
#include <cstddef>
#include <cstdint>

namespace bolt {
    class nes_cartridge : public nes_hardware {
    public:
        static constexpr uint16_t address_begin = 0x4020;
        static constexpr uint16_t address_end = 0xffff;

    private:
        static constexpr size_t address_range = address_end - address_begin + 1;

    public:
        nes_cartridge();
        virtual ~nes_cartridge() override final;

        virtual std::byte on_read(uint16_t address) override final;

        virtual void on_write(uint16_t address, std::byte value) override final;

    private:
        std::array<std::byte, address_range> data;
    };

    inline nes_cartridge::nes_cartridge() {

    }

    inline nes_cartridge::~nes_cartridge() {

    }
}

#endif