/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

enum layer_number { _QWERTY = 0, _LOWER, _RAISE, _ADJUST };


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,---------------------------------.                   ,----------------------------------.
   * |  Q  |   W  |   E  |   R  |   T  |                   |   Y  |   U  |   I  |   O  |   P  |
   * |-----+------+------+------+------|                   |------+------+------+------+------|
   * |  A  |   S  |   D  |   F  |   G  |                   |   H  |   J  |   K  |   L  |  ;:  |
   * |-----+------+------+------+------|                   |------+------+------+------+------|
   * |  Z  |   X  |   C  |   V  |   B  |                   |   N  |   M  |  ,<  |  .>  |  /?  |
   * |-----+------+------+------+------+-------|    ,------+------+------+------+------+------|
   * | CMD | Opt  | ctrl |shift |LOWER |ADJUST |    | Bksp | RAISE|                    | Esc  |
   * |     |      |      | Eisu |Space | KANA  |    |      | Enter|                    |      |
   * `-----------------------------------------'    `-----------------------------------------'
   */
  [_QWERTY] = LAYOUT_universal(
        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                              KC_Y,   KC_U,     KC_I,   KC_O,   KC_P,
        KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                              KC_H,   KC_J,     KC_K,   KC_L, KC_SCLN,
        KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                                              KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH,
      KC_LGUI, KC_LALT,  KC_LCTL, LSFT_T(KC_LANG2),LT(1,KC_SPC),LT(3,KC_LANG1),    KC_BSPC, LT(2,KC_ENT),  _______,_______,_______, KC_ESC
  ),

  /* Lower
   * ,---------------------------------.                   ,----------------------------------.
   * |  !  |   @  |   #  |   $  |   %  |                   |   ^  |   &  |   *  |   (  |   )  |
   * |-----+------+------+------+------|                   |------+------+------+------+------|
   * |  F1 |  F2  |  F3  |  F4  |  F5  |                   |  F6  |  +   |   =  |   {  |   }  |
   * |-----+------+------+------+------|                   |------+------+------+------+------|
   * |  F7 |  F8  |  F9  |  F10 |  F11 |                   |  F12 |  |   |   '  |  "   |  :   |
   * |-----+------+------+------+------+-------|    ,------+------+------+------+------+------|
   * | CMD | Opt  | ctrl |shift |LOWER |ADJUST |    | TO   | TO   |                    |  ~   |
   * |     |      |      | Eisu |Space | KANA  |    |RAISE |QWERTY|                    |      |
   * `-----------------------------------------'    `-----------------------------------------'
   */
  [_LOWER] = LAYOUT_universal(
    S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                        S(KC_6),      S(KC_7),   S(KC_8),    S(KC_9),   S(KC_0),
     KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,    S(KC_EQL),    KC_EQL, S(KC_LBRC), S(KC_RBRC),
     KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,                         KC_F12,   S(KC_BSLS),   KC_QUOT,    KC_DQUO,   S(KC_SCLN),
    _______, _______, _______, _______, _______, _______,        TO(2),   TO(0),      _______,   _______,    _______,   S(KC_GRV)
  ),

  /* Raise
   * ,---------------------------------.                   ,------------------------------------.
   * | Tab |   1  |   2  |   3  |   -  |                   |   \  | MOUSE2 | PgUp | PgDn | Del  |
   * |-----+------+------+------+------|                   |------+--------+------+------+------|
   * |  \  |   4  |   5  |   6  |   _  |                   |   :  | MOUSE1 |  UP  |   [  |   ]  |
   * |-----+------+------+------+------|                   |------+--------+------+------+------|
   * |  `  |   7  |   8  |   9  |   0  |                   |   |  | LEFT   | DOWN | RIGHT|  ;   |
   * |-----+------+------+------+------+-------|    ,------+------+--------+------+------+------|
   * | CMD | Opt  | ctrl |shift |LOWER |ADJUST |    | TO   |RAISE |                      |  =   |
   * |     |      |      | Eisu |Space | KANA  |    |LOWER |      |                      |      |
   * `-----------------------------------------'    `-------------------------------------------'
   */
  [_RAISE] = LAYOUT_universal(
    KC_TAB,     KC_1,    KC_2,     KC_3,    KC_MINS,                          KC_NUHS, KC_BTN2,   KC_PGUP,  KC_PGDN, KC_DEL,
   KC_BSLS,     KC_4,    KC_5,     KC_6, S(KC_MINS),                       S(KC_SCLN), KC_BTN1,     KC_UP,  KC_LBRC, KC_RBRC,
    KC_GRV,     KC_7,    KC_8,     KC_9,       KC_0,                       S(KC_NUHS), KC_LEFT,   KC_DOWN,  KC_RGHT, _______,
    _______, _______, _______, _______,     _______, _______,        TO(1),  _______ , _______ , _______ , _______ , KC_EQL
  ),

  [_ADJUST] = LAYOUT_universal(
    RGB_TOG  , _______  , _______  , _______  , _______  ,                            RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            RGB_M_K  , RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    RESET    , KBC_RST  , _______  , _______  , _______  , _______  ,      _______ ,  _______  , _______  , _______  , KBC_RST  , RESET
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
}
#endif
