/* ----------------------------------------------------------------------------
 *  Play the computer's hand.
 *  
 */
void computersHand_Loop() {

  byte boneIdx = NOTHING;
  byte boneDirection = NOTHING;
  
  players_hand_highlight_idx = 0;
  players_hand_visible_idx = 0;
  board_highlighted_idx = NOTHING;

  while (gameState == STATE_GAME_PLAY_COMPUTER) {

    bool drawBone = false;

    
    // Can a scoring play be made ?
    
    highestPossibleScore(PLAYER_COMPUTER, &boneIdx, &boneDirection);
    
    if (boneIdx != NOTHING) {
    
      drawMessageBox_WithHourglass(players_hand[PLAYER_COMPUTER][boneIdx]);
      playBone(PLAYER_COMPUTER, boneIdx, boneDirection);
       
    }
    else {


      // If not, what move will drive the PIP count down?
    	
      lowestPossibleScore(PLAYER_COMPUTER, &boneIdx, &boneDirection);
        
      if (boneIdx != NOTHING) {

        drawMessageBox_WithHourglass(players_hand[PLAYER_COMPUTER][boneIdx]);
        playBone(PLAYER_COMPUTER, boneIdx, boneDirection);
        gameState == STATE_GAME_PLAY_HUMAN_HAND_SEL;
           
      }
      else {

    	  
        // No bones can be played so draw ..

        if (bones_available_idx > 0) {

          players_hand[PLAYER_COMPUTER][players_hand_idx[PLAYER_COMPUTER]] = bones_available[bones_available_idx];
          drawMessageBox("I will draw  a bone.", 2, false);

          players_hand_idx[PLAYER_COMPUTER] = players_hand_idx[PLAYER_COMPUTER] + 1;
          bones_available_idx--;
          renderPlayerScore(PLAYER_COMPUTER, false);
          renderGraveyard(NOTHING, NOTHING);
          drawBone = true;
        
        }
        else {  // No bones to draw so pass ..

          gameState = (canPlay(PLAYER_HUMAN) ? STATE_GAME_PLAY_COMPUTER : STATE_GAME_PLAY_GAME);

          if (gameState == STATE_GAME_PLAY_COMPUTER) {

            drawMessageBox("I cannot go. I will have to pass.", 3, true);
            gameState == STATE_GAME_PLAY_HUMAN_HAND_SEL;

          }
          else {

            drawMessageBox("No one can play. This is a draw.", 3, true);

          }

        }
        
      }
    
    }

    boneIdx = NOTHING;
    boneDirection = NOTHING;

    
    // Pass control to the human if the game is still in play or finish the game ..
    
    if (!drawBone) {

      gameState = (isAnyoneOut() ? STATE_GAME_PLAY_GAME : gameState);
      gameState = (isTheGameOver() ? STATE_GAME_INTRO : gameState);

      if (gameState == STATE_GAME_PLAY_COMPUTER) {
        gameState = (canEitherPlayerMove() ? STATE_GAME_PLAY_HUMAN_HAND_SEL: STATE_GAME_PLAY_COMPUTER);
      }
      
    }
    
    delay(100);
  
  }


  // The playersTurn variable is used to record whose turn it is between rounds ..
  
  playersTurn = PLAYER_HUMAN;

}
