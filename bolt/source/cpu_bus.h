#ifndef BOLT_CONTROL_BUS_H_
#define BOLT_CONTROL_BUS_H_

#pragma once

#include "bus.h"

#include "addressing_mode.h"

#include <cstdint>

namespace bolt {
    class nes_cpu_bus : public nes_bus {
    public:
        template<typename addressing_mode = nes_addressing_mode_absolute>
        std::byte read(uint16_t address) const ;

        template<typename addressing_mode = nes_addressing_mode_absolute>
        void write(uint16_t address, std::byte data);
    };

    template<>
    inline std::byte nes_cpu_bus::read<nes_addressing_mode_immediate>(uint16_t address) const {
        if (auto data = nes_bus::read(static_cast<uint8_t>(address))) {
            return *data;
        }

        return std::byte();
    }

    template<>
    inline std::byte nes_cpu_bus::read<nes_addressing_mode_absolute>(uint16_t address) const {
        if (auto data = nes_bus::read(address)) {
            return *data;
        }

        return std::byte(address >> 8 & 0x0f);
    }

    template<>
    inline void nes_cpu_bus::write<nes_addressing_mode_absolute>(uint16_t address, std::byte data) {
        nes_bus::write(address, data);
    }
}

#endif