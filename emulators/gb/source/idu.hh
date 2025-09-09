#ifndef BOLT_GB_IDU_HH_
#define BOLT_GB_IDU_HH_

#pragma once

#include "register_file.hh"

namespace bolt {
    struct gb_tstate;

    class gb_register_file::gb_idu {
    public:
        gb_idu(gb_register_file &register_file)
            : register_file(register_file) {

        }

        ~gb_idu() = default;

        auto clk(gb_control_signals &ctrl_signals, uint64_t cycle) -> void {
            if (ctrl_signals.en_idu_inc_pc) {
                register_file.pc += 1u;
            }
        }

    private:
        gb_register_file &register_file;
    };
}

#endif