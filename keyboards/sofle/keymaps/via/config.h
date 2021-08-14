 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

//Add RGB underglow
//#define RGB_DI_PIN D3
//#define RGBLED_NUM 14
//#define RGBLED_SPLIT {7,7}
//#define RGBLIGHT_ANIMATIONS

#define IGNORE_MOD_TAP_INTERRUPT // this makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)
#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 1000

// Settings for using the keybaord as a mouse 30
#define MOUSEKEY_DELAY 0
// Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL 7
// Time between cursor movements
#define MOUSEKEY_MAX_SPEED  3
// Maximum cursor speed at which acceleration stops 40
#define MOUSEKEY_TIME_TO_MAX 40
// Time until maximum cursor speed is reached
#define MOUSEKEY_WHEEL_MAX_SPEED 0
// Maximum number of scroll steps per scroll action
#define MOUSEKEY_WHEEL_TIME_TO_MAX 0
// Time until maximum scroll speed is reached

//If your encoders clockwise directions are incorrect, you can swap the A & B pad definitions. They can also be flipped with a define:
#define ENCODER_DIRECTION_FLIP

//Additionally, the resolution, which defines how many pulses the encoder registers between each detent, can be defined with:
//#define ENCODER_RESOLUTION { 4, 2 }

//Enables fade out animation. Use together with OLED_TIMEOUT
#define OLED_FADE_OUT
#define OLED_TIMEOUT 60000
//Scrolls the OLED screen after 0ms of OLED inactivity. Helps reduce OLED Burn-in. Set to 0 to disable.
// #define OLED_SCROLL_TIMEOUT 1
//default 255
#define OLED_BRIGHTNESS 1

#define TAPPING_TERM_PER_KEY

#define BOOTMAGIC_KEY_SALT KC_K
#define BOOTMAGIC_KEY_EE_HANDS_LEFT KC_J
#define BOOTMAGIC_KEY_EE_HANDS_RIGHT KC_L


/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
//#define DEBUG_MATRIX_SCAN_RATE

#ifdef TAP_DANCE_ENABLE
    #define KTD_CLOS TD(TD_CLOS)
    #define KTD_SCLN TD(TD_SCLN)
    #define KTD_1 TD(TD_1)
    #define KTD_2 TD(TD_2)
    #define KTD_3 TD(TD_3)
    #define KTD_4 TD(TD_4)
    #define KTD_5 TD(TD_5)
    #define KTD_6 TD(TD_6)
    #define KTD_7 TD(TD_7)
    #define KTD_8 TD(TD_8)
    #define KTD_9 TD(TD_9)
    #define KTD_10 TD(TD_10)
    #define KTD_11 TD(TD_11)
#endif

#ifndef TAP_DANCE_ENABLE
    #define KTD_CLOS M_AF4
    #define KTD_SCLN KC_SCLN
    #define KTD_1 KC_EXLM
    #define KTD_2 KC_AT
    #define KTD_3 KC_HASH
    #define KTD_4 KC_DOLLAR
    #define KTD_5 KC_PERCENT
    #define KTD_6 KC_CIRCUMFLEX
    #define KTD_7 KC_AMPERSAND
    #define KTD_8 KC_ASTERISK
    #define KTD_9 KC_RBRC
    #define KTD_10 KC_MINS
    #define KTD_11 KC_EQL
#endif

#define _______ KC_TRNS


