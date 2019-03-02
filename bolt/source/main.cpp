#include <array>
#include <vector>

struct nes_bus {
    template<typename addressing_mode>
    uint8_t read(uint16_t address) { return 0; }

    template<typename addressing_mode>
    static void write(uint16_t address, uint8_t data) { }
};

struct nes_cpu {
    uint8_t         a;

    uint8_t         x;
    uint8_t         y;

    uint8_t         sp;

    uint16_t        pc;

    uint8_t         p;

    nes_bus bus;
};

struct nes_addressing_mode_implicit;
struct nes_addressing_mode_immediate;

template<typename addressing_mode>
using nes_fn_micro_instruction = void(*)(nes_cpu&);

template<typename addressing_mode, size_t cycles, nes_fn_micro_instruction<addressing_mode>... instructions>
class nes_instruction {
    using fn_micro_instruction = nes_fn_micro_instruction<addressing_mode>;
    using micro_instruction_sequence = std::array<fn_micro_instruction, cycles>;

public:
    static void execute_micro_instruction(nes_cpu& cpu) {
        (*current_instruction)(cpu);

        if (++current_instruction == instruction_sequence.cend()) {
            current_instruction = instruction_sequence.cbegin();
        }
    }

private:
    static constexpr micro_instruction_sequence instruction_sequence = { {instructions...} };

    typename static inline micro_instruction_sequence::const_iterator current_instruction = instruction_sequence.cbegin();
};

struct nes_alu {

};


#define DEFINE_NES_MICRO_INSTRUCTION(name, code)    \
template<typename addressing_mode>                  \
struct name {                                       \
    static void execute(nes_cpu& cpu) {             \
        code;                                       \
    };                                              \
};

DEFINE_NES_MICRO_INSTRUCTION(fetch_opcode, printf("fetch opcode\n"))
DEFINE_NES_MICRO_INSTRUCTION(fetch_data, printf("fetch data\n"))
DEFINE_NES_MICRO_INSTRUCTION(fetch_discard_pc, printf("fetch discard pc\n"))
DEFINE_NES_MICRO_INSTRUCTION(fetch_discard_sp, printf("fetch discard sp\n"))
DEFINE_NES_MICRO_INSTRUCTION(push_pch, printf("push pch\n"))
DEFINE_NES_MICRO_INSTRUCTION(push_pcl, printf("push pcl\n"))
DEFINE_NES_MICRO_INSTRUCTION(pull_pch, printf("pull pch\n"))
DEFINE_NES_MICRO_INSTRUCTION(pull_pcl, printf("pull pcl\n"))
DEFINE_NES_MICRO_INSTRUCTION(push_p, printf("push p\n"))
DEFINE_NES_MICRO_INSTRUCTION(fetch_rvh, printf("fetch rvh\n"))
DEFINE_NES_MICRO_INSTRUCTION(fetch_rvl, printf("fetch rvl\n"))
DEFINE_NES_MICRO_INSTRUCTION(nes_and, printf("and\n"))

template<typename addressing_mode, size_t cycles, template<typename> typename ...micro_instructions>
struct nes_instruction_generator {
    using instruction = nes_instruction<addressing_mode, cycles, micro_instructions<addressing_mode>::execute...>;
};

int main(int argc, char* argv[]) {
    nes_cpu cpu;

    auto and_immediate = nes_instruction_generator<nes_addressing_mode_immediate, 2,
        fetch_data,
        fetch_opcode>::instruction::execute_micro_instruction;



    auto brk = nes_instruction_generator<nes_addressing_mode_implicit, 7,
        fetch_discard_pc,
        push_pch,
        push_pcl,
        push_p,
        fetch_rvh,
        fetch_rvl,
        fetch_opcode>::instruction::execute_micro_instruction;

    auto rts = nes_instruction_generator<nes_addressing_mode_implicit, 6,
        fetch_discard_pc,
        fetch_discard_sp,
        pull_pch,
        pull_pcl,
        fetch_discard_pc,
        fetch_opcode>::instruction::execute_micro_instruction;



    while (1) {
        //brk(cpu);
        rts(cpu);
    }

    return 0;
}

    /*
        Mode        Bit Sequence    Instruction     Bytes   Cycles
        Immediate   0110 1001       adc             2       2
        Zero Page   0110 0101       adc             2       3
        Immediate   0010 1001       and             2       2
        Zero Page   0010 0101       and             2       3
        Immediate   1100 1001       cmp             2       2
        Zero Page   1100 0101       cmp             2       3
        Immediate   1110 0000       cpx             2       2
        Zero Page   1110 0100       cpx             2       3
        Immediate   1100 0000       cpy             2       2
        Zero Page   1100 0100       cpy             2       3
        Immediate   0100 1001       eor             2       2
        Immediate   1010 1001       lda             2       2
        Immediate   1010 0010       ldx             2       2
        Immediate   1010 0000       ldy             2       2
        Immediate   0000 1001       ora             2       2
        Immediate   1110 1001       sbc             2       2

        Zero Page
     */