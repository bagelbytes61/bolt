#ifndef BOLT_CONTROL_BUS_H_
#define BOLT_CONTROL_BUS_H_

#pragma once

#include "bus.h"

#include "addressing_mode.h"

#include <cstdint>

namespace bolt {
    class nes_cpu_bus : public nes_bus {
    public:
        uint8_t read(uint8_t address) const { return 0; }

        void write(uint16_t address, uint8_t value) {}
    };

    //template<>
    //uint8_t nes_cpu_bus::read<nes_addressing_mode::immediate>(uint16_t address) const {
    //    return 0;
    //}

    //void nes_cpu_bus::write(uint16_t address, uint8_t value) {

    //}
}

#endif