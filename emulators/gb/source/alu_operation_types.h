#ifndef BOLT_GB_ALU_OPERATION_TYPES_H_
#define BOLT_GB_ALU_OPERATION_TYPES_H_

#pragma once

#include <cstdint>

namespace bolt {
    enum struct gb_alu_op_type : uint64_t {
        _nop,
        _inc, _dec,
        _add, _adc, _sub, _sbc,
        _and, _xor, _or,
        _bit, _swap, _cp,
        _rl, _rr, _rla, _rra, _rlca, _rrca,
        _sla, _sra
    };
}

#endif