# hw definition file for WARG L431 CAN Nodes
# Largely based off of MatekL431 can nodes

# MCU class and specified type
MCU STM32L431 STM32L431xx

# bootloader starts firmware at 36k + 4k (STORAGE_FLASH)
FLASH_RESERVE_START_KB 40
FLASH_SIZE_KB 256

# store parameters in pages 18 and 19
STORAGE_FLASH_PAGE 18
define HAL_STORAGE_SIZE 800

# ChibiOS system timer
STM32_ST_USE_TIMER 15
define CH_CFG_ST_RESOLUTION 16

# board ID for firmware load
APJ_BOARD_ID 2000

# crystal frequency
OSCILLATOR_HZ 8000000

env AP_PERIPH 1

STDOUT_SERIAL SD1
STDOUT_BAUDRATE 57600

define HAL_NO_GPIO_IRQ
define SERIAL_BUFFERS_SIZE 512
define PORT_INT_REQUIRED_STACK 64

define DMA_RESERVE_SIZE 0

# MAIN_STACK is stack for ISR handlers
MAIN_STACK 0x300

# PROCESS_STACK controls stack for main thread
PROCESS_STACK 0xA00

# we setup a small defaults.parm 
define AP_PARAM_MAX_EMBEDDED_PARAM 512

# no state of life led's 
# PBX LED OUTPUT HIGH
# define HAL_LED_ON 1

# debugger support
PA13 JTMS-SWDIO SWD
PA14 JTCK-SWCLK SWD

# ------------------CAN -------------------------
# I do not know what CAN_ORDER Does
CAN_ORDER 1
PA11 CAN1_RX CAN1
PA12 CAN1_TX CAN1

# also have no clue what HAL_CAN_POOL_SIZE means
define HAL_CAN_POOL_SIZE 6000

# allow for reboot command for faster development
# define HAL_PERIPH_LISTEN_FOR_SERIAL_UART_REBOOT_CMD_PORT 0

# keep ROMFS uncompressed as we don't have enough RAM
# to uncompress the bootloader at runtime
env ROMFS_UNCOMPRESSED True