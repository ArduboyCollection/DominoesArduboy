/* ----------------------------------------------------------------------------
 *  Play the human's hand.
 *  
 */
void playersHand_Loop() {

  byte boneIdx = NOTHING;
  byte boneDirection = NOTHING;

  players_hand_highlight_idx = 0;
  players_hand_visible_idx = 0;
  renderGraveyard(NOTHING, players_hand_highlight_idx);

  while (gameState >= STATE_GAME_PLAY_HUMAN_HAND_SEL) {

    arduboy.pollButtons();

    
    // If the human cannot play a bone or draw one from the graveyard, the hand is over ..
    
    if (!canPlay(PLAYER_HUMAN) && bones_available_idx == 0) {

      gameState = (canPlay(PLAYER_COMPUTER) && !canPlay(PLAYER_HUMAN) ? gameState : STATE_GAME_PLAY_GAME);

      if (gameState >= STATE_GAME_PLAY_HUMAN_HAND_SEL) {

        delay(1000);
        drawMessageBox("You cannot play a bone. You must pass.", 3);

      }
      else {

        drawMessageBox("No one can play a bone. Its a stale-mate.", 3);

      }
      
    }

  
    // The human can play or draw so handle the actions ..
          
    if (gameState >= STATE_GAME_PLAY_HUMAN_HAND_SEL) { 

      switch (gameState) {

        case STATE_GAME_PLAY_HUMAN_HAND_SEL:
  
          if (arduboy.justPressed(LEFT_BUTTON) && players_hand_highlight_idx > 0) {
  
            players_hand_highlight_idx--;
            if (players_hand_highlight_idx < players_hand_visible_idx) {
              players_hand_visible_idx--;
            }
            renderPlayersHand(players_hand_highlight_idx);
            
          }

          if (arduboy.justPressed(RIGHT_BUTTON) && players_hand_highlight_idx < players_hand_idx[PLAYER_HUMAN] - 1) {
          
            players_hand_highlight_idx++;
            if (players_hand_highlight_idx >= players_hand_visible_idx + PLAYER_BOTTOM_VISIBLE) {
              players_hand_visible_idx++;
            }
            renderPlayersHand(players_hand_highlight_idx);
            
          }
              
          if (arduboy.justPressed(UP_BUTTON) && bones_available_idx > 0) { 

            graveyard_highlight_idx = bones_available_idx - 1;
            gameState = STATE_GAME_PLAY_HUMAN_GRAVE_SEL;
            renderGraveyard(graveyard_highlight_idx, NOTHING);
  
          }
  
          if (arduboy.justPressed(DOWN_BUTTON) && bones_available_idx > 0) { 
  
            graveyard_highlight_idx = 0;
            gameState = STATE_GAME_PLAY_HUMAN_GRAVE_SEL;
            renderGraveyard(graveyard_highlight_idx, NOTHING);
  
          }
          
          if (arduboy.justPressed(A_BUTTON)) { 

            if (!canPlayBone(players_hand[PLAYER_HUMAN][players_hand_highlight_idx])) {

              flashRedLED();
              
            }
            else {

              flashGreenLED();
             
              gameState = STATE_GAME_PLAY_HUMAN_BOARD_SEL;
              board_highlighted_idx = CENTER;
              renderBoard(board_highlighted_idx);

            }
            
          }

          break;

        case STATE_GAME_PLAY_HUMAN_GRAVE_SEL:
           
          if (arduboy.justPressed(LEFT_BUTTON) && graveyard_highlight_idx > 0) {
  
            graveyard_highlight_idx--;
            renderGraveyard(graveyard_highlight_idx, NOTHING);
            
          }

          if (arduboy.justPressed(RIGHT_BUTTON)) {

            if (graveyard_highlight_idx < bones_available_idx - 1) {

              graveyard_highlight_idx++;
              renderGraveyard(graveyard_highlight_idx, NOTHING);

            }
         
          }
           
          if (arduboy.justPressed(UP_BUTTON)) {
            
            if (graveyard_highlight_idx > BONES_GRAVEYARD_BONES_PER_ROW) {

              graveyard_highlight_idx = graveyard_highlight_idx - BONES_GRAVEYARD_BONES_PER_ROW;
              renderGraveyard(graveyard_highlight_idx, NOTHING);
              
            }
            else {

              graveyard_highlight_idx = NOTHING;
              gameState = STATE_GAME_PLAY_HUMAN_HAND_SEL;
              renderGraveyard(graveyard_highlight_idx, players_hand_highlight_idx);

            }
            
          }
           
          if (arduboy.justPressed(DOWN_BUTTON)) {
            
            if (graveyard_highlight_idx < bones_available_idx - BONES_GRAVEYARD_BONES_PER_ROW) {

              graveyard_highlight_idx = graveyard_highlight_idx + BONES_GRAVEYARD_BONES_PER_ROW;
              renderGraveyard(graveyard_highlight_idx, NOTHING);
              
            }
            else {

              graveyard_highlight_idx = NOTHING;
              gameState = STATE_GAME_PLAY_HUMAN_HAND_SEL;
              renderGraveyard(graveyard_highlight_idx, players_hand_highlight_idx);

            }
            
          }

          if (arduboy.justPressed(A_BUTTON)) {

            players_hand[PLAYER_HUMAN][players_hand_idx[PLAYER_HUMAN]] = bones_available[bones_available_idx];
            players_hand_idx[PLAYER_HUMAN] = players_hand_idx[PLAYER_HUMAN] + 1;
            bones_available_idx--;

            players_hand_highlight_idx = players_hand_idx[PLAYER_HUMAN] - 1;
            players_hand_visible_idx = (players_hand_highlight_idx >= PLAYER_BOTTOM_VISIBLE ? players_hand_highlight_idx - PLAYER_BOTTOM_VISIBLE + 1: 0);
        
            board_highlighted_idx = NOTHING;
            graveyard_highlight_idx = NOTHING;

            gameState = STATE_GAME_PLAY_HUMAN_HAND_SEL;
            renderGraveyard(NOTHING, players_hand_highlight_idx);
              
          }

          break;

        case STATE_GAME_PLAY_HUMAN_BOARD_SEL:

          if (arduboy.justPressed(LEFT_BUTTON) && board_highlighted_idx == CENTER && boardMode != BOARD_MODE_NO_BONES_PLAYED) {

            board_highlighted_idx = WEST;
            renderBoard(board_highlighted_idx);
            
          }

          if (arduboy.justPressed(LEFT_BUTTON) && board_highlighted_idx == EAST) {

            board_highlighted_idx = CENTER;
            renderBoard(board_highlighted_idx);
            
          }

          if (arduboy.justPressed(RIGHT_BUTTON) && board_highlighted_idx == CENTER && boardMode > BOARD_MODE_TWO_BONES_PLAYED) {

            board_highlighted_idx = EAST;
            renderBoard(board_highlighted_idx);
            
          }
          
          if (arduboy.justPressed(RIGHT_BUTTON) && board_highlighted_idx == WEST) {

            board_highlighted_idx = CENTER;
            renderBoard(board_highlighted_idx);
            
          }

          if (arduboy.justPressed(UP_BUTTON) && board_highlighted_idx == CENTER && boardMode == BOARD_MODE_X_AXIS_PLAYED) {

            board_highlighted_idx = NORTH;
            renderBoard(board_highlighted_idx);
            
          }

          if (arduboy.justPressed(UP_BUTTON) && board_highlighted_idx == SOUTH && boardMode == BOARD_MODE_X_AXIS_PLAYED) {

            board_highlighted_idx = CENTER;
            renderBoard(board_highlighted_idx);
            
          }

          if (arduboy.justPressed(DOWN_BUTTON) && board_highlighted_idx == CENTER && boardMode == BOARD_MODE_X_AXIS_PLAYED) {

            board_highlighted_idx = SOUTH;
            renderBoard(board_highlighted_idx);
            
          }

          if (arduboy.justPressed(DOWN_BUTTON) && board_highlighted_idx == NORTH && boardMode == BOARD_MODE_X_AXIS_PLAYED) {

            board_highlighted_idx = CENTER;
            renderBoard(board_highlighted_idx);
            
          }

          if (arduboy.justPressed(A_BUTTON)) {

            if (!canPlayBoard(players_hand[PLAYER_HUMAN][players_hand_highlight_idx], board_highlighted_idx)) {


              flashRedLED();
              
            }
            else {

              flashGreenLED();
              playBone(PLAYER_HUMAN, players_hand_highlight_idx, board_highlighted_idx);
     
              players_hand_highlight_idx = NOTHING;
              players_hand_visible_idx = 0;
              board_highlighted_idx = NOTHING;
              gameState = STATE_GAME_PLAY_HUMAN;

              renderPlayersHand(NOTHING);

            }
          
          }

          if (arduboy.justPressed(B_BUTTON)) {
          
            board_highlighted_idx = NOTHING;
            renderBoard(board_highlighted_idx);
            gameState = STATE_GAME_PLAY_HUMAN_HAND_SEL;
          
          }
          
          break;
          
      }

    }    


    // Pass control to the computer if the game is still in play or finish the game ..
      
    gameState = (isTheGameOver() ? STATE_GAME_INTRO : gameState);
    if (gameState != STATE_GAME_INTRO) {
      gameState = (isAnyoneOut() ? STATE_GAME_PLAY_GAME : gameState);
    }
    if (gameState != STATE_GAME_PLAY_GAME) {
      gameState = (canEitherPlayerMove() ? gameState : STATE_GAME_PLAY_GAME);
    }

    delay(100);
  
  }

}
