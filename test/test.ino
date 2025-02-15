int p1_b1 = 0;
int p1_b2 = 0;
int p1_b3 = 0;
int p1_b4 = 0;
int p2_b1 = 0;
int p2_b2 = 0;
int p2_b3 = 0;
int p2_b4 = 0;
int p3_b1 = 0;
int p3_b2 = 0;
int p3_b3 = 0;
int p3_b4 = 0;
void setup() {
  for(int i=22; i<38; i++) {
    pinMode(i,INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  p1_b1 = digitalRead(22);
  p1_b2 = digitalRead(23);
  p1_b3 = digitalRead(24);
  p1_b4 = digitalRead(25);
  Serial.print("p1_b1 = ");
  Serial.println(p1_b1);
  Serial.print("p1_b2 = ");
  Serial.println(p1_b2);
  Serial.print("p1_b3 = ");
  Serial.println(p1_b3);
  Serial.print("p1_b4 = ");
  Serial.println(p1_b4);
  delay(500);
}
