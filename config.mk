#
# Copyright (c) 2011 Atmel Corporation. All rights reserved.
#
# \asf_license_start
#
# \page License
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. The name of Atmel may not be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# 4. This software may only be redistributed and used in connection with an
#    Atmel microcontroller product.
#
# THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
# EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# \asf_license_stop
#

# Path to top level ASF directory relative to this project directory.
PRJ_PATH = ./

BUILD_DIR = build/

# Target CPU architecture: cortex-m3, cortex-m4
ARCH = cortex-m0plus

# Target part: none, sam3n4 or sam4l4aa
PART = samd21g18a

# Application target name. Given with suffix .a for library and .elf for a
# standalone application.
TARGET_FLASH = build/output_flash.elf
TARGET_SRAM = build/output_sram.elf

# List of C source files.
CSRCS = \
       ASF/common/utils/interrupt/interrupt_sam_nvic.c        \
       src/led_toggle.c          \
       board/board_init.c       \
       ASF/sam0/drivers/port/port.c                           \
       ASF/sam0/drivers/system/clock/clock_samd21_r21_da_ha1/clock.c \
       ASF/sam0/drivers/system/clock/clock_samd21_r21_da_ha1/gclk.c \
       ASF/sam0/drivers/system/interrupt/system_interrupt.c   \
       ASF/sam0/drivers/system/pinmux/pinmux.c                \
       ASF/sam0/drivers/system/system.c                       \
       ASF/sam0/utils/cmsis/samd21/source/gcc/startup_samd21.c \
       ASF/sam0/utils/cmsis/samd21/source/system_samd21.c     \
       ASF/sam0/utils/syscalls/gcc/syscalls.c

# List of assembler source files.
ASSRCS = 

# List of include paths.
INC_PATH = \
       include                                                \
       conf                                                   \
       ASF	                                              \
       ASF/common/boards                                      \
       ASF/common/utils                                       \
       ASF/sam0/boards                                        \
       board                    \
       ASF/sam0/drivers/port                                  \
       ASF/sam0/drivers/system                                \
       ASF/sam0/drivers/system/clock                          \
       ASF/sam0/drivers/system/clock/clock_samd21_r21_da_ha1  \
       ASF/sam0/drivers/system/interrupt                      \
       ASF/sam0/drivers/system/interrupt/system_interrupt_samd21 \
       ASF/sam0/drivers/system/pinmux                         \
       ASF/sam0/drivers/system/power                          \
       ASF/sam0/drivers/system/power/power_sam_d_r_h          \
       ASF/sam0/drivers/system/reset                          \
       ASF/sam0/drivers/system/reset/reset_sam_d_r_h          \
       ASF/sam0/utils                                         \
       ASF/sam0/utils/cmsis/samd21/include                    \
       ASF/sam0/utils/cmsis/samd21/source                     \
       ASF/sam0/utils/header_files                            \
       ASF/sam0/utils/preprocessor                            \
       ASF/thirdparty/CMSIS/Include                           \
       ASF/thirdparty/CMSIS/Lib/GCC \
       ASF/sam0/applications/led_toggle/samd21_xplained_pro/gcc

# Additional search paths for libraries.
LIB_PATH =  \
       ASF/thirdparty/CMSIS/Lib/GCC                          

# List of libraries to use during linking.
LIBS =  \
       arm_cortexM0l_math                                

# Path relative to top level directory pointing to a linker script.
LINKER_SCRIPT_FLASH = ASF/sam0/utils/linker_scripts/samd21/gcc/samd21g18a_samba.ld #NOTE: THIS IS SETUP FOR SAM-BA!
LINKER_SCRIPT_SRAM  = ASF/sam0/utils/linker_scripts/samd21/gcc/samd21g18a_sram.ld

# Path relative to top level directory pointing to a linker script.
DEBUG_SCRIPT_FLASH = board/debug/flash.gdb
DEBUG_SCRIPT_SRAM  = board/debug/sram.gdb

# Project type parameter: all, sram or flash
PROJECT_TYPE        = flash

# Additional options for debugging. By default the common Makefile.in will
# add -g3.
DBGFLAGS = 

# Application optimization used during compilation and linking:
# -O0, -O1, -O2, -O3 or -Os
OPTIMIZATION = -O1

# Extra flags to use when archiving.
ARFLAGS = 

# Extra flags to use when assembling.
ASFLAGS = 

# Extra flags to use when compiling.
CFLAGS = 

# Extra flags to use when preprocessing.
#
# Preprocessor symbol definitions
#   To add a definition use the format "-D name[=definition]".
#   To cancel a definition use the format "-U name".
#
# The most relevant symbols to define for the preprocessor are:
#   BOARD      Target board in use, see boards/board.h for a list.
#   EXT_BOARD  Optional extension board in use, see boards/board.h for a list.
CPPFLAGS = \
       -D ARM_MATH_CM0PLUS=true                           \
       -D BOARD=SFE_MINI                       \
       -D __SAMD21G18A__

# Extra flags to use when linking
LDFLAGS = \

# Pre- and post-build commands
PREBUILD_CMD = 
POSTBUILD_CMD = 
