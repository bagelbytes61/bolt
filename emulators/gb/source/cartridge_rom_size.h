#ifndef BOLT_GB_CARTRIDGE_ROM_SIZE_H_
#define BOLT_GB_CARTRIDGE_ROM_SIZE_H_

#pragma once

#include <cstdint>
#include <string>

namespace bolt {
    enum struct gb_cartridge_rom_size : uint8_t {
        _32k = 0x00,
        _64k = 0x01,
        _128k = 0x02,
        _256k = 0x03,
        _512k = 0x04,
        _1024k = 0x05,
        _2048k = 0x06,
        _4096k = 0x07
    };

    inline std::string gb_cartridge_rom_size_to_string(gb_cartridge_rom_size size) {
        switch (size) {
        case gb_cartridge_rom_size::_32k:   return "32K";
        case gb_cartridge_rom_size::_64k:   return "64K";
        case gb_cartridge_rom_size::_128k:  return "128K";
        case gb_cartridge_rom_size::_256k:  return "256K";
        case gb_cartridge_rom_size::_512k:  return "512K";
        case gb_cartridge_rom_size::_1024k: return "1024K";
        case gb_cartridge_rom_size::_2048k: return "2048K";
        case gb_cartridge_rom_size::_4096k: return "4096K";
        default:                            return "Unknown ROM size";
        }
    }
}

#endif