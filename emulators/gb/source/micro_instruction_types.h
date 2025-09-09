#ifndef BOLT_GB_MICRO_INSTRUCTION_TYPES_H_
#define BOLT_GB_MICRO_INSTRUCTION_TYPES_H_

#pragma once

#include <cstdint>

namespace bolt {
    enum struct gb_micro_instruction_type : uint64_t {
        not_implemented,

        internal_delay,

        fetch,
        decode,

        fetch_pch,
        fetch_pcl,

        push_pch,
        push_pcl,

        pop_pch,
        pop_pcl,
        
        load_msb,
        load_lsb,

        store_msb,
        store_lsb,

        jump_rel,

        increment,
        decrement
    };
}

#endif