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

#ifdef OLED_DRIVER_ENABLE
    #include "oled.c"
#endif
#include "somefile.c"

enum layer_names {
  _HOME,
  _GAME,
  _NUM,
  _NAV,
  _GPLUS,
  _EXTRA
};

enum custom_keycodes {          // макросы
    M_ARROW = SAFE_RANGE,
    M_PW1,
    M_PW2,
    M_SLCT,
    M_AF4,
    M_CACX,
    M_INC,
    M_DEC,
    M_LDR,
    LT_NUM,
    RT_NUM,
};

// ==========================Тап дэнс секция==============================
enum {              // Tap dance enums
    TD_GRV,
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
        case LT(_NAV,KC_BSPC):
            return 250;
        case LT(_NUM, KC_SPC):
            return 250;
        case LT(_EXTRA, KC_GRV):
            return 250;
        case LSFT_T(KC_SPC):
            return 250;
        case C_S_T(KC_TAB):
            return 250;
        case LCA_T(KC_Z):
            return 250;
        case LCTL_T(KC_ESC):
            return 250;
        case RCTL_T(KC_QUOT):
            return 250;
        case C_S_T(KC_LBRC):
            return 250;
        case KC_WH_U:
            return 10;
        case KC_WH_D:
            return 10;
        case M_AF4:
            return 500;
        case KTD_GRV:
            return 200;
        case KTD_SCLN:
            return 180;
        case KTD_1:
            return 200;
        case KTD_2:
            return 200;
        case KTD_3:
            return 200;
        case KTD_4:
            return 200;
        case KTD_5:
            return 200;
        case KTD_6:
            return 200;
        case KTD_7:
            return 200;
        case KTD_8:
            return 200;
        case KTD_9:
            return 200;
        case KTD_10:
            return 200;
        case KTD_11:
            return 200;
        // case KTD_12:
        //     return 200;
        default:
            return TAPPING_TERM;
    }
}


// Раскладки клавиатуры
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_HOME] = LAYOUT(
    KTD_GRV,         KTD_1,        KTD_2,    KTD_3,    KTD_4,    KTD_5,                                     KTD_6,   KTD_7,   KTD_8,   KTD_9,   KTD_10,     KTD_11,
    C_S_T(KC_TAB),   KC_Q,         KC_W,     KC_E,     KC_R,     KC_T,                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       C_S_T(KC_LBRC),
    LCTL_T(KC_ESC),  KC_A,         KC_S,     KC_D,     KC_F,     KC_G,                                      KC_H,    KC_J,    KC_K,    KC_L,    KTD_SCLN,   RCTL_T(KC_QUOT),
    KC_LSFT,         LCA_T(KC_Z),  KC_X,     KC_C,     KC_V,     KC_B,            C(KC_X),                KC_MPLY,   KC_N,    KC_M,    KC_COMM, KC_DOT, LCA_T(KC_SLSH),KC_RSFT,
                     M_LDR,        KC_LGUI,  KC_LALT,  MO(_NUM), LSFT_T(KC_SPC),  LT(_NUM, KC_SPC),   LT(_NAV,KC_BSPC), KC_RALT, LT(_EXTRA, KC_ENT), KC_BSLS),

	[_GAME] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,  KC_3,    KC_4,    KC_5,                              DM_PLY1,  DM_PLY2, DM_REC1, DM_REC2, KC_LOCK, DM_RSTP,
    KC_TAB,  KC_Q,    KC_W,  KC_E,    KC_R,    KC_T,                              KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_LCTL, KC_A,    KC_S,  KC_D,    KC_F,    KC_G,                              KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,  KC_C,    KC_V,    KC_B,     KC_MUTE,      TG(_GAME), KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC,
                      KC_F9, KC_BSPC, KC_LALT, MO(_GPLUS), KC_SPC,         KC_ENT,  LT(_NAV,KC_BSPC), KC_RALT, KC_RGUI, KC_BSLS),

	[_NUM] = LAYOUT(
    KC_PSCR,   KC_F1,   KC_2,    KC_F3,   KC_F4,    KC_F5,                              KC_F6,   KC_F7,   KC_F8,  KC_F9, KC_F10,  KC_F11,
    A(KC_TAB), M_ARROW, KC_GT,   KC_RBRC, KC_RPRN,  KC_RCBR,                            KC_PCMM, KC_7,    KC_8,   KC_9,  KC_PAST, KC_F12,
    DM_RSTP,   M_SLCT,  KC_LT,   KC_LBRC, KC_LPRN,  KC_LCBR,                            KC_PDOT, KC_4,    KC_5,   KC_6,  KC_0,    KC_PPLS,
    DM_REC1,   DM_PLY1, A(KC_X), A(KC_C), A(KC_V), A(KC_B), M_CACX,         TG(_GAME), _______,  KC_1,    KC_2,   KC_3,  KC_PSLS, KC_PENT,
                      KC_LOCK, KC_LCTL, _______,  _______, _______,         _______,  C(KC_DEL), KC_PMNS, _______, _______),

	[_NAV] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                               G(KC_1),    G(KC_2),    G(KC_3),    G(KC_4), G(KC_5), G(KC_6),
    _______, _______, KC_BTN1, KC_MS_U, _______, KC_WH_U,                               KC_DEL,     KC_HOME,    KC_END,     KC_INS,  KC_PGDN,  KC_PGUP,
    _______, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                               KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT, KC_ENT,  C(KC_BSPC),
    _______, _______, _______, _______, _______, _______,   _______,           _______, M_DEC,      C(KC_LEFT), C(KC_RGHT), M_INC,   M_SLCT,  M_AF4,
                      _______, _______, KC_ACL0, C(KC_DEL), KC_ACL0,           _______, _______,    C(KC_DEL),  KC_RCTL,    _______),

	[_GPLUS] = LAYOUT(
    _______,  _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______),

	[_EXTRA] = LAYOUT(
    _______,  G(S(KC_F)), _______,   _______, _______, _______,                           _______, _______, _______, _______, KC_PWR, KC_SLEP,
    _______,  _______,    _______,   _______, _______, _______,                           _______, _______, _______, _______, _______, RESET,
    _______,  _______,    _______,   M_PW1,   M_PW2,   _______,                           _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
    _______,  _______,    _______,   _______, _______, _______, _______,         _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,
                          _______,   _______, _______, _______, _______,         _______, _______, _______, _______, _______)
};


// Энкодер
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {          // --------------- ЛЕВАЯ КРУТИЛКА ------------------

// --------------- layer 4------------------
        if (IS_LAYER_ON(_GPLUS)) {
            if (clockwise) {
                // Здесь мог бы быть ваш keycode
            } else {
                // Здесь мог бы быть ваш keycode
            }
// --------------- NAV------------------
    } else if (IS_LAYER_ON(_NAV)) {
            if (clockwise) {
                clear_mods();
                tap_code16(A(S(KC_RIGHT)));
                clear_mods();
            } else {
                clear_mods();
                tap_code16(A(S(KC_LEFT)));
                clear_mods();
            }
// --------------- NUM------------------
    } else if (IS_LAYER_ON(_NUM)) {
            if (clockwise) {
                if (get_mods() & MOD_BIT(KC_LALT)) {    // инкремент в вс коде
                    tap_code16(C(S(G(KC_UP))));
                } else {
                    SEND_STRING(SS_LCTL("av"));         // вставка с выделением всего
                }
            } else {
                if (get_mods() & MOD_BIT(KC_LALT)) {
                    tap_code16(C(S(G(KC_DOWN))));       // декремент в вс коде
                } else {
                    SEND_STRING(SS_LCTL("ac"));         //копирование с выделением всего
                }
            }
// --------------- GAME------------------
    } else if (IS_LAYER_ON(_GAME)) {
            if (clockwise) {
                tap_code16(KC_F9);                      // загрузка
            } else {
                tap_code16(KC_F5);                      // сохранение
            }
// --------------- HOME LAYER LEFT ------------------
    } else  if (clockwise) {
                // tap_code16(LEFT_CW_HOME);


                if (get_mods() & MOD_BIT(KC_LSHIFT)) {
                    unregister_mods(MOD_LSFT);
                    tap_code16(C(KC_Y));                        //отмена вперед
                    register_mods(MOD_LSFT);
                } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
                    tap_code16(G(KC_RIGHT));                    // переместить окно на другой монитор
                } else if (get_mods() & MOD_BIT(KC_LALT)) {
                    tap_code16(C(KC_RIGHT));                    // переместить вкладку вс кода в правую группу
                    // clear_mods();
                } else if (get_mods() & MOD_BIT(KC_RALT)) {
                    tap_code16(C(S(KC_6)));                       // переход на следующую панель вс код
                } else if (get_mods() & MOD_BIT(KC_RCTL)) {
                    // Здесь мог бы быть ваш keycode
                }
                else {
                    tap_code16(C(KC_V));                         //вставка
                }
            } else {
                // tap_code16(LEFT_CCW_HOME);

                // Здесь мог бы быть ваш keycode

                if (get_mods() & MOD_BIT(KC_LSHIFT)) {
                    unregister_mods(MOD_LSFT);
                    tap_code16(C(KC_Z));                        //отмена назад
                    register_mods(MOD_LSFT);
                } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
                    tap_code16(G(KC_LEFT));                     // переместить окно на другой монитор
                } else if (get_mods() & MOD_BIT(KC_LALT)) {
                    tap_code16(C(KC_LEFT));                     // переместить вкладку вс кода в левую группу
                    // clear_mods();
                } else if (get_mods() & MOD_BIT(KC_RALT)) {
                    tap_code16(KC_TAB);                       // альт таб
                } else if (get_mods() & MOD_BIT(KC_RCTL)) {
                    // Здесь мог бы быть ваш keycode
                }
                else {
                    tap_code16(C(KC_C));                        //копирование
                }
          }

} else if (index == 1) {       // --------------- ПРАВАЯ КРУТИЛКА ------------------

    if (IS_LAYER_ON(_GPLUS)) {
            if (clockwise) {
                tap_code16(C(KC_PGDOWN));
            }
            else {
                tap_code16(C(KC_PGUP));
            }
// --------------- NAV------------------
    } else if (IS_LAYER_ON(_NAV)) {
            if (clockwise) {
                if (get_mods() & MOD_BIT(KC_RALT)) {
                    // единичное действие
                } else {
                    tap_code16(KC_VOLU);    // громче
                    tap_code16(KC_VOLU);    // громче
                    tap_code16(KC_VOLU);    // громче
                }
            }   else {
                if (get_mods() & MOD_BIT(KC_RALT)) {
                    // единичное действие
                }
                else {
                    tap_code16(KC_VOLD);    // тише
                    tap_code16(KC_VOLD);    // тише
                    tap_code16(KC_VOLD);    // тише
                }
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
// --------------- HOME LAYER RIGHT ------------------
    } else if (IS_LAYER_ON(_HOME)) {
            if (clockwise) {
                if (get_mods() & MOD_BIT(KC_LSHIFT)) {                  // развернуть область рекурсивно
                    unregister_code16(KC_LSHIFT);
                    tap_code16(C(KC_K));
                    tap_code16(C(S(KC_LBRC)));
                } else if (get_mods() & MOD_BIT(KC_LALT)) {             // развернуть все области
                    unregister_code16(KC_LALT);
                    tap_code16(C(KC_K));
                    tap_code16(C(KC_J));
                } else if (get_mods() & MOD_BIT(KC_LCTL)) {
                    tap_code16(S(KC_LBRC));                             // развернуть область
                } else if (get_mods() & MOD_BIT(KC_RALT)) {
                // Здесь мог бы быть ваш keycode
                } else if (get_mods() & MOD_BIT(KC_LGUI)) {
                    tap_code16(C(KC_RIGHT));                            // на правый рабочий стол
                }
                else {
                    tap_code16(C(KC_PGDN));
                }
            } else {
                if (get_mods() & MOD_BIT(KC_LSHIFT)) {                  // развернуть область рекурсивно
                    unregister_code16(KC_LSHIFT);
                    tap_code16(C(KC_K));
                    tap_code16(C(S(KC_RBRC)));
                } else if (get_mods() & MOD_BIT(KC_LALT)) {             // свернуть все области
                    unregister_code16(KC_LALT);
                    tap_code16(C(KC_K));
                    tap_code16(C(KC_P8));
                } else if (get_mods() & MOD_BIT(KC_RALT)) {
                // Здесь мог бы быть ваш keycode
                } else if (get_mods() & MOD_BIT(KC_LCTL)) {
                    tap_code16(S(KC_RBRC));                             // свернуть область
                } else if (get_mods() & MOD_BIT(KC_LGUI)) {
                    tap_code16(C(KC_LEFT));                             // на левый рабочий стол
                }
                else {
                    tap_code16(C(KC_PGUP));
                }
            }
    }
}
    return true;
}
// Реакции кастомных кодов
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    // case LSFT_T(KC_BSPC):
    //     if (record->event.pressed) {
    //         LSHIFT_PRESSED = true;
    //     } else {
    //         LSHIFT_PRESSED = false;
    //     }
    //     break;
    // case LT(_NAV,KC_BSPC):
    //     if (record->event.pressed) {
    //         if (get_mods() & LSHIFT_PRESSED) {
    //         // Здесь мог бы быть ваш keycode
    //             unregister_code16(KC_LSFT);
    //             unregister_code16(KC_BSPC);
    //             register_code16(KC_LCTL);
    //             register_code16(KC_DEL);
    //         } else {
    //             tap_code16(KC_BSPC);
    //         }
    //     } else {
    //         unregister_code16(KC_LCTL);
    //         unregister_code16(KC_DEL);
    //     }
    //     return false;
        // break;
    case KC_LALT:
        if (record->event.pressed) {
            register_code16(KC_LALT);
        } else {
            unregister_code16(KC_LALT);
        }
        break;
    case M_INC:
        if (record->event.pressed) {
            tap_code16(C(S(A(G(KC_UP)))));
        }
        break;
    case M_DEC:
        if (record->event.pressed) {
            tap_code16(C(S(A(G(KC_DOWN)))));
        }
        break;
    case M_CACX:
        if (record->event.pressed) {
            if (get_mods() & MOD_BIT(KC_LALT)) {
                unregister_code16(KC_LALT);
                // желательно комбинация с альтом, убрать верхнюю строку
            } else {
                SEND_STRING(SS_LCTL("ax"));         // вырезание с выделением всего

            }
        }
        break;
    case M_PW1:
        tap_code16(KC_LSFT);
        if (record->event.pressed) {
            SEND_STRING(PW1);
        }
        break;
    case M_PW2:
        tap_code16(KC_LSFT);
        if (record->event.pressed) {
            SEND_STRING(PW2);
            tap_code16(C(KC_LEFT));
            tap_code16(KC_LEFT);
        }
        break;
        case M_ARROW:
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
    case M_LDR:
            if (record->event.pressed) {
            // when keycode is pressed
            register_code16(KC_LCTL);
            register_code16(KC_LSFT);
            register_code16(KC_LALT);
        } else {
            unregister_code16(KC_LCTL);
            unregister_code16(KC_LSFT);
            unregister_code16(KC_LALT);
            // when keycode is released

        }
        break;
    };
    return true;
};


typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    // TD_SINGLE_TAP_SHIFT,
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

td_state_t hold_cur_dance (qk_tap_dance_state_t *state);

void register_hyper (void);
void unregister_hyper (void);

void GRV_finished (qk_tap_dance_state_t *state, void *user_data);
void GRV_reset (qk_tap_dance_state_t *state, void *user_data);

void SCLN_finished (qk_tap_dance_state_t *state, void *user_data);
void SCLN_reset (qk_tap_dance_state_t *state, void *user_data);

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


// td_state_t cur_dance(qk_tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
//         // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
//         else return TD_SINGLE_HOLD;
//     } else if (state->count == 2) {
//         // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
//         // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
//         // keystrokes of the key, and not the 'double tap' action/macro.
//         if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
//         else if (state->pressed) return TD_DOUBLE_HOLD;
//         else return TD_DOUBLE_TAP;
//     }

//     // Assumes no one is trying to type the same letter three times (at least not quickly).
//     // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
//     // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
//     if (state->count == 3) {
//         if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
//         else return TD_TRIPLE_HOLD;
//     } else return TD_UNKNOWN;
// }

td_state_t hold_cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted) {
      if (!state->pressed) return TD_SINGLE_TAP;
      else return TD_SINGLE_HOLD;
      }

        // if (get_mods() & MOD_MASK_SHIFT) {              // эта часть не работает как надо, при нажатии шифта залипает цифра
        //     return TD_SINGLE_TAP_SHIFT;                 //
        // } else return TD_SINGLE_TAP;                    //

    //   } else return TD_SINGLE_HOLD;
    else {
      if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
        // if (get_mods() & MOD_MASK_SHIFT) {               // эта часть не работает как надо, при нажатии шифта залипает цифра
        //     return TD_SINGLE_TAP_SHIFT;                  //
        // } else return TD_SINGLE_TAP;                     //

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

static td_tap_t GRV_state = {
    .is_press_action = true,
    .state = TD_NONE
};

static td_tap_t SCLN_state = {
    .is_press_action = true,
    .state = TD_NONE
};
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
void GRV_finished (qk_tap_dance_state_t *state, void *user_data) {
  GRV_state.state = hold_cur_dance(state);
  switch (GRV_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_0); break;
    case TD_SINGLE_HOLD: register_code16(KC_GRV); break;
    case TD_DOUBLE_HOLD: register_code16(KC_ESC); break;
    case TD_DOUBLE_TAP: register_code16(KC_LSFT); register_code16(KC_GRV);  break;
    // case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_F1); break;
    // case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F1); break;
    default: break;
  }
}
void GRV_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (GRV_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_0); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_GRV); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_ESC); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LSFT); unregister_code16(KC_GRV);  break;
    // case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_F1); break;
    // case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F1); break;
    default: break;
  }
  GRV_state.state = TD_NONE;
}

void SCLN_finished (qk_tap_dance_state_t *state, void *user_data) {
  SCLN_state.state = hold_cur_dance(state);
  switch (SCLN_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_SCLN); break;
    case TD_SINGLE_HOLD: register_code16(KC_ESC); break;
    case TD_DOUBLE_HOLD: register_code16(KC_ESC); break;
    case TD_DOUBLE_TAP: register_code16(KC_ENT); break;
    // case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_F1); break;
    // case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F1); break;
    default: break;
  }
}
void SCLN_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (SCLN_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_SCLN); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_ESC); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_ESC); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_ENT); break;
    // case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_F1); break;
    // case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F1); break;
    default: break;
  }
  SCLN_state.state = TD_NONE;
}
void td1_finished (qk_tap_dance_state_t *state, void *user_data) {
  td1_state.state = hold_cur_dance(state);
  switch (td1_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_1); break;
    // case TD_SINGLE_TAP_SHIFT: del_mods(MOD_MASK_SHIFT); register_code16(KC_P1); break;
    case TD_SINGLE_HOLD: register_code16(KC_F1); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LCTL); register_code16(KC_LALT); register_code16(KC_F1); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_LSHIFT); register_code16(KC_F1); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_LALT); register_code16(KC_F1); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F1); break;
    default: break;
  }
}
void td1_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td1_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_1); break;
    // case TD_SINGLE_TAP_SHIFT: unregister_code16(KC_1); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F1); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LCTL); unregister_code16(KC_LALT); unregister_code16(KC_F1); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_LSHIFT); unregister_code16(KC_F1); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_LALT); unregister_code16(KC_F1); break;
    case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F1); break;
    default: break;
  }
  td1_state.state = TD_NONE;
}
void td2_finished (qk_tap_dance_state_t *state, void *user_data) {
  td2_state.state = hold_cur_dance(state);
  switch (td2_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_2); break;
    case TD_SINGLE_HOLD: register_code16(KC_F2); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LCTL); register_code16(KC_LALT); register_code16(KC_F2); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_LSHIFT); register_code16(KC_F2); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_LALT); register_code16(KC_F2); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F2); break;
    default: break;
  }
}
void td2_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td2_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_2); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F2); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LCTL); unregister_code16(KC_LALT); unregister_code16(KC_F2); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_LSHIFT); unregister_code16(KC_F2); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_LALT); unregister_code16(KC_F2); break;
    case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F2); break;
    default: break;
  }
  td2_state.state = TD_NONE;
}

void td3_finished (qk_tap_dance_state_t *state, void *user_data) {
  td3_state.state = hold_cur_dance(state);
  switch (td3_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_3); break;
    case TD_SINGLE_HOLD: register_code16(KC_F3); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LCTL); register_code16(KC_LALT); register_code16(KC_F3); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_LSHIFT); register_code16(KC_F3); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_LALT); register_code16(KC_F3); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F3); break;
    default: break;
  }
}
void td3_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td3_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_3); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F3); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LCTL); unregister_code16(KC_LALT); unregister_code16(KC_F3); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_LSHIFT); unregister_code16(KC_F3); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_LALT); unregister_code16(KC_F3); break;
    case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F3); break;
    default: break;
  }
  td3_state.state = TD_NONE;
}

void td4_finished (qk_tap_dance_state_t *state, void *user_data) {
  td4_state.state = hold_cur_dance(state);
  switch (td4_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_4); break;
    case TD_SINGLE_HOLD: register_code16(KC_F4); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LCTL); register_code16(KC_LALT); register_code16(KC_F4); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_LSHIFT); register_code16(KC_F4); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_LALT); register_code16(KC_F4); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F4); break;
    default: break;
  }
}
void td4_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td4_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_4); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F4); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LCTL); unregister_code16(KC_LALT); unregister_code16(KC_F4); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_LSHIFT); unregister_code16(KC_F4); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_LALT); unregister_code16(KC_F4); break;
    case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F4); break;
    default: break;
  }
  td4_state.state = TD_NONE;
}
void td5_finished (qk_tap_dance_state_t *state, void *user_data) {
  td5_state.state = hold_cur_dance(state);
  switch (td5_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_5); break;
    case TD_SINGLE_HOLD: register_code16(KC_F5); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LCTL); register_code16(KC_LALT); register_code16(KC_F5); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_LSHIFT); register_code16(KC_F5); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_LALT); register_code16(KC_F5); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F5); break;
    default: break;
  }
}
void td5_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td5_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_5); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F5); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LCTL); unregister_code16(KC_LALT); unregister_code16(KC_F5); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_LSHIFT); unregister_code16(KC_F5); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_LALT); unregister_code16(KC_F5); break;
    case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F5); break;
    default: break;
  }
  td5_state.state = TD_NONE;
}

void td6_finished (qk_tap_dance_state_t *state, void *user_data) {
  td6_state.state = hold_cur_dance(state);
  switch (td6_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_6); break;
    case TD_SINGLE_HOLD: register_code16(KC_F6); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LCTL); register_code16(KC_LALT); register_code16(KC_F6); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_LSHIFT); register_code16(KC_F6); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_LALT); register_code16(KC_F6); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F6); break;
    default: break;
  }
}
void td6_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td6_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_6); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F6); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LCTL); unregister_code16(KC_LALT); unregister_code16(KC_F6); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_LSHIFT); unregister_code16(KC_F6); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_LALT); unregister_code16(KC_F6); break;
    case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F6); break;
    default: break;
  }
  td6_state.state = TD_NONE;
}

void td7_finished (qk_tap_dance_state_t *state, void *user_data) {
  td7_state.state = hold_cur_dance(state);
  switch (td7_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_7); break;
    case TD_SINGLE_HOLD: register_code16(KC_F7); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LCTL); register_code16(KC_LALT); register_code16(KC_F7); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_LSHIFT); register_code16(KC_F7); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_LALT); register_code16(KC_F7); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F7); break;
    default: break;
  }
}
void td7_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td7_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_7); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F7); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LCTL); unregister_code16(KC_LALT); unregister_code16(KC_F7); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_LSHIFT); unregister_code16(KC_F7); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_LALT); unregister_code16(KC_F7); break;
    case TD_TRIPLE_HOLD: unregister_hyper(); unregister_code16(KC_F7); break;
    default: break;
  }
  td7_state.state = TD_NONE;
}

void td8_finished (qk_tap_dance_state_t *state, void *user_data) {
  td8_state.state = hold_cur_dance(state);
  switch (td8_state.state) {
    case TD_SINGLE_TAP: register_code16(KC_8); break;
    case TD_SINGLE_HOLD: register_code16(KC_F8); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LCTL); register_code16(KC_LALT); register_code16(KC_F8); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_LSHIFT); register_code16(KC_F8); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_LALT); register_code16(KC_F8); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F8); break;
    default: break;
  }
}
void td8_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td8_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_8); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F8); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LCTL); unregister_code16(KC_LALT); unregister_code16(KC_F8); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_LSHIFT); unregister_code16(KC_F8); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_LALT); unregister_code16(KC_F8); break;
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
    case TD_DOUBLE_HOLD: register_code16(KC_LCTL); register_code16(KC_LALT); register_code16(KC_F9); break;
    case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_LSHIFT); register_code16(KC_F9); break;
    case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_LALT); register_code16(KC_F9); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F9); break;
    default: break;
  }
}
void td9_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td9_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_RBRC); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F9); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_LCTL); unregister_code16(KC_LALT); unregister_code16(KC_F9); break;
    case TD_DOUBLE_TAP: unregister_code16(KC_LCTL); unregister_code16(KC_LSHIFT); unregister_code16(KC_F9); break;
    case TD_TRIPLE_TAP: unregister_code16(KC_LSHIFT); unregister_code16(KC_LALT); unregister_code16(KC_F9); break;
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
    case TD_DOUBLE_HOLD: register_code16(KC_LCTL); register_code16(KC_LALT); register_code16(KC_F10); break;
    // case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_LSHIFT); register_code16(KC_F10); break;
    // case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_LALT); register_code16(KC_F10); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F10); break;
    default: break;
  }
}
void td10_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td10_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_MINS); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F10); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LCTL); register_code16(KC_LALT); register_code16(KC_F10); break;
    // case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_LSHIFT); register_code16(KC_F10); break;
    // case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_LALT); register_code16(KC_F10); break;
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
    case TD_DOUBLE_HOLD: register_code16(KC_LCTL); register_code16(KC_LALT); register_code16(KC_F11); break;
    // case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_LSHIFT); register_code16(KC_F11); break;
    // case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_LALT); register_code16(KC_F11); break;
    case TD_TRIPLE_HOLD: register_hyper(); register_code16(KC_F11); break;
    default: break;
  }
}
void td11_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td11_state.state) {
    case TD_SINGLE_TAP: unregister_code16(KC_EQL); break;
    case TD_SINGLE_HOLD: unregister_code16(KC_F11); break;
    case TD_DOUBLE_HOLD: register_code16(KC_LCTL); register_code16(KC_LALT); register_code16(KC_F11); break;
    // case TD_DOUBLE_TAP: register_code16(KC_LCTL); register_code16(KC_LSHIFT); register_code16(KC_F11); break;
    // case TD_TRIPLE_TAP: register_code16(KC_LSHIFT); register_code16(KC_LALT); register_code16(KC_F11); break;
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
    [TD_GRV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, GRV_finished, GRV_reset),
    [TD_SCLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, SCLN_finished, SCLN_reset),
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
