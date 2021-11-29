// Скетч для AVR имеющих более одно UART порта

#include "FlySkyIBus.h"             // IBus library
int ch = 14;                        // число каналов радиоаппаратуры RC

void setup()
{
  Serial.begin(115200); // hardserial for debigging
  IBus.begin(Serial1);  // start the IBus object
}

void loop()
{
  static int16_t inibus;
  IBus.loop();
  for (int i = 0; i < ch; i++)
  {
    inibus = IBus.readChannel(i);
    if (i < ch - 1)
    {
      Serial.print(inibus);
      Serial.print("\t");
    } else {
      Serial.println(inibus);
    }
  }
}
