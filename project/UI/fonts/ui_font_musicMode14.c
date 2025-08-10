/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --font D:/嵌入式/智能家居/squarelineDesign/assets/simhei.ttf -o D:/嵌入式/智能家居/squarelineDesign/assets\ui_font_musicMode14.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_MUSICMODE14
#define UI_FONT_MUSICMODE14 1
#endif

#if UI_FONT_MUSICMODE14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0x20,

    /* U+0022 "\"" */
    0xb6, 0x80,

    /* U+0023 "#" */
    0x28, 0xa4, 0xbf, 0x49, 0x2f, 0xd4, 0x51, 0x40,

    /* U+0024 "$" */
    0x21, 0x1d, 0x5a, 0xf1, 0x86, 0x2d, 0x6a, 0xe2,
    0x10,

    /* U+0025 "%" */
    0xea, 0xab, 0x2c, 0xf0, 0x73, 0x55, 0x55, 0x70,

    /* U+0026 "&" */
    0x31, 0x24, 0x94, 0x61, 0x89, 0x67, 0x8d, 0xf0,

    /* U+0027 "'" */
    0xe0,

    /* U+0028 "(" */
    0x2, 0x44, 0x88, 0x88, 0x88, 0x42, 0x20,

    /* U+0029 ")" */
    0x4, 0x22, 0x11, 0x11, 0x11, 0x24, 0x40,

    /* U+002A "*" */
    0x10, 0x21, 0xf1, 0xcf, 0xc2, 0x4, 0x0,

    /* U+002B "+" */
    0x10, 0x23, 0xf8, 0x81, 0x2, 0x0,

    /* U+002C "," */
    0xc0,

    /* U+002D "-" */
    0xfe,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x4, 0x8, 0x20, 0x41, 0x2, 0x8, 0x10, 0x40,
    0x82, 0x0,

    /* U+0030 "0" */
    0x39, 0x24, 0x51, 0x86, 0x18, 0x51, 0x4c, 0xe0,
    0x0,

    /* U+0031 "1" */
    0x2e, 0x92, 0x49, 0x24,

    /* U+0032 "2" */
    0x7b, 0x28, 0xc2, 0x8, 0x43, 0x18, 0xc3, 0xf0,

    /* U+0033 "3" */
    0x74, 0x62, 0x13, 0xc, 0x31, 0x8b, 0x80,

    /* U+0034 "4" */
    0x8, 0x30, 0x61, 0x46, 0x89, 0x22, 0x7f, 0x8,
    0x10,

    /* U+0035 "5" */
    0x7d, 0x4, 0x1e, 0x4c, 0x10, 0x61, 0x4d, 0xe0,

    /* U+0036 "6" */
    0x10, 0xc2, 0x10, 0xfa, 0x18, 0x61, 0xcd, 0xe0,

    /* U+0037 "7" */
    0xfc, 0x10, 0x82, 0x10, 0x42, 0x8, 0x21, 0x80,

    /* U+0038 "8" */
    0x7a, 0x28, 0xe2, 0x73, 0x38, 0x61, 0xcd, 0xe0,

    /* U+0039 "9" */
    0x79, 0x38, 0x61, 0xcd, 0xe1, 0x84, 0x30, 0x80,

    /* U+003A ":" */
    0x82,

    /* U+003B ";" */
    0x83, 0x0,

    /* U+003C "<" */
    0x0, 0x10, 0x84, 0x21, 0x4, 0x8, 0x10, 0x30,
    0x40,

    /* U+003D "=" */
    0xfe, 0x0, 0x0, 0xf, 0xe0,

    /* U+003E ">" */
    0x1, 0x2, 0x4, 0x8, 0x10, 0x46, 0x31, 0x84,
    0x0,

    /* U+003F "?" */
    0x76, 0x62, 0x11, 0x18, 0x80, 0x1, 0x0,

    /* U+0040 "@" */
    0x38, 0x8b, 0xed, 0x5c, 0xbb, 0x74, 0xf6, 0x40,
    0x70,

    /* U+0041 "A" */
    0x10, 0x60, 0xa1, 0x42, 0x8d, 0x9f, 0x22, 0x45,
    0x8c,

    /* U+0042 "B" */
    0xf2, 0x28, 0xa2, 0xf2, 0x38, 0x61, 0x8f, 0xe0,

    /* U+0043 "C" */
    0x39, 0x38, 0x61, 0x82, 0x8, 0x61, 0x4c, 0xe0,

    /* U+0044 "D" */
    0xf2, 0x28, 0x61, 0x86, 0x18, 0x61, 0x8b, 0xc0,

    /* U+0045 "E" */
    0xfc, 0x21, 0xf, 0xc2, 0x10, 0x87, 0xc0,

    /* U+0046 "F" */
    0xfc, 0x21, 0xf, 0x42, 0x10, 0x84, 0x0,

    /* U+0047 "G" */
    0x39, 0x38, 0x60, 0x82, 0x78, 0x61, 0x4c, 0xf0,

    /* U+0048 "H" */
    0x86, 0x18, 0x61, 0xfe, 0x18, 0x61, 0x86, 0x10,

    /* U+0049 "I" */
    0xff, 0xc0,

    /* U+004A "J" */
    0x8, 0x42, 0x10, 0x86, 0x31, 0x8b, 0x80,

    /* U+004B "K" */
    0x8a, 0x4b, 0x28, 0xe3, 0xc9, 0x26, 0x8a, 0x30,

    /* U+004C "L" */
    0x84, 0x21, 0x8, 0x42, 0x10, 0x87, 0xc0,

    /* U+004D "M" */
    0xcf, 0x3c, 0xf3, 0xce, 0xdb, 0x6d, 0xb6, 0xd0,

    /* U+004E "N" */
    0x87, 0x1c, 0x79, 0xb6, 0xd9, 0xe3, 0x8e, 0x10,

    /* U+004F "O" */
    0x79, 0x28, 0x61, 0x86, 0x18, 0x61, 0x49, 0xe0,

    /* U+0050 "P" */
    0xfa, 0x38, 0x61, 0x8f, 0xe8, 0x20, 0x82, 0x0,

    /* U+0051 "Q" */
    0x79, 0x28, 0x61, 0x86, 0x19, 0x67, 0x4d, 0xf0,
    0x0,

    /* U+0052 "R" */
    0xfa, 0x38, 0x61, 0x8f, 0xe9, 0xa2, 0x8e, 0x10,

    /* U+0053 "S" */
    0x7a, 0x28, 0x70, 0x70, 0x60, 0x61, 0xcd, 0xe0,

    /* U+0054 "T" */
    0xfc, 0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x80,

    /* U+0055 "U" */
    0x86, 0x18, 0x61, 0x86, 0x18, 0x61, 0xcd, 0xe0,

    /* U+0056 "V" */
    0xc6, 0x89, 0x12, 0x26, 0x85, 0xa, 0x14, 0x30,
    0x20,

    /* U+0057 "W" */
    0x97, 0x2f, 0xd7, 0xa6, 0xcd, 0x9b, 0x36, 0x6c,
    0x98,

    /* U+0058 "X" */
    0x44, 0x98, 0xa1, 0xc1, 0x6, 0xa, 0x34, 0x45,
    0x88,

    /* U+0059 "Y" */
    0x44, 0x88, 0xa1, 0x41, 0x2, 0x4, 0x8, 0x10,
    0x20,

    /* U+005A "Z" */
    0x7c, 0x10, 0x86, 0x10, 0xc6, 0x18, 0xc3, 0xf0,

    /* U+005B "[" */
    0xf8, 0x88, 0x88, 0x88, 0x88, 0x88, 0xf0,

    /* U+005C "\\" */
    0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x82, 0x10,

    /* U+005D "]" */
    0xf1, 0x11, 0x11, 0x11, 0x11, 0x11, 0xf0,

    /* U+005E "^" */
    0x23, 0xa6,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0x88, 0x80,

    /* U+0061 "a" */
    0x76, 0x46, 0xf8, 0xcd, 0xe0,

    /* U+0062 "b" */
    0x84, 0x21, 0xed, 0xc6, 0x31, 0xdf, 0x80,

    /* U+0063 "c" */
    0x7b, 0x38, 0x20, 0x87, 0x17, 0x80,

    /* U+0064 "d" */
    0x8, 0x42, 0xfd, 0xc6, 0x31, 0xdb, 0xc0,

    /* U+0065 "e" */
    0x73, 0x28, 0xbe, 0x83, 0x27, 0x80,

    /* U+0066 "f" */
    0x1c, 0x82, 0x3e, 0x20, 0x82, 0x8, 0x20, 0x80,

    /* U+0067 "g" */
    0x35, 0x24, 0x92, 0x71, 0x7, 0xe1, 0x78,

    /* U+0068 "h" */
    0x84, 0x21, 0x6c, 0xc6, 0x31, 0x8c, 0x40,

    /* U+0069 "i" */
    0x9f, 0xc0,

    /* U+006A "j" */
    0x10, 0x1, 0x11, 0x11, 0x11, 0x1e,

    /* U+006B "k" */
    0x84, 0x21, 0x3b, 0x53, 0xd2, 0x9c, 0x40,

    /* U+006C "l" */
    0xff, 0xc0,

    /* U+006D "m" */
    0xff, 0x26, 0x4c, 0x99, 0x32, 0x64, 0x80,

    /* U+006E "n" */
    0xb6, 0x63, 0x18, 0xc6, 0x20,

    /* U+006F "o" */
    0x7b, 0x38, 0x61, 0x87, 0x27, 0x80,

    /* U+0070 "p" */
    0xf6, 0xe3, 0x18, 0xef, 0xd0, 0x80,

    /* U+0071 "q" */
    0x7c, 0xe3, 0x18, 0xcd, 0xe1, 0x8,

    /* U+0072 "r" */
    0xbc, 0x88, 0x88, 0x80,

    /* U+0073 "s" */
    0x74, 0x60, 0xe0, 0xc5, 0xc0,

    /* U+0074 "t" */
    0x20, 0x8f, 0x88, 0x20, 0x82, 0x8, 0x1c,

    /* U+0075 "u" */
    0x8c, 0x63, 0x18, 0xcd, 0xa0,

    /* U+0076 "v" */
    0x45, 0x14, 0x8a, 0x28, 0xc1, 0x0,

    /* U+0077 "w" */
    0x93, 0x69, 0xd3, 0x66, 0xcd, 0x9a, 0x0,

    /* U+0078 "x" */
    0x44, 0xa3, 0x84, 0x29, 0xa4, 0x40,

    /* U+0079 "y" */
    0x45, 0x14, 0x8a, 0x28, 0xc1, 0x4, 0x60,

    /* U+007A "z" */
    0xf8, 0xc4, 0x44, 0x63, 0xe0,

    /* U+007B "{" */
    0x69, 0x24, 0xb2, 0x49, 0x26,

    /* U+007C "|" */
    0xff, 0xfe,

    /* U+007D "}" */
    0xc9, 0x24, 0x9a, 0x49, 0x2c,

    /* U+007E "~" */
    0x45, 0x46
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 112, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 112, .box_w = 1, .box_h = 11, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 112, .box_w = 3, .box_h = 3, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 5, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 13, .adv_w = 112, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 22, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 30, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 38, .adv_w = 112, .box_w = 1, .box_h = 3, .ofs_x = 3, .ofs_y = 7},
    {.bitmap_index = 39, .adv_w = 112, .box_w = 4, .box_h = 13, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 46, .adv_w = 112, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 53, .adv_w = 112, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 60, .adv_w = 112, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 66, .adv_w = 112, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 67, .adv_w = 112, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 68, .adv_w = 112, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 69, .adv_w = 112, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 79, .adv_w = 112, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 88, .adv_w = 112, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 92, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 100, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 107, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 132, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 140, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 148, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 112, .box_w = 1, .box_h = 7, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 157, .adv_w = 112, .box_w = 1, .box_h = 9, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 159, .adv_w = 112, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 112, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 173, .adv_w = 112, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 182, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 198, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 207, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 223, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 253, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 261, .adv_w = 112, .box_w = 1, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 263, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 278, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 285, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 293, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 112, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 326, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 334, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 342, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 358, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 367, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 376, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 385, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 394, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 402, .adv_w = 112, .box_w = 4, .box_h = 13, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 409, .adv_w = 112, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 417, .adv_w = 112, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 424, .adv_w = 112, .box_w = 5, .box_h = 3, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 426, .adv_w = 112, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 427, .adv_w = 112, .box_w = 3, .box_h = 3, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 429, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 434, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 441, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 447, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 454, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 460, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 468, .adv_w = 112, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 475, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 482, .adv_w = 112, .box_w = 1, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 484, .adv_w = 112, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 490, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 112, .box_w = 1, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 499, .adv_w = 112, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 506, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 511, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 517, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 523, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 529, .adv_w = 112, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 533, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 538, .adv_w = 112, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 545, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 550, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 556, .adv_w = 112, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 563, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 569, .adv_w = 112, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 576, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 581, .adv_w = 112, .box_w = 3, .box_h = 13, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 586, .adv_w = 112, .box_w = 1, .box_h = 15, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 588, .adv_w = 112, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 593, .adv_w = 112, .box_w = 5, .box_h = 3, .ofs_x = 1, .ofs_y = 10}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
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
    .cmap_num = 1,
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
const lv_font_t ui_font_musicMode14 = {
#else
lv_font_t ui_font_musicMode14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
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



#endif /*#if UI_FONT_MUSICMODE14*/

