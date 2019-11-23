#include <LiquidCrystal.h>
#include "Automata1.h"
//Constantes y tipos
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
const int boton1 = 8, boton2 = 9, boton3 = 10;
int boton_presionado;
bool bandera_presionado = 0, bandera_inicio = 0, botoni_presionado = 0;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Variables
long last_boton1,last_boton2,last_boton3;
//0 para introducir orden de *, 1 para transicion de * ,2 para orden de |, 3 para transicion de| , 4 para cinta , 5 para ejecucion y 6 para parado.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.cursor();
  pinMode(boton1,INPUT);
  pinMode(boton2,INPUT);
  pinMode(boton3,INPUT);
}


//==================================Botones===============
void boton1_presionado(){
  boton_presionado = 1;

}//boton1

void boton2_presionado(){
  boton_presionado = 2;

}//boton2

void boton3_presionado(){
  boton_presionado = 3;

}//boton3


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void borrarPantalla(){
  if(bandera_presionado == 1){
      lcd.clear();
      bandera_presionado = 0;
    }
}

void menu(){

  if(bandera_inicio == 1){
    lcd.setCursor(0,0);
    lcd.print("Maquina turing");
    lcd.setCursor(0,1);
    lcd.print("presiona 1 2 3");
  }//if

  switch (boton_presionado)
  {
  case 1:
    borrarPantalla();
    lcd.setCursor(0, 0);
    Automata1();//<---funcion automata1
    break;

  case 2:
    borrarPantalla();
    lcd.setCursor(0,0);
    lcd.print("se la"); 
    break;

  case 3:
    borrarPantalla();
    lcd.setCursor(0,0);
    lcd.print("Come");
    break;

  }//switch

}
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
//  Serial.println(fase);
 // Serial.println(configuracion.escrutado);
// Serial.println((millis() - last_boton1)/1000);
  if(botoni_presionado == 0){
    bandera_inicio = 1;
  }//if
  delay(10);
  menu();
  
  if (digitalRead(boton1)==HIGH){
    botoni_presionado = 1;
    bandera_presionado = 1;
    bandera_inicio = 0;
    boton1_presionado();
  }
  if (digitalRead(boton2)==HIGH){
    botoni_presionado = 1;
    bandera_presionado = 1;
    bandera_inicio = 0;
    boton2_presionado();
  }
  if (digitalRead(boton3)==HIGH){
    botoni_presionado = 1;
    bandera_presionado = 1;
    bandera_inicio = 0;
    boton3_presionado();
  }

  }
