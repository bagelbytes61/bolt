#ifndef BOLT_GB_CARTRIDGE_H_
#define BOLT_GB_CARTRIDGE_H_

#pragma once

#include "hardware.h"

#include <memory>
#include <map>

namespace bolt {
#define GB_CARTRIDGE_HARDWARE(hardware) ((hardware)->second)
#define GB_CARTRIDGE_HARDWARE_ADDR_BEGIN(hardware) ((hardware)->first.first)
#define GB_CARTRIDGE_HARDWARE_ADDR_END(hardware) ((hardware)->first.second)

    class gb_cartridge_hardware;

    class gb_cartridge : public gb_hardware {
    public:
        using gb_cartridge_hardware_ptr = std::unique_ptr<gb_cartridge_hardware>;

        static constexpr addr_range_t addr_range = make_addr_range_t(0x0000u, 0x8000u);

    public:
        virtual ~gb_cartridge() override final = default;

        void register_hardware(gb_cartridge_hardware_ptr hardware, addr_range_t addr_range);

        virtual word_t on_read_word(addr_t addr) const override final;

        virtual void on_write_word(addr_t addr, word_t data) override final;

    private:
        std::map<addr_range_t, gb_cartridge_hardware_ptr> registered_hardware;
    };
}

#endif