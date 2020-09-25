//#ifndef BOLT_GB_ALU_CORE_H_
//#define BOLT_GB_ALU_CORE_H_
//
//#pragma once
//
//#include "alu_bus.h"
//#include "alu_latch.h"
//
//namespace bolt {
//    class gb_alu_core {
//    public:
//        gb_alu_core(gb_alu_bus *hi_bus, gb_alu_latch *lo_latch, gb_register8_proxy_t flags);
//        ~gb_alu_core();
//
//        void machine_cycle(gb_alu_operation_type operation);
//
//    private:
//        uint8_t _inc(uint8_t in, gb_register8_proxy_t f);
//        uint8_t _dec(uint8_t in, gb_register8_proxy_t f);
//
//    private:
//        gb_alu_bus *hi_bus;
//        gb_alu_latch *lo_latch;
//
//        gb_register8_proxy_t flags;
//    };
//}
//
//#endif