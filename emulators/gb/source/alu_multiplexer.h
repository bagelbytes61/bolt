#ifndef BOLT_GB_ALU_MULTIPLEXER_H_
#define BOLT_GB_ALU_MULTIPLEXER_H_

#pragma once

#include "common.h"

#include "alu_latch.h"
#include "alu_peripheral.hh"

namespace bolt {
    //class gb_alu_latch;

    class gb_alu_multiplexer : public gb_alu_peripheral {
    public:
        gb_alu_multiplexer(gb_alu_latch &high_latch, gb_alu_latch &low_latch)
            : high_latch(high_latch)
            , low_latch(low_latch) {

        }
        ~gb_alu_multiplexer() = default;
        
        virtual auto read(void) const -> byte_t override final {
            return high_latch.read() & 0xf0 | low_latch.read() & 0xf;
        }

        virtual auto write(byte_t value) -> void override final {

        }

        //auto read_high_latch(void) const -> nibble_t {
        //    //return high_latch.unlatch(;
        //}

        //auto read_low_latch(void) const -> nibble_t {

        //}

    private:
        gb_alu_latch &high_latch;
        gb_alu_latch &low_latch;
    };
}

#endif