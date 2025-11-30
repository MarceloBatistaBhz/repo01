/*
 * Exemplo de Círculos e Formas Geométricas
 * LilyGo T-Display-S3-AMOLED-Touch
 *
 * Este exemplo demonstra:
 * - Desenho de círculos (preenchidos e contorno)
 * - Retângulos, triângulos e linhas
 * - Cores customizadas
 * - Animação simples
 *
 * Arquivos necessários (mesma pasta):
 * - rm67162.h
 * - rm67162.cpp
 * - pins_config.h
 *
 * Biblioteca necessária:
 * - TFT_eSPI (instale pelo Gerenciador de Bibliotecas)
 */

#include "rm67162.h"
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite spr = TFT_eSprite(&tft);

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("\n========================================");
  Serial.println("Exemplo: Circulos e Formas Geometricas");
  Serial.println("========================================\n");

  // Inicializa o display
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, HIGH);

  rm67162_init();
  lcd_setRotation(1);

  spr.createSprite(536, 240);
  spr.setSwapBytes(1);

  // Desenha exemplos estáticos primeiro
  desenharExemplosEstaticos();

  Serial.println("\nAgora iniciando animacao...");
  Serial.println("Pressione RESET para ver os exemplos estaticos novamente\n");

  delay(3000);  // Mostra exemplos estáticos por 3 segundos
}

void desenharExemplosEstaticos() {
  // ====== TELA 1: CÍRCULOS ======
  spr.fillSprite(TFT_BLACK);

  // Título
  spr.setTextColor(TFT_WHITE, TFT_BLACK);
  spr.setTextSize(2);
  spr.drawString("CIRCULOS - Exemplos", 150, 10);

  // Círculo vermelho preenchido
  spr.fillCircle(80, 100, 35, TFT_RED);
  spr.setTextSize(1);
  spr.setTextColor(TFT_WHITE);
  spr.drawString("Preenchido", 45, 150);

  // Círculo verde apenas contorno
  spr.drawCircle(200, 100, 35, TFT_GREEN);
  spr.drawString("Contorno", 165, 150);

  // Círculo azul com contorno branco
  spr.fillCircle(320, 100, 35, TFT_BLUE);
  spr.drawCircle(320, 100, 40, TFT_WHITE);
  spr.drawString("Duplo", 295, 150);

  // Círculos concêntricos coloridos
  spr.drawCircle(456, 100, 50, TFT_RED);
  spr.drawCircle(456, 100, 40, TFT_YELLOW);
  spr.drawCircle(456, 100, 30, TFT_GREEN);
  spr.drawCircle(456, 100, 20, TFT_CYAN);
  spr.drawCircle(456, 100, 10, TFT_MAGENTA);
  spr.drawString("Concentricos", 410, 160);

  // Informação de uso
  spr.setTextColor(TFT_CYAN);
  spr.drawString("fillCircle(x, y, raio, cor)", 10, 180);
  spr.drawString("drawCircle(x, y, raio, cor)", 10, 195);

  lcd_PushColors(0, 0, 536, 240, (uint16_t*)spr.getPointer());
  Serial.println("Tela 1: Circulos desenhados!");

  delay(3000);

  // ====== TELA 2: OUTRAS FORMAS ======
  spr.fillSprite(TFT_BLACK);

  // Título
  spr.setTextSize(2);
  spr.setTextColor(TFT_WHITE);
  spr.drawString("FORMAS GEOMETRICAS", 150, 10);

  // Retângulos
  spr.fillRect(30, 50, 80, 50, TFT_RED);
  spr.drawRect(30, 110, 80, 50, TFT_GREEN);
  spr.setTextSize(1);
  spr.drawString("Retangulos", 35, 170);

  // Retângulos arredondados
  spr.fillRoundRect(140, 50, 80, 50, 10, TFT_BLUE);
  spr.drawRoundRect(140, 110, 80, 50, 10, TFT_YELLOW);
  spr.drawString("Arredondados", 140, 170);

  // Triângulos
  spr.fillTriangle(280, 100, 320, 50, 360, 100, TFT_MAGENTA);
  spr.drawTriangle(280, 160, 320, 110, 360, 160, TFT_CYAN);
  spr.drawString("Triangulos", 285, 170);

  // Linhas
  for (int i = 0; i < 5; i++) {
    spr.drawLine(400, 50 + i*20, 520, 50 + i*20,
                 spr.color565(255, i*50, 255 - i*50));
  }
  spr.drawFastVLine(460, 50, 100, TFT_WHITE);
  spr.drawString("Linhas", 440, 170);

  lcd_PushColors(0, 0, 536, 240, (uint16_t*)spr.getPointer());
  Serial.println("Tela 2: Outras formas desenhadas!");

  delay(3000);

  // ====== TELA 3: ROSTO FELIZ ======
  spr.fillSprite(TFT_BLACK);

  spr.setTextSize(2);
  spr.setTextColor(TFT_YELLOW);
  spr.drawString("DESENHO CRIATIVO", 160, 10);

  // Rosto feliz com círculos
  spr.fillCircle(268, 120, 80, TFT_YELLOW);       // Rosto
  spr.fillCircle(240, 100, 12, TFT_BLACK);        // Olho esquerdo
  spr.fillCircle(296, 100, 12, TFT_BLACK);        // Olho direito

  // Sorriso (arco usando círculo cortado)
  for (int i = -30; i <= 30; i++) {
    int x = 268 + i;
    int y = 130 + (int)(sqrt(900 - i*i) * 0.5);
    spr.drawPixel(x, y, TFT_BLACK);
    spr.drawPixel(x, y+1, TFT_BLACK);
  }

  // Bochechas rosadas
  spr.fillCircle(200, 130, 15, TFT_PINK);
  spr.fillCircle(336, 130, 15, TFT_PINK);

  spr.setTextSize(1);
  spr.setTextColor(TFT_WHITE);
  spr.drawString("Feito com circulos e linhas!", 180, 220);

  lcd_PushColors(0, 0, 536, 240, (uint16_t*)spr.getPointer());
  Serial.println("Tela 3: Rosto feliz desenhado!");
}

void loop() {
  // ====== ANIMAÇÃO: CÍRCULO QUICANDO ======
  static int x = 50;      // Posição X
  static int y = 120;     // Posição Y
  static int dx = 3;      // Velocidade X
  static int dy = 2;      // Velocidade Y
  static int raio = 25;
  static int hue = 0;     // Para mudar cor gradualmente

  // Limpa a tela com fundo gradiente
  for (int i = 0; i < 240; i++) {
    uint16_t cor = spr.color565(0, i/2, 120 - i/2);
    spr.drawFastHLine(0, i, 536, cor);
  }

  // Título
  spr.setTextSize(2);
  spr.setTextColor(TFT_WHITE, spr.color565(0, 0, 120));
  spr.drawString("ANIMACAO: Circulo Quicando", 120, 10);

  // Calcula cor do círculo (efeito arco-íris)
  hue = (hue + 2) % 360;
  uint16_t cor = HSVtoRGB565(hue, 255, 255);

  // Desenha o círculo com efeito 3D
  // Sombra
  spr.fillCircle(x + 5, y + 5, raio, spr.color565(50, 50, 50));
  // Círculo principal
  spr.fillCircle(x, y, raio, cor);
  // Brilho
  spr.fillCircle(x - 8, y - 8, 8, TFT_WHITE);

  // Atualiza posição
  x += dx;
  y += dy;

  // Verifica colisão com bordas e inverte direção
  if (x - raio <= 0 || x + raio >= 536) {
    dx = -dx;
    Serial.println("Bateu na borda horizontal!");
  }
  if (y - raio <= 35 || y + raio >= 240) {
    dy = -dy;
    Serial.println("Bateu na borda vertical!");
  }

  // Mantém dentro dos limites
  x = constrain(x, raio, 536 - raio);
  y = constrain(y, raio + 5, 240 - raio);

  // Mostra posição
  spr.setTextSize(1);
  spr.setTextColor(TFT_WHITE);
  spr.fillRect(10, 220, 150, 15, TFT_BLACK);
  spr.setCursor(10, 222);
  spr.print("Pos: X=");
  spr.print(x);
  spr.print(" Y=");
  spr.print(y);

  // Envia para o display
  lcd_PushColors(0, 0, 536, 240, (uint16_t*)spr.getPointer());

  delay(10);  // Controla velocidade da animação
}

// Função auxiliar: converte HSV para RGB565
uint16_t HSVtoRGB565(int h, int s, int v) {
  float H = h / 60.0;
  float S = s / 255.0;
  float V = v / 255.0;

  int i = (int)H;
  float f = H - i;
  float p = V * (1 - S);
  float q = V * (1 - S * f);
  float t = V * (1 - S * (1 - f));

  float r, g, b;

  switch(i % 6) {
    case 0: r = V; g = t; b = p; break;
    case 1: r = q; g = V; b = p; break;
    case 2: r = p; g = V; b = t; break;
    case 3: r = p; g = q; b = V; break;
    case 4: r = t; g = p; b = V; break;
    case 5: r = V; g = p; b = q; break;
  }

  int R = r * 255;
  int G = g * 255;
  int B = b * 255;

  return spr.color565(R, G, B);
}
