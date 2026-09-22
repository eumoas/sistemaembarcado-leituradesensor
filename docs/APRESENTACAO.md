# Roteiro para apresentar o projeto

As capturas já incluídas registram o funcionamento original. O circuito atual usa quatro fios (VCC, GND, SDA e SCL) em trajetos paralelos, sem cruzamentos. Para registrar essa apresentação atualizada, siga os passos abaixo no VS Code.

## 1. Circuito e leituras contínuas

1. Pare a simulação que estiver aberta.
2. Abra `sensor_mpu6050/wokwi.toml` e execute **Wokwi: Start Simulator** pela paleta `Ctrl + Shift + P`.
3. Confira o desenho: o fio vermelho sobe do VCC até 3V3; os fios verde, azul e preto contornam o sensor pela esquerda e seguem até GPIO 8, GPIO 9 e GND.
4. Arraste a divisória acima do terminal para cima, deixando espaço para pelo menos três conjuntos completos de leituras.
5. Aguarde cerca de cinco segundos. Confira as linhas de aceleração, velocidade angular e temperatura.
6. Salve uma captura como `05-circuito-leituras.png`, mostrando a placa, o sensor, os fios e o terminal.

Não é necessário recompilar: a mudança foi apenas no desenho do circuito.

## 2. Teste de variação da temperatura

1. Com a simulação em execução, clique no MPU6050 e procure o controle de temperatura.
2. Observe primeiro o valor inicial de aproximadamente 24 °C no terminal.
3. Altere a temperatura para 30 °C e aguarde novas leituras.
4. Confira se a temperatura impressa fica próxima de 30 °C. Pequenas diferenças de arredondamento são possíveis.
5. Capture o controle e o terminal, de preferência mostrando as leituras anteriores e posteriores à alteração. Salve como `06-variacao-do-sensor.png`.
6. Restaure 24 °C ao finalizar.

Se os controles não aparecerem, pare a simulação e altere apenas `"temperature": "24"` para `"temperature": "30"` no `diagram.json`. Salve e inicie novamente. Nesse procedimento, registre uma captura antes e outra depois, pois a reinicialização pode limpar o terminal. Depois, restaure o atributo para `"24"`.

| Condição | Resultado esperado | Resultado observado |
|---|---|---|
| Temperatura configurada em 24 °C | Leitura próxima de 24 °C | 24,00 °C na captura original |
| Temperatura configurada em 30 °C | Leitura próxima de 30 °C | Pendente de execução e captura |

Não altere o código C para imprimir o valor esperado. O objetivo é mostrar que a leitura acompanha a entrada do sensor virtual. O teste de variação é complementar e só deve ser marcado como realizado após a observação real.

## 3. Captura da compilação com texto maior

1. No terminal Docker, execute `cd /project/sensor_mpu6050` e `idf.py build`.
2. Aguarde `Project build complete`.
3. Arraste a divisória do terminal para cima para que ele ocupe a maior parte do painel.
4. Role para mostrar a mensagem de conclusão e as linhas anteriores. Se possível, inclua também o comando e a linha de tamanho do binário.
5. Salve como `07-compilacao-ampliada.png`.

A captura de compilação já incluída demonstra a conclusão. Essa nova imagem é apenas uma melhoria de legibilidade; não precisa executar `idf.py flash`.

## 4. Incorporar as novas evidências

Salve os screenshots reais na pasta do projeto. Depois de conferir cada um, copie-os para `docs/imagens/`, inclua legendas no README e publique os arquivos no GitHub. Até essa conferência, as cinco imagens existentes continuam sendo as evidências da entrega.
