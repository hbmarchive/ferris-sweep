#include QMK_KEYBOARD_H

enum my_layers {
  BASE_LAYER,
  SYM_LAYER,
  NUM_LAYER,
  FUNC_LAYER
};

typedef enum {
  TD_NONE,
  TD_UNKNOWN,
  TD_SINGLE_TAP,
  TD_DOUBLE_TAP,
  TD_FAST_TYPING
} td_state_t;

typedef struct {
  bool is_press_action;
  uint8_t mods;
  td_state_t state;
} td_doubletap_t;

// Create instance of 'td_doubletap_t' for the Hyper tap dances.
static td_doubletap_t k_hyper1 = {
  .is_press_action = true,
  .mods = 0,
  .state = TD_NONE
};
static td_doubletap_t h_hyper2 = {
  .is_press_action = true,
  .mods = 0,
  .state = TD_NONE
};
static td_doubletap_t comm_hyper3 = {
  .is_press_action = true,
  .mods = 0,
  .state = TD_NONE
};
static td_doubletap_t dot_hyper4 = {
  .is_press_action = true,
  .mods = 0,
  .state = TD_NONE
};

enum my_tap_dances {
  TD_Z_CAPS,
  TD_X_CUT,
  TD_C_COPY,
  TD_V_PASTE,
  TD_F_PGDN,
  TD_B_PGUP,
  TD_LBRC_GLB,
  TD_RBRC_GRB,
  TD_K_HYPER1,
  TD_H_HYPER2,
  TD_COMM_HYPER3,
  TD_DOT_HYPER4
};

enum my_keycodes {
    M_DSKN = SAFE_RANGE,
    M_DSKP
};

td_state_t td_doubletap(tap_dance_state_t *state);

// For the AHK tap dances, put here so they can be used in any keymap.
void k_hyper1_finished(tap_dance_state_t *state, void *user_data);
void k_hyper1_reset(tap_dance_state_t *state, void *user_data);
void h_hyper2_finished(tap_dance_state_t *state, void *user_data);
void h_hyper2_reset(tap_dance_state_t *state, void *user_data);
void comm_hyper3_finished(tap_dance_state_t *state, void *user_data);
void comm_hyper3_reset(tap_dance_state_t *state, void *user_data);
void dot_hyper4_finished(tap_dance_state_t *state, void *user_data);
void dot_hyper4_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = LAYOUT_split_3x5_2(
      KC_Q, KC_W, TD(TD_F_PGDN), KC_P, TD(TD_B_PGUP), KC_J, KC_L, KC_U, KC_Y, KC_BSPC,
      KC_A, LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_T), KC_G, KC_M, RCTL_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), KC_O,
      TD(TD_Z_CAPS), TD(TD_X_CUT), TD(TD_C_COPY), KC_D, TD(TD_V_PASTE), TD(TD_K_HYPER1), TD(TD_H_HYPER2), TD(TD_COMM_HYPER3), TD(TD_DOT_HYPER4), KC_SLSH,
      OSM(MOD_LSFT), ALL_T(KC_SPC), KC_ENT, OSL(SYM_LAYER)
  ),
  [SYM_LAYER] = LAYOUT_split_3x5_2(
      KC_TAB, KC_DQUO, LSFT(KC_3), KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_PLUS,
      KC_ESC, KC_PIPE, TD(TD_LBRC_GLB), KC_LCBR, KC_LPRN, KC_COLN, KC_AT, KC_TILD, KC_MINS, KC_EQL,
      TO(FUNC_LAYER), KC_NUBS, TD(TD_RBRC_GRB), KC_RCBR, KC_RPRN, KC_SCLN, KC_QUOT, KC_HASH, KC_GRV, KC_EXLM,
      TO(BASE_LAYER), ALL_T(KC_SPC), KC_ENT, TO(NUM_LAYER)
  ),
  [NUM_LAYER] = LAYOUT_split_3x5_2(
      KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
      LCTL(KC_TAB), LALT(KC_TAB), LGUI(KC_TAB), KC_BTN1, KC_BTN2, KC_DEL,KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
      TO(FUNC_LAYER), KC_NO, M_DSKP, M_DSKN, LSFT(KC_V), KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
      TO(BASE_LAYER), ALL_T(KC_SPC), KC_ENT, KC_NO
  ),
  [FUNC_LAYER] = LAYOUT_split_3x5_2(
      KC_F1, KC_F2, KC_F3, KC_F4, KC_MNXT, KC_VOLU, KC_BRIU, KC_ASTR, KC_NO, KC_PLUS,
      KC_F5, KC_F6, KC_F7, KC_F8, KC_MPLY, KC_VOLD, KC_BRID, KC_NO, KC_MINS, KC_EQL,
      KC_F9, KC_F10, KC_F11, KC_F12, KC_MPRV, KC_MUTE, KC_NO, KC_COMM, KC_DOT, KC_SLSH,
      TO(BASE_LAYER), ALL_T(KC_SPC), KC_ENT, TO(SYM_LAYER)
  )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

// Tap dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Z, twice for Caps Lock
    [TD_Z_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_CAPS),
    // Tap once for X, twice for Ctrl-X
    [TD_X_CUT] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_CUT),
    // Tap once for C, twice for Ctrl-C
    [TD_C_COPY] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_COPY),
    // Tap once for V, twice for Ctrl-V
    [TD_V_PASTE] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_PSTE),
    // Tap once for F, twice for Ctrl-F
    [TD_F_PGDN] = ACTION_TAP_DANCE_DOUBLE(KC_F, LCTL(KC_F)),
    // Tap once for B, twice for Ctrl-B
    [TD_B_PGUP] = ACTION_TAP_DANCE_DOUBLE(KC_B, LCTL(KC_B)),
    // Tap once for [TD_, twice for GUI-[ (ChromeOS prev desk)
    [TD_LBRC_GLB] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LGUI(KC_LBRC)),
    // Tap once for ], twice for GUI-] (ChromeOS next desk)
    [TD_RBRC_GRB] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LGUI(KC_RBRC)),
    // Tap once for K, twice for Hyper-K
    [TD_K_HYPER1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, k_hyper1_finished, k_hyper1_reset),
    // Tap once for H, twice for Hyper-H
    [TD_H_HYPER2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, h_hyper2_finished, h_hyper2_reset),
    // Tap once for Comma, twice for Hyper-Comma
    [TD_COMM_HYPER3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, comm_hyper3_finished, comm_hyper3_reset),
    // Tap once for Dot, twice for Hyper-Dot
    [TD_DOT_HYPER4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dot_hyper4_finished, dot_hyper4_reset)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  // Return to the base later after fn keys, space or enter have been pressed
  case KC_F1 ... KC_F12:
  case KC_SPC:
  case KC_ENT:
    if (record->event.pressed) {
      layer_move(BASE_LAYER);
    }
    break;
  // Return to num layer if symbol keys in the func layer have been pressed
  case KC_ASTR:
  case KC_PLUS:
  case KC_MINS:
  case KC_EQL:
  case KC_DOT:
  case KC_SLSH:
    if (record->event.pressed) {
      if (IS_LAYER_ON(FUNC_LAYER)) {
        layer_move(NUM_LAYER);
      }
    }
    break;
  // Respond to next desktop macro
  case M_DSKN:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LGUI));
      SEND_STRING(SS_TAP(X_RIGHT));
      SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LCTL));
    }
    break;
  // Respond to previous desktop macro
  case M_DSKP:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LGUI));
      SEND_STRING(SS_TAP(X_LEFT));
      SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LCTL));
    }
    break;
  }
  return true;
}

td_state_t td_doubletap(tap_dance_state_t *state) {
  if (state->count == 1) {
    // interrupted means another key has been pressed within the tapping term
    // and not pressed means the key is no longer pressed.
    if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
  } else if (state->count == 2) {
    // if interrupted, another key has been pressed so we are seeing fast typing
    // and we will want to emit two keypresses not trigger the "double tap"
    // action.
    if (state->interrupted) return TD_FAST_TYPING;
    // Otherwise, if we have waited until the tapping term has expired after the
    // keypress has finished, this is probably deliberate and we want to trigger
    // the "double tap" action.
    else if (!state->pressed) return TD_DOUBLE_TAP;
  }
  return TD_UNKNOWN;
}

uint8_t hyper_tap_code(uint8_t code) {
  uint8_t mods = get_oneshot_mods();
  set_oneshot_mods(MOD_BIT(KC_LSFT) & MOD_BIT(KC_LCTL) & MOD_BIT(KC_LALT) & MOD_BIT(KC_LGUI));
  register_code(code);
  return mods;
}

void k_hyper1_finished(tap_dance_state_t *state, void *user_data) {
  k_hyper1.state = td_doubletap(state);
  switch (k_hyper1.state) {
    case TD_SINGLE_TAP: register_code(KC_K); break;
    case TD_DOUBLE_TAP: hyper_tap_code(KC_K); break;
    case TD_FAST_TYPING: tap_code(KC_K); register_code(KC_K); break;
    default: break;
  }
}

void k_hyper1_reset(tap_dance_state_t *state, void *user_data) {
  switch (k_hyper1.state) {
    case TD_SINGLE_TAP: unregister_code(KC_K); break;
    case TD_DOUBLE_TAP: unregister_code(KC_K); set_oneshot_mods(k_hyper1.mods); break;
    case TD_FAST_TYPING: unregister_code(KC_K); break;
    default: break;
  }
  k_hyper1.state = TD_NONE;
  k_hyper1.mods = 0;
}

void h_hyper2_finished(tap_dance_state_t *state, void *user_data) {
  h_hyper2.state = td_doubletap(state);
  switch (h_hyper2.state) {
    case TD_SINGLE_TAP: register_code(KC_H); break;
    case TD_DOUBLE_TAP: hyper_tap_code(KC_H); break;
    case TD_FAST_TYPING: tap_code(KC_H); register_code(KC_H); break;
    default: break;
  }
}
void h_hyper2_reset(tap_dance_state_t *state, void *user_data) {
  switch (h_hyper2.state) {
    case TD_SINGLE_TAP: unregister_code(KC_H); break;
    case TD_DOUBLE_TAP: unregister_code(KC_H); set_oneshot_mods(h_hyper2.mods); break;
    case TD_FAST_TYPING: unregister_code(KC_H); break;
    default: break;
  }
  h_hyper2.state = TD_NONE;
  h_hyper2.mods = 0;
}

void comm_hyper3_finished(tap_dance_state_t *state, void *user_data) {
  comm_hyper3.state = td_doubletap(state);
  switch (comm_hyper3.state) {
    case TD_SINGLE_TAP: register_code(KC_COMM); break;
    case TD_DOUBLE_TAP: hyper_tap_code(KC_COMM); break;
    case TD_FAST_TYPING: tap_code(KC_COMM); register_code(KC_COMM); break;
    default: break;
  }
}
void comm_hyper3_reset(tap_dance_state_t *state, void *user_data) {
  switch (comm_hyper3.state) {
    case TD_SINGLE_TAP: unregister_code(KC_COMM); break;
    case TD_DOUBLE_TAP: unregister_code(KC_COMM); set_oneshot_mods(comm_hyper3.mods); break;
    case TD_FAST_TYPING: unregister_code(KC_COMM); break;
    default: break;
  }
  comm_hyper3.state = TD_NONE;
  comm_hyper3.mods = 0;
}

void dot_hyper4_finished(tap_dance_state_t *state, void *user_data) {
  dot_hyper4.state = td_doubletap(state);
  switch (dot_hyper4.state) {
    case TD_SINGLE_TAP: register_code(KC_DOT); break;
    case TD_DOUBLE_TAP: hyper_tap_code(KC_DOT); break;
    case TD_FAST_TYPING: tap_code(KC_DOT); register_code(KC_DOT); break;
    default: break;
  }
}
void dot_hyper4_reset(tap_dance_state_t *state, void *user_data) {
  switch (dot_hyper4.state) {
    case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
    case TD_DOUBLE_TAP: unregister_code(KC_DOT); set_oneshot_mods(dot_hyper4.mods); break;
    case TD_FAST_TYPING: unregister_code(KC_DOT); break;
    default: break;
  }
  dot_hyper4.state = TD_NONE;
  dot_hyper4.mods = 0;
}
