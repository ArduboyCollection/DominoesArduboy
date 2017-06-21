const byte PROGMEM digit_0[] = {
  4, 4,
  0x1C, 0x22, 0x22, 0x1C, 
};

const byte PROGMEM digit_1[] = {
  4, 4,
  0x00, 0x24, 0x3E, 0x20, 
};

const byte PROGMEM digit_2[] = {
  4, 4,
  0x24, 0x32, 0x2A, 0x24, 
};

const byte PROGMEM digit_3[] = {
  4, 4,
  0x14, 0x22, 0x2A, 0x14, 
};

const byte PROGMEM digit_4[] = {
  4, 4,
  0x0C, 0x0A, 0x3E, 0x08, 
};

const byte PROGMEM digit_5[] = {
  4, 4,
  0x2E, 0x2A, 0x2A, 0x12, 
};

const byte PROGMEM digit_6[] = {
  4, 4,
  0x1C, 0x2A, 0x2A, 0x10, 
};

const byte PROGMEM digit_7[] = {
  4, 4,
  0x02, 0x32, 0x0A, 0x06, 
};

const byte PROGMEM digit_8[] = {
  4, 4,
  0x14, 0x2A, 0x2A, 0x14, 
};

const byte PROGMEM digit_9[] = {
  4, 4,
  0x24, 0x2A, 0x12, 0x0C, 
};

const byte PROGMEM leftArrow_Lowlight[] = {
  5, 9,
  0x10, 0x28, 0x44, 0x82, 0xFF, 
  0x00, 0x00, 0x00, 0x00, 0x01, 
};
 
const byte PROGMEM leftArrow_Highlight[] = {
  5, 9,
  0x10, 0x38, 0x7C, 0xFE, 0xFF, 
  0x00, 0x00, 0x00, 0x00, 0x01, 
};

const byte PROGMEM rightArrow_Lowlight[] = {
  5, 9,
  0xFF, 0x82, 0x44, 0x28, 0x10, 
  0x01, 0x00, 0x00, 0x00, 0x00, 
};
 
const byte PROGMEM rightArrow_Highlight[] = {
  5, 9,
  0xFF, 0xFE, 0x7C, 0x38, 0x10, 
  0x01, 0x00, 0x00, 0x00, 0x00, 
};

const byte* digits[] = {digit_0, digit_1, digit_2, digit_3, digit_4, digit_5, digit_6, digit_7, digit_8, digit_9};  


/* ----------------------------------------------------------------------------
 *  Render player's score.
 *  
 *  If ANIMATIONS is defined, flash the score three times.  Disable ANIMATIONS 
 *  to speed up testing in development mode.
 *  
 */
void renderPlayersScore(byte player, byte boneIdx) { 

  renderPlayerScore(PLAYER_COMPUTER, false);
  renderPlayerScore(PLAYER_HUMAN, false);
    
  for (byte y = 0; y < 6; y++) {

    renderPlayerScore(player, (y % 2 == 0));
    delay(250);

  }

}


/* ----------------------------------------------------------------------------
 *  Render a single player's score.
 *  
 */
void renderPlayerScore(byte player, bool highlight) {

  int player_score_0 = players_score[PLAYER_COMPUTER];
  int player_hand_bones = players_hand_idx[PLAYER_COMPUTER];
  int player_score_1 = players_score[PLAYER_HUMAN];
  
  if (player == PLAYER_COMPUTER) {

    if (!highlight) {
      
      arduboy.fillRect(SCORE_COMPUTER_LEFT, SCORE_COMPUTER_TOP, SCORE_COMPUTER_WIDTH, SCORE_COMPUTER_HEIGHT + 8, BLACK);
      sprites.drawOverwrite(SCORE_COMPUTER_LEFT + 1, SCORE_COMPUTER_TOP, digits[player_score_0 / 100], frame);
      player_score_0 = player_score_0 - (player_score_0 / 100) * 100;
      sprites.drawOverwrite(SCORE_COMPUTER_LEFT + 6, SCORE_COMPUTER_TOP, digits[player_score_0 / 10], frame);
      sprites.drawOverwrite(SCORE_COMPUTER_LEFT + 11, SCORE_COMPUTER_TOP, digits[player_score_0 % 10], frame);
      
      sprites.drawOverwrite(SCORE_COMPUTER_LEFT + 1, SCORE_COMPUTER_TOP + 8, digits[player_hand_bones / 10], frame);
      sprites.drawOverwrite(SCORE_COMPUTER_LEFT + 6, SCORE_COMPUTER_TOP + 8, digits[player_hand_bones % 10], frame);
      
    }
    else {
      
      arduboy.fillRect(SCORE_COMPUTER_LEFT, SCORE_COMPUTER_TOP, SCORE_COMPUTER_WIDTH, SCORE_COMPUTER_HEIGHT, WHITE);
      sprites.drawErase(SCORE_COMPUTER_LEFT + 1, SCORE_COMPUTER_TOP, digits[player_score_0 / 100], frame);
      player_score_0 = player_score_0 - (player_score_0 / 100) * 100;
      sprites.drawErase(SCORE_COMPUTER_LEFT + 6, SCORE_COMPUTER_TOP, digits[player_score_0 / 10], frame);
      sprites.drawErase(SCORE_COMPUTER_LEFT + 11, SCORE_COMPUTER_TOP, digits[player_score_0 % 10], frame);
      
    }
    
  }
 
  if (player == PLAYER_HUMAN) {

    if (!highlight) {
      
      arduboy.fillRect(SCORE_PLAYER_LEFT, SCORE_PLAYER_TOP, SCORE_PLAYER_WIDTH, SCORE_PLAYER_HEIGHT, BLACK);
      sprites.drawOverwrite(SCORE_PLAYER_LEFT + 1, SCORE_PLAYER_TOP, digits[player_score_1 / 100], frame);
      player_score_1 = player_score_1 - (player_score_1 / 100) * 100;
      sprites.drawOverwrite(SCORE_PLAYER_LEFT + 6, SCORE_PLAYER_TOP, digits[player_score_1 / 10], frame);
      sprites.drawOverwrite(SCORE_PLAYER_LEFT + 11, SCORE_PLAYER_TOP, digits[player_score_1 % 10], frame); 
      
    }
    else {

      arduboy.fillRect(SCORE_PLAYER_LEFT, SCORE_PLAYER_TOP, SCORE_PLAYER_WIDTH, SCORE_PLAYER_HEIGHT, WHITE);
      sprites.drawErase(SCORE_PLAYER_LEFT + 1, SCORE_PLAYER_TOP, digits[player_score_1 / 100], frame);
      player_score_1 = player_score_1 - (player_score_1 / 100) * 100;
      sprites.drawErase(SCORE_PLAYER_LEFT + 6, SCORE_PLAYER_TOP, digits[player_score_1 / 10], frame);
      sprites.drawErase(SCORE_PLAYER_LEFT + 11, SCORE_PLAYER_TOP, digits[player_score_1 % 10], frame);

    }
    
  }

  arduboy.display();

}


/* ----------------------------------------------------------------------------
 *  Render the player's hand.
 *  
 *  Only six bones can be rendered across the screen however the players hand
 *  may contain many more.  Render the bones from index 'players_hand_visible_idx'
 *  to 'players_hand_visible_idx' plus six.
 *  
 */
void renderPlayersHand(byte highlight) { 

  int x = 0;

  arduboy.fillRect(PLAYER_BOTTOM_LEFT_ARROW_X, PLAYER_BOTTOM_HAND_Y, MAX_X_LANDSCAPE, MAX_Y_LANDSCAPE, BLACK);
 
  for (byte y = players_hand_visible_idx; y < players_hand_idx[PLAYER_HUMAN]; y++) {

    drawBone_Rotated(bones_ref[players_hand[PLAYER_HUMAN][y]], PLAYER_BOTTOM_HAND_X + (x * BONES_SMALL_X_SPACING_LANDSCAPE), PLAYER_BOTTOM_HAND_Y, y == highlight);
    x++;
    if (y - players_hand_visible_idx + 1 >= PLAYER_BOTTOM_VISIBLE) break;

  }

  sprites.drawOverwrite(PLAYER_BOTTOM_LEFT_ARROW_X, PLAYER_BOTTOM_LEFT_ARROW_Y, (players_hand_visible_idx != 0 ? leftArrow_Highlight : leftArrow_Lowlight), frame);
  sprites.drawOverwrite(PLAYER_BOTTOM_RIGHT_ARROW_X, PLAYER_BOTTOM_RIGHT_ARROW_Y, ((players_hand_idx[1] - players_hand_visible_idx) > PLAYER_HAND_MAX_VISIBLE ? rightArrow_Highlight : rightArrow_Lowlight), frame);
  arduboy.display();

}


/* ----------------------------------------------------------------------------
 *  Render the graveyard.
 *  
 *  The graveyard includes available bones and those already played.  As the 
 *  bones are 17 pixels high, they overwrite the player's hand and this must
 *  be redrawn.
 *  
 *  The graveyard can only 'accommodate' 21 bones, as defined by the constants
 *  BONES_GRAVEYARD_BONES_PER_ROW and BONES_GRAVEYARD_BONES_ROWS.  Therefore
 *  rendering stops after the third row.  This gives the computer an advantage
 *  when getting towards the end of a long game as he can see every bone that
 *  has been played whereas the human may not be able to.  Tough luck!
 *  
 */
void renderGraveyard(byte highlight, byte playersHandHighlight) { 

  arduboy.fillRect(BONES_GRAVEYARD_X, BONES_GRAVEYARD_Y, BONES_GRAVEYARD_X_MAX, BONES_GRAVEYARD_Y_MAX, BLACK); 

  int x = BONES_GRAVEYARD_X;
  int y = BONES_GRAVEYARD_Y;
  int rows = 1;
  
  
  // Draw the available bones ..
  
  for (byte z = 0; z < bones_available_idx; z++) {
    
    drawBone_Hidden(x, y, z == highlight);
    x = x + BONES_SMALL_X_SPACING_PORTRAIT;
    
    if (x > (MAX_X_LANDSCAPE - BONES_SMALL_X_SPACING_PORTRAIT)) { 
      x = BONES_GRAVEYARD_X; 
      y = y + BONES_SMALL_Y_SPACING_PORTRAIT;
      rows++;
    }
    
  }

  
  // Draw the played bones ..

  for (byte z = 0; z < bones_played_idx; z++) {
    
    drawBone_Small(bones_ref[bones_played[z]], x, y, false);
    x = x + BONES_SMALL_X_SPACING_PORTRAIT;
    
    if (x > (MAX_X_LANDSCAPE - BONES_SMALL_X_SPACING_PORTRAIT)) { 
      x = BONES_GRAVEYARD_X; 
      y = y + BONES_SMALL_Y_SPACING_PORTRAIT;
      rows++;
    }
    
    
    // Do not render a fourth row as there is not enough real-estate ..
    
    if (rows >= BONES_GRAVEYARD_BONES_ROWS) { break; }
    
  }

  renderPlayersHand(playersHandHighlight);
  arduboy.display();    
  
}


/* ----------------------------------------------------------------------------
 *  Render the board.
 *  
 *  Render the playing board including played bones, available positions where
 *  bones can be played and the player's scores.  As the rendering of the board
 *  overwrites the player's hand this is also re-rendered.
 *  
 */
void renderBoard(byte highlight) {


  // Clear background ..
  
  arduboy.fillRect(0, 0, 55, 50, BLACK);
  

  // Render players scores ..
  
  renderPlayerScore(PLAYER_COMPUTER, false);
  renderPlayerScore(PLAYER_HUMAN, false);


  // Render board ..
 
  if (boardMode == BOARD_MODE_NO_BONES_PLAYED) {

      drawBone_Outline_Rotated(BONE_C_POS_X_NO_BONES_PLAYED, BONE_C_POS_Y_NO_BONES_PLAYED, highlight == CENTER);

  } else if (boardMode == BOARD_MODE_TWO_BONES_PLAYED) {

      drawBone_Rotated(bone_w_pips_outer, bone_w_pips_inner, BONE_W_POS_X_TWO_BONES_PLAYED, BONE_W_POS_Y_TWO_BONES_PLAYED, highlight == WEST);
      drawBone_Rotated(bone_c_pips_inner, bone_c_pips_outer, BONE_C_POS_X_TWO_BONES_PLAYED, BONE_C_POS_Y_TWO_BONES_PLAYED, highlight == CENTER);

  } else {
 
      if (boardMode == BOARD_MODE_X_AXIS_PLAYED){
        
        if (bone_n == NOTHING)    drawBone_Outline(BONE_N_POS_X_AXIS_PLAYED, BONE_N_POS_Y_AXIS_PLAYED, highlight == NORTH);
        if (bone_n != NOTHING)    drawBone_Small(bone_n_pips_outer, bone_n_pips_inner, BONE_N_POS_X_DOUBLE_BONE_PLAYED, BONE_N_POS_Y_DOUBLE_BONE_PLAYED, highlight == NORTH);
        
      }
      
      if (bone_w == NOTHING)      drawBone_Outline_Rotated(BONE_W_POS_X_DOUBLE_BONE_PLAYED, BONE_W_POS_Y_DOUBLE_BONE_PLAYED, highlight == WEST);
      if (bone_w != NOTHING)      drawBone_Rotated(bone_w_pips_outer, bone_w_pips_inner, BONE_W_POS_X_DOUBLE_BONE_PLAYED, BONE_W_POS_Y_DOUBLE_BONE_PLAYED, highlight == WEST);
      
      drawBone_Rotated(bone_c_pips_inner, bone_c_pips_outer, BONE_C_POS_X_DOUBLE_BONE_PLAYED, BONE_C_POS_Y_DOUBLE_BONE_PLAYED, highlight == CENTER);
      
      if (bone_e == NOTHING)      drawBone_Outline_Rotated(BONE_E_POS_X_DOUBLE_BONE_PLAYED, BONE_E_POS_Y_DOUBLE_BONE_PLAYED, highlight == EAST);
      if (bone_e != NOTHING)      drawBone_Rotated(bone_e_pips_inner, bone_e_pips_outer, BONE_E_POS_X_DOUBLE_BONE_PLAYED, BONE_E_POS_Y_DOUBLE_BONE_PLAYED, highlight == EAST);
      
      if (boardMode == BOARD_MODE_X_AXIS_PLAYED){
        
        if (bone_s == NOTHING)    drawBone_Outline(BONE_S_POS_X_AXIS_PLAYED, BONE_S_POS_Y_AXIS_PLAYED, highlight == SOUTH);
        if (bone_s != NOTHING)    drawBone_Small(bone_s_pips_inner, bone_s_pips_outer, BONE_S_POS_X_DOUBLE_BONE_PLAYED, BONE_S_POS_Y_DOUBLE_BONE_PLAYED, highlight == SOUTH);
        
      }
      
  }

  renderPlayersHand(players_hand_highlight_idx);
  arduboy.display();
  
}
