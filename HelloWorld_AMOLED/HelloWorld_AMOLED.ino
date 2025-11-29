/*
 * Hello World - LilyGo T-Display-S3-AMOLED-Touch
 *
 * Este código exibe "Hello World" no display AMOLED da placa LilyGo T-Display-S3
 *
 * Bibliotecas necessárias:
 * - TFT_eSPI (configurada para RM67162 AMOLED)
 * - OU use a biblioteca específica: https://github.com/Xinyuan-LilyGO/T-Display-S3-AMOLED
 *
 * Para instalar:
 * 1. Instale o suporte para ESP32-S3 no Arduino IDE
 * 2. Instale a biblioteca TFT_eSPI ou a biblioteca LilyGo AMOLED
 * 3. Configure a placa como "ESP32S3 Dev Module"
 */

#include <TFT_eSPI.h>
#include <SPI.h>

// Inicializa o display
TFT_eSPI tft = TFT_eSPI();

// Definições de pinos para LilyGo T-Display-S3-AMOLED
#define TFT_BL 38  // Backlight (geralmente não usado em AMOLED, mas pode controlar brilho)
#define PIN_POWER_ON 15  // Pino de alimentação do display

void setup() {
  // Inicializa comunicação serial para debug
  Serial.begin(115200);
  delay(100);

  Serial.println("Iniciando LilyGo T-Display-S3-AMOLED...");

  // Liga o display
  pinMode(PIN_POWER_ON, OUTPUT);
  digitalWrite(PIN_POWER_ON, HIGH);

  // Inicializa o display TFT
  tft.init();
  tft.setRotation(1);  // Ajuste conforme necessário (0-3)

  // Limpa a tela com fundo preto
  tft.fillScreen(TFT_BLACK);

  // Configura o texto
  tft.setTextColor(TFT_WHITE, TFT_BLACK);  // Texto branco, fundo preto
  tft.setTextSize(3);  // Tamanho do texto

  // Centraliza e exibe "Hello World"
  tft.setCursor(60, 100);  // Posição aproximada para centralizar
  tft.println("Hello World!");

  // Adiciona mais informações
  tft.setTextSize(2);
  tft.setCursor(40, 150);
  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.println("LilyGo T-Display-S3");

  tft.setCursor(80, 180);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.println("AMOLED Touch");

  Serial.println("Hello World exibido no display!");
}

void loop() {
  // Efeito de piscada suave (opcional)
  static unsigned long lastBlink = 0;
  static bool showText = true;

  if (millis() - lastBlink > 2000) {  // Pisca a cada 2 segundos
    lastBlink = millis();
    showText = !showText;

    if (showText) {
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextSize(3);
      tft.setCursor(60, 100);
      tft.println("Hello World!");
    } else {
      tft.setTextColor(TFT_YELLOW, TFT_BLACK);
      tft.setTextSize(3);
      tft.setCursor(60, 100);
      tft.println("Hello World!");
    }
  }

  delay(10);
}
