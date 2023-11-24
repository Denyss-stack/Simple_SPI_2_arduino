#include <RF24.h>
#include <SPI.h>

RF24 radio(7, 8);
const byte address[6] = "00001"; // 5-byte address
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    int num;
    radio.read(&num, sizeof(num));

    // Increment the received number
    num++;
    Serial.println(num);
    // Send back the incremented number to the master
    //radio.write(&num, sizeof(num));
    
  }
}