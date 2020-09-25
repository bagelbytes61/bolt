#include "bus.h"

#include "hardware.h"

using namespace bolt;

void gb_bus::register_hardware(gb_hardware_ptr_t hardware, addr_range_t addr_range) {

    registered_hardware.insert({ addr_range, hardware });
}

word_t gb_bus::read_word(addr_t addr) const {
    auto hardware_it = registered_hardware.begin();

    while (addr >= GB_HARDWARE_ADDR_END(hardware_it)) { ++hardware_it; };

    if (hardware_it != registered_hardware.end()) {

        return GB_HARDWARE(hardware_it)->on_read_word(addr - GB_HARDWARE_ADDR_BEGIN(hardware_it));
    }

    return {};
}

void gb_bus::write_word(addr_t addr, word_t value) {
    auto hardware_it = registered_hardware.begin();

    while (addr >= GB_HARDWARE_ADDR_END(hardware_it++));

    if (hardware_it != registered_hardware.end()) {

        GB_HARDWARE(hardware_it)->on_write_word(addr - GB_HARDWARE_ADDR_BEGIN(hardware_it), value);
    }
}