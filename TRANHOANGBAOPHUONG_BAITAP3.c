#include <TRANHOANGBAOPHUONG_BAITAP3.h>
#define led    PIN_B0
#define start  PIN_D1
#define SET    PIN_D0
void main()
{
   set_tris_d(0xFF);    //All PINS of PORTD as Input
   set_tris_b(0x00);    //All PINS of PORTB as Output
   set_tris_c(0x00);    //All PINS of PORTC as Output
   
   output_b(0x00);      // Xuat gia tri ra PORTB 0000.0000
   output_c(0x00);      // Xuat gia tri ra PORTC 0000.0000
   int count = 0;       // bien dem
   
   while(TRUE)
   {
      if (input_state(SET) == 0)       //Doc gia tri SET
      {
         delay_ms(10);                 //Chong doi nut nhan SET
         if (input_state(SET) == 1)
         {
            count++;
            output_c(count);           //Xuat ra gia tri nhi phan vao PORTC
         }
      }
      
      if (input_state(start) == 0)     //Doc gia tri SET
      {
         delay_ms(10);                 //Chong doi nut nhan start
         if (input_state(start) == 1)
         {
            for (int i = 0; i < count; i++)
            {
               output_high(led);
               delay_ms(500);
               output_low(led);
               output_c(count-i-1);    //Giam gia tri count moi lan chop tat LED
               delay_ms(500);
            }
            count = 0;
         }
      }
   }
}
