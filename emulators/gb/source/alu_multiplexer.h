#ifndef BOLT_GB_ALU_MULTIPLEXER_H_
#define BOLT_GB_ALU_MULTIPLEXER_H_

#pragma once

#include "alu_latch.h"

namespace bolt {
    class gb_alu_multiplexer {
    public:
        gb_alu_multiplexer(gb_alu_latch *latch_low, gb_alu_latch *latch_high)
            : latch_low(latch_low)
            , latch_high(latch_high) {

        }
        ~gb_alu_multiplexer() = default;

        nibble_t read_low_latch(void) const {

        }

        nibble_t read_high_latch(void) const {

        }

    private:
        gb_alu_latch *latch_low;
        gb_alu_latch *latch_high;
    };
}

#endif