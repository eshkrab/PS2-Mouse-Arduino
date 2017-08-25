#include <PS2Mouse.h>
#define NUM_TRACKBALLS 1  

//int tb_pins[NUM_TRACKBALLS][2] = { {2,3}, {4,5}, {6,7}, {8,9}, {14,15}, {16,17}};
//int tb_pins[NUM_TRACKBALLS][2] = { {2,3}, {4,5}};
int tb_pins[NUM_TRACKBALLS][2] = { {2,3}};
PS2Mouse * trackballs[NUM_TRACKBALLS];
int tb_data[NUM_TRACKBALLS][6];

//PS2Mouse mouse = PS2Mouse(3,2, STREAM);

void setup() {
  Serial.begin(57600);
  delay(1000);

  Serial.println("trackball setup");
  for (int i=0; i<NUM_TRACKBALLS; i++) {
    trackballs[i] = new PS2Mouse(tb_pins[i][1], tb_pins[i][0], STREAM);
    Serial.print(i);
    if (trackballs[i]->initialize() == -1){
      Serial.println("init failed");
    }
  }
  Serial.println();

  //mouse.initialize();

  Serial.println("setup done");
}

void loop() {
  //int data[6];
  //mouse.report(data);
  //Serial.print(data[0]); // Status Byte
  //Serial.print(":");
  //Serial.print(data[1]); // X Movement Data
  //Serial.print(",");
  //Serial.print(data[2]); // Y Movement Data
  //Serial.print(";");
  //Serial.print(data[3]); //MIDDLE 
  //Serial.print(",");
  //Serial.print(data[4]); // RIGHT
  //Serial.print(",");
  //Serial.print(data[5]); // LEFT
  //Serial.println();

  for (int i=0; i<NUM_TRACKBALLS; i++) {
    trackballs[i]->report(tb_data[i]);

    Serial.print(tb_data[i][0]); // Status Byte
    Serial.print(":");
    Serial.print(tb_data[i][1]); // X Movement Data
    Serial.print(",");
    Serial.print(tb_data[i][2]); // Y Movement Data
    Serial.print(";");
    Serial.print(tb_data[i][3]); //MIDDLE 
    Serial.print(",");
    Serial.print(tb_data[i][4]); // RIGHT
    Serial.print(",");
    Serial.print(tb_data[i][5]); // LEFT
    Serial.println();
  }
  Serial.println("---------------------");
  delay(100);
}
