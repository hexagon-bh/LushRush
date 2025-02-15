#include <Adafruit_NeoPixel.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

SoftwareSerial mySerial(11, 12); // RX, TX 핀 설정
DFRobotDFPlayerMini myDFPlayer;
Adafruit_NeoPixel pixels1(63, 6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(5, 7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(5, 8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4(5, 9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels5(5, 10, NEO_GRB + NEO_KHZ800);

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
int all_butten = 0;
int p1_click = 0;
int p2_click = 0;
int p3_click = 0;
int p1_color = 0;
int p2_color = 0;
int p3_color = 0;
int temp = 0;

void setup() {
  Serial.begin(9600); // 디버깅용 시리얼 통신
  mySerial.begin(9600); // DFPlayer Mini 통신
  randomSeed(analogRead(0));

  if (!myDFPlayer.begin(mySerial)) {
    Serial.println("DFPlayer Mini 초기화 실패!");
    while (true);
  }
  Serial.println("DFPlayer Mini 초기화 성공!");

  myDFPlayer.setTimeOut(500); // 통신 시간 초과 설정 (500ms)
  myDFPlayer.volume(30); // 볼륨 설정 (0~30)
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL); // EQ 설정
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD); // SD 카드 설정
  
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels2.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels3.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels4.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels5.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  for(int i=0; i<63; i++) {
    pixels1.setPixelColor(i, pixels1.Color(150, 150, 150));
  }
  for(int i=0; i<5; i++) {
    pixels2.setPixelColor(i, pixels2.Color(150, 0, 0));//빨
  }
  for(int i=0; i<5; i++) { // For each pixel...
    pixels3.setPixelColor(i, pixels3.Color(150, 150, 0));//노
  }
  for(int i=0; i<5; i++) { // For each pixel...
    pixels4.setPixelColor(i, pixels4.Color(0, 150, 0));//초
  }
  for(int i=0; i<5; i++) { // For each pixel...
    pixels5.setPixelColor(i, pixels5.Color(0, 0, 150));//파
  }
  pixels1.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();
  pixels5.show();
  
  for(int i=26; i<38; i++) {
    pinMode(i,INPUT_PULLUP);
  }
  for(int i=2; i<6; i++) {
    pinMode(i,OUTPUT);
  }
  delay(2000);
  for(int i=0; i<5; i++) { // For each pixel...
    pixels2.setPixelColor(i, pixels2.Color(200, 200, 200));//파
  }
  pixels3.clear();
  pixels4.clear();
  pixels5.clear();
  pixels2.show();
  pixels3.show();
  pixels4.show();
  pixels5.show();
  myDFPlayer.play(1); //29초
  delay(30000);
}

void loop() {
  myDFPlayer.play(2); //14초
  delay(14000);
  while(all_butten < 3){
    p1_b1 = digitalRead(26);
    p1_b2 = digitalRead(27);
    p1_b3 = digitalRead(28);
    p1_b4 = digitalRead(29);
    p2_b1 = digitalRead(30);
    p2_b2 = digitalRead(31);
    p2_b3 = digitalRead(32);
    p2_b4 = digitalRead(33);
    p3_b1 = digitalRead(34);
    p3_b2 = digitalRead(35);
    p3_b3 = digitalRead(36);
    p3_b4 = digitalRead(37);
    if(p1_click == 0){
      if(p1_b1 == 0){
        p1_color = 1;
        for(int i=0; i<5; i++) {
          pixels3.setPixelColor(i, pixels3.Color(150, 0, 0));//빨
        }
        pixels3.show();
        p1_click = 1;
        all_butten++;
      }
      else if(p1_b2 == 0){
        p1_color = 2;
        for(int i=0; i<5; i++) {
          pixels3.setPixelColor(i, pixels3.Color(150, 150, 0));//노
        }
        pixels3.show();
        p1_click = 1;
        all_butten++;
      }
      else if(p1_b3 == 0){
        p1_color = 3;
        for(int i=0; i<5; i++) {
          pixels3.setPixelColor(i, pixels3.Color(0, 150, 0));//초
        }
        pixels3.show();
        p1_click = 1;
        all_butten++;
      }
      else if(p1_b4 == 0){
        p1_color = 4;
        for(int i=0; i<5; i++) {
          pixels3.setPixelColor(i, pixels3.Color(0, 0, 150));//초
        }
        pixels3.show();
        p1_click = 1;
        all_butten++;
      }
    }//플레이어 1
    
    if(p2_click == 0){
      if(p2_b1 == 0){
        p2_color = 1;
        for(int i=0; i<5; i++) {
          pixels4.setPixelColor(i, pixels4.Color(150, 0, 0));//빨
        }
        pixels4.show();
        p2_click = 1;
        all_butten++;
      }
      else if(p2_b2 == 0){
        p2_color = 2;
        for(int i=0; i<5; i++) {
          pixels4.setPixelColor(i, pixels4.Color(150, 150, 0));//노
        }
        pixels4.show();
        p2_click = 1;
        all_butten++;
      }
      else if(p2_b3 == 0){
        p2_color = 3;
        for(int i=0; i<5; i++) {
          pixels4.setPixelColor(i, pixels4.Color(0, 150, 0));//초
        }
        pixels4.show();
        p2_click = 1;
        all_butten++;
      }
      else if(p2_b4 == 0){
        p2_color = 4;
        for(int i=0; i<5; i++) {
          pixels4.setPixelColor(i, pixels4.Color(0, 0, 150));//초
        }
        pixels4.show();
        p2_click = 1;
        all_butten++;
      }
    }//플레이어 2

    if(p3_click == 0){
      if(p3_b1 == 0){
        p3_color = 1;
        for(int i=0; i<5; i++) {
          pixels5.setPixelColor(i, pixels5.Color(150, 0, 0));//빨
        }
        pixels5.show();
        p3_click = 1;
        all_butten++;
      }
      else if(p3_b2 == 0){
        p3_color = 2;
        for(int i=0; i<5; i++) {
          pixels5.setPixelColor(i, pixels5.Color(150, 150, 0));//노
        }
        pixels5.show();
        p3_click = 1;
        all_butten++;
      }
      else if(p3_b3 == 0){
        p3_color = 3;
        for(int i=0; i<5; i++) {
          pixels5.setPixelColor(i, pixels5.Color(0, 150, 0));//초
        }
        pixels5.show();
        p3_click = 1;
        all_butten++;
      }
      else if(p3_b4 == 0){
        p3_color = 4;
        for(int i=0; i<5; i++) {
          pixels5.setPixelColor(i, pixels5.Color(0, 0, 150));//초
        }
        pixels5.show();
        p3_click = 1;
        all_butten++;
      }
    }//플레이어 3
    Serial.print("all_butten = ");
    Serial.println(all_butten);
    Serial.print("p1 = ");
    Serial.println(p1_color);
    Serial.print("p2 = ");
    Serial.println(p2_color);
    Serial.print("p3 = ");
    Serial.println(p3_color);
  }
  myDFPlayer.play(3);//8초
  delay(8000);
  temp = random(1,5);
  Serial.print("random = ");
  Serial.println(temp);
  if(temp == 1){
    for(int i=0; i<63; i++) {
      pixels1.setPixelColor(i, pixels1.Color(150, 0, 0));//빨
    }
    pixels1.show();
  }
  else if(temp == 2){
    for(int i=0; i<63; i++) {
      pixels1.setPixelColor(i, pixels1.Color(150, 150, 0));//노
    }
    pixels1.show();
  }
  else if(temp == 3){
    for(int i=0; i<63; i++) {
      pixels1.setPixelColor(i, pixels1.Color(0, 150, 0));//초
    }
    pixels1.show();
  }
  else if(temp == 4){
    for(int i=0; i<63; i++) {
      pixels1.setPixelColor(i, pixels1.Color(0, 0, 150));//파
    }
    pixels1.show();
  }
  delay(500);
  if(temp == p1_color){
    digitalWrite(3,HIGH);
  }
  if(temp == p2_color){
    digitalWrite(2,HIGH);
  }
  if(temp == p3_color){
    digitalWrite(5,HIGH);
  }
  delay(1700);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
  digitalWrite(5,LOW);
  if(temp == p1_color || temp == p2_color || temp == p3_color ){
    myDFPlayer.play(4);//8초
    delay(14000);
    delay(20000);
  }
  else{
    myDFPlayer.play(5);//8초
    delay(11000);
  }
  all_butten = 0;
  p1_click = 0;
  p2_click = 0;
  p3_click = 0;
  p1_color = 0;
  p2_color = 0;
  p3_color = 0;
  temp = 0;
  for(int i=0; i<63; i++) {
    pixels1.setPixelColor(i, pixels1.Color(150, 150, 150));
  }
  pixels3.clear();
  pixels4.clear();
  pixels5.clear();
  pixels1.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();
  pixels5.show();
}
