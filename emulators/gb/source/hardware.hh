#ifndef BOLT_GB_HARDWARE_H_
#define BOLT_GB_HARDWARE_H_

#pragma once

#include "common.h"

namespace bolt {
    class gb_hardware {
    public:
        virtual ~gb_hardware() = default;

        virtual word_t on_read_word(addr_t addr) const = 0;
        
        virtual void on_write_word(addr_t address, word_t value) = 0;
    };
}

#endif