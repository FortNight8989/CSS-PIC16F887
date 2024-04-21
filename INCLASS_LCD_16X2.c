#include <INCLASS_LCD_16X2.h>

#define RS PIN_E0
#define RW PIN_E1
#define E  PIN_E2

void lcd_command(unsigned int8 cm)
{
      output_low  (RW);
      output_high (RS);
      output_d    (cm);
      output_low  (e);
      output_high (e);
      delay_ms(1);
}

void lcd_data (unsigned int8 dt)
{
      output_low  (RW);
      output_high (RS);
      output_d    (dt);
      output_low  (e);
      output_high (e);
      delay_ms(1);
}

void lcd_setup ()
{
      delay_ms(5);
      lcd_command (0x38);
      delay_ms(5);
      lcd_command (0x0C);
      lcd_command (0x06);
      lcd_command (0x01);
      delay_ms(2);
}
void main()
{
      
      set_tris_d (0x00);
      set_tris_c (0x00);
      set_tris_b (0xff);
      lcd_setup ();
      lcd_command (0x83);  //Dong 1
      lcd_data ("HOC VI XU LI KHO QUA");
   while(TRUE)
   {
     for (unsigned int8 i = 0; i < 21; i++)
     {
         lcd_command (0xC8); 
         lcd_data (i/10 + 0x30);
         lcd_data (i%10 + 0x30);
         delay_ms (500);
     }
   }

}
