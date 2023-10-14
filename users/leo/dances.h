#pragma once

#include "quantum.h"

#define DANCES_LAYER(user_fn_on_dance_finished, user_fn_on_dance_reset, user_data_layer) \
    { .fn = {NULL, user_fn_on_dance_finished, user_fn_on_dance_reset, NULL}, .user_data = &(uint8_t){user_data_layer}, }

void esc_finished(tap_dance_state_t *state, void *user_data);
void esc_reset(tap_dance_state_t *state, void *user_data);

void sft_finished(tap_dance_state_t *state, void *user_data);
void sft_reset(tap_dance_state_t *state, void *user_data);
