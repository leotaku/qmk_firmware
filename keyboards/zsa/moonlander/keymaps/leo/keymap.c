/* Copyright 2021 Leo Gaskin <leo.gaskin@le0.gs>
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
#include "keymap_german.h"
#include "version.h"

enum layers {
    BASE,
    SYMBOLS,
    GAMING,
};

enum my_keycodes {
    MY_VIM  = LT(SYMBOLS, KC_ESC),
    MY_SFT  = OSM(MOD_LSFT),
    MY_CTL  = OSM(MOD_LCTL),
    MY_ALT  = OSM(MOD_LALT),
    MY_GUI  = OSM(MOD_LGUI),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,           _______, DE_Z,    KC_U,    KC_I,    KC_O,    KC_P,    DE_UDIA,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,           _______, KC_H,    KC_J,    KC_K,    KC_L,    DE_ODIA, DE_ADIA,
        _______, DE_Y,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  DE_MINS, _______,
        _______, _______, _______, MY_ALT,  MY_GUI,           TO(GAMING),        _______,          MY_VIM,  KC_ENT,  _______, _______, _______,
                                            MY_SFT,  MY_CTL,  _______,           _______, KC_BSPC, KC_SPC
    ),

    [SYMBOLS] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, DE_AT,   DE_CIRC, DE_EURO, DE_ASTR, DE_PLUS, _______,           _______, DE_LABK, DE_UDIA, DE_PIPE, DE_ODIA, DE_RABK, _______,
        _______, DE_ADIA, DE_SS,   KC_TAB,  DE_HASH, DE_TILD, _______,           _______, DE_SLSH, KC_DOWN, KC_UP,   KC_RGHT, KC_LEFT, _______,
        _______, DE_EXLM, DE_DQUO, DE_DLR,  DE_PERC, DE_AMPR,                             DE_BSLS, DE_QUOT, DE_GRV,  DE_EQL,  DE_QUES, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [GAMING] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, RGB_MODE_FORWARD,  RGB_VAI, _______, _______, _______, _______, _______, _______,
        KC_ESC,  _______, KC_W,    _______, _______, _______, RGB_MODE_REVERSE,  RGB_VAD, _______, _______, _______, _______, _______, _______,
        KC_TAB,  KC_A,    KC_S,    KC_D,    _______, _______, TOGGLE_LAYER_COLOR,RGB_TOG, _______, _______, _______, _______, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_LALT, KC_SPC,           TO(BASE),          _______,          _______, _______, _______, _______, _______,
                                            KC_LCTL, _______, _______,           _______, _______, _______
    ),
};
// clang-format on

// clang-format off
const uint32_t PROGMEM ledmaps[][RGB_MATRIX_LED_COUNT] = {
    [BASE] = LED_LAYOUT_moonlander(
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,                 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00,        0xf00,   0xf00,        0x00f, 0xf00, 0xf00, 0xf00, 0xf00,
                                    0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00
    ),

    [SYMBOLS] = LED_LAYOUT_moonlander(
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xfc0, 0xfc0, 0xfc0, 0xfc0, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,                 0xf00, 0xf00, 0xf00, 0xf00, 0xf00, 0xf00,
        0xf00, 0xf00, 0xf00, 0xf00, 0xf00,        0xf00,   0xf00,        0x00f, 0xf00, 0xf00, 0xf00, 0xf00,
                                    0xf00, 0xf00, 0xf00,   0xf00, 0xf00, 0xf00
    ),

    [GAMING] = LED_LAYOUT_moonlander(
        0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0,   0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0,
        0x0f0, 0x0f0, 0xfff, 0x0f0, 0x0f0, 0x0f0, 0x0f0,   0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0,
        0x0f0, 0xfff, 0xfff, 0xfff, 0x0f0, 0x0f0, 0x0f0,   0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0,
        0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0,                 0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0, 0x0f0,
        0x0f0, 0xfff, 0xfff, 0xfff, 0xfff,        0x0f0,   0x0f0,        0x00f, 0x0f0, 0x0f0, 0x0f0, 0x0f0,
                                    0x0f0, 0x0f0, 0x0f0,   0x0f0, 0x0f0, 0x0f0
    ),
};
// clang-format on

// clang-format off
_Static_assert(
    sizeof(keymaps) / sizeof(*keymaps) == sizeof(ledmaps) / sizeof(*ledmaps),
    "key and led maps are not of the same length"
);
// clang-format on

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        uint32_t hex = pgm_read_dword(&ledmaps[layer][i]);
        RGB      rgb = {
            .r = ((hex >> 8) & 0b1111) + (((hex >> 8) & 0b1111) << 4),
            .g = ((hex >> 4) & 0b1111) + (((hex >> 4) & 0b1111) << 4),
            .b = ((hex >> 0) & 0b1111) + (((hex >> 0) & 0b1111) << 4),
        };

        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
    }
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return true;
    }
    set_layer_color(biton32(layer_state));

    return false;
}
