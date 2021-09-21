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

#define KC_CAD LCTL(LALT(KC_DEL))  // Ctrl+Alt+Del

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _CURSOL
};

enum custom_keycodes {
    M_HNZN_TGL = SAFE_RANGE,    // IMEトグル用
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,                       KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     M_HNZN_TGL,
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,                       KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,                       KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  LT(4, KC_DEL),
                            LWIN_T(KC_ESC),     LT(1, KC_SPC),    LT(3, KC_ENT),  LT(2, KC_BSPC),    ALT_T(KC_APP)
  ),

  [_LOWER] = LAYOUT_reviung41(
    A(KC_TAB),  KC_EXLM,     KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,                KC_P7,    KC_P8,    KC_P9,  KC_PPLS,  KC_PMNS,  KC_PAST,
    S(KC_LGUI),      KC_UNDS,     KC_PIPE,  KC_UP,    KC_LCBR,   KC_RCBR,                KC_P4,    KC_P5,    KC_P6,  KC_HOME,  KC_UP,    KC_END,
    KC_LSFT,         C(KC_PGUP),  KC_LEFT,  KC_DOWN,  KC_RGHT,   C(KC_PGDN),             KC_P1,    KC_P2,    KC_P3,  KC_LEFT,  KC_DOWN,  KC_RGHT,
                                                         KC_LGUI,   _______,  KC_BSPC,   KC_P0,    KC_PDOT
  ),

  [_RAISE] = LAYOUT_reviung41(
    _______,  KC_1,      KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     LCA(KC_DEL),
    _______,  KC_MINS,   KC_EQL,   KC_BSLS,  KC_LBRC,   KC_RBRC,            KC_PGUP,  KC_UNDS,  KC_UP,    KC_LPRN,  KC_RPRN,  KC_RO,
    _______,  KC_CIRC,   KC_AMPR,  KC_ASTR,  KC_LPRN,   KC_RPRN,            KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  A(KC_F4), KC_CALCULATOR,
                                             _______,   _______,  KC_ENT,  _______,  _______
  ),

  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  KC_MINS,  KC_UNDS,  KC_UNDS, KC_PLUS,   KC_F1,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, KC_F7,     KC_F8,              KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_GRAVE,  RESET,
    _______,   KC_F6,   KC_F5,    KC_F4,    KC_F3,     KC_F2,              KC_LEFT,  KC_RGHT,  KC_UP,    KC_DOWN, KC_EQL,    XXXXXXX,
                                            _______,   _______,  _______,  _______,  _______
  ),

  [_CURSOL] = LAYOUT_reviung41(
    _______,   _______, _______,  _______,  XXXXXXX,   _______,            XXXXXXX,  XXXXXXX,  S(KC_HOME),  XXXXXXX,  S(KC_END),  KC_PGUP,
    _______,   _______, _______,  _______, XXXXXXX,    XXXXXXX,            XXXXXXX,  XXXXXXX,  KC_HOME,     KC_UP,    KC_END,     KC_PGDN,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            _______,  XXXXXXX,  KC_LEFT,     KC_DOWN,  KC_RGHT,    _______,
                                            _______,   _______,  _______,  _______,  _______
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode){
        case M_HNZN_TGL:
         if (record->event.pressed) {
             SEND_STRING(SS_LALT("`"));
         } else {
             break;
         }
         break;
    }
    return true;
}
