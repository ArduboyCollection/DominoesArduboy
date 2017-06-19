const byte PROGMEM bone_portrait[] = {
  9, 17,
  0xFE, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFE,
  0xFF, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0xFF,
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
};

const byte PROGMEM bone_portrait_highlighted[] = {
  9, 17,
  0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
  0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF,
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
};

const byte PROGMEM bone_portrait_outline[] = {
  9, 17,
  0xAA, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0xAA,
  0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA,
  0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
};

const byte PROGMEM bone_portrait_outline_highlighted[] = {
  9, 17,
  0xAA, 0x01, 0x54, 0xA9, 0x54, 0xA9, 0x54, 0x01, 0xAA,
  0xAA, 0x00, 0x2A, 0x54, 0x2A, 0x54, 0x2A, 0x00, 0xAA,
  0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
};

const byte PROGMEM bone_portrait_hidden[] = {
  9, 17,
  0xFE, 0x01, 0x55, 0xA9, 0x55, 0xA9, 0x55, 0x01, 0xFE,
  0xFF, 0x00, 0x2A, 0x54, 0x2A, 0x54, 0x2A, 0x00, 0xFF,
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
};

const byte PROGMEM bone_portrait_hidden_highlight[] = {
  9, 17,
  0xFE, 0x01, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0x01, 0xFE,
  0xFF, 0x00, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x00, 0xFF,
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
};

const byte PROGMEM bone_landscape[] = {
  17, 9,
  0xFE, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x7D, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFE,
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
};

const byte PROGMEM bone_landscape_highlighted[] = {
  17, 9,
  0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
};

const byte PROGMEM bone_landscape_outline[] = {
  17, 9,
  0xAA, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0xAA,
  0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
};

const byte PROGMEM bone_landscape_outline_highlighted[] = {
  17, 9,
  0xAA, 0x01, 0x54, 0x29, 0x54, 0x29, 0x54, 0x29, 0x00, 0x55, 0x28, 0x55, 0x28, 0x55, 0x28, 0x01, 0xAA,
  0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
};

const byte PROGMEM bones_pips_0[] = {
  5, 5,
  0x00, 0x00, 0x00, 0x00, 0x00, 
};

const byte PROGMEM bones_pips_1[] = {
  5, 5,
  0x00, 0x00, 0x04, 0x00, 0x00, 
};

const byte PROGMEM bones_pips_2[] = {
  5, 5,
  0x01, 0x00, 0x00, 0x00, 0x10, 
};

const byte PROGMEM bones_pips_3[] = {
  5, 5,
  0x01, 0x00, 0x04, 0x00, 0x10, 
};

const byte PROGMEM bones_pips_4[] = {
  5, 5,
  0x11, 0x00, 0x00, 0x00, 0x11, 
};

const byte PROGMEM bones_pips_5[] = {
  5, 5,
  0x11, 0x00, 0x04, 0x00, 0x11,
};

const byte PROGMEM bones_pips_6[] = {
  5, 5,
  0x15, 0x00, 0x00, 0x00, 0x15,
};

const byte PROGMEM bones_pips_0_hghlight[] = {
  5, 7,
  0x40, 0x40, 0x40, 0x40, 0x40, 
};

const byte PROGMEM bones_pips_1_hghlight[] = {
  5, 7,
  0x40, 0x40, 0x44, 0x40, 0x40, 
};

const byte PROGMEM bones_pips_2_hghlight[] = {
  5, 7,
  0x41, 0x40, 0x40, 0x40, 0x50, 
};

const byte PROGMEM bones_pips_3_hghlight[] = {
  5, 7,
  0x41, 0x40, 0x44, 0x40, 0x50, 
};

const byte PROGMEM bones_pips_4_hghlight[] = {
  5, 7,
  0x51, 0x40, 0x40, 0x40, 0x51, 
};

const byte PROGMEM bones_pips_5_hghlight[] = {
  5, 7,
  0x51, 0x40, 0x44, 0x40, 0x51, 
};

const byte PROGMEM bones_pips_6_hghlight[] = {
  5, 7,
  0x55, 0x40, 0x40, 0x40, 0x55,
};

const byte* const bone_pips[] = {bones_pips_0, bones_pips_1, bones_pips_2, bones_pips_3, bones_pips_4, bones_pips_5, bones_pips_6};  
const byte* const bone_pips_hghlight[] = {bones_pips_0_hghlight, bones_pips_1_hghlight, bones_pips_2_hghlight, bones_pips_3_hghlight, bones_pips_4_hghlight, bones_pips_5_hghlight, bones_pips_6_hghlight};  


/* ----------------------------------------------------------------------------
 *  Draw a bone at location x, y.  
 *  
 *  This function accepts a bone value (left and righ pip value in a single hex
 *  number) and renders it without regard to orientation.  This is used when
 *  rendering the played bones in the graveyard. 
 *  
 */
void drawBone_Small(byte boneValue, int x, int y, bool highlighted) {
  
  drawBone_Small(leftPips_ByBoneValue(boneValue), rightPips_ByBoneValue(boneValue), x, y, highlighted);
  
}


/* ----------------------------------------------------------------------------
 *  Draw a bone at location x, y.  
 *  
 *  This function accepts two parameters - left / top pips and right / bottom
 *  pips and renders a bone in this orientation.  This is used when rendering
 *  the board where orientation matters. 
 *  
 */
void drawBone_Small(byte pipsTop, byte pipsBottom, int x, int y, bool highlighted) {

  if (highlighted) {
    
    sprites.drawOverwrite(x, y, bone_portrait_highlighted, frame);
    sprites.drawErase(x + 2, y + 2, bone_pips[pipsTop], frame);
    sprites.drawErase(x + 2, y + 10, bone_pips[pipsBottom], frame);
    
  }
  else {

    sprites.drawOverwrite(x, y, bone_portrait, frame);
    sprites.drawOverwrite(x + 2, y + 2, bone_pips_hghlight[pipsTop], frame);
    sprites.drawOverwrite(x + 2, y + 10, bone_pips_hghlight[pipsBottom], frame);
  
  }
  
}


/* ----------------------------------------------------------------------------
 *  Draw a bone at location x, y in the landscape orientation.  
 *  
 *  This function accepts a bone value (left and righ pip value in a single hex
 *  number) and renders it without regard to orientation.  This is used when
 *  rendering the played bones in the graveyard. 
 *  
 */
void drawBone_Rotated(byte boneValue, int x, int y, bool highlighted) {
  
  drawBone_Rotated(leftPips_ByBoneValue(boneValue), rightPips_ByBoneValue(boneValue), x, y, highlighted);
  
}


/* ----------------------------------------------------------------------------
 *  Draw a bone at location x, y in the landscape orientation.  
 *  
 *  This function accepts a bone value (left and righ pip value in a single hex
 *  number) and renders it without regard to orientation.  This is used when
 *  rendering the played bones in the graveyard. 
 *  
 */
void drawBone_Rotated(byte pipsLeft, byte pipsRight, int x, int y, bool highlighted) {

  if (highlighted) {
    
    sprites.drawOverwrite(x, y, bone_landscape_highlighted, frame);
    sprites.drawErase(x + 2, y + 2, bone_pips[pipsLeft], frame);
    sprites.drawErase(x + 10, y + 2, bone_pips[pipsRight], frame);
    
  }
  else {

    sprites.drawOverwrite(x, y, bone_landscape, frame);
    sprites.drawOverwrite(x + 2, y + 2, bone_pips_hghlight[pipsLeft], frame);
    sprites.drawOverwrite(x + 10, y + 2, bone_pips_hghlight[pipsRight], frame);
  
  }

}


/* ----------------------------------------------------------------------------
 *  Draw a bone outline only at location X, Y.
 *  
 */
void drawBone_Outline(int x, int y, bool highlighted) {

  if (highlighted) {
    
    sprites.drawOverwrite(x, y, bone_portrait_outline_highlighted, frame);
    
  }
  else {
    
    sprites.drawOverwrite(x, y, bone_portrait_outline, frame);
    
  }

}


/* ----------------------------------------------------------------------------
 *  Draw a bone outline only at location X, Y in the landscape orientation. 
 *  
 */
void drawBone_Outline_Rotated(int x, int y, bool highlighted) {

  if (highlighted) {
    
    sprites.drawOverwrite(x, y, bone_landscape_outline_highlighted, frame);
    
  }
  else {
    
    sprites.drawOverwrite(x, y, bone_landscape_outline, frame);
    
  }

}


/* ----------------------------------------------------------------------------
 *  Draw a hidden bone at location X, Y in the landscape orientation. 
 *  
 */
void drawBone_Hidden(int x, int y, bool highlighted) {

  if (highlighted) {

    sprites.drawOverwrite(x, y, bone_portrait_hidden_highlight, frame);
  
  }
  else {
    
    sprites.drawOverwrite(x, y, bone_portrait_hidden, frame);
  
  }

}
