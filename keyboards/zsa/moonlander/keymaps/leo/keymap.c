/* Copyright 2021-2024 Leo Gaskin <leo.gaskin@le0.gs>
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
#include "dances.h"
#include "keymap_german.h"
#include "led_layouts.h"
#include "version.h"

enum layers {
    BASE,
    SHIFT,
    ALTGR,
    SYMBOLS,
    ANKI,
};

enum td_keycodes { TD_ESC };

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC] = DANCES_LAYER(esc_finished, esc_reset, ALTGR),
};

const uint16_t PROGMEM jk_chord[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM df_chord[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[] = {
    COMBO(jk_chord, OSL(SYMBOLS)),
    COMBO(df_chord, OSL(SYMBOLS)),
};

enum my_keycodes {
    MY_ESC = TD(TD_ESC),
    MY_SFT = OSL(SHIFT),
    MY_GUI = OSM(MOD_LGUI),
    MY_CTL = OSM(MOD_LCTL),
    MY_ALT = OSM(MOD_LALT),
};

enum shift_keycodes {
    SF_Q = LSFT(KC_Q),
    SF_W = LSFT(KC_W),
    SF_E = LSFT(KC_E),
    SF_R = LSFT(KC_R),
    SF_T = LSFT(KC_T),
    SF_Z = LSFT(DE_Z),
    SF_U = LSFT(KC_U),
    SF_I = LSFT(KC_I),
    SF_O = LSFT(KC_O),
    SF_P = LSFT(KC_P),
    SF_A = LSFT(KC_A),
    SF_S = LSFT(KC_S),
    SF_D = LSFT(KC_D),
    SF_F = LSFT(KC_F),
    SF_G = LSFT(KC_G),
    SF_H = LSFT(KC_H),
    SF_J = LSFT(KC_J),
    SF_K = LSFT(KC_K),
    SF_L = LSFT(KC_L),
    SF_Y = LSFT(DE_Y),
    SF_X = LSFT(KC_X),
    SF_C = LSFT(KC_C),
    SF_V = LSFT(KC_V),
    SF_B = LSFT(KC_B),
    SF_N = LSFT(KC_N),
    SF_M = LSFT(KC_M),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,           _______, DE_Z,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,           _______, KC_H,    KC_J,    KC_K,    KC_L,    DE_QUES, _______,
        _______, DE_Y,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  DE_MINS, _______,
        _______, _______, _______, MY_GUI,  MY_SFT,           _______,           TG(ANKI),         MY_ESC,  KC_ENT,  _______, _______, _______,
                                            MY_CTL,  MY_ALT,  _______,           _______, KC_BSPC, KC_SPC
    ),

    [SHIFT] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, SF_Q,    SF_W,    SF_E,    SF_R,    SF_T,    _______,           _______, SF_Z,    SF_U,    SF_I,    SF_O,    SF_P,    _______,
        _______, SF_A,    SF_S,    SF_D,    SF_F,    SF_G,    _______,           _______, SF_H,    SF_J,    SF_K,    SF_L,    KC_EXLM, _______,
        _______, DE_Y,    SF_X,    SF_C,    SF_V,    SF_B,                                SF_N,    SF_M,    DE_SCLN, DE_COLN, DE_UNDS, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [ALTGR] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, DE_AT,   _______, DE_EURO, _______, _______, _______,           _______, _______, DE_UDIA, _______, DE_ODIA, _______, _______,
        _______, DE_ADIA, DE_SS,   KC_TAB,  _______, KC_1,    _______,           _______, KC_0,    KC_DOWN, KC_UP,   KC_RGHT, KC_LEFT, _______,
        _______, _______, KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [SYMBOLS] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, DE_PIPE, DE_LABK, DE_RABK, DE_GRV,  _______,           _______, DE_DLR,  DE_LBRC, DE_RBRC, DE_PLUS, _______, _______,
        _______, _______, DE_ACUT, DE_DQUO, DE_QUOT, DE_ASTR, _______,           _______, DE_PERC, DE_LPRN, DE_RPRN, DE_EQL,  _______, _______,
        _______, _______, DE_HASH, DE_BSLS, DE_SLSH, DE_TILD,                             DE_AMPR, DE_LCBR, DE_RCBR, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [ANKI] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, KC_1,    KC_2,    KC_3,    KC_4,    _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          KC_SPC,  C(DE_Z), _______, DE_MINS, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};
// clang-format on

// clang-format off
const uint16_t PROGMEM ledmaps[][RGB_MATRIX_LED_COUNT] = {
    [BASE] = LED_LAYOUT_moonlander(
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,                 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0x00f,        0xf00,   0xf00,        0x00f, 0xf00, 0xf00, 0xf00, 0xf00,
                                    0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00
    ),

    [SHIFT] = LED_LAYOUT_moonlander(
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,                 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0x00f,        0xf00,   0xf00,        0x00f, 0xf00, 0xf00, 0xf00, 0xf00,
                                    0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00
    ),

    [ALTGR] = LED_LAYOUT_moonlander(
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf90, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf90, 0xf90, 0xf90, 0xf90, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,                 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00,        0xf00,   0xf00,        0x00f, 0xf00, 0xf00, 0xf00, 0xf00,
                                    0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00
    ),

    [SYMBOLS] = LED_LAYOUT_moonlander(
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,                 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00,        0xf00,   0xf00,        0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
                                    0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00
    ),

    [ANKI] = LED_LAYOUT_moonlander(
        0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,   0x111, 0x111, 0x111, 0x111, 0x111, 0x111, 0x111,
        0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,   0x111, 0x111, 0x111, 0x111, 0x111, 0x111, 0x111,
        0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,   0x111, 0x111, 0xf00, 0xff0, 0x0f0, 0x00f, 0x111,
        0x000, 0x000, 0x000, 0x000, 0x000, 0x000,                 0x111, 0x111, 0x111, 0x111, 0x666, 0x111,
        0x000, 0x000, 0x000, 0x000, 0x000,        0x000,   0x111,        0x0ff, 0xf40, 0x111, 0x111, 0x111,
                                    0x000, 0x000, 0x000,   0x111, 0x111, 0x111
    ),
};
// clang-format on

// clang-format off
_Static_assert(
    sizeof(keymaps) / sizeof(*keymaps) == sizeof(ledmaps) / sizeof(*ledmaps),
    "key and led maps are not of the same length"
);
// clang-format on

void set_layer_color(int selected_layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        for (int layer = selected_layer; layer >= 0; layer--) {
            uint16_t hex = pgm_read_word(&ledmaps[layer][i]);
            RGB      rgb = {
                .r = ((hex >> 8) & 0b1111) + (((hex >> 8) & 0b1111) << 4),
                .g = ((hex >> 4) & 0b1111) + (((hex >> 4) & 0b1111) << 4),
                .b = ((hex >> 0) & 0b1111) + (((hex >> 0) & 0b1111) << 4),
            };

            if (rgb.r || rgb.g || rgb.b) {
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                break;
            }
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return true;
    }
    set_layer_color(biton32(layer_state));

    return false;
}
