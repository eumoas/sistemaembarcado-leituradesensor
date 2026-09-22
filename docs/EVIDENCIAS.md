# Capturas para a entrega

O README inclui cinco capturas originais: configuração do ESP-IDF, conta Wokwi, compilação inicial, compilação final e simulação com leituras. A compilação final está registrada em `03-compilacao-concluida.png`, com a mensagem `Project build complete`. A tabela também indica capturas opcionais para complementar a apresentação.

| Nome sugerido | O que deve aparecer |
|---|---|
| `01-esp-idf-configurado.png` | Terminal do Docker após `idf.py --version`, mostrando `ESP-IDF v5.5` |
| `02-wokwi-configurado.png` | Confirmação da licença ativa no VS Code ou indicação da licença no simulador |
| `03-compilacao-concluida.png` | Compilação final com `Project build complete`; já incluída |
| `04-simulacao-monitor-serial.png` | Circuito e leituras; já incluído a partir da captura enviada |
| `05-circuito.png` | Opcional: circuito ampliado para facilitar a identificação dos fios e pinos |
| `06-variacao-do-sensor.png` | Opcional: alteração de uma entrada e correspondente mudança no monitor serial |

## Como capturar

1. Para a versão do ESP-IDF, use o terminal que está dentro do contêiner.
2. Para a compilação, entre em `/project/sensor_mpu6050` e execute `idf.py build`. Aguarde o término antes de capturar.
3. Para o circuito e as leituras, abra o Wokwi no VS Code, mantenha o simulador visível e aumente a área do terminal para facilitar a leitura.
4. Salve as capturas originais. Não substitua saídas de erro por textos de sucesso nem monte uma saída que não tenha ocorrido.
5. Após adicionar novas imagens, inclua-as na seção de evidências do README e atualize a situação correspondente.

Exemplo de inclusão no README, após o arquivo existir:

```markdown
![Compilação concluída no ESP-IDF](docs/imagens/03-compilacao-concluida.png)
```

Não é preciso mostrar chaves de licença, senhas ou tokens. A indicação de ativação é suficiente para documentar a configuração da conta.

## Conferência antes da entrega

- [x] Captura da versão do ESP-IDF incluída.
- [x] Licença Wokwi visível na captura da simulação.
- [x] Circuito e leituras incluídos.
- [x] Captura da compilação final incluída.
- [x] README e arquivos do projeto publicados no repositório informado.
- [x] Links locais conferidos e presença das cinco imagens confirmada no GitHub.
- [ ] Link do repositório e screenshot enviados no local de entrega da disciplina.

O teste de variação é complementar. Não é requisito adicional do enunciado.
