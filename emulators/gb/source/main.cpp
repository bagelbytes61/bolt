#include "bus.h"
#include "cartridge.h"
#include "cartridge_reader.h"
#include "cartridge_rom.h"
#include "cpu.h"
#include "vram.h"

#include "emulator.h"

#include <chrono>

using namespace bolt;

int main(int argc, char* argv[]) {
    auto rom_data = load_rom(argv[1]);

    auto rom = std::make_unique<gb_cartridge_rom>(std::move(rom_data));

    auto cartridge = std::make_shared<gb_cartridge>();
    cartridge->register_hardware(std::move(rom), gb_cartridge_rom::addr_begin, gb_cartridge_rom::addr_end);

    std::unique_ptr<gb_bus> bus = std::make_unique<gb_bus>();
    bus->register_hardware(cartridge, gb_cartridge::addr_begin, gb_cartridge::addr_end);

    gb_cpu cpu(std::move(bus));

    while (1) {
        //auto start = std::chrono::high_resolution_clock::now();

        //for (int i = 0; i < 1000000; ++i)
            cpu.machine_cycle();

        //auto stop = std::chrono::high_resolution_clock::now();

        //auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);

        //printf("cycle time: %.016fs\n", elapsed.count() / 1000000.f);
    }

    return 0;
}