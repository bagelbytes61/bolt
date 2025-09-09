#ifndef BOLT_GB_ALU_PERIPHERAL_HH_
#define BOLT_GB_ALU_PERIPHERAL_HH_

#pragma once

#include "common.h"

namespace bolt {
    class gb_alu_peripheral {
    public:
        virtual ~gb_alu_peripheral() = default;

        virtual auto read(void) const -> byte_t = 0;
        virtual auto write(byte_t) -> void = 0;
    };
}

#endif