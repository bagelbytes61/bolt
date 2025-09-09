#ifndef BOLT_GB_ROM_H_
#define BOLT_GB_ROM_H_

#pragma once

#include "hardware.hh"

#include <array>
#include <cstddef>
#include <cstdint>

namespace bolt {
    class gb_vram : public gb_hardware {
    public:
        static constexpr addr_range_t addr_range = make_addr_range(0x8000u, 0xa000u);

    public:
        virtual ~gb_vram() override final = default;

        virtual word_t 
            on_read_word(addr_t addr) const override final;

        virtual void 
            on_write_word(addr_t addr, word_t value) override final;

    private:
        std::array<byte_t, 0x2000u> data;
    };

    inline auto gb_vram::on_read_word(addr_t addr) const -> word_t {
        return data[addr];
    }

    inline auto gb_vram::on_write_word(addr_t addr, word_t value) -> void {
        data[addr] = value;
    }
}

#endif