#include <DK_DONGCO_QUAYTHUAN.h>
#define ena PIN_C0
#define START PIN_D0
#define STOP PIN_D1
#define in1 PIN_D2
#define in2 PIN_D3
int16 capdo = 0, value = 0;

void quaythuan()
{
   output_high(ena);
   output_low(in2);
   if (value <= 1000)
   {
      set_pwm1_duty()
    }
}
void ktnn()
{
   if (input(START)==0)
   {
      delay_ms(10);
      if (input(START)==1)
      {
        quaythuan();
    }
  }
  if (input(ena) == 0)
  {
      delay_ms(10);
      if(input (ena)== 1)
      {
            quaynghich();
      }
  }
}
void main()
{
   set_tris_b (0x00);
   setup_timer_2(T2_DIV_BY_16,249,1);
   setup_CCP1(CCP_PWM);
   while(TRUE)
   {
      ktnn();
   }
}
