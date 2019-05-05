#ifndef BOLT_GB_ALU_H_
#define BOLT_GB_ALU_H_

#pragma once

#include "cpu.h"
#include "instruction_encoding.h"
#include "register_type.h"

#include <cstdint>

namespace bolt {
    using gb_alu_register = uint8_t;
    using gb_alu_latch    = uint8_t;

    enum struct gb_alu_operation : uint8_t {
        _dec, _inc,
        _rl,  _rr,
        _sla, _sra,
        _bit,
        _add, _adc, _sub,
        _and, _xor, _or,
        _unknown
    };

    enum struct gb_operand_type : uint8_t {
        register8,
        register16,
        indirect,
        immediate
    };

#define GB_ALU_NO_INPUT  0xff
#define GB_ALU_NO_OUTPUT 0xff

#define GB_ALU_OP_NOP    0x00
#define GB_ALU_OP_INC    0x01
#define GB_ALU_OP_DEC    0x02
#define GB_ALU_OP_ADD    0x03
#define GB_ALU_OP_ADC    0x04
#define GB_ALU_OP_SUB    0x05
#define GB_ALU_OP_SBC    0x06
#define GB_ALU_OP_AND    0x07
#define GB_ALU_OP_XOR    0x08
#define GB_ALU_OP_OR     0x09
#define GB_ALU_OP_BIT    0x0a
#define GB_ALU_OP_SWAP   0x0b
#define GB_ALU_OP_CP     0x0c
#define GB_ALU_OP_RL     0x0d
#define GB_ALU_OP_RR     0x0e
#define GB_ALU_OP_RLA    0x0f
#define GB_ALU_OP_RRA    0x10
#define GB_ALU_OP_RLCA   0x11
#define GB_ALU_OP_RRCA   0x12
#define GB_ALU_OP_SLA    0x13
#define GB_ALU_OP_SRA    0x14

    class gb_alu {
    public:
        gb_alu(gb_cpu *cpu)             
            : in0_hi(GB_ALU_NO_INPUT),  in0_lo(GB_ALU_NO_INPUT)
            , in1_hi(GB_ALU_NO_INPUT),  in1_lo(GB_ALU_NO_INPUT)
            , out_hi(GB_ALU_NO_OUTPUT), out_lo(GB_ALU_NO_OUTPUT)
            , cpu(cpu) {
        }
        ~gb_alu() {}

        void machine_cycle() {
            if (((in0_hi & in0_lo) & GB_ALU_NO_INPUT) ||
                ((in1_hi & in1_lo) & GB_ALU_NO_INPUT)) {

                return;
            }

            auto ir = cpu->get_internal_register(gb_internal_register64_type::ir);

            auto op = decode_operation(static_cast<uint64_t>(ir));
            switch (op) {
                case gb_alu_operation::_dec: break;
                case gb_alu_operation::_inc: break;
                case gb_alu_operation::_rl: break;
                case gb_alu_operation::_rr: break;
                case gb_alu_operation::_sla: break;
                case gb_alu_operation::_sra: break;
                case gb_alu_operation::_bit: break;
                case gb_alu_operation::_add: break;
                case gb_alu_operation::_adc: break;
                case gb_alu_operation::_sub: break;
                case gb_alu_operation::_and: break;
                case gb_alu_operation::_xor: break;
                case gb_alu_operation::_or: break;
            }
        }



    private:
        gb_alu_operation decode_operation(gb_internal_register64_t ir) {
            switch ((static_cast<uint64_t>(ir) & GB_ALU_OPERATION_MASK) >> 25) {
                case GB_ALU_OP_DEC: return gb_alu_operation::_dec;
                case GB_ALU_OP_INC: return gb_alu_operation::_inc;
                case GB_ALU_OP_RL:  return gb_alu_operation::_rl;
                case GB_ALU_OP_RR:  return gb_alu_operation::_rr;
                case GB_ALU_OP_SLA: return gb_alu_operation::_sla;
                case GB_ALU_OP_SRA: return gb_alu_operation::_sra;
                case GB_ALU_OP_BIT: return gb_alu_operation::_bit;
                case GB_ALU_OP_ADD: return gb_alu_operation::_add;
                case GB_ALU_OP_ADC: return gb_alu_operation::_adc;
                case GB_ALU_OP_SUB: return gb_alu_operation::_sub;
                case GB_ALU_OP_AND: return gb_alu_operation::_and;
                case GB_ALU_OP_XOR: return gb_alu_operation::_xor;
                case GB_ALU_OP_OR:  return gb_alu_operation::_or;
            }

            return gb_alu_operation::_unknown;
        }



        template<gb_operand_type, typename t>
        void _dec(t operand);

        template<typename gb_alu_operand_type>
        void _inc(gb_alu_operand_type operand);

        void _xor(uint8_t a, uint8_t b) {
        }

    private:
        gb_alu_operation operation;

        gb_alu_latch in0_hi, in0_lo;
        gb_alu_latch in1_hi, in1_lo;

        gb_alu_latch out_hi, out_lo;

        gb_cpu *cpu;
    };

    template<>
    inline auto gb_alu::_dec<gb_operand_type::register8>(gb_register8_type operand) -> void {
        auto reg = cpu->get_register(operand);
        if (static_cast<uint8_t>(reg) - 1 == 0) {

        }

        if ((static_cast<uint8_t>(reg) & 0x0f) > 0x00) {

        }

        reg += 1;
    }

    template<>
    inline auto gb_alu::_dec<gb_operand_type::register16>(gb_register16_type operand) -> void {
        auto reg = cpu->get_register(operand);

        reg += 1;
    }

    template<>
    inline auto gb_alu::_dec<gb_operand_type::indirect>(address_t operand) -> void {

    }

    template<>
    inline auto gb_alu::_inc<gb_register8_type>(gb_register8_type operand) -> void {
        auto destination = cpu->get_register(operand);
        if (static_cast<uint8_t>(destination) + 1 == 0) {

        }

        if ((static_cast<uint8_t>(destination) & 0x0f) == 0x0f) {

        }

        destination += 1;
    }
}

#endif