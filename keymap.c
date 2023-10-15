/*
Copyright 2023 Hannah Blythe Morrison

This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version HBM_LAYOUT_3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "hbmorrison.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = HBM_LAYOUT_FERRIS( HBM_LAYOUT_3x5_2_BASE ),
  [LAYER_SYM] = HBM_LAYOUT_FERRIS( HBM_LAYOUT_3x5_2_SYM ),
  [LAYER_NAV] = HBM_LAYOUT_FERRIS( HBM_LAYOUT_3x5_2_NAV ),
  [LAYER_NUM] = HBM_LAYOUT_FERRIS( HBM_LAYOUT_3x5_2_NUM ),
  [LAYER_SCUT] = HBM_LAYOUT_FERRIS( HBM_LAYOUT_3x5_2_SCUT )
};
