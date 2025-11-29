# Configuração TFT_eSPI para LilyGo T-Display-S3-AMOLED

Este guia detalha como configurar a biblioteca TFT_eSPI especificamente para o display AMOLED RM67162.

## 🚨 Aviso Importante

A biblioteca **TFT_eSPI padrão pode NÃO ter suporte completo** para o controlador RM67162 usado neste display AMOLED.

**Recomendação**: Use a biblioteca oficial LilyGo em vez de TFT_eSPI (veja README.md).

Se você ainda quer usar TFT_eSPI, siga este guia.

---

## Passo 1: Localizar a Pasta da Biblioteca

Encontre onde a biblioteca TFT_eSPI foi instalada:

### Windows
```
C:\Users\[SEU_USUARIO]\Documents\Arduino\libraries\TFT_eSPI\
```

### Mac
```
/Users/[SEU_USUARIO]/Documents/Arduino/libraries/TFT_eSPI/
```

### Linux
```
/home/[SEU_USUARIO]/Arduino/libraries/TFT_eSPI/
```

---

## Passo 2: Verificar se existe Setup para LilyGo

1. Abra a pasta `TFT_eSPI/User_Setups/`

2. Procure por um arquivo como:
   - `Setup206_LilyGo_T_Display_S3.h`
   - `Setup_LilyGo_AMOLED.h`
   - Qualquer arquivo com "LilyGo" e "S3" no nome

3. **Se encontrou**: Vá para **Método A** abaixo
4. **Se NÃO encontrou**: Vá para **Método B** abaixo

---

## Método A: Usar Setup Existente (Se disponível)

### 1. Editar User_Setup_Select.h

Abra o arquivo: `TFT_eSPI/User_Setup_Select.h`

### 2. Comentar a linha padrão

Procure por esta linha (geralmente no início):
```cpp
#include <User_Setup.h>           // Default setup
```

Adicione `//` no início:
```cpp
// #include <User_Setup.h>        // Default setup
```

### 3. Descomentar setup da LilyGo

Procure na lista por algo como:
```cpp
// #include <User_Setups/Setup206_LilyGo_T_Display_S3.h>
```

Remova o `//`:
```cpp
#include <User_Setups/Setup206_LilyGo_T_Display_S3.h>
```

### 4. Salvar e testar

Salve o arquivo e tente compilar o código Arduino.

---

## Método B: Criar Configuração Manual

Se não existe um setup pré-configurado, você precisa criar um.

### 1. Abrir User_Setup.h

Abra o arquivo: `TFT_eSPI/User_Setup.h`

### 2. Limpar configurações antigas

**CUIDADO**: Faça backup do arquivo original primeiro!

Procure e **comente** (adicione `//`) todas as linhas que começam com `#define`:
- `#define ILI9341_DRIVER`
- `#define ST7735_DRIVER`
- Etc.

### 3. Adicionar configuração do RM67162

**IMPORTANTE**: A biblioteca TFT_eSPI padrão pode **não ter** o driver RM67162!

Você pode tentar adicionar esta configuração (mas pode não funcionar):

```cpp
// ============================================
// Configuração para LilyGo T-Display-S3-AMOLED
// ============================================

#define USER_SETUP_INFO "LilyGo_T_Display_S3_AMOLED"

// Tente usar driver genérico (pode não funcionar perfeitamente)
#define ST7789_DRIVER
#define CGRAM_OFFSET

// Resolução
#define TFT_WIDTH  536
#define TFT_HEIGHT 240

// Configuração de pinos (QSPI não é totalmente suportado em TFT_eSPI padrão)
// Estes valores podem não funcionar!
#define TFT_MISO -1
#define TFT_MOSI 18
#define TFT_SCLK 47
#define TFT_CS    6
#define TFT_DC    7
#define TFT_RST  17

// Fontes
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8

#define SMOOTH_FONT

// SPI Frequency
#define SPI_FREQUENCY  27000000
#define SPI_READ_FREQUENCY  20000000
```

### 4. Salvar e testar

Salve e tente compilar. **Provavelmente não funcionará perfeitamente**.

---

## Método C: Usar Biblioteca LilyGo (RECOMENDADO)

Em vez de lutar com TFT_eSPI, use a biblioteca oficial:

```
1. Arduino IDE → Sketch → Include Library → Manage Libraries
2. Procure: "LilyGo-AMOLED-Series"
3. Instale
4. Use o código: HelloWorld_LilyGo.ino
```

**Esta é a forma mais confiável!**

---

## Verificar se a Configuração Funcionou

### Teste 1: Compilação

Tente compilar qualquer sketch que use TFT_eSPI:

```cpp
#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();

void setup() {
  tft.init();
}

void loop() {}
```

Se compilar **sem erros** → Configuração aceita (mas pode não funcionar no hardware)

### Teste 2: Upload e Teste Visual

Use o código `HelloWorld_TFT_eSPI_Fixed.ino` que tem diagnósticos:

1. Upload para a placa
2. Abra Serial Monitor (115200 baud)
3. Observe se:
   - ✅ Serial mostra mensagens de inicialização
   - ✅ Display mostra cores piscando (vermelho, verde, azul)
   - ✅ "Hello World!" aparece

Se apenas o Serial funciona mas o display fica preto → Configuração incorreta!

---

## Por que TFT_eSPI pode não funcionar?

1. **Driver RM67162 específico**: Este controlador usa QSPI (Quad-SPI), não SPI normal
2. **Biblioteca genérica**: TFT_eSPI é feita para displays SPI padrão
3. **Timing específico**: AMOLED requer inicialização diferente de LCD

**Solução**: Use a biblioteca LilyGo que foi feita especificamente para este hardware!

---

## Comparação Rápida

| Aspecto | TFT_eSPI | LilyGo-AMOLED |
|---------|----------|---------------|
| Configuração | Complexa, manual | Automática |
| Suporte RM67162 | Limitado/inexistente | Completo |
| Confiabilidade | Baixa para AMOLED | Alta |
| Exemplos | Genéricos | Específicos |
| Recomendação | ❌ Não use | ✅ Use! |

---

## Ainda quer tentar TFT_eSPI?

Se você **realmente** precisa usar TFT_eSPI:

1. Verifique se existe firmware/driver customizado da LilyGo para TFT_eSPI
2. Procure no repositório oficial: https://github.com/Xinyuan-LilyGO/T-Display-S3-AMOLED
3. Veja se eles fornecem uma versão modificada do TFT_eSPI

Caso contrário: **use a biblioteca LilyGo-AMOLED-Series** e economize horas de frustração!

---

## Links Úteis

- [TFT_eSPI GitHub](https://github.com/Bodmer/TFT_eSPI)
- [LilyGo T-Display-S3-AMOLED](https://github.com/Xinyuan-LilyGO/T-Display-S3-AMOLED)
- [Issues conhecidos com RM67162](https://github.com/Bodmer/TFT_eSPI/issues?q=RM67162)
