// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// Copyright 2026 Blockmann2K
// SPDX-License-Identifier: GPL-2.0-or-later

/*
 * Automail - The Mechanical Armor
 *
 * This Keymap Is Designed for the Lotus 58 Glow Keyboard and Features a Custom Layout Based on the Colemak-DH Mod, With Tap Dance Integration For German Umlauts (Ä, Ö, Ü) and Eszett (ß).
 *
 * Operating System Requirement:
 * - Requires the Host Operating System Input Layout To Be Set to EurKEY (Or a Compatible AltGr Layout) For the Tap Dance Umlaut and Eszett Shortcuts To Function Properly.
 *
 * Features:
 * - Custom Layout Based on the Colemak-DH Mod With Tap Dance for German Special Characters.
 * - Dedicated Navigation, Symbol, System, and Fallback (QWERTY) Layers.
 * - Rotary Encoder Mapping for Volume Control.
 * - OLED Display Featuring a 32x32 Pixel Art, Indicating Active Layers, Caps Lock State, and Auto-Shift State.
 */

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------

// Base QMK Header
#include QMK_KEYBOARD_H

//-----------------------------------------------------------------------------
// Keymap
//-----------------------------------------------------------------------------

// ==> Tap Dance <==
// Declarations
enum {
    TD_A_AE,     // Tap: a | Double-Tap: ä (AltGr + a)
    TD_O_OE,     // Tap: o | Double-Tap: ö (AltGr + o)
    TD_U_UE,     // Tap: u | Double-Tap: ü (AltGr + u)
    TD_S_SS,     // Tap: s | Double-Tap: ß (AltGr + s)
};

// Custom Callback Functions
void td_a_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            tap_code16(KC_A);
        } else {
            tap_code16(S(KC_A));
        }
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) {
            tap_code16(RALT(KC_A));
        } else {
            tap_code16(S(RALT(KC_A)));
        }
    }
}

void td_o_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            tap_code16(KC_O);
        } else {
            tap_code16(S(KC_O));
        }
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) {
            tap_code16(RALT(KC_O));
        } else {
            tap_code16(S(RALT(KC_O)));
        }
    }
}

void td_u_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            tap_code16(KC_U);
        } else {
            tap_code16(S(KC_U));
        }
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) {
            tap_code16(RALT(KC_U));
        } else {
            tap_code16(S(RALT(KC_U)));
        }
    }
}

void td_s_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            tap_code16(KC_S);
        } else {
            tap_code16(S(KC_S));
        }
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) {
            tap_code16(RALT(KC_S));
        } else {
            tap_code16(S(RALT(KC_S)));
        }
    }
}

// Definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_A_AE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_a_finished, NULL),
    [TD_O_OE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_o_finished, NULL),
    [TD_U_UE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_u_finished, NULL),
    [TD_S_SS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_s_finished, NULL),
};

// ==> Matrix <==
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0 - Base
    [0] = LAYOUT(
        // First Row
        QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO, KC_MPLY, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,

        // Second Row
        KC_CAPS, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, TD(TD_U_UE), KC_Y, KC_SCLN, KC_INS,

        // Third Row
        KC_LSFT, TD(TD_A_AE), KC_R, TD(TD_S_SS), KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, TD(TD_O_OE), KC_HOME,

        // Fourth Row
        KC_LCTL, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_MPRV, KC_MNXT, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_PGUP,

        // Fifth Row
        KC_LGUI, KC_LALT, KC_SPC, KC_BSPC, KC_ENT, MO(1), MO(2), TG(4)
    ),

    // Layer 1 - Navigation
    [1] = LAYOUT(
        // First Row
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO, KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,

        // Second Row
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,

        // Third Row
        KC_RSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_END,

        // Fourth Row
        KC_RCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN,

        // Fifth Row
        KC_RGUI, KC_RALT, KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO
    ),

    // Layer 2 - Symbols
    [2] = LAYOUT(
        // First Row
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MO(3), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        // Second Row
        KC_NO, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, KC_PIPE, KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR, KC_UNDS, KC_NO,

        // Third Row
        KC_NO, KC_EXLM, KC_LT, KC_GT, KC_PEQL, KC_AMPR, KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_QUOT, KC_NO,

        // Fourth Row
        KC_NO, KC_GRV, KC_TILD, KC_LBRC, KC_RBRC, KC_PERC, KC_NO, KC_NO, KC_AT, KC_QUES, KC_COMM, KC_DOT, KC_BSLS, KC_NO,

        // Fifth Row
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO
    ),

    // Layer 3 - System
    [3] = LAYOUT(
        // First Row
        QK_BOOT, KC_NO, KC_NO, KC_NO, NK_TOGG, AC_TOGG, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, UG_NEXT, UG_SATU, UG_TOGG,

        // Second Row
        QK_RBT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, UG_PREV, UG_SATD, RGB_M_P,

        // Third Row
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, UG_HUEU, UG_VALU, RGB_M_B,

        // Fourth Row
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, UG_HUED, UG_VALD, RGB_M_R,

        // Fifth Row
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    // Layer 4 - Fallback
    [4] = LAYOUT(
        // First Row
        QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO, KC_MPLY, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,

        // Second Row
        KC_CAPS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,

        // Third Row
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,

        // Fourth Row
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MPRV, KC_MNXT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,

        // Fifth Row
        KC_LGUI, KC_LALT, KC_SPC, KC_BSPC, KC_ENT, KC_NO, KC_NO, KC_TRNS
    )
};

//-----------------------------------------------------------------------------
// Encoder
//-----------------------------------------------------------------------------

#ifdef ENCODER_MAP_ENABLE

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_NO, KC_NO)    , ENCODER_CCW_CW(KC_NO, KC_NO)     },
    [4] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};

#endif

//-----------------------------------------------------------------------------
// OLED Display
//-----------------------------------------------------------------------------

#ifdef OLED_ENABLE

// Add Custom Image
static void print_custom_image(void) {
    static const char PROGMEM image[] = {
        // 'hatsune-miku-pixel-art-32x32-black-and-white', 32x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0xe4, 0xe4, 0xe1, 0xf1, 0xf2, 0xf8, 0xfc, 0xfc, 0xfc,
        0xfc, 0xfc, 0xfc, 0xf8, 0x4c, 0x82, 0xf8, 0xfa, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0xf8, 0x3f, 0x9f, 0x3f, 0xff, 0xff, 0xe7, 0x97, 0xff, 0xff, 0xfe, 0x0f, 0x2d,
        0xe7, 0x8f, 0xff, 0x7f, 0x08, 0x01, 0x07, 0x19, 0xe7, 0x3f, 0xff, 0xf8, 0xe0, 0x00, 0x00, 0x00,
        0x00, 0xfc, 0xff, 0x00, 0x00, 0x0f, 0x70, 0x80, 0x01, 0x01, 0x23, 0x33, 0xff, 0x7b, 0xff, 0xff,
        0xff, 0xfb, 0xb3, 0x12, 0x03, 0x40, 0x80, 0xc0, 0x30, 0x00, 0x01, 0x07, 0xff, 0xff, 0xfc, 0x00,
        0x00, 0x00, 0x03, 0x07, 0x1c, 0x1e, 0x16, 0x07, 0x01, 0x03, 0x06, 0xcb, 0xbb, 0x31, 0x10, 0x11,
        0x1b, 0x7b, 0x11, 0xf1, 0x06, 0x02, 0x03, 0x03, 0x04, 0x0e, 0x7e, 0x3e, 0x0f, 0x07, 0x03, 0x00
    };

    oled_write_raw_P(image, sizeof(image));
}

// Add Status Overview
static void print_status_narrow(void) {
    // Move Cursor Below the 32x32 Image (4 Rows of 8px Height Each)
    oled_set_cursor(0, 4);

    // Title
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("Lotus -58-"), false);
    oled_write_P(PSTR("\n"), false);

    // Current Layer
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("-Base\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("-Nav \n"), false);
            break;
        case 2:
            oled_write_P(PSTR("-Sym \n"), false);
            break;
        case 3:
            oled_write_P(PSTR("-Sys \n"), false);
            break;
        case 4:
            oled_write_P(PSTR("-Fall\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef\n"), false);
    }

    // Caps Lock
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(PSTR("Caps \n"), led_usb_state.caps_lock);

    // Auto-Shift
    #ifdef AUTO_SHIFT_ENABLE

    bool autoshift = get_autoshift_state();
    oled_write_P(PSTR("Auto-Shift\n"), autoshift);

    #endif
}

// Print Content
bool oled_task_user(void) {
    print_custom_image();

    print_status_narrow();

    return false;
}

#endif
