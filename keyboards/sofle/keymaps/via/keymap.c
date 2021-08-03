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

#include QMK_KEYBOARD_H
#include "oled.c"

enum layer_names {
  _HOME,
  _GAME,
  _NUM,
  _NAV,
  _FN4
};

enum custom_keycodes {          // макросы
    M_ARROW = SAFE_RANGE,
    M_SLCT,
    M_AF4,
    M_1,
    M_2,
    M_3,
    M_4,
    M_5,
    M_6,
    M_7,
    M_8,
    M_SLEXT,
    M_SLSHR,
};

// ==========================Тап дэнс секция==============================
enum {              // Tap dance enums
    TD_SCLN,
    TD_1,
    TD_2,
    TD_3,
    TD_4,
    TD_5,
    TD_6,
    TD_7,
    TD_8,
    TD_9,
    TD_10,
    TD_11,
    // TD_12,
};

// Произвольные длительности нажатий, чтобы успевать кликать дважды
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_AF4:
            return 500;
        case OSM(MOD_LSFT):
            return 200;
        case TD(TD_SCLN):
            return 200;
        case TD(TD_1):
            return 200;
        case TD(TD_2):
            return 200;
        case TD(TD_3):
            return 200;
        case TD(TD_4):
            return 200;
        case TD(TD_5):
            return 200;
        case TD(TD_6):
            return 200;
        case TD(TD_7):
            return 200;
        case TD(TD_8):
            return 200;
        case TD(TD_9):
            return 200;
        case TD(TD_10):
            return 200;
        case TD(TD_11):
            return 200;
        // case TD(TD_12):
        //     return 200;
        default:
            return TAPPING_TERM;
    }
}

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(qk_tap_dance_state_t *state);
td_state_t hold_cur_dance (qk_tap_dance_state_t *state);

void register_hyper (void);
void unregister_hyper (void);

void td1_finished (qk_tap_dance_state_t *state, void *user_data);
void td1_reset (qk_tap_dance_state_t *state, void *user_data);

void td2_finished (qk_tap_dance_state_t *state, void *user_data);
void td2_reset (qk_tap_dance_state_t *state, void *user_data);

void td3_finished (qk_tap_dance_state_t *state, void *user_data);
void td3_reset (qk_tap_dance_state_t *state, void *user_data);

void td4_finished (qk_tap_dance_state_t *state, void *user_data);
void td4_reset (qk_tap_dance_state_t *state, void *user_data);

void td5_finished (qk_tap_dance_state_t *state, void *user_data);
void td5_reset (qk_tap_dance_state_t *state, void *user_data);

void td6_finished (qk_tap_dance_state_t *state, void *user_data);
void td6_reset (qk_tap_dance_state_t *state, void *user_data);

void td7_finished (qk_tap_dance_state_t *state, void *user_data);
void td7_reset (qk_tap_dance_state_t *state, void *user_data);

void td8_finished (qk_tap_dance_state_t *state, void *user_data);
void td8_reset (qk_tap_dance_state_t *state, void *user_data);

void td9_finished (qk_tap_dance_state_t *state, void *user_data);
void td9_reset (qk_tap_dance_state_t *state, void *user_data);

void td10_finished (qk_tap_dance_state_t *state, void *user_data);
void td10_reset (qk_tap_dance_state_t *state, void *user_data);

void td11_finished (qk_tap_dance_state_t *state, void *user_data);
void td11_reset (qk_tap_dance_state_t *state, void *user_data);

// void td12_finished (qk_tap_dance_state_t *state, void *user_data);
// void td12_reset (qk_tap_dance_state_t *state, void *user_data);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_HOME] = LAYOUT(
    LT(_FN4, KC_GRV),TD(TD_1),     TD(TD_2), TD(TD_3), TD(TD_4), TD(TD_5),                               TD(TD_6),  TD(TD_7), TD(TD_8),TD(TD_9),TD(TD_10),       TD(TD_11),
    C_S_T(KC_TAB),   KC_Q,         KC_W,     KC_E,     KC_R,     KC_T,                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,          C_S_T(KC_LBRC),
    LCTL_T(KC_ESC),  KC_A,         KC_S,     KC_D,     KC_F,     KC_G,                                      KC_H,    KC_J,    KC_K,    KC_L,    TD(TD_SCLN),   RCTL_T(KC_QUOT),
    OSM(MOD_LSFT),   LCA_T(KC_Z),  KC_X,     KC_C,     KC_V,     KC_B,            C(KC_X),                KC_MPLY,   KC_N,    KC_M,    KC_COMM, KC_DOT, LCA_T(KC_SLSH),KC_RSFT,
                     KC_LGUI,      KC_TRNS,  KC_LALT,  MO(_NUM), LSFT_T(KC_SPC),  LT(_NUM, KC_SPC),   LT(_NAV,KC_BSPC), RALT_T(KC_NO), LT(_FN4, KC_ENT), KC_BSLS),

	[_GAME] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,                            DM_PLY1,  DM_PLY2, DM_REC1, DM_REC2, KC_LOCK, DM_RSTP,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,                            KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,      KC_G,                            KC_H,     KC_J,    KC_K,    KC_L,    TD(TD_SCLN),    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,   KC_MUTE,      TG(_GAME), KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC,
                      KC_F9, KC_BSPC, KC_LALT,   MO(_FN4), KC_SPC,         KC_ENT,  LT(_NAV,KC_BSPC), KC_RCTL, EH_LEFT, EH_RGHT),

	[_NUM] = LAYOUT(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                              KC_F6,   KC_F7, KC_F8,   KC_F9,  KC_F10,  KC_F11,
    KC_CAPS, M_ARROW, KC_GT,   KC_RBRC, KC_RPRN,  KC_RCBR,                            KC_PCMM, KC_P7, KC_P8,   KC_P9,  KC_PAST, KC_F12,
    DM_RSTP, M_SLCT,  KC_LT,   KC_LBRC, KC_LPRN,  KC_LCBR,                            KC_PDOT, KC_P4, KC_P5,   KC_P6,  KC_P0, KC_PPLS,
    DM_REC1, DM_PLY1, A(KC_X), A(KC_C), A( KC_V), A(KC_B), KC_SLEP,         TG(_GAME),KC_TRNS, KC_P1, KC_P2,   KC_P3,  KC_PSLS, KC_PENT,
                      KC_LOCK, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,         KC_TRNS,  KC_P0,   KC_PMNS, KC_TRNS, KC_TRNS),

	[_NAV] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                             G(KC_1),    G(KC_2),    G(KC_3),    G(KC_4),    G(KC_5), G(KC_6),
    KC_TRNS, KC_PSCR, KC_BTN1, KC_MS_U, KC_TRNS, KC_TRNS,                             KC_DEL,     KC_HOME,    KC_END,     KC_TRNS,    KC_INS,  KC_PGUP,
    KC_TRNS, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                             KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_ENT,  KC_PGDN,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PWR,            KC_TRNS, M_SLSHR,    C(KC_LEFT), C(KC_RGHT), M_SLEXT,    M_SLCT, M_AF4,
                      KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL0, KC_ACL0,           KC_NO,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS),

	[_FN4] = LAYOUT(
    KC_NO,    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,                             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
    RESET,    KC_NO, DF(0),   DF(1),   CG_TOGG, TG(_FN4),                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
    TG(_FN4), KC_NO, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,                           KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO,
    KC_NO,    KC_NO, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        TG(_FN4), KC_NO,   KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_NO,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS, MO(_FN4), KC_TRNS)
};


td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

td_state_t hold_cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted) {
      if (!state->pressed) return TD_SINGLE_TAP;
      else return TD_SINGLE_HOLD;
    }
    else {
      if (!state->pressed) return TD_SINGLE_TAP;
      else return TD_SINGLE_HOLD;
    }
  }
  //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
  //with single tap.
  else if (state->count == 2) {
    if (state->pressed) return TD_DOUBLE_HOLD;
    else return TD_DOUBLE_TAP;
  }
  else if (state->count == 3) {
    if (!state->pressed) return TD_TRIPLE_TAP;
    else return TD_TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

void register_hyper (void) { //Helper function to invoke Hyper
  register_code16 (KC_LSFT);
  register_code16 (KC_LCTL);
  register_code16 (KC_LALT);
  register_code16 (KC_LGUI);
}
void unregister_hyper (void) { //Helper function to invoke Hyper
  unregister_code16 (KC_LSFT);
  unregister_code16 (KC_LCTL);
  unregister_code16 (KC_LALT);
  unregister_code16 (KC_LGUI);
}

static td_tap_t td1_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t td2_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t td3_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t td4_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t td5_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t td6_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t td7_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t td8_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t td9_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t td10_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t td11_state = {
    .is_press_action = true,
    .state = TD_NONE
};
// static td_tap_t td12_state = {
//     .is_press_action = true,
//     .state = TD_NONE
// };

void td1_finished (qk_tap_dance_state_t *state, void *user_data) {
  td1_state.state = hold_cur_dance(state);
  switch (td1_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_EXLM); break;
    case TD_SINGLE_HOLD: register_code16(KC_F1); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LALT); register_code16(KC_F1); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_F1); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_F1); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F1); break;
    default: break;
  }
}
void td1_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td1_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_EXLM); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F1); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LALT); unregister_code16(KC_F1); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_F1); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_F1); break;
    case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F1); break;
    default: break;
  }
  td1_state.state = TD_NONE;
}
void td2_finished (qk_tap_dance_state_t *state, void *user_data) {
  td2_state.state = hold_cur_dance(state);
  switch (td2_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_AT); break;
    case TD_SINGLE_HOLD: register_code16(KC_F2); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LALT); register_code16(KC_F2); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_F2); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_F2); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F2); break;
    default: break;
  }
}
void td2_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td2_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_AT); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F2); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LALT); unregister_code16(KC_F2); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_F2); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_F2); break;
    case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F2); break;
    default: break;
  }
  td2_state.state = TD_NONE;
}

void td3_finished (qk_tap_dance_state_t *state, void *user_data) {
  td3_state.state = hold_cur_dance(state);
  switch (td3_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_HASH); break;
    case TD_SINGLE_HOLD: register_code16(KC_F3); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LALT); register_code16(KC_F3); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_F3); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_F3); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F3); break;
    default: break;
  }
}
void td3_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td3_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_HASH); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F3); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LALT); unregister_code16(KC_F3); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_F3); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_F3); break;
    case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F3); break;
    default: break;
  }
  td3_state.state = TD_NONE;
}

void td4_finished (qk_tap_dance_state_t *state, void *user_data) {
  td4_state.state = hold_cur_dance(state);
  switch (td4_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_DOLLAR); break;
    case TD_SINGLE_HOLD: register_code16(KC_F4); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LALT); register_code16(KC_F4); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_F4); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_F4); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F4); break;
    default: break;
  }
}
void td4_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td4_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_DOLLAR); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F4); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LALT); unregister_code16(KC_F4); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_F4); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_F4); break;
    case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F4); break;
    default: break;
  }
  td4_state.state = TD_NONE;
}
void td5_finished (qk_tap_dance_state_t *state, void *user_data) {
  td5_state.state = hold_cur_dance(state);
  switch (td5_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_PERCENT); break;
    case TD_SINGLE_HOLD: register_code16(KC_F5); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LALT); register_code16(KC_F5); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_F5); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_F5); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F5); break;
    default: break;
  }
}
void td5_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td5_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_PERCENT); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F5); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LALT); unregister_code16(KC_F5); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_F5); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_F5); break;
    case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F5); break;
    default: break;
  }
  td5_state.state = TD_NONE;
}

void td6_finished (qk_tap_dance_state_t *state, void *user_data) {
  td6_state.state = hold_cur_dance(state);
  switch (td6_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_CIRCUMFLEX); break;
    case TD_SINGLE_HOLD: register_code16(KC_F6); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LALT); register_code16(KC_F6); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_F6); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_F6); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F6); break;
    default: break;
  }
}
void td6_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td6_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_CIRCUMFLEX); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F6); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LALT); unregister_code16(KC_F6); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_F6); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_F6); break;
case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F6); break;
    default: break;
  }
  td6_state.state = TD_NONE;
}

void td7_finished (qk_tap_dance_state_t *state, void *user_data) {
  td7_state.state = hold_cur_dance(state);
  switch (td7_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_AMPERSAND); break;
    case TD_SINGLE_HOLD: register_code16(KC_F7); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LALT); register_code16(KC_F7); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_F7); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_F7); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F7); break;
    default: break;
  }
}
void td7_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td7_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_AMPERSAND); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F7); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LALT); unregister_code16(KC_F7); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_F7); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_F7); break;
case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F7); break;
    default: break;
  }
  td7_state.state = TD_NONE;
}

void td8_finished (qk_tap_dance_state_t *state, void *user_data) {
  td8_state.state = hold_cur_dance(state);
  switch (td8_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_ASTERISK); break;
    case TD_SINGLE_HOLD: register_code16(KC_F8); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LALT); register_code16(KC_F8); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_F8); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_F8); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F8); break;
    default: break;
  }
}
void td8_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td8_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_ASTERISK); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F8); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LALT); unregister_code16(KC_F8); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_F8); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_F8); break;
case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F8); break;
    default: break;
  }
  td8_state.state = TD_NONE;
}

void td9_finished (qk_tap_dance_state_t *state, void *user_data) {
  td9_state.state = hold_cur_dance(state);
  switch (td9_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_RBRC); break;
    case TD_SINGLE_HOLD: register_code16(KC_F9); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LALT); register_code16(KC_F9); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_F9); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_F9); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F9); break;
    default: break;
  }
}
void td9_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td9_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_RBRC); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F9); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LALT); unregister_code16(KC_F9); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_F9); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_F9); break;
case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F9); break;
    default: break;
  }
  td9_state.state = TD_NONE;
}
void td10_finished (qk_tap_dance_state_t *state, void *user_data) {
  td10_state.state = hold_cur_dance(state);
  switch (td10_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_MINS); break;
    case TD_SINGLE_HOLD: register_code16(KC_F10); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LALT); register_code16(KC_F10); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_F10); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_F10); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F10); break;
    default: break;
  }
}
void td10_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td10_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_MINS); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F10); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LALT); unregister_code16(KC_F10); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_F10); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_F10); break;
case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F10); break;
    default: break;
  }
  td10_state.state = TD_NONE;
}

void td11_finished (qk_tap_dance_state_t *state, void *user_data) {
  td11_state.state = hold_cur_dance(state);
  switch (td11_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_EQL); break;
    case TD_SINGLE_HOLD: register_code16(KC_F11); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LALT); register_code16(KC_F11); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_F11);  break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_F11); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F11); break;
    default: break;
  }
}
void td11_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td11_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_EQL); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F11); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LALT); unregister_code16(KC_F11); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_F11); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_F11); break;
    case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F11); break;
    default: break;
  }
  td11_state.state = TD_NONE;
}
// void td12_finished (qk_tap_dance_state_t *state, void *user_data) {
//   td12_state.state = cur_dance(state);
//   switch (td12_state.state) {
//     case TD_SINGLE_TAP: register_code16(C_S_T(KC_LBRC)); break;
//     // case TD_SINGLE_HOLD: register_code16(KC_F12); break;
//     case TD_DOUBLE_HOLD: register_code16(KC_LALT); register_code16(KC_F12); break;
//     case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_F12); break;
//     case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_F12); break;
//     case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F12); break;
//     default: break;
//   }
// }
// void td12_reset (qk_tap_dance_state_t *state, void *user_data) {
//   switch (td12_state.state) {
//     case TD_SINGLE_TAP: unregister_code16(C_S_T(KC_LBRC)); break;
//     // case TD_SINGLE_HOLD: unregister_code16(KC_F12); break;
//     case TD_DOUBLE_HOLD: unregister_code16(KC_LALT); unregister_code16(KC_F12); break;
//     case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_F12); break;
//     case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_F12); break;
//     case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F12); break;
//     default: break;
//   }
//   td12_state.state = TD_NONE;
// }

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCOLON, KC_ENTER),
    [TD_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td1_finished, td1_reset),
    [TD_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td2_finished, td2_reset),
    [TD_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td3_finished, td3_reset),
    [TD_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td4_finished, td4_reset),
    [TD_5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td5_finished, td5_reset),
    [TD_6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td6_finished, td6_reset),
    [TD_7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td7_finished, td7_reset),
    [TD_8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td8_finished, td8_reset),
    [TD_9] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td9_finished, td9_reset),
    [TD_10] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td10_finished, td10_reset),
    [TD_11] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td11_finished, td11_reset),
    // [TD_12] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td12_finished, td12_reset),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
// --------------- ЛЕВАЯ КРУТИЛКА ------------------
    if (index == 0) {
// --------------- layer 4------------------
        if (IS_LAYER_ON(_FN4)) {
            if (clockwise) {
                tap_code16(A(KC_TAB));
            } else {
                tap_code16(LALT(KC_TAB));
            }
// --------------- NAV------------------
    } else if (IS_LAYER_ON(_NAV)) {
            if (clockwise) {
                tap_code16(KC_VOLU);
            } else {
                tap_code16(KC_VOLD);
            }
// --------------- NUM------------------
    } else if (IS_LAYER_ON(_NUM)) {
            if (clockwise) {
                if (get_mods() & MOD_BIT(KC_LALT)) {
                    unregister_mods(MOD_LALT);
                    tap_code16(C(G(KC_RIGHT)));        //на правый рабочий стол
                    register_mods(MOD_LALT);
                } else {
                    SEND_STRING(SS_LCTL("ax"));         //вырезание с выделением всего
                }
            } else {
                if (get_mods() & MOD_BIT(KC_LALT)) {
                    unregister_mods(MOD_LALT);
                    tap_code16(C(G(KC_LEFT)));        ////на левый рабочий стол
                    register_mods(MOD_LALT);
                } else {
                    SEND_STRING(SS_LCTL("ac"));         //копирование с выделением всего
                }
            }
// --------------- GAME------------------
    } else if (IS_LAYER_ON(_GAME)) {
            if (clockwise) {
                tap_code16(KC_F9);
            } else {
                tap_code16(KC_F5);
            }
// --------------- HOME LAYER------------------
    } else  if (clockwise) {
                if (get_mods() & MOD_BIT(KC_LSHIFT)) {
                    unregister_mods(MOD_LSFT);
                    tap_code16(C(KC_Y));         //отмена вперед
                    register_mods(MOD_LSFT);
                } else if (get_mods() & MOD_BIT(KC_LALT)) {
                    clear_mods();
                    tap_code16(KC_PGDN);         // прокрутка вверх
                    register_mods(MOD_LALT);
                } else if (get_mods() & MOD_MASK_CTRL) {
                    clear_mods();
                    tap_code16(G(S(KC_RIGHT)));         // переместить окно на другой монитор
                    register_mods(MOD_MASK_CTRL);
                }
                else {
                    tap_code16(C(KC_V));        //вставка
                }
            } else {
                if (get_mods() & MOD_BIT(KC_LSHIFT)) {
                    unregister_mods(MOD_LSFT);
                    tap_code16(C(KC_Z));        //отмена назад
                    register_mods(MOD_LSFT);
                } else if (get_mods() & MOD_BIT(KC_LALT)) {
                    clear_mods();
                    tap_code16(KC_PGUP);         // прокрутка вниз
                    register_mods(MOD_LALT);
                } else if (get_mods() & MOD_MASK_CTRL) {
                    clear_mods();
                    tap_code16(G(S(KC_LEFT)));         // переместить окно на другой монитор
                    register_mods(MOD_MASK_CTRL);
                }
                else {
                    tap_code16(C(KC_C));         //копирование
                }
          }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case M_ARROW:
//         if (record->event.pressed) {
//             // when keycode QMKBEST is pressed
//             SEND_STRING("=>");
//         } else {
//             // when keycode QMKBEST is released
//         }
//         break;
//     }
// }

// --------------- ПРАВАЯ КРУТИЛКА ------------------
} else if (index == 1) {
    if (IS_LAYER_ON(_FN4)) {
            if (clockwise) {
                tap_code16(C(KC_PGDOWN));
            }
            else {
                tap_code16(C(KC_PGUP));
            }
// --------------- NAV------------------
    } else if (IS_LAYER_ON(_NAV)) {
            if (clockwise) {
                tap_code16(KC_VOLU);    // громче
                tap_code16(KC_VOLU);    // громче
                tap_code16(KC_VOLU);    // громче
            }
            else {
                tap_code16(KC_VOLD);    // тише
                tap_code16(KC_VOLD);    // тише
                tap_code16(KC_VOLD);    // тише
            }
// --------------- NUM------------------
    } else if (IS_LAYER_ON(_NUM)) {
            if (clockwise) {
                tap_code16(A(KC_RIGHT));    // навигация по альт + стрелка
            }
            else {
                tap_code16(A(KC_LEFT));     // навигация по альт + стрелка
            }
// --------------- GAME------------------

    } else if (IS_LAYER_ON(_GAME)) {
            if (clockwise) {
                tap_code16(KC_VOLU);
            }
            else {
                tap_code16(KC_VOLD);
            }
// --------------- home layer------------------
    } else {
            if (clockwise) {
                tap_code16(C(KC_PGDOWN));       //переключение внутренних вкладок вперед
            }
            else {
                tap_code16(C(KC_PGUP));         //переключение внутренних вкладок назад
            }
    }

}
    return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case M_SLEXT:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_RIGHT) SS_UP(X_LSFT) SS_UP(X_LALT));
        }
        break;
    case M_SLSHR:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_LEFT) SS_UP(X_LSFT) SS_UP(X_LALT));
        }
        break;
        case KC_BSPC: {
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSFT);
                    SEND_STRING(SS_TAP(X_DEL));
                    register_code(KC_LSFT);
                } else {

                }
            } else {

            }
            return false;
            break;
        }    case M_ARROW:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("=>");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case M_SLCT:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LCTL) SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_RIGHT) SS_UP(X_LCTL) SS_UP(X_LSFT));
        } else {
            // when keycode QMKURL is released
        }
        break;
    case M_AF4:
            if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_F4) SS_UP(X_LALT));
        } else {
            // when keycode is released

        }
        break;

            // register_code16(KC_LALT);
            // register_code16(KC_F4);

            // SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_F4) SS_DELAY(5000) SS_UP(X_LALT));
    case M_1:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code16(KC_1);
            } else {
                tap_code16(KC_EXLM);
            }
        } else {
            // when keycode QMKURL is released
        }
        break;
    case M_2:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code16(KC_2);
            } else {
                tap_code16(KC_AT);
            }
        } else {
            // when keycode QMKURL is released
        }
        break;
    case M_3:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code16(KC_3);
            } else {
                tap_code16(KC_HASH);
            }
        } else {
            // when keycode QMKURL is released
        }
        break;
    case M_4:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code16(KC_4);
            } else {
                tap_code16(KC_DOLLAR);
            }
        } else {
            // when keycode QMKURL is released
        }
        break;
    case M_5:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code16(KC_5);
            } else {
                tap_code16(KC_PERCENT);
            }
        } else {
            // when keycode QMKURL is released
        }
        break;
    case M_6:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code16(KC_6);
            } else {
                tap_code16(KC_CIRCUMFLEX);
            }
        } else {
            // when keycode QMKURL is released
        }
        break;
    case M_7:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code16(KC_7);
            } else {
                tap_code16(KC_AMPERSAND);
            }
        } else {
            // when keycode QMKURL is released
        }
        break;
    case M_8:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code16(KC_8);
            } else {
                tap_code16(KC_ASTERISK);
            }
        } else {
            // when keycode QMKURL is released
        }
        break;
    }
    return true;
};








// void register_ctrl_shift (void) {
//   register_code (KC_LSFT);
//   register_code (KC_LCTRL);
// }

// void unregister_ctrl_shift (void) {
//   unregister_code (KC_LSFT);
//   unregister_code (KC_LCTRL);
// }

// void register_ctrl_alt (void) {
//   register_code (KC_LALT);
//   register_code (KC_LCTRL);
// }

// void unregister_ctrl_alt (void) {
//   unregister_code (KC_LALT);
//   unregister_code (KC_LCTRL);
// }

// void register_alt_shift (void) {
//   register_code (KC_LSFT);
//   register_code (KC_LALT);
// }

// void unregister_alt_shift (void) {
//   unregister_code (KC_LSFT);
//   unregister_code (KC_LALT);
// }
