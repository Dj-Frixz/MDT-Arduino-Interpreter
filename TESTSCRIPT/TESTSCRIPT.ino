uint8_t POTZ1 = A0;
int POTZ2 = A1;

void setup() {
  pinMode(POTZ1, INPUT);
  pinMode(POTZ2, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(POTZ1));
}
