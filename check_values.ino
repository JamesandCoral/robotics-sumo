

#include <Adafruit_MCP3008.h>

Adafruit_MCP3008 adc;

int count = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("MCP3008 simple test.");

  // Hardware SPI (specify CS, use any available digital)
  // Can use defaults if available, ex: UNO (SS=10) or Huzzah (SS=15)
  adc.begin();
  // Feather 32u4 (SS=17) or M0 (SS=16), defaults SS not broken out, must specify
  //adc.begin(10);

  // Software SPI (specify all, use any available digital)
  // (sck, mosi, miso, cs);
  //adc.begin(13, 11, 12, 10);
}

void loop() {

/*
  Serial.print("L =  "); Serial.print(adc.readADC(1)); Serial.print("   ");
  Serial.print("K =   "); Serial.print(adc.readADC(3)); Serial.print("   ");
  Serial.print("R=   "); Serial.print(adc.readADC(6)); Serial.print("   ");
*/
  Serial.print("L sensor=   "); Serial.print(adc.readADC(1)); Serial.print("   ");
  Serial.print("R sensor=   "); Serial.print(adc.readADC(5)); Serial.print("   ");
  
  Serial.println("   ");
  delay(100);
}
