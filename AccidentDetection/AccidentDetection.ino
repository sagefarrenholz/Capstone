
void setup() {
  GetAngleSetup();
  GPSsetup();
}

void loop() {
  bool sendmessage = false;
  while(!sendmessage) {
    GPS();
    if (GetAngle()) {
      //send text message
      sendmessage = true;
    }
  }
  SMS();
  delay(1000);
}

void SMS() {
  Serial.println("=========================================");
  printData();
  printGPS();
  Serial.println("=========================================");
}
