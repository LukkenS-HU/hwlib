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
#include <time.h>

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
                gpio_set_function((uint)pinNumber, GPIO_FUNC_NULL);

                gpio_init((uint)pinNumber);
                SetDirection(output);
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

            void SetDirection(bool output)
            {
                gpio_set_dir(GetPinNumber(), output);
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

            void pullup_enable()
            {
                gpio_pull_up(GetPinNumber());
            }

            void pulldown_enable()
            {
                gpio_pull_down(GetPinNumber());
            }

            void pull_disable()
            {
                gpio_disable_pulls(GetPinNumber());
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

        class pin_in_out : public pin_in,
                           public pin_out,
                           public pin_oc,
                           public hwlib::pin_in_out
        {
        public:
            explicit pin_in_out(pins pinNumber)
                    : pin_in(pinNumber), pin_out(pinNumber), rp2040_pin_base(pinNumber, true)
            {
                pullup_enable();
            }

            void direction_set_input() override
            {
                SetDirection(false);
            }

            bool read() override
            {
                return pin_in::read();
            }

            void direction_set_output() override
            {
                SetDirection(true);
            }

            void write(bool x) override
            {
                pin_out::write(x);
            }

            void refresh() override
            {
                pin_in::refresh();
            }

            void flush() override
            {
                pin_out::flush();
            }

            void direction_flush() override
            {
            }
        };

        class hardware_i2c : public i2c_bus,
                                    i2c_primitives
        {
        public:
            explicit hardware_i2c(i2c_inst_t *i2cInstance, pins scl, pins sda)
            : i2c_bus((i2c_primitives&)*this), _i2cInstance(i2cInstance)
            {
                gpio_set_function(scl, GPIO_FUNC_I2C);
                gpio_set_function(sda, GPIO_FUNC_I2C);

                i2c_init(i2cInstance, 400'000);
            }

        protected:
            void begin(uint8_t address, bool read) override
            {
                _address = address;
            }

            void end_write(bool stop) override
            {

            }

            void end_read() override
            {

            }

            void write(const uint8_t* data, size_t n) override
            {
                i2c_write_blocking(_i2cInstance, _address, data, n, false);
            }

            void read(bool first_read, uint8_t* data, size_t n) override
            {
                i2c_read_blocking(_i2cInstance, _address, data, n, false);
            }

        private:
            uint8_t _address = 0;
            i2c_inst_t *_i2cInstance;
        };
    }

    namespace target = hwlib::RP2040;

#ifdef _HWLIB_ONCE

    static void initialize_uart()
    {
        static bool UartInitialized = false;
        if (UartInitialized)
            return;

        uart_init(uart0, 115200);

        gpio_set_function(PICO_DEFAULT_UART_TX_PIN, GPIO_FUNC_UART);
        gpio_set_function(PICO_DEFAULT_UART_RX_PIN, GPIO_FUNC_UART);

        UartInitialized = true;
    }

    void uart_putc(char c)
    {
        initialize_uart();

        uart_putc(uart0, c);
    }

    void wait_ms(int_fast32_t n)
    {
        sleep_ms(n);
    }

    void wait_us(int_fast32_t n)
    {
        sleep_us(n);
    }

    uint_fast64_t now_us()
    {
        return time_us_64();
    }

    uint_fast64_t now_ticks()
    {
        return time_us_64();
    }

    uint_fast64_t ticks_per_us()
    {
        return 1;
    }

#endif
}

#endif //HWLIB_HWLIB_RP2040_HPP
