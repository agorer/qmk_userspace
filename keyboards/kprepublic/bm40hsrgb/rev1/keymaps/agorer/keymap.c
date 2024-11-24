/* Copyright 2020 tominabox1
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
#include "keymap_spanish.h"

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _ES
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Combos
enum combos {
  WE_ESC,
  SD_TAB,
  KL_BSPC
};

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [WE_ESC] = COMBO(we_combo, KC_ESC),
  [SD_TAB] = COMBO(sd_combo, KC_TAB),
  [KL_BSPC] = COMBO(kl_combo, KC_BSPC)
};

// Spanish characters
enum custom_keycodes {
    JJ_AACUTE = SAFE_RANGE,
    JJ_EACUTE,
    JJ_IACUTE,
    JJ_OACUTE,
    JJ_UACUTE,
    JJ_TILD
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case JJ_AACUTE:
        if (record->event.pressed) {
          tap_code16(ES_ACUT);
          tap_code16(KC_A);
        }
        break;
    case JJ_EACUTE:
        if (record->event.pressed) {
          tap_code16(ES_ACUT);
          tap_code16(KC_E);
        }
        break;
    case JJ_IACUTE:
        if (record->event.pressed) {
          tap_code16(ES_ACUT);
          tap_code16(KC_I);
        }
        break;
    case JJ_OACUTE:
        if (record->event.pressed) {
          tap_code16(ES_ACUT);
          tap_code16(KC_O);
        }
        break;
    case JJ_UACUTE:
        if (record->event.pressed) {
          tap_code16(ES_ACUT);
          tap_code16(KC_U);
        }
        break;
    case JJ_TILD:
      if (record->event.pressed) {
        tap_code16(ALGR(ES_NTIL));
      }
      break;
    }
    return true;
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-------------------------------------------------------------------------------------------------.
 * |  Q   |   W  |   E  |   R  |   T         |      |      |   Y         |   U  |   I  |   O  |  P   |
 * |------+------+------+------+-------------+------+------+-------------+------+------+------+------|
 * |  A   |   S  |   D  |   F  |   G / _ES   |      |      |   H / _ES   |   J  |   K  |   L  |  <   |
 * |------+------+------+------+-------------+------+------+-------------+------+------+------+------|
 * |  Z   |   X  |   C  |   V  |   B         |      |      |   N         |   M  |   ,  |   .  |  '   |
 * |------+------+------+------+-------------+------+------+-------------+------+------+------+------|
 * |      |      | Alt  | Cmd  | Lower / Spc |             | Raise / Rtr |  Cmd | Alt  |      |      |
 * `-------------------------------------------------------------------------------------------------'
 */

[_QWERTY] = LAYOUT_planck_mit(
                              KC_Q,                  KC_W,    KC_E,    KC_R,    KC_T,    _______,  _______,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
                              MT(MOD_LCTL, KC_A),    KC_S,    KC_D,    MT(MOD_LSFT, KC_F), LT(_ES, KC_G),    _______,  _______, LT(_ES, KC_H),    MT(MOD_RSFT, KC_J), KC_K, KC_L,    MT(MOD_RCTL, ES_MORD),
                              KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,  _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  ES_QUOT,
                              _______, _______, KC_LALT, KC_LGUI, LT(_LOWER, KC_SPC),         _______     ,  LT(_RAISE, KC_ENT), KC_RGUI, KC_RALT, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   =  |   7  |   8  |   9  |  0   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   +  |   4  |   5  |   6  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   *  |   1  |   2  |   3  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Alt  | Cmd  |      |             |      | Cmd  | Alt  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
                             _______, _______, _______, _______, _______, _______, _______, KC_PEQL, KC_P7,               KC_P8, KC_P9, KC_P0,
                             KC_LCTL, _______, _______, KC_LSFT, _______, _______, _______, KC_PPLS, MT(MOD_RSFT, KC_P4), KC_P5, KC_P6, MT(MOD_RCTL, KC_PMNS),
                             _______, _______, _______, _______, _______, _______, _______, KC_PAST, KC_P1,               KC_P2, KC_P3, KC_PSLS,
                             _______, _______, KC_LALT, KC_LGUI, _______,      _______    , _______, KC_RGUI,             KC_RALT, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |      |      |   ^  |   &  |   (  |   )  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |   ~  |   `  |   [  |   ]  |  ?   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F6  |  F7  |  F8  |  F9  |  F10 |      |      |   "  |   _  |   {  |   }  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Alt  | Cmd  |      |             |      | Cmd  | Alt  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
                             KC_EXLM, ES_AT, ES_HASH,    KC_DLR, KC_PERC, _______, _______, ES_CIRC, ES_AMPR, ES_LPRN, ES_RPRN, ES_PIPE,
                             KC_F1,   KC_F2,   KC_F3,     KC_F4,   KC_F5, _______, _______, JJ_TILD,  MT(MOD_RSFT, ES_GRV), ES_LBRC, ES_RBRC, ES_QUES,
                             KC_F6,   KC_F7,   KC_F8,     KC_F9,  KC_F10, _______, _______, ES_DQUO, ES_UNDS, ES_LCBR, ES_RCBR, LALT(ES_LABK),
                             _______, _______, KC_LALT, KC_LGUI, _______,     _______     , _______, KC_RGUI, KC_RALT, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  Up  |      | MCtrl|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Right|      |      |      |      | Vol- | Vol+ | Mute |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Reset| Boot |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
                              _______, _______,   KC_UP,  _______,C(KC_UP), _______, _______, _______, _______, _______, _______, _______,
                              _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,
                              _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,  QK_RBT, QK_BOOT,
                              _______, _______, _______,  _______, _______,      _______    , _______, _______, _______, _______, _______
),

/* ES characters
 * ,-----------------------------------------------------------------------------------.
 * |   º  |  ª   |   é  |      |      |      |      |      |  ú   |  í   |  ó   |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  á   |      |      |      |      |      |      |      |      |  ¨   |  ¡   |   ¿  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   ç  |      |      |      |      |   ñ  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  Alt | Cmd  |      |             | Cmd  | Alt  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ES] = LAYOUT_planck_mit(
                          ES_LABK,   S(ES_LABK), JJ_EACUTE, _______, _______, _______, _______,   _______, JJ_UACUTE, JJ_IACUTE, JJ_OACUTE,  KC_DEL,
                          JJ_AACUTE, _______,   _______, _______, _______, _______, _______,   _______,   _______,   ES_DIAE, MT(MOD_RSFT, ES_IEXL), ES_IQUE,
                          _______,   _______,   ES_CCED, _______, _______, _______, _______,   ES_NTIL,   _______,   _______,   _______, _______,
                          _______,   _______,   KC_LALT, KC_LGUI, _______,     _______     ,   _______,   KC_RGUI,   KC_RALT,   _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

