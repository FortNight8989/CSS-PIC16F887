#include <BAITAPLEDCHOPTAT.h>
#define  led PIN_C0
#define  bt PIN_C5
void main()
{
      set_tris_c(0x20); 
      output_low(led);
     while(true)
   {
         if(input(bt) == 0)
      {
         delay_ms(10);
         if(input(bt) == 1)
         {
         output_toggle(led);
         }
      
      }
   }
 }

