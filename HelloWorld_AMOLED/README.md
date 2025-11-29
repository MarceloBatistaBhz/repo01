# Hello World - LilyGo T-Display-S3-AMOLED-Touch

Código Arduino para exibir "Hello World" no display AMOLED da placa LilyGo T-Display-S3.

## Hardware

- **Placa**: LilyGo T-Display-S3-AMOLED-Touch
- **Display**: AMOLED 1.91" (536x240) com controlador RM67162
- **MCU**: ESP32-S3

## Bibliotecas Necessárias

### Opção 1: TFT_eSPI (Recomendado)
```
1. Instale a biblioteca TFT_eSPI no Arduino IDE
2. Configure o arquivo User_Setup.h para o display RM67162
```

### Opção 2: Biblioteca LilyGo (Mais fácil)
```
1. Baixe: https://github.com/Xinyuan-LilyGO/T-Display-S3-AMOLED
2. Instale via Arduino IDE -> Sketch -> Include Library -> Add .ZIP Library
```

## Configuração do Arduino IDE

1. **Adicionar suporte ESP32**:
   - File → Preferences → Additional Boards Manager URLs
   - Adicione: `https://espressif.github.io/arduino-esp32/package_esp32_index.json`

2. **Instalar placa ESP32**:
   - Tools → Board → Boards Manager
   - Procure "esp32" e instale "esp32 by Espressif Systems"

3. **Configurar a placa**:
   - Board: "ESP32S3 Dev Module"
   - USB CDC On Boot: "Enabled"
   - CPU Frequency: "240MHz"
   - Flash Size: "16MB (128Mb)"
   - Partition Scheme: "Huge APP (3MB No OTA/1MB SPIFFS)"
   - PSRAM: "OPI PSRAM"

## Como Usar

1. Abra o arquivo `HelloWorld_AMOLED.ino` no Arduino IDE
2. Conecte a placa LilyGo via USB-C
3. Selecione a porta correta em Tools → Port
4. Clique em Upload (seta para direita)
5. Aguarde a compilação e upload
6. "Hello World!" aparecerá no display AMOLED

## Funcionalidades

- Exibe "Hello World!" centralizado na tela
- Mostra informações adicionais sobre a placa
- Efeito de alternância de cores a cada 2 segundos
- Debug via Serial Monitor (115200 baud)

## Especificações Técnicas

| Componente | Detalhes |
|------------|----------|
| Display | AMOLED 1.91" 536x240px |
| Touch | Capacitivo CST816T |
| Processador | ESP32-S3 Dual Core 240MHz |
| Flash | 16MB |
| PSRAM | 8MB OPI PSRAM |
| WiFi | 802.11 b/g/n |
| Bluetooth | BLE 5.0 |
| USB | Type-C com CH343 |

## Pinos Importantes

- `PIN_POWER_ON = 15` - Liga/desliga o display
- `TFT_BL = 38` - Controle de brilho (opcional)

## Troubleshooting

- **Display não liga**: Verifique se PIN_POWER_ON está configurado corretamente
- **Erro de compilação**: Verifique se a biblioteca TFT_eSPI está instalada
- **Upload falha**: Mantenha o botão BOOT pressionado durante o upload
- **Nada aparece**: Tente diferentes valores em `tft.setRotation(0-3)`

## Links Úteis

- [Repositório oficial LilyGo](https://github.com/Xinyuan-LilyGO/T-Display-S3-AMOLED)
- [Documentação ESP32-S3](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/)
- [TFT_eSPI Library](https://github.com/Bodmer/TFT_eSPI)
