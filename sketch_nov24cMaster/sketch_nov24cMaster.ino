#include <RF24.h>
#include <SPI.h>

RF24 radio(7, 8);
const byte address[6] = "00001"; // 5-byte address
const byte address2[6] = "00010";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.openReadingPipe(0, address2);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  int num = 5;
  radio.write(&num, sizeof(num));

  //Serial.println(num);
  if(radio.available()){
    int num;
    radio.read(&num, sizeof(num));
    Serial.println(num);
  }
  delay(3000);
}