int ch1, ch2, turn, direction;
const int pwmA = 5, Ain_1 = 2, Ain_2 = 3;
const int pwmB = 6, Bin_1 = 4, Bin_2 = 7;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  tone(0, 1000, 200);
  while(analogRead(A6 < 500));
  tone(0, 1000, 200);

}

void loop() {?ษฬ
  Read();

}

void Read() {
  ch1 = pulseIn(A0, HIGH, 25000); delay(10);
  ch2 = pulseIn(A1, HIGH, 25000); delay(10);
  turn = map(ch1, 1000, 2000, -255, 255);
  direction = map(ch2, 1000, 2000, -255, 255);
  if (turn >= 255)turn = 255;
  if (turn <= -255)turn = -255;
  if (direction >= 255)direction = 255;
  if (direction <= 255)direction = -255;
  Serial.print("ch1 = "); Serial.print(ch1);
  Serial.print("ch2 = "); Serial.println(ch2);
}
