/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font D:/嵌入式/智能家居/squarelineDesign/assets/simhei.ttf -o D:/嵌入式/智能家居/squarelineDesign/assets\ui_font_Date.c --format lvgl -r 0x20-0x7f --symbols 年月日 --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_DATE
#define UI_FONT_DATE 1
#endif

#if UI_FONT_DATE

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xb0,

    /* U+0022 "\"" */
    0xbb, 0xb0,

    /* U+0023 "#" */
    0x24, 0x48, 0x91, 0x2f, 0xe4, 0x8a, 0x24, 0xfe,
    0x91, 0x22, 0x40,

    /* U+0024 "$" */
    0x11, 0xed, 0x65, 0x93, 0xc3, 0x86, 0x16, 0x59,
    0x75, 0x78, 0x41, 0x0,

    /* U+0025 "%" */
    0x45, 0x4a, 0xa5, 0x4a, 0x8a, 0x5, 0x15, 0x2a,
    0x95, 0x2a, 0x20,

    /* U+0026 "&" */
    0x30, 0x48, 0x48, 0x48, 0x50, 0x60, 0x60, 0xb2,
    0x9e, 0x8e, 0xce, 0x7a,

    /* U+0027 "'" */
    0xe0,

    /* U+0028 "(" */
    0x32, 0x44, 0x88, 0x88, 0x88, 0x44, 0x23,

    /* U+0029 ")" */
    0xc4, 0x22, 0x11, 0x11, 0x11, 0x22, 0x4c,

    /* U+002A "*" */
    0x11, 0x27, 0x59, 0xc7, 0xda, 0xc4, 0x8,

    /* U+002B "+" */
    0x10, 0x20, 0x47, 0xf1, 0x2, 0x4, 0x0,

    /* U+002C "," */
    0xe0,

    /* U+002D "-" */
    0xfe,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x0, 0x2, 0x2, 0x4, 0x4, 0x8, 0x8, 0x10,
    0x20, 0x20, 0x40, 0x40, 0x80,

    /* U+0030 "0" */
    0x38, 0xc9, 0xa, 0x1c, 0x38, 0x50, 0xa1, 0x42,
    0xcc, 0xf0, 0xc0,

    /* U+0031 "1" */
    0x2f, 0xd2, 0x49, 0x24, 0x90,

    /* U+0032 "2" */
    0x7b, 0xb8, 0x41, 0xc, 0x21, 0x84, 0x31, 0x8c,
    0x3f,

    /* U+0033 "3" */
    0x0, 0x79, 0x1a, 0x30, 0x61, 0x87, 0x3, 0x3,
    0x8d, 0x11, 0xc0,

    /* U+0034 "4" */
    0x4, 0xc, 0xc, 0x14, 0x34, 0x24, 0x44, 0xc4,
    0xff, 0x4, 0x4, 0x4,

    /* U+0035 "5" */
    0x3e, 0x40, 0x83, 0x7, 0xcc, 0x80, 0x81, 0x2,
    0x85, 0xb1, 0xc0,

    /* U+0036 "6" */
    0x8, 0x30, 0xc1, 0x7, 0x8f, 0xb1, 0xc1, 0x83,
    0x5, 0x11, 0xc0,

    /* U+0037 "7" */
    0xfe, 0xc, 0x10, 0x60, 0x83, 0x4, 0x8, 0x30,
    0x40, 0x81, 0x0,

    /* U+0038 "8" */
    0x79, 0x9a, 0x14, 0x2c, 0xcf, 0x33, 0x43, 0x87,
    0xf, 0xf3, 0xe0,

    /* U+0039 "9" */
    0x38, 0x8b, 0xe, 0x1c, 0x78, 0xdf, 0x6, 0x8,
    0x30, 0x41, 0x80,

    /* U+003A ":" */
    0x81,

    /* U+003B ";" */
    0x81, 0xc0,

    /* U+003C "<" */
    0x2, 0x8, 0x20, 0x82, 0x8, 0x10, 0x10, 0x10,
    0x10, 0x18, 0x10,

    /* U+003D "=" */
    0xfe, 0x0, 0x0, 0xf, 0xe0,

    /* U+003E ">" */
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x86, 0x18,
    0x61, 0x82, 0x0,

    /* U+003F "?" */
    0x7b, 0x38, 0x61, 0xc, 0x63, 0x8, 0x20, 0x0,
    0x8,

    /* U+0040 "@" */
    0x38, 0xc9, 0x6d, 0x5c, 0xb9, 0x74, 0xe9, 0xad,
    0x81, 0x21, 0xc0,

    /* U+0041 "A" */
    0x18, 0x18, 0x18, 0x38, 0x2c, 0x24, 0x24, 0x7e,
    0x46, 0x42, 0x42, 0xc3,

    /* U+0042 "B" */
    0xfa, 0x38, 0x61, 0x8f, 0xe8, 0xe1, 0x86, 0x18,
    0xfe,

    /* U+0043 "C" */
    0x38, 0x89, 0xc, 0x18, 0x10, 0x20, 0x41, 0x83,
    0x5, 0x11, 0xc0,

    /* U+0044 "D" */
    0xf2, 0x28, 0xe1, 0x86, 0x18, 0x61, 0x86, 0x38,
    0xbc,

    /* U+0045 "E" */
    0xfe, 0x8, 0x20, 0x83, 0xe8, 0x20, 0x82, 0x8,
    0x3f,

    /* U+0046 "F" */
    0xfe, 0x8, 0x20, 0x82, 0xf, 0xa0, 0x82, 0x8,
    0x20,

    /* U+0047 "G" */
    0x39, 0x28, 0x61, 0x82, 0x9, 0xe1, 0x86, 0x14,
    0xcf,

    /* U+0048 "H" */
    0x86, 0x18, 0x61, 0x87, 0xf8, 0x61, 0x86, 0x18,
    0x61,

    /* U+0049 "I" */
    0xff, 0xf0,

    /* U+004A "J" */
    0x4, 0x10, 0x41, 0x4, 0x10, 0x41, 0x86, 0x1c,
    0xde,

    /* U+004B "K" */
    0x8d, 0x12, 0x45, 0x8e, 0x1c, 0x3c, 0x48, 0x99,
    0x12, 0x34, 0x20,

    /* U+004C "L" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x82, 0x8,
    0x3f,

    /* U+004D "M" */
    0xc7, 0x8f, 0x1f, 0x7e, 0xf5, 0x6a, 0xd5, 0xbb,
    0x76, 0x4c, 0x90,

    /* U+004E "N" */
    0x87, 0x1c, 0x79, 0xa6, 0xdb, 0x65, 0x9e, 0x38,
    0xe1,

    /* U+004F "O" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x5, 0x11, 0xc0,

    /* U+0050 "P" */
    0xfa, 0x38, 0x61, 0x86, 0x3f, 0xa0, 0x82, 0x8,
    0x20,

    /* U+0051 "Q" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc5, 0x8b,
    0x1d, 0x19, 0xf0, 0x0,

    /* U+0052 "R" */
    0xfa, 0x38, 0x61, 0x86, 0x3f, 0xa6, 0x8a, 0x28,
    0xe1,

    /* U+0053 "S" */
    0x7a, 0x28, 0x60, 0xc1, 0xc1, 0x83, 0x86, 0x1c,
    0xde,

    /* U+0054 "T" */
    0xfc, 0x41, 0x4, 0x10, 0x41, 0x4, 0x10, 0x41,
    0x4,

    /* U+0055 "U" */
    0x86, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1c,
    0xde,

    /* U+0056 "V" */
    0xc3, 0x42, 0x42, 0x46, 0x64, 0x24, 0x24, 0x2c,
    0x38, 0x18, 0x18, 0x18,

    /* U+0057 "W" */
    0x9b, 0xdb, 0xda, 0xda, 0x5a, 0x5a, 0x6a, 0x6a,
    0x66, 0x66, 0x64, 0x64,

    /* U+0058 "X" */
    0x46, 0x66, 0x24, 0x3c, 0x18, 0x18, 0x18, 0x38,
    0x2c, 0x64, 0x46, 0xc2,

    /* U+0059 "Y" */
    0xc6, 0x89, 0x11, 0x42, 0x83, 0x4, 0x8, 0x10,
    0x20, 0x40, 0x80,

    /* U+005A "Z" */
    0xfc, 0x30, 0x86, 0x10, 0x42, 0x8, 0x41, 0x8,
    0x3f,

    /* U+005B "[" */
    0xf8, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0xf0,

    /* U+005C "\\" */
    0x82, 0x4, 0x10, 0x60, 0x82, 0x4, 0x10, 0x40,
    0x82, 0xc, 0x10,

    /* U+005D "]" */
    0xf1, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0xf0,

    /* U+005E "^" */
    0x31, 0xec, 0xc0,

    /* U+005F "_" */
    0xff,

    /* U+0060 "`" */
    0xc6, 0x20,

    /* U+0061 "a" */
    0x79, 0x98, 0x33, 0xee, 0x50, 0xa3, 0x3a,

    /* U+0062 "b" */
    0x82, 0x8, 0x20, 0xfb, 0x28, 0x61, 0x86, 0x1c,
    0xbe,

    /* U+0063 "c" */
    0x39, 0x38, 0x60, 0x82, 0x14, 0xce,

    /* U+0064 "d" */
    0x4, 0x10, 0x41, 0x7d, 0x38, 0x61, 0x86, 0x1c,
    0xdf,

    /* U+0065 "e" */
    0x38, 0x9a, 0x17, 0xe8, 0x10, 0xd1, 0x1c,

    /* U+0066 "f" */
    0x1e, 0x40, 0x81, 0xf, 0xc4, 0x8, 0x10, 0x20,
    0x40, 0x81, 0x0,

    /* U+0067 "g" */
    0x36, 0x91, 0x22, 0x47, 0x8, 0x10, 0x3e, 0x85,
    0xf0,

    /* U+0068 "h" */
    0x82, 0x8, 0x20, 0xbb, 0x18, 0x61, 0x86, 0x18,
    0x61,

    /* U+0069 "i" */
    0xcf, 0xf0,

    /* U+006A "j" */
    0x11, 0x0, 0x11, 0x11, 0x11, 0x11, 0x1e,

    /* U+006B "k" */
    0x82, 0x8, 0x20, 0x8a, 0x4a, 0x3c, 0xd2, 0x68,
    0xa3,

    /* U+006C "l" */
    0xff, 0xf0,

    /* U+006D "m" */
    0xff, 0x26, 0x4c, 0x99, 0x32, 0x64, 0xc9,

    /* U+006E "n" */
    0xbb, 0x18, 0x61, 0x86, 0x18, 0x61,

    /* U+006F "o" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x51, 0x1c,

    /* U+0070 "p" */
    0xfb, 0x28, 0x61, 0x86, 0x1c, 0xbe, 0x82, 0x0,

    /* U+0071 "q" */
    0x7f, 0x38, 0x61, 0x86, 0x14, 0xdf, 0x4, 0x10,

    /* U+0072 "r" */
    0xbe, 0xc8, 0x88, 0x88,

    /* U+0073 "s" */
    0x7a, 0x18, 0x3c, 0x3c, 0x18, 0x5e,

    /* U+0074 "t" */
    0x20, 0x40, 0x87, 0xe2, 0x4, 0x8, 0x10, 0x20,
    0x44, 0x78,

    /* U+0075 "u" */
    0x86, 0x18, 0x61, 0x86, 0x18, 0xdd,

    /* U+0076 "v" */
    0x86, 0x3c, 0x92, 0x59, 0xc3, 0xc,

    /* U+0077 "w" */
    0x9b, 0xda, 0x5a, 0x5a, 0x6a, 0x6a, 0x64, 0x24,

    /* U+0078 "x" */
    0xcd, 0x27, 0x8c, 0x31, 0xec, 0xa3,

    /* U+0079 "y" */
    0xc6, 0x89, 0x13, 0x62, 0x85, 0xe, 0x8, 0x10,
    0xc0,

    /* U+007A "z" */
    0xfc, 0x31, 0x84, 0x21, 0x8c, 0x3f,

    /* U+007B "{" */
    0x69, 0x24, 0x96, 0x49, 0x24, 0x98,

    /* U+007C "|" */
    0xff, 0xff, 0x80,

    /* U+007D "}" */
    0xc9, 0x24, 0x93, 0x49, 0x24, 0xb0,

    /* U+007E "~" */
    0x62, 0x58, 0x80,

    /* U+5E74 "年" */
    0xc, 0x0, 0x30, 0x0, 0x7f, 0xf1, 0x84, 0x2,
    0x8, 0xc, 0x10, 0x17, 0xfe, 0x8, 0x40, 0x10,
    0x80, 0x21, 0x3, 0xff, 0xf8, 0x4, 0x0, 0x8,
    0x0, 0x10, 0x0, 0x20, 0x0,

    /* U+65E5 "日" */
    0xff, 0xe0, 0x18, 0x6, 0x1, 0x80, 0x7f, 0xf8,
    0x6, 0x1, 0x80, 0x60, 0x18, 0x7, 0xff, 0x80,
    0x40,

    /* U+6708 "月" */
    0x3f, 0xe4, 0x4, 0x80, 0x9f, 0xf2, 0x2, 0x40,
    0x48, 0x9, 0xff, 0x20, 0x24, 0x5, 0x0, 0xa0,
    0x18, 0xe
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 128, .box_w = 1, .box_h = 12, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 128, .box_w = 4, .box_h = 3, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 5, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 28, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 51, .adv_w = 128, .box_w = 1, .box_h = 3, .ofs_x = 3, .ofs_y = 9},
    {.bitmap_index = 52, .adv_w = 128, .box_w = 4, .box_h = 14, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 59, .adv_w = 128, .box_w = 4, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 66, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 73, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 80, .adv_w = 128, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 81, .adv_w = 128, .box_w = 7, .box_h = 1, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 82, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 83, .adv_w = 128, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 107, .adv_w = 128, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 121, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 132, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 155, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 166, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 188, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 199, .adv_w = 128, .box_w = 1, .box_h = 8, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 200, .adv_w = 128, .box_w = 1, .box_h = 10, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 202, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 218, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 229, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 249, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 261, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 281, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 290, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 299, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 308, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 128, .box_w = 1, .box_h = 12, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 337, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 357, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 368, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 377, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 388, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 397, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 409, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 418, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 427, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 436, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 445, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 457, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 469, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 481, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 492, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 501, .adv_w = 128, .box_w = 4, .box_h = 15, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 509, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 520, .adv_w = 128, .box_w = 4, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 528, .adv_w = 128, .box_w = 6, .box_h = 3, .ofs_x = 1, .ofs_y = 11},
    {.bitmap_index = 531, .adv_w = 128, .box_w = 8, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 532, .adv_w = 128, .box_w = 4, .box_h = 3, .ofs_x = 2, .ofs_y = 11},
    {.bitmap_index = 534, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 541, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 550, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 556, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 565, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 572, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 583, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 592, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 601, .adv_w = 128, .box_w = 1, .box_h = 12, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 603, .adv_w = 128, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 610, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 619, .adv_w = 128, .box_w = 1, .box_h = 12, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 621, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 628, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 634, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 641, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 649, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 657, .adv_w = 128, .box_w = 4, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 661, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 667, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 677, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 683, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 689, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 697, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 703, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 712, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 718, .adv_w = 128, .box_w = 3, .box_h = 15, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 724, .adv_w = 128, .box_w = 1, .box_h = 17, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 727, .adv_w = 128, .box_w = 3, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 733, .adv_w = 128, .box_w = 6, .box_h = 3, .ofs_x = 1, .ofs_y = 12},
    {.bitmap_index = 736, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 765, .adv_w = 256, .box_w = 10, .box_h = 13, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 782, .adv_w = 256, .box_w = 11, .box_h = 13, .ofs_x = 2, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x771, 0x894
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 24180, .range_length = 2197, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 3, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_Date = {
#else
lv_font_t ui_font_Date = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_DATE*/

