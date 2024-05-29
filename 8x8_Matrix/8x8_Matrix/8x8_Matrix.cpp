    #include <Arduino.h>
    #include <stdbool.h>
    #define joyX A0
    #define joyY A1
    #define C1 2
    #define C2 3
    #define C3 4
    #define C4 5
    #define C5 6
    #define C6 7
    #define C7 8
    #define C8 9

    int dataPin = 10;
    int clockPin = 12;
    int latchPin = 11;
    int lights_list[8] [8] = {
    {0,0,0,0,0,0,0,0},
    {0,1,1,0,0,1,1,0},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,0},
    {0,0,1,1,1,1,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0}
    };
    int const  led_list [8] = 
    {C1, C2, C3, C4, C5, C6, C7, C8};
    
    int rows = 0;
    int columns = 0;
    bool C1_STATUS, C2_STATUS, C3_STATUS, C4_STATUS, C5_STATUS, C6_STATUS, C7_STATUS, C8_STATUS;
    int byte_shift, latch_final;
    int round6 = 0;
    int round7 = 0;
    
    int status_list [8];
    
    void column_switch(){
          C1_STATUS= false;
          C2_STATUS= false;
          C3_STATUS= false;
          C4_STATUS= false;
          C5_STATUS= false;
          C6_STATUS= false;
          C7_STATUS= false;
          C8_STATUS= false;
      switch (columns) {
        case 0:
          Serial.print("Case 1  ");
          C1_STATUS= true;
          break;
        case 1:
          Serial.print("Case 2  ");
          C2_STATUS= true;
          break;
        case 2:
          Serial.print("Case 3  ");
          C3_STATUS= true;
          break;
        case 3:
          Serial.print("Case 4  ");
          C4_STATUS= true;
          break;
        case 4:
          Serial.print("Case 5  ");
          C5_STATUS= true;
          break;
        case 5:
          Serial.print("Case 6  ");
          C6_STATUS= true;
          break;
        case 6:
          Serial.print("Case 7  ");
          C7_STATUS= true;
          break;
        case 7:
          Serial.print("Case 8  ");
          C8_STATUS= true;
          break;
      }
      status_list [0] = C1_STATUS;
      status_list [1] = C2_STATUS;
      status_list [2] = C3_STATUS;
      status_list [3] = C4_STATUS;
      status_list [4] = C5_STATUS;
      status_list [5] = C6_STATUS;
      status_list [6] = C7_STATUS;
      status_list [7] = C8_STATUS;
    }
    int latch_list [8];
    

    void setup() {
      Serial.begin(9600);
      pinMode(dataPin, OUTPUT);
      pinMode(clockPin, OUTPUT);
      pinMode(latchPin, OUTPUT);
      pinMode(C1, OUTPUT);
	    pinMode(C2, OUTPUT);
	    pinMode(C3, OUTPUT);
      pinMode(C4, OUTPUT);
	    pinMode(C5, OUTPUT);
	    pinMode(C6, OUTPUT);
      pinMode(C7, OUTPUT);
	    pinMode(C8, OUTPUT);
    }

    void loop() {
      for(int j; j<8; j++){
        for(int k; k<8; k++){
          if (lights_list[k] [j] == 1){
            byte_shift = byte_shift << 1;
          }
          else if (lights_list[k] [j] == 0){
            byte_shift = byte_shift << 1;
            byte_shift++;
          }
        } 
      latch_final = byte_shift;  
      }
      
      if (rows<8){
        if(columns<8){
          column_switch();
          digitalWrite(latchPin, HIGH);
          shiftOut(dataPin, clockPin, LSBFIRST, latch_final);
          digitalWrite(latchPin, LOW); 
        }
        /*if(columns == 7){
          latch_list [0] = latch_final;
          for(int i; i<8; i++){
            latch_list[i] = latch_list[i-1];
          }
        }*/
      }
      else{
       rows = 0;
      }
      for(int col_clear = 0; col_clear <8; col_clear++){
        if (status_list[col_clear] != status_list[columns])
        digitalWrite(led_list[col_clear], 0);
      }
      digitalWrite(led_list[columns], status_list[columns]);
      Serial.print(rows);
      Serial.print("   ");
      Serial.println(columns);
      Serial.print("byte_shift: ");
      Serial.println(byte_shift);  
      Serial.print("led_list: ");
      Serial.println(led_list[columns]);
      Serial.print("status_list: ");
      Serial.println(status_list[columns]); 
      Serial.print("C3_STAT: ");
      Serial.println(C3_STATUS); 
      Serial.println("");

      /*if (columns <6){
        columns++;
      }
      if(columns == 6 && round6 == 1){
        columns++;
      }
      if (columns == 6){
        round6++;
      }
      if (columns == 7 && round7 == 1){
        rows++;
        columns = 0;
        byte_shift = 0;
        latch_final = 0;
        round6 = 0;
        round7 = 0;
      }
      if(columns == 7){
        round7++;
      }*/
    }
