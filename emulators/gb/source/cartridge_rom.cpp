#include "cartridge_rom.h"

using namespace bolt;

gb_cartridge_rom::gb_cartridge_rom(std::unique_ptr<byte_t[]> &&data)
    : data(std::move(data)) {

}