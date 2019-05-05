#ifndef BOLT_GB_CARTRIDGE_ROM_H_
#define BOLT_GB_CARTRIDGE_ROM_H_

#pragma once

#include "cartridge_hardware.h"

#include <cstddef>
#include <cstdint>
#include <memory>

namespace bolt {
    class gb_cartridge_rom : public gb_cartridge_hardware {
    public:
        static constexpr uint16_t addr_begin = 0x0000;
        static constexpr uint16_t addr_end   = 0x8000;

    public:
        gb_cartridge_rom(std::unique_ptr<byte_t[]> data);
        virtual ~gb_cartridge_rom() override final = default;

        virtual word_t on_read(address_t address) const override final;

        virtual void on_write(address_t address, word_t value) override final;

    private:
        std::unique_ptr<byte_t[]> data;
    };

    inline uint8_t gb_cartridge_rom::on_read(address_t address) const {
        return data.get()[address];
    }

    inline void gb_cartridge_rom::on_write(address_t address, word_t value) {

    }
}

#endif