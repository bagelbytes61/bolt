#ifndef BOLT_COMMON_H_
#define BOLT_COMMON_H_

#pragma once

#include <cstddef>
#include <cstdint>
#include <utility>

namespace bolt {
    using addr_t = uint16_t;
    using addr_ext_t = size_t;
    using addr_range_t = std::pair<addr_t, addr_t>;
    
    using bit_t = uint8_t;
    using nibble_t = uint8_t;
    using byte_t = uint8_t;
    using word_t = byte_t;

    using signal_t = uint8_t;

    using addr_bus_t = uint16_t;
    using data_bus_t = uint8_t;

    inline constexpr addr_range_t make_addr_range(addr_t addr_begin, addr_t addr_end) {
        
        return { addr_begin, addr_end };
    }

    inline constexpr bool addr_in_range(addr_t addr, addr_range_t addr_range) {
        
        return (addr >= addr_range.first && addr < addr_range.second);
    }
}

#endif