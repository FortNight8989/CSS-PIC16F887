#include <TRANHOANGBAOPHUONG_BAITAP5.h>
#define RS   PIN_C0
#define RW   PIN_C1
#define E    PIN_C2
#define MOD  PIN_B0
#define UP   PIN_B1
#define DOWN   PIN_B2

unsigned int8 HH, MM, SS, gt, gio, phut; //bien dem khong dau tu 0-255
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

void hienthi()
{
    lcd_command (0xC8);
    lcd_data (HH/10 + 0X30);
    lcd_data (HH%10 + 0x30);
    lcd_data(":");
    lcd_data (MM/10 + 0X30);
    lcd_data (MM%10 + 0x30);
    lcd_data(":");
    lcd_data (SS/10 + 0X30);
    lcd_data (SS%10 + 0x30);
}
void kt_MOD()
 {
      if (!input(MOD))              //if (input(PIN_B0) == 0)
      {
         delay_ms(10);                 //Chong doi nut nhan
     if (input(MOD) == 1)
      {
         gt++;
      }
         if(gt == 3) gt = 0;
    }
  }

void KIEMTRANUT_UP_HH ()         //KT NUT UP DIEU CHINH GIO
{
   if(input (UP) == 0)
   {
      delay_ms(1);
   }
   if(input (UP) == 0)
   gio++;
   if (gio == 24) gio = 0;
   while (input (UP) == 0);
}

void KIEMTRANUT_DOWN_HH ()     //KT NUT DOWN DIEU CHINH GIO
{
   if(input (DOWN) == 0)
   {
      delay_ms(1);
   }
   if(input (DOWN) == 0)
   {
   gio--;
   if (gio == -1) gio = 23;
   while (input (DOWN) == 0);
   }
}

void KIEMTRANUT_UP_MM ()          //KT NUT UP DIEU CHINH PHUT
{
   if(input (UP) == 0)
   {
      delay_ms(1);
   }
   if(input (UP) == 0)
   {
   phut++;
   if (phut == 61) 
   {phut = 0;
   while (input (UP) == 0);
   }
 }
}

void KIEMTRANUT_DOWN_MM ()        //KT NUT DOWN DIEU CHINH GIO
{
   if(input (DOWN) == 0)
   {
      delay_ms(1);
   }
   if(input (DOWN) == 0)
   {
   phut--;
   if (phut == -1) phut = 60;
   while (input (DOWN) == 0);
   }
}

 void delay_nn_ms(int dl)        //CHUONG TRINH DELAY NN
 {
      for (int i = 0; i < dl; i++)
      {  
         kt_MOD();
         if ( gt == 1)
         {
         KIEMTRANUT_UP_HH ();
         KIEMTRANUT_DOWN_HH ();
         HH = gio;
         hienthi();
         delay_ms(1);
         kt_MOD();
         }
      }
 }
void main()
{
   set_tris_C  (0x00);
   set_tris_D  (0x00);
   set_tris_B  (0xff);
   lcd_setup();
   lcd_command (0x80);
   lcd_data(" PHUONG 19146244");
   lcd_command (0xC0);
   lcd_data("DONG HO ");
   
     while (true)
   {
      for ( unsigned int8 HH = gio; HH < 24; HH++)
      {
         for (unsigned int8 MM = phut; MM < 60; MM++)
         {
            for (unsigned int8 SS = 0; SS < 60; SS++)
            {
               lcd_command (0xC8);
               lcd_data (HH/10 + 0X30);
               lcd_data (HH%10 + 0x30);
               lcd_data(":");
               lcd_data (MM/10 + 0X30);
               lcd_data (MM%10 + 0x30);
               lcd_data(":");
               lcd_data (SS/10 + 0X30);
               lcd_data (SS%10 + 0x30);
               delay_nn_ms (200);
            }
         }
      }
   }
 }


