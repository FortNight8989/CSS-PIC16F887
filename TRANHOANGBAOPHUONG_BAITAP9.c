#include <TRANHOANGBAOPHUONG_BAITAP9.h>
#define RS PIN_C0
#define RW PIN_C1
#define E  PIN_C2
#define led PIN_C5
unsigned int16 d_out, v_in, nhietdo, value;
float ss = 4.887;  //4.887mV
void lcd_command (unsigned int8 cm)
{
   output_low(RS);
   output_low(RW);
   output_d(cm);
   output_low(E);
   output_high(E);
   delay_ms(1);
}
void lcd_data (unsigned int8 dt)
{
   output_low(RS);
   output_low(RW);
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
   delay_ms(1);
}
void hienthi_kq (unsigned int kq)
{
   lcd_data(kq/100 + 0x30);
   lcd_data(kq%100/10 + 0x30);
   lcd_data(kq%100%10 + 0x30);
}
void main()
{
   set_tris_a(0xff);
   set_tris_c(0x00);
   set_tris_d(0x00);
   set_tris_e(0x00);
   output_low(led);
   setup_adc_ports(sAN0|sAN1);
   setup_adc(ADC_CLOCK_DIV_2);
   
   while(TRUE)
   {
      set_adc_channel(0);
      d_out = read_adc();
      v_in = d_out*ss;
      nhietdo = v_in/10;
      
      set_adc_channel(1);
      d_out = read_adc();
      value = d_out*100/1023;
  
      lcd_command(0x80);
      lcd_data("Nhiet Do: ");
      hienthi_kq(value);
      lcd_data(0xdf);
      lcd_data("C");
      
      lcd_command(0xc0);
      lcd_data("Nhiet Do: ");
      hienthi_kq(value);
      lcd_data(0xdf);
      lcd_data("C");
      
      if(nhietdo > value)
      {
         output_high(led);
      }
      else
      {
         output_low(led);
      }
   }
}
