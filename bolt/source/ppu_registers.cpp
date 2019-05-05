#include "ppu_registers.h"

using namespace bolt;

std::byte nes_ppu_registers::on_read(uint16_t address) {
    switch (address) {
    case ppuctrl_address:   return ppuctrl;
    case ppumask_address:   return ppumask;
    case ppustatus_address: return ppustatus;
    case oamaddr_address:   return oamaddr;
    case oamdata_address:   return oamdata;
    case ppuscroll_address: return ppuscroll;
    case ppuaddr_address:   return ppuaddr;
    case ppudata_address:   return ppudata;
    }
}

void nes_ppu_registers::on_write(uint16_t address, std::byte value) {

}