/*
  C-file generated by �C/GUI-BitmapConvert V2.30c, compiled Jul 23 2002, 12:06:33

  (c) 2002  Micrium, Inc.
  www.micrium.com

  (c) 1998-2002  Segger
  Microcontroller Systeme GmbH
  www.segger.com

  Source file: box_inplace
  Dimensions:  30 * 30
  NumColors:   3
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

const GUI_COLOR Colorsbox_inplace[] = {
     0x000000,0x0000FF,0x000080
};

const GUI_LOGPALETTE Palbox_inplace = {
  3,	/* number of entries */
  0, 	/* No transparency */
  &Colorsbox_inplace[0]
};

const unsigned char acbox_inplace[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x15, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x40,
  0x15, 0x41, 0x55, 0x55, 0x55, 0x54, 0x15, 0x40,
  0x15, 0x41, 0x55, 0x55, 0x55, 0x54, 0x15, 0x40,
  0x15, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x40,
  0x10, 0x40, 0x00, 0x00, 0x00, 0x00, 0x10, 0x40,
  0x10, 0x45, 0x4A, 0xAA, 0xAA, 0x15, 0x10, 0x40,
  0x15, 0x45, 0x52, 0xAA, 0xA8, 0x55, 0x15, 0x40,
  0x15, 0x45, 0x54, 0xAA, 0xA1, 0x55, 0x15, 0x40,
  0x15, 0x41, 0x55, 0x2A, 0x85, 0x54, 0x15, 0x40,
  0x15, 0x48, 0x55, 0x4A, 0x15, 0x52, 0x15, 0x40,
  0x15, 0x4A, 0x15, 0x50, 0x55, 0x4A, 0x15, 0x40,
  0x15, 0x4A, 0x85, 0x54, 0x55, 0x2A, 0x15, 0x40,
  0x15, 0x4A, 0xA1, 0x55, 0x14, 0xAA, 0x15, 0x40,
  0x15, 0x4A, 0xA8, 0x55, 0x42, 0xAA, 0x15, 0x40,
  0x15, 0x4A, 0xA8, 0x15, 0x52, 0xAA, 0x15, 0x40,
  0x15, 0x4A, 0xA1, 0x45, 0x54, 0xAA, 0x15, 0x40,
  0x15, 0x4A, 0x85, 0x51, 0x55, 0x2A, 0x15, 0x40,
  0x15, 0x4A, 0x15, 0x50, 0x55, 0x4A, 0x15, 0x40,
  0x15, 0x48, 0x55, 0x4A, 0x15, 0x52, 0x15, 0x40,
  0x15, 0x41, 0x55, 0x2A, 0x85, 0x54, 0x15, 0x40,
  0x15, 0x45, 0x54, 0xAA, 0xA1, 0x55, 0x15, 0x40,
  0x15, 0x45, 0x52, 0xAA, 0xA8, 0x55, 0x15, 0x40,
  0x10, 0x45, 0x4A, 0xAA, 0xAA, 0x15, 0x10, 0x40,
  0x10, 0x40, 0x00, 0x00, 0x00, 0x00, 0x10, 0x40,
  0x15, 0x55, 0x55, 0x55, 0x55, 0x51, 0x55, 0x40,
  0x15, 0x41, 0x55, 0x55, 0x55, 0x54, 0x15, 0x40,
  0x15, 0x41, 0x55, 0x55, 0x55, 0x54, 0x15, 0x40,
  0x15, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x40,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const GUI_BITMAP bmbox_inplace = {
 30, /* XSize */
 30, /* YSize */
 8, /* BytesPerLine */
 2, /* BitsPerPixel */
 acbox_inplace,  /* Pointer to picture data (indices) */
 &Palbox_inplace  /* Pointer to palette */
};

/* *** End of file *** */
