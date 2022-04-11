/* Copyright 2021-2022 Leo Gaskin <leo.gaskin@le0.gs>
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
    SYMB,
    GAME,
};

enum custom_keycodes {
    TD_ORYX = WEBUSB_PAIR,
    TD_VIM  = LT(SYMB, KC_ESC),
    TD_SFT  = OSM(MOD_LSFT),
    TD_CTL  = OSM(MOD_LCTL),
    TD_ALT  = OSM(MOD_LALT),
    TD_GUI  = OSM(MOD_LGUI),
    TD_ADIA = ALGR(KC_A),
    TD_ODIA = ALGR(KC_O),
    TD_UDIA = ALGR(KC_U),
    TD_SS   = ALGR(KC_S),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DE_SS,   DE_ACUT,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,           _______, DE_Z,    KC_U,    KC_I,    KC_O,    KC_P,    DE_UDIA,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,           _______, KC_H,    KC_J,    KC_K,    KC_L,    DE_ODIA, DE_ADIA,
        KC_TAB,  DE_Y,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  DE_MINS, _______,
        _______, TD_ORYX, _______, TD_ALT,  TD_GUI,           TO(GAME),          _______,          TD_VIM,  KC_ENT,  DE_HASH, DE_PLUS, _______,
                                            TD_SFT,  TD_CTL,  _______,           _______, KC_BSPC, KC_SPC
    ),

    [SYMB] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, DE_AT,   DE_CIRC, DE_EURO, DE_ASTR, DE_PLUS, _______,           _______, DE_LABK, TD_UDIA, DE_PIPE, TD_ODIA, DE_RABK, _______,
        _______, TD_ADIA, TD_SS,   KC_TAB,  DE_HASH, DE_TILD, _______,           _______, DE_SLSH, KC_DOWN, KC_UP,   KC_RGHT, KC_LEFT, _______,
        _______, DE_EXLM, DE_DQUO, DE_DLR,  DE_PERC, DE_AMPR,                             DE_BSLS, DE_QUOT, DE_GRV,  DE_EQL,  DE_QUES, _______,
        _______, _______, _______, _______, _______,          _______,           _______,           _______, _______, _______, _______,  _______,
                                            _______, _______, _______,           TO(BASE), _______, _______
    ),

    [GAME] = LAYOUT_moonlander(
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
const uint8_t PROGMEM ledmaps[][DRIVER_LED_TOTAL][3] = {
    [BASE] = { {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {141,255,233},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255} },

    [SYMB] = { {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, { 31,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, { 31,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, { 31,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, { 31,255,255}, {  0,255,255}, {141,255,233},
               {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255}, {  0,255,255}, {  0,255,255},
               {  0,255,255} },

    [GAME] = { { 86,255,255}, { 86,255,255}, { 86,255,255}, { 86,255,255}, { 86,255,255},
               { 86,255,255}, { 86,255,255}, {  0,  0,255}, { 86,255,255}, {  0,  0,255},
               { 86,255,255}, {  0,  0,255}, {  0,  0,255}, { 86,255,255}, {  0,  0,255},
               { 86,255,255}, { 86,255,255}, {  0,  0,255}, { 86,255,255}, {  0,  0,255},
               { 86,255,255}, { 86,255,255}, { 86,255,255}, { 86,255,255}, {  0,  0,255},
               { 86,255,255}, { 86,255,255}, { 86,255,255}, { 86,255,255},
               { 86,255,255}, { 86,255,255}, { 86,255,255},
               { 86,255,255}, { 86,255,255}, { 86,255,255},
               { 86,255,255},
               { 86,255,255}, { 86,255,255}, { 86,255,255}, { 86,255,255}, { 86,255,255},
               { 86,255,255}, { 86,255,255}, { 86,255,255}, { 86,255,255}, { 86,255,255},
               { 86,255,255}, { 86,255,255}, { 86,255,255}, { 86,255,255}, { 86,255,255},
               { 86,255,255}, { 86,255,255}, { 86,255,255}, { 86,255,255}, { 86,255,255},
               { 86,255,255}, { 86,255,255}, { 86,255,255}, { 86,255,255}, { 86,255,233},
               { 86,255,255}, { 86,255,255}, { 86,255,255}, { 86,255,255},
               { 86,255,255}, { 86,255,255}, { 86,255,255},
               { 86,255,255}, { 86,255,255}, { 86,255,255},
               { 86,255,255} },
};
// clang-format on

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmaps[layer][i][0]),
            .s = pgm_read_byte(&ledmaps[layer][i][1]),
            .v = pgm_read_byte(&ledmaps[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return;
    }
    switch (biton32(layer_state)) {
        case BASE:
            set_layer_color(BASE);
            break;
        case SYMB:
            set_layer_color(SYMB);
            break;
        case GAME:
            set_layer_color(GAME);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
}
