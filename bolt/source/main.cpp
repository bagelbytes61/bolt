#include "emulator.h"

#include "instruction.h"

int main(int argc, char* argv[]) {
    bolt::emulator emulator;

    std::cout << bolt::nes_instruction<0x31>::bytes << '\n';
    std::cout << bolt::nes_instruction<0x31>::cycles << '\n';


    return emulator.emulate();
}