#include <BAITAP6_TRANHOANGBAOPHUONG.h>
#define led PIN_D7
#define bt PIN_B0
#bit TMR1IF=0x0c.0
unsigned int8 i=0, dl = 1;
void main()
{
   set_tris_d(0x00);
   set_tris_b(0xff);
   setup_timer_1(T1_INTERNAL| T1_DIV_BY_8);
   output_low(led);
   set_timer1(3036);
   while(TRUE)
   {
      if(input (bt) == 0)
      {
         dl++;
         if(dl == 11)
         {
            dl = 1;
            i = 0;
         }
      }
       if (TMR1IF == 1)
     {
         //output_toggle(led);
         TMR1IF = 0;
         set_timer1(3036);
         i++;
     }
     if (i==dl)
     {
         i=0;
         output_toggle(led);
     }  
   }

}
