#ifndef BOLT_EMULATOR_H_
#define BOLT_EMULATOR_H_

#pragma once

#include "cartridge.h"
#include "cpu_bus.h"
#include "cpu.h"
#include "internal_ram.h"
#include "io_registers.h"
#include "ppu_registers.h"

namespace bolt {
    class emulator {
    public:
        emulator()
            : cpu(&cpu_bus)
            , running(true) {

            //cpu_bus.register_hardware(&internal_ram, nes_internal_ram::address_begin, nes_internal_ram::address_end);
            cpu_bus.register_hardware(&ppu_registers, nes_ppu_registers::address_begin, nes_ppu_registers::address_end);
            cpu_bus.register_hardware(&io_registers, nes_io_registers::address_begin, nes_io_registers::address_end);
            cpu_bus.register_hardware(&cartridge, nes_cartridge::address_begin, nes_cartridge::address_end);
        }
        ~emulator() {}

        int emulate();

    private:
        nes_cpu_bus         cpu_bus;
       // nes_ppu_bus
        nes_internal_ram    internal_ram;
        nes_cartridge       cartridge;
        nes_ppu_registers   ppu_registers;
        nes_io_registers    io_registers;
        nes_cpu             cpu;

        bool                running;
    };
}

#endif