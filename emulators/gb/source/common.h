#ifndef BOLT_COMMON_H_
#define BOLT_COMMON_H_

#pragma once

#include <cstddef>
#include <cstdint>

namespace bolt {
    using address_t = uint16_t;
    using address_ext_t = size_t;
    using word_t = uint8_t;
    using byte_t = uint8_t;

    inline bool addr_in_range(address_t address, address_t begin, address_t end) {
        return (address >= begin && address < end);
    }
}

#endif