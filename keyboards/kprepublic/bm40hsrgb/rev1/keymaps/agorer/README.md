# Steps to flash firmware (https://docs.qmk.fm/newbs_flashing):

1. Compile firmware

```
# qmk compile
```

2. Open QMK Toolbox

3. Set keyboard in bootloader mode (after this the keyboard stops working, you could go back with the `Exit DFU` button on QMK Toolbox) by tapping QK_BOOT 

4. Send firmware to keyboard memory (when finished keyboars will start working again)

```
# qmk flash
```

# List of available keys

https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

# Using spanish layout

https://docs.qmk.fm/reference_keymap_extras
