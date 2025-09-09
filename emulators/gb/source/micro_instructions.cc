//#include "micro_instructions.h"
//
//#include "alu.h"
//#include "instruction_table.h"
//#include "operand.hh"
//#include "register_bus.hh"
//#include "tstate.hh"
//
//#include <variant>
//
//namespace bolt {
//    static std::array<gb_instruction_t, 0xffu> gb_instr_encode_table = gb_generate_instr_encode_table();
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::not_implemented) {
//        std::puts("!!!INSTRUCTION NOT IMPLEMENTED!!!");
//        //std::printf("PC: %#06x\n",       static_cast<gb_register16_t>(register_bus->get_register(gb_register16_type::pc)));
//        //std::printf("Instruction: %#04x\n", peripheral_bus->read_word(register_bus->get_register(gb_register16_type::pc)));
//
//        assert(false);
//
//        return { };
//    }
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::internal_delay) {
//        //auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//
//        //if (gb_instr_opcode(ir) == 0x20) {
//            //auto pc = reg_file->get_register(gb_register16_type::pc);
//            //auto z = reg_file->get_register(gb_internal_register8_type::z);
//
//            //int8_t r8;
//            //const gb_register8_t v = z;
//            //std::memcpy(&r8, &v, sizeof(r8));
//
//            //pc += r8;
//        //}
//
//        //if (gb_instr_alu_op(ir) != gb_alu_op_type::_nop) {
//        //    //alu->machine_cycle();
//        //}
//
//        //ir = gb_instr_advance_micro_instr(ir);
//
//        return { };
//    }
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::fetch) {
//        //auto pc = reg_file->get_register(gb_register16_type::pc);
//
//        //if (tstate.flags & gb_tstate::mem_access_complete) {
//        //    //auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//
//        //    //gb_instr_encode_table[tstate.data];
//
//        //    return { };
//        //} 
//
//        return { };
//    }
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::decode) {
//        //auto pc = reg_file->get_register(gb_register16_type::pc);
//        //auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//
//        //const bool update_pc = gb_instr_update_pc(ir);
//
//
//
//        //switch (gb_instr_opcode(ir)) {
//        //    case 0xf3: /* DI */
//        //        break;
//        //}
//
//        //if (update_pc) {
//        //    pc += static_cast<gb_register16_t>(gb_instr_length(ir));
//        //} 
//
//        //ir = gb_instr_encode_table[peripheral_bus->read_word(pc)];
//
//        //std::printf("PC: %#06x\n", static_cast<gb_register16_t>(reg_file->get_register(gb_register16_type::pc)));
//        //std::printf("Instruction: %#04x\n", (uint16_t)gb_instr_opcode(ir));
//
//        //if (const auto op = gb_instr_alu_op(ir); op != gb_alu_op_type::_nop) {
//        //    alu->set_operands(gb_instr_src(ir), gb_instr_dst(ir));
//        //    alu->set_operation(op);
//        //}
//
//        return { };
//    }
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::fetch_pch) {
//        //auto pc = reg_file->get_register(gb_register16_type::pc);
//        //auto w = reg_file->get_register(gb_internal_register8_type::w);
//
//        ////w = peripheral_bus->read_word(pc + 2u);
//
//        //pc.get_high_register() = reg_file->get_register(gb_internal_register8_type::w);
//        //pc.get_low_register() = reg_file->get_register(gb_internal_register8_type::z);
//
//        //auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//
//        //ir = gb_instr_advance_micro_instr(ir);
//    
//        return { };
//    }
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::fetch_pcl) {
//        //auto pc = reg_file->get_register(gb_register16_type::pc);
//        //auto z = reg_file->get_register(gb_internal_register8_type::z);
//
//        //z = peripheral_bus->read_word(pc + 1u);
//
//        //auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//
//        //ir = gb_instr_advance_micro_instr(ir);
//
//        return { };
//    }
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::push_pch) {
//        //auto pch = reg_file->get_register(gb_register16_type::pc).get_high_register();
//        
//        //pch.push();
//
//        //auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//
//        //ir = gb_instr_advance_micro_instr(ir);
//
//        return { };
//    }
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::push_pcl) {
//        //auto pcl = reg_file->get_register(gb_register16_type::pc).get_high_register();
//        
//        //pcl.push();
//
//        //auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//
//        //ir = gb_instr_advance_micro_instr(ir);
//    
//        return { };
//    }
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::pop_pch) {
//        //auto pch = reg_file->get_register(gb_register16_type::pc).get_high_register();
//        
//        //pch.pop();
//
//        //auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//
//        //ir = gb_instr_advance_micro_instr(ir);
//    
//        return { };
//    }
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::pop_pcl) {
//        //auto pcl = reg_file->get_register(gb_register16_type::pc).get_high_register();
//        
//        //pcl.pop();
//
//        //auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//
//        //ir = gb_instr_advance_micro_instr(ir);
//    
//        return { };
//    }
//
//    template<typename t, typename v>
//    constexpr auto cast_enum(t value) {
//        return static_cast<std::underlying_type_t<v>>(value);
//    }
//
//    //enum struct gb_immediate_operand_type : std::underlying_type_t<gb_instruction_operand_type> {
//    //    d8 = cast_enum<gb_immediate_operand_type>(gb_instruction_operand_type::d8),
//    //    d16 = cast_enum<gb_instruction_operand_type>(gb_instruction_operand_type::d16)
//    //};
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::load_msb) {
//        //auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//
//        //if (gb_instr_dst(ir) & gb_instruction_operand_flag::indirect) {
//        //    auto pc = register_bus->get_register(gb_register16_type::pc);
//        //    auto w = register_bus->get_internal_register(gb_internal_register8_type::w);
//
//        //    //w = peripheral_bus->read_word(peripheral_bus->read_word(pc + 2));
//        //} else {
//        //    const auto src = gb_operand(register_bus, peripheral_bus, gb_instr_src(ir));
//        //    auto dst = gb_operand(register_bus, peripheral_bus, gb_instr_dst(ir));
//
//        //    dst.load(src);
//        //}
//
//        //ir = gb_instr_advance_micro_instr(ir);
//    
//        return { };
//    }
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::load_lsb) {
//        //auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//        //
//        //if (gb_instr_src(ir) & gb_instruction_operand_flag::indirect) {
//        //    auto pc = register_bus->get_register(gb_register16_type::pc);
//        //    auto z = register_bus->get_internal_register(gb_internal_register8_type::z);
//
//        //    //z = peripheral_bus->read_word(peripheral_bus->read_word(pc + 1));
//        //} else {
//        //    const auto src = gb_operand(register_bus, peripheral_bus, gb_instr_src(ir));
//        //    auto dst = gb_operand(register_bus, peripheral_bus, gb_instr_dst(ir));
//
//        //    dst.load(src);
//        //}
//
//        //ir = gb_instr_advance_micro_instr(ir);
//    
//        return { };
//    }
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::store_msb) {
//        //auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//    
//        //const auto src = gb_operand(register_bus, peripheral_bus, gb_instr_src(ir));
//        //auto dst = gb_operand(register_bus, peripheral_bus, gb_instr_dst(ir));
//
//        //src.store(dst);
//
//        //ir = gb_instr_advance_micro_instr(ir);
//    
//        return { };
//    }
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::store_lsb) {
//        //auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//
//        ////if (gb_instr_src(ir) == gb_instruction_operand_type::a8) {
//        ////    const auto src = gb_operand(register_bus, peripheral_bus, gb_internal_register8_type::z);
//
//        ////} else {
//
//        ////}
//    
//        //const auto src = gb_operand(register_bus, peripheral_bus, gb_instr_src(ir));
//        //auto dst = gb_operand(register_bus, peripheral_bus, gb_instr_dst(ir));
//
//        //src.store(dst);
//
//        //ir = gb_instr_advance_micro_instr(ir);
//    
//        return { };
//    }
//
//    GB_MICRO_INSTRUCTION_PROTOTYPE(gb_micro_instruction_type::jump_rel) {
//        //auto pc = register_bus->get_register(gb_register16_type::pc);
//        //auto z = register_bus->get_internal_register(gb_internal_register8_type::z);
//
//        ////z = peripheral_bus->read_word(pc + 1);
//
//        //auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//
//        //if (const auto cc = (gb_instr_cc(ir) & ~gb_instruction_cc::reset) << 4u) {
//        //    auto f = register_bus->get_register(gb_register8_type::f);
//
//        //    const bool reset = gb_instr_cc(ir) & gb_instruction_cc::reset;
//
//        //    if (!reset && !(f & cc) || reset && (f & cc)) {
//        //        // Skip the next (internal delay) micro instruction
//        //        ir = gb_instr_advance_micro_instr(ir);
//        //    }
//        //}
//
//        //ir = gb_instr_advance_micro_instr(ir);
//    
//        return { };
//    }
//
//    /* 
//        The following two micro instructions operate strictly on (16-bit) registers, which
//        is why we clear the indirect instruction operand flag (Instructions such as LD (HL-), A
//        will set this flag but ultimately still require a register decrement or increment)
//    */
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::increment) {
//        //auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//
//        //auto dst = register_bus->get_register(static_cast<gb_register16_type>(gb_instr_dst(ir)));
//
//        //++dst;
//
//        //ir = gb_instr_advance_micro_instr(ir);
//    
//        return { };
//    }
//
//    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::decrement) {
//       // auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);
//
//       // auto dst = register_bus->get_register(static_cast<gb_register16_type>(gb_instr_dst(ir)));
//
//       //--dst;
//
//       // ir = gb_instr_advance_micro_instr(ir);
//    
//        return { };
//    }
//}