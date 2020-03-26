#include <HardwareSerial.h>

//--------------------------------------------------------------------------------------------------

void setup()
{
    Serial.begin(230400);
    while(!Serial)
        delay(10);
}

//--------------------------------------------------------------------------------------------------

void loop()
{ 
    if(serial_buffer.process())
    {
        while(serial_buffer.hasLine())
        {
            String line{ serial_buffer.getLine() };
            Serial.printf("buffered line read: %s\n", line.c_str());
        }
    }
}
