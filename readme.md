# Hannah's Ferris Sweep Layout

This is my first attempt at a layout for my new Ferris Sweep. I have chosen
learn Colemak DH - my first alternative keyboard layout - so I have tried to
take my cues for numbers and symbols from the UK ISO keyboard layout to keep
everything else as familiar as possible.

Broadly speaking, this is designed as a layout where keys and modifiers are
tapped rather than held down. Aside from the use of home row modifier keys there
is no chording required and I try to use tap dancing as an alternative for
common situations where chording would otherwise be called for.

In practice, a single tap of the layer key gets to the symbol layer and a double
tap of the same layer key gets to the number and navigation layer. Most of the
time you will be tapping this layer key, hitting a symbol then carrying on in
the base layer. Also, wherever you are, tapping the space or enter key will
bring you back to the base layer. The idea is that you should not have to think
too much about which layer you are in most of the time.

### Credit

I want to give full credit and a massive amount of thanks to [Ben
Vallack](https://www.youtube.com/benvallack) for talking through his
tap-not-hold approach and for all of his inspirational work on ergonomic
keyboards and layouts. My initial layout drew heavily from his [Ferris Sweep
layout](https://github.com/benvallack/34-QMK-Ferris-Sweep).

The contributers who make QMK possible are an incredible bunch of people and the
ErgoMechKeyboard community as a whole has been welcoming and helpful. Please
support open source projects and communities, folks.

## Base Layer

![Base Layer](https://i.imgur.com/rQCSlum.png)

The base layer uses [Colemak DH](https://colemakmods.github.io/mod-dh/)
[2020](https://forum.colemak.com/topic/2638-announcement-a-change-to-colemakdh/),
with a `Shift` thumb key on the outside left , a `Space` thumb key on the inside
left, an `Enter` thumb key on the inside right and a `Sym Layer` thumb key on
the outside right. The `Backspace` key is available at the top right.

When tapped, the `Shift` thumb key capitalises or shifts the next key that is
tapped. It does nothing when held down. The `Sym Layer` thumb key switches the
keyboard into the **symbol layer** for one key press only, and the keyboard will
return to the **base layer** immediately after a symbol key has been tapped.

Tap dance is enabled and double taps on the following keys produce different key
presses:

* Double tapping the `Z` key produces `Caps Lock`
* Double tapping the `X` key produces `Ctrl-X` (i.e. cut)
* Double tapping the `C` key produces `Ctrl-V` (i.e. copy)
* Double tapping the `V` key produces `Ctrl-C` (i.e. paste)
* Double tapping the `F` key produces `Ctrl-F` (i.e. page down in Vim)
* Double tapping the `B` key produces `Ctrl-B` (i.e. page up in Vim)

Home row modifiers are available on the following keys:

* Hold `R` or `I` for `Win`
* Hold `S` or `E` for `Alt`
* Hold `T` or `N` for `Ctrl`

These keys can be held down alone or in combination. For example, on Windows you
might hold down the `E` key - for `Alt` - then tap `F` followed by `S` to access
the File menu followed by the Save menu entry. Or, if you use 1Password, you
might hold down `N` - for `Ctrl`- then tap `Shift` followed by `Space` to pull
up the 1Password quick access window.

The `Space` key can be held to produce the `Hyper` modifier, which is actually
the combination of the `Shift`, `Ctrl`, `Alt` and `Win` keys pressed
together. This can be used to bind global shortcuts using programs like
AutoHotKey.

## Symbol Layer

![Symbol Layer](https://i.imgur.com/zaIR99n.png)

The **symbol layer** is influenced by the way symbols are laid out on UK ISO
keyboards. The symbols usually found above `2` to `8` are on the top row. The
`Minus` / `Underscore` and `Equals` / `Plus` keys are on the right side as pairs
of separate keys. The `Esc` and `Tab` keys are on the far left side.

In the middle there are more pairs of keys that are usually found to the right
of the middle row: `Hash` / `Tilde` , `Quote` / `At`  and `Semicolon` / `Colon`.
The `Exclamation Mark` key is on the bottom right, which would have appeared in
the `1` position if there was space, but which is now placed on the same key as
the `Slash/Question mark` key in the base layer as a compromise. The `Grave` key
appears beside it, also in a compromise position.

Most of the left side is taken up by pairs of braces and brackets. The
`Backslash` / `Pipe` key pair is on the outside of the left side and the `Func
Layer` key at the bottom left switches the keyboard into the **function layer**.

The `Nav Layer` thumb key on the outside right switches the keyboard into the
**number and navigation layer**. The `Space` and `Enter` thumb keys remain on
the inside left and right, and the outside left thumb key becomes `Base Layer`,
which returns the keyboard to the **base layer**.

As well as producing their respective key presses, the `Space` and `Enter` thumb
keys will also return the keyboard to the **base layer** when tapped.

## Number and Navigation Layer

![Number and Navigation Layer](https://i.imgur.com/zfo0K7G.png)

The top row is taken up by numbers as they appear on standard-sized keyboards.
On the right side there are arrow keys arranged in the traditional Vim
navigation format (like `HJKL` in QWERTY keyboards) with the `Home`, `Page
Down`, `Page Up` and `End` keys below them. The `Delete` and `Insert` keys are
on the inside right.

There are a set of modified `Tab` keys on the left hand side for navigating
between tabs and windows: `Ctrl-Tab`, `Alt-Tab` and `Win-Tab`. In addition,
for Windows 11, there are two macros bound to keys that will switch to previous
and next virtual desks. The `Left Button` and `Right Button` keys serve as
alternative mouse buttons when using an external trackball or trackpad.

On the bottom left the `Func Layer` key switches the keyboard into the
**function layer**.

Finally, the `Capital-V` key is a Vim shortcut for entering visual mode while
navigating.

The thumb keys remain consistent: the `Space` and `Enter` thumb keys are on the
inside and the `Base Layer` thumb key is on the outside left. As with the symbol
layer, all three of these keys return the keyboard to the **base layer**.

## Function Layer

![Function Layer](https://i.imgur.com/MhngS8s.png)

Twelve function keys take up most of the left side. When any of the function
keys are tapped the keyboard returns to the **base layer**.

Media controls are on the inside of the left side. These keys are sticky so
music tracks can be skipped, played and paused without the layer changing.
Volume adjustment, mute and screen brightness adjustment keys are on the inside
of the right side. These keys are also sticky so they can be tapped repeatedly.

The rest of the right side has a number of symbols that can be used in
conjunction with the number layer to perform calculations. When any of these
symbols are tapped the keyboard will return to the **number and navigation
layer**. This is intended to simplify working with a calculator. The positions
of the symbols mirror their positions in lower layers.

Again, the thumb keys remain consistent: the `Space` and `Enter` thumb keys are
on the inside and the `Base Layer` thumb key is on the outside left. All three
of these keys return the keyboard to the **base layer**.

The `Sym Layer` thumb key reappears on the far right to return the keyboard to
the **symbol layer**. This means that a double tap of the thumb key will return
the keyboard to the **number and navigation layer**.

## Layer Navigation

The layer navigation keys are designed so that you can move between layers in a
predictable way without having to know which layer you are currently in.

**To get to the base layer** tap the *outside right* followed by the *outside
left* thumb keys.

**To get to the number layer** tap the *outside right* thumb key twice.

**To get to the function layer** tap the *outside right* thumb key followed by
the *bottom left* key.

**To get to the symbol layer** tap the *outside right*, *outside left* then
*outside right* thumb keys.

This last sequence of taps is mostly unnecessary. Most of the time, you will
have just pressed `Space` or `Enter`, or you will have typed a letter or a
symbol, and you will know that you are in the **base layer**, so you will only
have to tap the *outside right* thumb key once to reach the **symbol layer**.

Strictly speaking, the same could be said about the first sequence of taps as
well, but is useful to remember *outside right*, *outside left* as a panic
sequence of sorts to get back to the beginning and clear your head.

##  How To Compile and Flash RP2040 Firmware

First compile the firmware as normal:

```shell
qmk compile -kb ferris/sweep -km hbmorrison
```

Then convert the `ferris_sweep_hbmorrison.hex` file to a `.uf2` file for the
rp2040 controller by running:

```shell
make CONVERT_TO=kb2040 ferris/sweep:hbmorrison:uf2-split-left
```

Once the conversion has completed, the make command will wait for the keyboard
bootloader to be mounted. Unplug the USB cable from the Ferris Sweep, hold down
the top left key and, while holding the key down, plug the USB cable back into
the **left-hand side controller** on the keyboard.
