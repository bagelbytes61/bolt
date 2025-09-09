//#ifndef BOLT_GB_REGISTER_PROXY_H_
//#define BOLT_GB_REGISTER_PROXY_H_
//
//#pragma once
//
//#include "register_type.hh"
//
//#include <type_traits>
//
//namespace bolt {
//    template<typename t>
//    struct gb_register16_enable;
//
//    template<>
//    struct gb_register16_enable<gb_register8_type> {
//        static constexpr bool enabled = false;
//    };
//
//    template<>
//    struct gb_register16_enable<gb_register16_type> {
//        static constexpr bool enabled = true;
//    };
//
//    template<>
//    struct gb_register16_enable<gb_internal_register8_type> {
//        static constexpr bool enabled = false;
//    };
//
//    template<>
//    struct gb_register16_enable<gb_internal_register16_type> {
//        static constexpr bool enabled = true;
//    };
//
//    template<typename t>
//    struct gb_register64_enable;
//
//    template<>
//    struct gb_register64_enable<gb_internal_register64_type> {
//        static constexpr bool enabled = true;
//    };
//
//    template<typename t>
//    struct gb_register_push_pop_enable;
//
//    template<>
//    struct gb_register_push_pop_enable<gb_register8_type> {
//        static constexpr bool enabled = true;
//    };
//
//    template<>
//    struct gb_register_push_pop_enable<gb_register16_type> {
//        static constexpr bool enabled = true;
//    };
//
//    template<>
//    struct gb_register_push_pop_enable<gb_internal_register8_type> {
//        static constexpr bool enabled = false;
//    };
//
//    template<>
//    struct gb_register_push_pop_enable<gb_internal_register16_type> {
//        static constexpr bool enabled = false;
//    };
//
//    template<>
//    struct gb_register_push_pop_enable<gb_internal_register64_type> {
//        static constexpr bool enabled = false;
//    };
//
//    class gb_cpu;
//
//    template<typename gb_register_type>
//    class gb_register_proxy {
//        using gb_register_t = std::underlying_type_t<gb_register_type>;
//        using gb_register_underlying_type_t = std::underlying_type_t<gb_register_type>;
//
//    public:
//        gb_register_proxy(gb_register8_t *register_high, gb_register8_t *register_low);
//        gb_register_proxy(gb_register_t *register_t);
//        ~gb_register_proxy() = default;
//
//        auto operator&(void) -> gb_register_t *{
//            return register_t;
//        }
//
//        gb_register_proxy& operator++(void);
//        gb_register_proxy& operator--(void);
//
//        gb_register_proxy& operator=(gb_register_underlying_type_t value);
//
//        gb_register_proxy& operator+=(int8_t value) { *register_t += value; return *this; }
//        gb_register_proxy& operator+=(gb_register_underlying_type_t value);
//        gb_register_proxy& operator-=(gb_register_underlying_type_t value);
//
//        gb_register_proxy& operator&=(gb_register_underlying_type_t value);
//        gb_register_proxy& operator|=(gb_register_underlying_type_t value);
//        gb_register_proxy& operator^=(gb_register_underlying_type_t value);
//
//        // gb_register_t &operator *(void) const;
//        operator gb_register_t(void) const;
//
//        //template<typename t = gb_register_type>
//        //typename std::enable_if_t<gb_register_push_pop_enable<t>::enabled, gb_register_t>
//        //    push(void);
//
//        //template<typename t = gb_register_type>
//        //typename std::enable_if_t<gb_register_push_pop_enable<t>::enabled, gb_register_t>
//        //    pop(void) const;
//
//        template <typename t = gb_register_type>
//        typename std::enable_if_t<gb_register16_enable<t>::enabled, gb_register_proxy<gb_register8_type>>
//            get_high_register(void) const;
//
//        template <typename t = gb_register_type>
//        typename std::enable_if_t<gb_register16_enable<t>::enabled, gb_register_proxy<gb_register8_type>>
//            get_low_register(void) const;
//
//    private:
//        gb_register8_t *register_high;
//        gb_register8_t *register_low;
//
//        gb_register_t  *register_t;
//    };
//
//    using gb_register8_proxy_t = gb_register_proxy<gb_register8_type>;
//    using gb_register16_proxy_t = gb_register_proxy<gb_register16_type>;
//
//    using gb_internal_register8_proxy_t = gb_register_proxy<gb_internal_register8_type>;
//    using gb_internal_register16_proxy_t = gb_register_proxy<gb_internal_register16_type>;
//    using gb_internal_register64_proxy_t = gb_register_proxy<gb_internal_register64_type>;
//}
//
//#include "register_proxy.inl"
//
//#endif