#include QMK_KEYBOARD_H

enum layers{
  _BASE_CMK,
  _NUM_NAV,
  _SYM_BRC,
  _ALT,
  _BASE,
};
enum combo_events {
  COMBO_BSPC,
  COMBO_NUMDEL,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
  COMBO_BSPC_ALT,
  COMBO_ESC_ALT,
  COMBO_ENT_ALT,
};

#define KC_NUM_BSPC LT(_NUM_NAV, KC_BSPC)
#define KC_SYM_SPC LT(_SYM_BRC, KC_SPC)
#define KC_CA LCTL_T(KC_A)
#define KC_AS LALT_T(KC_S)
#define KC_SD LSFT_T(KC_D)
#define KC_GF LGUI_T(KC_F)
#define KC_GJ RGUI_T(KC_J)
#define KC_SK RSFT_T(KC_K)
#define KC_AL RALT_T(KC_L)
#define KC_CENT RCTL_T(KC_ENT)

#define KC_AR LALT_T(KC_R)
#define KC_SS LSFT_T(KC_S)
#define KC_LGT LGUI_T(KC_T)
#define KC_GN RGUI_T(KC_N)
#define KC_SE RSFT_T(KC_E)
#define KC_AI RALT_T(KC_I)
#define KC_CO RCTL_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_space(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,     KC_P,
    KC_CA,  KC_AS,  KC_SD,  KC_GF,   KC_G,   KC_H,  KC_GJ,   KC_SK,  KC_AL, KC_CENT,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM, KC_DOT,
    KC_LCTL, KC_LALT, KC_LGUI, KC_NUM_BSPC, KC_SYM_SPC, KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_NUM_NAV] = LAYOUT_split_space(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAGE_UP, KC_PAGE_DOWN, KC_TRNS, KC_BSLS, KC_SLSH,
    RGB_TOG, RGB_MOD, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_SYM_BRC] = LAYOUT_split_space(
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQUAL, KC_MINS,
    KC_LCBR, KC_LBRC, KC_LPRN, KC_UNDS, KC_RPRN, KC_RBRC, KC_RCBR, KC_SCLN, KC_TRNS, KC_QUOTE,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    DF(_BASE), RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_ALT] = LAYOUT_split_space(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_BASE_CMK] = LAYOUT_split_space(
    KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,   KC_J,   KC_L,    KC_U,   KC_Y,  KC_SCLN,
    KC_CA,  KC_AR,  KC_SS,  KC_LGT,   KC_D,   KC_H,  KC_GN,   KC_SE,  KC_AI, KC_CO,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_K,   KC_M, KC_COMM, KC_DOT,
    KC_LCTL, KC_LALT, KC_LGUI, KC_NUM_BSPC, KC_SYM_SPC, KC_RALT, KC_RGUI, KC_RCTL
  ),
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_numdel[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo_bspc_alt[] = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_esc_alt[] = {KC_CA, KC_AR, COMBO_END};
const uint16_t PROGMEM combo_ent_alt[] = {KC_AI, KC_CO, COMBO_END};
combo_t key_combos[] = {
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_NUMDEL] = COMBO(combo_numdel,KC_DEL),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),
  [COMBO_BSPC_ALT] = COMBO(combo_bspc_alt,KC_BSPC),
  [COMBO_ESC_ALT] = COMBO(combo_esc_alt,KC_ESC),
  [COMBO_ENT_ALT] = COMBO(combo_ent_alt, KC_ENT),
};
#endif
