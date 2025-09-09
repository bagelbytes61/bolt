#ifndef BOLT_GB_BUS_H_
#define BOLT_GB_BUS_H_

#pragma once

#include "common.h"
#include "tstate.hh"

#include <map>
#include <memory>

namespace bolt {
    #define GB_MEMORY_REGION(region) ((region)->second)
    #define GB_MEMORY_REGION_ADDR_BEGIN(region) ((region)->first.first)
    #define GB_MEMORY_REGION_ADDR_END(region) ((region)->first.second)

    class gb_hardware; 

    using gb_memory_map = std::map<addr_range_t, gb_hardware *>;

    class gb_bus {
    public:
        gb_bus() = default;
        ~gb_bus() = default;

        auto clk(gb_control_signals &ctrl_signals, uint64_t cycle) -> void;

        auto register_memory_region(gb_hardware *hardware, addr_range_t addr_range) -> void;

        auto get_address_bus(void) -> addr_bus_t &;

        auto get_data_bus(void) -> data_bus_t &;

    private:
        addr_bus_t addr_bus;

        data_bus_t data_bus;

        gb_memory_map memory_map;
    };

}

#endif