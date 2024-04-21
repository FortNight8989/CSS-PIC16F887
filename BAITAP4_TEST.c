#include <BAITAP4_TEST.h>
#define button PIN_B0
unsigned int8 dem = 0;
int8 st ;
signed int8 Ma7Doan[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void HienThiLed()
{
   output_c(Ma7Doan[dem%10]);
   output_d(0xf7);
   delay_ms(1);
   output_d(0xff);
   output_c(Ma7Doan[dem/10]);
   output_d(0xfb);
   delay_ms(1);
   output_d(0xff);
}
void KiemTra_nn()
{
   if (input_state (button) == 0)
   {
      delay_ms(10);           //Chong doi nut nhan
   }
   if (input_state (button) == 0)
   {
      st++;
   if (st == 3)
   {
      st = 1;
   }
 }
}
void delay_time( int dl)
{
   int tam = dl/2;
   for ( int i = 0; i < tam; i++)
   {
      HienThiLed();
      KiemTra_nn();
   }
}

void DemLen ()
{
   dem++;
   if ( dem == 100)
   {
      dem = 99;
   }
   delay_time(2000);
}

void DemXuong()
{
   dem--;
   if (dem<0)
   {
      dem = 0;
   }
   delay_time(2000);
}
void main()
{
   set_tris_c(0x00);
   set_tris_d(0x00);
   set_tris_b(0xff);
   while (TRUE)
   {
      KiemTra_nn();
      HienThiLed();
      if (st == 1)
      {
         DemLen();   
      }
      else if (st == 2)
    {      
         DemXuong();
   }   
  }
}
