#include "cartridge_reader.h"

using namespace bolt;

#define GB_CARTRIDGE_TITLE_OFFSET             0x0134
#define GB_CARTRIDGE_NEW_LICENSEE_CODE_OFFSET 0x0144
#define GB_CARTRIDGE_TYPE_OFFSET              0x0147
#define GB_CARTRIDGE_ROM_SIZE_OFFSET          0x0148
#define GB_CARTRIDGE_RAM_SIZE_OFFSET          0x0149
#define GB_CARTRIDGE_COUNTRY_CODE_OFFSET      0x014a
#define GB_CARTRIDGE_OLD_LICENSEE_CODE_OFFSET 0x014b

#define GB_USES_NEW_LICENSEE_CODE             0x33

#include <exception>

gb_cartridge_reader::gb_cartridge_reader(const byte_t *rom)
    : title(read_title(rom))
    , licensee(read_licensee(rom))
    , type(read_type(rom))
    , rom_size(read_rom_size(rom))
    , ram_size(read_ram_size(rom))
    , country_code(read_country_code(rom)) {

}

gb_cartridge_reader::~gb_cartridge_reader() {

}

std::string gb_cartridge_reader::read_title(const byte_t *rom) {
    std::string title(11, '\0');

    title.assign(reinterpret_cast<const char*>(rom + GB_CARTRIDGE_TITLE_OFFSET), 11);

    return title;
}

gb_cartridge_licensee gb_cartridge_reader::read_licensee(const byte_t *rom) {
    uint8_t old_licensee;

    std::memcpy(&old_licensee, rom + GB_CARTRIDGE_OLD_LICENSEE_CODE_OFFSET, sizeof(old_licensee));
    if (old_licensee != GB_USES_NEW_LICENSEE_CODE) {
        return static_cast<gb_cartridge_licensee>(old_licensee);
    }

    uint16_t new_licensee;

    std::memcpy(&new_licensee, rom + GB_CARTRIDGE_NEW_LICENSEE_CODE_OFFSET, sizeof(new_licensee));

    return static_cast<gb_cartridge_licensee>(new_licensee);
}

gb_cartridge_type gb_cartridge_reader::read_type(const byte_t *rom) {
    uint8_t type;

    std::memcpy(&type, rom + GB_CARTRIDGE_TYPE_OFFSET, sizeof(type));

    return static_cast<gb_cartridge_type>(type);
}

gb_cartridge_rom_size gb_cartridge_reader::read_rom_size(const byte_t *rom) {
    uint8_t rom_size;

    std::memcpy(&rom_size, rom + GB_CARTRIDGE_ROM_SIZE_OFFSET, sizeof(rom_size));

    return static_cast<gb_cartridge_rom_size>(rom_size);
}

gb_cartridge_ram_size gb_cartridge_reader::read_ram_size(const byte_t *rom) {
    uint8_t ram_size;
    
    std::memcpy(&ram_size, rom + GB_CARTRIDGE_RAM_SIZE_OFFSET, sizeof(ram_size));

    return static_cast<gb_cartridge_ram_size>(ram_size);
}

gb_cartridge_country_code gb_cartridge_reader::read_country_code(const byte_t *rom) {
    uint8_t country_code;

    std::memcpy(&country_code, rom + GB_CARTRIDGE_COUNTRY_CODE_OFFSET, sizeof(country_code));

    return static_cast<gb_cartridge_country_code>(country_code);
}