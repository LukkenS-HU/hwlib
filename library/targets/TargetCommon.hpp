// ==========================================================================
//
// File      : TargetCommon.hpp
// Part of   : C++ hwlib library for close-to-the-hardware OO programming
// Copyright : LukkenS 2022
// License   : GNU/GPLv2 only
//
// This file is distributed under the GNU General Public License Version 2 only
// (See accompanying file LICENSE_1_1.txt)
// https://www.gnu.org/licenses/old-licenses/gpl-2.0.html
//
// ==========================================================================

#ifndef HWLIB_TARGETCOMMON_H
#define HWLIB_TARGETCOMMON_H

namespace hwlib::target
{
    struct pin_info_type
    {
        uint8_t port;
        uint8_t pin;
    };
}

#endif //HWLIB_TARGETCOMMON_H
