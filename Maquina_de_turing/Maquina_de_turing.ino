#include <LiquidCrystal.h>
#include "Automata1.h"
//Constantes y tipos
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
const int boton1 = 8, boton2 = 9, boton3 = 10;
int boton_presionado, Arreglop_boton1 = 0, estado_boton1, estado_boton2, estado_boton3, fuePresionado = 0,fuePresionado2 = 0 , fuePresionado3 = 0, posCursor = 0, boton2pres = 0, car_final;
bool bandera_presionado = 0, bandera_inicio = 0, botoni_presionado = 0;
char Arreglo_boton1[3] = {'a', 'b' , 'c'}, ArregloCadena[16];


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



void Automata1F(){
  lcd.print("hola desde funcion");
}//funcion del automata


//====================================================AUTOMATAS==================================================
void Automata1(){
    int bandera = 0;
    //==========menu de botones en automata 1=======================
    while(bandera == 0){
     
            //=======================CONTROLADOR BOTON 1======================
            lcd.setCursor(posCursor,0);
            Serial.print(posCursor);
        
            if(fuePresionado){
              if(digitalRead(boton1) == LOW){
                fuePresionado = 0;
              }//si fue despresionado
            }//si fue presionado
            else{
              if (digitalRead(boton1) == HIGH){
                fuePresionado = 1;
                lcd.print(Arreglo_boton1[Arreglop_boton1]);
                car_final =  Arreglop_boton1;
                Serial.print("bton 1 presionado");
    
                Arreglop_boton1 +=1;
                if(Arreglop_boton1 >= 3){
                  Arreglop_boton1 = 0;
                }//si es mayor que 3
              }//if
            }//else   
            
            //==========================CONTROLADOR BOTON 2===========================
         if(fuePresionado2){
              if(digitalRead(boton2) == LOW){
                fuePresionado2 = 0;
              }//si fue despresionado
            }//si fue presionado
            else{
              if (digitalRead(boton2) == HIGH){
                fuePresionado2 = 1;
                ArregloCadena[posCursor] = Arreglo_boton1[car_final];
          Serial.print("bton 2 presionado!!!");
          Serial.print(ArregloCadena[posCursor]);
          posCursor = posCursor + 1;
              }//is
            }//else
            
           
           //==========================CONTROLADOR  BOTON 3======================
            if(fuePresionado3){
              if(digitalRead(boton3) == LOW){
                fuePresionado3 = 0;
              }//si fue despresionado
            }//si fue presionado
            else{
              if (digitalRead(boton3) == HIGH){
                fuePresionado3 = 1;
                Serial.print("BOTON 3===========================");
                Serial.print(Arreglop_boton1);
                ArregloCadena[posCursor] = Arreglo_boton1[car_final];
                bandera = 1;
                Automata1F();
              }//is
            }//else
            
            
            
    }//while button 3
      Serial.print("me sali del boton 3");
    //ArregloCadena[posCursor] = Arreglo_boton1[Arreglop_boton1 -1];

}//automata1

























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
    //lcd.print("Come");
    lcd.print(ArregloCadena[0]);
    lcd.setCursor(1,0);
    lcd.print(ArregloCadena[1]);
    lcd.setCursor(2,0);
    lcd.print(ArregloCadena[2]);
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
