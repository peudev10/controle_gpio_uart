#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"

#define LED_RED 13
#define LED_GREEN 11
#define LED_BLUE 12
#define BUZZER_PIN 21

void init()
{
    // configuração inicial dos LEDs

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, 0);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_put(LED_GREEN, 0);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_put(LED_BLUE, 0);

    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
}

void green_on()
{
    gpio_put(LED_GREEN, 1);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_RED, 0);
    printf("Verde\n");
    sleep_ms(2000);
}

void blue_on()
{
    gpio_put(LED_BLUE, 1);
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_RED, 0);
    printf("Azul\n");
    sleep_ms(2000);
}

void red_on()
{
    gpio_put(LED_RED, 1);
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
    printf("Vermelho\n");
    sleep_ms(2000);
}

void white_on()
{
    gpio_put(LED_RED, 1);
    gpio_put(LED_GREEN, 1);
    gpio_put(LED_BLUE, 1);
    printf("Branco\n");
    sleep_ms(2000);
}

void turn_off()
{
    gpio_put(LED_RED, 0);
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
    printf("Off\n");
    sleep_ms(2000);
}

void buzzer_active(uint32_t buzzer_frequency, uint32_t duration_buzzer_on)
{
    uint32_t half_period_us = (1000000 / buzzer_frequency) / 2; // Define por quanto tempo o pino conectado ao buzzer deve ficar em nível alto/baixo

    // gera uma onda quadrada
    for (uint32_t i = 0; i < duration_buzzer_on * 1000; i += half_period_us * 2)
    {
        gpio_put(BUZZER_PIN, 1);
        sleep_us(half_period_us);
        gpio_put(BUZZER_PIN, 0);
        sleep_us(half_period_us);
    }
}

int main()
{
    stdio_init_all();
    init();
    char buffer[1024];

    while (true)
    {
        fflush(stdin);
        scanf("%s", buffer);
        if(strcmp(buffer, "verde") == 0){
            green_on();
        }
        if(strcmp(buffer, "azul") == 0){
            blue_on();
        }
        if(strcmp(buffer, "vermelho") == 0){
            red_on();
        }
        if(strcmp(buffer, "branco") == 0){
            white_on();
        }
        if(strcmp(buffer, "off") == 0){
            turn_off();
        }
        if(strcmp(buffer, "som") == 0){
            buzzer_active(900, 2000);
        }
    }
}
