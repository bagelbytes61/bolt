#ifndef GB_REGISTER_BUS_H_
#define GB_REGISTER_BUS_H_

#pragma once

#include "cpu.h"

namespace bolt {
    class gb_cpu::gb_register_bus : gb_cpu {
    public:
        template<typename gb_register_type>
        gb_register_proxy<gb_register_type> get_register(gb_register_type reg_type);
        
        template<typename gb_internal_register_type>
        gb_register_proxy<gb_internal_register_type> get_internal_register(gb_internal_register_type reg_type);
    };

    template<typename gb_register_type>
    auto gb_cpu::gb_register_bus::get_register(gb_register_type reg_type) -> gb_register_proxy<gb_register_type> {

        return gb_cpu::get_register(reg_type);
    }

    template<typename gb_internal_register_type>
    auto gb_cpu::gb_register_bus::get_internal_register(gb_internal_register_type reg_type) -> gb_register_proxy<gb_internal_register_type> {

        return gb_cpu::get_internal_register(reg_type);
    }
}

#endif