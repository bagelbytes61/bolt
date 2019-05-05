#ifndef BOLT_IO_REGISTERS_H_
#define BOLT_IO_REGISTERS_H_

#pragma once

#include "hardware.h"

#include <cstddef>
#include <cstdint>

namespace bolt {
    class nes_io_registers : public nes_hardware {
    public:
        static constexpr uint16_t address_begin = 0x2000;
        static constexpr uint16_t address_end = 0x2007;

    private:


    public:
        virtual ~nes_io_registers() override final;

        virtual std::byte on_read(uint16_t address) override final;

        virtual void on_write(uint16_t address, std::byte value) override final;

    private:

    };

    inline nes_io_registers::~nes_io_registers() {

    }
}

#endif