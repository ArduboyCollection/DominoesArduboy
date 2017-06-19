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

  while (gameState == STATE_GAME_PLAY_HUMAN) {

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

    	  
        // No tiles can be played so draw ..

        if (bones_available_idx > 0) {

          players_hand[PLAYER_COMPUTER][players_hand_idx[PLAYER_COMPUTER]] = bones_available[bones_available_idx];
          drawMessageBox("I will draw\na bone.", 2);

          players_hand_idx[PLAYER_COMPUTER] = players_hand_idx[PLAYER_COMPUTER] + 1;
          bones_available_idx--;
          renderPlayerScore(PLAYER_COMPUTER, false);
          renderGraveyard(NOTHING, NOTHING);
          drawBone = true;
        
        }
        else {  // No tiles to draw so pass ..

          gameState = (canPlay(PLAYER_HUMAN) ? STATE_GAME_PLAY_HUMAN : STATE_GAME_PLAY_GAME);

          if (gameState == STATE_GAME_PLAY_HUMAN) {

            drawMessageBox("I cannot go\nI will have\nto pass.", 3);
            gameState == STATE_GAME_PLAY_HUMAN_HAND_SEL;

          }
          else {

            drawMessageBox("No one can\nplay. This\nis a draw.", 3);

          }

        }
        
      }
    
    }

    boneIdx = NOTHING;
    boneDirection = NOTHING;

    
    // Pass control to the human if the game is still in play or finish the game ..
    
    if (!drawBone) {
      gameState = (isTheGameOver() ? STATE_GAME_INTRO : gameState);
      if (gameState != STATE_GAME_INTRO) {
        gameState = (isAnyoneOut() ? STATE_GAME_PLAY_GAME : gameState);
      }
      if (gameState != STATE_GAME_PLAY_GAME) {
        gameState = (canEitherPlayerMove() ? STATE_GAME_PLAY_HUMAN_HAND_SEL: STATE_GAME_PLAY_HUMAN);
      }
    }
    
    delay(100);
  
  }

}
