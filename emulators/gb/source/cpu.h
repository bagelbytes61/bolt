#ifndef BOLT_GB_CPU_H_
#define BOLT_GB_CPU_H_

#pragma once

#include "bus.h"    
#include "platform.h"
#include "register_proxy.h"

#include <memory>

namespace bolt {
    using gb_micro_instruction_fn = void(*)(gb_cpu*, gb_bus*);

    class gb_alu;

    class gb_cpu {
    public:
        gb_cpu(std::unique_ptr<gb_bus> bus);
        ~gb_cpu();

        void machine_cycle();

        template<typename gb_register_type, typename gb_register_t = std::underlying_type_t<gb_register_type>>
        gb_register_t push_register(gb_register_t* register_t);

        template<typename gb_register_type, typename gb_register_t = std::underlying_type_t<gb_register_type>>
        gb_register_t pop_register(gb_register_t* register_t);

        template<typename gb_register_type>
        gb_register_proxy<gb_register_type> get_register(gb_register_type reg);

        template<typename gb_internal_register_type>
        gb_register_proxy<gb_internal_register_type> get_internal_register(gb_internal_register_type reg);

    private:
        GB_REGISTER_PAIR(a, f);
        GB_REGISTER_PAIR(b, c);
        GB_REGISTER_PAIR(d, e);
        GB_REGISTER_PAIR(h, l);
        gb_register16_t pc;
        gb_register16_t sp;

        // As much as I don't like not having this also as an 8-bit register (as it should be),
        // this is by far the most performant solution that I can think of at the moment
        gb_internal_register64_t ir;
        GB_INTERNAL_REGISTER_PAIR(w, z);

        std::unique_ptr<gb_bus> bus;
        std::unique_ptr<gb_alu> alu;
    };

    template<>
    inline auto gb_cpu::push_register<gb_register8_type>(gb_register8_t *reg) -> gb_register8_t {
        bus->write(--sp, *reg);

        return *reg;
    }

    template<>
    inline auto gb_cpu::push_register<gb_register16_type>(gb_register16_t *reg) -> gb_register16_t {
        bus->write(--sp, (*reg >> 8) & 0xff);
        bus->write(--sp, (*reg >> 0) & 0xff);

        return *reg;
    }

    template<>
    inline auto gb_cpu::pop_register<gb_register8_type>(gb_register8_t *reg) -> gb_register8_t {
        return *reg = bus->read(sp++);
    }

    template<>
    inline auto gb_cpu::pop_register<gb_register16_type>(gb_register16_t *reg) -> gb_register16_t {
        *reg ^= (*reg & 0xff00) ^ (uint16_t(bus->read(sp++)) << 8);
        *reg ^= (*reg & 0x00ff) ^ (uint16_t(bus->read(sp++)) << 0);

        return *reg;
    }

    template<>
    inline auto gb_cpu::get_register(gb_register8_type reg) -> gb_register_proxy<gb_register8_type> {
        switch (reg) {
            case gb_register8_type::a: return gb_register8_proxy_t(this, &a);
            case gb_register8_type::f: return gb_register8_proxy_t(this, &f);
            case gb_register8_type::b: return gb_register8_proxy_t(this, &b);
            case gb_register8_type::c: return gb_register8_proxy_t(this, &c);
            case gb_register8_type::d: return gb_register8_proxy_t(this, &d);
            case gb_register8_type::e: return gb_register8_proxy_t(this, &e);
            case gb_register8_type::h: return gb_register8_proxy_t(this, &h);
            case gb_register8_type::l: return gb_register8_proxy_t(this, &l);
        }
    }

    template<>
    inline auto gb_cpu::get_register(gb_register16_type reg) -> gb_register_proxy<gb_register16_type> {
        switch (reg) {
            case gb_register16_type::bc: return gb_register16_proxy_t(this, &b, &c);
            case gb_register16_type::de: return gb_register16_proxy_t(this, &d, &e);
            case gb_register16_type::hl: return gb_register16_proxy_t(this, &h, &l);
            case gb_register16_type::pc: return gb_register16_proxy_t(this, reinterpret_cast<uint8_t *>(&pc), reinterpret_cast<uint8_t *>(&pc) + 1);
            case gb_register16_type::sp: return gb_register16_proxy_t(this, reinterpret_cast<uint8_t *>(&sp), reinterpret_cast<uint8_t *>(&sp) + 1);
        }
    }

    template<>
    inline auto gb_cpu::get_internal_register(gb_internal_register8_type reg) -> gb_register_proxy<gb_internal_register8_type> {
        switch (reg) {
            case gb_internal_register8_type::w:  return gb_internal_register8_proxy_t(this, &w);
            case gb_internal_register8_type::z:  return gb_internal_register8_proxy_t(this, &z);
        }
    }

    template<>
    inline auto gb_cpu::get_internal_register(gb_internal_register16_type reg) -> gb_register_proxy<gb_internal_register16_type> {
        switch (reg) {
            case gb_internal_register16_type::wz: return gb_internal_register16_proxy_t(this, &w, &z);
        }
    }

    template<>
    inline auto gb_cpu::get_internal_register(gb_internal_register64_type reg) -> gb_register_proxy<gb_internal_register64_type> {
        switch (reg) {
            case gb_internal_register64_type::ir: return gb_internal_register64_proxy_t(this, &ir);
        }
    }
}

#endif