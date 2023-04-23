#include <Adafruit_MCP3008.h>
Adafruit_MCP3008 adc;
int pwma = 5, ina1 = 2, ina2 = 3;
int pwmb = 6, inb1 = 4, inb2 = 7;
void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("MCP3008 simple test.");
  adc.begin();
  pinMode(pwma, OUTPUT);
  pinMode(ina1, OUTPUT);
  pinMode(ina2, OUTPUT);
  pinMode(pwmb, OUTPUT);
  pinMode(inb1, OUTPUT);
  pinMode(inb2, OUTPUT);
  tone(8, 1000, 200);
  while (analogRead(A6) < 500);
  tone(8, 1000, 200);
  motor(127, 127); delay(1000); motor(0, 0); delay(1000);
  motor(-127, -127); delay(1000); motor(0, 0); delay(1000);
  motor(127, -127); delay(1000); motor(0, 0); delay(1000);
  motor(-127, 127); delay(1000); motor(0, 0); delay(1000);
}

void loop() {
  Serial.print(adc.readADC(0)); Serial.print("\t");
  Serial.print(adc.readADC(1)); Serial.print("\t");
  Serial.print(adc.readADC(3)); Serial.print("\t");
  Serial.print(adc.readADC(6)); Serial.print("\t");
  Serial.print(adc.readADC(7)); Serial.print("\t");
  Serial.println(); delay(100);
}

void motor(int A, int B) {
  if (A > 0) {
    analogWrite(pwma, A);
    digitalWrite(ina1, LOW);
    digitalWrite(ina2, HIGH);
  }
  if (A <= 0) {
    analogWrite(pwma, -A);
    digitalWrite(ina1, HIGH);
    digitalWrite(ina2, LOW);
  }
  if (B > 0) {
    analogWrite(pwmb, B);
    digitalWrite(inb1, LOW);
    digitalWrite(inb2, HIGH);
  }
  if (B <= 0) {
    analogWrite(pwmb, -B);
    digitalWrite(inb1, HIGH);
    digitalWrite(inb2, LOW);
  }
}
