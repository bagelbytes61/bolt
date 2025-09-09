#include "bus.hh"

#include "hardware.hh"

using namespace bolt;

static inline auto gb_bus_read(const gb_memory_map &mem_map, addr_t addr) -> word_t {
    auto it = mem_map.cbegin();

    while (addr >= GB_MEMORY_REGION_ADDR_END(it)) { ++it; };

    if (it != mem_map.cend()) {
        return GB_MEMORY_REGION(it)->on_read_word(addr - GB_MEMORY_REGION_ADDR_BEGIN(it));
    }
}

static inline auto gb_bus_write(gb_memory_map &mem_map, addr_t addr, word_t data) -> void {    
    auto it = mem_map.begin();
    
    while (addr >= GB_MEMORY_REGION_ADDR_END(it++));
    
    if (it != mem_map.end()) {
        GB_MEMORY_REGION(it)->on_write_word(addr - GB_MEMORY_REGION_ADDR_BEGIN(it), data);
    }
}

auto gb_bus::clk(gb_control_signals &ctrl_signals, uint64_t cycle) -> void {
    if (ctrl_signals.rd) {
        data_bus = gb_bus_read(memory_map, addr_bus);
    } else if (ctrl_signals.wr) {
        gb_bus_write(memory_map, addr_bus, data_bus);
    }
}

auto gb_bus::register_memory_region(gb_hardware *hardware, addr_range_t addr_range) -> void {
    memory_map.emplace(addr_range, hardware);
}

auto gb_bus::get_address_bus(void) -> addr_bus_t & {
    return addr_bus;
}

auto gb_bus::get_data_bus(void) -> data_bus_t & {
    return data_bus;
}