#include <LiquidCrystal.h>
//Constantes y tipos
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
const int boton1=8,boton2=9,boton3=10;
const int ledPin =  13;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Variables
long last_boton1,last_boton2,last_boton3;
//0 para introducir orden de *, 1 para transicion de * ,2 para orden de |, 3 para transicion de| , 4 para cinta , 5 para ejecucion y 6 para parado.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.cursor();
  pinMode(ledPin, OUTPUT); 
  pinMode(8,INPUT);
  pinMode(boton2,INPUT);
  pinMode(boton3,INPUT);
  reiniciar(true);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void dibujar(){

 lcd.print("Hola");
 lcd.print("mundo"); 
 lcd.print("N se la come");

}
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
//  Serial.println(fase);
 // Serial.println(configuracion.escrutado);
// Serial.println((millis() - last_boton1)/1000);
  
  delay(10);
  dibujar();
  /*
  if (digitalRead(boton1)==HIGH){
  boton1_pressed();
  }
  if (digitalRead(boton2)==HIGH){
  boton2_pressed();
  }
  if (digitalRead(boton3)==HIGH){
  boton3_pressed();
  }
   if (digitalRead(boton3)==HIGH){
  boton3_pressed();
  */
  }

  



  
}











