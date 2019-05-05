#ifndef BOLT_GB_INSTRUCTION_ENCODING_H_
#define BOLT_GB_INSTRUCTION_ENCODING_H_

#pragma once

#include "common.h"

namespace bolt {
    /*
    ||*******************************************************************INSTRUCTION ENCODING LAYOUT********************************************************************||
    ||                                                                                BITS                                                                              ||
    ||******************************************************************************************************************************************************************||
    ||63                       61||58 54||53 49||48 44||43 39||38 34||33                            29||28  25||24  17||16  15||    14   ||13 10||9   6||5  3||   2     ||
    ||MICRO INSTR SEQUENCE LENGTH||       MICRO INSTR SEQUENCE      ||  MICRO INSTR SEQUENCE POSITION ||ALU OP||OPCODE||LENGTH||UPDATE PC|| DST || SRC || CC || CC EVAL ||
    ||                           ||  5  ||  4  ||  3  ||  2  ||  1  ||  5  ||  4  ||  3  ||  2 ||  1  ||                                               ||    ||         ||
    ||******************************************************************************************************************************************************************||
    */

#define GB_INSTR_NONE                (0x00ull)
#define GB_INSTR_REGISTER_A          (0x01ull)
#define GB_INSTR_REGISTER_B          (0x02ull)
#define GB_INSTR_REGISTER_C          (0x03ull)
#define GB_INSTR_REGISTER_D          (0x04ull)
#define GB_INSTR_REGISTER_E          (0x05ull)
#define GB_INSTR_REGISTER_H          (0x06ull)
#define GB_INSTR_REGISTER_L          (0x07ull)
#define GB_INSTR_REGISTER_BC         (0x08ull)
#define GB_INSTR_REGISTER_DE         (0x09ull)
#define GB_INSTR_REGISTER_HL         (0x0aull)
#define GB_INSTR_REGISTER_SP         (0x0bull)
#define GB_INSTR_INDIRECT_HL         (0x0cull)
#define GB_INSTR_D8                  (0x0dull)
#define GB_INSTR_D16                 (0x0eull)
#define GB_INSTR_A8                  (0x0full)
#define GB_INSTR_A16                 (0x10ull)
#define GB_INSTR_R8                  (0x11ull)

#define GB_INSTR_CC_NONE             (0x00ull << 0))
#define GB_INSTR_CC_Z                (0x01ull << 7)
#define GB_INSTR_CC_N                (0x01ull << 6)
#define GB_INSTR_CC_H                (0x01ull << 5)
#define GB_INSTR_CC_C                (0x01ull << 4)

#define GB_INSTR_CC_EVAL_TRUE        (0x01ull)
#define GB_INSTR_CC_EVAL_FALSE       (0x00ull)


#define GB_MICRO_INSTR_SEQU_POS_1    (1ull << 0)
#define GB_MICRO_INSTR_SEQU_POS_2    (1ull << 1)
#define GB_MICRO_INSTR_SEQU_POS_3    (1ull << 2)
#define GB_MICRO_INSTR_SEQU_POS_4    (1ull << 3)
#define GB_MICRO_INSTR_SEQU_POS_5    (1ull << 4)

#define GB_MICRO_INSTR_SEQU_LEN_MASK (0x07ull << 61)
#define GB_MICRO_INSTR_SEQU_5_MASK   (0x1full << 56)
#define GB_MICRO_INSTR_SEQU_4_MASK   (0x1full << 51)
#define GB_MICRO_INSTR_SEQU_3_MASK   (0x1full << 46)
#define GB_MICRO_INSTR_SEQU_2_MASK   (0x1full << 41)
#define GB_MICRO_INSTR_SEQU_1_MASK   (0x1full << 36)
#define GB_MICRO_INSTR_SEQU_POS_MASK (0x07ull << 29)
#define GB_ALU_OPERATION_MASK        (0x1full << 25)
#define GB_INSTR_MASK                (0xffull << 17)
#define GB_INSTR_LENGTH_MASK         (0x3full << 15)
#define GB_INSTR_UPDATE_PC_MASK      (0x01ull << 14)
#define GB_INSTR_DST_MASK            (0x0full << 10)
#define GB_INSTR_SRC_MASK            (0x0full <<  6)
#define GB_INSTR_CC_MASK             (0x0full <<  3)
#define GB_INSTR_CC_EVAL_MASK        (0x01ull <<  2)

#define GB_ENCODE_MICRO_INSTR_SEQU_LEN(len) ((static_cast<uint64_t>((len)      & 0x07ull)   << 61)
#define GB_ENCODE_MICRO_INSTR_SEQU_5(micro) ((static_cast<uint64_t>((micro))   & 0x1full)   << 56)
#define GB_ENCODE_MICRO_INSTR_SEQU_4(micro) ((static_cast<uint64_t>((micro))   & 0x1full)   << 51)
#define GB_ENCODE_MICRO_INSTR_SEQU_3(micro) ((static_cast<uint64_t>((micro))   & 0x1full)   << 46)
#define GB_ENCODE_MICRO_INSTR_SEQU_2(micro) ((static_cast<uint64_t>((micro))   & 0x1full)   << 41)
#define GB_ENCODE_MICRO_INSTR_SEQU_1(micro) ((static_cast<uint64_t>((micro))   & 0x1full)   << 36)
#define GB_ENCODE_MICRO_INSTR_SEQU_POS(pos) ((static_cast<uint64_t>((pos))     & 0x1full)   << 29)
#define GB_ENCODE_ALU_OP(op)                ((static_cast<uint64_t>((op))      & 0x1full)   << 25)
#define GB_ENCODE_INSTR(op)                 ((static_cast<uint64_t>((op))      & 0xffull)   << 17)
#define GB_ENCODE_INSTR_LEN(len)            ((static_cast<uint64_t>((len))     & 0x03ull)   << 15)
#define GB_ENCODE_INSTR_UPDATE_PC(update)   ((static_cast<uint64_t>((update))  & 0x01ull)   << 14)
#define GB_ENCODE_INSTR_DST(dst)            ((static_cast<uint64_t>((dst))     & 0x0full)   << 10)
#define GB_ENCODE_INSTR_SRC(src)            ((static_cast<uint64_t>((src))     & 0x0full)   <<  6)
#define GB_ENCODE_INSTR_CC(cc)              ((static_cast<uint64_t>((cc) >> 4) & 0x1full)   <<  3)
#define GB_ENCODE_INSTR_CC_EVAL(eval)       ((static_cast<uint64_t>((eval))    & 0x01ull)   <<  2)

#define GB_DECODE_MICRO_INSTR_SEQU_LEN(instr) (static_cast<uint8_t>(((instr) >> 61) & 0x07ull))
#define GB_DECODE_MICRO_INSTR_SEQU_5(instr)   (static_cast<uint8_t>(((instr) >> 56) & 0x1full))
#define GB_DECODE_MICRO_INSTR_SEQU_4(instr)   (static_cast<uint8_t>(((instr) >> 51) & 0x1full))
#define GB_DECODE_MICRO_INSTR_SEQU_3(instr)   (static_cast<uint8_t>(((instr) >> 46) & 0x1full))
#define GB_DECODE_MICRO_INSTR_SEQU_2(instr)   (static_cast<uint8_t>(((instr) >> 41) & 0x1full))
#define GB_DECODE_MICRO_INSTR_SEQU_1(instr)   (static_cast<uint8_t>(((instr) >> 36) & 0x1full))
#define GB_DECODE_MICRO_INSTR_SEQU_POS(instr) (static_cast<uint8_t>(((instr) >> 29) & 0x1full))
#define GB_DECODE_ALU_OP(instr)               (static_cast<uint8_t>(((instr) >> 25) & 0x1full))
#define GB_DECODE_INSTR(instr)                (static_cast<uint8_t>(((instr) >> 17) & 0xffull))
#define GB_DECODE_INSTR_LEN(instr)            (static_cast<uint8_t>(((instr) >> 15) & 0x03ull))
#define GB_DECODE_INSTR_UPDATE_PC(instr)      (static_cast<uint8_t>(((instr) >> 14) & 0x01ull))
#define GB_DECODE_INSTR_DST(instr)            (static_cast<uint8_t>(((instr) >> 10) & 0x0full))
#define GB_DECODE_INSTR_SRC(instr)            (static_cast<uint8_t>(((instr) >>  6) & 0x0full))
#define GB_DECODE_INSTR_CC(instr)             (static_cast<uint8_t>(((instr) >>  3) & 0x1full) << 4)
#define GB_DECODE_INSTR_CC_EVAL(instr)        (static_cast<uint8_t>(((instr) >>  2) & 0x01ull))

#define GB_ADVANCE_MICRO_INSTR(instr) ((instr) ^= ((instr) & GB_MICRO_INSTR_SEQU_POS_MASK) ^ \
                                      ((GB_DECODE_MICRO_INSTR_SEQU_POS((instr)) << 1 | !GB_DECODE_MICRO_INSTR_SEQU_POS((instr))) << 29))
}

#endif