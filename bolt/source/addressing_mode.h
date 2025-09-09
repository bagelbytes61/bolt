#ifndef BOLT_ADDRESSING_MODE_H_
#define BOLT_ADDRESSING_MODE_H_

#pragma once

#include <cstdint>

namespace bolt {

#define NES_ADDRESSING_MODE_ACCUMULATOR         0b11111100
#define NES_ADDRESSING_MODE_IMMEDIATE           0b00001000
#define NES_ADDRESSING_MODE_ZERO_PAGE           0b00000100
#define NES_ADDRESSING_MODE_ZERO_PAGE_XY        0b00010100
#define NES_ADDRESSING_MODE_ABSOLUTE            0b00001100   
#define NES_ADDRESSING_MODE_ABSOLUTE_X          0b00011000
#define NES_ADDRESSING_MODE_ABSOLUTE_Y          0b00011100
#define NES_ADDRESSING_MODE_INDEXED_INDIRECT    0b00000000
#define NES_ADDRESSING_MODE_INDIRECT_INDEXED    0b00010000

#define NES_ADDRESSING_MODE_MASK                0b00011100

    struct nes_addressing_mode_implicit;

    struct nes_addressing_mode_accumulator;

    struct nes_addressing_mode_immediate;

    struct nes_addressing_mode_zero_page;
    struct nes_addressing_mode_zero_page_x;
    struct nes_addressing_mode_zero_page_y;

    struct nes_addressing_mode_relative;

    struct nes_addressing_mode_absolute;
    struct nes_addressing_mode_absolute_x;
    struct nes_addressing_mode_absolute_y;

    struct nes_addressing_mode_indirect;

    struct nes_addressing_mode_indexed_indirect;

    struct nes_addressing_mode_indirect_indexed;

    template<uint8_t opcode, uint8_t addressing_mode = opcode>
    struct nes_addressing_mode_mapper;

    template<uint8_t opcode> struct nes_addressing_mode_mapper<opcode, NES_ADDRESSING_MODE_ZERO_PAGE> {
        using type = nes_addressing_mode_zero_page;
    };

    template<uint8_t opcode> struct nes_addressing_mode_mapper<opcode, NES_ADDRESSING_MODE_ZERO_PAGE_XY> {
        using type = nes_addressing_mode_zero_page;
    };


    template<uint8_t opcode> struct nes_addressing_mode_mapper<opcode, NES_ADDRESSING_MODE_ABSOLUTE> {
        using type = nes_addressing_mode_absolute;
    };
}

#endif