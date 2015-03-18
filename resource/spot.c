/*
  C-file generated by �C/GUI-BitmapConvert V2.30c, compiled Jul 23 2002, 12:06:33

  (c) 2002  Micrium, Inc.
  www.micrium.com

  (c) 1998-2002  Segger
  Microcontroller Systeme GmbH
  www.segger.com

  Source file: spot
  Dimensions:  30 * 30
  NumColors:   8
*/

#include "stdlib.h"

#include "GUI.H"

/*   Palette
The following are the entries of the palette table.
Every entry is a 32-bit value (of which 24 bits are actually used)
the lower   8 bits represent the Red component,
the middle  8 bits represent the Green component,
the highest 8 bits (of the 24 bits used) represent the Blue component
as follows:   0xBBGGRR
*/

const GUI_COLOR Colorsspot[] = {
     0xFF00FF,0x800000,0x808000,0xFF0000
    ,0xC0C0C0,0xFFFFFF,0x808080,0x800080
};

const GUI_LOGPALETTE Palspot = {
  8,	/* number of entries */
  0, 	/* No transparency */
  &Colorsspot[0]
};

const unsigned char acspot[] = {
  0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10,
  0x10, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x12, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x01,
  0x11, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x23, 0x21, 0x11, 0x11, 0x11, 0x11, 0x10, 0x11,
  0x11, 0x10, 0x11, 0x11, 0x11, 0x11, 0x12, 0x32, 0x32, 0x11, 0x11, 0x11, 0x11, 0x01, 0x11,
  0x11, 0x11, 0x01, 0x11, 0x11, 0x11, 0x23, 0x23, 0x23, 0x21, 0x11, 0x11, 0x10, 0x11, 0x11,
  0x11, 0x11, 0x10, 0x11, 0x11, 0x12, 0x32, 0x32, 0x32, 0x32, 0x11, 0x11, 0x01, 0x11, 0x11,
  0x11, 0x11, 0x11, 0x01, 0x11, 0x23, 0x24, 0x45, 0x46, 0x23, 0x21, 0x10, 0x11, 0x11, 0x11,
  0x11, 0x11, 0x11, 0x10, 0x12, 0x34, 0x55, 0x55, 0x54, 0x40, 0x32, 0x01, 0x11, 0x11, 0x11,
  0x11, 0x11, 0x11, 0x11, 0x06, 0x45, 0x55, 0x55, 0x54, 0x40, 0x00, 0x21, 0x11, 0x11, 0x11,
  0x11, 0x11, 0x11, 0x12, 0x35, 0x55, 0x55, 0x55, 0x54, 0x40, 0x00, 0x32, 0x11, 0x11, 0x11,
  0x11, 0x11, 0x11, 0x23, 0x55, 0x55, 0x55, 0x55, 0x55, 0x44, 0x00, 0x03, 0x21, 0x11, 0x11,
  0x11, 0x11, 0x12, 0x36, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54, 0x00, 0x07, 0x32, 0x11, 0x11,
  0x11, 0x11, 0x23, 0x24, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00, 0x23, 0x21, 0x11,
  0x11, 0x12, 0x32, 0x35, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00, 0x32, 0x32, 0x11,
  0x11, 0x23, 0x23, 0x25, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00, 0x23, 0x23, 0x21,
  0x12, 0x32, 0x32, 0x65, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00, 0x72, 0x32, 0x11,
  0x11, 0x23, 0x23, 0x25, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00, 0x23, 0x21, 0x11,
  0x11, 0x12, 0x32, 0x35, 0x55, 0x55, 0x55, 0x55, 0x55, 0x44, 0x00, 0x00, 0x32, 0x11, 0x11,
  0x11, 0x11, 0x23, 0x24, 0x55, 0x55, 0x55, 0x55, 0x55, 0x44, 0x00, 0x00, 0x21, 0x11, 0x11,
  0x11, 0x11, 0x12, 0x36, 0x55, 0x55, 0x55, 0x55, 0x44, 0x40, 0x00, 0x02, 0x11, 0x11, 0x11,
  0x11, 0x11, 0x11, 0x23, 0x45, 0x54, 0x44, 0x44, 0x44, 0x00, 0x00, 0x01, 0x11, 0x11, 0x11,
  0x11, 0x11, 0x11, 0x12, 0x04, 0x44, 0x44, 0x40, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11,
  0x11, 0x11, 0x11, 0x10, 0x23, 0x44, 0x40, 0x00, 0x00, 0x00, 0x01, 0x01, 0x11, 0x11, 0x11,
  0x11, 0x11, 0x11, 0x01, 0x12, 0x76, 0x00, 0x00, 0x00, 0x02, 0x11, 0x10, 0x11, 0x11, 0x11,
  0x11, 0x11, 0x10, 0x11, 0x11, 0x23, 0x24, 0x40, 0x44, 0x21, 0x11, 0x11, 0x01, 0x11, 0x11,
  0x11, 0x11, 0x01, 0x11, 0x11, 0x12, 0x32, 0x32, 0x32, 0x11, 0x11, 0x11, 0x10, 0x11, 0x11,
  0x11, 0x10, 0x11, 0x11, 0x11, 0x11, 0x23, 0x23, 0x21, 0x11, 0x11, 0x11, 0x11, 0x01, 0x11,
  0x11, 0x01, 0x11, 0x11, 0x11, 0x11, 0x12, 0x32, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x11,
  0x10, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x21, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x01,
  0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10
};

const GUI_BITMAP bmspot = {
 30, /* XSize */
 30, /* YSize */
 15, /* BytesPerLine */
 4, /* BitsPerPixel */
 acspot,  /* Pointer to picture data (indices) */
 &Palspot  /* Pointer to palette */
};

/* *** End of file *** */
