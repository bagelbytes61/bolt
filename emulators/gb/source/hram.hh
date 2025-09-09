#ifndef BOLT_GB_HRAM_HH_
#define BOLT_GB_HRAM_HH_

#pragma once

#include "hardware.hh"

#include <array>

namespace bolt {
    class gb_hram : public gb_hardware {
    public:
        static constexpr auto addr_range = make_addr_range(0xff80u, 0xffffu);

    public:
        virtual ~gb_hram() override final = default;

        virtual auto on_read_word(addr_t addr) const -> word_t override final;

        virtual auto on_write_word(addr_t addr, word_t value) -> void override final;

    private:
        std::array<byte_t, 0x7fu> data;
    };

    inline auto gb_hram::on_read_word(addr_t addr) const -> word_t {
        return data.at(addr);
    }

    inline auto gb_hram::on_write_word(addr_t addr, word_t value) -> void {
        data.at(addr) = value;
    }
}

#endif