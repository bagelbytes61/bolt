#ifndef BOLT_GB_CARTRIDGE_TYPE_H_
#define BOLT_GB_CARTRIDGE_TYPE_H_

#pragma once

#include <cstdint>
#include <string>

namespace bolt {
    enum struct gb_cartridge_type : uint8_t {
        rom_only                       = 0x00,
        rom_battery                    = 0x08,
        rom_ram_battery                = 0x09,

        mbc1                           = 0x01,
        mbc1_ram                       = 0x02,
        mbc1_ram_battery               = 0x03,

        mbc2                           = 0x05,
        mbc2_battery                   = 0x06,

        mbc3                           = 0x11,
        mbc3_ram                       = 0x12,
        mbc3_ram_battery               = 0x13,
        mbc3_timer_battery             = 0x0f,
        mbc3_timer_ram_battery         = 0x10,

        mbc5                           = 0x19,
        mbc5_ram                       = 0x1a,
        mbc5_ram_battery               = 0x1b,
        mbc5_rumble                    = 0x1c,
        mbc5_rumble_ram                = 0x1d,
        mbc5_rumble_ram_battery        = 0x1e,

        mbc6                           = 0x20,

        mbc7_sensor_rumble_ram_battery = 0x22,

        mmm01                          = 0x0b,
        mmm01_ram                      = 0x0c,
        mmm01_ram_battery              = 0x0d,

        pocket_camera                  = 0xfc,
        bandai_tama5                   = 0xfd,
        huc3                           = 0xfe,
        huc3_ram_battery               = 0xff
    };

    inline std::string gb_cartridge_type_to_string(gb_cartridge_type type) {
        switch (type) {
        case gb_cartridge_type::rom_only:                       return "ROM only";
        case gb_cartridge_type::rom_battery:                    return "ROM + Battery";
        case gb_cartridge_type::rom_ram_battery:                return "ROM + RAM + Battery";
        case gb_cartridge_type::mbc1:                           return "MBC1";
        case gb_cartridge_type::mbc1_ram:                       return "MBC1 + RAM";
        case gb_cartridge_type::mbc1_ram_battery:               return "MBC1 + RAM + Battery";
        case gb_cartridge_type::mbc2:                           return "MBC2";
        case gb_cartridge_type::mbc2_battery:                   return "MBC2 + Battery";
        case gb_cartridge_type::mbc3:                           return "MBC3";
        case gb_cartridge_type::mbc3_ram:                       return "MBC3 + RAM";
        case gb_cartridge_type::mbc3_ram_battery:               return "MBC3 + RAM + Battery";
        case gb_cartridge_type::mbc3_timer_battery:             return "MBC3 + Timer + Battery";
        case gb_cartridge_type::mbc3_timer_ram_battery:         return "MBC3 + Timer + RAM + Battery";
        case gb_cartridge_type::mbc5:                           return "MBC5";
        case gb_cartridge_type::mbc5_ram:                       return "MBC5 + RAM";
        case gb_cartridge_type::mbc5_ram_battery:               return "MBC5 + RAM + Battery";
        case gb_cartridge_type::mbc5_rumble:                    return "MBC5 + Rumble";
        case gb_cartridge_type::mbc5_rumble_ram:                return "MBC5 + Rumble + RAM";
        case gb_cartridge_type::mbc5_rumble_ram_battery:        return "MBC5 + Rumble + RAM + Battery";
        case gb_cartridge_type::mbc6:                           return "MBC6";
        case gb_cartridge_type::mbc7_sensor_rumble_ram_battery: return "MBC7 + Sensor + Rumble + RAM + Battery";
        case gb_cartridge_type::mmm01:                          return "MMM01";
        case gb_cartridge_type::mmm01_ram:                      return "MMM01 + RAM";
        case gb_cartridge_type::mmm01_ram_battery:              return "MMM01 + RAM + Battery";
        case gb_cartridge_type::huc3:                           return "HuC3";
        case gb_cartridge_type::huc3_ram_battery:               return "HuC3 + RAM + Battery";
        default:                                                return "Unknown cartridge type";
        }
    }
}

#endif