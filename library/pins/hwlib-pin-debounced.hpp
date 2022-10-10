// ==========================================================================
//
// File      : hwlib-pin-debounced.hpp
// Part of   : C++ hwlib library for close-to-the-hardware OO programming
// Copyright : LukkenS 2022
// License   : GNU/GPLv2 only
//
// This file is distributed under the GNU General Public License Version 2 only
// (See accompanying file LICENSE_1_1.txt)
// https://www.gnu.org/licenses/old-licenses/gpl-2.0.html
//
// ==========================================================================

// included only via hwlib.hpp, hence no multiple-include guard is needed

// this file contains Doxygen lines
/// @file

#ifndef HWLIB_HWLIB_PIN_DEBOUNCED_H
#define HWLIB_HWLIB_PIN_DEBOUNCED_H

namespace hwlib
{
    class pin_in_debounced : public pin_in
    {
    public:
        explicit pin_in_debounced(hwlib::pin_in& wrappedPin, uint64_t minDebounceTimeUS, bool debounceHigh, bool debounceLow)
        : _wrappedPin(wrappedPin), _minDebounceTimeUS(minDebounceTimeUS), _state(wrappedPin.read()), _debouncedState(_state),
          _debounceHigh(debounceHigh), _debounceLow(debounceLow)
        {}

        bool read() override
        {
            return _debouncedState;
        }

        void refresh() override
        {
            _wrappedPin.refresh();

            bool newState = _wrappedPin.read();
            if (_state != newState)
            {
                if (newState && !_debounceHigh || !newState && !_debounceLow)
                    _debouncedState = newState;
                else
                {
                    _state = newState;
                    _lastStateChangeTime = hwlib::now_us();
                }

                return;
            }

            if (GetCurrentStateTimeMS() < _minDebounceTimeUS || _state == _debouncedState)
                return;

            _debouncedState = _state;
        }

        // Gets how long the current state has not changed.
        [[nodiscard]]
        uint64_t GetCurrentStateTimeMS() const
        {
            return hwlib::now_us() - _lastStateChangeTime;
        }

    private:
        bool _debounceHigh;
        bool _debounceLow;

        bool _state;
        bool _debouncedState;

        uint64_t _lastStateChangeTime = 0;
        uint64_t _minDebounceTimeUS = 0;

        hwlib::pin_in &_wrappedPin;
    };
}

#endif //HWLIB_HWLIB_PIN_DEBOUNCED_H
