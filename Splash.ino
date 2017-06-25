const byte PROGMEM large_bone_portrait[] = {
  23, 48,
  0xF8, 0x04, 0x02, 0xE1, 0xF1, 0xF1, 0xF1, 0xE1, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xE1, 0xF1, 0xF1, 0xF1, 0xE1, 0x02, 0x04, 0xF8,
  0xFF, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x38, 0x7C, 0x7C, 0x7C, 0x38, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0xFF,
  0xFF, 0x00, 0x00, 0x8E, 0x9F, 0x9F, 0x9F, 0x8E, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x8E, 0x9F, 0x9F, 0x9F, 0x8E, 0x00, 0x00, 0xFF,
  0xFF, 0x00, 0x00, 0x38, 0x7C, 0x7C, 0x7C, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x7C, 0x7C, 0x7C, 0x38, 0x00, 0x00, 0xFF,
  0xFF, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0xFF,
  0x0F, 0x10, 0x20, 0x43, 0x47, 0x47, 0x47, 0x43, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x43, 0x47, 0x47, 0x47, 0x43, 0x20, 0x10, 0x0F,
};

const byte PROGMEM large_bone_landscape[] = {
  47, 24,
  0xF8, 0x04, 0x02, 0x01, 0x71, 0xF9, 0xF9, 0xF9, 0x71, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFD, 0x01, 0x01, 0x01, 0x71, 0xF9, 0xF9, 0xF9, 0x71, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x71, 0xF9, 0xF9, 0xF9, 0x71, 0x02, 0x04, 0xF8,
  0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x3E, 0x3E, 0x3E, 0x1C, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x1C, 0x3E, 0x3E, 0x3E, 0x1C, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0xFF,
  0x0F, 0x10, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x47, 0x4F, 0x4F, 0x4F, 0x47, 0x40, 0x40, 0x4F, 0x40, 0x40, 0x40, 0x47, 0x4F, 0x4F, 0x4F, 0x47, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x47, 0x4F, 0x4F, 0x4F, 0x47, 0x20, 0x10, 0x0F,
};

#ifdef SOUNDS

const uint16_t starwars[] PROGMEM = {
  NOTE_C4,1200, NOTE_G4,1200, 
  NOTE_F4,250,NOTE_E4,250,NOTE_D4,250,
  NOTE_C5,1200,NOTE_G4,600,NOTE_F4,250,
  NOTE_E4,250,NOTE_D4,250,NOTE_C5,1200,NOTE_G4,600,
  NOTE_F4,250,NOTE_E4,250,NOTE_F4,250,NOTE_D4,1200,
  TONES_END
};

#endif


#define SPLASH_DELAY_BEFORE_PROMPT      20
#define SPLASH_PORTRAIT_BONE_X          1
#define SPLASH_PORTRAIT_BONE_Y          1
#define SPLASH_LANDSCAPE_BONE_X         18
#define SPLASH_LANDSCAPE_BONE_Y         36

#ifndef SOUNDS

#define SPLASH_UPPER_LINE_X             70
#define SPLASH_UPPER_LINE_X_MAX         127
#define SPLASH_UPPER_LINE_Y             8

#define SPLASH_LOWER_LINE_X             SPLASH_UPPER_LINE_X
#define SPLASH_LOWER_LINE_X_MAX         SPLASH_UPPER_LINE_X_MAX
#define SPLASH_LOWER_LINE_Y             28

#define SPLASH_HEADLINE_X               75
#define SPLASH_HEADLINE_Y               15
#define SPLASH_PROMPT_X                 79
#define SPLASH_PROMPT_Y                 45
#define SPLASH_PROMPT_CIRCLE_X          117
#define SPLASH_PROMPT_CIRCLE_Y          49
#define SPLASH_PROMPT_CIRCLE_RAD        5

#else

#define SPLASH_UPPER_LINE_X             70
#define SPLASH_UPPER_LINE_X_MAX         127
#define SPLASH_UPPER_LINE_Y             2

#define SPLASH_LOWER_LINE_X             SPLASH_UPPER_LINE_X
#define SPLASH_LOWER_LINE_X_MAX         SPLASH_UPPER_LINE_X_MAX
#define SPLASH_LOWER_LINE_Y             22

#define SPLASH_HEADLINE_X               75
#define SPLASH_HEADLINE_Y               9
#define SPLASH_PROMPT_X                 78
#define SPLASH_PROMPT_Y                 36
#define SPLASH_PROMPT_CIRCLE_X          118
#define SPLASH_PROMPT_CIRCLE_Y          39
#define SPLASH_PROMPT_CIRCLE_RAD        5

#define SPLASH_SOUND_PROMPT_X           94
#define SPLASH_SOUND_PROMPT_Y           52
#define SPLASH_SOUND_PROMPT_CIRCLE_X    83
#define SPLASH_SOUND_PROMPT_CIRCLE_Y    55
#define SPLASH_SOUND_PROMPT_CIRCLE_RAD  5

#endif


/* ----------------------------------------------------------------------------
 *  Handle the splash screen.
 *  
 *  The splash screen allows the user names to be entered via an on-screen 
 *  keyboard.  Names are limited in length to PLAYER_NAME_MAX_LENGTH characters 
 *  to conserve memory and real estate.
 *  
 */
void drawSplash_Loop() {

  int delayVal = 0;

  
  // Reset the scores ..
  memset(players_score, 0, (sizeof(players_score) / sizeof(players_score[0])));


  // Clear the screen and render the splash ..
  
  arduboy.clear();
  sprites.drawOverwrite(SPLASH_PORTRAIT_BONE_X, SPLASH_PORTRAIT_BONE_Y, large_bone_portrait, frame);
  sprites.drawOverwrite(SPLASH_LANDSCAPE_BONE_X, SPLASH_LANDSCAPE_BONE_Y, large_bone_landscape, frame);

  drawHorizontalDottedLine(SPLASH_UPPER_LINE_X, SPLASH_UPPER_LINE_X_MAX, SPLASH_UPPER_LINE_Y);
  drawHorizontalDottedLine(SPLASH_LOWER_LINE_X, SPLASH_LOWER_LINE_X_MAX, SPLASH_LOWER_LINE_Y);

  arduboy.setCursor(SPLASH_HEADLINE_X, SPLASH_HEADLINE_Y);
  arduboy.print("Dominoes");
  arduboy.display();


#ifdef SOUNDS  // Play welcome tune ..
  
  sound.tones(starwars);

#endif


#ifdef ANIMATIONS

  DelayOrButtonPress(SPLASH_DELAY_BEFORE_PROMPT);

#endif

#ifndef SOUNDS

  // Render 'Press A' prompt ..
  
  arduboy.setCursor(SPLASH_PROMPT_X, SPLASH_PROMPT_Y);
  arduboy.print("Press");
  arduboy.fillCircle(SPLASH_PROMPT_CIRCLE_X, SPLASH_PROMPT_CIRCLE_Y, SPLASH_PROMPT_CIRCLE_RAD, WHITE);
  
  arduboy.setCursor(SPLASH_PROMPT_X + 36, SPLASH_PROMPT_Y);
  arduboy.setTextColor(BLACK);
  arduboy.setTextBackground(WHITE);
  arduboy.print("A");

  arduboy.setTextColor(WHITE);
  arduboy.setTextBackground(BLACK);

#endif


#ifdef SOUNDS


  // Render 'Press A' prompt ..
  
  arduboy.setCursor(SPLASH_PROMPT_X, SPLASH_PROMPT_Y);
  arduboy.print("Press");
  arduboy.fillCircle(SPLASH_PROMPT_CIRCLE_X, SPLASH_PROMPT_CIRCLE_Y, SPLASH_PROMPT_CIRCLE_RAD, WHITE);
  
  arduboy.setCursor(SPLASH_PROMPT_CIRCLE_X - 2, SPLASH_PROMPT_Y);
  arduboy.setTextColor(BLACK);
  arduboy.setTextBackground(WHITE);
  arduboy.print("A");

  arduboy.setTextColor(WHITE);
  arduboy.setTextBackground(BLACK);

  
  // Render 'B Sounds' prompt ..
  
  arduboy.setCursor(SPLASH_SOUND_PROMPT_X, SPLASH_SOUND_PROMPT_Y);
  arduboy.print("Sound");
  arduboy.fillCircle(SPLASH_SOUND_PROMPT_CIRCLE_X, SPLASH_SOUND_PROMPT_CIRCLE_Y, SPLASH_SOUND_PROMPT_CIRCLE_RAD, WHITE);
  
  arduboy.setCursor(SPLASH_SOUND_PROMPT_CIRCLE_X - 2, SPLASH_SOUND_PROMPT_Y);
  arduboy.setTextColor(BLACK);
  arduboy.setTextBackground(WHITE);
  arduboy.print("B");

  arduboy.setTextColor(WHITE);
  arduboy.setTextBackground(BLACK);

#endif

  
  // Wait for the player to press either A or B button ..
  
  arduboy.display();

  while (true) {

    if (arduboy.pressed(A_BUTTON)) { break; }

#ifdef SOUNDS   
    if (arduboy.pressed(B_BUTTON)) { 

      if (arduboy.audio.enabled()) {
      
        arduboy.audio.off(); 
        arduboy.fillCircle(SPLASH_SOUND_PROMPT_CIRCLE_X, SPLASH_SOUND_PROMPT_CIRCLE_Y, SPLASH_SOUND_PROMPT_CIRCLE_RAD, BLACK);
        arduboy.setCursor(SPLASH_SOUND_PROMPT_CIRCLE_X - 2, SPLASH_SOUND_PROMPT_Y);
        arduboy.setTextColor(WHITE);
        arduboy.setTextBackground(BLACK);
        arduboy.print("B");
        arduboy.drawCircle(SPLASH_SOUND_PROMPT_CIRCLE_X, SPLASH_SOUND_PROMPT_CIRCLE_Y, SPLASH_SOUND_PROMPT_CIRCLE_RAD, WHITE);

      }
      else {
      
        arduboy.audio.on(); 
        arduboy.fillCircle(SPLASH_SOUND_PROMPT_CIRCLE_X, SPLASH_SOUND_PROMPT_CIRCLE_Y, SPLASH_SOUND_PROMPT_CIRCLE_RAD, WHITE);
        arduboy.setCursor(SPLASH_SOUND_PROMPT_CIRCLE_X - 2, SPLASH_SOUND_PROMPT_Y);
        arduboy.setTextColor(BLACK);
        arduboy.setTextBackground(WHITE);
        arduboy.print("B");
        arduboy.setTextColor(WHITE);
        arduboy.setTextBackground(BLACK);
        
      }

      arduboy.display();
        
    }
#endif
    
    arduboy.delayShort(100);

#ifdef SCREENSHOTS
  //screenShot();
#endif

  }

  gameState = STATE_GAME_PLAY_GAME;
  
}
