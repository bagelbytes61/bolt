#include "internal_ram.h"

using namespace bolt;

std::byte nes_internal_ram::on_read(uint16_t address) {
    return data[address];
}

void nes_internal_ram::on_write(uint16_t address, std::byte value) {
    data[address] = value;
}