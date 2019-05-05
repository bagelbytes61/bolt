#ifndef BOLT_GB_ROM_H_
#define BOLT_GB_ROM_H_

#pragma once

#include "hardware.h"

#include <array>
#include <cstddef>
#include <cstdint>

namespace bolt {
    class gb_vram : public gb_hardware {
    public:
        static constexpr uint16_t addr_begin = 0x8000;
        static constexpr uint16_t addr_end = 0xa000;

    public:
        virtual ~gb_vram() override final = default;

        virtual uint8_t
            on_read(address_t address) const override final;

        virtual void
            on_write(address_t address, word_t value) override final;

    private:
        std::array<byte_t, 0x2000> data;
    };

    inline uint8_t gb_vram::on_read(address_t address) const {
        return data[address];
    }

    inline void gb_vram::on_write(address_t address, word_t value) {
        data[address] = value;
    }
}

#endif