#include "io_registers.h"

using namespace bolt;

std::byte nes_io_registers::on_read(uint16_t address) {
    return std::byte();
}

void nes_io_registers::on_write(uint16_t address, std::byte value) {
    switch (address) {

    }
}