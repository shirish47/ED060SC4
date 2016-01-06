#include "EPD.h"
#define vHIGH true
#define vLOW false
/*hardware Setup 3.3 volt given directly no switching on off 
-1.5(VCOM) volt given directly no on/off 
22v, -20,15,-15 are controllable.*/

void setup() {
  // put your setup code here, to run once:
if(gdisp_lld_init())
 {}
 power_on();
//writing some thing to pixel just for testing.
 for(int i=0;i<20;i++)
 for(int j=0;j<20;j++)
 {
   if(j>10)
   gdisp_lld_draw_pixel(i,j,false);
   else
   gdisp_lld_draw_pixel(i,j,true);
 }
 //flushing to display
 flush_buffers();
//power_off();
}

void loop() {  
}

