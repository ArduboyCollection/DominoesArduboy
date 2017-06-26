#include "Arduboy2Ext.h"

/* SJH */
void Arduboy2Ext::setTextWrap(bool w, int16_t l, int16_t r)
{
  textWrap = w;
  cursor_wrap_leftPos = l;
  cursor_wrap_rightPos = r;
}

/* SJH */
void Arduboy2Ext::setTextWrapPositions(int16_t l, int16_t r)
{
  cursor_wrap_leftPos = l;
  cursor_wrap_rightPos = r;
}


/* SJH */
void Arduboy2Ext::setTextVertSpacing(int16_t y)
{
  vert_spacing = y;
}

Arduboy2Ext::Arduboy2Ext()
{
  cursor_wrap_leftPos = 0;              
  cursor_wrap_rightPos = WIDTH;           
  vert_spacing = DEFAULT_VERT_SPACING;      
}

size_t Arduboy2Ext::write(uint8_t c)
{
  if (c == '\n')
  {
    cursor_y += (textSize * vert_spacing);  
    cursor_x = cursor_wrap_leftPos;    
  }
  else if (c == '\r')
  {
    // skip em
  }
  else
  {
    drawChar(cursor_x, cursor_y, c, textColor, textBackground, textSize);
    cursor_x += textSize * 6;
    if (c == '\n' || textWrap && (cursor_x > (cursor_wrap_rightPos - textSize * 6))) 
    {
      // calling ourselves recursively for 'newline' is
      // 12 bytes smaller than doing the same math here
      write('\n');
    }
  }
  return 1;
}

