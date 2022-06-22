// ==========================================================================
//
// File      : hwlib-graphics-font-8x8.hpp
// Part of   : C++ hwlib library for close-to-the-hardware OO programming
// Copyright : wouter@voti.nl 2017-2019
//
// based on https://github.com/dhepper/font8x8, which is based on
// http://dimensionalrift.homelinux.net/combuster/mos3/?p=viewsource&file=/modules/gfx/font8_8.asm
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================

// included only via hwlib.hpp, hence no multiple-include guard is needed

// this file contains Doxygen lines
/// @file

namespace hwlib
{

/// an 8x8 font   
    class font_default_8x8 : public font
    {
    private:

        static const image_8x8 images[128];

    public:

        constexpr const image& operator[](char c) const override
        {
            return images[c & 0x7F];
        }
    };


// ===========================================================================
//
// implementations
//
// ===========================================================================

#ifdef _HWLIB_ONCE

    const image_8x8 font_default_8x8::images[128] = {
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0000
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0001
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0002
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0003
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0004
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0005
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0006
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0007
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0008
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0009
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+000A
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+000B
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+000C
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+000D
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+000E
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+000F
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0010
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0011
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0012
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0013
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0014
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0015
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0016
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0017
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0018
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0019
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+001A
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+001B
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+001C
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+001D
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+001E
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+001F
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0020 ( )
            image_8x8(0x18, 0x3C, 0x3C, 0x18, 0x18, 0x00, 0x18, 0x00), // U+0021 (!)
            image_8x8(0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0022 (")
            image_8x8(0x36, 0x36, 0x7F, 0x36, 0x7F, 0x36, 0x36, 0x00), // U+0023 (#)
            image_8x8(0x0C, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x0C, 0x00), // U+0024 ($)
            image_8x8(0x00, 0x63, 0x33, 0x18, 0x0C, 0x66, 0x63, 0x00), // U+0025 (%)
            image_8x8(0x1C, 0x36, 0x1C, 0x6E, 0x3B, 0x33, 0x6E, 0x00), // U+0026 (&)
            image_8x8(0x06, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0027 (')
            image_8x8(0x18, 0x0C, 0x06, 0x06, 0x06, 0x0C, 0x18, 0x00), // U+0028 (()
            image_8x8(0x06, 0x0C, 0x18, 0x18, 0x18, 0x0C, 0x06, 0x00), // U+0029 ())
            image_8x8(0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00), // U+002A (*)
            image_8x8(0x00, 0x0C, 0x0C, 0x3F, 0x0C, 0x0C, 0x00, 0x00), // U+002B (+)
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x06), // U+002C (,)
            image_8x8(0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00), // U+002D (-)
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00), // U+002E (.)
            image_8x8(0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x00), // U+002F (/)
            image_8x8(0x3E, 0x63, 0x73, 0x7B, 0x6F, 0x67, 0x3E, 0x00), // U+0030 (0)
            image_8x8(0x0C, 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x3F, 0x00), // U+0031 (1)
            image_8x8(0x1E, 0x33, 0x30, 0x1C, 0x06, 0x33, 0x3F, 0x00), // U+0032 (2)
            image_8x8(0x1E, 0x33, 0x30, 0x1C, 0x30, 0x33, 0x1E, 0x00), // U+0033 (3)
            image_8x8(0x38, 0x3C, 0x36, 0x33, 0x7F, 0x30, 0x78, 0x00), // U+0034 (4)
            image_8x8(0x3F, 0x03, 0x1F, 0x30, 0x30, 0x33, 0x1E, 0x00), // U+0035 (5)
            image_8x8(0x1C, 0x06, 0x03, 0x1F, 0x33, 0x33, 0x1E, 0x00), // U+0036 (6)
            image_8x8(0x3F, 0x33, 0x30, 0x18, 0x0C, 0x0C, 0x0C, 0x00), // U+0037 (7)
            image_8x8(0x1E, 0x33, 0x33, 0x1E, 0x33, 0x33, 0x1E, 0x00), // U+0038 (8)
            image_8x8(0x1E, 0x33, 0x33, 0x3E, 0x30, 0x18, 0x0E, 0x00), // U+0039 (9)
            image_8x8(0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x00), // U+003A (:)
            image_8x8(0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x06), // U+003B (//)
            image_8x8(0x18, 0x0C, 0x06, 0x03, 0x06, 0x0C, 0x18, 0x00), // U+003C (<)
            image_8x8(0x00, 0x00, 0x3F, 0x00, 0x00, 0x3F, 0x00, 0x00), // U+003D (=)
            image_8x8(0x06, 0x0C, 0x18, 0x30, 0x18, 0x0C, 0x06, 0x00), // U+003E (>)
            image_8x8(0x1E, 0x33, 0x30, 0x18, 0x0C, 0x00, 0x0C, 0x00), // U+003F (?)
            image_8x8(0x3E, 0x63, 0x7B, 0x7B, 0x7B, 0x03, 0x1E, 0x00), // U+0040 (@)
            image_8x8(0x0C, 0x1E, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x00), // U+0041 (A)
            image_8x8(0x3F, 0x66, 0x66, 0x3E, 0x66, 0x66, 0x3F, 0x00), // U+0042 (B)
            image_8x8(0x3C, 0x66, 0x03, 0x03, 0x03, 0x66, 0x3C, 0x00), // U+0043 (C)
            image_8x8(0x1F, 0x36, 0x66, 0x66, 0x66, 0x36, 0x1F, 0x00), // U+0044 (D)
            image_8x8(0x7F, 0x46, 0x16, 0x1E, 0x16, 0x46, 0x7F, 0x00), // U+0045 (E)
            image_8x8(0x7F, 0x46, 0x16, 0x1E, 0x16, 0x06, 0x0F, 0x00), // U+0046 (F)
            image_8x8(0x3C, 0x66, 0x03, 0x03, 0x73, 0x66, 0x7C, 0x00), // U+0047 (G)
            image_8x8(0x33, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x33, 0x00), // U+0048 (H)
            image_8x8(0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00), // U+0049 (I)
            image_8x8(0x78, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E, 0x00), // U+004A (J)
            image_8x8(0x67, 0x66, 0x36, 0x1E, 0x36, 0x66, 0x67, 0x00), // U+004B (K)
            image_8x8(0x0F, 0x06, 0x06, 0x06, 0x46, 0x66, 0x7F, 0x00), // U+004C (L)
            image_8x8(0x63, 0x77, 0x7F, 0x7F, 0x6B, 0x63, 0x63, 0x00), // U+004D (M)
            image_8x8(0x63, 0x67, 0x6F, 0x7B, 0x73, 0x63, 0x63, 0x00), // U+004E (N)
            image_8x8(0x1C, 0x36, 0x63, 0x63, 0x63, 0x36, 0x1C, 0x00), // U+004F (O)
            image_8x8(0x3F, 0x66, 0x66, 0x3E, 0x06, 0x06, 0x0F, 0x00), // U+0050 (P)
            image_8x8(0x1E, 0x33, 0x33, 0x33, 0x3B, 0x1E, 0x38, 0x00), // U+0051 (Q)
            image_8x8(0x3F, 0x66, 0x66, 0x3E, 0x36, 0x66, 0x67, 0x00), // U+0052 (R)
            image_8x8(0x1E, 0x33, 0x07, 0x0E, 0x38, 0x33, 0x1E, 0x00), // U+0053 (S)
            image_8x8(0x3F, 0x2D, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00), // U+0054 (T)
            image_8x8(0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3F, 0x00), // U+0055 (U)
            image_8x8(0x33, 0x33, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00), // U+0056 (V)
            image_8x8(0x63, 0x63, 0x63, 0x6B, 0x7F, 0x77, 0x63, 0x00), // U+0057 (W)
            image_8x8(0x63, 0x63, 0x36, 0x1C, 0x1C, 0x36, 0x63, 0x00), // U+0058 (X)
            image_8x8(0x33, 0x33, 0x33, 0x1E, 0x0C, 0x0C, 0x1E, 0x00), // U+0059 (Y)
            image_8x8(0x7F, 0x63, 0x31, 0x18, 0x4C, 0x66, 0x7F, 0x00), // U+005A (Z)
            image_8x8(0x1E, 0x06, 0x06, 0x06, 0x06, 0x06, 0x1E, 0x00), // U+005B ([)
            image_8x8(0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x40, 0x00), // U+005C (\)
            image_8x8(0x1E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1E, 0x00), // U+005D (])
            image_8x8(0x08, 0x1C, 0x36, 0x63, 0x00, 0x00, 0x00, 0x00), // U+005E (^)
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF), // U+005F (_)
            image_8x8(0x0C, 0x0C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00), // U+0060 (`)
            image_8x8(0x00, 0x00, 0x1E, 0x30, 0x3E, 0x33, 0x6E, 0x00), // U+0061 (a)
            image_8x8(0x07, 0x06, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00), // U+0062 (b)
            image_8x8(0x00, 0x00, 0x1E, 0x33, 0x03, 0x33, 0x1E, 0x00), // U+0063 (c)
            image_8x8(0x38, 0x30, 0x30, 0x3e, 0x33, 0x33, 0x6E, 0x00), // U+0064 (d)
            image_8x8(0x00, 0x00, 0x1E, 0x33, 0x3f, 0x03, 0x1E, 0x00), // U+0065 (e)
            image_8x8(0x1C, 0x36, 0x06, 0x0f, 0x06, 0x06, 0x0F, 0x00), // U+0066 (f)
            image_8x8(0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x1F), // U+0067 (g)
            image_8x8(0x07, 0x06, 0x36, 0x6E, 0x66, 0x66, 0x67, 0x00), // U+0068 (h)
            image_8x8(0x0C, 0x00, 0x0E, 0x0C, 0x0C, 0x0C, 0x1E, 0x00), // U+0069 (i)
            image_8x8(0x30, 0x00, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E), // U+006A (j)
            image_8x8(0x07, 0x06, 0x66, 0x36, 0x1E, 0x36, 0x67, 0x00), // U+006B (k)
            image_8x8(0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00), // U+006C (l)
            image_8x8(0x00, 0x00, 0x33, 0x7F, 0x7F, 0x6B, 0x63, 0x00), // U+006D (m)
            image_8x8(0x00, 0x00, 0x1F, 0x33, 0x33, 0x33, 0x33, 0x00), // U+006E (n)
            image_8x8(0x00, 0x00, 0x1E, 0x33, 0x33, 0x33, 0x1E, 0x00), // U+006F (o)
            image_8x8(0x00, 0x00, 0x3B, 0x66, 0x66, 0x3E, 0x06, 0x0F), // U+0070 (p)
            image_8x8(0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x78), // U+0071 (q)
            image_8x8(0x00, 0x00, 0x3B, 0x6E, 0x66, 0x06, 0x0F, 0x00), // U+0072 (r)
            image_8x8(0x00, 0x00, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x00), // U+0073 (s)
            image_8x8(0x08, 0x0C, 0x3E, 0x0C, 0x0C, 0x2C, 0x18, 0x00), // U+0074 (t)
            image_8x8(0x00, 0x00, 0x33, 0x33, 0x33, 0x33, 0x6E, 0x00), // U+0075 (u)
            image_8x8(0x00, 0x00, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00), // U+0076 (v)
            image_8x8(0x00, 0x00, 0x63, 0x6B, 0x7F, 0x7F, 0x36, 0x00), // U+0077 (w)
            image_8x8(0x00, 0x00, 0x63, 0x36, 0x1C, 0x36, 0x63, 0x00), // U+0078 (x)
            image_8x8(0x00, 0x00, 0x33, 0x33, 0x33, 0x3E, 0x30, 0x1F), // U+0079 (y)
            image_8x8(0x00, 0x00, 0x3F, 0x19, 0x0C, 0x26, 0x3F, 0x00), // U+007A (z)
            image_8x8(0x38, 0x0C, 0x0C, 0x07, 0x0C, 0x0C, 0x38, 0x00), // U+007B ({)
            image_8x8(0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00), // U+007C (|)
            image_8x8(0x07, 0x0C, 0x0C, 0x38, 0x0C, 0x0C, 0x07, 0x00), // U+007D (})
            image_8x8(0x6E, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00), // U+007E (~)
            image_8x8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00)  // U+007F
    };

#endif // #ifdef _HWLIB_ONCE

}; //namespace hwlib 
