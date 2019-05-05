#ifndef BOLT_BUS_H_
#define BOLT_BUS_H_

#pragma once

#include "hardware.h"

#include <cstdint>
#include <map>
#include <optional>

namespace bolt {
#define NES_HARDWARE(hardware) ((hardware)->second)
#define NES_HARDWARE_ADDRESS_BEGIN(hardware) ((hardware)->first.first)
#define NES_HARDWARE_ADDRESS_END(hardware) ((hardware)->first.second)

    using read_result = std::optional<std::byte>;

    class nes_bus {
    public:
        void register_hardware(nes_hardware* hardware, uint16_t addr_begin, uint16_t addr_end) {
            hardware_map.insert({ { addr_begin, addr_end }, hardware });
        }

    protected:
        read_result read(uint16_t address) const {
            auto hardware_it = hardware_map.begin();
            while (address >= NES_HARDWARE_ADDRESS_END(hardware_it)) { ++hardware_it; }

            if (hardware_it != hardware_map.end()) {
                const uint16_t offset = NES_HARDWARE_ADDRESS_BEGIN(hardware_it);

                return NES_HARDWARE(hardware_it)->on_read(address - offset);
            }

            return {};
        }

        void write(uint16_t address, std::byte data) {
            auto hardware_it = hardware_map.begin();
            while (address >= NES_HARDWARE_ADDRESS_END(hardware_it)) { ++hardware_it; }

            if (hardware_it != hardware_map.end()) {
                const uint16_t offset = NES_HARDWARE_ADDRESS_BEGIN(hardware_it);

               NES_HARDWARE(hardware_it)->on_write(address - offset, data);
            }
        }

    protected:
        std::map<std::pair<uint16_t, uint16_t>, nes_hardware*> hardware_map;
    };
}

#endif