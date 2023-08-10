#include QMK_KEYBOARD_H

enum my_layers {
  BASE_LAYER,
  SYM_LAYER,
  NAV_LAYER,
  FUNC_LAYER,
  SCUT_LAYER
};

enum my_keycodes {
    M_ESCQ = SAFE_RANGE,
    M_ESCW,
    M_ESCV,
    M_EQLR,
    M_ALTT,
    M_SCM1
};

// Stores state of M_ALTT macro - true if we are currently tabbing between
// windows.
static bool m_altt_pressed = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = LAYOUT_split_3x5_2(
    LSFT_T(KC_Q), LCTL_T(KC_W), LALT_T(KC_F), LGUI_T(KC_P), KC_B, KC_J, RGUI_T(KC_L), RALT_T(KC_U), RCTL_T(KC_Y), RSFT_T(KC_BSPC),
    KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O,
    KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, OSL(SCUT_LAYER),
    OSM(MOD_LSFT), KC_SPC, KC_ENT, OSL(SYM_LAYER)
  ),
  [SYM_LAYER] = LAYOUT_split_3x5_2(
    KC_EXLM, LSFT(KC_2), LSFT(KC_3), KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_PLUS,
    KC_ESC, LSFT(KC_NUBS), KC_LBRC, KC_LCBR, KC_LPRN, KC_COLN, LSFT(KC_QUOT), LSFT(KC_BSLS), KC_MINS, KC_EQL,
    TO(FUNC_LAYER), KC_NUBS, KC_RBRC, KC_RCBR, KC_RPRN, KC_SCLN, KC_QUOT, KC_BSLS, KC_GRV, OSL(SCUT_LAYER),
    TO(BASE_LAYER), KC_SPC, KC_ENT, TO(NAV_LAYER)
  ),
  [NAV_LAYER] = LAYOUT_split_3x5_2(
    LSFT_T(KC_1), LCTL_T(KC_2), LALT_T(KC_3), LGUI_T(KC_4), KC_5, KC_6, LGUI_T(KC_7), LALT_T(KC_8), LCTL_T(KC_9), LSFT_T(KC_0),
    KC_TAB, LCTL(KC_TAB), M_ALTT, KC_BTN1, KC_BTN2, KC_WH_U, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
    TO(FUNC_LAYER), LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RGHT)), M_SCM1, M_ESCV, KC_WH_D, KC_HOME, KC_PGDN, KC_PGUP, OSL(SCUT_LAYER),
    TO(BASE_LAYER), KC_SPC, KC_ENT, KC_NO
  ),
  [FUNC_LAYER] = LAYOUT_split_3x5_2(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_MNXT, KC_VOLU, KC_BRIU, KC_ASTR, KC_NO, KC_PLUS,
    KC_F5, KC_F6, KC_F7, KC_F8, KC_MPLY, KC_VOLD, KC_BRID, KC_NO, KC_MINS, KC_EQL,
    KC_F9, KC_F10, KC_F11, KC_F12, KC_MPRV, KC_MUTE, KC_NO, KC_COMM, KC_DOT, OSL(SCUT_LAYER),
    TO(BASE_LAYER), KC_SPC, KC_ENT, TO(SYM_LAYER)
  ),
  [SCUT_LAYER] = LAYOUT_split_3x5_2(
    M_ESCQ, M_ESCW, LCTL(KC_F), LSFT(LCTL(KC_SPC)), LCTL(KC_B), KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL,
    KC_TAB, HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), HYPR(KC_G), HYPR(KC_M), HYPR(KC_4), HYPR(KC_5), HYPR(KC_6), KC_INS,
    KC_CAPS, LCTL(KC_X), LCTL(KC_C), LSFT(LCTL(KC_C)), LCTL(KC_V), HYPR(KC_K), LSFT(LCTL(KC_1)), KC_NO, M_EQLR, KC_SLSH,
    TO(BASE_LAYER), KC_SPC, KC_ENT, KC_NO
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode != M_ALTT && m_altt_pressed) {
    unregister_code(KC_LALT);
    m_altt_pressed = false;
  }
  switch (keycode) {
    case M_ALTT:
      if (record->event.pressed) {
        if (!m_altt_pressed) {
          register_code(KC_LALT);
          m_altt_pressed = true;
        }
        tap_code(KC_TAB);
      }
      break;
    case M_SCM1:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL));
        SEND_STRING(SS_DELAY(100)SS_TAP(X_BTN1));
        SEND_STRING(SS_UP(X_LCTL)SS_UP(X_LSFT));
      }
      break;
    case M_ESCQ:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC)":q!"SS_TAP(X_ENT));
      } else {
        layer_move(BASE_LAYER);
      }
      break;
    case M_ESCW:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC)":wq"SS_TAP(X_ENT));
      } else {
        layer_move(BASE_LAYER);
      }
      break;
    case M_EQLR:
      if (record->event.pressed) {
        SEND_STRING("=> ");
      } else {
        layer_move(BASE_LAYER);
      }
      break;
    case M_ESCV:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC));
        SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_V)SS_UP(X_LSFT));
      }
      break;
  }
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Return to the base layer if space, enter or a function key is pressed.
    case KC_SPC:
    case KC_ENT:
    case KC_F1 ... KC_F12:
      if (!record->event.pressed) { layer_move(BASE_LAYER); }
      break;
    // Cancel caps lock if escape is pressed.
    case KC_ESC:
      if (host_keyboard_led_state().caps_lock) { tap_code(KC_CAPS); }
      break;
    // Return to the nav layer if symbols in the func layer have been pressed.
    case KC_ASTR:
    case KC_PLUS:
    case KC_MINS:
    case KC_EQL:
    case KC_DOT:
    case KC_SLSH:
      if (!record->event.pressed) {
        if (IS_LAYER_ON(FUNC_LAYER)) {
          layer_move(NAV_LAYER);
        }
      }
      break;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Set the tapping term for the homerow mods.
    case LSFT_T(KC_A):
    case LCTL_T(KC_R):
    case LALT_T(KC_S):
    case LGUI_T(KC_T):
    case RGUI_T(KC_N):
    case RALT_T(KC_E):
    case RCTL_T(KC_I):
    case RSFT_T(KC_O):
      return TAPPING_TERM_MODS;
    default:
      return TAPPING_TERM;
  }
}
