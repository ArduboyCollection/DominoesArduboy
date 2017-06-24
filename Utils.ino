/* ----------------------------------------------------------------------------
 *  Shuffle the bones ..
 *  
 */
void shuffleBones() {

	
  // Clear the bones_played array and populate the bones_available array with 
  // a sequential number between 0 and BONES_COUNT (26).
	
  for (byte x = 0; x < BONES_COUNT; x++) {
      
    bones_available[x] = x;
    bones_played[x] = 0;
            
  }
    
  
  // Randomly switch bones in the array with each other ..
  
  for (byte x = BONES_COUNT - 1; x > 0; x--) {
      
    byte y = random(x + 1);

    byte z = bones_available[y];
    bones_available[y] = bones_available[x];
    bones_available[x] = z;

  }
  
  bones_available_idx = BONES_COUNT - 1;
  bones_played_idx = 0;
   
}


/* ----------------------------------------------------------------------------
 *  Deal the bones to the players ..
 *  
 */
void dealBones() {
	
  memset(players_hand[0], 0, (sizeof(players_hand[0]) / sizeof(players_hand[0][0])));
  memset(players_hand_idx, 0, (sizeof(players_hand_idx) / sizeof(players_hand_idx[0])));
  
  for (byte x = PLAYER_COMPUTER; x <= PLAYER_HUMAN; x++) {

      for (byte y = 0; y < BONES_INITIAL_COUNT; y++) {
      
      players_hand[x][y] = bones_available[bones_available_idx];
      
      bones_available_idx--;
      players_hand_idx[x]++;
    
    }
            
  }
    
}


/* ----------------------------------------------------------------------------
 *  Get the pip count of the board ..
 *  
 */
byte getPipCount() {

  if (bone_c == NOTHING && bone_n == NOTHING && bone_s == NOTHING && bone_e == NOTHING && bone_w == NOTHING) {
      
    return NOTHING;
            
  }

  if (bone_c != NOTHING && bone_n == NOTHING && bone_s == NOTHING && bone_e == NOTHING && bone_w == NOTHING) {
      
    return bone_c_pips_inner + bone_c_pips_outer;
            
  }

  if (bone_e != NOTHING && bone_w != NOTHING) {
    
    return bone_w_pips_outer + bone_e_pips_outer + (bone_n != NOTHING ? bone_n_pips_outer : 0) + (bone_s != NOTHING ? bone_s_pips_outer : 0);
          
  }
  else {
   
    return (bone_c_pips_inner == bone_c_pips_outer ? bone_c_pips_inner + bone_c_pips_outer : bone_c_pips_outer) + (bone_w != NOTHING ? bone_w_pips_outer : 0) + (bone_e != NOTHING ? bone_e_pips_outer : 0);
          
  }
  
}


/* ----------------------------------------------------------------------------
 *  Get the left-hand pip count of the bone by value.
 *  
 *  Bone values are a literal representation of the bone represented as a two-digit
 *  number such as 13 where the 1 is the right hand pip value and 3 is the left 
 *  hand pip value.
 *  
 */
byte leftPips_ByBoneValue(byte boneValue) {

  return boneValue >> 4; 
      
}


/* ----------------------------------------------------------------------------
 *  Get the right-hand pip count of the bone by value.
 *  
 *  Bone values are a literal representation of the bone represented as a two-digit
 *  number such as 13 where the 1 is the right hand pip value and 3 is the left 
 *  hand pip value.
 *  
 */
byte rightPips_ByBoneValue(byte boneValue) {

  return boneValue & 0x0F; 
      
}


/* ----------------------------------------------------------------------------
 *  Get the left-hand pip count of the bone by id.
 *  
 *  The bone value (left and right hand pip values as a two-digit value) must 
 *  be looked up via the bones-ref array.
 *  
 */
byte leftPips_ByBoneId(byte boneId) {

  return bones_ref[boneId] >> 4; 
      
}


/* ----------------------------------------------------------------------------
 *  Get the right-hand pip count of the bone by id.
 *  
 *  The bone value (left and right hand pip values as a two-digit value) must 
 *  be looked up via the bones-ref array.
 *  
 */
byte rightPips_ByBoneId(byte boneId) {

  return bones_ref[boneId] & 0x0F; 
      
}


/* ----------------------------------------------------------------------------
 *  Calculate the board's pip value if the nominated bone is played.
 *  
 */
byte playBone_NewPipValue(byte existingBonePips, byte newBoneId) {

  if (existingBonePips == rightPips_ByBoneId(newBoneId)) {
  
    return leftPips_ByBoneId(newBoneId);
    
  }
  else {
  
    return rightPips_ByBoneId(newBoneId);
    
  }
     
} 


/* ----------------------------------------------------------------------------
 *  Have all 3 bones on the X-axis of play been played?
 *  
 */
boolean hasXAxisBeenPlayed() {

  return (bone_w != NOTHING && bone_c != NOTHING && bone_e != NOTHING);
  
}


/* ----------------------------------------------------------------------------
 *  Has a double bone been played?
 *  
 */
boolean hasADoubleBeenPlayed(byte currentMode) {
 
  // Has a double been played ?

  switch (currentMode) {
     
    case BOARD_MODE_NO_BONES_PLAYED:

      return (bone_c_pips_inner == bone_c_pips_outer);
    
    case BOARD_MODE_ONE_BONE_PLAYED:
    case BOARD_MODE_TWO_BONES_PLAYED:

      if (bone_c_pips_inner == bone_c_pips_outer) {
        return true;
      }

      if (bone_w_pips_inner == bone_w_pips_outer && bone_e == NOTHING) {
        bone_e = bone_c;
        bone_e_pips_inner = bone_c_pips_inner;
        bone_e_pips_outer = bone_c_pips_outer;
        bone_c = bone_w;
        bone_c_pips_inner = bone_w_pips_inner;
        bone_c_pips_outer = bone_w_pips_outer;
        bone_w = NOTHING;
        bone_w_pips_inner = NOTHING;
        bone_w_pips_outer = NOTHING;
        return true;
      }
      
      if (bone_e_pips_inner == bone_e_pips_outer && bone_w == NOTHING) {
        bone_w = bone_c;
        bone_w_pips_inner = bone_c_pips_outer;
        bone_w_pips_outer = bone_c_pips_inner;
        bone_c = bone_e;
        bone_c_pips_inner = bone_e_pips_inner;
        bone_c_pips_outer = bone_e_pips_outer;
        bone_e = NOTHING;
        bone_e_pips_inner = NOTHING;
        bone_e_pips_outer = NOTHING;
        return true;
      }
           
      if (bone_e_pips_inner != bone_e_pips_outer && bone_w == NOTHING) {
        bone_w = bone_c;
        bone_w_pips_outer = bone_c_pips_inner;
        bone_w_pips_inner = bone_c_pips_outer;
        bone_c = bone_e;
        bone_c_pips_inner = bone_e_pips_inner;
        bone_c_pips_outer = bone_e_pips_outer;
        bone_e = NOTHING;
        bone_e_pips_inner = NOTHING;
        bone_e_pips_outer = NOTHING;
        return false;
      }

      return false;

  }
  
  return true;
  
}


/* ----------------------------------------------------------------------------
 *  Will the nominated bone block play?
 *  
 */
boolean canBlock(byte pips) {

  return (boneCounts_Overall[pips] + boneCounts_Inhand[pips] == 7);

}


/* ----------------------------------------------------------------------------
 *  Populate bone counts.
 *  
 *  When determining whether a bone could block play, a count of each pip value
 *  (from one to six) that is visible is determined by inspecting the players 
 *  hand and the played bones.   The bone counts per pip are recorded into two
 *  arrays, boneCounts_Overall and boneCounts_Inhand.
 *  
 */
void populateBoneCounts(byte player) {


  // Clear array before processing ..
  
  memset(boneCounts_Overall, 0, sizeof(boneCounts_Overall));
  memset(boneCounts_Inhand, 0, sizeof(boneCounts_Inhand));


  // Populate bone count from players hand ..

  for (byte x = 0; x < players_hand_idx[player]; x++) {
    
    boneCounts_Inhand[leftPips_ByBoneId(players_hand[player][x])]++;
    
    if (leftPips_ByBoneId(players_hand[player][x]) != rightPips_ByBoneId(players_hand[player][x])) {
        boneCounts_Inhand[rightPips_ByBoneId(players_hand[player][x])]++;
      }
    
  }


  // Populate visible bones in grave yard ..

  for (byte x = 0; x < bones_played_idx; x++) {
    
    boneCounts_Overall[leftPips_ByBoneId(bones_played[x])]++;
    
    if (leftPips_ByBoneId(bones_played[x]) != rightPips_ByBoneId(bones_played[x])) {
      boneCounts_Overall[rightPips_ByBoneId(bones_played[x])]++;
    }
    
  }


  // Populate visible bones on board ..
  
  if (bone_c != NOTHING) {
    boneCounts_Overall[bone_c_pips_inner]++;
    if (bone_c_pips_inner != bone_c_pips_outer) { boneCounts_Overall[bone_c_pips_outer]++; }
  }

  if (bone_n != NOTHING) {
    boneCounts_Overall[bone_n_pips_inner]++;
    if (bone_n_pips_inner != bone_n_pips_outer) { boneCounts_Overall[bone_n_pips_outer]++; }
  }

  if (bone_s != NOTHING) {
    boneCounts_Overall[bone_s_pips_inner]++;
    if (bone_s_pips_inner != bone_s_pips_outer) { boneCounts_Overall[bone_s_pips_outer]++; }
  }

  if (bone_e != NOTHING) {
    boneCounts_Overall[bone_e_pips_inner]++;
    if (bone_e_pips_inner != bone_e_pips_outer) { boneCounts_Overall[bone_e_pips_outer]++; }
  }

  if (bone_w != NOTHING) {
    boneCounts_Overall[bone_w_pips_inner]++;
    if (bone_w_pips_inner != bone_w_pips_outer) { boneCounts_Overall[bone_w_pips_outer]++; }
  }

}


/* ----------------------------------------------------------------------------
 *  What is the value of the pips in a player's hand ? (rounded to nearest 5).
 *  
 */
int handValue(byte player) {

  int score = 0;
  
  for (byte x = 0; x < players_hand_idx[player]; x++) {
    score = score + leftPips_ByBoneId(players_hand[player][x]);
    score = score + rightPips_ByBoneId(players_hand[player][x]);
  }

  if (score % 5 == 0 || score % 5 == 1 || score % 5 == 2) {

    return (score / 5) * 5;

  }
  else {

    return ((score / 5) + 1) * 5;

  }

}


/* ----------------------------------------------------------------------------
 *  Can the player play a bone?
 *  
 */
boolean canPlay(byte player) {

  int score = 0;

  for (byte x = 0; x < players_hand_idx[player]; x++) {

    if (canPlayBone(players_hand[player][x])) {

        return true;
        
    }

  }

  return false;
  
}


/* ----------------------------------------------------------------------------
 *  Can the bone be played?
 *  
 */
boolean canPlayBone(byte boneId) {
 
  if (boardMode == BOARD_MODE_NO_BONES_PLAYED) {
    
      return true;

  }
  else {

    if (bone_c_pips_outer == leftPips_ByBoneId(boneId) || bone_c_pips_outer == rightPips_ByBoneId(boneId)) {
      return true;
    }
  
    if (bone_e_pips_outer == NOTHING && (bone_c_pips_outer == leftPips_ByBoneId(boneId) || bone_c_pips_outer == rightPips_ByBoneId(boneId))) 	  { return true; }  
    if (bone_e_pips_outer != NOTHING && (bone_e_pips_outer == leftPips_ByBoneId(boneId) || bone_e_pips_outer == rightPips_ByBoneId(boneId))) 	  { return true; }
    if (bone_w_pips_outer == NOTHING && (bone_c_pips_inner == leftPips_ByBoneId(boneId) || bone_c_pips_inner == rightPips_ByBoneId(boneId))) 	  { return true; }
    if (bone_w_pips_outer != NOTHING && (bone_w_pips_outer == leftPips_ByBoneId(boneId) || bone_w_pips_outer == rightPips_ByBoneId(boneId))) 	  { return true; }

    if (boardMode == BOARD_MODE_X_AXIS_PLAYED) {
  
      if (bone_n_pips_outer == NOTHING && (bone_c_pips_outer == leftPips_ByBoneId(boneId) || bone_c_pips_outer == rightPips_ByBoneId(boneId)))    { return true; }
      if (bone_n_pips_outer != NOTHING && (bone_n_pips_outer == leftPips_ByBoneId(boneId) || bone_n_pips_outer == rightPips_ByBoneId(boneId)))    { return true; }
      if (bone_s_pips_outer == NOTHING && (bone_c_pips_outer == leftPips_ByBoneId(boneId) || bone_c_pips_outer == rightPips_ByBoneId(boneId)))    { return true; }
      if (bone_s_pips_outer != NOTHING && (bone_s_pips_outer == leftPips_ByBoneId(boneId) || bone_s_pips_outer == rightPips_ByBoneId(boneId)))    { return true; }

    }
      
  }
           
  return false;

}


/* ----------------------------------------------------------------------------
 *  Can either player make a move or draw a bone?
 *  
 */
boolean canEitherPlayerMove() {
  

  // Check to see if a move exists for any player ..

  if (bones_available_idx == 0 && !canPlay(PLAYER_COMPUTER) && !canPlay(PLAYER_HUMAN)) {

    int hand0 = handValue(PLAYER_COMPUTER);
    int hand1 = handValue(PLAYER_HUMAN);

    if (hand0 == hand1) {
      
      drawMessageBox("No one can\nplay a bone.", 2, true);
      return false;
    }

    if (hand0 > hand1) {
      
      players_score[PLAYER_HUMAN] = hand0 - hand1;
      drawMessageBox("No one can\nplay a bone.", 2, true, PLAYER_HUMAN);
      return false;         

    }

    if (hand0 < hand1) {
      
      players_score[PLAYER_COMPUTER] = hand1 - hand0;
      drawMessageBox("No one can\nplay a bone.", 2, true, PLAYER_COMPUTER);
      return false;         

    }

  }

  return true;
  
 }



/* ----------------------------------------------------------------------------
 *  Flash the red LED.
 *  
 */
void flashRedLED() {

  arduboy.digitalWriteRGB(RED_LED, RGB_ON);
  arduboy.delayShort(100);
  arduboy.digitalWriteRGB(RED_LED, RGB_OFF);

}


/* ----------------------------------------------------------------------------
 *  Flash the green LED.
 *  
 */
void flashGreenLED() {
 
  arduboy.digitalWriteRGB(GREEN_LED, RGB_ON);
  arduboy.delayShort(100);
  arduboy.digitalWriteRGB(GREEN_LED, RGB_OFF);

}


/* ----------------------------------------------------------------------------
 *  Delay before proceeding.  If the user clicks the A or B button, then abort. 
 *  
 */
void DelayOrButtonPress(byte delayVal) {

  int delayCnt = 0;
  
  while (delayCnt < delayVal) {
    if (arduboy.pressed(A_BUTTON) || arduboy.pressed(B_BUTTON)) { break; }
    arduboy.delayShort(100);
    delayCnt++;
  }

}



/* ----------------------------------------------------------------------------
 *  Wait for a button press. 
 *  
 */
void WaitForButtonPress() {
  
  while (true) {
    if (arduboy.pressed(A_BUTTON) || arduboy.pressed(B_BUTTON)) { break; }
    arduboy.delayShort(100);
  }

}


/* ----------------------------------------------------------------------------
 *  Draw a horizontal dotted line. 
 *  
 *  So much nicer than a solid line!
 *  
 */
void drawHorizontalDottedLine(int x1, int x2, int y) {

  for (int x3 = x1; x3 <= x2; x3+=2) {
    arduboy.drawPixel(x3, y, WHITE);
  }
  
}


/* ----------------------------------------------------------------------------
 *  Is the game over yet?
 *  
 */
boolean isTheGameOver() {

  if (players_score[PLAYER_COMPUTER] > GAME_FIRST_TO_REACH_SCORE || players_score[PLAYER_HUMAN] > GAME_FIRST_TO_REACH_SCORE) {

    if (players_score[PLAYER_COMPUTER] > GAME_FIRST_TO_REACH_SCORE) {
      
      drawMessageBox("\n  I won !", 3, true);

    }
    else {
      
      drawMessageBox("\n You won !", 3, true);

    }

    DelayOrButtonPress(200);
    return true;

  }
  else {
    
    return false;
    
  }

}


/* ----------------------------------------------------------------------------
 *  Has either player played all their bones?
 *  
 */
boolean isAnyoneOut() {


  // Game still in play?

  for (byte x = PLAYER_COMPUTER; x <= PLAYER_HUMAN; x++) {


    // Has the player run out of bones?
    
    if (players_hand_idx[x] == 0) {

      if (x == PLAYER_COMPUTER) {

        renderPlayersHand(players_hand_highlight_idx);

        players_score[PLAYER_COMPUTER] = players_score[PLAYER_COMPUTER] + handValue(1);
        //              1234567890A1234567890A1234567890A
        drawMessageBox("I have used up all my   bones.", 3, true, PLAYER_COMPUTER);
        gameState = STATE_GAME_PLAY_GAME;
        return true;

      }

      if (x == PLAYER_HUMAN) {

        renderPlayersHand(players_hand_highlight_idx);

        players_score[PLAYER_HUMAN] = players_score[PLAYER_HUMAN] + handValue(PLAYER_COMPUTER);
        //              1234567890A1234567890A1234567890A
        drawMessageBox("You have played all ofyour bones.", 3, true, PLAYER_HUMAN);
        gameState = STATE_GAME_PLAY_GAME;
        return true;

      }
      
    }

  }

  return false;
  
}

/* ----------------------------------------------------------------------------
 *  Sends a screen shot to the programmer.
 *  
 */
#ifdef SCREENSHOTS

void screenShot() {
  Serial.write(arduboy.getBuffer(), 128 * 64 / 8);
  arduboy.delayShort(1000);
}

#endif
