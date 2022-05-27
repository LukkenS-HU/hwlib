// ==========================================================================
//
// File      : hwlib-rp2040.hpp
// Part of   : C++ hwlib library for close-to-the-hardware OO programming
// Copyright : LukkenS 2022
// License   : GNU/GPLv2 only
//
// This file is distributed under the GNU General Public License Version 2 only
// (See accompanying file LICENSE_1_1.txt)
// https://www.gnu.org/licenses/old-licenses/gpl-2.0.html
//
// ==========================================================================

#ifndef HWLIB_HWLIB_RP2040_HPP
#define HWLIB_HWLIB_RP2040_HPP

#include <hwlib-all.hpp>

#include <hardware/gpio.h>
#include <hardware/i2c.h>
#include <hardware/uart.h>

namespace hwlib
{
    namespace RP2040
    {
        enum pins : uint8_t
        {
            PIN_GP0 = 0,
            PIN_GP1 = 1,
            PIN_GP2 = 2,
            PIN_GP3 = 3,
            PIN_GP4 = 4,
            PIN_GP5 = 5,
            PIN_GP6 = 6,
            PIN_GP7 = 7,
            PIN_GP8 = 8,
            PIN_GP9 = 9,
            PIN_GP10 = 10,
            PIN_GP11 = 11,
            PIN_GP12 = 12,
            PIN_GP13 = 13,
            PIN_GP14 = 14,
            PIN_GP15 = 15,
            PIN_GP16 = 16,
            PIN_GP17 = 17,
            PIN_GP18 = 18,
            PIN_GP19 = 19,
            PIN_GP20 = 20,
            PIN_GP21 = 21,
            PIN_GP22 = 22,
            PIN_GP23 = 23,
            PIN_GP24 = 24,
            PIN_GP25 = 25,
            PIN_GP26 = 26,
            PIN_GP27 = 27,
            PIN_GP28 = 28,

            PIN_BUILTIN_LED = PICO_DEFAULT_LED_PIN,

            PIN_ADC0 = PIN_GP26,
            PIN_ADC1 = PIN_GP27,
            PIN_ADC2 = PIN_GP28
        };

        class rp2040_pin_base
        {
        protected:
            explicit rp2040_pin_base(pins pinNumber, bool output)
                    : _pinNumber(pinNumber)
            {
                gpio_init((uint)pinNumber);
                gpio_set_dir((uint)pinNumber, output);
            }

            [[nodiscard]]
            pins GetPinNumber() const
            {
                return _pinNumber;
            }

            void SetPinNumber(pins value)
            {
                _pinNumber = value;
            }

        private:
            pins _pinNumber;
        };

        class pin_in : public virtual rp2040_pin_base, public hwlib::pin_in
        {
        public:
            explicit pin_in(pins pinNumber)
                    : rp2040_pin_base(pinNumber, GPIO_IN)
            {
            }

            bool read() override
            {
                return gpio_get(GetPinNumber());
            }
        };

        class pin_out : public virtual rp2040_pin_base, public hwlib::pin_out
        {
        public:
            explicit pin_out(pins pinNumber)
                    : rp2040_pin_base(pinNumber, GPIO_OUT)
            {
            }

            void write(bool x) override
            {
                gpio_put(GetPinNumber(), x);
            }

            void flush() override
            {
            }
        };

        // TODO: HWLIB seems to have a very particular way of handling I2C that does not really work with hardware implementations,
        //       Since it seems to manually send every control message instead
        //       (The repository doesn't seem to contain any hardware I2C implementations either)
        //       of letting the potential hardware implementation handle the device address for example.
        //       Changing the HWLIB api would break everything, so I'll just leave the 'BitBanged' implementation for what it is
        //       and pretend the RP2040 does not actually have hardware I2C.
        namespace I2C
        {

        }
    }

    namespace target = hwlib::RP2040;

#ifdef _HWLIB_ONCE

    void uart_putc(char c)
    {
        uart_putc(uart0, c);
    }

    void wait_ms(int_fast32_t n)
    {
        sleep_ms(n);
    }

#endif
}

#endif //HWLIB_HWLIB_RP2040_HPP
