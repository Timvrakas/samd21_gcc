So this is a SAMD21 build template. just `make` in the this directory, and the `build` directory will provide you project `.bin`s.

You can upload this to a SAM-BA bootloader device with the `upload.sh` script, which calls `bossac`

To configure source selection, edit config.mk and include all the libraries/code you wish to use.

To configure Board/Clock config edit header files in `board/`. The `board.h` file defines the intransient properties of the given MCU configuration, while `conf_board.h` defines an application specific configuration. `conf_clocks.h` defines the clock configuration.

I probably broke the doxygen. Sorry.

Eventually this will be a PlatformIO framework?
