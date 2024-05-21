/*New Blynk app with Home Automation
   Home Page
*/

//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Define the relay pins
#define relay1 D1
#define relay2 D2
//#define BLYNK_TEMPLATE_ID "TMPLyDjT_MiG"
//#define BLYNK_DEVICE_NAME "Home automation"
#define BLYNK_AUTH_TOKEN "5wpN2dKeunm9klfOQCT1uTmK6scQSAu6"

char auth[] = "5wpN2dKeunm9klfOQCT1uTmK6scQSAu6";
char ssid[] = "Infinity";
char pass[] = "kshitij@12";

//Get the button values
BLYNK_WRITE(V1) {
  bool value1 = param.asInt();
  // Check these values and turn the relay1 ON and OFF
  if (value1 == 1) {
    digitalWrite(relay1, LOW);
  } else {
    digitalWrite(relay1, HIGH);
  }
}

//Get the button values
BLYNK_WRITE(V2) {
  bool value2 = param.asInt();
  // Check these values and turn the relay2 ON and OFF
  if (value2 == 1) {
    digitalWrite(relay2, LOW);
  } else {
    digitalWrite(relay2, HIGH);
  }
}

void setup() {
  //Set the relay pins as output pins
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);

  // Turn OFF the relay
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);

  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}
