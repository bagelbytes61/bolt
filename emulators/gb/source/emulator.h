#ifndef GB_EMULATOR_H_
#define GB_EMULATOR_H_

#pragma once

#include "common.h"

#include <fstream>
#include <memory>
#include <string>

namespace bolt {
    std::unique_ptr<byte_t[]> load_rom(const std::string &filepath) {
        std::ifstream file(filepath, std::ios::binary);
        if (!file) {
            return nullptr;
        }

        file.seekg(0, std::ios::end);
        auto length = file.tellg();
        file.seekg(0, std::ios::beg);

        auto rom = std::make_unique<byte_t[]>(static_cast<size_t>(length));
        file.read(reinterpret_cast<char*>(rom.get()), length);

        file.close();

        return std::move(rom);
    }
}

#endif