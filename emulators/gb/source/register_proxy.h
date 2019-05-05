#ifndef BOLT_GB_REGISTER_PROXY_H_
#define BOLT_GB_REGISTER_PROXY_H_

#pragma once

#include "register_type.h"

namespace bolt {
    template<typename t>
    struct gb_register16_enable;

    template<>
    struct gb_register16_enable<gb_register8_type> {
        static constexpr bool enabled = false;
    };

    template<>
    struct gb_register16_enable<gb_register16_type> {
        static constexpr bool enabled = true;
    };

    template<>
    struct gb_register16_enable<gb_internal_register8_type> {
        static constexpr bool enabled = false;
    };

    template<>
    struct gb_register16_enable<gb_internal_register16_type> {
        static constexpr bool enabled = true;
    };

    template<typename t>
    struct gb_register64_enable;

    template<>
    struct gb_register64_enable<gb_internal_register64_type> {
        static constexpr bool enabled = true;
    };

    template<typename t>
    struct gb_register_push_pop_enable;

    template<>
    struct gb_register_push_pop_enable<gb_register8_type> {
        static constexpr bool enabled = true;
    };

    template<>
    struct gb_register_push_pop_enable<gb_register16_type> {
        static constexpr bool enabled = true;
    };

    template<>
    struct gb_register_push_pop_enable<gb_internal_register8_type> {
        static constexpr bool enabled = false;
    };

    template<>
    struct gb_register_push_pop_enable<gb_internal_register16_type> {
        static constexpr bool enabled = false;
    };

    template<>
    struct gb_register_push_pop_enable<gb_internal_register64_type> {
        static constexpr bool enabled = false;
    };

    using gb_register8_t = uint8_t;
    using gb_register16_t = uint16_t;

    using gb_internal_register8_t = uint8_t;
    using gb_internal_register16_t = uint16_t;
    using gb_internal_register64_t = uint64_t; // I can explain, I promise!

    class gb_cpu;

    template<typename gb_register_type>
    class gb_register_proxy {
        using gb_register_t = std::underlying_type_t<gb_register_type>;
        using underlying_type_t = std::underlying_type_t<gb_register_type>;
    public:
        gb_register_proxy(gb_cpu* cpu, gb_register8_t* high, gb_register8_t* low);
        gb_register_proxy(gb_cpu* cpu, gb_register_t* t);
        ~gb_register_proxy() = default;

        gb_register_proxy& operator++();
        gb_register_proxy& operator--();

        gb_register_proxy& operator=(underlying_type_t value);

        gb_register_proxy& operator+=(underlying_type_t value);
        gb_register_proxy& operator-=(underlying_type_t value);

        gb_register_proxy& operator&=(underlying_type_t value);
        gb_register_proxy& operator|=(underlying_type_t value);
        gb_register_proxy& operator^=(underlying_type_t value);


        // Ideally this would be marked explicit, but trust me I know what I'm doing :P
        operator underlying_type_t() const;

        template<typename t = gb_register_type>
        typename std::enable_if_t<gb_register_push_pop_enable<t>::enabled, underlying_type_t>
            push();

        template<typename t = gb_register_type>
        typename std::enable_if_t<gb_register_push_pop_enable<t>::enabled, underlying_type_t>
            pop();

        template <typename t = gb_register_type>
        typename std::enable_if_t<gb_register16_enable<t>::enabled, gb_register_proxy<gb_register8_type>>
            get_high_register();

        template <typename t = gb_register_type>
        typename std::enable_if_t<gb_register16_enable<t>::enabled, gb_register_proxy<gb_register8_type>>
            get_low_register();

    private:
        gb_register8_t *register_high;
        gb_register8_t *register_low;

        gb_register_t  *register_t;

        gb_cpu         *cpu;
    };
    
#include "cpu.h"

    template<typename gb_register_type>
    gb_register_proxy<gb_register_type>::gb_register_proxy(gb_cpu* cpu, gb_register8_t* high, gb_register8_t* low) 
#if defined(BOLT_LITTLE_ENDIAN)
         : register_high(low)
         , register_low(high)
         , register_t(reinterpret_cast<gb_register_t*>(register_low))
#elif defined(BOLT_BIG_ENDIAN)
        : register_high(high)
        , register_low(low)
        , register_t(reinterpret_cast<gb_register_t*>(register_high))
#endif
        , cpu(cpu) {
    }

    template<typename gb_register_type>
    gb_register_proxy<gb_register_type>::gb_register_proxy(gb_cpu* cpu, gb_register_t* t)
        : register_high(nullptr)
        , register_low(nullptr)
        , register_t(t)
        , cpu(cpu) {
    }

    template<typename gb_register_type>
    auto gb_register_proxy<gb_register_type>::operator++() -> gb_register_proxy<gb_register_type>& {
        ++(*this->register_t);

        return *this;
    }

    template<typename gb_register_type>
    auto gb_register_proxy<gb_register_type>::operator--() -> gb_register_proxy<gb_register_type>& {
        --(*this->register_t);

        return *this;
    }

    template<typename gb_register_type>
    auto gb_register_proxy<gb_register_type>::operator=(underlying_type_t value) -> gb_register_proxy<gb_register_type>& {
        std::memcpy(register_t, &value, sizeof(value));

        return *this;
    }

    template<typename gb_register_type>
    auto gb_register_proxy<gb_register_type>::operator+=(underlying_type_t value) -> gb_register_proxy<gb_register_type>& {
        *register_t += value;

        return *this;
    }

    template<typename gb_register_type>
    auto gb_register_proxy<gb_register_type>::operator-=(underlying_type_t value) -> gb_register_proxy<gb_register_type>& {
        *register_t -= value;

        return *this;
    }

    template<typename gb_register_type>
    auto gb_register_proxy<gb_register_type>::operator&=(underlying_type_t value) -> gb_register_proxy<gb_register_type>& {
        *register_t &= value;

        return *this;
    }

    template<typename gb_register_type>
    auto gb_register_proxy<gb_register_type>::operator|=(underlying_type_t value) -> gb_register_proxy<gb_register_type>& {
        *register_t |= value;

        return *this;
    }

    template<typename gb_register_type>
    auto gb_register_proxy<gb_register_type>::operator^=(underlying_type_t value) -> gb_register_proxy<gb_register_type>& {
        *register_t ^= value;

        return *this;
    }

    template<typename gb_register_type>
    gb_register_proxy<gb_register_type>::operator underlying_type_t() const {
        return *register_t;
    }

    template<typename gb_register_type>
    template<typename t>
    inline auto gb_register_proxy<gb_register_type>::push() -> typename std::enable_if_t<gb_register_push_pop_enable<t>::enabled, gb_register_proxy<gb_register_type>::underlying_type_t> {
        return cpu->push_register<gb_register_type>(register_t);
    }

    template<typename gb_register_type>
    template<typename t>
    inline auto gb_register_proxy<gb_register_type>::pop() -> typename std::enable_if_t<gb_register_push_pop_enable<t>::enabled, gb_register_proxy<gb_register_type>::underlying_type_t> {
        return cpu->pop_register<gb_register_type>(register_t);
    }

    template <typename gb_register_type> 
    template<typename t>
    inline auto gb_register_proxy<gb_register_type>::get_high_register() -> typename std::enable_if_t<gb_register16_enable<t>::enabled, gb_register_proxy<gb_register8_type>> {
        return { cpu, register_high };
    }

    template <typename gb_register_type> 
    template<typename t>
    inline auto gb_register_proxy<gb_register_type>::get_low_register() -> typename std::enable_if_t<gb_register16_enable<t>::enabled, gb_register_proxy<gb_register8_type>> {
        return { cpu, register_low };
    }

    using gb_register8_proxy_t = gb_register_proxy<gb_register8_type>;
    using gb_register16_proxy_t = gb_register_proxy<gb_register16_type>;

    using gb_internal_register8_proxy_t = gb_register_proxy<gb_internal_register8_type>;
    using gb_internal_register16_proxy_t = gb_register_proxy<gb_internal_register16_type>;
    using gb_internal_register64_proxy_t = gb_register_proxy<gb_internal_register64_type>;
}

#endif