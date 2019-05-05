#ifndef BOLT_GB_CARTRIDGE_MBC1_H_
#define BOLT_GB_CARTRIDGE_MBC1_H_

#pragma once

#include "cartridge_mbc.h"

#include "cartridge_ram.h"
#include "cartridge_rom.h"

#include <cstddef>
#include <cstdint>

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

#define GB_MBC1_RAMG_MASK  0x0f
#define GB_MBC1_BANK1_MASK 0x1f
#define GB_MBC1_BANK2_MASK 0x03
#define GB_MBC1_MODE_MASK  0x01

#define GB_MBC1_RAMG_ENABLE 0x0a

#define GB_MBC1_ROM_BITS_14_18_SHIFT 14
#define GB_MBC1_ROM_BITS_19_20_SHIFT 19
#define GB_MBC1_RAM_BITS_13_14_SHIFT 13

    class gb_cartridge_ram;
    class gb_cartridge_rom;
    
    class gb_cartridge_mbc1 : public gb_cartridge_mbc {
    public:
        virtual ~gb_cartridge_mbc1() override final = default;

        virtual word_t on_read(address_t address) const override final;

        virtual void on_write(address_t address, word_t value) override final;

    private:
        virtual address_t rom_0000_3fff_physical_address(address_t address) const override final;
        virtual address_t rom_4000_7fff_physical_address(address_t address) const override final;

        virtual address_t ram_a000_bfff_physical_address(address_t address) const override final;

    private:
        gb_cartridge_rom* rom;

        gb_cartridge_ram* ram;

        bool ramg;

        uint8_t bank1;

        uint8_t bank2;

        uint8_t mode;
    };

#pragma warning(disable:4146)

    inline address_t gb_cartridge_mbc1::rom_0000_3fff_physical_address(address_t address) const {
        return ((uint32_t(bank2)) << GB_MBC1_ROM_BITS_19_20_SHIFT) & (-(uint32_t(mode))) | (address & GB_MBC_ROM_BITS_0_13_MASK);
    }

    inline address_t gb_cartridge_mbc1::rom_4000_7fff_physical_address(address_t address) const {
        return ((uint32_t(bank2)) << GB_MBC1_ROM_BITS_19_20_SHIFT) | ((uint32_t(bank1)) << GB_MBC1_ROM_BITS_14_18_SHIFT) | (address & GB_MBC_ROM_BITS_0_13_MASK);
    }

    inline address_t gb_cartridge_mbc1::ram_a000_bfff_physical_address(address_t address) const {
        return ((uint16_t(bank2)) << GB_MBC1_RAM_BITS_13_14_SHIFT) & (-(uint16_t(mode))) | (address & GB_MBC_RAM_BITS_0_12_MASK);
    }
}

#endif