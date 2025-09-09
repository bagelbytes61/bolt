#ifndef BOLT_GB_CARTRIDGE_LICENSEE_H_
#define BOLT_GB_CARTRIDGE_LICENSEE_H_

#pragma once

#include <cstdint>
#include <string>

namespace bolt {
    #define GB_NEW_LICENSEE_ASCII_VALUE(a, b) (static_cast<uint16_t>(a) << 8 | (b))

    enum struct gb_cartridge_licensee : uint16_t {
        none            = GB_NEW_LICENSEE_ASCII_VALUE('0', '0'),
        electronic_arts = GB_NEW_LICENSEE_ASCII_VALUE('1', '3'),
        kss             = GB_NEW_LICENSEE_ASCII_VALUE('2', '0'),
        san_x           = GB_NEW_LICENSEE_ASCII_VALUE('2', '5'),
        viacom          = GB_NEW_LICENSEE_ASCII_VALUE('3', '0'),
        ocean_acclaim   = GB_NEW_LICENSEE_ASCII_VALUE('3', '3'),
        taito           = GB_NEW_LICENSEE_ASCII_VALUE('3', '8'),
        ubisoft         = GB_NEW_LICENSEE_ASCII_VALUE('4', '1'),
        angel           = GB_NEW_LICENSEE_ASCII_VALUE('4', '6'),
        absolute        = GB_NEW_LICENSEE_ASCII_VALUE('5', '0'),
        american_sammy  = GB_NEW_LICENSEE_ASCII_VALUE('5', '3'),
        ljn             = GB_NEW_LICENSEE_ASCII_VALUE('5', '6'),
        milton_bradley  = GB_NEW_LICENSEE_ASCII_VALUE('5', '7'),
        lucasarts       = GB_NEW_LICENSEE_ASCII_VALUE('6', '4'),
        infogrames      = GB_NEW_LICENSEE_ASCII_VALUE('7', '3'),
        sculptured      = GB_NEW_LICENSEE_ASCII_VALUE('7', '9'),
        accolade        = GB_NEW_LICENSEE_ASCII_VALUE('7', '9'),
        tokuma_shoten_i = GB_NEW_LICENSEE_ASCII_VALUE('8', '6'),
        video_system    = GB_NEW_LICENSEE_ASCII_VALUE('9', '2'),
        yonezawa_spal   = GB_NEW_LICENSEE_ASCII_VALUE('9', '6'),
        konami_yugioh   = GB_NEW_LICENSEE_ASCII_VALUE('A', '4'),
        nintendo_rd1    = GB_NEW_LICENSEE_ASCII_VALUE('0', '1'),
        hudson_soft     = GB_NEW_LICENSEE_ASCII_VALUE('1', '8'),
        pow             = GB_NEW_LICENSEE_ASCII_VALUE('2', '2'),
        kemco_japan     = GB_NEW_LICENSEE_ASCII_VALUE('2', '8'),
        nintendo        = GB_NEW_LICENSEE_ASCII_VALUE('3', '1'),
        konami_0        = GB_NEW_LICENSEE_ASCII_VALUE('3', '4'),
        hudson          = GB_NEW_LICENSEE_ASCII_VALUE('3', '8'),
        atlus           = GB_NEW_LICENSEE_ASCII_VALUE('4', '2'),
        bullet_proof    = GB_NEW_LICENSEE_ASCII_VALUE('4', '7'),
        acclaim         = GB_NEW_LICENSEE_ASCII_VALUE('5', '1'),
        konami_1        = GB_NEW_LICENSEE_ASCII_VALUE('5', '4'),
        matchbox        = GB_NEW_LICENSEE_ASCII_VALUE('5', '7'),
        titus           = GB_NEW_LICENSEE_ASCII_VALUE('6', '0'),
        ocean           = GB_NEW_LICENSEE_ASCII_VALUE('6', '7'),
        interplay       = GB_NEW_LICENSEE_ASCII_VALUE('7', '1'),
        sci             = GB_NEW_LICENSEE_ASCII_VALUE('7', '5'),
        misawa          = GB_NEW_LICENSEE_ASCII_VALUE('8', '0'),
    };

    inline std::string gb_cartridge_licensee_to_string(gb_cartridge_licensee licensee) {
        switch (licensee) {
        case gb_cartridge_licensee::none:            return "None";
        case gb_cartridge_licensee::electronic_arts: return "Electronic Arts";
        case gb_cartridge_licensee::kss:             return "kss";
        case gb_cartridge_licensee::san_x:           return "san-x";
        case gb_cartridge_licensee::ocean_acclaim:   return "Ocean/Acclaim";
        case gb_cartridge_licensee::taito:           return "Taito";
        case gb_cartridge_licensee::ubisoft:         return "Ubisoft";
        default:                                     return "Unknown";
        }
    }
}

#endif