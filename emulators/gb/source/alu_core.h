//#ifndef BOLT_GB_ALU_CORE_H_
//#define BOLT_GB_ALU_CORE_H_
//
//#pragma once
//
//#include "alu_operation_types.h"
//#include "alu_peripheral.hh"
//#include "common.h"
//#include "register_proxy.hh"
//
////#include "alu_bus.h"
////#include "alu_latch.h"
////#include "alu_multiplexer.h"
//
//namespace bolt {
//    class gb_alu_bus;
//    class gb_alu_latch;
//    class gb_alu_multiplexer;
//
//    struct gb_flag {
//        enum {
//            carry = 0x10u,
//            half_carry = 0x20u,
//            subtract = 0x40u,
//            zero = 0x80u
//        };
//    };
//
//    class gb_alu_core : public gb_alu_peripheral {
//    public:
//        gb_alu_core(gb_alu_multiplexer &operand_high, gb_alu_multiplexer &operand_low, gb_alu_bus &high_bus, gb_alu_latch &result_latch, gb_register8_proxy_t flags);
//        ~gb_alu_core();
//
//        virtual auto read(void) const -> byte_t override final;
//
//        virtual auto write(byte_t value) -> void override final;
//
//        void machine_cycle(gb_alu_op_type operation, bit_t shift_bit);
//
//    private:
//        auto _inc(uint8_t op, gb_register8_proxy_t f) -> uint8_t;
//        auto _dec(uint8_t op, gb_register8_proxy_t f) -> uint8_t;
//        
//        auto _xor(uint8_t op1, uint8_t op2, gb_register8_proxy_t f) -> uint8_t;
//        
//        auto _rrca(uint8_t op, gb_register8_proxy_t f) -> uint8_t;
//
//    private:
//        byte_t result;
//
//        gb_alu_multiplexer &op1;
//        gb_alu_multiplexer &op2;
//
//        gb_alu_bus &high_bus;
//        gb_alu_latch &result_latch;
//
//        gb_register8_proxy_t flags;
//    };
//}
//
//#endif