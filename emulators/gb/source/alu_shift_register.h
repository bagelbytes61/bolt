//#ifndef BOLT_GB_ALU_SHIFT_REGISTER_H_
//#define BOLT_GB_ALU_SHIFT_REGISTER_H_
//
//#pragma once
//
//#include "alu_peripheral.hh"
//#include "cpu.hh"
//#include "operand.hh"
//
////#include "alu_bus.h"
////#include "register_bus.hh"
//
//namespace bolt {
//    class gb_alu_shift_register : public gb_alu_peripheral {
//    public:
//        gb_alu_shift_register(gb_cpu::gb_register_bus &register_bus, gb_alu_bus &alu_bus)
//            : register_bus(register_bus)
//            , alu_bus(alu_bus) {
//        
//        }
//        ~gb_alu_shift_register() = default;
//
//        virtual auto read(void) const -> byte_t override final {
//            return value;
//        }
//        
//        virtual auto write(byte_t) -> void override final {
//
//        }
//
//        auto set_register(gb_register8_type reg_type) -> void {
//            reg = &register_bus.get_register(reg_type);
//        }
//
//        auto load_unshifted(void) -> void {            
//            value = *reg;
//        }
//
//        auto load_shifted_left(void) ->  bit_t {            
//            const bit_t bit = *reg >> 7u;
//
//            value = *reg << 1u;
//
//            return bit;
//        }
//
//        auto load_shifted_right(void) -> bit_t {            
//            const bit_t bit = *reg & 0x1;
//
//            value = *reg >> 1u;
//
//            return bit;
//        }
//
//    private:
//        //gb_cpu::gb_register_bus &register_bus;
//
//        gb_alu_bus &alu_bus;
//
//        gb_register8_t *reg;
//    
//        byte_t value;
//    };
//}
//
//#endif