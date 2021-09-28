/* Copyright 2020 @toastedmangoes
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _CURSOL
};

enum custom_keycodes {
    M_HNZN_TGL = SAFE_RANGE,    // IMEトグル用
    M_SP_LO,                    // LT(_LOWER, KC_SPC)
    M_BS_RA,                    // LT(_RAISE, KC_BS)
    M_EN_AD,                    // LT(_ADJUST, KC_ENT)
    M_DL_CUR                    // LT(_CURSOL, KC_DEL)
  };

// Base Layer Mod-Tap
#define KC_SSSF  RSFT_T(KC_SLSH)
#define KC_APAL  ALT_T(KC_APP)
#define KC_ESGU  LWIN_T(KC_ESC)

static bool lower_pressed = false;  // Lowerキー記憶用
static bool raise_pressed = false;  // Raiseキー記憶用
static bool adj_pressed   = false;  // Adjustキー記憶用
static bool cur_pressed   = false;  // Cursolキー記憶用
static uint16_t lower_pressed_time = 0; // Lowerキー押し下げ時間
static uint16_t raise_pressed_time = 0; // Raiseキー押し下げ時間
static uint16_t adj_pressed_time = 0; // Adjustキー押し下げ時間
static uint16_t cur_pressed_time = 0; // cursolキー押し下げ時間

// Base Layer Tap-Hold
// #define LT_SPLO  LT(_LOWER, KC_SPC)
// #define LT_BSRA  LT(_RAISE, KC_BSPC)
// #define LT_ENAD  LT(_ADJUST, KC_ENT)
// #define LT_DLCUR LT(_CURSOL, KC_DEL)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      M_HNZN_TGL,
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,   KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SSSF,   M_DL_CUR,
                                          KC_ESGU,   M_SP_LO,    M_EN_AD,  M_BS_RA,    KC_APAL
                                //  KC_ESGU,     LT(1, KC_SPC),    LT(3, KC_ENT),  LT(2, KC_BSPC),    KC_APAL
  ),

  [_LOWER] = LAYOUT_reviung41(
    A(KC_TAB),    KC_EXLM,     KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,                KC_P7,    KC_P8,    KC_P9,  KC_PPLS,  KC_PAST,  _______,
    S(KC_LGUI),   KC_UNDS,     KC_PIPE,  KC_UP,    KC_LCBR,   KC_RCBR,                KC_P4,    KC_P5,    KC_P6,  KC_PMNS,  KC_PSLS,    _______,
    KC_LSFT,      C(KC_PGUP),  KC_LEFT,  KC_DOWN,  KC_RGHT,   C(KC_PGDN),             KC_P1,    KC_P2,    KC_P3,  KC_PEQL,  A(KC_F4),  KC_CALC,
                                                         KC_LGUI,   _______,  KC_BSPC,   KC_P0,    KC_PDOT
  ),

  [_RAISE] = LAYOUT_reviung41(
    _______,  KC_1,      KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     LCA(KC_DEL),
    _______,  KC_MINS,   KC_EQL,   KC_BSLS,  KC_LBRC,   KC_RBRC,            KC_BSLS,  KC_MINS,  KC_EQL,   KC_LPRN,  KC_RPRN,  KC_RO,
    _______,  KC_CIRC,   KC_AMPR,  KC_ASTR,  KC_LPRN,   KC_RPRN,            KC_PIPE,  KC_UNDS,  KC_PLUS,  _______,  SWIN(KC_LEFT), SWIN(KC_RGHT),
                                             _______,   _______,  KC_ENT,  _______,  _______
  ),

  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  _______,   RGB_TOG,            _______,  KC_MINS,  KC_UNDS,  KC_UNDS, KC_PLUS,   KC_F1,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, KC_F7,     KC_F8,              KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_GRAVE,  RESET,
    _______,   KC_F6,   KC_F5,    KC_F4,    KC_F3,     KC_F2,              KC_LEFT,  KC_RGHT,  KC_UP,    KC_DOWN, KC_EQL,    _______,
                                            _______,   _______,  _______,  _______,  _______
  ),

  [_CURSOL] = LAYOUT_reviung41(
    KC_TAB,    KC_EXLM,  KC_AT,   KC_HASH,  KC_DLR,   KC_PERC,            KC_LCBR,  KC_RCBR,  S(KC_HOME),  _______,  S(KC_END),  KC_PGUP,
    KC_LCTL,   KC_CIRC, KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RCBR,            KC_LBRC,  KC_RBRC,  KC_HOME,     KC_UP,    KC_END,     KC_PGDN,
    KC_LSFT,   KC_BSLS, KC_PIPE,  KC_EQL,   KC_PLUS,  KC_TILD,            _______,  _______,  KC_LEFT,     KC_DOWN,  KC_RGHT,    _______,
                                            _______,   KC_LALT,  KC_BSPC,  _______,  _______
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint16_t lower_diff_time = 0;
    uint16_t raise_diff_time = 0;
    uint16_t adj_diff_time = 0;
    uint16_t cur_diff_time = 0;
    switch(keycode){
        case M_HNZN_TGL:  /* 全角/半角トグル */
         if (record->event.pressed) {
             SEND_STRING(SS_LALT("`"));
         } else {
             break;
         }
         break;

        case M_SP_LO:   // Lower/SPACEキー押下時
         if (record->event.pressed) {
             lower_pressed = true;  // Lowerキーが押されたことを記憶
             lower_pressed_time = record->event.time;

             layer_on(_LOWER);
         } else {
             layer_off(_LOWER);

             lower_diff_time = TIMER_DIFF_16(record->event.time, lower_pressed_time);

            if (lower_pressed && lower_diff_time < TAPPING_TERM) {
               register_code(KC_SPC);
               unregister_code(KC_SPC);
            }
         lower_pressed = false;
        }
        return false;
        break;

        case M_BS_RA:   // RAISE/BackSpaceキー押下時
         if (record->event.pressed) {
             raise_pressed = true;  // Raiseキーが押されたことを記憶
             raise_pressed_time = record->event.time;

             layer_on(_RAISE);
         } else {
             layer_off(_RAISE);

             raise_diff_time = TIMER_DIFF_16(record->event.time, raise_pressed_time);

            if (raise_pressed && raise_diff_time < TAPPING_TERM) {
               register_code(KC_BSPC);
               unregister_code(KC_BSPC);
            }
            raise_pressed = false;
        }
        return false;
        break;

        case M_EN_AD:   // ADJUST/Enterキー押下時
         if (record->event.pressed) {
             adj_pressed = true;  // Adjustキーが押されたことを記憶
             adj_pressed_time = record->event.time;

             layer_on(_ADJUST);
         } else {
             layer_off(_ADJUST);

             adj_diff_time = TIMER_DIFF_16(record->event.time, adj_pressed_time);

             if (adj_pressed && adj_diff_time < TAPPING_TERM) {
                register_code(KC_ENT);
                unregister_code(KC_ENT);
             }
            adj_pressed = false;
        }
        return false;
        break;

        case M_DL_CUR:   // CURSOL/Delキー押下時
         if (record->event.pressed) {
             cur_pressed = true;  // Cursolキーが押されたことを記憶
             cur_pressed_time = record->event.time;

             layer_on(_CURSOL);
         } else {
             layer_off(_CURSOL);

             cur_diff_time = TIMER_DIFF_16(record->event.time, cur_pressed_time);

            if (cur_pressed && cur_diff_time < TAPPING_TERM) {
               register_code(KC_DEL);
               unregister_code(KC_DEL);
            }
            cur_pressed = false;
        }
        return false;
        break;

        default:
         if (record->event.pressed) {
             // reset the flag
             lower_pressed = false;
             raise_pressed = false;
             adj_pressed   = false;
             cur_pressed   = false;
         }
         break;
    }
    return true;
}

// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LT_SPLO:
//             return true;
//         case LT_BSRA:
//             return true;
//         case LT_ENAD:
//             return true;
//         case LT_DLCUR:
//             return true;
//         default:
//             return false;
//     }
// }
