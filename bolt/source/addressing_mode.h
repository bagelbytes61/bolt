#ifndef BOLT_ADDRESSING_MODE_H_
#define BOLT_ADDRESSING_MODE_H_

#pragma once

#include <cstdint>

namespace bolt {

    struct nes_addressing_mode_implicit;

    struct nes_addressing_mode_accumulator;

    struct nes_addressing_mode_immediate;

    struct nes_addressing_mode_zero_page;
    struct nes_addressing_mode_zero_pageX;
    struct nes_addressing_mode_zero_pageY;

    struct nes_addressing_mode_relative;

    struct nes_addressing_mode_absolute;
    struct nes_addressing_mode_absolute_x;
    struct nes_addressing_mode_absolute_y;

    struct nes_addressing_mode_indirect;

    struct nes_addressing_mode_indexed_indirect;

    struct nes_addressing_mode_indirect_index;
}

#endif