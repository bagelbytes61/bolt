#ifndef BOLT_GB_CARTRIDGE_RAM_SIZE_H_
#define BOLT_GB_CARTRIDGE_RAM_SIZE_H_

#pragma once

#include <cstdint>
#include <string>

namespace bolt {
    enum struct gb_cartridge_ram_size : uint8_t {
        none = 0x00,
        _2k = 0x01,
        _8k = 0x02,
        _32k = 0x03,
        _64k = 0x05,
        _128k = 0x04
    };

    inline std::string gb_cartridge_ram_size_to_string(gb_cartridge_ram_size size) {
        switch (size) {
        case gb_cartridge_ram_size::none:  return "None";
        case gb_cartridge_ram_size::_2k:   return "2k";
        case gb_cartridge_ram_size::_8k:   return "8k";
        case gb_cartridge_ram_size::_32k:  return "32k";
        case gb_cartridge_ram_size::_64k:  return "64k";
        case gb_cartridge_ram_size::_128k: return "128k";
        default:                           return "Unknown RAM size";
        }
    }
}

#endif