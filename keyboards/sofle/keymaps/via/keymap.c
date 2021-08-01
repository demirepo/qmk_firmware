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

enum custom_keycodes {
    M_ARROW = SAFE_RANGE,
    M_MACRO0,
    M_MACRO1,
    M_MACRO2,
    M_MACRO3,
    M_MACRO4,
    M_MACRO5,
    M_MACRO6,
    M_MACRO7,
    M_MACRO8,
    M_MACRO9,
    M_MACRO10,
    M_MACRO11,
    M_MACRO12,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case M_ARROW:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("=>");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    // case QMKURL:
    //     if (record->event.pressed) {
    //         // when keycode QMKURL is pressed
    //         SEND_STRING("https://qmk.fm/\n");
    //     } else {
    //         // when keycode QMKURL is released
    //     }
    //     break;

    // case MY_OTHER_MACRO:
    //     if (record->event.pressed) {
    //        SEND_STRING(SS_LCTL("ac")); // selects all and copies
    //     }
    //     break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_HOME] = LAYOUT(
    KC_GRV,         KC_EXLM,      KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                    KC_CIRC, KC_AMPR,     KC_ASTR, KC_RBRC, KC_MINS,          KC_EQL,
    C_S_T(KC_TAB),  KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,                                       KC_Y,    KC_U,        KC_I,    KC_O,    C_S_T(KC_P),      KC_LBRC,
    LCTL_T(KC_ESC), KC_A,         KC_S,    KC_D,    KC_F,    KC_G,                                       KC_H,    KC_J,        KC_K,     KC_L,    RCTL_T(KC_SCLN),  KC_QUOT,
    OSM(MOD_LSFT),  LCA_T(KC_Z),  KC_X,    KC_C,    KC_V,    KC_B,     C(KC_X),                KC_MPLY,  KC_N,    KC_M,        KC_COMM, KC_DOT,  LCA_T(KC_SLSH),   OSM(MOD_LSFT),
                          KC_LGUI, KC_TRNS, LALT_T(KC_TRNS), MO(_NUM), LSFT_T(KC_SPC),     LT(_NUM, KC_SPC), LT(_NAV,KC_BSPC), RALT_T(KC_TRNS), KC_ENT,  KC_BSLS),

	[_GAME] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,                            KC_CIRC,  KC_AMPR, KC_ASTR, KC_BSLS, KC_MINS, KC_EQL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,                            KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,      KC_G,                            KC_H,     KC_J,    KC_K,    KC_L,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,     KC_MUTE,    TG(_GAME), KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC,
                      KC_F9, KC_BSPC, KC_LALT,   MO(_FN4), KC_SPC,         KC_SPC,  MO(_NAV), KC_RCTL, KC_RALT, KC_RBRC),

	[_NUM] = LAYOUT(
    KC_TRNS, KC_F1,   KC_F2,      KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7, KC_F8,   KC_F9,  KC_F10,  KC_F11,
    KC_CAPS, M_ARROW, C(KC_RSFT), KC_LBRC, KC_RBRC, KC_UNDS,                        KC_PCMM, KC_P7, KC_P8,   KC_P9,  KC_PAST, KC_F12,
    KC_TRNS, KC_LCBR, KC_RCBR,    KC_LPRN, KC_RPRN, KC_MINS,                        KC_PDOT, KC_P4, KC_P5,   KC_P6,  KC_PMNS, KC_PPLS,
    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_PWR,     TG(_GAME), KC_TRNS, KC_P1, KC_P2,   KC_P3,  KC_PSLS, KC_PENT,
                      KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,   KC_P0,   KC_P0, KC_TRNS, KC_TRNS),

	[_NAV] = LAYOUT(
    KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                         G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_6),
    KC_TRNS, KC_TRNS,    KC_BTN1,    KC_MS_U,    KC_BTN2,    KC_TRNS,                         KC_DEL,  KC_HOME, KC_END,  KC_TRNS, KC_INS,  KC_PGUP,
    KC_TRNS, KC_TRNS,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_TRNS,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,  KC_PGDN,
    KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_TRNS, KC_TRNS,       KC_SLEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_ACL0, KC_TRNS,       KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_FN4] = LAYOUT(
    KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
    RESET, KC_NO, DF(0),   DF(1),   CG_TOGG, KC_NO,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
    KC_NO, KC_NO, CG_TOGG, KC_NO,   KC_NO,   KC_NO,                            KC_NO,   KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          TG(_FN4),   KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO,
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
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
    } else {
            if (clockwise) {
                if (get_mods() & MOD_BIT(KC_LSHIFT)) {
                    unregister_mods(MOD_LSFT);
                    tap_code16(C(KC_Y));         //отмена вперед
                    register_mods(MOD_LSFT);
                } else if (get_mods() & MOD_BIT(KC_LALT)) {                         //эта часть пока не рабоает, что-то с режимом альта
                    unregister_mods(MOD_LALT);                                      //эта часть пока не рабоает
                    SEND_STRING(SS_LCTL("ax")); // выделение всего и вырезание      //эта часть пока не работает
                    register_mods(MOD_LALT);                                        //эта часть пока не рабоает
                } else {
                    tap_code16(C(KC_V));        //вставка
                }
            } else if (get_mods() & MOD_BIT(KC_LSHIFT)) {
                    unregister_mods(MOD_LSFT);
                    tap_code16(C(KC_Z));        //отмена назад
                    register_mods(MOD_LSFT);
            } else if (get_mods() & MOD_BIT(KC_LALT)) {                             //эта часть пока не работает
                    unregister_mods(MOD_LALT);                                      //эта часть пока не работает
                    SEND_STRING(SS_LCTL("ac")); // выделение всего и вырезание      //эта часть пока не рабоает
                    register_mods(MOD_LALT);                                        //эта часть пока не работает
            } else {
                    tap_code16(C(KC_C));         //копирование
            }
    }
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
            }
            else {
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

// Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// /*
//  * QWERTY
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
//  * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
//  * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */

// [0] = LAYOUT(
//   KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
//   KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
//   KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
//   KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
//                  KC_LGUI,KC_LALT,KC_LCTRL, MO(2), KC_ENT,      KC_SPC,  MO(3), KC_RCTRL, KC_RALT, KC_RGUI
// ),
// /*
//  * COLEMAK
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
//  * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
//  * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */

// [1] = LAYOUT(
//   KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
//   KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
//   KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
//   KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,      XXXXXXX,KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
//                  KC_LGUI,KC_LALT,KC_LCTRL,KC_TRNS, KC_ENT,      KC_SPC,  KC_TRNS, KC_RCTRL, KC_RALT, KC_RGUI
// ),
// /* LOWER
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
//  * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
//  * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */
// [2] = LAYOUT(
//   _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
//   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
//   _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
//   _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
//                        _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
// ),
// /* RAISE
//  * ,----------------------------------------.                    ,-----------------------------------------.
//  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
//  * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
//  * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */
// [3] = LAYOUT(
//   _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
//   _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, _______,   KC_UP, _______,_______, KC_BSPC,
//   _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
//   _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, _______, XXXXXXX, _______,   XXXXXXX, _______,
//                          _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
// )
// };
