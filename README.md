# Controle de LEDs e Buzzer no Raspberry Pi Pico (EMBARCATECH/U4-ATV2)

Este projeto implementa a funcionalidade de controle de LEDs e um buzzer no Raspberry Pi Pico utilizando a linguagem C. O programa interage com o microcontrolador via comandos recebidos pelo terminal serial USB, permitindo realizar diversas ações de controle. Ele é a solução para a Atividade 2 - Unidade 4 do programa de residência da Embarcatech.

## 🖥️ Estrutura do Código

O programa está estruturado em funções que processam comandos enviados via terminal. Cada comando realiza uma ação específica, como ligar/desligar LEDs ou acionar o buzzer.

### Configuração Inicial

Os pinos configurados no programa são:
- **LED Vermelho**: GPIO 13
- **LED Verde**: GPIO 11
- **LED Azul**: GPIO 12
- **Buzzer**: GPIO 21

Todos os pinos são configurados como saída digital.

### Comandos Disponíveis

A tabela abaixo descreve os comandos implementados e suas funcionalidades planejadas:

| **Comando** | **Descrição**                                     | **Responsável** |
|-------------|---------------------------------------------------|-----------------|
| `RED`       | Liga o LED vermelho (GPIO 13).                    | Pedro Duarte    |
| `GREEN`     | Liga o LED verde (GPIO 11).                       | Ícaro           |
| `BLUE`      | Liga o LED azul (GPIO 12).                        | Samyr           |
| `WHITE`     | Liga todos os LEDs, simulando luz branca.         | Bruna           |
| `OFF`       | Desliga todos os LEDs.                            | Reinan          |
| `BUZZER`    | Aciona o buzzer por 2 segundos.                   | Gabriel Shiva   |
| `SEQUENCE`  | Liga os LEDs em animação sequencial.              |                 |
| `REBOOT`    | Habilita modo gravação (reboot).                  |                 |

## 🔧 Como Usar

1. **Configuração do Ambiente**:
   - Conecte o Raspberry Pi Pico ao computador via USB.
   - Compile o programa e faça o upload para o Pico.

2. **Execução do Programa**:
   - Abra um terminal serial (por exemplo `Putty`) configurado com as especificações corretas do Pico.
   - Digite os comandos conforme a tabela acima para executar as funcionalidades.

## Link para Apresentação em Vídeo

O vídeo demonstrando o funcionamento do projeto pode ser acessado [aqui](https://drive.google.com/file/d/1DEAElFLA5ENNIuHGiwDmEz23rfH2NVKk/view?usp=drivesdk).
