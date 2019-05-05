#ifndef BOLT_GB_CARTRIDGE_H_
#define BOLT_GB_CARTRIDGE_H_

#pragma once

#include "hardware.h"

#include <memory>
#include <map>

namespace bolt {
#define GB_CARTRIDGE_HARDWARE(hardware) ((hardware)->second)
#define GB_CARTRIDGE_HARDWARE_ADDRESS_BEGIN(hardware) ((hardware)->first.first)
#define GB_CARTRIDGE_HARDWARE_ADDRESS_END(hardware) ((hardware)->first.second)

    class gb_cartridge_hardware;

    class gb_cartridge : public gb_hardware {
    public:
        static constexpr uint16_t addr_begin = 0x0000;
        static constexpr uint16_t addr_end = 0x8000;

    public:
        virtual ~gb_cartridge() override final = default;

        void register_hardware(std::unique_ptr<gb_cartridge_hardware> hardware, address_t addr_begin, address_t addr_end);

        virtual uint8_t on_read(address_t address) const override final;

        virtual void on_write(address_t address, word_t data) override final;

    private:
        std::map<std::pair<address_t, address_t>, std::unique_ptr<gb_cartridge_hardware>> registered_hardware;
    };
}

#endif