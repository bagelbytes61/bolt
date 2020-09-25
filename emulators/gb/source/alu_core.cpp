//#include "alu_core.h"
//
//#include "alu_bus.h"
//#include "alu_latch.h"
//
//using namespace bolt;
//
//gb_alu_core::gb_alu_core(gb_alu_bus *hi_bus, gb_alu_latch *lo_latch, gb_register8_proxy_t flags)
//    : hi_bus(hi_bus)
//    , lo_latch(lo_latch)
//    , flags(flags) {
//
//}
//
//gb_alu_core::~gb_alu_core() {
//
//}
//
//void gb_alu_core::machine_cycle(gb_alu_operation operation, uint8_t a, uint8_t b) {
//    switch (operation) {
//        case gb_alu_operation::_inc: {
//            auto result = _inc(a, flags);
//            hi_bus->write(gb_alu_bus_part::high, result >> 4);
//        }
//    }
//}
//
//auto gb_alu_core::_inc(uint8_t in, gb_register8_proxy_t f) -> uint8_t {
//    if ((in & 0x0f) == 0x0f) {
//        f |= GB_FLAGS_H_MASK;
//    }
//    else {
//        f &= ~GB_FLAGS_H_MASK;
//    }
//
//    if (((in & 0x0f) + 1) == 0) {
//        f |= GB_FLAGS_Z_MASK;
//    }
//    else {
//        f &= ~GB_FLAGS_Z_MASK;
//    }
//
//    f &= ~GB_FLAGS_N_MASK;
//
//    return in + 1;
//}
//
//auto gb_alu_core::_dec(uint8_t in, gb_register8_proxy_t f) -> uint8_t {
//    if ((in - 1) == 0) {
//        f |= GB_FLAGS_Z_MASK;
//    }
//    else {
//        f &= ~GB_FLAGS_Z_MASK;
//    }
//
//    if ((in & 0x0f) > 0) {
//        f |= GB_FLAGS_H_MASK;
//    }
//    else {
//        f &= ~GB_FLAGS_H_MASK;
//    }
//
//    f |= GB_FLAGS_N_MASK;
//
//    return in -= 1;
//}