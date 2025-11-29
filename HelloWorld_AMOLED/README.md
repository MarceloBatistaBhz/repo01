# Hello World - LilyGo T-Display-S3-AMOLED-Touch

Códigos Arduino para exibir "Hello World" no display AMOLED da placa LilyGo T-Display-S3.

## 🔴 PROBLEMA: Display não mostra nada?

Se o Serial Monitor mostra "Hello World exibido no display!" mas a tela está preta, o problema é a **configuração da biblioteca TFT_eSPI**.

**SOLUÇÃO RÁPIDA**: Use o arquivo `HelloWorld_Sprite.ino` ⭐ - é o mais simples e funciona direto!

---

## 📁 Arquivos Disponíveis

### 1. `HelloWorld_Sprite.ino` ⭐⭐⭐ **RECOMENDADO - MAIS FÁCIL!**
- **FUNCIONA SEM INSTALAR BIBLIOTECAS EXTRAS!**
- Todos os arquivos necessários (rm67162.h, rm67162.cpp, pins_config.h) já estão inclusos
- Apenas instale TFT_eSPI pelo Gerenciador de Bibliotecas
- Baseado no exemplo oficial da LilyGo
- **USE ESTE!** É a forma mais simples e confiável!

### 2. `HelloWorld_TFT_eSPI_Fixed.ino` 🔧 **DIAGNÓSTICO**
- Versão com TFT_eSPI corrigida
- Inclui código de diagnóstico
- Mostra cores piscando (vermelho, verde, azul)
- Útil para testar se o display está funcionando

### 3. `HelloWorld_LilyGo.ino`
- Usa a biblioteca oficial LilyGo-AMOLED-Series
- Requer instalação da biblioteca específica
- **ATENÇÃO**: Pode dar erro de compilação dependendo da versão da biblioteca

### 4. `HelloWorld_AMOLED.ino`
- Versão original com TFT_eSPI
- Requer configuração manual da biblioteca
- Use apenas se você já configurou o TFT_eSPI corretamente

---

## 🚀 Início Rápido (MÉTODO MAIS FÁCIL!)

### Usando `HelloWorld_Sprite.ino` ⭐

#### 1. Instalar apenas TFT_eSPI

```
Arduino IDE → Sketch → Include Library → Manage Libraries
Procure: "TFT_eSPI"
Clique em Install
```

**Pronto!** Você NÃO precisa configurar nada na biblioteca TFT_eSPI porque o código usa os drivers inclusos (rm67162.h/cpp e pins_config.h) que já estão na pasta do projeto!

#### 2. Configurar ESP32

**Adicionar suporte ESP32**:
- File → Preferences → Additional Boards Manager URLs
- Adicione: `https://espressif.github.io/arduino-esp32/package_esp32_index.json`
- OK

**Instalar placa ESP32**:
- Tools → Board → Boards Manager
- Procure: "esp32"
- Instale: "esp32 by Espressif Systems"

#### 3. Configurar Placa

```
Board: "ESP32S3 Dev Module"
USB CDC On Boot: "Enabled"
CPU Frequency: "240MHz"
Flash Size: "16MB (128Mb)"
Partition Scheme: "Huge APP (3MB No OTA/1MB SPIFFS)"
PSRAM: "OPI PSRAM"
Upload Speed: "921600"
```

#### 4. Upload

```
1. Abra HelloWorld_Sprite.ino
2. Conecte a placa via USB-C
3. Selecione a porta correta (Tools → Port)
4. Clique em Upload (→)
5. Aguarde... "Hello World!" deve aparecer!
```

**Se der erro de compilação**, verifique se a PSRAM está habilitada (veja item 3 acima).

---

## 🔧 Usando TFT_eSPI (Método Avançado)

Se você realmente quer usar TFT_eSPI, siga estes passos:

### 1. Instalar TFT_eSPI

```
Arduino IDE → Sketch → Include Library → Manage Libraries
Procure: "TFT_eSPI"
Instale a biblioteca
```

### 2. Configurar TFT_eSPI

**Localize a pasta da biblioteca**:
- **Windows**: `Documents\Arduino\libraries\TFT_eSPI`
- **Mac**: `~/Documents/Arduino/libraries/TFT_eSPI`
- **Linux**: `~/Arduino/libraries/TFT_eSPI`

**Método A - Editar User_Setup_Select.h**:
```
1. Abra: TFT_eSPI/User_Setup_Select.h
2. Comente a linha (adicione //):
   // #include <User_Setup.h>
3. Procure por linhas com "Setup206" ou "LilyGo"
4. Descomente (remova //):
   #include <User_Setups/Setup206_LilyGo_T_Display_S3.h>
5. Salve o arquivo
```

**Método B - Copiar arquivo de configuração**:
```
1. Copie o conteúdo de User_Setup_AMOLED.h (deste projeto)
2. Cole em TFT_eSPI/User_Setup.h
3. Salve
```

### 3. Testar

```
1. Abra HelloWorld_TFT_eSPI_Fixed.ino
2. Faça o upload
3. Abra o Serial Monitor (115200 baud)
4. Você deve ver:
   - Cores piscando (vermelho, verde, azul)
   - Mensagens de diagnóstico
   - "Hello World!" na tela
```

---

## 🐛 Troubleshooting

### Display completamente preto
- ✅ Verifique se PIN_LED está funcionando (pino 38)
- ✅ Use `HelloWorld_TFT_eSPI_Fixed.ino` para diagnóstico
- ✅ Se você viu as cores piscarem, o display funciona!
- ✅ Problema é configuração da biblioteca → Use `HelloWorld_Sprite.ino`

### Erro de compilação
```
"TFT_eSPI.h: No such file"
→ Instale a biblioteca TFT_eSPI pelo Gerenciador de Bibliotecas

"class LilyGo_AMOLED has no member named 'fillScreen'"
→ A biblioteca LilyGo-AMOLED-Series mudou a API
→ Use HelloWorld_Sprite.ino em vez de HelloWorld_LilyGo.ino

"LilyGo_AMOLED.h: No such file"
→ Instale a biblioteca LilyGo-AMOLED-Series (mas use HelloWorld_Sprite.ino)

"PSRAM not turned on" ou "BOARD_HAS_PSRAM"
→ Tools → PSRAM → "OPI PSRAM"

"Compilation error: ..."
→ Verifique se selecionou "ESP32S3 Dev Module" como placa
```

### Upload falha
```
"Failed to connect"
→ Mantenha botão BOOT pressionado durante upload

"Timed out waiting for packet header"
→ Tente velocidade menor: Tools → Upload Speed → 115200
```

### Texto cortado ou fora da tela
```
→ Ajuste tft.setRotation(0-3) para diferentes orientações
→ Teste valores 0, 1, 2 e 3
→ Ajuste coordenadas setCursor() conforme necessário
```

### Display muito escuro
```
→ AMOLED não usa backlight tradicional
→ Cores escuras (preto, cinza) aparecem muito escuras
→ Use cores vibrantes (branco, ciano, amarelo)
```

---

## 📊 Hardware

| Componente | Detalhes |
|------------|----------|
| Display | AMOLED 1.91" 536x240px |
| Controlador | RM67162 (QSPI) |
| Touch | Capacitivo CST816T |
| Processador | ESP32-S3 Dual Core 240MHz |
| Flash | 16MB |
| PSRAM | 8MB OPI PSRAM |
| WiFi | 802.11 b/g/n |
| Bluetooth | BLE 5.0 |
| USB | Type-C com CH343 |

## 📍 Pinos Importantes

```cpp
PIN_POWER_ON = 15   // Liga/desliga display (CRÍTICO!)
PIN_TOUCH_RES = 21  // Reset do touch
TFT_BL = 38         // Controle (geralmente não usado em AMOLED)
```

## 🔗 Links Úteis

- [Repositório LilyGo T-Display-S3-AMOLED](https://github.com/Xinyuan-LilyGO/T-Display-S3-AMOLED)
- [Exemplos oficiais](https://github.com/Xinyuan-LilyGO/T-Display-S3-AMOLED/tree/main/examples)
- [ESP32-S3 Documentação](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/)
- [TFT_eSPI Library](https://github.com/Bodmer/TFT_eSPI)

---

## ✅ Checklist Rápido (HelloWorld_Sprite.ino)

- [ ] Biblioteca TFT_eSPI instalada (apenas esta!)
- [ ] ESP32 board manager instalado
- [ ] Placa configurada como "ESP32S3 Dev Module"
- [ ] USB CDC On Boot = "Enabled"
- [ ] PSRAM = "OPI PSRAM" ⚠️ **IMPORTANTE!**
- [ ] Cabo USB-C conectado
- [ ] Porta serial correta selecionada
- [ ] Arquivos rm67162.h, rm67162.cpp e pins_config.h na mesma pasta do .ino
- [ ] Serial Monitor em 115200 baud

**Ainda com problemas?** Verifique se a PSRAM está ativada - é o erro mais comum!
