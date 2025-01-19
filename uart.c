#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>  

#define LED_VERMELHO 13  // Pino do LED vermelho
#define LED_VERDE 11     // Pino do LED verde
#define LED_AZUL 12      // Pino do LED azul
#define BUZZER_GPIO 21   // Pino do buzzer

// Função para controlar os LEDs
void controlar_led(int led_ativo) {
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
 
    if (led_ativo != 0) {
        gpio_put(led_ativo, 1);
    }
}

void ligar_leds(bool led_ativo){// Função para ligar todos os LEDs
    gpio_put(LED_VERMELHO, led_ativo);
    gpio_put(LED_VERDE, led_ativo);
    gpio_put(LED_AZUL, led_ativo);
}

// Função para processar o comando recebido
void processar_comando(const char *command) {
    if (strcmp(command, "RED") == 0) {
        controlar_led(LED_VERMELHO);
        printf("\nLED vermelho aceso!\n");
    } else if (strcmp(command, "GREEN") == 0) {
         controlar_led(LED_VERDE);
        printf("\nLED verde aceso!\n");
        
    } else if (strcmp(command, "BLUE") == 0) {
        controlar_led(LED_AZUL);
        printf("\nLED azul aceso!\n");
        
    } else if (strcmp(command, "WHITE") == 0) {
        ligar_leds(1);
        printf("\nLED branco aceso!\n");
        
    } else if (strcmp(command, "OFF") == 0) {
        controlar_led(0);
        printf("\nLEDs desligados!\n");
        
    } else if (strcmp(command, "BUZZER") == 0) {
        
    } else {
        printf("\nComando nao reconhecido: %s\n", command);
    }
}

int main() {
    stdio_init_all();

    gpio_init(LED_VERMELHO);
    gpio_init(LED_VERDE);
    gpio_init(LED_AZUL);
    gpio_init(BUZZER_GPIO);

    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_set_dir(BUZZER_GPIO, GPIO_OUT);

    char command[10] = {0};  
    int index = 0;

    while (true) {
        if (stdio_usb_connected()) {
            int c = getchar_timeout_us(10000);
            if (c != PICO_ERROR_TIMEOUT) {
                if (c == '\n' || c == '\r') {  // Final da entrada
                    command[index] = '\0';  // Finaliza a string

                    processar_comando(command);  // Processa o comando recebido

                    index = 0; 
                    memset(command, 0, sizeof(command));  // Limpa o buffer

                } else if (index < sizeof(command) - 1) {
                    command[index++] = (char)c;  // Adiciona caractere ao buffer
                    putchar(c);  // imprime caractere no terminal
                }
            }
        }
    }

    return 0;
}
