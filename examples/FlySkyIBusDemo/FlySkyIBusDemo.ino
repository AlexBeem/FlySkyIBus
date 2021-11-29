
/*
 * Test FlySky IBus interface:
 * on an Arduino Mega
 * RX0 - 0   TX0 - 1
 * RXD1 - 19   TXD1 - 18
 * RXD2 - 17   TXD2 - 16
 * RXD3 - 15   TXD3 - 14
 *
 * on an Arduino 328PB
 * RXD0 - PD0   TXD0 - PD1
 *        (D0)         (D1)
 *  ----------------------     
 * RXD1 - PB4   TXD1 - PB3
 *       (D12)        (D11) 
 * -----------------------
 *  Connect FS-iA6B receiver to Serial1.
 *  PWM1 = CH1 & etc.
 *  CH1 - 0   CH2 - 1   CH3 - 2    CH4 -3
 *  CH5 - 4   CH6 - 5   CH7 - 6    CH8 -7
 *  CH9 - 8   CH10 - 9  CH11 - 10  CH12 -11
 *  CH13 - 12 CH114 - 13
 */
 
#include "FlySkyIBus.h"
 
void setup()
{
  Serial.begin(115200);
  IBus.begin(Serial1);
}
 
void loop()
{
  IBus.loop();
  Serial.println(IBus.readChannel(0), HEX);
}
