#include "alu.h"
#include "register_proxy.hh"
#include "bus.hh"
#include "cartridge.h"
#include "cartridge_reader.h"
#include "cartridge_rom.h"
#include "cpu.hh"
#include "hram.hh"
#include "vram.h"
#include "emulator.h"
#include "decoder.hh"
#include "idu.hh"
#include "clock.hh"

#include <chrono>

using namespace bolt;

int main(int argc, char* argv[]) {
    auto rom_data = load_rom(argv[1]);

    //gb_tstate tstate;
    //tstate.data = 0x3e;
    //gb_decoder().cycle(tstate);
    //tstate.data = 0x41;
    //gb_decoder().cycle(tstate);
    //tstate.data = 0x46;
    //gb_decoder().cycle(tstate);
    //tstate.data = 0x75;
    //gb_decoder().cycle(tstate);
    auto rom = gb_cartridge_rom(std::move(rom_data));
    auto cartridge = gb_cartridge();
    cartridge.register_hardware(&rom, gb_cartridge_rom::addr_range);

    //auto hram = gb_hram();

    //bus.register_hardware(&cartridge, gb_cartridge::addr_range);

    auto cpu = gb_cpu(cartridge);
    ////gb_alu alu();

    gb_clock clk;


    clk.register_callback(std::bind(&gb_cpu::clk, &cpu, std::placeholders::_1, std::placeholders::_2));
    //clk.register_callback(std::bind(&gb_control_unit::clk, &ctrl_unit, std::ref(ctrl_signals), std::placeholders::_1));

    clk.start();

     //while (1) {
    //     //bus.clk(tstate);
    //     cpu.clk(tstate);
    ////    //auto start = std::chrono::high_resolution_clock::now();

    ////    //cpu.machine_cycle();

    ////    //auto stop = std::chrono::high_resolution_clock::now();

    ////    //auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);

    ////    //printf("cycle time: %.016fs\n", elapsed.count() / 1000000.f);
    //}

    return 0;
}