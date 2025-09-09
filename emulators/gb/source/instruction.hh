#ifndef BOLT_GB_INSTRUCTION_H_
#define BOLT_GB_INSTRUCTION_H_

#pragma once

#include "alu_operation_types.h"
#include "micro_instruction_types.h"
#include "register_type.hh"

#include <cstdint>
#include <stdexcept>
#include <type_traits>

/*
||**********************************************************INSTRUCTION ENCODING LAYOUT**********************************************************||
||                                                                     BITS                                                                      ||
||***********************************************************************************************************************************************||
||63 59||58 54||53 49||48 44||43 39||38                            36||35  28||27  26||    25   ||24 17||16  9||8  5||4                         0||
||       MICRO INSTR SEQUENCE      ||  MICRO INSTR SEQUENCE POSITION ||OPCODE||LENGTH||UPDATE PC|| DST || SRC || CC ||         ALU OP            ||
||  5  ||  4  ||  3  ||  2  ||  1  ||                                ||      ||      ||         ||     ||     ||    ||                           ||
||***********************************************************************************************************************************************||
*/

namespace bolt {
    using gb_instruction_t = uint64_t;

    struct gb_instruction_operand_flag {
        enum {
            register8 = 0x10u,
            register16 = 0x20u,
            indirect = 0x40,
            immediate = 0x80
        };
    };

    template<typename t, typename underlying_type=std::underlying_type_t<t>>
    constexpr auto enum_value(t value) -> underlying_type {
        return static_cast<underlying_type>(value);
    }
    struct gb_instruction_operand_type {
        enum {
            none/*,

            a = enum_value(gb_register8_type::a) | gb_instruction_operand_flag::register8,
            b = enum_value(gb_register8_type::b) | gb_instruction_operand_flag::register8,
            c = enum_value(gb_register8_type::c) | gb_instruction_operand_flag::register8,
            d = enum_value(gb_register8_type::d) | gb_instruction_operand_flag::register8,
            e = enum_value(gb_register8_type::e) | gb_instruction_operand_flag::register8,
            h = enum_value(gb_register8_type::h) | gb_instruction_operand_flag::register8,
            l = enum_value(gb_register8_type::l) | gb_instruction_operand_flag::register8,
            bc = enum_value(gb_register16_type::bc) | gb_instruction_operand_flag::register16,
            sp = enum_value(gb_register16_type::sp) | gb_instruction_operand_flag::register16,
            de = enum_value(gb_register16_type::de) | gb_instruction_operand_flag::register16,
            hl = enum_value(gb_register16_type::hl) | gb_instruction_operand_flag::register16,

            d8 = 0u | gb_instruction_operand_flag::immediate,
            d16 = 1u | gb_instruction_operand_flag::immediate,
            a8 = 2u | gb_instruction_operand_flag::immediate,
            a16 = 3u | gb_instruction_operand_flag::immediate,
            r8 = 4u | gb_instruction_operand_flag::immediate*/
        };
    };

    using gb_instruction_operand_t = uint64_t;
    
    struct gb_instruction_cc {
        static constexpr uint32_t reset = 0x08u;
        
        enum {
            none = 0x00u,
            z = 0x01u,
            c = 0x2u,
            nz = z | reset,
            nc = c | reset
        };
    };

    using gb_instruction_cc_t = uint64_t;

    static constexpr auto gb_instr_micro_instr_sequ_shift = 38u;
    static constexpr auto gb_instr_micro_instr_sequ_pos_shift = 35u;
    static constexpr auto gb_instr_opcode_shift = 27u;
    static constexpr auto gb_instr_length_shift = 25u;
    static constexpr auto gb_instr_udate_pc_shift = 24u;
    static constexpr auto gb_instr_dst_shift = 17u;
    static constexpr auto gb_instr_src_shift = 12u;
    static constexpr auto gb_instr_cc_shift = 6u;
    static constexpr auto gb_instr_alu_op_shift = 0u;

    static constexpr auto gb_instr_micro_instr_sequ_mask     = 0x1full;
    static constexpr auto gb_instr_micro_instr_sequ_pos_mask = 0x07ull;
    static constexpr auto gb_instr_opcode_mask               = 0xffull;
    static constexpr auto gb_instr_length_mask               = 0x03ull;
    static constexpr auto gb_instr_udate_pc_mask             = 0x01ull;
    static constexpr auto gb_instr_dst_mask                  = 0x7full;
    static constexpr auto gb_instr_src_mask                  = 0x7full;
    static constexpr auto gb_instr_cc_mask                   = 0x0full;
    static constexpr auto gb_instr_alu_op_mask               = 0x3full;

    static constexpr auto gb_instr_micro_instr_sequ_bits = 5u;

    class gb_instruction_builder {
    public:
        constexpr gb_instruction_builder() : instruction(0ull) { }
        ~gb_instruction_builder() = default;

        constexpr gb_instruction_builder(const gb_instruction_builder &) = delete;
        constexpr gb_instruction_builder(gb_instruction_builder &&) = delete;

        constexpr gb_instruction_builder &operator=(const gb_instruction_builder &) = delete;
        constexpr gb_instruction_builder &operator=(gb_instruction_builder &&) = delete;

        //constexpr gb_instruction_builder &encode_micro_instr_sequ_len(uint64_t sequ_len) {
        //    if (sequ_len < 1 || sequ_len > 5u) {
        //         throw std::logic_error("gb_instruction_builder::encode_micro_instr_sequ_len(): 'sequ_len' must fall in range of 1 to 5");
        //    }

        //    instruction |= sequ_len << gb_instr_micro_instr_sequ_len_shift;

        //    return *this;
        //}

        constexpr gb_instruction_builder &encode_micro_instr_sequ(uint64_t sequ, gb_micro_instruction_type instr) {

            instruction |= static_cast<uint64_t>(instr) << (gb_instr_micro_instr_sequ_shift + (sequ - 1ull) * gb_instr_micro_instr_sequ_bits);

            return *this;
        }

        constexpr gb_instruction_builder &encode_opcode(uint64_t opcode) {
            instruction |= opcode << gb_instr_opcode_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_length(uint64_t length) {
            instruction |= length << gb_instr_length_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_update_pc(bool update) {
            instruction |= static_cast<uint64_t>(update) << gb_instr_udate_pc_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_source(gb_instruction_operand_t src) {
            instruction |= static_cast<gb_instruction_t>(src) << gb_instr_src_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_destination(gb_instruction_operand_t dst) {
            instruction |= static_cast<gb_instruction_t>(dst) << gb_instr_dst_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_cc(gb_instruction_cc_t cc) {
            instruction |= static_cast<uint64_t>(cc) << gb_instr_cc_shift;

            return *this;
        }

        constexpr gb_instruction_builder &encode_alu_operation(gb_alu_op_type op) {
            instruction |= static_cast<uint64_t>(op) << gb_instr_alu_op_shift;

            return *this;
        }

        constexpr gb_instruction_t build(void) {
            instruction |= 1ull << gb_instr_micro_instr_sequ_pos_shift;

            const auto instr = instruction;

            instruction = 0ull;

            return instr;
        }

    private:
        gb_instruction_t instruction;
    };

    inline auto gb_instr_micro_instr_sequ_pos(gb_instruction_t instr) -> uint64_t {

        return instr >> gb_instr_micro_instr_sequ_pos_shift & gb_instr_micro_instr_sequ_pos_mask;
    }

    inline auto gb_instr_micro_instr_sequ(gb_instruction_t instr, uint64_t sequ) -> uint64_t {

        return instr >> (gb_instr_micro_instr_sequ_shift + (sequ - 1ull) * gb_instr_micro_instr_sequ_bits) & gb_instr_micro_instr_sequ_mask;
    }

    inline auto gb_instr_opcode(gb_instruction_t instr) -> uint64_t {

        return instr >> gb_instr_opcode_shift & gb_instr_opcode_mask;
    }

    inline auto gb_instr_length(gb_instruction_t instr) -> uint64_t {

        return instr >> gb_instr_length_shift & gb_instr_length_mask;
    }

    inline auto gb_instr_update_pc(gb_instruction_t instr) -> bool {

        return static_cast<bool>(instr >> gb_instr_udate_pc_shift & gb_instr_udate_pc_mask);
    }

    inline auto gb_instr_dst(gb_instruction_t instr) -> gb_instruction_operand_t {

        return static_cast<gb_instruction_operand_t>(instr >> gb_instr_dst_shift & gb_instr_dst_mask);
    }

    inline auto gb_instr_src(gb_instruction_t instr) -> gb_instruction_operand_t {

        return static_cast<gb_instruction_operand_t>(instr >> gb_instr_src_shift & gb_instr_src_mask);
    }

    inline auto gb_instr_cc(gb_instruction_t instr) -> gb_instruction_cc_t {

        return static_cast<gb_instruction_cc_t>(instr >> gb_instr_cc_shift & gb_instr_cc_mask);
    }

    inline auto gb_instr_alu_op(gb_instruction_t instr) -> gb_alu_op_type {
        return static_cast<gb_alu_op_type>(instr >> gb_instr_alu_op_shift & gb_instr_alu_op_mask);
    }

    inline auto gb_instr_advance_micro_instr(gb_instruction_t instr) -> uint64_t {
        const auto sequ_pos = gb_instr_micro_instr_sequ_pos(instr);

        return instr ^ (instr & gb_instr_micro_instr_sequ_pos_mask << gb_instr_micro_instr_sequ_pos_shift) ^ ((sequ_pos + 1ull) << gb_instr_micro_instr_sequ_pos_shift);
    }
}

#endif