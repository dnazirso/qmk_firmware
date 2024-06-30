#include <stdint.h>
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _AZERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    // CL_ keycodes are here for charaters that need capslock on to be inputed.
    CL_AGRV = SAFE_RANGE, // À
    CL_EACU,              // É
    CL_EGRV,              // È
    UC_PI,                // π
    UC_ELIP               // …
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * AZERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   Z  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  ^   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  %   |   Q  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   M  |  $   |
     * |------+------+------+------+------+------|       |    |  Del  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   ,  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `-----------------------------------'           '------''---------------------------'
     */

    [_AZERTY] = LAYOUT(
        /**/ KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, /*                                    */ KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,        //
        /**/ KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, /*                                    */ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,        //
        /**/ S(KC_QUOT), KC_A, KC_S, KC_D, KC_F, KC_G, /*                                */ KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_RBRC,     //
        /**/ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX, /*                 */ KC_DEL, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, //
        /*              */ KC_LGUI, KC_LALT, KC_LCTL, MO(_LOWER), KC_SPC, /*    */ KC_ENT, MO(_RAISE), KC_RCTL, KC_RALT, KC_RGUI          //
        ),

    /*---------------------------------------------------------------------------------------------------------*/

    /* LOWER
     * ,-----------------------------------------.                     ,-----------------------------------------.
     * | Esc  |   À  |   È  |   É  |   @  |   ù  |                     |   £  |   $  |   €  |   ²  |   °  |      |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * | Tab  |   <  |   >  |   (  |   )  |      |                     |      |   /  |   \  |   |  |   _  |      |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * | Caps |   [  |   ]  |   {  |   }  |      |-------.     ,-------|      |   +  |   -  |   *  |   =  |      |
     * |------+------+------+------+------+------|       |     |       |------+------+------+------+------+------|
     * | Shift|   ·  |   `  |   '  |   "  |      |-------|     |-------|      |   ?  |   .  |   #  |   ¤  | Shift|
     * `-----------------------------------------/       /      \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Enter  /        \Space \  |RAISE | RCTR | RAlt | HYPER|
     *            |      |      |      |      |/       /          \      \ |      |      |      |      |
     *            `-----------------------------------'            '------''--------------------------'
     */

    [_LOWER] = LAYOUT(
        /**/ _______, CL_AGRV, CL_EGRV, CL_EACU, ALGR(KC_0), KC_QUOTE, /*                                               */ S(KC_RBRC), KC_RBRC, ALGR(KC_E), KC_GRV, S(KC_MINS), _______,     //
        /**/ _______, KC_NUBS, S(KC_NUBS), KC_5, KC_MINS, _______, /*                                                   */ _______, S(KC_DOT), ALGR(KC_8), ALGR(KC_6), KC_8, _______,        //
        /**/ KC_CAPS, ALGR(KC_5), ALGR(KC_MINS), ALGR(KC_4), ALGR(KC_EQL), _______, /*                                  */ _______, S(KC_EQL), KC_6, KC_NUHS, KC_EQL, _______,               //
        /**/ KC_LSFT, ALGR(KC_COMM), KC_4, ALGR(KC_7), KC_3, _______, _______, /*                              */ _______, _______, S(KC_M), S(KC_COMM), ALGR(KC_3), ALGR(KC_RBRC), KC_RSFT, //
        /*                  */ KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX, _______, /*                                 */ _______, MO(_ADJUST), KC_RCTL, KC_RALT, KC_RGUI                            //
        ),

    /*---------------------------------------------------------------------------------------------------------*/

    /* RAISE
     * ,----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  | Ins  | Pscr | Menu |      |      |                    | PgUp |      |  Up  |      |      | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|PgDown| Left | Down | Rigth|  Del |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      |      |      |      |      | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |ADJUST| /Space  /       \Enter \  |      | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [_RAISE] = LAYOUT(
        /**/ _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, /*                                         */ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,            //
        /**/ _______, KC_INS, KC_PSCR, KC_APP, XXXXXXX, XXXXXXX, /*                                 */ KC_PGUP, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, KC_F12,     //
        /**/ _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*                               */ KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, _______,   //
        /**/ _______, KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX, _______, /*              */ _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, //
        /*              */ KC_LGUI, KC_LALT, KC_LCTL, MO(_ADJUST), KC_SPC, /*               */ KC_ENT, XXXXXXX, KC_RCTL, KC_RALT, KC_RGUI                     //
        ),

    /*---------------------------------------------------------------------------------------------------------*/

    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_ADJUST] = LAYOUT(
        /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*                        */ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  //
        /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*                        */ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  //
        /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*                        */ XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,  //
        /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*       */ XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, //
        /*                  */ _______, _______, _______, _______, _______, /*       */ _______, _______, _______, _______, _______                    //
        )                                                                                                                                              //
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("UNIX"), false);
    oled_write_ln_P(PSTR("\n"), false);

    switch (get_highest_layer(default_layer_state)) {
        case _AZERTY:
            oled_write_ln_P(PSTR("Azert"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }

    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _AZERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

// Custom keycode handling.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // handling this once instead of in each keycode uses less program memory.
    if (record->event.pressed) {
        switch (keycode) {
            case CL_AGRV:
                // capsLockOn à capsLockOff
                SEND_STRING(SS_TAP(X_CAPS) "0" SS_TAP(X_CAPS));
                break;
            case CL_EACU:
                // capsLockOn é capsLockOff
                SEND_STRING(SS_TAP(X_CAPS) "2" SS_TAP(X_CAPS));
                break;
            case CL_EGRV:
                // capsLockOn è capsLockOff
                SEND_STRING(SS_TAP(X_CAPS) "7" SS_TAP(X_CAPS));
                break;
            case UC_PI:
                // Ctrl+Shift+u 3CO Enter
                tap_code16(LCTL(LSFT(KC_U)));
                tap_code16(S(KC_3));
                tap_code16(KC_C);
                tap_code16(S(KC_0));
                tap_code16(KC_ENT);
                break;
            case UC_ELIP:
                // Ctrl+Shift+u 2026 Enter
                tap_code16(LCTL(LSFT(KC_U)));
                tap_code16(S(KC_2));
                tap_code16(S(KC_0));
                tap_code16(S(KC_2));
                tap_code16(S(KC_6));
                tap_code16(KC_ENT);
                break;
        }
    }
    // this uses less memory than returning in each case.
    return keycode < SAFE_RANGE;
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_MS_WH_RIGHT);
        } else {
            tap_code(KC_MS_WH_LEFT);
        }
    }

    if (index == 1) {
        if (clockwise) {
            tap_code(KC_MS_WH_UP);
        } else {
            tap_code(KC_MS_WH_DOWN);
        }
    }

    // avoid volume change default behavior
    return false;
}

#endif
