#include QMK_KEYBOARD_H

enum custom_keycodes { MUTEMIC = SAFE_RANGE, LOCK, };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MUTEMIC:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING(SS_LGUI(SS_LSFT("m")));
            }
            break;
        case LOCK:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING(SS_LGUI(SS_LCTL("q")));
            }
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * ,-----------------------,
     * |  7  |  8  |  9  |  /  |
     * |-----+-----+-----+-----|
     * |  4  |  5  |  6  |  *  |
     * |-----+-----+-----+-----|
     * |  1  |  2  |  3  |  -  |
     * |-----+-----+-----+-----|
     * |  0  |  .  |  =  |  +  |
     * `-----------------------'
     */
    LAYOUT_ortho_4x4(
         KC_AUDIO_MUTE, KC_SYSTEM_SLEEP, LOCK, KC_PSLS,
         KC_MEDIA_PREV_TRACK, KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK,
         MUTEMIC, KC_P2, KC_P3, KC_PMNS,
         KC_F5, KC_F6, KC_F7, KC_F8)

};

// Set led state during powerup
void keyboard_post_init_user(void) { writePinHigh(LED_RED); }

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {  // First encoder - top left
        if (clockwise) {
            tap_code(KC_AUDIO_VOL_DOWN);
        } else {
            tap_code(KC_AUDIO_VOL_UP);
        }
    } else if (index == 1) {  // Second encoder - top right
        if (clockwise) {
           tap_code16(G(KC_Z));
        } else {
            tap_code16(G(S(KC_Z)));
        }
    }
}
