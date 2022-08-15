#include QMK_KEYBOARD_H

#define ______ KC_TRNS

#define KC_CAD LCTL(LALT(KC_DEL))  // Ctrl+Alt+Del 


enum layer_number {
  _QWERTY = 0,
  _NUMPAD,
  _LOWER,
  _RAISE,
  _ADJUST,
};


enum custom_keycodes {
    M_HNZN_TGL = SAFE_RANGE    // IMEトグル用
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode){
        case M_HNZN_TGL:
          if (record->event.pressed){
              SEND_STRING(SS_LALT("`"));
          } else {

          }
          break;
    }
    return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | BS | 全/半|
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RSh |  U  |MO(1)|
   * |-----------------------------------------------------------------------------------------+
   * | LT(1)|  Win  |  Alt  |  Space  |LT(2,ENT)|  BackSpace(2) | Menu |RCtrl|  L  |  D  |  R  |
   * `-----------------------------------------------------------------------------------------'
   */

  [_QWERTY] = LAYOUT_directional(
      KC_GESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, M_HNZN_TGL,
      KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,
      KC_LCTL,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,  KC_ENT,
      KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,  KC_UP,  LT(_LOWER,KC_DEL),
      LT(_NUMPAD,KC_GRV),  MT(MOD_LGUI,KC_APP), KC_LALT,  KC_SPC, LT(_RAISE,KC_ENT), LT(_RAISE,KC_BSPC), KC_APP, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
     /* KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, ______, KC_BSPC, */
     /* KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, */
     /* KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, */
     /* KC_LSFT,         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL, */
     /* KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, MO(1), KC_LEFT, KC_DOWN, KC_RIGHT */
      ),

  /* FN Layer
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |           |
   * |-----------------------------------------------------------------------------------------+
   * |        |     |     |     |     |     |     |  7  |  8  |  9  |     |  ↑  |     |        |
   * |-----------------------------------------------------------------------------------------+
   * |         |     |  F2  |  F3  |  F4  |  F5  |    |  4  |  5  |  6  |  ←  |  →  |          |
   * |-----------------------------------------------------------------------------------------+
   * |        |  F6 |  F7 |  F8  |  F9  |  F10  |    |  1  |  2  |  3  | ↓ |    |  PgUp  |     |
   * |-----------------------------------------------------------------------------------------+
   * |      |  Win  |  Alt  |  Space  |         |       |   0   | .  |  Home  |  Pgdn  |  End  |
   * `-----------------------------------------------------------------------------------------'
   */
  [_NUMPAD] = LAYOUT_directional(
      KC_GRV, KC_F1,      KC_F2,      KC_F3,       KC_F4,     KC_F5,       KC_F6,   KC_F7,    KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12, ______, RESET,
      KC_CAD, KC_F2,      KC_F3,      KC_F4,       KC_F5,     KC_F6,       ______,  KC_P7,    KC_P8,    KC_P9,   KC_PMNS, KC_PSLS, KC_PSLS, KC_PAST,
      ______, KC_F7,      KC_F8,      KC_F9,       KC_F10,    ______,      KC_PSLS, KC_P4,    KC_P5,    KC_P6,   KC_PPLS,  KC_PAST, ______,
      ______, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C),  LCTL(KC_V), LCTL(KC_B), KC_P0,   KC_P1,    KC_P2,    KC_P3,   KC_PEQL, ______,  KC_PGUP, ______,
      MO(_NUMPAD), KC_APP,      ______,    KC_RO,       MO(_RAISE),    ______,                         KC_P0,   KC_PDOT,           KC_HOME, KC_PGDN, KC_END
      ),

  [_LOWER] = LAYOUT_directional(
      KC_GRV, KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,   KC_F12,  ______,  RESET,
      KC_CAD, KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,       ______,  KC_P7,   KC_P8,   KC_P9,  KC_PPLS, KC_UP,    KC_PMNS, KC_PAST,
      ______, KC_F7,      KC_F8,      KC_F9,      KC_F10,     ______,      KC_PSLS, KC_P4,   KC_P5,   KC_P6,  KC_LEFT, KC_RIGHT, KC_PEQL,
      ______, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_B),  KC_P0,   KC_P1,   KC_P2,   KC_P3,  KC_DOWN, ______,   KC_PGUP, ______,
      ______, KC_APP,  ______,  KC_RO,  ______,  ______,                                              KC_P0,  KC_PDOT, KC_HOME,  KC_PGDN,  KC_END
      ),
/*   LAYOUT_directional(
      KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, ______, RESET,
      KC_CAD, ______, ______, ______, ______, ______, ______, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_UP, KC_PMNS, KC_PAST,
      ______, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_PSLS, KC_P4, KC_P5, KC_P6, KC_LEFT, KC_RIGHT,KC_PEQL,
      ______,  KC_F7, KC_F8, KC_F9, KC_F10, ______, KC_P0, KC_P1, KC_P2, KC_P3, KC_DOWN, ______, KC_PGUP, ______,
      ______, KC_APP,  ______,  KC_RO,  ______,  ______,  KC_P0,  KC_PDOT,  KC_HOME,  KC_PGDN,  KC_END
      ),
 */
  /* FN Layer
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |   RESET   |
   * |-----------------------------------------------------------------------------------------+
   * |        |RBB T|RGB M| Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |     |      |      |      |
   * |-----------------------------------------------------------------------------------------+
   * |         | BL T| BL M| BL+ | BL- |     |     |     |     |     |     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |     |     |     |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     |      |     |     |     |
   * `-----------------------------------------------------------------------------------------'
   */
 [_RAISE] = LAYOUT_directional(
      KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, ______, RESET,
      KC_CAD, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, KC_UP, ______, ______,
      ______, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, ______, ______, KC_LEFT, KC_RIGHT,______,
      ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, KC_PGUP, ______,
      ______, KC_APP,  ______,  KC_RO,  ______,  ______,  ______,  ______,  KC_HOME,  KC_PGDN,  KC_END
      ),


  [_ADJUST] = LAYOUT_directional(
      KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_TRNS, RESET,
      ______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ______, ______, ______, ______, ______,
      ______, ______, ______, ______, KC_F7, ______, ______, KC_F10, ______, ______, ______, ______,
      ______, BL_TOGG, BL_STEP, BL_INC, BL_DEC, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
      ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______
      ),
};


layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _RAISE, _NUMPAD, _ADJUST);
  return state;
}