#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>  

#define LED_VERMELHO 13  // Pino do LED vermelho
#define LED_VERDE 11     // Pino do LED verde
#define LED_AZUL 12      // Pino do LED azul
#define BUZZER_GPIO 21   // Pino do buzzer

const uint32_t buzzer_frequency = 250;

// Ativa o buzzer com uma certa frequência e por um certo tempo
void buzzer_active(uint32_t buzzer_frequency_in, uint32_t duration_buzzer_on) {
    uint32_t half_period_us = (1000000 / buzzer_frequency_in) / 2; // Define por quanto tempo o pino conectado ao buzzer deve ficar em nível alto/baixo

    // gera uma onda quadrada
    for (uint32_t i = 0; i < duration_buzzer_on * 1000; i += half_period_us * 2) {
        gpio_put(BUZZER_GPIO, 1);
        sleep_us(half_period_us);
        gpio_put(BUZZER_GPIO, 0);
        sleep_us(half_period_us);
    }
}

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
        buzzer_active(buzzer_frequency, 2000);
        printf("\nBUZZER ativo em %d HZ!\n", buzzer_frequency);
    } else {
        printf("\nComando nao reconhecido: %s\n", command);
    }
}

int main() {
    char command[1024];  

    stdio_init_all();

    gpio_init(LED_VERMELHO);
    gpio_init(LED_VERDE);
    gpio_init(LED_AZUL);
    gpio_init(BUZZER_GPIO);

    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_set_dir(BUZZER_GPIO, GPIO_OUT);

    while (true) {
        if (stdio_usb_connected()) {
            printf("\nDIGITE O COMANDO: "); 
            scanf("%1024s", command);

            processar_comando(command);
        }
    }

    return 0;
}
