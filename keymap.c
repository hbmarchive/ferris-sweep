#include QMK_KEYBOARD_H

enum my_layers {
  BASE_LAYER,
  SYM_LAYER,
  NAV_LAYER,
  FUNC_LAYER
};

enum my_tap_dances {
  TD_Q_GRV,
  TD_A_TAB,
  TD_Z_CAPS,
  TD_X_CTLX,
  TD_C_CTLC,
  TD_V_CTLV,
  TD_W_CTLW,
  TD_F_CTLF,
  TD_B_CTLB,
  TD_LBRC_GLB,
  TD_RBRC_GRB,
  TD_SLSH_LEAD
};

enum my_keycodes {
    M_DSKN = SAFE_RANGE,
    M_DSKP
};

typedef enum {
  TD_NONE,
  TD_UNKNOWN,
  TD_SINGLE_TAP,
  TD_LEADER_TAP,
  TD_KEYPRESSES
} td_leaderstate_t;

typedef struct {
  bool is_press_action;
  td_leaderstate_t state;
} td_doubletap_t;

// Create instance of 'td_doubletap_t' for the leader tap dance.
static td_doubletap_t slsh_lead = {
  .is_press_action = true,
  .state = TD_NONE
};

// For the leader tap dance, put here so they can be used in any keymap.
td_leaderstate_t td_get_leader_taps(tap_dance_state_t *state);
void slsh_lead_finished(tap_dance_state_t *state, void *user_data);
void slsh_lead_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = LAYOUT_split_3x5_2(
    TD(TD_Q_GRV), TD(TD_W_CTLW), TD(TD_F_CTLF), KC_P, TD(TD_B_CTLB), KC_J, KC_L, KC_U, KC_Y, KC_BSPC,
    TD(TD_A_TAB), LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_T), KC_G, KC_M, RCTL_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), KC_O,
    TD(TD_Z_CAPS), TD(TD_X_CTLX), TD(TD_C_CTLC), KC_D, TD(TD_V_CTLV), KC_K, KC_H, KC_COMM, KC_DOT, TD(TD_SLSH_LEAD),
    OSM(MOD_LSFT), KC_SPC, KC_ENT, OSL(SYM_LAYER)
  ),
  [SYM_LAYER] = LAYOUT_split_3x5_2(
    KC_EXLM, LSFT(KC_2), LSFT(KC_3), KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_PLUS,
    KC_ESC, LSFT(KC_NUBS), TD(TD_LBRC_GLB), KC_LCBR, KC_LPRN, KC_COLN, LSFT(KC_QUOT), LSFT(KC_BSLS), KC_MINS, KC_EQL,
    TO(FUNC_LAYER), KC_NUBS, TD(TD_RBRC_GRB), KC_RCBR, KC_RPRN, KC_SCLN, KC_QUOT, KC_BSLS, LSFT(KC_DOT), KC_QUES,
    TO(BASE_LAYER), KC_SPC, KC_ENT, TO(NAV_LAYER)
  ),
  [NAV_LAYER] = LAYOUT_split_3x5_2(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_TAB, LCTL(KC_TAB), LALT(KC_TAB), KC_BTN1, KC_BTN2, KC_DEL, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
    QK_LEAD, TO(FUNC_LAYER), M_DSKP, M_DSKN, LSFT(KC_V), KC_INS, KC_NO, KC_PGDN, KC_PGUP, QK_LEAD,
    TO(BASE_LAYER), KC_SPC, KC_ENT, KC_NO
  ),
  [FUNC_LAYER] = LAYOUT_split_3x5_2(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_MNXT, KC_VOLU, KC_BRIU, KC_ASTR, KC_NO, KC_PLUS,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_MPLY, KC_VOLD, KC_BRID, KC_NO, KC_MINS, KC_EQL,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MUTE, KC_NO, KC_COMM, KC_DOT, KC_SLSH,
    TO(BASE_LAYER), KC_SPC, KC_ENT, TO(SYM_LAYER)
  )
};

// Tap dance definitions.
tap_dance_action_t tap_dance_actions[] = {
  // Cut, copy and paste.
  [TD_X_CTLX] = ACTION_TAP_DANCE_DOUBLE(KC_X, LCTL(KC_X)),
  [TD_C_CTLC] = ACTION_TAP_DANCE_DOUBLE(KC_C, LCTL(KC_C)),
  [TD_V_CTLV] = ACTION_TAP_DANCE_DOUBLE(KC_V, LCTL(KC_V)),
  // GRAVE on Q key.
  [TD_Q_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_GRV),
  // Tab on A key.
  [TD_A_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB),
  // Caps lock on Z key.
  [TD_Z_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_CAPS),
  // Vim split commands.
  [TD_W_CTLW] = ACTION_TAP_DANCE_DOUBLE(KC_W, LCTL(KC_W)),
  // Vim page up and down.
  [TD_F_CTLF] = ACTION_TAP_DANCE_DOUBLE(KC_F, LCTL(KC_F)),
  [TD_B_CTLB] = ACTION_TAP_DANCE_DOUBLE(KC_B, LCTL(KC_B)),
  // Tap once for [, twice for Search-[ (ChromeOS prev desk).
  [TD_LBRC_GLB] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LGUI(KC_LBRC)),
  // Tap once for ], twice for Search-] (ChromeOS next desk).
  [TD_RBRC_GRB] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LGUI(KC_RBRC)),
  // Tap once for /, twice for leader key.
  [TD_SLSH_LEAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, slsh_lead_finished, slsh_lead_reset),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  // Return to the base later after fn keys, space or enter have been pressed.
  case KC_F1 ... KC_F12:
  case KC_SPC:
  case KC_ENT:
    if (record->event.pressed) {
      layer_move(BASE_LAYER);
    }
    break;
  // Return to num layer if symbol keys in the func layer have been pressed.
  case KC_ASTR:
  case KC_PLUS:
  case KC_MINS:
  case KC_EQL:
  case KC_DOT:
  case KC_SLSH:
    if (record->event.pressed) {
      if (IS_LAYER_ON(FUNC_LAYER)) {
        layer_move(NAV_LAYER);
      }
    }
    break;
  // Respond to next desktop macro.
  case M_DSKN:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LGUI));
      SEND_STRING(SS_TAP(X_RIGHT));
      SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LCTL));
    }
    break;
  // Respond to previous desktop macro.
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Increase the tapping term for the homerow mods.
    case LGUI_T(KC_R):
    case LALT_T(KC_S):
    case LCTL_T(KC_T):
    case RCTL_T(KC_N):
    case RALT_T(KC_E):
    case RGUI_T(KC_I):
      return TAPPING_TERM + 1000;
    // Set the tapping term for the paste key differently.
    case LCTL(KC_V):
      return TAPPING_TERM_PASTE;
    // Set the tapping term for the leader key differently.
    case TD(TD_SLSH_LEAD):
      return TAPPING_TERM_LEADER;
    default:
      return TAPPING_TERM;
  }
}

td_leaderstate_t td_get_leader_taps(tap_dance_state_t *state) {
  if (state->count == 1) {
    // Interrupted means another key has been pressed within the tapping term
    // and state not being pressed means the leader key is no longer pressed, so
    // return a single tap either way.
    if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
  } else if (state->count == 2) {
    // Normally if the double tap has been interrupted we interpret that as fast
    // typing but in the case of the leader key we actually interpret that as a
    // leader action, so the opposite as true and we return the tap dance
    // action: a leader tap.
    if (state->interrupted) return TD_LEADER_TAP;
    // And if the tapping term has expired without another key being pressed to
    // interrupt, we interpret this as a "timeout" of sorts - in this case of
    // the leader key specifically - and we issue the two keypresses instead of
    // the tapdance action.
    else if (!state->pressed) return TD_KEYPRESSES;
  }
  return TD_UNKNOWN;
}

void slsh_lead_finished(tap_dance_state_t *state, void *user_data) {
  slsh_lead.state = td_get_leader_taps(state);
  switch (slsh_lead.state) {
    case TD_SINGLE_TAP: register_code(KC_SLSH); break;
    case TD_KEYPRESSES: tap_code(KC_SLSH); register_code(KC_SLSH); break;
    default: break;
  }
}

void slsh_lead_reset(tap_dance_state_t *state, void *user_data) {
  switch (slsh_lead.state) {
    case TD_SINGLE_TAP: unregister_code(KC_SLSH); break;
    case TD_LEADER_TAP: leader_start(); break;
    case TD_KEYPRESSES: unregister_code(KC_SLSH); break;
    default: break;
  }
  slsh_lead.state = TD_NONE;
}

void leader_start_user(void) {
  // Do something when the leader key is pressed.
}

void leader_end_user(void) {
  // AutoHotkey shortcuts to minimise, maximise and close windows.
  if (leader_sequence_one_key(KC_M)) {
      SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
      SEND_STRING(SS_TAP(X_M));
      SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_one_key(KC_G)) {
      SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
      SEND_STRING(SS_TAP(X_G));
      SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_one_key(KC_BSPC)) {
      SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
      SEND_STRING(SS_TAP(X_BSPC));
      SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  // AutoHotkey shortcuts to open applications or bring them to the front.
  } else if (leader_sequence_one_key(KC_R)) {
    SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_1));
    SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_one_key(KC_S)) {
    SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_2));
    SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
    reset_tap_dance(&tap_dance_actions[TD_F_CTLF].state);
  } else if (leader_sequence_one_key(KC_T)) {
    SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_3));
    SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_one_key(KC_N)) {
    SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_4));
    SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
    reset_tap_dance(&tap_dance_actions[TD_B_CTLB].state);
  } else if (leader_sequence_one_key(KC_E)) {
    SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_5));
    SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_one_key(KC_I)) {
    SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_6));
    SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_two_keys(KC_0, KC_1)) {
    SEND_STRING(SS_TAP(X_F1));
  } else if (leader_sequence_two_keys(KC_1, KC_0)) {
    SEND_STRING(SS_TAP(X_F10));
  } else if (leader_sequence_two_keys(KC_1, KC_1)) {
    SEND_STRING(SS_TAP(X_F11));
  } else if (leader_sequence_two_keys(KC_1, KC_2)) {
    SEND_STRING(SS_TAP(X_F12));
  } else if (leader_sequence_one_key(KC_2)) {
    SEND_STRING(SS_TAP(X_F2));
  } else if (leader_sequence_one_key(KC_3)) {
    SEND_STRING(SS_TAP(X_F3));
  } else if (leader_sequence_one_key(KC_4)) {
    SEND_STRING(SS_TAP(X_F4));
  } else if (leader_sequence_one_key(KC_5)) {
    SEND_STRING(SS_TAP(X_F5));
  } else if (leader_sequence_one_key(KC_6)) {
    SEND_STRING(SS_TAP(X_F6));
  } else if (leader_sequence_one_key(KC_7)) {
    SEND_STRING(SS_TAP(X_F7));
  } else if (leader_sequence_one_key(KC_8)) {
    SEND_STRING(SS_TAP(X_F8));
  } else if (leader_sequence_one_key(KC_9)) {
    SEND_STRING(SS_TAP(X_F9));
  }
}
