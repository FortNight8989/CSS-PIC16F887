#include <BAITAPLEDCHOPTAT_DONGIAN.h>

void main()
{
   set_tris_c (0x00); //port c la output
   while(TRUE)
   {
      output_toggle (pin_c0);
      delay_ms (5000);
   }

}
