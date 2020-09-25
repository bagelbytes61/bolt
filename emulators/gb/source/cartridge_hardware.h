#ifndef BOLT_GB_CARTRIDGE_HARDWARE_H_
#define BOLT_GB_CARTRIDGE_HARDWARE_H_

#pragma once

#include "common.h"

#include <cstdint>
#include <memory>

namespace bolt {
    using gb_cartridge_register = uint8_t;
    
    class gb_cartridge_hardware {
    public:
        virtual ~gb_cartridge_hardware() = default;

        virtual word_t on_read_word(addr_t addr) const = 0;

        virtual void on_write_word(addr_t addr, word_t value) = 0;
    };
}

#endif