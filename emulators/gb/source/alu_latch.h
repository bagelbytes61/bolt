#ifndef BOLT_GB_ALU_LATCH_H_
#define BOLT_GB_ALU_LATCH_H_

#pragma once

#include "alu_bus.h"
#include "alu.h"

#include <cstdint>

namespace bolt {
    //enum struct gb_alu_latch_type {
    //    from,
    //    to
    //};

    //enum struct gb_alu_latch_part {
    //    low,
    //    high
    //};

    //class gb_alu_latch {
    //public:
    //    gb_alu_latch(gb_alu_bus *bus)
    //        : bus(bus)
    //        , value(0xff) {
    //    }


    //    void latch(gb_alu_latch_part part) {
    //        if (part == gb_alu_latch_part::high) {
    //            value ^= ((value & 0xf0) ^ (bus->read(gb_alu_bus_part::high) << 4));
    //        } else {
    //            value ^= ((value & 0x0f) ^ (bus->read(gb_alu_bus_part::low)  << 0));
    //        }
    //    }

    //    void unlatch(gb_alu_latch_part part) {
    //        if (part == gb_alu_latch_part::high) {
    //            bus->write(gb_alu_bus_part::high, get_part(part));
    //        } else {
    //            bus->write(gb_alu_bus_part::low, get_part(part));
    //        }
    //    }



    //private:
    //    uint8_t get_part(gb_alu_latch_part part) const {
    //        if (part == gb_alu_latch_part::high) {
    //            return (value & 0xf0) >> 4;
    //        }
    //        else {
    //            return (value & 0x0f) >> 0;
    //        }
    //    }

    //private:
    //    gb_alu_bus *bus;

    //    uint8_t value;
    //};
}

#endif