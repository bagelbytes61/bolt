//#ifndef BOLT_GB_OPERAND_HH_
//#define BOLT_GB_OPERAND_HH_
//
//#include "cpu.hh"
//
//#include <cassert>
//#include <variant>
//
//namespace bolt {
//    class gb_immediate_operand {
//    public:
//        gb_immediate_operand(byte_t value)
//            : value(value) {
//
//        }
//        ~gb_immediate_operand() = default;
//
//
//    private:
//        byte_t value;
//    };
//
//    class gb_memory_operand {
//    public:
//
//    private:
//    };
//
//    template<typename gb_register_type>
//    class gb_register_operand {
//    public:
//        gb_register_operand(gb_register_proxy<gb_register_type> reg)
//            : reg(reg) {
//
//        }
//        ~gb_register_operand() = default;
//
//    private:
//        gb_register_proxy<gb_register_type> reg;
//    };
//
//    class gb_operand {
//        enum struct operand_type {
//            immediate,
//            register8,
//            register16
//        };
//
//    public:
//        gb_operand() = default;
//        gb_operand(gb_cpu::gb_register_bus *register_bus, gb_bus *bus, gb_instruction_operand_t operand)
//            : register_bus(register_bus)
//            , bus(bus) {
//
//            if (operand & gb_instruction_operand_flag::register8) {
//                value = register_bus->get_register(static_cast<gb_register8_type>(operand & ~gb_instruction_operand_flag::register8));
//            } else if (operand & gb_instruction_operand_flag::register16) {
//                const auto reg_type = static_cast<gb_register16_type>(operand & ~gb_instruction_operand_flag::register16 & ~gb_instruction_operand_flag::indirect);
//
//                if (operand & gb_instruction_operand_flag::indirect) {
//                    value = gb_memory_operand();
//                } else {
//                    value = register_bus->get_register(reg_type);
//                }
//            } else {
//                auto pc = register_bus->get_register(gb_register16_type::pc);
//
//                //value = gb_immediate_operand(bus->read_word(pc + 1));
//            }
//        }
//
//        auto operator++(void) -> gb_operand & {
//            assert(!std::holds_alternative<gb_immediate_operand>(value));
//            assert(!std::holds_alternative<gb_register8_proxy_t>(value));
//
//            ++std::get<gb_register16_proxy_t>(value);
//
//            return *this;
//        }
//
//        auto operator--(void) -> gb_operand & {
//            assert(!std::holds_alternative<gb_immediate_operand>(value));
//            assert(!std::holds_alternative<gb_register8_proxy_t>(value));
//
//            --std::get<gb_register16_proxy_t>(value);
//        
//            return *this;
//        }
//
//        auto load(const gb_operand &operand) -> void {
//            assert(!std::holds_alternative<gb_immediate_operand>(value));
//
//            if (std::holds_alternative<gb_immediate_operand>(operand.value)) {
//                value = std::get<gb_immediate_operand>(operand.value);
//            } else if (std::holds_alternative<gb_register8_proxy_t>(operand.value)) {
//                value = std::get<gb_register8_proxy_t>(operand.value);
//            } else if (std::holds_alternative<gb_register16_proxy_t>(operand.value)) {
//                value = std::get<gb_register16_proxy_t>(operand.value);
//            }
//        }
//
//        auto store(gb_operand &operand) const -> void {
//            assert(!std::holds_alternative<gb_immediate_operand>(operand.value));
//
//            if (std::holds_alternative<gb_register8_proxy_t>(operand.value)) {
//                operand.value = std::get<gb_register8_proxy_t>(operand.value);
//            } else if (std::holds_alternative<gb_register16_proxy_t>(operand.value)) {
//                operand.value = std::get<gb_register16_proxy_t>(operand.value);
//            }
//        }
//
//    private:
//        //auto load(gb_immediate_operand)
//
//        //template<typename gb_operand_type>
//        //auto load(gb_register_proxy<gb_operand_type> dst) const -> void {
//        //    dst = std::get<gb_register_proxy<gb_operand_type>>(op);
//        //}
//
//        //template<typename gb_operand_type>
//        //auto store(gb_operand_type src) -> void {
//        //    std::get<gb_register_proxy<gb_operand_type>>(op) = src;
//        //}
//
//    private:
//        gb_cpu::gb_register_bus *register_bus;
//        gb_bus *bus;
//
//        std::variant<
//            std::monostate,
//            gb_immediate_operand,
//            gb_memory_operand,
//            gb_register8_proxy_t,
//            gb_register16_proxy_t> value;
//    };
//}
//
//#endif