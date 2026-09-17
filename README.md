# QMK Keymap Automail

## Overview

My Goal Was To Create an Efficient and Easy-To-Use Keymap.

Feel Free To Contribute to This Keymap or Use It as a Base for Your Own!

If You Are Wondering Why I Call It "Automail", It Is an FMAB Reference ;).

The Following Is an Overview of What This Keymap Is and What Features It Has.

Additionally, I Did Some Simple Latency Optimizations by:
- Reducing the Key Debounce Time and Forcing a 1000 Hz Polling Rate.

```
Automail - The Mechanical Armor

This Keymap Is Designed for the Lotus 58 Glow Keyboard and Features a Custom Layout Based on the Colemak-DH Mod, With Tap Dance Integration For German Umlauts (Ä, Ö, Ü) and Eszett (ß).

Operating System Requirement:
- Requires the Host Operating System Input Layout To Be Set to EurKEY (Or a Compatible AltGr Layout) For the Tap Dance Umlaut and Eszett Shortcuts To Function Properly.

Features:
- Custom Layout Based on the Colemak-DH Mod With Tap Dance for German Special Characters.
- Dedicated Navigation, Symbol, System, and Fallback (QWERTY) Layers.
- Rotary Encoder Mapping for Volume Control.
- OLED Display Featuring a 32x32 Pixel Art, Indicating Active Layers, Caps Lock State, and Auto-Shift State.
```

## How To Use It?

1. QMK - [Setup Your Environment](https://docs.qmk.fm/newbs_getting_started)
2. Replace `qmk_firmware/keyboards/tweetydabird/lotus58` Files With This Repository Files.
3. QMK - [Building Your First Firmware](https://docs.qmk.fm/newbs_building_firmware)
4. QMK - [Flashing Your Keyboard](https://docs.qmk.fm/newbs_flashing)

Note:
- With the Current Configuration, the Firmware Is Compiled for an RP2040 MCU With Outputs an `.uf2`.
- A Pre-Compiled Version of the Firmware Can Be Found at `firmware/`.
- If You Want To Change That Behavior, Adjust the `keymaps/Automail/keymap.json`.

## Useful

- [QMK Firmware Docs](https://docs.qmk.fm/)
- [EurKey - The European Keyboard Layout](https://eurkey.steffen.bruentjen.eu/)
- [Colemak Mod-DH - A Colemak Mod for More Comfortable Typing.](https://colemakmods.github.io/mod-dh/keyboards.html#matrix-keyboards)

## License
This Project Is Licensed Under the `GPL-2.0-or-later` License:

- [GPL-3.0 License](LICENSE)
