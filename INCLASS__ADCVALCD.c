#include <INCLASS__ADCVALCD.h>
#define RS PIN_C0
#define RW PIN_C1
#define E  PIN_C2

unsigned int16 vin,v;
unsigned int16 dout;
float ss = 4.887;//(mV)
void lcd_command(unsigned int8 cm)
{
   output_low(RW); 
   output_low(RS);
   output_d(cm);
   output_low(E);
   output_high(E);
   delay_ms(1);
}
void lcd_data(unsigned int8 dt)
{
   output_low(RW); 
   output_high(RS);
   output_d(dt);
   output_low(E);
   output_high(E);
   delay_ms(1);
}
void lcd_setup()
{
   delay_ms(5);
   lcd_command(0x38);
   delay_ms(5);
   lcd_command(0x0c);
   lcd_command(0x06);
   lcd_command(0x01);
   delay_ms(2);
}
void main()
{
   set_tris_d(0x00);
   set_tris_c(0x00);
   set_tris_a(0xff);
   lcd_setup();
   setup_adc_ports(sAN0);
   setup_adc(ADC_CLOCK_DIV_2);

   while(TRUE)
   {
      set_adc_channel(0);
      dout = read_adc();
      vin = dout*ss;
      v = 10*vin;
      lcd_command(0xc6);
      lcd_data(v/10000 + 0x30);
      lcd_data(v%10000/1000 + 0x30);
      lcd_data(v%10000%1000/100 + 0x30);
      lcd_data(v%10000%1000%100/10 + 0x30);
      lcd_data(v%10000%1000%100%10 + 0x30);
      lcd_data("
lcd_data("Mv");
   }

}
