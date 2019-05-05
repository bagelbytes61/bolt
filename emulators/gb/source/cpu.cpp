#include "cpu.h"

#include "alu.h"
#include "instruction_encoding.h"
#include "micro_instruction_table.h"

using namespace bolt;

constexpr std::array<gb_micro_instruction_fn, 0xff> gb_micro_instruction_table = gb_generate_micro_instr_jump_table();

gb_cpu::gb_cpu(std::unique_ptr<gb_bus> bus)
    : a(0x01u), f(0xb0u)
    , b(0x00u), c(0x13u)
    , d(0x00u), e(0xd8u)
    , h(0x01u), l(0x4du)
    , pc(0x100u), sp(0xfffeu)
    , ir(0x00ull)
    , w(0x00u), z(0x00u)
    , bus(std::move(bus))
    , alu(std::make_unique<gb_alu>(this)) {

    // First decode the initial instruction at the current PC position as we
    // decode the next instruction at the end of the current instruction
    GB_MICRO_INSTR(GB_MICRO_INSTR_DECODE_PC)(this, this->bus.get());

    // Next make sure to advance the micro instruction sequence position 
    // to the first micro instruction
    GB_ADVANCE_MICRO_INSTR(ir);
}

gb_cpu::~gb_cpu() {

}

void gb_cpu::machine_cycle() {
    if (GB_DECODE_ALU_OP(ir) != 0) {
        alu->machine_cycle();
    }

    switch (GB_DECODE_MICRO_INSTR_SEQU_POS(ir)) {
        case GB_MICRO_INSTR_SEQU_POS_1: gb_micro_instruction_table[GB_DECODE_MICRO_INSTR_SEQU_1(ir)](this, bus.get()); break;
        case GB_MICRO_INSTR_SEQU_POS_2: gb_micro_instruction_table[GB_DECODE_MICRO_INSTR_SEQU_2(ir)](this, bus.get()); break;
        case GB_MICRO_INSTR_SEQU_POS_3: gb_micro_instruction_table[GB_DECODE_MICRO_INSTR_SEQU_3(ir)](this, bus.get()); break;
        case GB_MICRO_INSTR_SEQU_POS_4: gb_micro_instruction_table[GB_DECODE_MICRO_INSTR_SEQU_4(ir)](this, bus.get()); break;
        case GB_MICRO_INSTR_SEQU_POS_5: gb_micro_instruction_table[GB_DECODE_MICRO_INSTR_SEQU_5(ir)](this, bus.get()); break;
    }

    GB_ADVANCE_MICRO_INSTR(ir);
}