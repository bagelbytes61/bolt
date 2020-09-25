#include "cpu.h"

#include "alu.h"
#include "instruction.h"
#include "micro_instruction_table.h"

using namespace bolt;

constexpr std::array<gb_micro_instruction_fn, 0xffu> gb_micro_instruction_table = gb_generate_micro_instr_jump_table();

static void print_ir(gb_internal_register64_t ir) {
    //std::printf("Micro instruction sequence length: %llu\n", GB_DECODE_MICRO_INSTR_SEQU_LEN(ir));
    //std::printf("Micro instruction sequence 5: %llu\n", GB_DECODE_MICRO_INSTR_SEQU_5(ir));
    //std::printf("Micro instruction sequence 4: %llu\n", GB_DECODE_MICRO_INSTR_SEQU_4(ir));
    //std::printf("Micro instruction sequence 3: %llu\n", GB_DECODE_MICRO_INSTR_SEQU_3(ir));
    //std::printf("Micro instruction sequence 2: %llu\n", GB_DECODE_MICRO_INSTR_SEQU_2(ir));
    //std::printf("Micro instruction sequence 1: %llu\n", GB_DECODE_MICRO_INSTR_SEQU_1(ir));
    //std::printf("Micro instruction sequence position: %llu\n", GB_DECODE_MICRO_INSTR_SEQU_POS(ir));
}

gb_cpu::gb_cpu(std::unique_ptr<gb_bus> &&bus)
    : a(0x01u), f(0xb0u)
    , b(0x00u), c(0x13u)
    , d(0x00u), e(0xd8u)
    , h(0x01u), l(0x4du)
    , pc(0x100u), sp(0xfffeu)
    , ir(0x00ull)
    , w(0x00u), z(0x00u)
    , bus(std::move(bus)) {

    // First decode the initial instruction at the current PC position as we always
    // decode the following instruction at the end of the current instruction.
    GB_MICRO_INSTRUCTION(gb_micro_instruction_type::decode_pc)(get_register_bus(), this->bus.get());
}

gb_cpu::~gb_cpu() {

}

void gb_cpu::machine_cycle(void) {
    const auto micro_instr_sequ_pos = gb_decode_micro_instr_sequ_pos(ir);

    const auto micro_instr_sequ = gb_decode_micro_instr_sequ(ir, static_cast<size_t>(micro_instr_sequ_pos));
    
    const auto micro_instr = gb_micro_instruction_table.at(static_cast<size_t>(micro_instr_sequ));

    micro_instr(get_register_bus(), bus.get());
}