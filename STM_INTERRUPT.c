// the pin where the input button is attached. Change, if needed
#define BUTTON  PA2

// volatile is important, because this variable is modified in IRQ routine
volatile uint8_t flag = 0;


void PBB(void)
{delay(50);
    flag = 1 - flag;
    Serial_println_i(flag);
}


void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, 1);   // turn off the LED
Serial_begin(9600);
    pinMode(2,INPUT);

  GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_IN_FL_IT);
  disableInterrupts();
  EXTI_SetExtIntSensitivity( EXTI_PORT_GPIOB, FALLING);  
  enableInterrupts();

  attachInterrupt(INT_PORTB & 0xff,PBB,0);
}


void loop()
{
    if (flag) {
        digitalWrite(LED_BUILTIN, 0);
        delay(300);
        digitalWrite(LED_BUILTIN, 1);
       
    }
    delay(2000);
}
