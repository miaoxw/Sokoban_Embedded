/*
  C-file generated by �C/GUI-BitmapConvert V2.30c, compiled Jul 23 2002, 12:06:33

  (c) 2002  Micrium, Inc.
  www.micrium.com

  (c) 1998-2002  Segger
  Microcontroller Systeme GmbH
  www.segger.com

  Source file: ground
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

const GUI_COLOR Colorsground[] = {
     0x000000,0xFFFF00,0x808000
};

const GUI_LOGPALETTE Palground = {
  3,	/* number of entries */
  0, 	/* No transparency */
  &Colorsground[0]
};

const unsigned char acground[] = {
  0x11, 0x11, 0x11, 0x11, 0x91, 0x11, 0x11, 0x10,
  0x44, 0x46, 0x44, 0x46, 0x44, 0x44, 0x46, 0x40,
  0x19, 0x99, 0x11, 0x19, 0x11, 0x11, 0x11, 0x90,
  0x44, 0x44, 0x44, 0x44, 0x44, 0x64, 0x44, 0x60,
  0x19, 0x11, 0x19, 0x11, 0x91, 0x99, 0x19, 0x90,
  0x44, 0x44, 0x44, 0x64, 0x44, 0x64, 0x44, 0x40,
  0x11, 0x19, 0x11, 0x11, 0x11, 0x99, 0x11, 0x10,
  0x44, 0x64, 0x64, 0x66, 0x44, 0x44, 0x44, 0x40,
  0x11, 0x19, 0x11, 0x99, 0x11, 0x19, 0x11, 0x10,
  0x44, 0x44, 0x44, 0x46, 0x46, 0x44, 0x44, 0x40,
  0x11, 0x11, 0x11, 0x11, 0x11, 0x91, 0x91, 0x10,
  0x44, 0x64, 0x44, 0x44, 0x44, 0x64, 0x44, 0x40,
  0x11, 0x11, 0x11, 0x91, 0x91, 0x11, 0x11, 0x90,
  0x44, 0x44, 0x44, 0x46, 0x44, 0x64, 0x44, 0x40,
  0x11, 0x11, 0x11, 0x11, 0x19, 0x99, 0x91, 0x90,
  0x44, 0x44, 0x44, 0x44, 0x64, 0x64, 0x64, 0x40,
  0x91, 0x11, 0x11, 0x91, 0x11, 0x91, 0x91, 0x10,
  0x64, 0x44, 0x44, 0x64, 0x64, 0x64, 0x64, 0x60,
  0x11, 0x19, 0x91, 0x11, 0x11, 0x11, 0x11, 0x90,
  0x64, 0x46, 0x64, 0x44, 0x66, 0x64, 0x44, 0x40,
  0x91, 0x11, 0x91, 0x91, 0x11, 0x11, 0x19, 0x90,
  0x64, 0x46, 0x44, 0x64, 0x46, 0x46, 0x46, 0x40,
  0x91, 0x19, 0x19, 0x11, 0x91, 0x91, 0x19, 0x10,
  0x44, 0x44, 0x64, 0x64, 0x44, 0x44, 0x44, 0x40,
  0x11, 0x91, 0x11, 0x99, 0x11, 0x19, 0x91, 0x10,
  0x44, 0x64, 0x44, 0x44, 0x44, 0x44, 0x44, 0x40,
  0x11, 0x11, 0x11, 0x19, 0x11, 0x11, 0x11, 0x10,
  0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x66, 0x40,
  0x99, 0x11, 0x91, 0x11, 0x11, 0x11, 0x19, 0x10,
  0x66, 0x44, 0x44, 0x44, 0x44, 0x44, 0x46, 0x60
};

const GUI_BITMAP bmground = {
 30, /* XSize */
 30, /* YSize */
 8, /* BytesPerLine */
 2, /* BitsPerPixel */
 acground,  /* Pointer to picture data (indices) */
 &Palground  /* Pointer to palette */
};

/* *** End of file *** */
