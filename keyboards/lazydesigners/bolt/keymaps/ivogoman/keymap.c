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

#define LTNAV_BSPC LT(4, KC_BSPC)
#define LTSYM_SPC LT(2, KC_SPC)
#define LTNUM_TAB LT(1, KC_TAB)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
               KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOTE,    KC_BSPC,
               KC_ESC,  LCTL_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LGUI_T(KC_T),  KC_D,  KC_H,    RGUI_T(KC_N),     RSFT_T(KC_E), LALT_T(KC_I), RCTL_T(KC_O), KC_ENT,
               KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH,  KC_UP,
               KC_LCTL,  KC_LALT,                   KC_ESC, LTNAV_BSPC,          LTSYM_SPC, LTNUM_TAB,                 KC_LEFT, KC_DOWN, KC_RGHT
             ),
    // [0] = LAYOUT(
    //            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    //            QK_GESC,  LCTL_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LGUI_T(KC_F),  KC_G,       KC_H,    RGUI_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOTE,
    //            KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLASH,
    //            KC_LCTL,  KC_LALT,                   KC_ESC, LTNAV_ENT,          LTSYM_SPC, LTNUM_DEL,                 KC_LEFT, KC_DOWN, KC_RGHT
    //          ),  
    [1] = LAYOUT(
               QK_BOOT,    KC_LBRC, KC_7,   KC_8,    KC_9,    KC_RBRC,               KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,
               EE_CLR,     KC_SCLN, KC_4,    KC_5,   KC_6,    KC_EQL,                KC_NO,    KC_LSFT,   KC_LGUI,   KC_LALT, KC_LCTL, KC_BSLS,
               KC_NO,      KC_GRV,  KC_1,    KC_2,   KC_3,    KC_BSLS,     KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,
               KC_VOLD,    KC_DOT,                   KC_0,    KC_MINS,     KC_NO,    KC_NO,                KC_NO,   KC_NO,  KC_NO
             ),
    [2] = LAYOUT(
               RGB_TOG,   KC_LCBR, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RCBR,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
               RGB_VAI,   KC_COLN, KC_DLR,   KC_PERC, KC_CIRC, KC_PLUS,                   KC_NO,   KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, KC_NO,
               RGB_VAD,   KC_TILD, KC_EXLM,  KC_AT,   KC_HASH, KC_PIPE,            KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_HUI,  RGB_SAI,
               KC_NO,     KC_UNDS,                    KC_RPRN, KC_UNDS,            KC_NO, KC_NO,                     KC_NO,   RGB_HUD,  RGB_SAD
             ),
    [3] = LAYOUT(
               QK_BOOT,  KC_F12,   KC_F7,   KC_F8,   KC_F9,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
               KC_NO,    KC_F11,   KC_F4,   KC_F5,   KC_F3,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
               KC_NO,    KC_F10,   KC_F1,   KC_F2,   KC_F3,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
               KC_NO,    KC_NO,                      KC_NO,   KC_NO,            KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO
             ),
    [4] = LAYOUT(
               QK_BOOT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,                     KC_AGIN,   KC_PSTE,   KC_COPY,   KC_CUT,   KC_UNDO,    KC_NO,
               KC_NO,    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,  KC_NO,                     KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_NO,
               KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
               KC_NO,    KC_NO,                      KC_NO,   KC_NO,            KC_ENT,   KC_NO,                     KC_NO,   KC_NO,    KC_NO
             )
};


#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_GREEN);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif
