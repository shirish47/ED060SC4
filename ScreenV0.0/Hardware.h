/*
 * 2013 Petteri Aimonen <jpa@gfx.mail.kapsi.fi>
 * This file is released to the public domain.
 * 
 */

/* Board interface definitions for ED060SC4 PrimeView E-ink panel.
 *
 * This file corresponds to the connections shown in example_schematics.png,
 * and is designed to interface with ChibiOS/RT.
 * 
 * Please note that this file has never been tested in exactly this pin
 * configuration, because the actual boards I have are slightly different.
 */

#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include "Arduino.h"


/*
 * IO pins assignments.
 */
#define EINK_D0       2  //controller port PTB16 change to PTD0(2)
#define EINK_D1       14  //controller port PTB17 change to PTD1(14) 
#define EINK_D2       7 //controller port PTD0  change to PTD2(7)
#define EINK_D3       8  //controller port PTA12 change to PTD3(8)
#define EINK_D4       6  //controller port PTA13 change to PTD4(6)
#define EINK_D5       20  //controller port PTD7  change to PTD5(20)
#define EINK_D6       21 //controller port PTD4  change to PTD6(21)
#define EINK_D7       5  //controller port PTD2  change to PTD7(5)

/* Controll Pins */

#define EINK_GMODE    15   //controller port PTD3 change to PTB1(15)
#define EINK_SPV      9
#define EINK_CKV      16  //controller port PTC4 change to PTB0(16)
#define EINK_CL       11 //PTC6
#define EINK_LE       22//** change to PTC1(22)
#define EINK_OE       17
#define EINK_SPH      18

/* Power Pins */
#define VPOS_CTRL    19
#define VNEG_CTRL    23//** change to PTC2(23)



/* Set up IO pins for the panel connection. */
void inline init_board(void) {
    
    /* Power control for the positive & negative side */
    pinMode(VPOS_CTRL,OUTPUT);
    digitalWrite(VPOS_CTRL,LOW);
    pinMode(VNEG_CTRL,OUTPUT);
    digitalWrite(VNEG_CTRL,LOW);
    /* Main data bus */
        pinMode(EINK_D0,OUTPUT);
        pinMode(EINK_D1,OUTPUT);
        pinMode(EINK_D2,OUTPUT);
        pinMode(EINK_D3,OUTPUT);
        pinMode(EINK_D4,OUTPUT);
        pinMode(EINK_D5,OUTPUT);
        pinMode(EINK_D6,OUTPUT);
        pinMode(EINK_D7,OUTPUT);

//    palWritePort(GPIOB, 0);
//    palSetGroupMode(GPIOB, 0xFFFF, 0, PAL_MODE_OUTPUT_PUSHPULL);

  // control Pins
      pinMode(EINK_GMODE,OUTPUT);
      pinMode(EINK_SPV,OUTPUT);
      pinMode(EINK_CKV,OUTPUT);
      pinMode(EINK_CL,OUTPUT);      
      pinMode(EINK_LE,OUTPUT);
      pinMode(EINK_OE,OUTPUT);
      pinMode(EINK_SPH,OUTPUT);
}

/* Delay for display waveforms. Should be an accurate microsecond delay. */
 void inline eink_delay(int us)
{
  delayMicroseconds(us);
}

/* Turn the E-ink panel Vdd supply (+3.3V) on or off. */
// void inline setpower_vdd(bool on) {
  ///  palWritePad(GPIOB, GPIOB_SMPS_CTRL, !on);
  ///  palWritePad(GPIOA, GPIOA_EINK_VDD, on);
//}

/* Turn the E-ink panel negative supplies (-15V, -20V) on or off. */
 void inline setpower_vneg(bool on) {
   if(on)//TRUE:ON
   {digitalWrite(VNEG_CTRL,HIGH);return;}
   else //OFF
   {digitalWrite(VNEG_CTRL,LOW);return;}
}

/* Turn the E-ink panel positive supplies (-15V, -20V) on or off. */
 void inline setpower_vpos(bool on) {
   if(on)//TRUE:ON
   {digitalWrite(VPOS_CTRL,HIGH);return;}
   else //OFF
   {digitalWrite(VPOS_CTRL,LOW);return;}
}

/* Set the state of the LE (source driver Latch Enable) pin. */
 void inline setpin_le(bool on) {
     if(on)//TRUE:ON
   {digitalWrite(EINK_LE,HIGH);return;}
   else //OFF
   {digitalWrite(EINK_LE,LOW);return;}
   //  palWritePad(GPIOB, GPIOB_EINK_LE, on);
}

/* Set the state of the OE (source driver Output Enable) pin. */
 void inline setpin_oe(bool on) {
      if(on)//TRUE:ON
   {digitalWrite(EINK_OE,HIGH);return;}
   else //OFF
   {digitalWrite(EINK_OE,LOW);return;}
    //palWritePad(GPIOB, GPIOB_EINK_OE, on);
}

/* Set the state of the CL (source driver Clock) pin. */
 void inline setpin_cl(bool on) {
      if(on)//TRUE:ON
   {digitalWrite(EINK_CL,HIGH);return;}
   else //OFF
   {digitalWrite(EINK_CL,LOW);return;}
    //palWritePad(GPIOB, GPIOB_EINK_CL, on);
}

/* Set the state of the SPH (source driver Start Pulse Horizontal) pin. */
 void inline setpin_sph(bool on) {
   if(on)//TRUE:ON
   {digitalWrite(EINK_SPH,HIGH);return;}
   else //OFF
   {digitalWrite(EINK_SPH,LOW);return;}
    //palWritePad(GPIOB, GPIOB_EINK_SPH, on);
}

/* Set the state of the D0-D7 (source driver Data) pins. */
 void inline setpins_data(uint8_t value) {
    GPIOD_PDOR=value; ///palWriteGroup(GPIOB, 0xFF, GPIOB_EINK_D0, value);
}

/* Set the state of the CKV (gate driver Clock Vertical) pin. */
 void inline setpin_ckv(bool on) {
   if(on)//TRUE:ON
   {digitalWrite(EINK_CKV,HIGH);return;}
   else //OFF
   {digitalWrite(EINK_CKV,LOW);return;}
   //palWritePad(GPIOB, GPIOB_EINK_CKV, on);
}

/* Set the state of the GMODE (gate driver Gate Mode) pin. */
 void inline setpin_gmode(bool on) {
   if(on)//TRUE:ON
   {digitalWrite(EINK_GMODE,HIGH);return;}
   else //OFF
   {digitalWrite(EINK_GMODE,LOW);return;}

   //palWritePad(GPIOC, GPIOC_EINK_GMODE, on);
}

/* Set the state of the SPV (gate driver Start Pulse Vertical) pin. */
 void inline setpin_spv(bool on) {
   if(on)//TRUE:ON
   {digitalWrite(EINK_SPV,HIGH);return;}
   else //OFF
   {digitalWrite(EINK_SPV,LOW);return;}

  //  palWritePad(GPIOB, GPIOB_EINK_SPV, on);
}

#endif
