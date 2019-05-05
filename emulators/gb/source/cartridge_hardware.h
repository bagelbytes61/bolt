#ifndef BOLT_GB_CARTRIDGE_HARDWARE_H_
#define BOLT_GB_CARTRIDGE_HARDWARE_H_

#pragma once

#include "common.h"

namespace bolt {
    class gb_cartridge_hardware {
    public:
        virtual ~gb_cartridge_hardware() = default;

        virtual word_t on_read(address_t address) const = 0;

        virtual void on_write(address_t address, word_t data) = 0;
    };
}

#endif