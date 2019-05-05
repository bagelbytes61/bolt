#ifndef BOLT_GB_CARTRIDGE_READER_H_
#define BOLT_GB_CARTRIDGE_READER_H_

#pragma once

#include "common.h"

#include "cartridge_country_code.h"
#include "cartridge_licensee.h"
#include "cartridge_ram_size.h"
#include "cartridge_rom_size.h"
#include "cartridge_type.h"

#include <cstdint>
#include <fstream>
#include <memory>
#include <string>

namespace bolt {
    class gb_cartridge_reader {
    public:
        gb_cartridge_reader(const byte_t *rom);
        ~gb_cartridge_reader();

        std::string get_title() const;

        gb_cartridge_licensee get_licensee() const;

        gb_cartridge_type get_type() const;

        gb_cartridge_rom_size get_rom_size() const;

        gb_cartridge_ram_size get_ram_size() const;

        gb_cartridge_country_code  get_country_code() const;

    private:
        std::string read_title(const byte_t *rom);

        gb_cartridge_licensee read_licensee(const byte_t *rom);

        gb_cartridge_type read_type(const byte_t *rom);

        gb_cartridge_rom_size read_rom_size(const byte_t *rom);

        gb_cartridge_ram_size read_ram_size(const byte_t *rom);

        gb_cartridge_country_code read_country_code(const byte_t *rom);

    private:
        std::string title;

        gb_cartridge_licensee licensee;

        gb_cartridge_type type;

        gb_cartridge_rom_size rom_size;

        gb_cartridge_ram_size ram_size;

        gb_cartridge_country_code country_code;
    };

    inline std::string gb_cartridge_reader::get_title() const {
        return title;
    }

    inline gb_cartridge_licensee gb_cartridge_reader::get_licensee() const {
        return licensee;
    }

    inline gb_cartridge_type gb_cartridge_reader::get_type() const {
        return type;
    }

    inline gb_cartridge_rom_size gb_cartridge_reader::get_rom_size() const {
        return rom_size;
    }

    inline gb_cartridge_ram_size gb_cartridge_reader::get_ram_size() const {
        return ram_size;
    }

    inline gb_cartridge_country_code gb_cartridge_reader::get_country_code() const {
        return country_code;
    }
}

#endif