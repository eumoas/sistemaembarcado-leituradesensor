# Capturas da entrega

As capturas estão em `docs/imagens/` e são apresentadas, com legendas, na [seção 9 do README](../README.md#9-evidências-da-atividade). São screenshots originais, sem alteração dos resultados.

| Arquivo | Etapa comprovada | O que aparece |
|---|---|---|
| `01-esp-idf-configurado.png` | Configuração do ESP-IDF | Imagem Docker baixada e `idf.py --version` retornando `ESP-IDF v5.5` |
| `02-wokwi-configurado.png` | Conta Wokwi | Conta autenticada no site Wokwi |
| `03-compilacao-final.png` | Código compilando sem erros | Comando de compilação, `ESP-IDF v5.5`, tamanho do binário e `Project build complete` |
| `04-circuito-monitor-serial.png` | Circuito e leituras do sensor | Licença Wokwi ativa no VS Code, circuito ESP32-S3 + MPU6050 e leituras consecutivas no monitor serial |
| `05-variacao-temperatura-50c.png` | Leitura do sensor | Controle de temperatura em 50,4 °C e leitura `50.40 C` |
| `06-variacao-temperatura-16c.png` | Leitura do sensor | Controle de temperatura em 16,2 °C e leitura `16.20 C` |

A pasta `anteriores/` guarda capturas de etapas intermediárias: a compilação inicial, a primeira versão do circuito e uma compilação no terminal do VS Code.

## Conferência antes da entrega

- [x] Versão do ESP-IDF registrada.
- [x] Conta Wokwi autenticada e licença ativa na extensão do VS Code.
- [x] Circuito com VCC, GND, SDA e SCL, sem cruzamento de fios.
- [x] Compilação concluída sem erros.
- [x] Monitor serial com várias leituras consecutivas.
- [x] Teste de variação da temperatura executado.
- [x] README, código e imagens publicados no repositório.
- [ ] Link do repositório e screenshot enviados no local de entrega da disciplina.
