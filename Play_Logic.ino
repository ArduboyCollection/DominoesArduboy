/* ----------------------------------------------------------------------------
 *  The computer will attempt to:
 *  
 *  1)  Play a domino that scores.
 *  2)  Play a domino that blocks an end of the play using a bone whose pips are 
 *      fully visible in the his hand or the 'used' boness. 
 *  3)  Play a domino that reduces the pip count thus preventing other players
 *      scoring highly. 
 *  
 */

/* ----------------------------------------------------------------------------
 *  Calculate the best score-producing hand.
 *  
 *  Iterate through the player's hand and return the best score-producing hand
 *  if one exists.  Returns the cards index (in the hand, zero-based) and the 
 *  cardinal location on the playing field to place it.
 *    
 */
void highestPossibleScore(byte player, byte *retIndex, byte *retDirection) {

  byte retValue = 0;
  byte leftPips = NOTHING;
  byte rightPips = NOTHING;
  bool isDouble = false;
    
  for (byte x = 0; x < players_hand_idx[player]; x++) {

      byte boneIdx = players_hand[player][x]; 

      leftPips = leftPips;
      rightPips = rightPips;
      isDouble = (leftPips == rightPips);
      
      switch (boardMode) {
      
        case BOARD_MODE_NO_BONES_PLAYED:
          highestPossibleScore_CenterOnly(x, leftPips, rightPips, &retValue, retIndex, retDirection);
          break;
          
        case BOARD_MODE_ONE_BONE_PLAYED:

          if (bone_c_pips_outer == leftPips)    { highestPossibleScore_East(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_c_pips_outer == rightPips)   { highestPossibleScore_East(isDouble, x, leftPips, &retValue, retIndex, retDirection); }
          if (bone_c_pips_inner == leftPips)    { highestPossibleScore_West(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_c_pips_inner == rightPips)   { highestPossibleScore_West(isDouble, x, leftPips, &retValue, retIndex, retDirection); }
                    
          break;

        case BOARD_MODE_TWO_BONES_PLAYED:
          
          if (bone_c_pips_outer == leftPips)    { highestPossibleScore_Center(x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_c_pips_outer == rightPips)   { highestPossibleScore_Center(x, leftPips, &retValue, retIndex, retDirection); }
          if (bone_w_pips_outer == leftPips)    { highestPossibleScore_West(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_w_pips_outer == rightPips)   { highestPossibleScore_West(isDouble, x, leftPips, &retValue, retIndex, retDirection); }
          
          break;

      case BOARD_MODE_DOUBLE_BONE_PLAYED:

        if (bone_e != NOTHING) {                         // Center is occupied and east is played ..
          
          if (bone_e_pips_outer == leftPips) {  

            if (bone_w != NOTHING)              { highestPossibleScore_East(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
            if (bone_w == NOTHING)              { highestPossibleScore_East_CenterOnly(x, rightPips, &retValue, retIndex, retDirection); }
          
          }
          
          if (bone_e_pips_outer == rightPips) { 

            if (bone_w != NOTHING)              { highestPossibleScore_East(isDouble, x, leftPips, &retValue, retIndex, retDirection); }
            if (bone_w == NOTHING)              { highestPossibleScore_East_CenterOnly(x, leftPips, &retValue, retIndex, retDirection); }
          
          }
         
        }

        if (bone_w != NOTHING) {                         // Center is occupied and west is played ..
          
          if (bone_w_pips_outer == leftPips) { 

            if (bone_e != NOTHING)              { highestPossibleScore_West(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
            if (bone_e == NOTHING)              { highestPossibleScore_West_CenterOnly(x, rightPips, &retValue, retIndex, retDirection); }
          
          }
          
          if (bone_w_pips_outer == rightPips) { 

            if (bone_e != NOTHING)              { highestPossibleScore_West(isDouble, x, leftPips, &retValue, retIndex, retDirection); }
            if (bone_e == NOTHING)              { highestPossibleScore_West_CenterOnly(x, leftPips, &retValue, retIndex, retDirection); }
          
          }
         
        }

        if (bone_w == NOTHING && bone_e == NOTHING) {    // Center is occupied but the east and the west are empty ..

          if (bone_c_pips_outer == leftPips)    { highestPossibleScore_West_CenterOnly(x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_c_pips_outer == rightPips)   { highestPossibleScore_West_CenterOnly(x, leftPips, &retValue, retIndex, retDirection); }

        }          

        break;
    
      case BOARD_MODE_X_AXIS_PLAYED:

        if (bone_e_pips_outer == leftPips)      { highestPossibleScore_East(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
        if (bone_e_pips_outer == rightPips)     { highestPossibleScore_East(isDouble, x, leftPips, &retValue, retIndex, retDirection); }
        if (bone_w_pips_outer == leftPips)      { highestPossibleScore_West(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
        if (bone_w_pips_outer == rightPips)     { highestPossibleScore_West(isDouble, x, leftPips, &retValue, retIndex, retDirection); }

        if (bone_n != NOTHING) {                         
          
          if (bone_n_pips_outer == leftPips)    { highestPossibleScore_North(x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_n_pips_outer == rightPips)   { highestPossibleScore_North(x, leftPips, &retValue, retIndex, retDirection); }
          
        }
        else {
          
          if (bone_c_pips_outer == leftPips)    { highestPossibleScore_North(x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_c_pips_outer == rightPips)   { highestPossibleScore_North(x, leftPips, &retValue, retIndex, retDirection); }
        
        }

        if (bone_s != NOTHING) { 
          
          if (bone_s_pips_outer == leftPips)    { highestPossibleScore_South(x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_s_pips_outer == rightPips)   { highestPossibleScore_South(x, leftPips, &retValue, retIndex, retDirection); }
          
        }
        else {
          
          if (bone_c_pips_outer == leftPips)    { highestPossibleScore_North(x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_c_pips_outer == rightPips)   { highestPossibleScore_North(x, rightPips, &retValue, retIndex, retDirection); }
        
        }

        break;
     
    }

  }  

}


/* ----------------------------------------------------------------------------
 *  Calculate the best score-producing hand (North).
 *  
 *  Can the nominated bone be played in the North position?  If so, will it
 *  result in a score that is lower than all previously calculated ones ??
 *    
 */
void highestPossibleScore_North(byte boneIdx, byte pips, byte *retValue, byte *retIndex, byte *retDirection) {

  if (((bone_w_pips_outer + bone_e_pips_outer + (bone_s != NOTHING ? bone_s_pips_outer : 0) + (bone_n != NOTHING ? bone_n_pips_outer : 0) + pips)) % 5 == 0 && 
      (bone_w_pips_outer + bone_e_pips_outer + (bone_s != NOTHING ? bone_s_pips_outer : 0) + (bone_n != NOTHING ? bone_n_pips_outer : 0) + pips) > *retValue) { 
    *retValue = (bone_w_pips_outer + bone_e_pips_outer + (bone_n != NOTHING ? bone_n_pips_outer : 0) + pips); 
    *retDirection = NORTH;
    *retIndex = boneIdx;
  }

}


/* ----------------------------------------------------------------------------
 *  Calculate the best score-producing hand (South).
 *  
 *  Can the nominated bone be played in the South position?  If so, will it
 *  result in a score that is lower than all previously calculated ones ??
 *    
 */
void highestPossibleScore_South(byte boneIdx, byte pips, byte *retValue, byte *retIndex, byte *retDirection) {

  if ((bone_w_pips_outer + bone_e_pips_outer + (bone_n != NOTHING ? bone_n_pips_outer : 0) + pips) % 5 == 0 && 
      (bone_w_pips_outer + bone_e_pips_outer + (bone_n != NOTHING ? bone_n_pips_outer : 0) + pips) > *retValue) {  
    *retValue = (bone_w_pips_outer + bone_e_pips_outer + (bone_n != NOTHING ? bone_n_pips_outer : 0) + pips); 
    *retDirection = SOUTH;
    *retIndex = boneIdx;
  }

}


/* ----------------------------------------------------------------------------
 *  Calculate the best score-producing hand (Center).
 *  
 *  Can the nominated bone be played in the Center position?  If so, will it
 *  result in a score that is lower than all previously calculated ones ??
 *    
 */
void highestPossibleScore_Center(byte boneIdx, byte pips, byte *retValue, byte *retIndex, byte *retDirection) {

  if ((bone_w_pips_outer + bone_e_pips_outer + (bone_n != NOTHING ? bone_n_pips_outer : 0) + pips) % 5 == 0 && 
      (bone_w_pips_outer + bone_e_pips_outer + (bone_n != NOTHING ? bone_n_pips_outer : 0) + pips) > *retValue) {  
    *retValue = (bone_w_pips_outer + bone_e_pips_outer + (bone_n != NOTHING ? bone_n_pips_outer : 0) + pips); 
    *retDirection = SOUTH;
    *retIndex = boneIdx;
  }

}


/* ----------------------------------------------------------------------------
 *  Calculate the best score-producing hand (Center Only).
 *  
 *  Can the nominated bone be played in the West position against the centre 
 *  bone? If so, will it result in a score that is lower than all previously 
 *  calculated ones ??  
 *    
 */
void highestPossibleScore_CenterOnly(byte boneIdx, byte leftPips, byte rightPips, byte *retValue, byte *retIndex, byte *retDirection) {

  if ((leftPips + rightPips) % 5 == 0 && (leftPips + rightPips) > *retValue) { 
    *retValue = (leftPips + rightPips); 
    *retDirection = CENTER;
    *retIndex = boneIdx;
  }

}


/* ----------------------------------------------------------------------------
 *  Calculate the best score-producing hand (West).
 *  
 *  Can the nominated bone be played in the West position?  If so, will it
 *  result in a score that is lower than all previously calculated ones ??
 *    
 */
void highestPossibleScore_West(boolean isDouble, byte boneIdx, byte pips, byte *retValue, byte *retIndex, byte *retDirection) {

  switch (boardMode) {
  
    case BOARD_MODE_ONE_BONE_PLAYED:

      if ((bone_c_pips_outer + (pips * (isDouble ? 2 : 1))) % 5 == 0 && (bone_c_pips_outer + (pips * (isDouble ? 2 : 1))) > *retValue) { 
        *retValue = (bone_c_pips_outer + (pips * (isDouble ? 2 : 1))); 
        *retDirection = WEST;
        *retIndex = boneIdx;
      }
      
      break;
      
    case BOARD_MODE_TWO_BONES_PLAYED:
      
      if ((bone_c_pips_outer + pips) % 5 == 0 && (bone_c_pips_outer + pips) > *retValue) { 
        *retValue = (bone_c_pips_outer + pips); 
        *retDirection = WEST;
        *retIndex = boneIdx;
      }
      
      break;

    case BOARD_MODE_DOUBLE_BONE_PLAYED:
      
      if ((bone_e_pips_outer + pips) % 5 == 0 && (bone_e_pips_outer + pips) > *retValue) { 
        *retValue = (bone_e_pips_outer + pips); 
        *retDirection = WEST;
        *retIndex = boneIdx;
      }
      
      break;

    case BOARD_MODE_X_AXIS_PLAYED:

      if (((bone_n != NOTHING ? bone_n_pips_outer : 0) + (bone_s != NOTHING ? bone_s_pips_outer : 0) + bone_e_pips_outer + pips) % 5 == 0 && 
          ((bone_n != NOTHING ? bone_n_pips_outer : 0) + (bone_s != NOTHING ? bone_s_pips_outer : 0) + bone_e_pips_outer + pips) > *retValue) { 
        *retValue = ((bone_n != NOTHING ? bone_n_pips_outer : 0) + (bone_s != NOTHING ? bone_s_pips_outer : 0) + bone_e_pips_outer + pips); 
        *retDirection = WEST;
        *retIndex = boneIdx;
      }
      
      break;
      
  }
  
}


/* ----------------------------------------------------------------------------
 *  Calculate the best score-producing hand (West, Center Only).
 *  
 *  Can the nominated bone be played in the West position against the centre 
 *  bone? If so, will it result in a score that is lower than all previously 
 *  calculated ones ??  
 *    
 */
void highestPossibleScore_West_CenterOnly(byte boneIdx, byte pips, byte *retValue, byte *retIndex, byte *retDirection) {

  if ((bone_c_pips_outer + bone_c_pips_inner + pips) % 5 == 0 && (bone_c_pips_outer + bone_c_pips_inner + pips) > *retValue) { 
    *retValue = (bone_c_pips_outer + bone_c_pips_inner + pips); 
    *retDirection = WEST;
    *retIndex = boneIdx;
  }

}


/* ----------------------------------------------------------------------------
 *  Calculate the best score-producing hand (East).
 *  
 *  Can the nominated bone be played in the East position?  If so, will it
 *  result in a score that is lower than all previously calculated ones ??
 *    
 */
void highestPossibleScore_East(boolean isDouble, byte boneIdx, byte pips, byte *retValue, byte *retIndex, byte *retDirection) {

  switch (boardMode) {
  
    case BOARD_MODE_ONE_BONE_PLAYED:

      if (bone_c_pips_inner + (pips * (isDouble ? 2 : 1)) % 5 == 0 && (bone_c_pips_inner + (pips * (isDouble ? 2 : 1))) > *retValue) { 
        *retValue = (bone_c_pips_inner + (pips * (isDouble ? 2 : 1))); 
        *retDirection = EAST;
        *retIndex = boneIdx;
      }
      
      break;
      
    case BOARD_MODE_DOUBLE_BONE_PLAYED:     
  
      if ((bone_w_pips_outer + pips) % 5 == 0 && (bone_w_pips_outer + pips) > *retValue) { 
        *retValue = (bone_w_pips_outer + pips); 
        *retDirection = EAST;
        *retIndex = boneIdx;
      }
      
      break;
      
    case BOARD_MODE_X_AXIS_PLAYED:      
  
      if (((bone_n != NOTHING ? bone_n_pips_outer : 0) + (bone_s != NOTHING ? bone_s_pips_outer : 0) + bone_w_pips_outer + pips) % 5 == 0 && 
          ((bone_n != NOTHING ? bone_n_pips_outer : 0) + (bone_s != NOTHING ? bone_s_pips_outer : 0) + bone_w_pips_outer + pips) > *retValue) { 
        *retValue = ((bone_n != NOTHING ? bone_n_pips_outer : 0) + (bone_s != NOTHING ? bone_s_pips_outer : 0) + bone_w_pips_outer + pips); 
        *retDirection = EAST;
        *retIndex = boneIdx;
      }
      
      break;
      
  }
  
}


/* ----------------------------------------------------------------------------
 *  Calculate the best score-producing hand (East, Center Only).
 *  
 *  Can the nominated bone be played in the East position against the centre 
 *  bone? If so, will it result in a score that is lower than all previously 
 *  calculated ones ??  
 *    
 */
void highestPossibleScore_East_CenterOnly(byte boneIdx, byte pips, byte *retValue, byte *retIndex, byte *retDirection) {
  
  if ((bone_c_pips_outer + bone_c_pips_inner + pips) % 5 == 0 && (bone_c_pips_outer + bone_c_pips_inner + pips) > *retValue) { 
    *retValue = (bone_c_pips_outer + bone_c_pips_inner + pips); 
    *retDirection = EAST;
    *retIndex = boneIdx;
  }

}


/* ----------------------------------------------------------------------------
 *  Calculate the lowest possible score.
 *  
 *  If a scoring hand cannot be played, look for a bone that reduces the overall
 *  pip score as much as possible.  A play that results in a block is given more
 *  weight than other moves.
 *  
 */
void lowestPossibleScore(byte player, byte *retIndex, byte *retDirection) {

  byte retValue = NOTHING;

  
  // Work out which bones are in play or in the computer's hand.  These are then 
  // used to work out whether a blocking play can be made ..
  
  populateBoneCounts(PLAYER_COMPUTER);
  
  
  // Cycle through all bones in the hand ..
  
  for (byte x = 0; x < players_hand_idx[player]; x++) {

    byte boneIdx = players_hand[player][x]; 
    byte leftPips = leftPips_ByBoneId(boneIdx);
    byte rightPips = rightPips_ByBoneId(boneIdx);
    bool isDouble = (leftPips == rightPips);
    
    switch (boardMode) {
      
      case BOARD_MODE_NO_BONES_PLAYED:
        lowestPossibleScore_CenterOnly(x, leftPips, rightPips, &retValue, retIndex, retDirection);
        break;
          
      case BOARD_MODE_ONE_BONE_PLAYED:

        if (bone_c_pips_outer == leftPips)      { lowestPossibleScore_East(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
        if (bone_c_pips_outer == rightPips)     { lowestPossibleScore_East(isDouble, x, leftPips, &retValue, retIndex, retDirection); }
        if (bone_c_pips_inner == leftPips)      { lowestPossibleScore_West(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
        if (bone_c_pips_inner == rightPips)     { lowestPossibleScore_West(isDouble, x, leftPips, &retValue, retIndex, retDirection); }
          
        break;

      case BOARD_MODE_TWO_BONES_PLAYED:
         
        if (bone_c_pips_outer == leftPips)      { lowestPossibleScore_Center(x, rightPips, &retValue, retIndex, retDirection); }
        if (bone_c_pips_outer == rightPips)     { lowestPossibleScore_Center(x, leftPips, &retValue, retIndex, retDirection); }
        if (bone_w_pips_outer == leftPips)      { lowestPossibleScore_West(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
        if (bone_w_pips_outer == rightPips)     { lowestPossibleScore_West(isDouble, x, leftPips, &retValue, retIndex, retDirection); }
          
        break;
        
      case BOARD_MODE_DOUBLE_BONE_PLAYED:
       
        if (bone_e != NOTHING) { 

          if (bone_e_pips_outer == leftPips)    { lowestPossibleScore_East(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_e_pips_outer == rightPips)   { lowestPossibleScore_East(isDouble, x, leftPips, &retValue, retIndex, retDirection); }
         
        }
        else {

          if (bone_c_pips_outer == leftPips)    { lowestPossibleScore_East(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_c_pips_outer == rightPips)   { lowestPossibleScore_East(isDouble, x, leftPips, &retValue, retIndex, retDirection); }

        }

        if (bone_w != NOTHING) { 

          if (bone_w_pips_outer == leftPips)    { lowestPossibleScore_West(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_w_pips_outer == rightPips)   { lowestPossibleScore_West(isDouble, x, leftPips, &retValue, retIndex, retDirection); }
         
        }
        else {

          if (bone_c_pips_outer == leftPips)    { lowestPossibleScore_West(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_c_pips_outer == rightPips)   { lowestPossibleScore_West(isDouble, x, leftPips, &retValue, retIndex, retDirection); }

        }
        
        if (bone_w == NOTHING && bone_e == NOTHING) { // Center is occupied but the east and the west are empty ..

          if (bone_c_pips_outer == leftPips)    { lowestPossibleScore_West(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_c_pips_outer == rightPips)   { lowestPossibleScore_West(isDouble, x, leftPips, &retValue, retIndex, retDirection); }

        }          

        break;
    
      case BOARD_MODE_X_AXIS_PLAYED:
       
        if (bone_e_pips_outer == leftPips)      { lowestPossibleScore_East(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
        if (bone_e_pips_outer == rightPips)     { lowestPossibleScore_East(isDouble, x, leftPips, &retValue, retIndex, retDirection); }
        if (bone_w_pips_outer == leftPips)      { lowestPossibleScore_West(isDouble, x, rightPips, &retValue, retIndex, retDirection); }
        if (bone_w_pips_outer == rightPips)     { lowestPossibleScore_West(isDouble, x, leftPips, &retValue, retIndex, retDirection); }

        if (bone_n != NOTHING) { // North ..
         
          if (bone_n_pips_outer == leftPips)    { lowestPossibleScore_North(x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_n_pips_outer == rightPips)   { lowestPossibleScore_North(x, leftPips, &retValue, retIndex, retDirection); }
          
        }
        else {
         
          if (bone_c_pips_outer == leftPips)    { lowestPossibleScore_North(x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_c_pips_outer == rightPips)   { lowestPossibleScore_North(x, leftPips, &retValue, retIndex, retDirection); }
        
        }

        if (bone_s != NOTHING) { // South ..
          
          if (bone_s_pips_outer == leftPips)    { lowestPossibleScore_South(x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_s_pips_outer == rightPips)   { lowestPossibleScore_South(x, leftPips, &retValue, retIndex, retDirection); }
          
        }
        else {
          
          if (bone_c_pips_outer == leftPips)    { lowestPossibleScore_North(x, rightPips, &retValue, retIndex, retDirection); }
          if (bone_c_pips_outer == rightPips)   { lowestPossibleScore_North(x, leftPips, &retValue, retIndex, retDirection); }
        
        }

        break;
     
    }

  }  

}


/* ----------------------------------------------------------------------------
 *  Calculate the lowest possible score (North).
 *  
 *  Can the nominated bone be played in the North position?  If so, could it 
 *  block the other player or drive the pip count down to a value that is lower 
 *  than all previously calculated ones ??  Moves that block the other player 
 *  are preferred to non-blocking moves.
 *    
 */
void lowestPossibleScore_North(byte boneIdx, byte pips, byte *retValue, byte *retIndex, byte *retDirection) {
    
  if (canBlock(pips) || bone_w_pips_outer + bone_e_pips_outer + (bone_s != NOTHING ? bone_s_pips_outer : 0) + pips < *retValue) { 
    *retValue = canBlock(pips) ? 0 : (bone_w_pips_outer + bone_e_pips_outer + (bone_s != NOTHING ? bone_s_pips_outer : 0) + pips); 
    *retDirection = NORTH;
    *retIndex = boneIdx;
  }

}


/* ----------------------------------------------------------------------------
 *  Calculate the lowest possible score (South).
 *  
 *  Can the nominated bone be played in the South position?  If so, could it 
 *  block the other player or drive the pip count down to a value that is lower 
 *  than all previously calculated ones ??  Moves that block the other player 
 *  are preferred to non-blocking moves.
 *    
 */
void lowestPossibleScore_South(byte boneIdx, byte pips, byte *retValue, byte *retIndex, byte *retDirection) {

  if (canBlock(pips) || bone_w_pips_outer + bone_e_pips_outer + (bone_n != NOTHING ? bone_n_pips_outer : 0) + pips < *retValue) {  
    *retValue = canBlock(pips) ? 0 : (bone_w_pips_outer + bone_e_pips_outer + (bone_n != NOTHING ? bone_n_pips_outer : 0) + pips); 
    *retDirection = SOUTH;
    *retIndex = boneIdx;
  }

}


/* ----------------------------------------------------------------------------
 *  Calculate the lowest possible score (Center).
 *  
 *  Can the nominated bone be played in the Center position?  If so, could it 
 *  block the other player or drive the pip count down to a value that is lower 
 *  than all previously calculated ones ??  Moves that block the other player 
 *  are preferred to non-blocking moves.
 *    
 */
void lowestPossibleScore_Center(byte boneIdx, byte pips, byte *retValue, byte *retIndex, byte *retDirection) {

  if (canBlock(pips) || bone_w_pips_outer + pips < *retValue) { 
    *retValue = (canBlock(pips) ? 0 : bone_w_pips_outer + pips);
    *retDirection = CENTER;
    *retIndex = boneIdx;
  }
  
}


/* ----------------------------------------------------------------------------
 *  Calculate the lowest possible score (Center Only).
 *  
 *  Can the nominated bone be played in the Center position?  If so, could it 
 *  block the other player or drive the pip count down to a value that is lower 
 *  than all previously calculated ones ??  Moves that block the other player 
 *  are preferred to non-blocking moves.
 *    
 */
void lowestPossibleScore_CenterOnly(byte boneIdx, byte leftPips, byte rightPips, byte *retValue, byte *retIndex, byte *retDirection) {

  if (leftPips + rightPips < *retValue) { 
    *retValue = leftPips + rightPips;
    *retDirection = CENTER;
    *retIndex = boneIdx;
  }
  
}

/* ----------------------------------------------------------------------------
 *  Calculate the lowest possible score (West).
 *  
 *  Can the nominated bone be played in the West position?  If so, could it 
 *  block the other player or drive the pip count down to a value that is lower 
 *  than all previously calculated ones ??  Moves that block the other player 
 *  are preferred to non-blocking moves.
 *    
 */
void lowestPossibleScore_West(boolean isDouble, byte boneIdx, byte pips, byte *retValue, byte *retIndex, byte *retDirection) {

  switch (boardMode) {
    
    case BOARD_MODE_TWO_BONES_PLAYED:

      if (canBlock(pips) || bone_c_pips_outer + pips < *retValue) { 
        *retValue = (canBlock(pips) ? 0 : bone_c_pips_outer + pips);
        *retDirection = WEST;
        *retIndex = boneIdx;
      } 
        
      break;
  
    case BOARD_MODE_ONE_BONE_PLAYED:

      if (canBlock( pips) || bone_c_pips_outer + (pips * (isDouble ? 2 : 1)) < *retValue) { 
        *retValue = (canBlock(pips) ? 0 : bone_c_pips_outer + (pips * (isDouble ? 2 : 1)));
        *retDirection = WEST;
        *retIndex = boneIdx;
      }

      break;
     
    case BOARD_MODE_DOUBLE_BONE_PLAYED:

      if (canBlock(pips) || (bone_e != NOTHING ? bone_e_pips_outer : bone_c_pips_outer + bone_c_pips_inner) + pips < *retValue) { 
        *retValue = canBlock(pips) ? 0 : ((bone_e != NOTHING ? bone_e_pips_outer : bone_c_pips_outer + bone_c_pips_inner) + pips); 
        *retDirection = WEST;
        *retIndex = boneIdx;
      }

      break;

    case BOARD_MODE_X_AXIS_PLAYED:

      if (canBlock(pips) || (bone_n != NOTHING ? bone_n_pips_outer : 0) + (bone_s != NOTHING ? bone_s_pips_outer : 0) + bone_e_pips_outer + pips < *retValue) { 
        *retValue = canBlock(pips) ? 0 : ((bone_n != NOTHING ? bone_n_pips_outer : 0) + (bone_s != NOTHING ? bone_s_pips_outer : 0) + bone_e_pips_outer + pips); 
        *retDirection = WEST;
        *retIndex = boneIdx;
      }
      
      break;
        
  }

}


/* ----------------------------------------------------------------------------
 *  Calculate the lowest possible score (West, Center Only).
 *  
 *  Can the nominated bone be played in the West position?  If so, could it 
 *  block the other player or drive the pip count down to a value that is lower 
 *  than all previously calculated ones ??  Moves that block the other player 
 *  are preferred to non-blocking moves.
 *    
 */
void lowestPossibleScore_West_CenterOnly(byte boneIdx, byte pips, byte *retValue, byte *retIndex, byte *retDirection) {

  if (canBlock(pips) || bone_c_pips_inner + bone_c_pips_outer + pips < *retValue) { 
    *retValue = canBlock(pips) ? 0 : (bone_c_pips_inner + bone_c_pips_outer + pips); 
    *retDirection = WEST;
    *retIndex = boneIdx;
  }

}


/* ----------------------------------------------------------------------------
 *  Calculate the lowest possible score (East).
 *  
 *  Can the nominated bone be played in the East position?  If so, could it 
 *  block the other player or drive the pip count down to a value that is lower 
 *  than all previously calculated ones ??  Moves that block the other player 
 *  are preferred to non-blocking moves.
 *    
 */
void lowestPossibleScore_East(boolean isDouble, byte boneIdx, byte pips, byte *retValue, byte *retIndex, byte *retDirection) {

  switch (boardMode) {
    
    case BOARD_MODE_ONE_BONE_PLAYED:
      
      if (canBlock(pips) || bone_c_pips_inner + (pips * (isDouble ? 2 : 1)) < *retValue) {
        *retValue = (canBlock(pips) ? 0 : bone_c_pips_inner + (pips * (isDouble ? 2 : 1)));
        *retDirection = EAST;
        *retIndex = boneIdx;
      }
          
      break;
      
    case BOARD_MODE_DOUBLE_BONE_PLAYED:

      if (canBlock(pips) || (bone_w != NOTHING ? bone_w_pips_outer : bone_c_pips_outer + bone_c_pips_inner) + pips < *retValue) { 
        *retValue = canBlock(pips) ? 0 :((bone_w != NOTHING ? bone_w_pips_outer : bone_c_pips_outer + bone_c_pips_inner) + pips); 
        *retDirection = EAST;
        *retIndex = boneIdx;
      }
            
      break;

    case BOARD_MODE_X_AXIS_PLAYED:

      if (canBlock(pips) || (bone_n != NOTHING ? bone_n_pips_outer : 0) + (bone_s != NOTHING ? bone_s_pips_outer : 0) + bone_w_pips_outer + pips < *retValue) { 
        *retValue = canBlock(pips) ? 0 : ((bone_n != NOTHING ? bone_n_pips_outer : 0) + (bone_s != NOTHING ? bone_s_pips_outer : 0) + bone_w_pips_outer + pips); 
        *retDirection = EAST;
        *retIndex = boneIdx;
      }
      
  }
  
}


/* ----------------------------------------------------------------------------
 *  Play a bone.
 *  
 *  Play the bone at 'index' in the hand of the 'player' in cardinal location 
 *  'position'.
 *  
 */
void playBone(byte player, byte index, byte position) {


  // Update the board's end bones ..
  
  switch (position) {
      
    case CENTER:
    
      if (bone_c == NOTHING) {
        bone_c = players_hand[player][index];
        bone_c_pips_inner = leftPips_ByBoneId(players_hand[player][index]);
        bone_c_pips_outer = rightPips_ByBoneId(players_hand[player][index]);
      }
      else {
        bones_played[bones_played_idx] = bone_c;
        bones_played_idx++;
        bone_c = players_hand[player][index];
        bone_c_pips_inner = bone_c_pips_outer;
        bone_c_pips_outer = playBone_NewPipValue(bone_c_pips_inner, bone_c);
      }
      break;
        
    case NORTH:
    
      if (bone_n == NOTHING) {
        bone_n = players_hand[player][index];
        bone_n_pips_inner = bone_c_pips_outer;
        bone_n_pips_outer = playBone_NewPipValue(bone_n_pips_inner, players_hand[player][index]);
      }
      else {
        bones_played[bones_played_idx] = bone_n;
        bones_played_idx++;
        bone_n = players_hand[player][index];
        bone_n_pips_inner = bone_n_pips_outer;
        bone_n_pips_outer = playBone_NewPipValue(bone_n_pips_inner, bone_n);
      }
      break;
      
    case SOUTH:
    
      if (bone_s == NOTHING) {
        bone_s = players_hand[player][index];
        bone_s_pips_inner = bone_c_pips_outer;
        bone_s_pips_outer = playBone_NewPipValue(bone_s_pips_inner, players_hand[player][index]);
      }
      else {
        bones_played[bones_played_idx] = bone_s;
        bones_played_idx++;
        bone_s = players_hand[player][index];
        bone_s_pips_inner = bone_s_pips_outer;
        bone_s_pips_outer = playBone_NewPipValue(bone_s_pips_inner, bone_s);
      }
      break;      

    case EAST:
    
      if (bone_e == NOTHING) {
        bone_e = players_hand[player][index];
        if (bone_c == NOTHING) {
          bone_e_pips_inner = bone_e_pips_inner;
          bone_e_pips_outer = playBone_NewPipValue(bone_e_pips_inner, players_hand[player][index]);
        }
        else {
          bone_e_pips_inner = bone_c_pips_outer;
          bone_e_pips_outer = playBone_NewPipValue(bone_e_pips_inner, players_hand[player][index]);
        }
      }
      else {        
        bones_played[bones_played_idx] = bone_e;
        bones_played_idx++;
        bone_e = players_hand[player][index];
        bone_e_pips_inner = bone_e_pips_outer;
        bone_e_pips_outer = playBone_NewPipValue(bone_e_pips_inner, bone_e);
      }
      break;
      
    case WEST:

      if (bone_w == NOTHING) {
        bone_w = players_hand[player][index];
        if (bone_c == NOTHING) {
          bone_w_pips_inner = bone_w_pips_inner;
          bone_w_pips_outer = playBone_NewPipValue(bone_w_pips_inner, players_hand[player][index]);
        }
        else {
          bone_w_pips_inner = bone_c_pips_inner;
          bone_w_pips_outer = playBone_NewPipValue(bone_w_pips_inner, players_hand[player][index]);
        }
      }
      else {
        bones_played[bones_played_idx] = bone_w;
        bones_played_idx++;
        bone_w = players_hand[player][index];
        bone_w_pips_inner = bone_w_pips_outer;
        bone_w_pips_outer = playBone_NewPipValue(bone_w_pips_inner, bone_w);

      }
      break;
                  
  }
 
  
  // Shuffle the bones along in the players hand to the left ..

  for (byte x = index; x < players_hand_idx[player] - 1; x++) {
            
      players_hand[player][x] = players_hand[player][x + 1]; 
      
  }

  players_hand[player][players_hand_idx[player] - 1] = 0;
  players_hand_idx[player]--;

  

  // Update screen ..

  switch (boardMode) {
  
    case BOARD_MODE_NO_BONES_PLAYED:
      boardMode = (hasADoubleBeenPlayed(BOARD_MODE_NO_BONES_PLAYED) ? BOARD_MODE_DOUBLE_BONE_PLAYED : BOARD_MODE_ONE_BONE_PLAYED);
      break;
  
    case BOARD_MODE_ONE_BONE_PLAYED:
      boardMode = (hasADoubleBeenPlayed(BOARD_MODE_ONE_BONE_PLAYED) ? BOARD_MODE_DOUBLE_BONE_PLAYED : BOARD_MODE_TWO_BONES_PLAYED);
      break;
  
    case BOARD_MODE_TWO_BONES_PLAYED:
      boardMode = (hasADoubleBeenPlayed(BOARD_MODE_TWO_BONES_PLAYED) ? BOARD_MODE_DOUBLE_BONE_PLAYED : BOARD_MODE_TWO_BONES_PLAYED);
      break;
      
    case BOARD_MODE_DOUBLE_BONE_PLAYED:  
      boardMode = (hasXAxisBeenPlayed() ? BOARD_MODE_X_AXIS_PLAYED : BOARD_MODE_DOUBLE_BONE_PLAYED);
      break;
      
    case BOARD_MODE_X_AXIS_PLAYED:  
      break;

  }

  renderBoard(NOTHING);


  // Update score ..

  if (getPipCount() % 5 == 0 && getPipCount() != 0) {

    renderGraveyard(NOTHING, players_hand_highlight_idx);
    players_score[player] = players_score[player] + getPipCount();
    renderPlayersScore(player, players_hand_highlight_idx);
    renderPlayersHand(players_hand_highlight_idx);
  
  }
  else {
    renderGraveyard(NOTHING, players_hand_highlight_idx);
  }

}


/* ----------------------------------------------------------------------------
 *  Can the nominated bone be played in the position?
 *  
 */
boolean canPlayBoard(byte boneIdx, byte position) {

  byte leftPips = leftPips_ByBoneId( boneIdx );
  byte rightPips = rightPips_ByBoneId( boneIdx );
  
  switch (boardMode) {
  
    case BOARD_MODE_NO_BONES_PLAYED:

      return true;

    case BOARD_MODE_ONE_BONE_PLAYED:

      if (position == EAST) {
        
        if (bone_e == NOTHING && bone_c != NOTHING && ( bone_c_pips_outer == leftPips || bone_c_pips_outer == rightPips)) {
          return true;
        }
  
        if (bone_e != NOTHING && ( bone_e_pips_inner == leftPips || bone_e_pips_inner == rightPips)) {
          return true;
        }

      }
      
      if (position == WEST) {

        if (bone_w == NOTHING && bone_c != NOTHING && ( bone_c_pips_inner == leftPips || bone_c_pips_inner == rightPips)) {
          return true;
        }

        if (bone_w != NOTHING && ( bone_w_pips_outer == leftPips || bone_w_pips_outer == rightPips)) {
          return true;
        }
            
      }
      
      if (position == CENTER) {
          
        if (bone_c_pips_outer == NOTHING || bone_c_pips_outer == leftPips || bone_c_pips_outer == rightPips) {
          return true;
        }
      
      }
      
      break;
      
    case BOARD_MODE_TWO_BONES_PLAYED:

      if (position == WEST && (bone_w_pips_outer == leftPips || bone_w_pips_outer == rightPips)) {
        return true;
      }
    
      if (position == CENTER && (bone_c_pips_outer == leftPips || bone_c_pips_outer == rightPips)) {
        return true;
      }

      break;
      
    case BOARD_MODE_DOUBLE_BONE_PLAYED:
    
      if (position == EAST) {
        
        if (bone_e_pips_outer == NOTHING && (bone_c_pips_outer == leftPips || bone_c_pips_outer == rightPips)) {
          return true;
        }
    
        if (bone_e_pips_outer != NOTHING && (bone_e_pips_outer == leftPips || bone_e_pips_outer == rightPips)) {
          return true;
        }

      }
   
      if (position == WEST) {
    
        if (bone_w_pips_outer == NOTHING && (bone_c_pips_inner == leftPips || bone_c_pips_inner == rightPips)) {
          return true;
        }
    
        if (bone_w_pips_outer != NOTHING && (bone_w_pips_outer == leftPips || bone_w_pips_outer == rightPips)) {
          return true;
        }

      }
      
      break;

    case BOARD_MODE_X_AXIS_PLAYED:

      if (position == NORTH) {
      
        if (bone_n_pips_outer == NOTHING && (bone_c_pips_outer == leftPips || bone_c_pips_outer == rightPips)) {
          return true;
        }
    
        if (bone_n_pips_outer != NOTHING && (bone_n_pips_outer == leftPips || bone_n_pips_outer == rightPips)) {
          return true;
        }
      
      }

      if (position == SOUTH) {
      
        if (bone_s_pips_outer == NOTHING && (bone_c_pips_outer == leftPips || bone_c_pips_outer == rightPips)) {
          return true;
        }
    
        if (bone_s_pips_outer != NOTHING && (bone_s_pips_outer == leftPips || bone_s_pips_outer == rightPips)) {
          return true;
        }

      }

      if (position == EAST && (bone_e_pips_outer == leftPips || bone_e_pips_outer == rightPips)) {
        return true;
      }
    
      if (position == WEST && (bone_w_pips_outer == leftPips || bone_w_pips_outer == rightPips)) {
        return true;
      }

      break;
      
  }

  return false;
  
}

