#ifndef BOLT_GB_CARTRIDGE_HARDWARE_TYPE_H_
#define BOLT_GB_CARTRIDGE_HARDWARE_TYPE_H_

#pragma once

#include <cstdint>
#include <type_traits>

namespace bolt {
    enum struct gb_cartridge_hardware_type : uint32_t {
        mbc1    = 0x00000001,
        mbc2    = 0x00000002,
        mbc3    = 0x00000004,
        mbc5    = 0x00000008,
        mbc6    = 0x00000010,
        mbc7    = 0x00000020,

        ram     = 0x00000040,
        battery = 0x00000080,
        timer   = 0x00000100,
        rumbler = 0x00000200
    };

    inline gb_cartridge_hardware_type operator&(gb_cartridge_hardware_type lhs, gb_cartridge_hardware_type rhs) {
        return static_cast<gb_cartridge_hardware_type>(
            static_cast<std::underlying_type_t<gb_cartridge_hardware_type>>(lhs) &
            static_cast<std::underlying_type_t<gb_cartridge_hardware_type>>(lhs));
    }

    inline gb_cartridge_hardware_type operator|(gb_cartridge_hardware_type lhs, gb_cartridge_hardware_type rhs) {
        return static_cast<gb_cartridge_hardware_type>(
            static_cast<std::underlying_type_t<gb_cartridge_hardware_type>>(lhs) |
            static_cast<std::underlying_type_t<gb_cartridge_hardware_type>>(lhs));
    }
}

#endif