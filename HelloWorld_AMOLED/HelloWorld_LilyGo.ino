/*
 * Hello World - LilyGo T-Display-S3-AMOLED-Touch
 * Versão com biblioteca LilyGo (RECOMENDADA)
 *
 * Biblioteca necessária:
 * https://github.com/Xinyuan-LilyGO/T-Display-S3-AMOLED
 *
 * Instalação:
 * 1. Arduino IDE -> Sketch -> Include Library -> Manage Libraries
 * 2. Procure por "LilyGo-AMOLED-Series" e instale
 * OU
 * 1. Baixe o ZIP do GitHub acima
 * 2. Sketch -> Include Library -> Add .ZIP Library
 *
 * Configuração da placa:
 * - Board: "ESP32S3 Dev Module"
 * - USB CDC On Boot: "Enabled"
 * - Flash Size: "16MB (128Mb)"
 * - Partition Scheme: "Huge APP (3MB No OTA/1MB SPIFFS)"
 * - PSRAM: "OPI PSRAM"
 */

#include <LilyGo_AMOLED.h>
#include <LV_Helper.h>

LilyGo_Class amoled;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Iniciando LilyGo T-Display-S3-AMOLED...");

  // Inicializa o display AMOLED
  // Modelo: LILYGO_AMOLED_191 (1.91 polegadas)
  bool result = amoled.begin();

  if (!result) {
    Serial.println("ERRO: Falha ao inicializar o display!");
    while (1) {
      delay(1000);
    }
  }

  Serial.println("Display inicializado com sucesso!");

  // Limpa a tela com cor preta
  amoled.fillScreen(0x0000);  // 0x0000 = Preto em RGB565

  // Define o tamanho do texto
  amoled.setTextSize(3);

  // "Hello World!" - Branco
  amoled.setTextColor(0xFFFF, 0x0000);  // Branco em preto
  amoled.setCursor(60, 90);
  amoled.println("Hello World!");

  // Informações adicionais
  amoled.setTextSize(2);

  // "LilyGo T-Display-S3" - Ciano
  amoled.setTextColor(0x07FF, 0x0000);  // Ciano
  amoled.setCursor(40, 140);
  amoled.println("LilyGo T-Display-S3");

  // "AMOLED Touch" - Verde
  amoled.setTextColor(0x07E0, 0x0000);  // Verde
  amoled.setCursor(80, 170);
  amoled.println("AMOLED Touch");

  Serial.println("Hello World exibido no display!");
  Serial.println("Resolucao: " + String(amoled.width()) + "x" + String(amoled.height()));
}

void loop() {
  // Efeito de alternância de cores
  static unsigned long lastBlink = 0;
  static bool useWhite = true;

  if (millis() - lastBlink > 2000) {
    lastBlink = millis();
    useWhite = !useWhite;

    // Redesenha "Hello World!" com cor alternada
    amoled.setTextSize(3);

    if (useWhite) {
      amoled.setTextColor(0xFFFF, 0x0000);  // Branco
    } else {
      amoled.setTextColor(0xFFE0, 0x0000);  // Amarelo
    }

    amoled.setCursor(60, 90);
    amoled.println("Hello World!");
  }

  delay(10);
}
