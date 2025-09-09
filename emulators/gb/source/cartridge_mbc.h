#ifndef BOLT_GB_CARTRIDGE_MBC_H_
#define BOLT_GB_CARTRIDGE_MBC_H_

#pragma once

#include "cartridge_hardware.h"

#include <cstddef>
#include <cstdint>

namespace bolt {

#define GB_MBC_ROM_0000_3FFF_BEGIN 0x0000
#define GB_MBC_ROM_0000_3FFF_END   0x4000

#define GB_MBC_ROM_4000_7FFF_BEGIN 0x4000
#define GB_MBC_ROM_4000_7FFF_END   0x8000

#define GB_MBC_RAM_A000_BFFF_BEGIN 0xa000
#define GB_MBC_RAM_A000_BFFF_END   0xc000

#define GB_MBC_ROM_BITS_0_13_MASK 0x3fff

#define GB_MBC_RAM_BITS_0_12_MASK 0x1fff

    class gb_cartridge_mbc : public gb_cartridge_hardware {
    public:
        virtual ~gb_cartridge_mbc() override = default;

        virtual word_t on_read_word(addr_t addr) const override = 0;

        virtual void on_write_word(addr_t addr, word_t value) override = 0;

    protected:
        virtual addr_t rom_0000_3fff_physical_address(addr_t addr) const = 0;
        virtual addr_t rom_4000_7fff_physical_address(addr_t addr) const = 0;

        virtual addr_t ram_a000_bfff_physical_address(addr_t addr) const = 0;
    };
}

#endif