/*************************************************** 
  This is a library for the HTU21D-F Humidity & Temp Sensor

  Designed specifically to work with the HTU21D-F sensor from Adafruit
  ----> https://www.adafruit.com/products/1899

  These displays use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include "Wire.h"

#define HTU21DF_I2CADDR       0x40
#define HTU21DF_READTEMP      0xE3
#define HTU21DF_READHUM       0xE5
#define HTU21DF_WRITEREG       0xE6
#define HTU21DF_READREG       0xE7
#define HTU21DF_RESET       0xFE

#define RH8_T12 0b00000001
#define RH10_T13 0b10000000
#define RH11_T11 0b10000001
#define RH12_T14 0b00000000


class Adafruit_HTU21DF {
 public:
  Adafruit_HTU21DF();
  boolean begin(void);
  boolean begin(byte resBits);
  float readTemperature(void);
  float readHumidity(void);
  void setResolution(byte resBits);
  void reset(void);
 private:
  boolean readData(void);
  byte read_user_register(void);
  float humidity, temp;
};

