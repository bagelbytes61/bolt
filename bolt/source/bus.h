#ifndef BOLT_BUS_H_
#define BOLT_BUS_H_

#pragma once

#include "hardware.h"

#include <cstdint>
#include <map>

namespace bolt {
    class nes_bus {
    public:
        void register_hardware(nes_hardware* hardware, uint16_t addr_begin, uint16_t addr_end) {
            m_hardware.insert({ { addr_begin, addr_end }, hardware });
        }

    protected:
        std::map<std::pair<uint16_t, uint16_t>, nes_hardware*> m_hardware;
    };
}

#endif