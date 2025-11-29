/*
 * Configuração de Pinos para LilyGo T-Display-S3-AMOLED
 * Baseado no exemplo oficial do repositório LilyGo
 */

#pragma once

// Ativa driver QSPI (mais rápido que SPI normal)
#define LCD_USB_QSPI_DREVER 1

// Configurações SPI
#define SPI_FREQUENCY       75000000  // 75 MHz
#define TFT_SPI_MODE        SPI_MODE0
#define TFT_SPI_HOST        SPI2_HOST

// Resolução do LCD
#define EXAMPLE_LCD_H_RES   536
#define EXAMPLE_LCD_V_RES   240
#define LVGL_LCD_BUF_SIZE   (EXAMPLE_LCD_H_RES * EXAMPLE_LCD_V_RES)

// Dimensões (TFT_WIDTH e TFT_HEIGHT dependem da rotação)
#define TFT_WIDTH           240
#define TFT_HEIGHT          536
#define SEND_BUF_SIZE       (0x4000)  // 16KB buffer

// Pinos SPI Tradicionais
#define TFT_TE              9
#define TFT_SDO             8
#define TFT_DC              7
#define TFT_RES             17
#define TFT_CS              6
#define TFT_MOSI            18
#define TFT_SCK             47

// Pinos QSPI (Quad SPI - 4x mais rápido)
#define TFT_QSPI_CS         6
#define TFT_QSPI_SCK        47
#define TFT_QSPI_D0         18
#define TFT_QSPI_D1         7
#define TFT_QSPI_D2         48
#define TFT_QSPI_D3         5
#define TFT_QSPI_RST        17

// Pinos de Periféricos
#define PIN_LED             38  // LED / Controle do display
#define PIN_BAT_VOLT        4   // Leitura de voltagem da bateria
#define PIN_BUTTON_1        0   // Botão 1
#define PIN_BUTTON_2        21  // Botão 2 (também Touch Reset em alguns modelos)

// Aliases
#define PIN_TOUCH_RES       PIN_BUTTON_2
#define PIN_POWER_ON        PIN_LED
