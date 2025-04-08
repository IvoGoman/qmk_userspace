// Copyright 2024 Conor Burns (@Conor-Burns)
/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

#define LTNUM_ESC LT(_NUM, KC_ESC)
#define LTSYM_DEL LT(_SYM, KC_DEL)

enum layer_names {
    _BASE,
    _NUM,
    _SYM,
    _NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_40(
              KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,               KC_Y,     KC_U,             KC_I,             KC_O,             KC_P,
    KC_LCTL,  LCTL_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LGUI_T(KC_F),  KC_G,               KC_H,     RGUI_T(KC_J),     RSFT_T(KC_K),     LALT_T(KC_L),     RCTL_T(KC_SCLN),  KC_QUOT,
    KC_TAB,   KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,               KC_N,     KC_M,             KC_COMM,          KC_DOT,           KC_SLSH,          KC_BSPC,
                                  KC_LSFT,  LTNUM_ESC,   KC_ENT,                             KC_SPC,   LTSYM_DEL,    KC_RSFT
  ),

  [_NUM] = LAYOUT_40(
              KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    _______,  _______,  KC_LEFT,  KC_RIGHT, KC_UP,    KC_LBRC,            KC_RBRC,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  KC_DOWN,  KC_LCBR,            KC_RCBR,  _______,  _______,  _______,  _______,  _______,
                                  _______,  _______,  _______,            _______,  _______,  _______
  ),

  [_SYM] = LAYOUT_40(
    KC_EXLM,       KC_AT,     KC_HASH,      KC_DLR,     KC_PERC,          KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
    _______,  _______,  KC_LEFT,     KC_RIGHT,      KC_UP,      KC_EQL,            KC_MINS,  KC_BSLS,  _______,  _______,  KC_GRV,   KC_GRV,
    _______,  _______,  _______,  _______,  KC_DOWN,     KC_PLUS,            KC_UNDS,  KC_PIPE,  _______,  _______,  KC_TILD, KC_TILD,
                                  _______,  _______,  _______,            _______,  _______,  _______
  ),

  [_NAV] = LAYOUT_40(
              _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                  _______,  _______,  _______,            _______,  _______,  _______
  )
};


const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_40(
             'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       'L', 'L', 'L',  'R', 'R', 'R'
    );

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUM] =  { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_SYM] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_NAV] = { ENCODER_CCW_CW(KC_RGHT, KC_LEFT) }
};

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if(active) { tap_code(KC_MPLY); } else {  }
            break;
    }
    return true;
}
