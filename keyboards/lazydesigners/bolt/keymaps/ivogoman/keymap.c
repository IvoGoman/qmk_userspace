/* Copyright 2020 LAZYDESIGNERS
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

#define LTNAV_ESC  LT(_NAV, KC_ESC)
#define LTNUM_SPC  LT(_NUM, KC_SPC)
#define LTSYM_BSPC LT(_SYM, KC_BSPC)

enum layer_names {
    _BASE,
    _NUM,
    _SYM,
    _NAV
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
               KC_TAB,   KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,       KC_J,    KC_L,          KC_U,           KC_Y,           KC_QUOTE,       KC_BSPC,
               KC_ESC,   LCTL_T(KC_A),   LALT_T(KC_R),   LSFT_T(KC_S),   LGUI_T(KC_T),   KC_D,       KC_H,    RGUI_T(KC_N),  RSFT_T(KC_E),   LALT_T(KC_I),   RCTL_T(KC_O),   KC_ENT,
               KC_LSFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,       KC_B,    KC_K,          KC_M,           KC_COMM,        KC_DOT,  KC_SLASH,  KC_UP,
               KC_LCTL,  KC_UNDS,                   LTNAV_ESC, KC_ENT,                             LTNUM_SPC, LTSYM_BSPC,                                     KC_LEFT, KC_DOWN, KC_RGHT
             ),
    // [0] = LAYOUT(
    //            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    //            QK_GESC,  LCTL_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LGUI_T(KC_F),  KC_G,       KC_H,    RGUI_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOTE,
    //            KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLASH,
    //            KC_LCTL,  KC_LALT,                   KC_ESC, LTNAV_ENT,          LTSYM_SPC, LTNUM_DEL,                 KC_LEFT, KC_DOWN, KC_RGHT
    //          ),
    [_NUM] = LAYOUT(
               KC_NO,    KC_NO, KC_7,    KC_8,   KC_9,    KC_NO,             KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,
               KC_NO,    KC_NO, KC_4,    KC_5,   KC_6,    KC_NO,             KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,
               KC_NO,    KC_NO, KC_1,    KC_2,   KC_3,    KC_NO,             KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,
               KC_NO,    KC_NO,                  KC_NO, KC_0,                KC_NO,    KC_NO,                KC_NO,   KC_NO,  KC_NO
             ),
    [_SYM] = LAYOUT(
               _______,   KC_GRV ,  KC_LABK,  KC_RABK,  KC_MINS,  KC_PIPE,            KC_CIRC,  KC_LCBR,  KC_RCBR,  KC_DLR ,  KC_NO,    KC_NO,
               _______,   KC_EXLM,  KC_ASTR,  KC_SLSH,  KC_EQL,   KC_AMPR,            KC_HASH,  KC_LPRN,  KC_RPRN,  KC_SCLN,  KC_DQUO,  KC_NO,
               _______,   KC_TILD,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PERC,            KC_AT,    KC_COLON, KC_COMM,  KC_DOT ,  KC_QUOT,  KC_NO, KC_NO,
               KC_NO,     KC_UNDS,                    _______, _______,               KC_NO, KC_NO,                     KC_NO,   KC_NO,  KC_NO
             ),
    [_NAV] = LAYOUT(
               _______,  RGB_TOG,  _______,  _______,  _______,  _______,             KC_NO,   KC_NO,   KC_UP,   KC_NO,     KC_NO,   KC_NO,
               QK_BOOT,  RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,  _______,             KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT,  KC_NO,   KC_NO,
               QK_RBT,   RGB_HUD,  RGB_SAD,  RGB_VAD,  _______,  _______,             KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,
               KC_NO,    KC_NO,                      KC_NO,   KC_NO,                  KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO
             )
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L',           '*', '*',  '*', '*',      'R', 'R', 'R'
    );


#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_GREEN);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif
