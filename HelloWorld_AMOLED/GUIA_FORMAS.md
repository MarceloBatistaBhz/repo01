# 🎨 Guia de Formas Geométricas e Desenho

Este guia mostra todas as funções de desenho disponíveis para o display AMOLED.

## 📋 Índice

- [Círculos](#círculos)
- [Retângulos](#retângulos)
- [Triângulos](#triângulos)
- [Linhas](#linhas)
- [Pixels](#pixels)
- [Texto](#texto)
- [Cores](#cores)
- [Exemplos Práticos](#exemplos-práticos)

---

## ⭕ Círculos

### Círculo Preenchido
```cpp
spr.fillCircle(x, y, raio, cor);
```
**Parâmetros:**
- `x`, `y`: coordenadas do centro
- `raio`: raio em pixels
- `cor`: cor RGB565 (ex: TFT_RED, TFT_BLUE)

**Exemplo:**
```cpp
spr.fillCircle(268, 120, 50, TFT_RED);  // Círculo vermelho no centro
```

### Círculo Contorno
```cpp
spr.drawCircle(x, y, raio, cor);
```

**Exemplo:**
```cpp
// Círculo com borda branca
spr.fillCircle(100, 100, 40, TFT_BLUE);
spr.drawCircle(100, 100, 45, TFT_WHITE);
```

---

## ◼️ Retângulos

### Retângulo Preenchido
```cpp
spr.fillRect(x, y, largura, altura, cor);
```

**Exemplo:**
```cpp
spr.fillRect(50, 50, 100, 60, TFT_GREEN);
```

### Retângulo Contorno
```cpp
spr.drawRect(x, y, largura, altura, cor);
```

### Retângulo com Cantos Arredondados
```cpp
spr.fillRoundRect(x, y, largura, altura, raio_canto, cor);
spr.drawRoundRect(x, y, largura, altura, raio_canto, cor);
```

**Exemplo:**
```cpp
// Botão com cantos arredondados
spr.fillRoundRect(100, 100, 150, 50, 10, TFT_BLUE);
spr.setTextColor(TFT_WHITE);
spr.drawString("Clique Aqui", 130, 115);
```

---

## 🔺 Triângulos

### Triângulo Preenchido
```cpp
spr.fillTriangle(x1, y1, x2, y2, x3, y3, cor);
```

**Parâmetros:**
- `x1, y1`: primeiro vértice
- `x2, y2`: segundo vértice
- `x3, y3`: terceiro vértice
- `cor`: cor do preenchimento

**Exemplo:**
```cpp
// Seta para cima
spr.fillTriangle(268, 50,   // topo
                 230, 110,  // esquerda
                 306, 110,  // direita
                 TFT_YELLOW);
```

### Triângulo Contorno
```cpp
spr.drawTriangle(x1, y1, x2, y2, x3, y3, cor);
```

---

## 📏 Linhas

### Linha Diagonal
```cpp
spr.drawLine(x1, y1, x2, y2, cor);
```

**Exemplo:**
```cpp
// Linha diagonal do canto superior esquerdo ao inferior direito
spr.drawLine(0, 0, 536, 240, TFT_WHITE);
```

### Linha Horizontal (Mais Rápida)
```cpp
spr.drawFastHLine(x, y, largura, cor);
```

**Exemplo:**
```cpp
// Linha horizontal
spr.drawFastHLine(50, 120, 436, TFT_GREEN);
```

### Linha Vertical (Mais Rápida)
```cpp
spr.drawFastVLine(x, y, altura, cor);
```

**Exemplo:**
```cpp
// Linha vertical
spr.drawFastVLine(268, 20, 200, TFT_CYAN);
```

---

## 🎯 Pixels

### Desenhar Pixel Individual
```cpp
spr.drawPixel(x, y, cor);
```

**Exemplo:**
```cpp
// Desenha estrelas aleatórias
for (int i = 0; i < 100; i++) {
  int x = random(536);
  int y = random(240);
  spr.drawPixel(x, y, TFT_WHITE);
}
```

### Ler Cor de um Pixel
```cpp
uint16_t cor = spr.readPixel(x, y);
```

---

## 📝 Texto

### Configurar Texto
```cpp
spr.setTextColor(cor_texto, cor_fundo);  // Com fundo
spr.setTextColor(cor_texto);             // Sem fundo (transparente)
spr.setTextSize(tamanho);                // 1, 2, 3, 4...
spr.setTextDatum(posicao);               // TL_DATUM, MC_DATUM, etc.
```

### Desenhar Texto
```cpp
spr.drawString(texto, x, y);
spr.drawString(texto, x, y, fonte);      // Com fonte específica
spr.setCursor(x, y);
spr.print(texto);
```

**Posicionamento (Datum):**
- `TL_DATUM` - Top Left (superior esquerdo)
- `TC_DATUM` - Top Center (superior centro)
- `TR_DATUM` - Top Right (superior direito)
- `ML_DATUM` - Middle Left
- `MC_DATUM` - Middle Center (centro)
- `MR_DATUM` - Middle Right
- `BL_DATUM` - Bottom Left
- `BC_DATUM` - Bottom Center
- `BR_DATUM` - Bottom Right

**Exemplo:**
```cpp
spr.setTextSize(3);
spr.setTextColor(TFT_WHITE, TFT_BLACK);
spr.setTextDatum(MC_DATUM);  // Centralizado
spr.drawString("Centro!", 268, 120);
```

### Fontes Disponíveis
```cpp
spr.drawString(texto, x, y, 1);  // Font 1 - Padrão pequena
spr.drawString(texto, x, y, 2);  // Font 2 - Média
spr.drawString(texto, x, y, 4);  // Font 4 - Grande
spr.drawString(texto, x, y, 6);  // Font 6 - Muito grande
spr.drawString(texto, x, y, 7);  // Font 7 - 7 segmentos
```

---

## 🎨 Cores

### Cores Predefinidas
```cpp
TFT_BLACK       // 0x0000  Preto
TFT_NAVY        // 0x000F  Azul marinho
TFT_DARKGREEN   // 0x03E0  Verde escuro
TFT_DARKCYAN    // 0x03EF  Ciano escuro
TFT_MAROON      // 0x7800  Marrom
TFT_PURPLE      // 0x780F  Roxo
TFT_OLIVE       // 0x7BE0  Oliva
TFT_LIGHTGREY   // 0xC618  Cinza claro
TFT_DARKGREY    // 0x7BEF  Cinza escuro
TFT_BLUE        // 0x001F  Azul
TFT_GREEN       // 0x07E0  Verde
TFT_CYAN        // 0x07FF  Ciano
TFT_RED         // 0xF800  Vermelho
TFT_MAGENTA     // 0xF81F  Magenta
TFT_YELLOW      // 0xFFE0  Amarelo
TFT_WHITE       // 0xFFFF  Branco
TFT_ORANGE      // 0xFD20  Laranja
TFT_GREENYELLOW // 0xAFE5  Verde amarelado
TFT_PINK        // 0xF81F  Rosa
```

### Criar Cor Customizada (RGB565)
```cpp
uint16_t cor = spr.color565(R, G, B);
```

**Parâmetros:**
- `R`: Vermelho (0-255)
- `G`: Verde (0-255)
- `B`: Azul (0-255)

**Exemplo:**
```cpp
uint16_t roxo = spr.color565(128, 0, 255);
uint16_t laranja = spr.color565(255, 165, 0);
uint16_t rosa = spr.color565(255, 192, 203);

spr.fillCircle(100, 120, 40, roxo);
spr.fillCircle(268, 120, 40, laranja);
spr.fillCircle(436, 120, 40, rosa);
```

### Converter Cor RGB565 para RGB888
```cpp
uint8_t r = (cor >> 11) << 3;
uint8_t g = ((cor >> 5) & 0x3F) << 2;
uint8_t b = (cor & 0x1F) << 3;
```

---

## 💡 Exemplos Práticos

### 1. Rosto Feliz
```cpp
void desenharRostoFeliz(int x, int y) {
  // Rosto
  spr.fillCircle(x, y, 60, TFT_YELLOW);

  // Olhos
  spr.fillCircle(x - 20, y - 15, 8, TFT_BLACK);
  spr.fillCircle(x + 20, y - 15, 8, TFT_BLACK);

  // Sorriso (arco)
  for (int i = -25; i <= 25; i++) {
    int px = x + i;
    int py = y + 10 + (int)(sqrt(625 - i*i) * 0.4);
    spr.drawPixel(px, py, TFT_BLACK);
    spr.drawPixel(px, py + 1, TFT_BLACK);
  }
}
```

### 2. Gráfico de Barras
```cpp
void desenharGrafico(int valores[], int total) {
  int larguraBarra = 40;
  int espacamento = 10;

  for (int i = 0; i < total; i++) {
    int x = 50 + i * (larguraBarra + espacamento);
    int altura = valores[i];
    int y = 200 - altura;

    // Barra com gradiente
    for (int j = 0; j < altura; j++) {
      uint16_t cor = spr.color565(255 - j, j, 128);
      spr.drawFastHLine(x, y + j, larguraBarra, cor);
    }

    // Borda
    spr.drawRect(x, y, larguraBarra, altura, TFT_WHITE);
  }
}
```

### 3. Relógio Analógico
```cpp
void desenharRelogio(int horas, int minutos) {
  int centroX = 268;
  int centroY = 120;
  int raio = 80;

  // Círculo externo
  spr.drawCircle(centroX, centroY, raio, TFT_WHITE);
  spr.drawCircle(centroX, centroY, raio - 2, TFT_WHITE);

  // Marcações das horas
  for (int i = 0; i < 12; i++) {
    float angulo = i * 30 * DEG_TO_RAD;
    int x1 = centroX + (raio - 10) * sin(angulo);
    int y1 = centroY - (raio - 10) * cos(angulo);
    int x2 = centroX + (raio - 5) * sin(angulo);
    int y2 = centroY - (raio - 5) * cos(angulo);
    spr.drawLine(x1, y1, x2, y2, TFT_WHITE);
  }

  // Ponteiro das horas
  float anguloH = (horas % 12 + minutos / 60.0) * 30 * DEG_TO_RAD;
  int xH = centroX + 40 * sin(anguloH);
  int yH = centroY - 40 * cos(anguloH);
  spr.drawLine(centroX, centroY, xH, yH, TFT_RED);

  // Ponteiro dos minutos
  float anguloM = minutos * 6 * DEG_TO_RAD;
  int xM = centroX + 60 * sin(anguloM);
  int yM = centroY - 60 * cos(anguloM);
  spr.drawLine(centroX, centroY, xM, yM, TFT_GREEN);

  // Centro
  spr.fillCircle(centroX, centroY, 5, TFT_WHITE);
}
```

### 4. Padrão de Grade
```cpp
void desenharGrade() {
  // Linhas verticais
  for (int x = 0; x < 536; x += 50) {
    spr.drawFastVLine(x, 0, 240, spr.color565(50, 50, 50));
  }

  // Linhas horizontais
  for (int y = 0; y < 240; y += 50) {
    spr.drawFastHLine(0, y, 536, spr.color565(50, 50, 50));
  }

  // Eixos principais
  spr.drawFastVLine(268, 0, 240, TFT_CYAN);  // Centro vertical
  spr.drawFastHLine(0, 120, 536, TFT_CYAN);  // Centro horizontal
}
```

### 5. Botão Interativo
```cpp
void desenharBotao(int x, int y, String texto, bool pressionado) {
  int largura = 120;
  int altura = 40;

  if (pressionado) {
    // Botão pressionado (mais escuro, deslocado)
    spr.fillRoundRect(x + 2, y + 2, largura, altura, 8, TFT_DARKGREY);
    spr.drawRoundRect(x + 2, y + 2, largura, altura, 8, TFT_WHITE);
  } else {
    // Botão normal
    spr.fillRoundRect(x, y, largura, altura, 8, TFT_BLUE);
    spr.drawRoundRect(x, y, largura, altura, 8, TFT_CYAN);
    // Sombra
    spr.fillRoundRect(x + 3, y + 3, largura, altura, 8, spr.color565(30, 30, 30));
  }

  // Texto centralizado
  spr.setTextSize(2);
  spr.setTextColor(TFT_WHITE);
  spr.setTextDatum(MC_DATUM);
  int offset = pressionado ? 2 : 0;
  spr.drawString(texto, x + largura/2 + offset, y + altura/2 + offset);
}
```

---

## 📐 Coordenadas do Display

```
Dimensões: 536 x 240 pixels (rotação 1)

   0,0 ──────────────────────────── 535,0
    │                                  │
    │                                  │
    │         268,120 (centro)         │
    │                                  │
    │                                  │
   0,239 ────────────────────────── 535,239
```

---

## ⚡ Dicas de Performance

1. **Use `fillScreen()` uma vez**
   ```cpp
   spr.fillSprite(TFT_BLACK);  // Limpa tudo de uma vez
   ```

2. **Desenhe tudo no sprite primeiro, depois envie**
   ```cpp
   // ✅ Correto
   spr.fillCircle(...);
   spr.drawRect(...);
   spr.drawString(...);
   lcd_PushColors(...);  // Uma vez só
   ```

3. **Use `drawFastHLine` e `drawFastVLine` quando possível**
   - São mais rápidas que `drawLine` para linhas retas

4. **Reduza redesenhos desnecessários**
   ```cpp
   // Se apenas uma área mudou, redesenhe só ela
   spr.fillRect(area_x, area_y, w, h, TFT_BLACK);  // Limpa área
   spr.drawString(...);  // Redesenha
   ```

---

## 🎓 Arquivo de Exemplo

Veja o arquivo `Exemplo_Circulos.ino` para um exemplo completo e funcional de todos os conceitos deste guia!

O exemplo inclui:
- ✅ Círculos preenchidos e contornos
- ✅ Círculos concêntricos
- ✅ Retângulos e triângulos
- ✅ Desenho criativo (rosto feliz)
- ✅ Animação de círculo quicando com efeito arco-íris
- ✅ Gradientes e cores customizadas

---

**Divirta-se criando!** 🎨
