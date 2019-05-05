#include "micro_instructions.h"

#include "instruction_table.h"

using namespace bolt;

constexpr std::array<uint64_t, 0xff> gb_instr_encode_table = gb_generate_instr_encode_table();

namespace bolt {
    GB_DEFINE_MICRO_INSTR(GB_MICRO_INSTR_NOT_IMPL) {
        std::printf("PC: %04x\n", static_cast<uint16_t>(cpu->get_register(gb_register16_type::pc)));
        std::printf("Instruction: %02x\n", bus->read(static_cast<uint16_t>(cpu->get_register(gb_register16_type::pc))));

        assert(false);
    }

    GB_DEFINE_MICRO_INSTR(GB_MICRO_INSTR_INTERNAL_DELAY) {

    }

    GB_DEFINE_MICRO_INSTR(GB_MICRO_INSTR_DECODE_PC) {
        auto pc = cpu->get_register(gb_register16_type::pc);
        auto ir = cpu->get_internal_register(gb_internal_register64_type::ir);

        if (GB_DECODE_INSTR_UPDATE_PC(ir)) {
            pc += GB_DECODE_INSTR_LEN(ir);
        }

        // Note that this is performing a deep-copy to the underlying register itself
        ir = gb_instr_encode_table[bus->read(pc)];

        auto f = cpu->get_internal_register(gb_register8_type::f);
        if (f & GB_DECODE_INSTR_CC(ir)) {
            f ^= ((f & GB_INSTR_CC_EVAL_MASK) ^ GB_ENCODE_INSTR_CC_EVAL(GB_INSTR_CC_EVAL_TRUE));
        }
    }

    GB_DEFINE_MICRO_INSTR(GB_MICRO_INSTR_FETCH_PCH) {
        auto pc = cpu->get_register(gb_register16_type::pc);
        auto w = cpu->get_internal_register(gb_internal_register8_type::w);

        w = bus->read(pc + 2);

        auto ir = cpu->get_internal_register(gb_internal_register64_type::ir);
        if (GB_DECODE_INSTR_CC_EVAL(ir) == GB_INSTR_CC_EVAL_TRUE) {
            // Note that these are performing deep-copies to the underlying registers themselves
            // rather than copying the register pointers
            pc.get_high_register() = cpu->get_internal_register(gb_internal_register8_type::w);
            pc.get_low_register() = cpu->get_internal_register(gb_internal_register8_type::z);
        }
    }

    GB_DEFINE_MICRO_INSTR(GB_MICRO_INSTR_FETCH_PCL) {
        auto pc = cpu->get_register(gb_register16_type::pc);
        auto z = cpu->get_internal_register(gb_internal_register8_type::z);

        z = bus->read(pc + 1);
    }

    GB_DEFINE_MICRO_INSTR(GB_MICRO_INSTR_PUSH_PCH) {
        auto pch = cpu->get_register(gb_register16_type::pc).get_high_register();
        pch.push();
    }

    GB_DEFINE_MICRO_INSTR(GB_MICRO_INSTR_PUSH_PCL) {
        auto pcl = cpu->get_register(gb_register16_type::pc).get_high_register();
        pcl.push();
    }

    GB_DEFINE_MICRO_INSTR(GB_MICRO_INSTR_POP_PCH) {
        auto pch = cpu->get_register(gb_register16_type::pc).get_high_register();
        pch.pop();
    }

    GB_DEFINE_MICRO_INSTR(GB_MICRO_INSTR_POP_PCL) {
        auto pcl = cpu->get_register(gb_register16_type::pc).get_high_register();
        pcl.pop();
    }
}