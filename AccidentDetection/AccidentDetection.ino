#include <SparkFun_u-blox_SARA-R5_Arduino_Library.h>
SARA_R5 mySARA;

void setup() {
  //setup_get_angle();
  //setup_GPS();
  setup_network_operator();
  setup_SMS();
}

void loop() {
  /*do {
    GPS();
  } while (!get_angle());
  SMS();
  print_info();
  delay(1000);*/
}

void print_info() {
  Serial.println("=========================================");
  print_data();
  print_GPS();
  Serial.println("=========================================");
}
