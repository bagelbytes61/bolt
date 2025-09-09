#ifndef BOLT_GB_CPU_H_
#define BOLT_GB_CPU_H_

#pragma once

#include "bus.hh"
#include "clock.hh"
#include "decoder.hh"
#include "idu.hh"
#include "instruction.hh"
#include "platform.hh"
#include "register_file.hh"

#include <memory>
#include <vector>

namespace bolt {
    class gb_alu;
    class gb_cartridge;
    class gb_idu;

    class gb_cpu {
    public:
        gb_cpu(gb_cartridge &cartridge);
        ~gb_cpu();

        gb_cpu(const gb_cpu &) = delete;
        gb_cpu &operator=(const gb_cpu &) = delete;

        gb_cpu(gb_cpu &&) = delete;
        gb_cpu &operator=(gb_cpu &&) = delete;

        auto clk(uint64_t cycle, gb_clock_state state) -> void;

        //template<typename gb_register_type, typename gb_register_t = std::underlying_type_t<gb_register_type>>
        //gb_register_t push_register(gb_register_t reg);

        //template<typename gb_register_type, typename gb_register_t = std::underlying_type_t<gb_register_type>>
        //gb_register_t pop_register(gb_register_t reg) const;

    //private:
    //    template<typename gb_register_type>
    //    gb_register_proxy<gb_register_type> get_register(gb_register_type reg_type);

    //    template<typename gb_internal_register_type>
    //    gb_register_proxy<gb_internal_register_type> get_internal_register(gb_internal_register_type reg_type);

    private:
        gb_bus bus;

        gb_decoder decoder;
        gb_control_unit control_unit;

        gb_register_file register_file;
        gb_register_file::gb_idu idu;

        gb_control_signals control_signals;

        //gb_tstate tstate;


        //std::unique_ptr<gb_register_bus> register_bus;
        //std::unique_ptr<gb_alu> alu;
        //std::unique_ptr<gb_idu> idu;
    };

    //template<>
    //inline auto gb_cpu::push_register<gb_register8_type>(gb_register8_t reg) -> gb_register8_t {
    //    //peripheral_bus->write_word(--sp, reg);

    //    return reg;
    //}

    //template<>
    //inline auto gb_cpu::push_register<gb_register16_type>(gb_register16_t reg) -> gb_register16_t {
    //    //peripheral_bus->write_word(--sp, (reg >> 8u) & 0xffu);
    //    //peripheral_bus->write_word(--sp, (reg >> 0u) & 0xffu);

    //    return reg;
    //}

    //template<>
    //inline auto gb_cpu::pop_register<gb_register8_type>(gb_register8_t reg) const -> gb_register8_t {

    //    //return reg = peripheral_bus->read_word(sp++);

    //    return reg;
    //}

    //template<>
    //inline auto gb_cpu::pop_register<gb_register16_type>(gb_register16_t reg) const -> gb_register16_t {
    //    //reg ^= (reg & 0xff00u) ^ ((uint16_t(peripheral_bus->read_word(sp++)) << 8u));
    //    //reg ^= (reg & 0x00ffu) ^ ((uint16_t(peripheral_bus->read_word(sp++)) << 0u));

    //    return reg;
    //}



    //template<>
    //inline auto gb_cpu::get_register(gb_register16_type reg_type) -> gb_register_proxy<gb_register16_type> {
    //    switch (reg_type) {
    //        case gb_register16_type::bc: return gb_register16_proxy_t(this, &b, &c);
    //        case gb_register16_type::de: return gb_register16_proxy_t(this, &d, &e);
    //        case gb_register16_type::hl: return gb_register16_proxy_t(this, &h, &l);
    //        case gb_register16_type::pc: return gb_register16_proxy_t(this, &pch, &pcl);
    //        case gb_register16_type::sp: return gb_register16_proxy_t(this, &sp);
    //        default: __assume(false);
    //    }
    //}

    //template<>
    //inline auto gb_cpu::get_internal_register(gb_internal_register8_type reg_type) -> gb_register_proxy<gb_internal_register8_type> {
    //    switch (reg_type) {
    //        case gb_internal_register8_type::w:  return gb_internal_register8_proxy_t(this, &w);
    //        case gb_internal_register8_type::z:  return gb_internal_register8_proxy_t(this, &z);
    //        default: __assume(false);
    //    }
    //}

    //template<>
    //inline auto gb_cpu::get_internal_register(gb_internal_register16_type reg_type) -> gb_register_proxy<gb_internal_register16_type> {
    //    switch (reg_type) {
    //        case gb_internal_register16_type::wz: return gb_internal_register16_proxy_t(this, &w, &z);
    //        default: __assume(false);
    //    }
    //}

    //template<>
    //inline auto gb_cpu::get_internal_register(gb_internal_register64_type reg_type) -> gb_register_proxy<gb_internal_register64_type> {
    //    switch (reg_type) {
    //        case gb_internal_register64_type::ir: return gb_internal_register64_proxy_t(this, &ir);
    //        default: __assume(false);
    //    }
    //}
}

#endif