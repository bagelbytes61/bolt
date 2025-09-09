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
        static constexpr addr_range_t addr_range = make_addr_range(0x0000u, 0x8000u);

    public:
        gb_cartridge_rom(std::unique_ptr<byte_t[]> &&data);
        virtual ~gb_cartridge_rom() override final = default;

        virtual word_t on_read_word(addr_t addr) const override final;

        virtual void on_write_word(addr_t addr, word_t value) override final;

    private:
        std::unique_ptr<byte_t[]> data;
    };

    inline uint8_t gb_cartridge_rom::on_read_word(addr_t addr) const {
        
        return data[addr];
    }

    inline void gb_cartridge_rom::on_write_word(addr_t addr, word_t value) {

    }
}

#endif