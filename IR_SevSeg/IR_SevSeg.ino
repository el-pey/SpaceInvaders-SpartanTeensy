#include "SevSeg.h"
#include <IRremote.h>

elapsedMillis sinceTest1;

elapsedMillis sinceWord1;
elapsedMillis sinceWord2;

int RECV_PIN = 0;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long lastValidDecode;
unsigned long currentDecodedIR;

void setup(){
 Serial.begin(9600); 
 sevSeg_pinSetup();
 irrecv.enableIRIn(); // Start the receiver
 sevSeg_update(16, 0, 18, 10, -3);
}

void loop(){  
  
  if (irrecv.decode(&results)) {    
    
    if(results.value != REPEAT && results.value != 0){
      lastValidDecode = results.value;
      currentDecodedIR = lastValidDecode;
    } else{
     if (results.value == REPEAT){
       currentDecodedIR = lastValidDecode;
     }     
    }
    
    sevSeg_update(currentDecodedIR, 4);
    Serial.println(currentDecodedIR, HEX);
    irrecv.resume(); // Receive the next value
  }
  sevSeg_refresh();
}
