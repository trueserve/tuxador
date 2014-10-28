/*
 * Tuxador
 * a simple door counter device
 *
 * circuit and code Copyright 2014 true <trueamx at gmail dot com>
 * original idea and code Copyright 2014 tuxavant <tuxavant at tuxavant dot com>
 *
 */

#include <stdint.h>

#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/sleep.h>


/* -- LCD COMMON ------------------------- */
#define LCD_HD44780          0  // 16x2 character LCD
#define LCD_ST7735_HW        1  // typically 1.8" 128x160 TFT LCD using HW SPI
#define LCD_ST7735_SW        2  // above, but using soft SPI
                                // The original circuit uses hard SPI because only MOSI is used
                                // Also, the LED will NOT be used in hard SPI mode,
                                // instead any indicators will be on-screen.
#define LCD_BACKLIGHT        6  // pin 6 = brightness control. other pins on/off only


/* -- HD44780 CONFIG --------------------- */
#define LCD_HD44780_D4       A0 // HD44780 pin 11-14, must be on the same port, ascending
#define LCD_HD44780_EN       7  // HD44780 pin 6
#define LCD_HD44780_RS       8  // HD44780 pin 4
 
 
/* -- ST7735 CONFIG ---------------------- */
#define LCD_ST7735_RESET     7  // HD44780 pin 6
#define LCD_ST7735_A0        8  // HD44780 pin 7, jumpered
#define LCD_ST7735_SW_MOSI   A3 // HD44780 pin 8, jumpered
#define LCD_ST7735_SW_SCK    A2 // HD44780 pin 9, jumpered
#define LCD_ST7735_CS        A0 // HD44780 pin 10, jumpered
