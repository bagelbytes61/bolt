#ifndef BOLT_GB_CARTRIDGE_COUNTRY_CODE_H_
#define BOLT_GB_CARTRIDGE_COUNTRY_CODE_H_

#pragma once

#include <cstdint>
#include <string>

namespace bolt {
    enum struct gb_cartridge_country_code : uint8_t {
        japan = 0x00,
        non_japan = 0x01
    };

    inline std::string gb_cartridge_country_code_to_string(gb_cartridge_country_code code) {
        switch (code) {
        case gb_cartridge_country_code::japan:      return "Japan";
        case gb_cartridge_country_code::non_japan:  return "Non-Japan";
        default:                                    return "Unknown country code";
        }
    }
}

#endif