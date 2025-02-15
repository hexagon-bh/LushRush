

void setup() {
  Serial.begin(9600); // 디버깅용 시리얼 통신
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  digitalWrite(3,HIGH);
  delay(500);
  digitalWrite(3,LOW);
  delay(500);
  digitalWrite(2,HIGH);
  delay(500);
  digitalWrite(2,LOW);
  delay(500);
  digitalWrite(5,HIGH);
  delay(500);
  digitalWrite(5,LOW);
  delay(500);
}
