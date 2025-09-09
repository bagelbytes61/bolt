#ifndef BOLT_GB_CARTRIDGE_RAM_H_
#define BOLT_GB_CARTRIDGE_RAM_H_

#pragma once

#include "cartridge_hardware.h"

#include <memory>

namespace bolt {
    class gb_cartridge_ram : public gb_cartridge_hardware {
    public:
        virtual ~gb_cartridge_ram() override final = default;

        virtual word_t on_read_word(addr_t addr) const override final;

        virtual void on_write_word(addr_t addr, word_t value) override final;

    private:
        std::unique_ptr<byte_t[]> data;
    };

    inline word_t gb_cartridge_ram::on_read_word(addr_t addr) const {
        
        return data[addr];
    }

    inline void gb_cartridge_ram::on_write_word(addr_t addr, word_t value) {
        
        data[addr] = value;
    }
}

#endif