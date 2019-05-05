#ifndef BOLT_HARDWARE_H_
#define BOLT_HARDWARE_H_

#pragma once

#include <cstddef>
#include <cstdint>

namespace bolt {
    struct nes_hardware {
        virtual ~nes_hardware() = 0;

        virtual std::byte on_read(uint16_t address) = 0;

        virtual void on_write(uint16_t address, std::byte value) = 0;
    };

    inline nes_hardware::~nes_hardware() {

    }
}

#endif