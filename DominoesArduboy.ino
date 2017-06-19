#include "Arduboy\Arduboy2.h"

Arduboy2 arduboy;  
Sprites sprites;

#define NO_SKIP_ANIMATIONS

#define SCORE_COMPUTER_LEFT                   0
#define SCORE_COMPUTER_TOP                    0
#define SCORE_COMPUTER_WIDTH                  16
#define SCORE_COMPUTER_HEIGHT                 7

#define SCORE_PLAYER_LEFT                     SCORE_COMPUTER_LEFT
#define SCORE_PLAYER_TOP                      44
#define SCORE_PLAYER_WIDTH                    SCORE_COMPUTER_WIDTH
#define SCORE_PLAYER_HEIGHT                   SCORE_COMPUTER_HEIGHT

#define STATE_GAME_INTRO                      0
#define STATE_GAME_PLAY_GAME                  1
#define STATE_GAME_PLAY_HUMAN                 2
#define STATE_GAME_PLAY_HUMAN_HAND_SEL        3
#define STATE_GAME_PLAY_HUMAN_GRAVE_SEL       4
#define STATE_GAME_PLAY_HUMAN_BOARD_SEL       5

#define WHITE                                 1
#define BLACK                                 0

#define TABLE_COLOUR                          GREYB
#define TABLE_COLOUR_DARK                     GREYA
#define TABLE_COLOUR_OUTLINE                  GREY9

#define BONES_MAX_PIPS                        6      
#define BONES_COUNT                           28
#define BONES_INITIAL_COUNT                   7

#define PLAYER_COMPUTER                       0
#define PLAYER_HUMAN                          1

#define BONES_SMALL_X_SPACING_PORTRAIT        10
#define BONES_SMALL_Y_SPACING_PORTRAIT        18
#define BONES_SMALL_X_SPACING_LANDSCAPE       BONES_SMALL_Y_SPACING_PORTRAIT
#define BONES_SMALL_Y_SPACING_LANDSCAPE       BONES_SMALL_X_SPACING_PORTRAIT
#define BONES_SMALL_X_SPACING_HALF            5 
#define BONES_SMALL_Y_SPACING_HALF            9
#define BONES_SMALL_HEIGHT_PORTRAIT           17
#define BONES_SMALL_WIDTH_PORTRAIT            9
#define BONES_SMALL_HEIGHT_LANDSCAPE          BONES_SMALL_WIDTH_PORTRAIT
#define BONES_SMALL_WIDTH_LANDSCAPE           BONES_SMALL_HEIGHT_PORTRAIT

#define BONE_POS_X                            1
#define BONE_POS_Y                            23

#define BONE_C_POS_X_NO_BONES_PLAYED          19
#define BONE_C_POS_Y_NO_BONES_PLAYED          23

#define BONE_W_POS_X_ONE_BONE_PLAYED          1
#define BONE_C_POS_X_ONE_BONE_PLAYED          BONE_C_POS_X_NO_BONES_PLAYED
#define BONE_E_POS_X_ONE_BONE_PLAYED          37
#define BONE_W_POS_Y_ONE_BONE_PLAYED          BONE_C_POS_Y_NO_BONES_PLAYED
#define BONE_C_POS_Y_ONE_BONE_PLAYED          BONE_C_POS_Y_NO_BONES_PLAYED
#define BONE_E_POS_Y_ONE_BONE_PLAYED          BONE_C_POS_Y_NO_BONES_PLAYED

#define BONE_W_POS_X_TWO_BONES_PLAYED         9
#define BONE_C_POS_X_TWO_BONES_PLAYED         28
#define BONE_W_POS_Y_TWO_BONES_PLAYED         23 
#define BONE_C_POS_Y_TWO_BONES_PLAYED         23

#define BONE_N_POS_X_DOUBLE_BONE_PLAYED       23 
#define BONE_S_POS_X_DOUBLE_BONE_PLAYED       23
#define BONE_E_POS_X_DOUBLE_BONE_PLAYED       BONE_E_POS_X_ONE_BONE_PLAYED
#define BONE_W_POS_X_DOUBLE_BONE_PLAYED       BONE_W_POS_X_ONE_BONE_PLAYED
#define BONE_C_POS_X_DOUBLE_BONE_PLAYED       BONE_C_POS_X_ONE_BONE_PLAYED
#define BONE_N_POS_Y_DOUBLE_BONE_PLAYED       5
#define BONE_C_POS_Y_DOUBLE_BONE_PLAYED       BONE_C_POS_Y_NO_BONES_PLAYED
#define BONE_S_POS_Y_DOUBLE_BONE_PLAYED       33
#define BONE_W_POS_Y_DOUBLE_BONE_PLAYED       BONE_C_POS_Y_NO_BONES_PLAYED
#define BONE_E_POS_Y_DOUBLE_BONE_PLAYED       BONE_C_POS_Y_NO_BONES_PLAYED

#define BONE_N_POS_X_AXIS_PLAYED              BONE_N_POS_X_DOUBLE_BONE_PLAYED 
#define BONE_S_POS_X_AXIS_PLAYED              BONE_S_POS_X_DOUBLE_BONE_PLAYED
#define BONE_E_POS_X_AXIS_PLAYED              BONE_E_POS_X_DOUBLE_BONE_PLAYED
#define BONE_W_POS_X_AXIS_PLAYED              BONE_W_POS_X_DOUBLE_BONE_PLAYED
#define BONE_C_POS_X_AXIS_PLAYED              BONE_C_POS_X_DOUBLE_BONE_PLAYED
#define BONE_N_POS_Y_AXIS_PLAYED              BONE_N_POS_Y_DOUBLE_BONE_PLAYED
#define BONE_C_POS_Y_AXIS_PLAYED              BONE_C_POS_Y_DOUBLE_BONE_PLAYED
#define BONE_S_POS_Y_AXIS_PLAYED              BONE_S_POS_Y_DOUBLE_BONE_PLAYED
#define BONE_W_POS_Y_AXIS_PLAYED              BONE_W_POS_Y_DOUBLE_BONE_PLAYED
#define BONE_E_POS_Y_AXIS_PLAYED              BONE_E_POS_Y_DOUBLE_BONE_PLAYED

#define BONES_GRAVEYARD_X                     58
#define BONES_GRAVEYARD_X_MAX                 127
#define BONES_GRAVEYARD_Y                     0
#define BONES_GRAVEYARD_Y_MAX                 53
#define BONES_GRAVEYARD_BONES_PER_ROW         7
#define BONES_GRAVEYARD_BONES_ROWS            3

#define PLAYER_BOTTOM_HAND_X                  10
#define PLAYER_BOTTOM_HAND_Y                  55
#define PLAYER_HAND_MAX_VISIBLE               6
#define GAME_FIRST_TO_REACH_SCORE             100

#define PLAYER_BOTTOM_VISIBLE                 PLAYER_HAND_MAX_VISIBLE
#define PLAYER_BOTTOM_LEFT_ARROW_X            0
#define PLAYER_BOTTOM_LEFT_ARROW_Y            55
#define PLAYER_BOTTOM_LEFT_ARROW_WIDTH        5
#define PLAYER_BOTTOM_LEFT_ARROW_HEIGHT       9
#define PLAYER_BOTTOM_RIGHT_ARROW_X           122
#define PLAYER_BOTTOM_RIGHT_ARROW_Y           PLAYER_BOTTOM_LEFT_ARROW_Y
#define PLAYER_BOTTOM_RIGHT_ARROW_WIDTH       5
#define PLAYER_BOTTOM_RIGHT_ARROW_HEIGHT      9

#define CENTER                                0
#define NORTH                                 1
#define SOUTH                                 2
#define EAST                                  3
#define WEST                                  4
#define NOTHING                               255

#define BOARD_MODE_NO_BONES_PLAYED            0
#define BOARD_MODE_ONE_BONE_PLAYED            1
#define BOARD_MODE_TWO_BONES_PLAYED           2
#define BOARD_MODE_DOUBLE_BONE_PLAYED         3
#define BOARD_MODE_X_AXIS_PLAYED              4

#define MAX_X_LANDSCAPE                       128
#define MAX_Y_LANDSCAPE                       64

                                                    // The 'bones_ref' array contains an element for each bone in a standard
                                                    // 28 bone.  Arrays that represent players hands, bones available or bones
                                                    // played all contain indexes that point to this array.

                            //    0     1     2     3     4     5     6
byte bones_ref[BONES_COUNT] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
                            //    7     8     9    10    11    12  
                               0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 
                            //   13    14    15    16    17
                               0x22, 0x23, 0x24, 0x25, 0x26, 
                            //   18    19    20    21
                               0x33, 0x34, 0x35, 0x36, 
                            //   22    23    24
                               0x44, 0x45, 0x46, 
                            //   25    26
                               0x55, 0x56,
                            //   27
                               0x66};
                               
byte bones_available[BONES_COUNT] = {0};	          // Array of bones that the players can draw from. Each array value 
byte bones_available_idx = 0;                       // points to an entry in the 'bones_ref' array which contains the 
                                                    // actual bone details (left and right pip values). The next available
											                              // bone is indicated by the 'bones_available_idx' variable.

byte bones_played[BONES_COUNT] = {0};		            // Array of bones played. Again, each array value points to an entry
byte bones_played_idx = 0;                          // in the 'bones_ref' array.


byte players_hand[2][BONES_COUNT] = {0};	          // Multi-dimensional array that holds the two player's hand.  Bones 
byte players_hand_idx[2] = {0};                     // will fill the lowest positions in the array - when a bone is played
                                                    // from a hand, the bones are shuffled to the 'left' of the array.
                                                    // The 'players_hand_idx[]' indicates the number of bones in each hand.  

byte players_score[2] = {0};				                // Players score.


                                                    // When making a move, the player must select a bone from their hand
                                                    // followed by a position on the board.  Alternatively, they can select
                                                    // a tile from the graveyard to add to their hand (although in reality
                                                    // they will always  get the next tile from the 'bones_available' array.

byte players_hand_visible_idx = 0;			            // Only six player's bones are visible at one time and the player can
                                                    // scroll through these.  The 'players_hand_visible_idx' defines which
                                                    // should be displayed in the left most position on the display.
byte players_hand_highlight_idx = 0;      	        // Used to store the currently selected bone.
byte graveyard_highlight_idx = NOTHING;             // Used to store the currently selected graveyard tile.
byte board_highlighted_idx = NOTHING;               // Used to store the currently seelcted board location.  

byte boneCounts_Overall[7] = {0};         	        // Used to count how many of each bone is visible on the board.
byte boneCounts_Inhand[7] = {0};          	        // Used to count how many of each bone is visible in the players hand.

byte bone_n = NOTHING;						                  // Stores the index reference (to bones_ref) for each board position.
byte bone_s = NOTHING;
byte bone_e = NOTHING;
byte bone_w = NOTHING;
byte bone_c = NOTHING;

byte bone_n_pips_inner = NOTHING;			              // Stores the inner and outer PIP count for each board position.
byte bone_s_pips_inner = NOTHING;
byte bone_e_pips_inner = NOTHING;
byte bone_w_pips_inner = NOTHING;
byte bone_n_pips_outer = NOTHING;
byte bone_s_pips_outer = NOTHING;
byte bone_e_pips_outer = NOTHING;
byte bone_w_pips_outer = NOTHING;
byte bone_c_pips_inner = NOTHING;
byte bone_c_pips_outer = NOTHING;

byte boardMode = BOARD_MODE_NO_BONES_PLAYED;        // Stores the current mode of the board which is used to determine what
                                                    // board positions should be rendered and selectable when playing a bone.
                                                    // For example, when the boardMode is equal to 'NO_BONES_PLAYED' only the
                                                    // center tile of the board is rendered and selectable.

byte gameState = STATE_GAME_INTRO;				
byte frame = 0;


/* ----------------------------------------------------------------------------
 *  Initialise the Arduboy and get ready ..
 */
void setup() {

  arduboy.boot();
  arduboy.setFrameRate(30);
  arduboy.setTextWrap(true, BONES_GRAVEYARD_X);
  arduboy.setTextVertSpacing(7);

}


/* ----------------------------------------------------------------------------
 *  Define an array of function pointers that represent the various modes of
 *  game play.  These correspond to the STATE_GAME_ .. constants however the 
 *  playersHand_Loop handles all of the the STATE_GAME_PLAY_HUMAN variants.
 */
typedef void (*FunctionPointer) ();

const FunctionPointer PROGMEM gameLoop[] = {
  drawSplash_Loop,  
  playGame_Loop,
  computersHand_Loop,
  playersHand_Loop
};


/* ----------------------------------------------------------------------------
 *  Play dominoes !
 */
void loop() {

  if (!(arduboy.nextFrame())) return;
  
  arduboy.pollButtons();
  ((FunctionPointer)pgm_read_word(&gameLoop[gameState])) ();
      
}


/* ----------------------------------------------------------------------------
 *  Outer game loop.
 *  
 *  Game play continues until one player reaches 100 points.  
 */
void playGame_Loop() {

  while (gameState == STATE_GAME_PLAY_GAME) {

    int seed = analogRead(3);

    
    // Clear and reset the players hands, the available bones and the board ..
    
    memset(bones_available, 0, (sizeof(bones_available) / sizeof(bones_available[0])));
    memset(bones_played, 0, (sizeof(bones_played) / sizeof(bones_played[0])));

    boardMode = BOARD_MODE_NO_BONES_PLAYED;
    bones_available_idx = 0;
    bones_played_idx = 0; 
    players_hand_visible_idx = 0;
    
    memset(players_hand[0], 0, (sizeof(players_hand[0]) / sizeof(players_hand[0][0])));
    memset(players_hand_idx, 0, (sizeof(players_hand_idx) / sizeof(players_hand_idx[0])));
    
    players_hand_highlight_idx = 0;
    board_highlighted_idx = NOTHING;

    bone_n = NOTHING;
    bone_s = NOTHING;
    bone_e = NOTHING;
    bone_w = NOTHING;
    bone_c = NOTHING;

    bone_n_pips_inner = NOTHING;
    bone_s_pips_inner = NOTHING;
    bone_e_pips_inner = NOTHING;
    bone_w_pips_inner = NOTHING;
    bone_n_pips_outer = NOTHING;
    bone_s_pips_outer = NOTHING;
    bone_e_pips_outer = NOTHING;
    bone_w_pips_outer = NOTHING;
    bone_c_pips_inner = NOTHING;
    bone_c_pips_outer = NOTHING;
           

    // Shuffle and deal the bones ..
    
    randomSeed(seed);
    shuffleBones();
    dealBones();
  
    
    // Render the screen ..
    
    arduboy.clear();
    renderGraveyard(NOTHING, players_hand_highlight_idx);
    gameState = STATE_GAME_PLAY_HUMAN_HAND_SEL;
    renderBoard(NOTHING);

  }

}





