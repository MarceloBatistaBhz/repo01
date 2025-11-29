// Configuração TFT_eSPI para LilyGo T-Display-S3-AMOLED
// Copie este arquivo para a pasta da biblioteca TFT_eSPI como User_Setup.h
// Caminho típico: Arduino/libraries/TFT_eSPI/User_Setup.h

#define USER_SETUP_INFO "T-Display-S3-AMOLED"

// Driver do display
#define RM67162_DRIVER

// Resolução do display AMOLED
#define TFT_WIDTH  536
#define TFT_HEIGHT 240

// Pinos SPI e controle
#define TFT_QSPI_CS   6
#define TFT_QSPI_SCK  47
#define TFT_QSPI_D0   18
#define TFT_QSPI_D1   7
#define TFT_QSPI_D2   48
#define TFT_QSPI_D3   5
#define TFT_QSPI_RST  17

// Pino de alimentação do display
#define TFT_BL   38

// Fonte padrão
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF

#define SMOOTH_FONT

// Velocidade SPI
#define SPI_FREQUENCY       40000000
#define SPI_READ_FREQUENCY  16000000
#define SPI_TOUCH_FREQUENCY  2500000

// Suporte para DMA
#define ESP32_DMA_CHANNEL 1
