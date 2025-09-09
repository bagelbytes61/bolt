#include "alu_bus.h"

#include "alu_shift_register.h"

using namespace bolt;

//gb_alu_bus::gb_alu_bus(gb_alu_shift_register &shift_register, gb_cpu::gb_register_bus &register_bus, gb_alu_bus_part part)
//    : shift_register(shift_register)
//    , register_bus(register_bus)
//    , part(part) {
//
//}
//
//auto gb_alu_bus::read(void) const -> byte_t {
//    return shift_register.read();
//}
//
//auto gb_alu_bus::write(nibble_t value) -> void {
//    if (part == gb_alu_bus_part::high) {
//        *reg = (*reg & 0xf) | value << 4u;
//    } else {
//        *reg = (*reg & 0xf0) | value & 0xf;
//    }
//}