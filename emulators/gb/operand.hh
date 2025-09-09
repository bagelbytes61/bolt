#ifndef BOLT_GB_OPERAND_HH_
#define BOLT_GB_OPERAND_HH

#pragma once

#include "cpu.hh"

#include <cassert>
#include <variant>

namespace bolt {
    class gb_immediate_operand {
    public:
        gb_immediate_operand(gb_bus *bus) {

        }
        ~gb_immediate_operand() = default;


    private:
    };

    template<typename gb_register_type>
    class gb_register_operand {
    public:
        gb_register_operand(gb_register_proxy<gb_register_type> reg)
            : reg(reg) {

        }
        ~gb_register_operand() = default;

    private:
        gb_register_proxy<gb_register_type> reg;
    };

    class gb_operand {
        enum struct operand_type {
            immediate,
            register8,
            register16
        };

    public:
        gb_operand(gb_cpu::gb_register_bus *register_bus, gb_bus *bus, gb_instruction_operand_t operand)
            : register_bus(register_bus)
            , bus(bus) {

            if (operand & gb_instruction_operand_flag::register8) {
                //op = register_bus->get_register(static_cast<gb_register8_type>(operand & ~gb_instruction_operand_flag::register8));
            } else if (operand & gb_instruction_operand_flag::register16) {
                //op = register_bus->get_register(static_cast<gb_register8_type>(operand & ~gb_instruction_operand_flag::register16));
            }
        }

        auto load(gb_operand &operand) const -> void {
            assert(!std::holds_alternative<gb_immediate_operand>(operand.op));

            if (std::holds_alternative<gb_immediate_operand>(op)) {
                //operand.load(std)
                //auto src = std::get<gb_immediate_operand>(op);

            } else if (std::holds_alternative<gb_register8_proxy_t>(op)) {
                load(std::get<gb_register8_proxy_t>(operand.op));

            } else if (std::holds_alternative<gb_register16_proxy_t>(op)) {
                load(std::get<gb_register8_proxy_t>(operand.op));
            }
        }

        auto store(const gb_operand &operand) -> void {
            assert(!std::holds_alternative<gb_immediate_operand>(op));

            if (std::holds_alternative<gb_immediate_operand>(operand.op)) {
                std::get<gb_immediate_operand>(operand.op);

            } else if (std::holds_alternative<gb_register8_proxy_t>(operand.op)) {
                store(std::get<gb_register8_proxy_t>(operand.op));

            } else if (std::holds_alternative<gb_register16_proxy_t>(operand.op)) {
                store(std::get<gb_register16_proxy_t>(operand.op));
            }
        }

    private:
        //auto load(gb_immediate_operand)

        template<typename gb_register_type>
        auto load(gb_register_proxy<gb_register_type> dst) const -> void {
            dst = std::get<gb_register_proxy<gb_register_type>>(op);
        }

        template<typename gb_register_type>
        auto store(gb_register_proxy<gb_register_type> src) -> void {
            std::get<gb_register_proxy<gb_register_type>>(op) = src;
        }

    private:
        gb_cpu::gb_register_bus *register_bus;
        gb_bus *bus;

        std::variant<
            std::monostate,
            gb_immediate_operand,
            gb_register8_proxy_t,
            gb_register16_proxy_t> op;
    };
}

#endif
