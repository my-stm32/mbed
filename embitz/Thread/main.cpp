#include "mbed.h"
#include "rtos.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

Serial pc(PC_6,PC_7);
uint16_t ledvalue=0;
uint16_t ledvalue2=0;
Ticker tick;
void setLed(uint8_t  val)
{
   // led1=val % 2;

    led2=(val /2 ) % 2;

    led3=(val /4 ) % 2;

    led4=(val /5 ) % 2;
}

void printstr(void const *args)
{
    while (true) {
        pc.printf("Hello World,Now value is %d.\n",ledvalue);
        // pc.printf("Hello World,Now value is %d.\n",*(uint8_t *)args);
        Thread::wait(1000);
    }
}

void led(void const *args)
{
    while (true) {
        led1=!led1;
        Thread::wait(100);
    }
}

int main()
{
    //Thread thread(printstr);
  Thread thread(printstr,&ledvalue);
  Thread thread2(led,&ledvalue2);
    while (1)
    {
        setLed(++ledvalue);
        Thread::wait(100);
    }
}
