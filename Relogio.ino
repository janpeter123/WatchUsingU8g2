#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

//Set the Hour Ten
int Dh = 2;
//Set the Hour Unit
int Uh = 2;
//Set the Minute Ten
int Dm = 5;
//Set the Minute Unit
int Um = 4;

//Defining Variables To convert to string and then transfer to the display.
//Converting Variables into string
String Dhora;
String Uhora;
String Dminuto;
String Uminuto;
//hour with the ten and with the unit.
String Hora;
//minute with the ten and with the unit.
String Minuto;

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 

 void setup(void) {
   u8g2.begin();
}

  void loop(void) {
  if(Dm==5 && Um>9){
   Dm=0;
      Um=0;
      Uh++;

      if(Dh<2 && Uh>9 ){
          Dh++;
          Uh=0;
      }
  } 
  else if(Um>9){
    Um=0;
    Dm++;
  }
   if(Dh==2 && Uh==4){
          Dh=0;
          Uh=0;
    }

   u8g2.clearBuffer();// clear the internal memory
   u8g2.setFont(u8g2_font_logisoso28_tr);  // font
    Dhora = String(Dh);
    Uhora = String(Uh);
    Hora = Dhora+Uhora;
    Dminuto = String(Dm);
    Uminuto = String(Um);
    Minuto = Dminuto+Uminuto;
   u8g2.drawStr(10,29, Hora.c_str());  // write something to the internal memory
   u8g2.drawStr(50,29, ":");
   u8g2.drawStr(60,29, Minuto.c_str());
   u8g2.sendBuffer();         // transfer internal memory to the display
   delay(60000);
   Um++;
}
