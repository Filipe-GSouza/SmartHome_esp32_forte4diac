/*
 * hutschienenmoped_led_strip.h
 *
 *  Created on: 20.02.2023
 *      Author: franz
 */

#ifndef SRC_MODULES_ESP_ADDONS_HUTSCHIENENMOPED_LED_STRIP_H_
#define SRC_MODULES_ESP_ADDONS_HUTSCHIENENMOPED_LED_STRIP_H_


#if CONFIG_IDF_TARGET_ESP32 //M5 Stack Atom Lite and PSRAM.
  #define LED_IO       (GPIO_NUM_27) /*!< GPIO_NUM_27, input and output */
#elif CONFIG_IDF_TARGET_ESP32S2
  #define LED_IO       (GPIO_NUM_27) /*!< GPIO_NUM_27, input and output */
#elif CONFIG_IDF_TARGET_ESP32S3
  #define LED_IO       (GPIO_NUM_27) /*!< GPIO_NUM_27, input and output */
#elif CONFIG_IDF_TARGET_ESP32C3  //M5 STAMP-C3
  #define LED_IO       (GPIO_NUM_2) /*!< GPIO_NUM_2, input and output */
#elif CONFIG_IDF_TARGET_ESP32H4
  #define LED_IO       (GPIO_NUM_27) /*!< GPIO_NUM_27, input and output */
#elif CONFIG_IDF_TARGET_ESP32C2
  #define LED_IO       (GPIO_NUM_27) /*!< GPIO_NUM_27, input and output */
#elif CONFIG_IDF_TARGET_ESP32C6
  #define LED_IO       (GPIO_NUM_27) /*!< GPIO_NUM_27, input and output */
#elif CONFIG_IDF_TARGET_ESP32H2
  #define LED_IO       (GPIO_NUM_27) /*!< GPIO_NUM_27, input and output */
#else
  #error no known Target
#endif


#endif /* SRC_MODULES_ESP_ADDONS_HUTSCHIENENMOPED_LED_STRIP_H_ */
