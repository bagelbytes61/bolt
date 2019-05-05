#include "cartridge_mbc1.h"

using namespace bolt;

 word_t gb_cartridge_mbc1::on_read(address_t address) const {
    if (addr_in_range(address, GB_MBC_ROM_0000_3FFF_BEGIN, GB_MBC_ROM_0000_3FFF_END)) {
        address_t physical_address = rom_0000_3fff_physical_address(uint16_t(address));

        return rom->on_read(physical_address);
    }
    else if (addr_in_range(address, GB_MBC_ROM_4000_7FFF_BEGIN, GB_MBC_ROM_4000_7FFF_END)) {
        address_t physical_address = rom_4000_7fff_physical_address(uint16_t(address));

        return rom->on_read(physical_address);
    }
    else if (addr_in_range(address, GB_MBC_RAM_A000_BFFF_BEGIN, GB_MBC_RAM_A000_BFFF_END)) {
        address_t physical_address = ram_a000_bfff_physical_address(uint16_t(address));

        return ramg ? ram->on_read(physical_address) : 0xff;
    }
}

void gb_cartridge_mbc1::on_write(address_t address, word_t value) {
    if (addr_in_range(address, GB_MBC1_RAMG_BEGIN, GB_MBC1_RAMG_END)) {
        ramg = (value & GB_MBC1_RAMG_MASK) == GB_MBC1_RAMG_ENABLE;
    }
    else if (addr_in_range(address, GB_MBC1_BANK1_BEGIN, GB_MBC1_BANK1_END)) {
        bank1 = (value & GB_MBC1_BANK1_MASK) | !(value & GB_MBC1_BANK1_MASK);
    }
    else if (addr_in_range(address, GB_MBC1_BANK2_BEGIN, GB_MBC1_BANK2_END)) {
        bank2 = value & GB_MBC1_BANK2_MASK;
    }
    else if (addr_in_range(address, GB_MBC1_MODE_BEGIN, GB_MBC1_MODE_END)) {
        mode = value & GB_MBC1_MODE_MASK;
    }
}