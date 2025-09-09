//#include "alu_core.h"
//
//#include "alu_bus.h"
//#include "alu_latch.h"
//#include "alu_multiplexer.h"
//
//using namespace bolt;
//
////gb_alu_core::gb_alu_core(gb_alu_bus *hi_bus, gb_alu_latch *lo_latch, gb_register8_proxy_t flags)
////    , lo_latch(lo_latch)
////    , flags(flags) {
////
////}
//
//gb_alu_core::gb_alu_core(gb_alu_multiplexer &op1, gb_alu_multiplexer &op2, gb_alu_bus &high_bus, gb_alu_latch &result_latch, gb_register8_proxy_t flags)
//    : op1(op1)
//    , op2(op2)
//    , high_bus(high_bus)
//    , result_latch(result_latch)
//    , flags(flags) {
//
//}
//
//
//gb_alu_core::~gb_alu_core() {
//
//}
//
//auto gb_alu_core::read(void) const -> byte_t {
//    return result;
//}
//
//auto gb_alu_core::write(byte_t value) -> void {
//
//}
//
//void gb_alu_core::machine_cycle(gb_alu_op_type op, bit_t shift_bit) {
//    switch (op) {
//        case gb_alu_op_type::_inc: {
//            //const byte_t operand = (op1.read_high_latch() << 4u | op1.read_low_latch());
//            result = _inc(op1.read(), flags);
//
//            //result_latch.latch(result & 0xf);
//            //high_bus.write(result >> 4u);
//            //result_latch.unlatch();
//            break;
//        }
//        case gb_alu_op_type::_dec: {
//            result = _dec(op1.read(), flags);
//            result_latch.latch();
//            high_bus.write(result >> 4u);
//            result_latch.unlatch();
//            break;
//        }
//        case gb_alu_op_type::_xor: {
//            result = _xor(op1.read(), op2.read(), flags);
//            result_latch.latch();
//            high_bus.write(result >> 4u);
//            result_latch.unlatch();
//            break;
//        }
//
//
//    }
//}
//
//auto gb_alu_core::_inc(uint8_t in, gb_register8_proxy_t f) -> uint8_t {
//    if ((in & 0x0f) == 0x0f) {
//        f |= gb_flag::half_carry;
//    }
//    else {
//        f &= ~gb_flag::half_carry;
//    }
//
//    if (((in & 0x0f) + 1) == 0) {
//        f |= gb_flag::zero;
//    }
//    else {
//        f &= ~gb_flag::zero;
//    }
//
//    f &= ~gb_flag::subtract;
//
//    return in + 1;
//}
//
//auto gb_alu_core::_dec(uint8_t op, gb_register8_proxy_t f) -> uint8_t {
//    const uint8_t result = op - 1;
//    
//    if (result == 0) {
//        f |= gb_flag::zero;
//    } else {
//        f &= ~gb_flag::zero;
//    }
//
//    if ((op & 0x0f) > 0) {
//        f |= gb_flag::half_carry;
//    } else {
//        f &= ~gb_flag::half_carry;
//    }
//
//    f |= gb_flag::subtract;
//
//    return result;
//}
//
//auto gb_alu_core::_xor(uint8_t op1, uint8_t op2, gb_register8_proxy_t f) -> uint8_t {
//    const uint8_t result = op1 ^ op2;
//    
//    if (result == 0) {
//        f |= gb_flag::zero;
//    } else {
//        f &= ~gb_flag::zero;
//    }
//
//    f &= ~(gb_flag::carry | gb_flag::half_carry | gb_flag::subtract);
//
//    return result;
//}
//
//auto gb_alu_core::_rrca(uint8_t op, gb_register8_proxy_t f) -> uint8_t {
//    const bit_t shift_bit = op & 0x01;;
//    const uint8_t result = op >> 1u;
//
//    if (result == 0) {
//        f |= gb_flag::zero;
//    } else {
//        f &= ~gb_flag::zero;
//    }
//
//    f = f & ~gb_flag::carry | gb_flag::carry * shift_bit;
//
//    return result;
//}