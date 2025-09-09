#include "emulator.h"

using namespace bolt;

int emulator::emulate() {
    while (running) {
        cpu.cycle();

        cpu.handle_interrupts();
    }

    return 0;
}