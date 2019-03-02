#ifndef BOLT_INTERNAL_RAM_H_
#define BOLT_INTERNAL_RAM_H_

#pragma once

#include "hardware.h"

#include <array>
#include <cstdint>

namespace bolt {
    class nes_internal_ram : public nes_hardware {
    public:
        static constexpr uint16_t address_begin = 0x0000;
        static constexpr uint16_t address_end = 0x0800;

    public:

    private:
        std::array<std::byte, 0x0800> m_data;
    };
}

#endif