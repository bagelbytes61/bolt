#ifndef BOLT_GB_ALU_LATCH_H_
#define BOLT_GB_ALU_LATCH_H_

#pragma once

#include "alu_bus.h"
#include "alu_peripheral.hh"

#include <cstdint>

namespace bolt {
    enum struct gb_alu_latch_part {
        high,
        low
    };

    class gb_alu_latch : public gb_alu_peripheral {
    public:
        gb_alu_latch(gb_alu_peripheral &src, gb_alu_peripheral &dst, gb_alu_latch_part part)
            : src(src)
            , dst(dst)
            , part(part)
            , value(0xff) {
        }

        virtual auto read(void) const -> byte_t override final {
            return value;
        }


        virtual auto write(byte_t) -> void override final {

        }

        void latch(void) {
            this->value = src.read();
                
            //if (part == gb_alu_latch_part::high) {
            //    value ^= ((value & 0xf0) ^ (bus->read(gb_alu_bus_part::high) << 4));
            //} else {
            //    value ^= ((value & 0x0f) ^ (bus->read(gb_alu_bus_part::low)  << 0));
            //}
        }

        void unlatch(void) {
            dst.write(value);
            //peripheral.write(value);
            //if (part == gb_alu_latch_part::high) {
                //bus->write(gb_alu_bus_part::high, get_part(part));
            //} else {
                //bus->write(gb_alu_bus_part::low, get_part(part));
            //}
        }



    private:
        //uint8_t get_part(gb_alu_latch_part part) const {
        //    if (part == gb_alu_latch_part::high) {
        //        return (value & 0xf0) >> 4;
        //    }
        //    else {
        //        return (value & 0x0f) >> 0;
        //    }
        //}

    private:
        gb_alu_peripheral &src;
        gb_alu_peripheral &dst;

        gb_alu_latch_part part;

        nibble_t value;
    };
}

#endif