//#include "alu.h"
//
//using namespace bolt;
//
//gb_alu::gb_alu(gb_cpu::gb_register_bus &register_bus)
//    : high_shift_register(register_bus, high_bus)
//    , low_shift_register(register_bus, low_bus)
//    , high_bus(high_shift_register, register_bus, gb_alu_bus_part::high)
//    , low_bus(low_shift_register, register_bus, gb_alu_bus_part::low)
//    , op1_high_latch(high_bus, op1_multiplexer, gb_alu_latch_part::high)
//    , op1_low_latch(low_bus, op1_multiplexer, gb_alu_latch_part::low)
//    , op2_high_latch(high_bus, op2_multiplexer, gb_alu_latch_part::high)
//    , op2_low_latch(low_bus, op2_multiplexer, gb_alu_latch_part::low)
//    , result_latch(core, low_bus, gb_alu_latch_part::low)
//    , op1_multiplexer(op1_high_latch, op1_low_latch)
//    , op2_multiplexer(op2_high_latch, op2_low_latch)
//    , core(op1_multiplexer, op2_multiplexer, high_bus, result_latch, register_bus.get_register(gb_register8_type::f)) {
//
//}
//
//auto gb_alu::machine_cycle(void) -> void {
//    bit_t shift_bit = 0;
//
//    const auto op1_reg_type = static_cast<gb_register8_type>(op1 & 0xf);
//    const auto op2_reg_type = static_cast<gb_register8_type>(op2 & 0xf);
//
//    high_shift_register.set_register(op1_reg_type);
//    low_shift_register.set_register(op2_reg_type);
//
//    high_bus.set_register(op1_reg_type);
//    low_bus.set_register(op1_reg_type);
//
//    if (operation == gb_alu_op_type::_sla) {
//        shift_bit = high_shift_register.load_shifted_left();
//        low_shift_register.load_shifted_left();
//    } else if (operation == gb_alu_op_type::_sra) {
//        high_shift_register.load_shifted_right();
//        shift_bit = low_shift_register.load_shifted_right();
//    } else {
//        high_shift_register.load_unshifted();
//        low_shift_register.load_unshifted();
//    }
//    
//    op1_high_latch.latch();
//    op1_low_latch.latch();
//
//    high_bus.set_register(op2_reg_type);
//    low_bus.set_register(op2_reg_type);
//
//    if (operation == gb_alu_op_type::_sla) {
//        shift_bit = high_shift_register.load_shifted_left();
//        low_shift_register.load_shifted_left();
//    } else if (operation == gb_alu_op_type::_sra) {
//        high_shift_register.load_shifted_right();
//        shift_bit = low_shift_register.load_shifted_right();
//    } else {
//        high_shift_register.load_unshifted();
//        low_shift_register.load_unshifted();
//    }
//
//    op2_high_latch.latch();
//    op2_low_latch.latch();
//
//    core.machine_cycle(operation, shift_bit);
//
//    //if ((operand_a | operand_b) & gb_instruction_operand_flag::register16) {
//    //    if (state == internal_state::low) {
//    //        state = internal_state::high;
//    //    } else {
//    //        state = internal_state::low;
//    //    }
//    //}
//}
//
//auto gb_alu::set_operands(gb_instruction_operand_t a, gb_instruction_operand_t b) -> void {
//    op1 = a;
//    op2 = b;
//}
//
//auto gb_alu::set_operation(gb_alu_op_type operation) -> void {
//    this->operation = operation;
//}