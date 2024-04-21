#include <VXL_PROJECT.h>

#define LCD_ENABLE_PIN  PIN_D2                                   
#define LCD_RS_PIN      PIN_D0                                    
#define LCD_RW_PIN      PIN_D1                                    
#define LCD_DATA4       PIN_D4                                    
#define LCD_DATA5       PIN_D5                                  
#define LCD_DATA6       PIN_D6                                    
#define LCD_DATA7       PIN_D7
#include <lcd.c>

int16 capdo=0;
unsigned int16 nd;
unsigned int16 dout;

void hienthind()
{
      set_adc_channel(0); //Chon kenh can chuyen doi ADC
      delay_us(10);
      dout = read_adc();  //doc ket qua sau khi chuyen doi
      nd = dout*4.887/10; //tinh gia tri nhiet do tu ket qua ADC
      delay_ms(1);
      
      //ghi ghi tri nhiet do len LCD
      if(nd < 100)
      {      
      lcd_gotoxy(2,1);
      lcd_putc("Nhiet do: ");
      lcd_putc(nd%100/10 + 0x30);
      lcd_putc(nd%100%10 + 0x30);
      lcd_putc(0xdf);
      lcd_putc("C");
      }
      else
      {
      lcd_gotoxy(2,1);
      lcd_putc("Nhiet do:");
      lcd_putc(nd/100 + 0x30);
      lcd_putc(nd%100/10 + 0x30);
      lcd_putc(nd%100%10 + 0x30);
      lcd_putc(0xdf);
      lcd_putc("C");
      }
}

void hienthi_capdo()
{     
      if(nd<=35)
      {
        capdo=0;
      }
      else if(nd<=45)
      {
        capdo =1;
      }
      else if(nd<=55)
      {
        capdo=2;
      }
      else
      {
        capdo=3;
      }
       set_pwm1_duty(capdo*1000/3); // thiet lap he so chu ky
      //ghi cap toc do len LCD 
      lcd_gotoxy(5,2);
      lcd_putc("Cap do ");
      lcd_putc(capdo + 0x30);
}

void main()
{
   set_tris_d(0x00);
   set_tris_a(0x5f);
   set_tris_c(0x00);
   lcd_init();
   setup_adc(ADC_CLOCK_DIV_2);       //dinh cau hinh ADC
   setup_adc_ports(SAN0);            //thiet lap chan ADC
   setup_timer_2(T2_DIV_BY_16,249,1); //cau hinh cho timer 2
   setup_ccp1(ccp_pwm);               // khoi tao chuc nang pwm khoi ccp1

   output_high(pin_c2);    // c2 muc cao
   output_low(pin_c3);     // c3 muc cao
   
   lcd_gotoxy(6,1);          //thiet lap vi tri con tro
   lcd_putc("NHOM 14");
   lcd_gotoxy(4,2);          
   lcd_putc("VXL - 05CLC");
   delay_ms(2000);
   lcd_putc("\f");          // xoa man hinh LCD
   while(TRUE)
   { 
       hienthind();
       hienthi_capdo();
   }

}
