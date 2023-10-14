#include "quantum.h"

enum td_state { TD_HOLD, TD_TAP, TD_DOUBLE_TAP };

static enum td_state td_state;

enum td_state cur_dance(tap_dance_state_t *state) {
    if (/* state->interrupted || */ !state->pressed) {
        return state->count == 1 ? TD_TAP : TD_DOUBLE_TAP;
    } else {
        return TD_HOLD;
    }
}

void esc_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_HOLD:
            layer_on(*(uint8_t *)user_data);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_ESC);
        case TD_TAP:
            clear_oneshot_mods();
            clear_mods();
            register_code(KC_ESC);
            break;
    }
}

void esc_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_HOLD:
            layer_off(*(uint8_t *)user_data);
            break;
        case TD_TAP:
        case TD_DOUBLE_TAP:
            unregister_code(KC_ESC);
            break;
    }
}

void sft_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_HOLD:
            layer_on(*(uint8_t *)user_data);
            break;
        case TD_TAP:
            if (get_mods() & MOD_BIT_LSHIFT) {
                del_mods(MOD_BIT_LSHIFT);
                break;
            }
            add_oneshot_mods(MOD_BIT_LSHIFT);
            break;
        case TD_DOUBLE_TAP:
            if (get_mods() & MOD_BIT_LSHIFT) {
                del_mods(MOD_BIT_LSHIFT);
                break;
            }
            add_mods(MOD_BIT_LSHIFT);
            break;
    }
}

void sft_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_HOLD:
            layer_off(*(uint8_t *)user_data);
            break;
        default:
            break;
    }
}
