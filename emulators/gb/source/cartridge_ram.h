#ifndef BOLT_GB_CARTRIDGE_RAM_H_
#define BOLT_GB_CARTRIDGE_RAM_H_

#pragma once

#include "cartridge_hardware.h"

#include <memory>

namespace bolt {
    class gb_cartridge_ram : public gb_cartridge_hardware {
    public:
        virtual ~gb_cartridge_ram() override final = default;

        virtual uint8_t on_read(address_t address) const override final;

        virtual void on_write(address_t address, word_t value) override final;

    private:
        std::unique_ptr<byte_t> data;
    };

    inline uint8_t gb_cartridge_ram::on_read(address_t address) const {
        return data.get()[address];
    }

    inline void gb_cartridge_ram::on_write(address_t address, word_t value) {
        data.get()[address] = value;
    }
}

#endif