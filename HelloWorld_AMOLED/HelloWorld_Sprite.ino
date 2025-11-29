/*
 * Hello World - LilyGo T-Display-S3-AMOLED-Touch
 * Versão CORRIGIDA usando TFT_eSPI com Sprites
 *
 * Baseado no exemplo oficial: TFT_eSPI_Sprite
 * https://github.com/Xinyuan-LilyGO/T-Display-S3-AMOLED
 *
 * IMPORTANTE:
 * - Este código usa os arquivos rm67162.h e pins_config.h inclusos
 * - NÃO precisa instalar biblioteca adicional LilyGo
 * - Apenas instale TFT_eSPI via Gerenciador de Bibliotecas
 *
 * Instalação:
 * 1. Arduino IDE → Sketch → Include Library → Manage Libraries
 * 2. Procure: "TFT_eSPI" e instale
 * 3. Compile este sketch (os arquivos .h estão na mesma pasta)
 */

#include "rm67162.h"
#include <TFT_eSPI.h>

// Sprite funciona como um framebuffer na memória
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite spr = TFT_eSprite(&tft);

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("\n========================================");
  Serial.println("LilyGo T-Display-S3-AMOLED - Hello World");
  Serial.println("========================================\n");

  // PASSO 1: Liga o LED/Display
  Serial.println("1. Ligando display...");
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, HIGH);
  delay(100);

  // PASSO 2: Inicializa o driver RM67162
  Serial.println("2. Inicializando driver RM67162...");
  rm67162_init();

  // PASSO 3: Define rotação
  Serial.println("3. Configurando rotacao...");
  lcd_setRotation(1);  // 0, 1, 2 ou 3

  // PASSO 4: Cria o sprite (framebuffer)
  Serial.println("4. Criando sprite...");
  spr.createSprite(536, 240);  // WIDTH x HEIGHT
  spr.setSwapBytes(1);  // Importante para cores corretas!

  Serial.println("5. Desenhando no sprite...");

  // Limpa com preto
  spr.fillSprite(TFT_BLACK);

  // Desenha "Hello World!" em BRANCO
  spr.setTextColor(TFT_WHITE, TFT_BLACK);
  spr.setTextSize(3);
  spr.drawString("Hello World!", 120, 90);

  // Texto adicional em CIANO
  spr.setTextColor(TFT_CYAN, TFT_BLACK);
  spr.setTextSize(2);
  spr.drawString("LilyGo T-Display-S3", 100, 140);

  // Texto em VERDE
  spr.setTextColor(TFT_GREEN, TFT_BLACK);
  spr.drawString("AMOLED Touch", 160, 170);

  // PASSO 5: Envia o sprite para o display
  Serial.println("6. Enviando para o display...");
  lcd_PushColors(0, 0, 536, 240, (uint16_t*)spr.getPointer());

  Serial.println("\n========================================");
  Serial.println("SUCESSO! Hello World no display!");
  Serial.println("========================================\n");
}

void loop() {
  // Alterna cores do "Hello World!" a cada 2 segundos
  static unsigned long lastUpdate = 0;
  static int colorIndex = 0;
  static uint16_t colors[] = {TFT_WHITE, TFT_YELLOW, TFT_CYAN, TFT_MAGENTA, TFT_RED, TFT_GREEN};
  static const char* colorNames[] = {"BRANCO", "AMARELO", "CIANO", "MAGENTA", "VERMELHO", "VERDE"};

  if (millis() - lastUpdate > 2000) {
    lastUpdate = millis();

    // Limpa a área do texto
    spr.fillRect(100, 80, 350, 35, TFT_BLACK);

    // Desenha com nova cor
    spr.setTextColor(colors[colorIndex], TFT_BLACK);
    spr.setTextSize(3);
    spr.drawString("Hello World!", 120, 90);

    // Atualiza apenas a área que mudou
    lcd_PushColors(0, 0, 536, 240, (uint16_t*)spr.getPointer());

    Serial.println("Cor: " + String(colorNames[colorIndex]));

    colorIndex = (colorIndex + 1) % 6;
  }

  delay(10);
}
