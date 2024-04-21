#include <INCLASS_BAITAPLED7DOAN_NUTNHAN.h>
#define button PIN_B0
unsigned int8 ma7doan[10]={0XC0,0XF9,0xA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
//int1 i = 0;
//int1 status = 0;
//void kiemTraNutNhan ()
//{
 //  if(!input(button))
  // {
  //       delay_ms(10);
    //     if(input (button))
     //    {
      //      status = ~status;
     //       //output_bit(pin_C0);
     //    }
  // }
//}

//void delay_nn()
//{
   //for ( int j = 0; j < 200; j++)
   //{
   //   kiemTraNutNhan();
   //   delay_ms (1);
   //}
//}

void main()
{
  // set_tris_d (0x00);
   //set_tris_b (0xff);
   ///set_tris_c (0x1f);
   set_tris_c (0x00);
   set_tris_d (0x00);
   while(TRUE)
   {
      output_c(ma7doan[0]);
      output_d(0xf7);
      delay_ms(500);
      output_d(0xff);
      output_c(ma7doan[1]);
      output_d(0xfb);
      delay_ms(500);
      output_d(0xff);
       output_c(ma7doan[2]);
      output_d(0xfb);
      delay_ms(500);
      output_d(0xfd);
       output_c(ma7doan[3]);
      output_d(0xfb);
      delay_ms(500);
      output_d(0xfe);
      }
    }
      
    //  kiemTraNutNhan();
    //  if(status == 1)
    //  {
         //      if(i < 10)
      //      {
        //       output_d(ma7doan[i]);
        //       delay_nn();
        //       i++;
              
         //    }
         //      else
          //  {
           ///    i = 0;
          //  }
      //}
      //else
    //  {
        //    output_d(ma7doan[i]);
      //}
  // }

//}
