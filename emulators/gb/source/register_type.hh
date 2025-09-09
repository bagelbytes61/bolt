//#ifndef BOLT_GB_REGISTER_TYPE_H_
//#define BOLT_GB_REGISTER_TYPE_H_
//
//#pragma once
//
//#include "platform.hh"
//
//#include <cstdint>
//
//#if defined(BOLT_BIG_ENDIAN)
//#define GB_REGISTER_PAIR(a, b) gb_register8_t a, b
//#define GB_INTERNAL_REGISTER_PAIR(a, b) gb_register8_t a, b
//#elif defined(BOLT_LITTLE_ENDIAN)
//#define GB_REGISTER_PAIR(a, b) gb_register8_t b, a
//#define GB_INTERNAL_REGISTER_PAIR(a, b) gb_register8_t b, a
//#endif
//
//namespace bolt {
//    using gb_register8_t = uint8_t;
//    using gb_register16_t = uint16_t;
//
//    using gb_instruction_register_t = uint64_t; // I can explain, I promise!
//
//    enum struct gb_register8_type : uint8_t {
//        a, f,
//        b, c,
//        d, e,
//        h, l,
//
//        pch, pcl,
//        sph, spl
//    };
//
//    enum struct gb_register16_type : uint16_t{
//        bc,
//        de,
//        hl,
//
//        pc,
//        sp
//    };
//
//    enum struct gb_internal_register8_type : uint8_t {
//        w, z
//    };
//
//    enum struct gb_internal_register16_type : uint8_t {
//        wz
//    };
//
//    enum struct gb_internal_register64_type : uint64_t {
//        ir
//    };
//}
//
//#endif