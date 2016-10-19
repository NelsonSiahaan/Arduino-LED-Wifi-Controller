////////////////////////////////////////////////////////////////////////////////
// Arduino-LED-Wifi-Controller.ino - Main controller for the esp8266 module as
// part of the Arduino-LED-Controller project.
//
// Copyright 2016 Samuel R Fields
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////////

#include <ESP8266WiFi.h>

#include "WifiDefs.h"

String serialInputString = "";
bool serialDataReady = false;

////////////////////////////////////////////////////////////////////////////////
// @brief
// RReads serial input and processes command responses
////////////////////////////////////////////////////////////////////////////////
void
processSerial(
   void
   )
{
   if (strncmp(serialInputString, "ON", 2) == 0)
   {
      // Send the response back to the app
   }
   else if (strncmp(serialInputString, "OFF", 3) == 0)
   {
      // Send the response back to the app
   }
}

////////////////////////////////////////////////////////////////////////////////
// @brief
// Initializes necessary values during power on
////////////////////////////////////////////////////////////////////////////////
void 
setup(
   void
   ) 
{
   Serial.begin(115200);
   serialInputString.reserve(256);

   // Connect to Wifi network
   WiFi.begin(ssid, password);
  
   while (WiFi.status() != WL_CONNECTED) 
   {
      // Put non-blocking delay here
   }
}

////////////////////////////////////////////////////////////////////////////////
// @brief
// The Wifi controller's main loop.
////////////////////////////////////////////////////////////////////////////////
void 
loop(
   void
   ) 
{
   if (serialDataReady)
   {
      processSerial();
      serialInputString = "";
      serialDataReady = false;
   }

   // // Use WiFiClient class to create TCP connections
   // WiFiClient client;
   // const int httpPort = 80;
   // if (!client.connect(host, httpPort)) 
   // {
   //    Serial.println("connection failed");
   //    return;
   // }
  
   // // We now create a URI for the request
   // String url = "/testwifi/index.html";
   // Serial.print("Requesting URL: ");
   // Serial.println(url);
  
   // // This will send the request to the server
   // client.print(String("GET ") + url + " HTTP/1.1\r\n" +
   //             "Host: " + host + "\r\n" + 
   //             "Connection: close\r\n\r\n");
   // delay(500);
  
   // // Read all the lines of the reply from server and print them to Serial
   // while(client.available())
   // {
   //    String line = client.readStringUntil('\r');
   //    Serial.print(line);
   // }
  
   // Serial.println();
   // Serial.println("closing connection");
}

////////////////////////////////////////////////////////////////////////////////
// @brief
// Processes serial coming from the Arduino LED controller
////////////////////////////////////////////////////////////////////////////////
void
serialEvent(
   void
   )
{
   while (Serial.available())
   {
      char in = (char)Serial.read();
      serialInputString += in;
      if (in == '\n')
      {
         serialDataReady = true;
      }
   }
}