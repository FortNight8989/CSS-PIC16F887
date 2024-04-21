#include <TIMER_LCD_VIDEO.h>
#fuses  hs
#use delay (clock = 20M)
#define RS   PIN_C0
#define RW   PIN_C1
#define E    PIN_C2

//unsigned int8 ma7doan[10]={0XC0,0XF9,0xA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};

void lcd_command(unsigned int8 cm)
{
     output_low (RW);
     output_low (RS);
     output_d(cm);
     output_low (E);
     output_high(E);
     delay_ms(1);
}

void lcd_data(unsigned int8 dt)
{
      output_low (RW);
      output_high (RS);
      output_d (dt);
      output_low (E);
      output_high (E);
      delay_ms (1);
}

void lcd_setup ()
{
      delay_ms(5);
      lcd_command (0x38);
      delay_ms(5);
      lcd_command (0x0c);
      lcd_command(0x06);
      lcd_command(0x01);
      delay_ms(2);
 }


void main()
{
   set_tris_a(0X01);
   set_tris_b(0);
   set_tris_c(0x00);
   //set_tris_d(0xff);
   set_tris_e(0xff);
   output_d(0);
   
   lcd_setup();
   lcd_command (0x80);
   lcd_data(" PHUONG 19146244");
   lcd_command (0xC0);
   lcd_data("DONG HO ");
   
   
   while(TRUE)
   {
      //TODO: User Code
   }
}
