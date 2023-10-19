/**
* A proof of concept, bare minimal code for a system
* to water a plant and measure its moisture.
*/

#include "pico/stdlib.h"
#include "hardware/adc.h"

#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#define PICO_DEFAULT_LED_PIN 25
#endif

int main()
{
    const int PUMP_PIN = 0;
    const int SENSOR_PIN = 1;
    const int LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_init(PUMP_PIN);
    adc_gpio_init(SENSOR_PIN);
    gpio_set_dir(PUMP_PIN, GPIO_OUT);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    const int vol_conversion_factor = 3.3f / (1 << 12);
    
    while (true) 
    {
        gpio_put(LED_PIN, 1);
        float water_value = adc_read()*vol_conversion_factor; // probs crashes here
        if (water_value < 0.7) 
        {
            gpio_put(PUMP_PIN, 1);
            sleep_ms(1000);
            gpio_put(PUMP_PIN, 0);
        }
        gpio_put(LED_PIN, 0);
        sleep_ms(5000);
    }
}
