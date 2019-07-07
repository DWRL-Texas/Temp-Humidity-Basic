/*
 * The DHT sensor measures temperature and relative humidity. 
 Expressed as a percentage, relative humidity is
 the amount of water vapor in the air divided by 
 the saturation point (the amount of water the air can hold at a given temperature).
 */

// Download the DHT sensor library and add it to the "libraries" folder before getting started.

#include <dht.h>

dht DHT;

#define DHT11_PIN 7 // DHT pin "S" connected to digital pin 7
// The middle pin on the DHT sensor is Vcc (+)
// The right pin on the DHT sensor is GND (-)

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  if((DHT.temperature * 9/5 + 32 ) > 0){
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature * 9/5 + 32);
  }
  if(DHT.humidity > 0){
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
  }
  
  delay(5000);
}
