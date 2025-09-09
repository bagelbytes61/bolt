#ifndef GB_REGISTER_BUS_H_
#define GB_REGISTER_BUS_H_

#pragma once

#include "register_file.hh"

namespace bolt {
    //class gb_cpu::gb_register_bus {
    //public:
    //    gb_register_bus(gb_register_file *register_file);
    //    ~gb_register_bus() = default;

    //    gb_register_bus(const gb_register_bus &) = default;
    //    gb_register_bus(gb_register_bus &&) = default;

    //    gb_register_bus &operator=(const gb_register_bus &) = default;
    //    gb_register_bus &operator=(gb_register_bus &&) = default;

    //    template<typename gb_register_type>
    //    gb_register_proxy<gb_register_type> get_register(gb_register_type reg_type);
    //    
    //    template<typename gb_internal_register_type>
    //    gb_register_proxy<gb_internal_register_type> get_internal_register(gb_internal_register_type reg_type);
    //
    //private:
    //    gb_register_file *register_file;
    //};

    //inline gb_cpu::gb_register_bus::gb_register_bus(gb_register_file *register_file)
    //    : register_file(register_file) {

    //}

    //template<typename gb_register_type>
    //auto gb_cpu::gb_register_bus::get_register(gb_register_type reg_type) -> gb_register_proxy<gb_register_type> {
    //    return register_file->get_register(reg_type);
    //}

    //template<typename gb_internal_register_type>
    //auto gb_cpu::gb_register_bus::get_internal_register(gb_internal_register_type reg_type) -> gb_register_proxy<gb_internal_register_type> {
    //    return register_file->get_internal_register(reg_type);
    //}
}

#endif