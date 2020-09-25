#ifndef BOLT_GB_ALU_H_
#define BOLT_GB_ALU_H_

#pragma once
#include "alu_operation_types.h"
#include "alu_bus.h"    
#include "alu_core.h"
#include "alu_latch.h"
#include "register_bus.h"

namespace bolt {
    class gb_cpu;

    //class gb_alu {
    //public:
    //    gb_alu(gb_cpu::gb_register_bus *register_bus) {}
    //    ~gb_alu() {}

    //    void machine_cycle(gb_alu_operation_type op_type) {
    //        //core.machine_cycle(operation, 0, 0);
    //    }


    //private:


    //private:
    //    gb_alu_bus hi_bus, lo_bus;

    //    gb_alu_latch a_hi_latch, a_lo_latch;
    //    gb_alu_latch b_hi_latch, b_lo_latch;
    //    gb_alu_latch r_lo_latch;
    //    
    //    gb_alu_core core;
    //};
}

#endif