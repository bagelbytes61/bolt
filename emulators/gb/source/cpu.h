#ifndef BOLT_GB_CPU_H_
#define BOLT_GB_CPU_H_

#pragma once

#include "bus.h"    
#include "platform.h"
#include "register_proxy.h"

#include <memory>

namespace bolt {
    class gb_cpu {
    public:
        class gb_register_bus;

    public:
        gb_cpu(std::unique_ptr<gb_bus> &&bus);
        ~gb_cpu();

        gb_cpu(const gb_cpu &) = delete;
        gb_cpu &operator=(const gb_cpu &) = delete;

        gb_cpu(gb_cpu &&) = delete;
        gb_cpu &operator=(gb_cpu &&) = delete;

        void machine_cycle(void);

        template<typename gb_register_type, typename gb_register_t = std::underlying_type_t<gb_register_type>>
        gb_register_t push_register(gb_register_t reg);

        template<typename gb_register_type, typename gb_register_t = std::underlying_type_t<gb_register_type>>
        gb_register_t pop_register(gb_register_t reg) const;

    private:
        gb_register_bus *get_register_bus(void);

        template<typename gb_register_type>
        gb_register_proxy<gb_register_type> get_register(gb_register_type reg_type);

        template<typename gb_internal_register_type>
        gb_register_proxy<gb_internal_register_type> get_internal_register(gb_internal_register_type reg_type);

    private:
        GB_REGISTER_PAIR(a, f);
        GB_REGISTER_PAIR(b, c);
        GB_REGISTER_PAIR(d, e);
        GB_REGISTER_PAIR(h, l);
        gb_register16_t pc;
        mutable gb_register16_t sp;

        // Note that this 64-bit register does not accurately reflect 
        // the 8-bit instruction register present in the actual hardware
        gb_internal_register64_t ir;
        GB_INTERNAL_REGISTER_PAIR(w, z);

        std::unique_ptr<gb_bus> bus;
    };

    template<>
    inline auto gb_cpu::push_register<gb_register8_type>(gb_register8_t reg) -> gb_register8_t {
        bus->write_word(--sp, reg);

        return reg;
    }

    template<>
    inline auto gb_cpu::push_register<gb_register16_type>(gb_register16_t reg) -> gb_register16_t {
        bus->write_word(--sp, (reg >> 8u) & 0xffu);
        bus->write_word(--sp, (reg >> 0u) & 0xffu);

        return reg;
    }

    template<>
    inline auto gb_cpu::pop_register<gb_register8_type>(gb_register8_t reg) const -> gb_register8_t {

        return reg = bus->read_word(sp++);
    }

    template<>
    inline auto gb_cpu::pop_register<gb_register16_type>(gb_register16_t reg) const -> gb_register16_t {
        reg ^= (reg & 0xff00u) ^ ((uint16_t(bus->read_word(sp++)) << 8u));
        reg ^= (reg & 0x00ffu) ^ ((uint16_t(bus->read_word(sp++)) << 0u));

        return reg;
    }

    inline auto gb_cpu::get_register_bus(void) -> gb_register_bus *{
        
        return reinterpret_cast<gb_register_bus *>(this);
    }

    template<>
    inline auto gb_cpu::get_register(gb_register8_type reg_type) -> gb_register_proxy<gb_register8_type> {
        switch (reg_type) {
            case gb_register8_type::a: return gb_register8_proxy_t(this, &a);
            case gb_register8_type::f: return gb_register8_proxy_t(this, &f);
            case gb_register8_type::b: return gb_register8_proxy_t(this, &b);
            case gb_register8_type::c: return gb_register8_proxy_t(this, &c);
            case gb_register8_type::d: return gb_register8_proxy_t(this, &d);
            case gb_register8_type::e: return gb_register8_proxy_t(this, &e);
            case gb_register8_type::h: return gb_register8_proxy_t(this, &h);
            case gb_register8_type::l: return gb_register8_proxy_t(this, &l);
            case gb_register8_type::pch: return gb_register8_proxy_t(this, reinterpret_cast<uint8_t *>(pc + 0));
            case gb_register8_type::pcl: return gb_register8_proxy_t(this, reinterpret_cast<uint8_t *>(pc + 1));
            case gb_register8_type::sph: return gb_register8_proxy_t(this, reinterpret_cast<uint8_t *>(sp + 0));
            case gb_register8_type::spl: return gb_register8_proxy_t(this, reinterpret_cast<uint8_t *>(sp + 1));
        }
    }

    template<>
    inline auto gb_cpu::get_register(gb_register16_type reg_type) -> gb_register_proxy<gb_register16_type> {
        switch (reg_type) {
            case gb_register16_type::bc: return gb_register16_proxy_t(this, &b, &c);
            case gb_register16_type::de: return gb_register16_proxy_t(this, &d, &e);
            case gb_register16_type::hl: return gb_register16_proxy_t(this, &h, &l);
            case gb_register16_type::pc: return gb_register16_proxy_t(this, reinterpret_cast<uint8_t *>(&pc), reinterpret_cast<uint8_t *>(&pc) + 1);
            case gb_register16_type::sp: return gb_register16_proxy_t(this, reinterpret_cast<uint8_t *>(&sp), reinterpret_cast<uint8_t *>(&sp) + 1);
            default: __assume(false);
        }
    }

    template<>
    inline auto gb_cpu::get_internal_register(gb_internal_register8_type reg_type) -> gb_register_proxy<gb_internal_register8_type> {
        switch (reg_type) {
            case gb_internal_register8_type::w:  return gb_internal_register8_proxy_t(this, &w);
            case gb_internal_register8_type::z:  return gb_internal_register8_proxy_t(this, &z);
            default: __assume(false);
        }
    }

    template<>
    inline auto gb_cpu::get_internal_register(gb_internal_register16_type reg_type) -> gb_register_proxy<gb_internal_register16_type> {
        switch (reg_type) {
            case gb_internal_register16_type::wz: return gb_internal_register16_proxy_t(this, &w, &z);
            default: __assume(false);
        }
    }

    template<>
    inline auto gb_cpu::get_internal_register(gb_internal_register64_type reg_type) -> gb_register_proxy<gb_internal_register64_type> {
        switch (reg_type) {
            case gb_internal_register64_type::ir: return gb_internal_register64_proxy_t(this, &ir);
            default: __assume(false);
        }
    }
}

#endif