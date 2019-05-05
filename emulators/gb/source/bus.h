#ifndef BOLT_GB_BUS_H_
#define BOLT_GB_BUS_H_

#pragma once

#include "common.h"

#include <map>
#include <memory>

namespace bolt {
#define GB_HARDWARE(hardware) ((hardware)->second)
#define GB_HARDWARE_ADDRESS_BEGIN(hardware) ((hardware)->first.first)
#define GB_HARDWARE_ADDRESS_END(hardware) ((hardware)->first.second)

    class gb_hardware;

    class gb_bus {
    public:
        void register_hardware(std::shared_ptr<gb_hardware> hardware, address_t addr_begin, address_t addr_end);

        uint8_t read(address_t address);

        void write(address_t address, word_t value);

    private:
        std::map<std::pair<address_t, address_t>, std::shared_ptr<gb_hardware>> registered_hardware;
    };
}

#endif