#ifndef BOLT_INTERNAL_RAM_H_
#define BOLT_INTERNAL_RAM_H_

#pragma once

#include "hardware.h"

#include <array>
#include <cstdint>

namespace bolt {
    class nes_internal_ram : public nes_hardware {
    public:
        static constexpr uint16_t address_begin = 0x0000;
        static constexpr uint16_t address_end = 0x0800;

    private:
        static constexpr size_t address_range = address_end - address_begin + 1;

    public:
        virtual ~nes_internal_ram() override final;

        virtual std::byte on_read(uint16_t address) override final;

        virtual void on_write(uint16_t address, std::byte value) override final;

    private:
        std::array<std::byte, address_range> data;
    };

    inline nes_internal_ram::~nes_internal_ram() {

    }
}

#endif