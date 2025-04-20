// Copyright 2024 Conor Burns (@Conor-Burns)
/* SPDX-License-Identifier: GPL-2.0-or-later */

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
  [_BASE] = LAYOUT_40(
              KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,               KC_Y,     KC_U,             KC_I,             KC_O,             KC_P,
    KC_TAB,  LCTL_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LGUI_T(KC_F),  KC_G,               KC_H,     RGUI_T(KC_J),     RSFT_T(KC_K),     LALT_T(KC_L),     RCTL_T(KC_SCLN),  KC_BSPC,
    KC_LCTL,   KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,              KC_N,     KC_M,             KC_COMM,          KC_DOT,           KC_SLSH,          KC_QUOTE,
                                  KC_UNDS,  LTNAV_ESC,   KC_ENT,                          LTNUM_SPC,   LTSYM_BSPC,    KC_DEL
  ),

  [_NUM] = LAYOUT_40(
              _______,  KC_7,     KC_8,     KC_9,     _______,            _______,  _______,  _______,  _______,  _______,
    _______,  _______,  KC_4,     KC_5,     KC_6,     _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  KC_1,     KC_2,     KC_3,     _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                   _______, KC_0,     _______,            _______,  _______,  _______
  ),

  [_SYM] = LAYOUT_40(
              KC_GRV ,  KC_LABK,  KC_RABK,  KC_MINS,  KC_PIPE,            KC_CIRC,  KC_LCBR,  KC_RCBR,  KC_DLR , _______,
    KC_BSLS,  KC_EXLM,  KC_ASTR,  KC_SLSH,  KC_EQL,  KC_AMPR,            KC_HASH,  KC_LPRN,  KC_RPRN,  KC_SCLN, KC_DQUO,  _______,
    _______,  KC_TILD,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PERC,            KC_AT  ,  KC_COLN,  KC_COMM,  KC_DOT , KC_QUOT,  _______,
                                  _______,  _______,  _______,            _______,  _______,  _______
  ),

  [_NAV] = LAYOUT_40(
              RGB_TOG,  _______,  _______,  _______,  _______,            _______,  _______,  KC_UP,    _______,  _______,
    QK_BOOT,  RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,  _______,            _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, _______,  _______,
    QK_RBT,   RGB_HUD,  RGB_SAD,  RGB_VAD,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                  _______,  _______,  _______,            _______,  _______,  _______
  )
};


const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_40(
             'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       'L', 'L', 'L',  'R', '*', 'R'
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
