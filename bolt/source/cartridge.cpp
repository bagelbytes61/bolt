#include "cartridge.h"

using namespace bolt;

std::byte nes_cartridge::on_read(uint16_t address) {
    return data[address];
}

void nes_cartridge::on_write(uint16_t address, std::byte value) {
    data[address] = value;
}