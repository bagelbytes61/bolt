#include "micro_instructions.h"

#include "instruction_table.h"
#include "register_bus.h"

using namespace bolt;

namespace bolt {
    static std::array<gb_instruction_t, 0xffu> gb_instr_encode_table = gb_generate_instr_encode_table();

    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::not_implemented) {
        std::puts("!!!INSTRUCTION NOT IMPLEMENTED!!!");
        std::printf("PC: %#06x\n",       static_cast<gb_register16_t>(register_bus->get_register(gb_register16_type::pc)));
        std::printf("Instruction: %#04x\n", peripheral_bus->read_word(register_bus->get_register(gb_register16_type::pc)));

        assert(false);
    }

    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::internal_delay) {
        auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);

        ir = gb_advance_micro_instr(ir);
    }

    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::decode_pc) {
        auto pc = register_bus->get_register(gb_register16_type::pc);
        auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);

        if (gb_decode_instr_update_pc(ir)) {
            pc += static_cast<gb_register16_t>(gb_decode_instr_length(ir));
        }

        // Note that this is copying via the proxy to the underlying register itself.
        ir = gb_instr_encode_table[peripheral_bus->read_word(pc)];

        std::printf("Instruction: %#04x\n", (uint16_t)gb_decode_instr_opcode(ir));

        //auto f = register_bus->get_register(gb_register8_type::f);
        //if ((GB_DECODE_CC(ir) != GB_CC_NONE) && (f & GB_DECODE_CC(ir))) {
        //    f ^= ((f & GB_CC_EVAL_MASK) ^ GB_ENCODE_CC_EVAL(GB_CC_EVAL_TRUE));
        //}

        //if ((GB_DECODE_ALU_OP(ir) != GB_ALU_OP_NOP)) {
        //    
        //}
    }

    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::fetch_pch) {
        auto pc = register_bus->get_register(gb_register16_type::pc);
        auto w = register_bus->get_internal_register(gb_internal_register8_type::w);

        w = peripheral_bus->read_word(pc + 2u);

        auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);

        if (gb_decode_instr_cc(ir) == static_cast<gb_instruction_t>(gb_instruction_cc::none) || gb_decode_instr_cc_eval(ir)) {
            // Note that these are copying via the proxies to the underlying registers
            pc.get_high_register() = register_bus->get_internal_register(gb_internal_register8_type::w);
            pc.get_low_register() = register_bus->get_internal_register(gb_internal_register8_type::z);
        }
        
        // Note that this is copying via the proxy to the underlying register
        ir = gb_advance_micro_instr(ir);
    }

    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::fetch_pcl) {
        auto pc = register_bus->get_register(gb_register16_type::pc);
        auto z = register_bus->get_internal_register(gb_internal_register8_type::z);

        // Note that this is copying via the proxy to the underlying register itself.
        z = peripheral_bus->read_word(pc + 1u);

        auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);

        // Note that this is copying via the proxy to the underlying register
        ir = gb_advance_micro_instr(ir);
    }

    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::push_pch) {
        auto pch = register_bus->get_register(gb_register16_type::pc).get_high_register();
        
        pch.push();

        auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);

        // Note that this is copying via the proxy to the underlying register
        ir = gb_advance_micro_instr(ir);
    }

    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::push_pcl) {
        auto pcl = register_bus->get_register(gb_register16_type::pc).get_high_register();
        
        pcl.push();

        auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);

        // Note that this is copying via the proxy to the underlying register
        ir = gb_advance_micro_instr(ir);
    }

    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::pop_pch) {
        auto pch = register_bus->get_register(gb_register16_type::pc).get_high_register();
        
        pch.pop();

        auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);

        // Note that this is copying via the proxy to the underlying register
        ir = gb_advance_micro_instr(ir);
    }

    GB_MICRO_INSTRUCTION_DEFINITION(gb_micro_instruction_type::pop_pcl) {
        auto pcl = register_bus->get_register(gb_register16_type::pc).get_high_register();
        
        pcl.pop();

        auto ir = register_bus->get_internal_register(gb_internal_register64_type::ir);

        // Note that this is copying via the proxy to the underlying register
        ir = gb_advance_micro_instr(ir);
    }
}