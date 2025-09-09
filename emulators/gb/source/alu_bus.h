#ifndef BOLT_GB_ALU_BUS_H_
#define BOLT_GB_ALU_BUS_H_

#pragma once

#include "alu_peripheral.hh"
#include "register_bus.hh"

#include <cstdint>

namespace bolt {
    class gb_alu_shift_register;

    enum struct gb_alu_bus_part {
        low,
        high
    };

    class gb_alu_bus : public gb_alu_peripheral {
    public:
        //gb_alu_bus(gb_alu_shift_register &shift_register, gb_cpu::gb_register_bus &register_bus, gb_alu_bus_part part);                                                                                                                            
        //~gb_alu_bus() = default;

        //virtual auto read(void) const -> byte_t override final;
        //
        //virtual auto write(nibble_t value) -> void override final;

        //auto set_register(gb_register8_type reg_type) -> void {
        //    reg = &register_bus.get_register(reg_type);
        //}

    private:
        //gb_alu_shift_register &shift_register;

        //gb_cpu::gb_register_bus &register_bus;

        //gb_alu_bus_part part;

        //gb_register8_t *reg;
    };
}

#endif