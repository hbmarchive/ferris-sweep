/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// Enable kinetic mouse
#define MK_KINETIC_SPEED

// Set the mouse settings to a comfortable speed/accuracy trade-off, assuming a
// screen refresh rate of 60 Htz or higher The default is 50. This makes the
// mouse ~3 times faster and more accurate
#define MOUSEKEY_INTERVAL 16

// The default is 20. Since we made the mouse about 3 times faster with the
// previous setting, give it more time to accelerate to max speed to retain
// precise control over short distances.
#define MOUSEKEY_TIME_TO_MAX 40

// The default is 300. Let's try and make this as low as possible while keeping
// the cursor responsive
#define MOUSEKEY_DELAY 100

// It makes sense to use the same delay for the mouseweel
#define MOUSEKEY_WHEEL_DELAY 100

// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 50

// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100

// Vaguely tuned settings for kinetic mouse wheel
#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 12
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS 32
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 32
#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 12

// Default tapping term
#define TAPPING_TERM 190
#define PERMISSIVE_HOLD
#define TAPPING_TERM_PER_KEY

// Tapping term for the homerow mod keys
#define TAPPING_TERM_MODS 550

// Tapping term for tapdance keys
#define TAPPING_TERM_TAPDANCE 160

// Enable key repeat - disabled for now
// #define QUICK_TAP_TERM 100
