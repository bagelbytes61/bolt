#include "cartridge.h"

#include "cartridge_hardware.h"

using namespace bolt;

void gb_cartridge::register_hardware(std::unique_ptr<gb_cartridge_hardware> hardware, address_t addr_begin, address_t addr_end) {
    registered_hardware.insert({ std::make_pair(addr_begin, addr_end), std::move(hardware) });
}

word_t gb_cartridge::on_read(address_t address) const {
    auto hardware_it = registered_hardware.begin();

    while (address >= GB_CARTRIDGE_HARDWARE_ADDRESS_END(hardware_it)) { ++hardware_it; };

    if (hardware_it != registered_hardware.end()) {
        const uint16_t offset = GB_CARTRIDGE_HARDWARE_ADDRESS_BEGIN(hardware_it);

        return GB_CARTRIDGE_HARDWARE(hardware_it)->on_read(address - offset);
    }

    return {};
}

void gb_cartridge::on_write(address_t address, word_t value) {

}