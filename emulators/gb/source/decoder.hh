#ifndef BOLT_GB_DECODER_HH_
#define BOLT_GB_DECODER_HH_

#pragma once

#include "clock.hh"
#include "register_file.hh"

namespace bolt {
    struct gb_control_signals;

    class gb_decoder {
    public:
        gb_decoder(const gb_register8_t &ir)
            : ir(ir) {

        }

        auto clk(gb_control_signals &ctrl_signals, uint64_t cycle) -> void;

    private:
        const gb_register8_t &ir;
    };

    class gb_control_unit {
    public:
        gb_control_unit();

        auto clk(gb_control_signals &ctrl_signals, uint64_t cycle, gb_clock_state state) -> void;

    private:
        uint8_t current_t_cycle;

        bool is_fetch_cycle;
        bool is_exec_cycle;
    };
}


#endif