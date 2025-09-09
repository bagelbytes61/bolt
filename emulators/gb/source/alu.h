//#ifndef BOLT_GB_ALU_H_
//#define BOLT_GB_ALU_H_
//
//#pragma once
//
//#include "alu_bus.h"
//#include "alu_core.h"
//#include "alu_latch.h"
//#include "alu_multiplexer.h"
//#include "alu_operation_types.h"
//#include "alu_shift_register.h"
//#include "operand.hh"
//#include "register_bus.hh"
//
//namespace bolt {
//    class gb_cpu;
//
//    class gb_alu {
//    public:
//        gb_alu(gb_cpu::gb_register_bus &register_bus);
//        ~gb_alu() = default;
//
//        auto machine_cycle(void) -> void;
//
//        auto set_operands(gb_instruction_operand_t a, gb_instruction_operand_t b) -> void;
//        auto set_operation(gb_alu_op_type op) -> void;
//
//    private:
//        gb_alu_shift_register high_shift_register;
//        gb_alu_shift_register low_shift_register;
//        
//        gb_alu_op_type operation;
//
//        gb_instruction_operand_t op1;
//        gb_instruction_operand_t op2;
//        gb_alu_bus high_bus;
//        gb_alu_bus low_bus;
//
//        gb_alu_latch op1_high_latch;
//        gb_alu_latch op1_low_latch;
//        gb_alu_latch op2_high_latch;
//        gb_alu_latch op2_low_latch;
//
//        gb_alu_latch result_latch;
//        
//        gb_alu_multiplexer op1_multiplexer;
//        gb_alu_multiplexer op2_multiplexer;
//
//        gb_alu_core core;
//    };
//}
//
//#endif