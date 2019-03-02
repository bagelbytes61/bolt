#ifndef BOLT_MEMORY_MAP_H_
#define BOLT_MEMORY_MAP_H_

#pragma once

#include <cstdint>

struct AddressRange {
    uint16_t begin;

    uint16_t end;
};

#define DECLARE_ADDRESS_RANGE(name) extern const AddressRange name;

namespace bolt {
    
}

#endif