#ifndef BOLT_GB_REGISTER_FILE_HH_
#define BOLT_GB_REGISTER_FILE_HH_

#pragma once

#include "register_proxy.hh"

#include "tstate.hh"

#include <array>
#include <string>

#define GB_REGISTER_LIST \
    X(b),                \
    X(c),                \
    X(d),                \
    X(e),                \
    X(h),                \
    X(l),                \
    X(dummy1),           \
    X(a)
    //X(z),                
    //X(w),                
    //X(spl),               \
    //X(sph),               \
    //X(pcl),               \
    //X(pch),               \

#define GB_REGISTER16_LIST \
    X(pc),                 \
    X(sp),                 \
    X(bc),                 \
    X(de),                 \
    X(hl),

namespace bolt {
    using gb_register8_t = uint8_t;
    using gb_register16_t = uint16_t;

    struct gb_tstate;


    inline auto register_name(uint8_t r) -> std::string {
#define X(r) #r
        static const auto names = std::array{ GB_REGISTER_LIST };
#undef X

        return names.at(r);
    }

    struct gb_register8_type {
        enum {
#define X(r) r
            GB_REGISTER_LIST
#undef X
        };
    };

    class gb_register_file {
    public:
        class gb_idu;

    public:
        gb_register_file(addr_bus_t &addr_bus, data_bus_t &data_bus)
            : addr_bus(addr_bus)
            , data_bus(data_bus)
            , pc(0x100) {

        }

        auto update(gb_control_signals &ctrl_signals) -> void {
            if (ctrl_signals.m1 && !ctrl_signals.rd) {
                //addr_bus = pc;
            }

            if (ctrl_signals.en_z_wr) {
                z = data_bus;
            }

            if (ctrl_signals.en_w_wr) {
                w = data_bus;
            }

            if (ctrl_signals.en_ir_wr) {
                ir = data_bus;
            }

            if (ctrl_signals.en_wz_rd_addr_bus) {
                pc = static_cast<addr_t>(w << 8u) | z;
            }

            if (ctrl_signals.en_pc_rd_addr_bus) {
                addr_bus = pc;
            }
        }

        auto get_pc(void) const -> gb_register16_t {
            return pc;
        }

    private:
        addr_bus_t &addr_bus;
        data_bus_t &data_bus;

        gb_register8_t gprs[8u];

        gb_register8_t w;
        gb_register8_t z;
        
        gb_register8_t ir;
        
        gb_register16_t pc;
        gb_register16_t sp;

        //GB_REGISTER_PAIR(a, f);
        //GB_REGISTER_PAIR(b, c);
        //GB_REGISTER_PAIR(d, e);
        //GB_REGISTER_PAIR(h, l);

        //GB_REGISTER_PAIR(pch, pcl);
        //GB_REGISTER_PAIR(sph, spl);

        //GB_INTERNAL_REGISTER_PAIR(w, z);
    };

    //template<>
    //inline auto gb_register_file::get_register(gb_register8_type reg_type) -> gb_register_proxy<gb_register8_type> {
    //    switch (reg_type) {
    //        case gb_register8_type::a: return gb_register8_proxy_t(&a);
    //        case gb_register8_type::f: return gb_register8_proxy_t(&f);
    //        case gb_register8_type::b: return gb_register8_proxy_t(&b);
    //        case gb_register8_type::c: return gb_register8_proxy_t(&c);
    //        case gb_register8_type::d: return gb_register8_proxy_t(&d);
    //        case gb_register8_type::e: return gb_register8_proxy_t(&e);
    //        case gb_register8_type::h: return gb_register8_proxy_t(&h);
    //        case gb_register8_type::l: return gb_register8_proxy_t(&l);
    //        case gb_register8_type::pch: return gb_register8_proxy_t(&pch);
    //        case gb_register8_type::pcl: return gb_register8_proxy_t(&pcl);
    //        case gb_register8_type::sph: return gb_register8_proxy_t(&sph);
    //        case gb_register8_type::spl: return gb_register8_proxy_t(&spl);
    //        default: __assume(false);
    //    }
    //}

    //template<>
    //inline auto gb_register_file::get_register(gb_register16_type reg_type) -> gb_register_proxy<gb_register16_type> {
    //    switch (reg_type) {
    //        case gb_register16_type::bc: return gb_register16_proxy_t(&b, &c);
    //        case gb_register16_type::de: return gb_register16_proxy_t(&d, &e);
    //        case gb_register16_type::hl: return gb_register16_proxy_t(&h, &l);
    //        case gb_register16_type::pc: return gb_register16_proxy_t(&pch, &pcl);
    //        case gb_register16_type::sp: return gb_register16_proxy_t(&sph, &spl);
    //        default: __assume(false);
    //    }
    //}

    //template<>
    //inline auto gb_register_file::get_register(gb_internal_register8_type reg_type) -> gb_register_proxy<gb_internal_register8_type> {
    //    switch (reg_type) {
    //        case gb_internal_register8_type::w: return gb_internal_register8_proxy_t(&w);
    //        case gb_internal_register8_type::z: return gb_internal_register8_proxy_t(&z);
    //        default: __assume(false);
    //    }
    //}

    //template<>
    //inline auto gb_register_file::get_register(gb_internal_register16_type reg_type) -> gb_register_proxy<gb_internal_register16_type> {
    //    switch (reg_type) {
    //        case gb_internal_register16_type::wz: return gb_internal_register16_proxy_t(&w, &z);
    //        default: __assume(false);
    //    }
    //}
}

#endif