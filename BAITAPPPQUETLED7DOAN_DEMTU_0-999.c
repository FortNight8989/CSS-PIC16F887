#include <BAITAPPPQUETLED7DOAN_DEMTU_0-999.h>
#define BUTTON input (PIN_A0)
#define start (PIN_B0)

//=====================CHUONG TRINH CHINH====================
unsigned int8 Ma7Doan[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
int dem;
void nn_start()
{
   if (!input(start))
   {
      delay_ms (100);
      if (!input(start))
      {
         for (int j = 0; j < 99  ; j++)
         {
            while (input (start) == 0) 
            {
               output
            }
         }
      }
   }
}
void hienthi()
{
      output_c(Ma7Doan[((dem%1000)%100)%10]);
      output_d(0xf7);
      delay_ms(1);
      output_d(0xff);
      output_c(Ma7Doan[((dem%1000)%100)/10]);
      output_d(0xfb);
      delay_ms(1);
      output_d(0xff);
      output_c(Ma7Doan[(dem%1000)/100]);
      output_d(0xfd);
      delay_ms(1);
      output_d(0xff);
      output_c(Ma7Doan[(dem/1000)]);
      output_d(0xfe);
      delay_ms(1);
      output_d(0xff);
}

void delay_ht_ms (int dl)
{
   int tam = dl/4;
   for (int i = 0; i < tam; i++)
   {
      hienthi();
   }
}
void main()
{
   set_tris_c (0x00);
   set_tris_d (0x00);
   set_tris_b (0xff);
   while(TRUE)
   {
      for ( dem = 0; dem < 1000; dem++)
      {
            hienthi();
            delay_ht_ms(200);
            
      }
      
   }

}

