#ifndef BOLT_GB_INSTRUCTION_H_
#define BOLT_GB_INSTRUCTION_H_

#pragma once

#include "alu_operation_types.h"
#include "micro_instruction_types.h"

#include <cstdint>
#include <stdexcept>
#include <type_traits>

/*
||***********************************************************************INSTRUCTION ENCODING LAYOUT***************************************************************************||
||                                                                                     BITS                                                                                    ||
||*****************************************************************************************************************************************************************************||
||63                       61||60 56||55 51||50 46||45 41||40 36||35                            33||32  25||24  23||    22   ||21 17||16 12||11  9||    8    ||7    3||2      0||
||MICRO INSTR SEQUENCE LENGTH||       MICRO INSTR SEQUENCE      ||  MICRO INSTR SEQUENCE POSITION ||OPCODE||LENGTH||UPDATE PC|| DST || SRC || CC  || CC EVAL ||ALU OP||RESERVED||
||                           ||  5  ||  4  ||  3  ||  2  ||  1  ||                                ||      ||      ||         ||     ||     ||     ||         ||      ||        ||
||*****************************************************************************************************************************************************************************||
*/

#include <iostream>

namespace bolt {
    enum struct gb_instruction_register_type : uint64_t {
        none = 0x0ull,
        direct_a = 0x1ull,
        direct_b = 0x2ull,
        direct_c = 0x3ull,
        direct_d = 0x4ull,
        direct_e = 0x5ull,
        direct_h = 0x6ull,
        direct_l = 0x7ull,
        direct_bc = 0x8ull,
        direct_de = 0x9ull,
        direct_hl = 0xaull,
        direct_sp = 0xbull,
        indirect_hl = 0xcull
    };

    enum struct gb_instruction_immediate_type : uint64_t {
        d8 = 0xdull,
        d16 = 0xeull,
        a8 = 0xfull,
        a16 = 0x10ull,
        r8 = 0x11ull
    };

    enum struct gb_instruction_cc : uint64_t {
        none = 0x0ull << 0u,
        c = 0x1ull << 4u,
        h = 0x1ull << 5u,
        n = 0x1ull << 6u,
        z = 0x1ull << 7u
    };

    static constexpr auto gb_instruction_micro_instr_sequ_len_shift = 61u;
    static constexpr auto gb_instruction_micro_instr_sequ_shift = 36u;
    static constexpr auto gb_instruction_micro_instr_sequ_pos_shift = 33u;
    static constexpr auto gb_instruction_opcode_shift = 25u;
    static constexpr auto gb_instruction_length_shift = 23u;
    static constexpr auto gb_instruction_udate_pc_shift = 22u;
    static constexpr auto gb_instruction_dst_shift = 17u;
    static constexpr auto gb_instruction_src_shift = 12u;
    static constexpr auto gb_instruction_cc_shift = 9u;
    static constexpr auto gb_instruction_cc_eval_shift = 8u;
    static constexpr auto gb_instruction_alu_op_shift = 3u;

    static constexpr auto gb_instruction_micro_instr_sequ_len_mask = 0x07ull;
    static constexpr auto gb_instruction_micro_instr_sequ_mask     = 0x1full;
    static constexpr auto gb_instruction_micro_instr_sequ_pos_mask = 0x07ull;
    static constexpr auto gb_instruction_opcode_mask               = 0xffull;
    static constexpr auto gb_instruction_length_mask               = 0x03ull;
    static constexpr auto gb_instruction_udate_pc_mask             = 0x01ull;
    static constexpr auto gb_instruction_dst_mask                  = 0x1full;
    static constexpr auto gb_instruction_src_mask                  = 0x1full;
    static constexpr auto gb_instruction_cc_mask                   = 0x07ull;
    static constexpr auto gb_instruction_cc_eval_mask              = 0x01ull;
    static constexpr auto gb_instruction_alu_op_mask               = 0x1full;

    static constexpr auto gb_instruction_micro_instr_sequ_bits = 5u;

    //using gb_instruction_t = uint64_t;

    class gb_instruction {
    public:
        ~gb_instruction() = default;

        gb_instruction(const gb_instruction &) = default;
        gb_instruction(gb_instruction &&) = default;

        gb_instruction &operator=(const gb_instruction &) = default;
        gb_instruction &operator=(gb_instruction &&) = default;

    protected:
        constexpr gb_instruction() = delete;
        constexpr
    };

    class gb_instruction_builder : gb_instruction {
    public:
        constexpr gb_instruction_builder()
            : instruction(0ull) {

        }
        ~gb_instruction_builder() = default;

        constexpr gb_instruction_builder(const gb_instruction_builder &) = delete;
        constexpr gb_instruction_builder &operator=(const gb_instruction_builder &) = delete;

         gb_instruction_builder(const gb_instruction_builder &) = delete;
         gb_instruction_builder &operator=(gb_instruction_builder &&) = delete;

        constexpr gb_instruction_builder &encode_micro_instr_sequ_len(size_t sequ_len) {
            if (sequ_len < 1 || sequ_len > 5u) {
                // throw std::logic_error("gb_instruction_builder::encode_micro_instr_sequ_len(): 'sequ_len' must fall in range of 1 to 5");
            }

            instruction |= static_cast<gb_instruction_t>(sequ_len) << gb_instruction_micro_instr_sequ_len_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_micro_instr_sequ(size_t sequ, gb_micro_instruction_type instr) {

            instruction |= static_cast<gb_instruction_t>(instr) << (gb_instruction_micro_instr_sequ_shift + (sequ - 1ull) * gb_instruction_micro_instr_sequ_bits);

            return *this;
        }

        constexpr gb_instruction_builder &encode_opcode(uint8_t opcode) {
            instruction |= static_cast<gb_instruction_t>(opcode) << gb_instruction_opcode_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_length(uint8_t length) {
            instruction |= static_cast<gb_instruction_t>(length) << gb_instruction_length_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_update_pc(bool update) {
            instruction |= static_cast<gb_instruction_t>(update) << gb_instruction_udate_pc_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_destination(gb_instruction_register_type destination) {
            instruction |= static_cast<gb_instruction_t>(destination) << gb_instruction_dst_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_destination(gb_instruction_immediate_type destination) {
            instruction |= static_cast<gb_instruction_t>(destination) << gb_instruction_dst_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_source(gb_instruction_register_type source) {
            instruction |= static_cast<gb_instruction_t>(source) << gb_instruction_src_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_source(gb_instruction_immediate_type source) {
            instruction |= static_cast<gb_instruction_t>(source) << gb_instruction_src_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_cc(gb_instruction_cc cc) {
            instruction |= static_cast<gb_instruction_t>(cc) << gb_instruction_cc_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_evaluate_cc(bool evaluate) {
            instruction |= static_cast<gb_instruction_t>(evaluate) << gb_instruction_cc_eval_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_alu_operation(gb_alu_operation_type op_type) {
            instruction |= static_cast<gb_instruction_t>(op_type) << gb_instruction_alu_op_shift;

            return *this;
        }

        constexpr gb_instruction build(void) {
            auto instr = instruction;

            instr |= 1ull << gb_instruction_micro_instr_sequ_pos_shift;

            reset();

            return instr;
        }

    private:
        constexpr void reset(void) {
            instruction = 0ull;
        }

    private:
        gb_instruction_t instruction;
    };

    inline auto gb_decode_micro_instr_sequ_pos(gb_instruction_t instr) -> uint64_t {

        return instr >> gb_instruction_micro_instr_sequ_pos_shift & gb_instruction_micro_instr_sequ_pos_mask;
    }

    inline auto gb_decode_micro_instr_sequ(gb_instruction_t instr, size_t sequ) -> uint64_t {

        return instr >> (gb_instruction_micro_instr_sequ_shift + (sequ - 1ull) * gb_instruction_micro_instr_sequ_bits) & gb_instruction_micro_instr_sequ_mask;
    }

    inline auto gb_decode_instr_opcode(gb_instruction_t instr) -> uint64_t {

        return instr >> gb_instruction_opcode_shift & gb_instruction_opcode_mask;
    }

    inline auto gb_decode_instr_length(gb_instruction_t instr) -> uint64_t {

        return instr >> gb_instruction_length_shift & gb_instruction_length_mask;
    }
    
    inline auto gb_decode_instr_update_pc(gb_instruction_t instr) -> uint64_t {

        return instr >> gb_instruction_udate_pc_shift & gb_instruction_udate_pc_mask;
    }

    inline auto gb_decode_instr_cc(gb_instruction_t instr) -> uint64_t {

        return instr >> gb_instruction_cc_shift & gb_instruction_cc_mask;
    }

    inline auto gb_decode_instr_cc_eval(gb_instruction_t instr) -> uint64_t {

        return instr >> gb_instruction_cc_eval_shift & gb_instruction_cc_eval_mask;
    }

    inline auto gb_advance_micro_instr(gb_instruction_t instr) -> gb_instruction_t {
        const auto micro_instr_sequ_pos = gb_decode_micro_instr_sequ_pos(instr);

        return instr ^ (instr & gb_instruction_micro_instr_sequ_pos_mask << gb_instruction_micro_instr_sequ_pos_shift) ^ ((micro_instr_sequ_pos + 1ull) << gb_instruction_micro_instr_sequ_pos_shift);
    }
}

#endif