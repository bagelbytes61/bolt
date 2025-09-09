#include "cartridge.h"

#include "cartridge_hardware.h"

using namespace bolt;

void gb_cartridge::register_hardware(gb_cartridge_hardware *hardware, addr_range_t addr_range) {
    registered_hardware.emplace(addr_range, std::move(hardware));
}

word_t gb_cartridge::on_read_word(addr_t addr) const {
    auto hardware_it = registered_hardware.begin();

    while (addr >= GB_CARTRIDGE_HARDWARE_ADDR_END(hardware_it)) { ++hardware_it; };

    if (hardware_it != registered_hardware.end()) {

        return GB_CARTRIDGE_HARDWARE(hardware_it)->on_read_word(addr - GB_CARTRIDGE_HARDWARE_ADDR_BEGIN(hardware_it));
    }

    return {};
}

void gb_cartridge::on_write_word(addr_t addr, word_t value) {
    auto hardware_it = registered_hardware.begin();

    while (addr >= GB_CARTRIDGE_HARDWARE_ADDR_END(hardware_it)) { ++hardware_it; }

    if (hardware_it != registered_hardware.end()) {

        GB_CARTRIDGE_HARDWARE(hardware_it)->on_write_word(addr, value);
    }
}