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

enum {
    TD_MCR1,
    TD_MCR2,
    TD_SCLN
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    // [TD_MCR1] = ACTION_TAP_DANCE_DOUBLE(DM_PLY1, DM_REC1),
    // [TD_MCR2] = ACTION_TAP_DANCE_DOUBLE(DM_PLY2, DM_REC2),
    [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCOLON, KC_ENTER),
};

//делаем кастомные длительности нажтатий, чтобы успевать кликать дважды
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case TD(TD_MCR1):
        //     return 200;
        // case TD(TD_MCR2):
        //     return 200;
        case OSM(MOD_LSFT):
            return 200;
        case TD(TD_SCLN):
            return 200;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_BSPC:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_ALT) {
                unregister_mods(MOD_MASK_ALT);
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_DEL) SS_UP(X_LCTL));
            } else {
                tap_code16(LT(_NAV,KC_BSPC));
            }
        } else {
            // when keycode QMKURL is released
        }
        break;
    case M_ARROW:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("=>");
            // SEND_STRING(SS_TAP(X_EQL) SS_TAP(X_GT));      эту строку переписать, выдает ошибку
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
            tap_code16(A(KC_F4));
        break;
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
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_HOME] = LAYOUT(
    LT(_FN4, KC_GRV),M_1,          M_2,     M_3,     M_4,     M_5,                                  M_6,     M_7,     M_8,     KC_RBRC,KC_MINS,       KC_EQL,
    C_S_T(KC_TAB),   KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,                                 KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,          C_S_T(KC_LBRC),
    LCTL_T(KC_ESC),  KC_A,         KC_S,    KC_D,    KC_F,    KC_G,                                 KC_H,    KC_J,    KC_K,    KC_L,   TD(TD_SCLN),   RCTL_T(KC_QUOT),
    OSM(MOD_LSFT),   LCA_T(KC_Z),  KC_X,    KC_C,    KC_V,    KC_B,     C(KC_X),         KC_MPLY,   KC_N,    KC_M,    KC_COMM, KC_DOT, LCA_T(KC_SLSH),OSM(MOD_LSFT),
                    KC_LGUI, KC_TRNS, LALT_T(KC_NO),   MO(_NUM), LSFT_T(KC_SPC),  LT(_NUM, KC_SPC), LT(_NAV,KC_BSPC), RALT_T(KC_NO), LT(_FN4, KC_ENT), KC_BSLS),

	[_GAME] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,                            DM_PLY1,  DM_PLY2, DM_REC1, DM_REC2, KC_LOCK, DM_RSTP,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,                            KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,      KC_G,                            KC_H,     KC_J,    KC_K,    KC_L,    TD(TD_SCLN),    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,   KC_MUTE,      TG(_GAME), KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC,
                      KC_F9, KC_BSPC, KC_LALT,   MO(_FN4), KC_SPC,         KC_ENT,  LT(_NAV,KC_BSPC), KC_RCTL, EH_LEFT, EH_RGHT),

	[_NUM] = LAYOUT(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                              KC_F6,   KC_F7, KC_F8,   KC_F9,  KC_F10,  KC_F11,
    KC_CAPS, M_ARROW, KC_GT,   KC_RBRC, KC_RPRN,  KC_RCBR,                            KC_PCMM, KC_P7, KC_P8,   KC_P9,  KC_PAST, KC_F12,
    DM_RSTP, M_SLCT,  KC_LT,   KC_LBRC, KC_LPRN,  KC_LCBR,                            KC_PDOT, KC_P4, KC_P5,   KC_P6,  KC_PMNS, KC_PPLS,
    DM_REC1, DM_PLY1, A(KC_X), A(KC_C), A( KC_V), A(KC_B), KC_SLEP,         TG(_GAME),KC_TRNS, KC_P1, KC_P2,   KC_P3,  KC_PSLS, KC_PENT,
                      KC_LOCK, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,         KC_TRNS,  KC_P0,   KC_P0, KC_TRNS, KC_TRNS),

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
