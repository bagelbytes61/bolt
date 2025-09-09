#include "cartridge_mbc1.h"

#include "cartridge_ram.h"
#include "cartridge_rom.h"

using namespace bolt;

gb_cartridge_mbc1::gb_cartridge_mbc1()
    : ramg(0b0000u)
    , bank1(0b00001u)
    , bank2(0b00u)
    , mode(0b0u) {
    
}

 word_t gb_cartridge_mbc1::on_read_word(addr_t addr) const {
    if (addr_in_range(addr, make_addr_range(GB_MBC_ROM_0000_3FFF_BEGIN, GB_MBC_ROM_0000_3FFF_END))) {
        const auto physical_addr = rom_0000_3fff_physical_address(addr);

        return cart_rom->on_read_word(physical_addr);
    }
    else if (addr_in_range(addr, make_addr_range(GB_MBC_ROM_4000_7FFF_BEGIN, GB_MBC_ROM_4000_7FFF_END))) {
       const auto physical_addr = rom_4000_7fff_physical_address(addr);

        return cart_rom->on_read_word(physical_addr);
    }
    else if (addr_in_range(addr, make_addr_range(GB_MBC_RAM_A000_BFFF_BEGIN, GB_MBC_RAM_A000_BFFF_END))) {
        const auto physical_addr = ram_a000_bfff_physical_address(addr);

        return ramg ? cart_ram->on_read_word(physical_addr) : 0xff;
    }
}

void gb_cartridge_mbc1::on_write_word(addr_t addr, word_t value) {
    if (addr_in_range(addr, make_addr_range(GB_MBC1_RAMG_BEGIN, GB_MBC1_RAMG_END))) {
        ramg = value & GB_MBC1_RAMG_MASK;
    }
    else if (addr_in_range(addr, make_addr_range(GB_MBC1_BANK1_BEGIN, GB_MBC1_BANK1_END))) {
        bank1 = value & GB_MBC1_BANK1_MASK | !(value & GB_MBC1_BANK1_MASK);
    }
    else if (addr_in_range(addr, make_addr_range(GB_MBC1_BANK2_BEGIN, GB_MBC1_BANK2_END))) {
        bank2 = value & GB_MBC1_BANK2_MASK;
    }
    else if (addr_in_range(addr, make_addr_range(GB_MBC1_MODE_BEGIN, GB_MBC1_MODE_END))) {
        mode = value & GB_MBC1_MODE_MASK;
    }
}