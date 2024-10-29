#include <TheThingsNetwork.h>

// Set your AppEUI and AppKey
const char *appEui = "0004A30B001C3FBB";
const char *appKey = "a8d4748dc38b7111503cf784b58597c3";

#define loraSerial Serial1
#define debugSerial Serial

// Replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915
#define freqPlan TTN_FP_EU868

TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

void setup()
{
  debugSerial.begin(9600);
  loraSerial.begin(57600);

  debugSerial.println("-- JOIN");
 ttn.join(appEui, appKey);

    while (!debugSerial) {
    ;
    }

  debugSerial.println("-- STATUS");
  ttn.showStatus();

  

}

void loop()
{
  debugSerial.println("-- LOOP");

  digitalWrite(LED_BUILTIN, HIGH); 
  byte dataOn[1] = {1}; 
  ttn.sendBytes(dataOn, sizeof(dataOn)); 
  delay(500); // LED tændt i 500 ms 
  
  // Sluk LED og send "0" til gateway 
  digitalWrite(LED_BUILTIN, LOW); 
  byte dataOff[1] = {0}; 
  ttn.sendBytes(dataOff, sizeof(dataOff)); 
  delay(500); // LED slukket i 500 ms


  // Prepare array of 1 byte to indicate LED status
  //byte data[1];
  //data[0] = (digitalRead(LED_BUILTIN) == HIGH) ? 1 : 0;
 
  
  // Send it off
  //ttn.sendBytes(data, sizeof(data));
  
  //delay(5000);
}
