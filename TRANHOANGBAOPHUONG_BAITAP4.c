#include <TRANHOANGBAOPHUONG_BAITAP4.h>
#define button PIN_B0
unsigned int8 dem = 0;
int8 st ;
signed int8 Ma7Doan[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
//so dem tu 0-9
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
      delay_ms(10);                 //Chong doi nut nhan
   }
   if (input_state (button) == 0)   //KIEM TRA NUT NHAN DA TAT HOAN TOAN
   {
      st++;
   if (st == 3)                     //NEU NHAN ST = 3 LAN THI CHO ST = 1
   {
      st = 1;
   }
 }
}
void delay_time( int num )
{
   int gt = num/4;                  //gt la thoi gian chuong trinh chay
   for ( int i = 0; i < gt; i++)
   {
      HienThiLed();                 //LIEN TUC GOI HAM CON HIENTHILED
      KiemTra_nn();                 //LIEN TUC GOI HAM CON KIEMTRANN
   }
}

void DemLen ()
{
   dem++;
   if ( dem >= 100)
   {
      dem = 99;
   }
   delay_time(500);
}

void DemXuong()
{
   dem--;
   if ( dem<=0 )
   {
      dem = 0;
   }
   delay_time(500);
}
void main()
{
   set_tris_c(0x00);       //PORT C la chan xuat du lieu
   set_tris_d(0x00);       //PORT D la chan xuat du lieu
   set_tris_b(0xff);       //PORT B la chan NHAN du lieu
   while (TRUE)
   {
      KiemTra_nn();        //LIEN TUC KIEM TRA NUT NHAN
      HienThiLed();        //GOI HAM CON HIEN THI LED
      if (st == 1)
      {
         DemLen();         //GOI HAM CON DEM LEN
      }
      else if (st == 2)    //ST CHI CO 2 TRANG THAI
    {      
         DemXuong();       //GOI HAM CON DEM XUONG
   }   
  }
}




