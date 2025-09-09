#ifndef BOLT_GB_TSTATE_HH_
#define BOLT_GB_TSTATE_HH_

#pragma once

#include "common.h"

namespace bolt {
    
    //using gb_control_signals = uint64_t;

    struct gb_control_signals {
         inline static constexpr auto m1 = 1u << 0u;
         inline static constexpr auto mreq = 1u << 1u;
         inline static constexpr auto wr = 1u << 2u;
         inline static constexpr auto rd = 1u << 3u;

         inline static constexpr auto en_w_wr = 1u << 4u;
         inline static constexpr auto en_w_rd = 1u << 5u;
         inline static constexpr auto en_z_wr = 1u << 6u;
         inline static constexpr auto en_z_rd = 1u << 7u;

         inline static constexpr auto en_pc_rd_addr_bus = 1u << 8u;

         inline static constexpr auto en_ir_wr = 1u << 9u;
         inline static constexpr auto en_ir_rd_decoder = 1u << 10u;


         inline static constexpr auto en_idu_inc_pc = 1u << 11u;
         //inline static constexpr auto en_ir_wr = 1u << 14u;
         //inline static constexpr auto en_ir_wr = 1u << 15u;


        //signal_t m1;       /* Machine cycle one signal */
        //signal_t mreq;     /* Memory request signal */
        //signal_t wr;       /* Memory write signal */
        //signal_t rd;       /* Memory read signal */

        //signal_t en_w_rd;  /* W read enable */
        //signal_t en_w_wr;  /* W read enable */

        //signal_t en_z_rd;  /* Z read enable */
        //signal_t en_z_wr;  /* Z write enable */

        //signal_t en_wz_rd_addr_bus;

        //signal_t en_ir_wr; /* IR write enable */

        //signal_t en_pc_rd_addr_bus;

        //signal_t en_ir_rd_decoder;

        //signal_t en_idu_inc_pc;

        //signal_t nop_00h;
        //signal_t jp_nn_c3h;


    };

    //struct gb_tstate {
    //    addr_bus_signals_t addr_bus;
    //    data_bus_signals_t data_bus;
    //
    //    gb_control_signals ctrl_signals;

    //    int8_t cycle;
    //    //int8_t mcycle;
    //};
}

#endif