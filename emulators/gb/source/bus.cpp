#include "bus.h"

#include "hardware.h"

using namespace bolt;

void gb_bus::register_hardware(std::shared_ptr<gb_hardware> hardware, address_t addr_begin, address_t addr_end) {
    registered_hardware.insert({ { addr_begin, addr_end }, hardware });
}

uint8_t gb_bus::read(address_t address) {
    auto hardware_it = registered_hardware.begin();

    while (address >= GB_HARDWARE_ADDRESS_END(hardware_it)) { ++hardware_it; };

    if (hardware_it != registered_hardware.end()) {
        const uint16_t offset = GB_HARDWARE_ADDRESS_BEGIN(hardware_it);

        return GB_HARDWARE(hardware_it)->on_read(address - offset);
    }

    return {};
}

void gb_bus::write(address_t address, word_t data) {
    auto hardware_it = registered_hardware.begin();

    while (address >= GB_HARDWARE_ADDRESS_END(hardware_it++));

    if (hardware_it != registered_hardware.end()) {
        const uint16_t offset = GB_HARDWARE_ADDRESS_BEGIN(hardware_it);

        GB_HARDWARE(hardware_it)->on_write(address, data);
    }
}