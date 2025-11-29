/*
 * Hello World - LilyGo T-Display-S3-AMOLED-Touch
 * Versão TFT_eSPI CORRIGIDA com diagnósticos
 *
 * IMPORTANTE: A biblioteca TFT_eSPI precisa ser configurada corretamente!
 *
 * Configuração TFT_eSPI:
 * 1. Localize a pasta da biblioteca TFT_eSPI:
 *    Windows: Documents\Arduino\libraries\TFT_eSPI
 *    Mac: ~/Documents/Arduino/libraries/TFT_eSPI
 *    Linux: ~/Arduino/libraries/TFT_eSPI
 *
 * 2. Edite o arquivo User_Setup_Select.h e comente a linha:
 *    // #include <User_Setup.h>
 *
 * 3. Adicione esta linha no lugar:
 *    #include <User_Setups/Setup206_LilyGo_T_Display_S3.h>
 *
 * OU copie o conteúdo do arquivo User_Setup_AMOLED.h para User_Setup.h
 */

#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();

// Pinos específicos para LilyGo T-Display-S3-AMOLED
#define PIN_POWER_ON 15   // Pino de power - CRÍTICO!
#define PIN_TOUCH_RES 21  // Touch reset

void setup() {
  Serial.begin(115200);
  delay(2000);  // Aumentado para dar tempo de abrir o Serial Monitor

  Serial.println("\n\n========================================");
  Serial.println("LilyGo T-Display-S3-AMOLED - Diagnóstico");
  Serial.println("========================================\n");

  // PASSO 1: Ligar alimentação do display
  Serial.println("1. Ligando alimentacao do display...");
  pinMode(PIN_POWER_ON, OUTPUT);
  digitalWrite(PIN_POWER_ON, HIGH);
  delay(100);
  Serial.println("   [OK] Display alimentado");

  // PASSO 2: Reset do touch (ajuda a estabilizar)
  Serial.println("2. Resetando touch controller...");
  pinMode(PIN_TOUCH_RES, OUTPUT);
  digitalWrite(PIN_TOUCH_RES, LOW);
  delay(10);
  digitalWrite(PIN_TOUCH_RES, HIGH);
  delay(50);
  Serial.println("   [OK] Touch resetado");

  // PASSO 3: Inicializar display
  Serial.println("3. Inicializando TFT_eSPI...");
  tft.init();
  Serial.println("   [OK] TFT inicializado");

  // PASSO 4: Configurar orientação
  Serial.println("4. Configurando orientacao...");
  tft.setRotation(1);  // 0, 1, 2 ou 3 - teste diferentes valores!
  Serial.println("   [OK] Rotacao definida como 1");

  // PASSO 5: Teste de preenchimento de tela
  Serial.println("5. Testando cores basicas...");

  Serial.println("   - Vermelho...");
  tft.fillScreen(TFT_RED);
  delay(500);

  Serial.println("   - Verde...");
  tft.fillScreen(TFT_GREEN);
  delay(500);

  Serial.println("   - Azul...");
  tft.fillScreen(TFT_BLUE);
  delay(500);

  Serial.println("   - Preto...");
  tft.fillScreen(TFT_BLACK);
  delay(500);
  Serial.println("   [OK] Teste de cores concluido");

  // PASSO 6: Desenhar texto
  Serial.println("6. Desenhando texto...");

  // Configurar texto
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(3);
  tft.setTextDatum(MC_DATUM);  // Centralizado

  // Desenhar no centro da tela
  int centerX = tft.width() / 2;
  int centerY = tft.height() / 2;

  Serial.println("   Dimensoes da tela: " + String(tft.width()) + "x" + String(tft.height()));
  Serial.println("   Centro: (" + String(centerX) + ", " + String(centerY) + ")");

  tft.drawString("Hello World!", centerX, centerY - 30);

  // Texto adicional
  tft.setTextSize(2);
  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.drawString("LilyGo T-Display-S3", centerX, centerY + 20);

  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.drawString("AMOLED Touch", centerX, centerY + 50);

  Serial.println("   [OK] Texto desenhado");

  Serial.println("\n========================================");
  Serial.println("TESTE CONCLUIDO!");
  Serial.println("Se voce viu as cores piscarem,");
  Serial.println("o display esta funcionando!");
  Serial.println("========================================\n");
}

void loop() {
  static unsigned long lastUpdate = 0;
  static int colorIndex = 0;
  static uint16_t colors[] = {TFT_WHITE, TFT_YELLOW, TFT_CYAN, TFT_MAGENTA};
  static String colorNames[] = {"BRANCO", "AMARELO", "CIANO", "MAGENTA"};

  if (millis() - lastUpdate > 2000) {
    lastUpdate = millis();

    // Alterna cores do "Hello World!"
    int centerX = tft.width() / 2;
    int centerY = tft.height() / 2;

    tft.setTextColor(colors[colorIndex], TFT_BLACK);
    tft.setTextSize(3);
    tft.setTextDatum(MC_DATUM);
    tft.drawString("Hello World!", centerX, centerY - 30);

    Serial.println("Cor alterada para: " + colorNames[colorIndex]);

    colorIndex = (colorIndex + 1) % 4;
  }

  delay(10);
}
