#include QMK_KEYBOARD_H

#define LTNAV_ESC  LT(_NAV, KC_ESC)
#define LTNUM_BSPC  LT(_NUM, KC_BSPC)
#define LTSYM_DEL LT(_SYM, KC_DEL)

enum layer_names {
    _BASE,
    _NUM,
    _SYM,
    _NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
      KC_TAB,   KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,              KC_J,     KC_L,             KC_U,             KC_Y,             KC_SCLN,       KC_BSPC,
      KC_ESC,   LCTL_T(KC_A),   LALT_T(KC_R),   LSFT_T(KC_S),   LGUI_T(KC_T),   KC_D,              KC_H,     RGUI_T(KC_N),     RSFT_T(KC_E),     LALT_T(KC_I),     RCTL_T(KC_O),  KC_TAB,
      KC_LCTL,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,              KC_K,     KC_M,             KC_COMM,          KC_DOT,           KC_SLSH,       KC_QUOTE,
                                              KC_UNDS,   LTNAV_ESC,    KC_SPC,   LTNUM_BSPC, LTSYM_DEL
    ),

    [_NUM] = LAYOUT(
        _______,  _______,  KC_7,     KC_8,     KC_9,     _______,            _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  KC_4,     KC_5,     KC_6,     _______,            _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  KC_1,     KC_2,     KC_3,     _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                                _______,  KC_0,     _______,  _______,  _______
    ),

    [_SYM] = LAYOUT(
        _______,  KC_GRV ,  KC_LABK,  KC_RABK,  KC_MINS,  KC_PIPE,            KC_CIRC,  KC_LCBR,  KC_RCBR,  KC_DLR,  _______,  _______,
        KC_BSLS,  KC_EXLM,  KC_ASTR,  KC_SLSH,  KC_EQL,  KC_AMPR,             KC_HASH,  KC_LPRN,  KC_RPRN,  KC_SCLN, KC_DQUO,  _______,
        _______,  KC_TILD,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PERC,            KC_AT  ,  KC_COLON, KC_COMM,  KC_DOT,  KC_QUOT,  _______,
                                                _______,  _______,  _______,  _______,  _______
    ),

    [_NAV] = LAYOUT(
        _______,  RGB_TOG,  _______,  _______,  _______,  _______,            _______,  _______,  KC_UP,    _______,  _______,  _______,
        QK_BOOT,  RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,  _______,            _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, _______,  _______,
        QK_RBT,   RGB_HUD,  RGB_SAD,  RGB_VAD,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                                _______,  _______,  KC_ENT,  _______,  _______
        )
  };

  const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',      'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',      'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',      'R', 'R', 'R', 'R', 'R', 'R',
                            '*', '*', '*', '*', '*'
    );
