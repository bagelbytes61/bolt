#include "cpu.h"

#include "cpu_bus.h"
#include "instruction_meta_data.h"

using namespace bolt;

#define NES_BASE_INSTRUCTION_TO_COMPILE_TIME_VALUE(base)                                                \
base == NES_INSTRUCTION_ADC ? NES_INSTRUCTION_ADC : base == NES_INSTRUCTION_AND ? NES_INSTRUCTION_AND : \
base == NES_INSTRUCTION_ASL ? NES_INSTRUCTION_ASL : base == NES_INSTRUCTION_BCC ? NES_INSTRUCTION_BCC : \
base == NES_INSTRUCTION_BCS ? NES_INSTRUCTION_BCS : base == NES_INSTRUCTION_BEQ ? NES_INSTRUCTION_BEQ : \
base == NES_INSTRUCTION_BIT ? NES_INSTRUCTION_BIT : base == NES_INSTRUCTION_BMI ? NES_INSTRUCTION_BMI : \
base == NES_INSTRUCTION_BNE ? NES_INSTRUCTION_BNE : base == NES_INSTRUCTION_BRK ? NES_INSTRUCTION_BRK : \
base == NES_INSTRUCTION_BVC ? NES_INSTRUCTION_BVC : base == NES_INSTRUCTION_BVS ? NES_INSTRUCTION_BVS : \
base == NES_INSTRUCTION_CLC ? NES_INSTRUCTION_CLC : base == NES_INSTRUCTION_CLI ? NES_INSTRUCTION_CLI : \
base == NES_INSTRUCTION_CLV ? NES_INSTRUCTION_CLV : base == NES_INSTRUCTION_CMP ? NES_INSTRUCTION_CMP : \
base == NES_INSTRUCTION_CPX ? NES_INSTRUCTION_CPX : base == NES_INSTRUCTION_CPY ? NES_INSTRUCTION_CPY : 0 \

void nes_cpu::cycle() {
    uint8_t opcode = fetch_next_opcode();
    //constexpr uint8_t x = NES_BASE_INSTRUCTION_TO_COMPILE_TIME_VALUE(opcode);
}

void nes_cpu::handle_interrupts() {

}

uint8_t nes_cpu::fetch_next_opcode() const {
    return std::to_integer<uint8_t>(bus->read(NES_PC(this)));
}