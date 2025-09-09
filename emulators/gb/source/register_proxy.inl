#ifndef BOLT_REGISTER_PROXY_INL_
#define BOLT_REGISTER_PROXY_INL_

#pragma once

#include "register_proxy.hh"

#include <cstring>

namespace bolt {
    template<typename gb_register_type>
    gb_register_proxy<gb_register_type>::gb_register_proxy(gb_register8_t *register_high, gb_register8_t *register_low)
#if defined(BOLT_LITTLE_ENDIAN)
        : register_high(register_high)
        , register_low(register_low)
#elif defined(BOLT_BIG_ENDIAN)
        : register_high(register_high)
        , register_low(register_low)
#endif
        , register_t(reinterpret_cast<gb_register_t*>(this->register_low)) {

    }

    template<typename gb_register_type>
    inline gb_register_proxy<gb_register_type>::gb_register_proxy(gb_register_t *register_t)
        : register_high(nullptr)
        , register_low(nullptr)
        , register_t(register_t) {

    }

    template<typename gb_register_type>
    inline auto gb_register_proxy<gb_register_type>::operator++(void) -> gb_register_proxy<gb_register_type>& {
        ++(*register_t);

        return *this;
    }

    template<typename gb_register_type>
    inline auto gb_register_proxy<gb_register_type>::operator--(void) -> gb_register_proxy<gb_register_type>& {
        --(*register_t);

        return *this;
    }

    template<typename gb_register_type>
    inline auto gb_register_proxy<gb_register_type>::operator=(gb_register_underlying_type_t value) -> gb_register_proxy<gb_register_type>& {
        std::memcpy(register_t, &value, sizeof(value));

        return *this;
    }

    template<typename gb_register_type>
    inline auto gb_register_proxy<gb_register_type>::operator+=(gb_register_underlying_type_t value) -> gb_register_proxy<gb_register_type>& {
        *register_t += value;

        return *this;
    }

    template<typename gb_register_type>
    inline auto gb_register_proxy<gb_register_type>::operator-=(gb_register_underlying_type_t value) -> gb_register_proxy<gb_register_type>& {
        *register_t -= value;

        return *this;
    }

    template<typename gb_register_type>
    inline auto gb_register_proxy<gb_register_type>::operator&=(gb_register_underlying_type_t value) -> gb_register_proxy<gb_register_type>& {
        *register_t &= value;

        return *this;
    }

    template<typename gb_register_type>
    inline auto gb_register_proxy<gb_register_type>::operator|=(gb_register_underlying_type_t value) -> gb_register_proxy<gb_register_type>& {
        *register_t |= value;

        return *this;
    }

    template<typename gb_register_type>
    inline auto gb_register_proxy<gb_register_type>::operator^=(gb_register_underlying_type_t value) -> gb_register_proxy<gb_register_type>& {
        *register_t ^= value;

        return *this;
    }

    template<typename gb_register_type>
    inline gb_register_proxy<gb_register_type>::operator std::underlying_type_t<gb_register_type>(void) const {

        return *register_t;
    }

    //template<typename gb_register_type>
    //template<typename t>
    //inline auto gb_register_proxy<gb_register_type>::push(void) -> typename std::enable_if_t<gb_register_push_pop_enable<t>::enabled, gb_register_proxy<gb_register_type>::gb_register_underlying_type_t> {
    //    
    //    return cpu->push_register<gb_register_type>(*register_t);
    //}

    //template<typename gb_register_type>
    //template<typename t>
    //inline auto gb_register_proxy<gb_register_type>::pop(void) const -> typename std::enable_if_t<gb_register_push_pop_enable<t>::enabled, gb_register_proxy<gb_register_type>::gb_register_underlying_type_t> {
    //    
    //    return cpu->pop_register<gb_register_type>(*register_t);
    //}

    template <typename gb_register_type>
    template<typename t>
    inline auto gb_register_proxy<gb_register_type>::get_high_register(void) const -> typename std::enable_if_t<gb_register16_enable<t>::enabled, gb_register_proxy<gb_register8_type>> {
        
        return { register_high };
    }

    template <typename gb_register_type>
    template<typename t>
    inline auto gb_register_proxy<gb_register_type>::get_low_register(void) const -> typename std::enable_if_t<gb_register16_enable<t>::enabled, gb_register_proxy<gb_register8_type>> {
        
        return { register_low };
    }
}

#endif