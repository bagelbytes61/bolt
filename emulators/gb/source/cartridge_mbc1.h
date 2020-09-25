#ifndef BOLT_GB_CARTRIDGE_MBC1_H_
#define BOLT_GB_CARTRIDGE_MBC1_H_

#pragma once

#include "cartridge_mbc.h"

#include <cstddef>
#include <cstdint>
#include <memory>

/*
#################### MBC1 Physical ROM Mapping ####################
###################################################################
# Accessed address        # Bank number     # Address within bank #
########################### 20-19 #  18-14  #         13-0        #
###################################################################
# 0x0000-0x3fff, MODE=0b0 # 0b00  # 0b00000 #       A<13:0>       #
# 0x0000-0x3fff, MODE=0b1 # BANK2 # 0b00000 #       A<13:0>       #
# 0x4000-0x7fff  -------- # BANK2 # BANK1   #       A<13:0>       #
###################################################################
*/

/*
#################### MBC1 Physical RAM Mapping ####################
###################################################################
#    Accessed address     # Bank number #   Address within bank   #
###########################   14-13     #           12-0          #
###################################################################
# 0xa000-0xbfff, MODE=0b0 #   0b00      #          A<12:0>        #
# 0xa000-0xbfff, MODE=0b1 #   BANK2     #          A<12:0>        #
###################################################################
*/

namespace bolt {
#define GB_MBC1_RAMG_BEGIN  0x0000
#define GB_MBC1_RAMG_END    0x2000

#define GB_MBC1_BANK1_BEGIN 0x2000
#define GB_MBC1_BANK1_END   0x4000

#define GB_MBC1_BANK2_BEGIN 0x4000
#define GB_MBC1_BANK2_END   0x6000

#define GB_MBC1_MODE_BEGIN  0x6000
#define GB_MBC1_MODE_END    0x8000

#define GB_MBC1_RAMG_MASK  0x0fu
#define GB_MBC1_BANK1_MASK 0x1fu
#define GB_MBC1_BANK2_MASK 0x03u
#define GB_MBC1_MODE_MASK  0x01u

#define GB_MBC1_RAMG_ENABLE_MASK 0x0au

#define GB_MBC1_ROM_BITS_14_18_SHIFT 14
#define GB_MBC1_ROM_BITS_19_20_SHIFT 19
#define GB_MBC1_RAM_BITS_13_14_SHIFT 13

    class gb_cartridge_ram;
    class gb_cartridge_rom;
    
    class gb_cartridge_mbc1 : public gb_cartridge_mbc {
    public:
        gb_cartridge_mbc1();
        virtual ~gb_cartridge_mbc1() override final = default;

        virtual word_t on_read_word(addr_t addr) const override final;

        virtual void on_write_word(addr_t addr, word_t value) override final;

    private:
        virtual addr_t rom_0000_3fff_physical_address(addr_t addr) const override final;
        virtual addr_t rom_4000_7fff_physical_address(addr_t addr) const override final;

        virtual addr_t ram_a000_bfff_physical_address(addr_t addr) const override final;

    private:
        gb_cartridge_rom *cart_rom;
        gb_cartridge_ram *cart_ram;

        gb_cartridge_register ramg;
        gb_cartridge_register bank1;
        gb_cartridge_register bank2;
        gb_cartridge_register mode;
    };

#pragma warning(disable:4146)

    inline addr_t gb_cartridge_mbc1::rom_0000_3fff_physical_address(addr_t addr) const {
        return ((uint32_t(bank2)) << GB_MBC1_ROM_BITS_19_20_SHIFT) & (-(uint32_t(mode))) | (addr & GB_MBC_ROM_BITS_0_13_MASK);
    }

    inline addr_t gb_cartridge_mbc1::rom_4000_7fff_physical_address(addr_t addr) const {
        return ((uint32_t(bank2)) << GB_MBC1_ROM_BITS_19_20_SHIFT) | ((uint32_t(bank1)) << GB_MBC1_ROM_BITS_14_18_SHIFT) | (addr & GB_MBC_ROM_BITS_0_13_MASK);
    }

    inline addr_t gb_cartridge_mbc1::ram_a000_bfff_physical_address(addr_t addr) const {
        return ((uint16_t(bank2)) << GB_MBC1_RAM_BITS_13_14_SHIFT) & (-(uint16_t(mode))) | (addr & GB_MBC_RAM_BITS_0_12_MASK);
    }
}

#endif