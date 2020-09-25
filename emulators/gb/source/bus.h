#ifndef BOLT_GB_BUS_H_
#define BOLT_GB_BUS_H_

#pragma once

#include "common.h"

#include <map>
#include <memory>

namespace bolt {
#define GB_HARDWARE(hardware) ((hardware)->second)
#define GB_HARDWARE_ADDR_BEGIN(hardware) ((hardware)->first.first)
#define GB_HARDWARE_ADDR_END(hardware) ((hardware)->first.second)

    class gb_hardware; 

    class gb_bus {
        using gb_hardware_ptr_t = std::shared_ptr<gb_hardware>;

    public:
        void register_hardware(gb_hardware_ptr_t hardware, addr_range_t addr_range);

        word_t read_word(addr_t addr) const;

        void write_word(addr_t addr, word_t value);

    private:
        std::map<addr_range_t, gb_hardware_ptr_t> registered_hardware;
    };
}

#endif