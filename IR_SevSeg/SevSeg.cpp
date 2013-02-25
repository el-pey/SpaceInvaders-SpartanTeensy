
#include "SevSeg.h"

short valueDigit1 = 0;
short valueDigit2 = 0;
short valueDigit3 = 0;
short valueDigit4 = 0;
short DP_pos = 4;

long digitInterval = 1; 
elapsedMillis sinceDigitChange;

short currentDigit = 1;
int digToDecode = 7;

boolean statusDigit1 = true;
boolean statusDigit2 = false;
boolean statusDigit3 = false;
boolean statusDigit4 = false;

boolean dp_on = false;

void sevSeg_pinSetup(){
   pinMode(DIGIT1, OUTPUT);
   pinMode(DIGIT2, OUTPUT);
   pinMode(DIGIT3, OUTPUT);
   pinMode(DIGIT4, OUTPUT);
   pinMode(COLON_ANODE, OUTPUT);
   pinMode(COLON_CATHODE, OUTPUT);
   pinMode(APOSTROPHE_ANODE, OUTPUT);
   pinMode(APOSTROPHE_CATHODE, OUTPUT);
   pinMode(SEG_A, OUTPUT);
   pinMode(SEG_B, OUTPUT);
   pinMode(SEG_C, OUTPUT);
   pinMode(SEG_D, OUTPUT);
   pinMode(SEG_E, OUTPUT);
   pinMode(SEG_F, OUTPUT);
   pinMode(SEG_G, OUTPUT);
   pinMode(DECIMAL_POINT, OUTPUT);

}

void sevSeg_update(short digit1, short digit2, short digit3, short digit4, short DP_posIn){
  
  valueDigit1 = digit1;
  valueDigit2 = digit2;
  valueDigit3 = digit3;
  valueDigit4 = digit4;
  
  if(DP_posIn > 0 && DP_posIn < 5){    
   DP_pos = DP_posIn;    
  } else{
   DP_pos = 4; 
  }  
}

void sevSeg_update(unsigned long toDisp, short DP_posIn){
  sevSeg_update((toDisp & 0xF000)>>12, (toDisp & 0xF00)>>8, (toDisp & 0xF0)>>4, (toDisp & 0xF), DP_posIn);  
}

void sevSeg_refresh(){
  
  
  char decodedOutput;
  
  if(sinceDigitChange >= digitInterval) {
   
    sinceDigitChange = sinceDigitChange - digitInterval;  
    
    switch (currentDigit){
     case 1:
    currentDigit = 2;
    statusDigit1 = false;
    statusDigit2 = true;
    statusDigit3 = false;
    statusDigit4 = false;
    digToDecode = valueDigit2;
    
   break;
   case 2:
    currentDigit = 3;
    statusDigit1 = false;
    statusDigit2 = false;
    statusDigit3 = true;
    statusDigit4 = false;
    digToDecode = valueDigit3;
   break; 
   case 3:
    currentDigit = 4;
    statusDigit1 = false;
    statusDigit2 = false;
    statusDigit3 = false;
    statusDigit4 = true;
    digToDecode = valueDigit4;
   break;
   case 4:
    currentDigit = 1;
    statusDigit1 = true;
    statusDigit2 = false;
    statusDigit3 = false;
    statusDigit4 = false;
    digToDecode = valueDigit1;
   break;
    }
    if(currentDigit == DP_pos){
      dp_on = true;
    }else{
      dp_on = false;
    }
    decodedOutput = decodeSegments(digToDecode);      
  
  digitalWrite(DIGIT1, statusDigit1);
  digitalWrite(DIGIT2, statusDigit2);
  digitalWrite(DIGIT3, statusDigit3);
  digitalWrite(DIGIT4, statusDigit4);
  digitalWrite(SEG_A, (decodedOutput>>0)&1);
  digitalWrite(SEG_B, (decodedOutput>>1)&1);
  digitalWrite(SEG_C, (decodedOutput>>2)&1);
  digitalWrite(SEG_D, (decodedOutput>>3)&1);
  digitalWrite(SEG_E, (decodedOutput>>4)&1);
  digitalWrite(SEG_F, (decodedOutput>>5)&1);
  digitalWrite(SEG_G, (decodedOutput>>6)&1);
  digitalWrite(DECIMAL_POINT, !dp_on); //low asserted
    
  }  
  
}

char decodeSegments(int digitIn){

char decodedSegments;

  switch(digitIn){
   
   case 0:
     decodedSegments = ZERO; 
	 break;
   case 1:
     decodedSegments = ONE; 
	 break;
   case 2: 
     decodedSegments = TWO; 
	 break;
   case 3:
     decodedSegments = THREE; 
	 break;
   case 4:
     decodedSegments = FOUR; 
	 break;
   case 5:
     decodedSegments = FIVE; 
	 break;
   case 6:
     decodedSegments = SIX; 
	 break;
   case 7:
     decodedSegments = SEVEN; 
	 break;
   case 8:
     decodedSegments = EIGHT; 
	 break;
   case 9:
     decodedSegments = NINE; 
	 break;
   case 10:
     decodedSegments = TEN; 
	 break;
   case 11:
     decodedSegments = ELEVEN; 
	 break;
   case 12:
     decodedSegments = TWELVE; 
	 break;
   case 13:
     decodedSegments = THIRTEEN;
	 break;
   case 14:
     decodedSegments = FOURTEEN; 
	 break;
   case 15:
     decodedSegments = FIFTEEN;
	 break;
   case 16:
     decodedSegments = SIXTEEN;
	 break;
   case 17:
     decodedSegments = SEVENTEEN;
         break;
   case 18:
     decodedSegments = EIGHTEEN;
         break;
   case 19:
     decodedSegments = NINETEEN;
         break;
   case 20:
     decodedSegments = TWENTY;
         break;    
   case 21:
     decodedSegments = TWENTYONE; 
	 break;
   default:
     decodedSegments = TWENTYTWO;
  }
  
  return decodedSegments;
}
