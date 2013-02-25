#include <WProgram.h>

#define DIGIT1 10
#define DIGIT2 11
#define DIGIT3 15
#define DIGIT4 17
#define COLON_ANODE 13
#define COLON_CATHODE 42
#define APOSTROPHE_ANODE 44
#define APOSTROPHE_CATHODE 45
#define SEG_A 40
#define SEG_B 38
#define SEG_C 41
#define SEG_D 12
#define SEG_E 14
#define SEG_F 43
#define SEG_G 39
#define DECIMAL_POINT 16

// segments encoding, LSB is A (gfedcba)
#define ZERO 0x40
#define ONE 0x79
#define TWO 0x24
#define THREE 0x30
#define FOUR 0x19
#define FIVE 0x12
#define SIX 0x02
#define SEVEN 0x78
#define EIGHT 0x00
#define NINE 0x10
#define TEN 0x08  //A
#define ELEVEN 0x03  //B
#define TWELVE 0x46  //C
#define THIRTEEN 0x21  //D
#define FOURTEEN 0x06  //E
#define FIFTEEN 0x0e  //F
//Some extra characters
#define SIXTEEN 0x09  //H
#define SEVENTEEN 0x71 //J
#define EIGHTEEN 0x47  //L
#define NINETEEN 0X07  //T
#define TWENTY 0X63  //U
#define TWENTYONE 0X0C  //P
#define TWENTYTWO 0X23  //o

void sevSeg_update(short digit1, short digit2, short digit3, short digit4, short DP_pos);
void sevSeg_update(unsigned long toDisp, short DP_posIn);
void sevSeg_refresh();
void sevSeg_pinSetup();
char decodeSegments(int digitIn);
