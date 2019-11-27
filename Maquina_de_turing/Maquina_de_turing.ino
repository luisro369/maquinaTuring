#include <LiquidCrystal.h>
#include "Automata1.h"
//Constantes y tipos
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
const int boton1 = 8, boton2 = 9, boton3 = 10;

int boton_presionado, Arreglop_boton1 = 0, estado_boton1, estado_boton2, estado_boton3, fuePresionado = 0,fuePresionado2 = 0 , fuePresionado3 = 0, posCursor = 0, boton2pres = 0, car_final;
bool bandera_presionado = 0, bandera_inicio = 0, botoni_presionado = 0;
char Arreglo_boton1[3] = {'a', 'b' , 'c'};
//===========variables automata1==============
char mur[10] = {'m', 'u', 'r', 'c', 'i', 'e', 'l', 'a', 'g', 'o'} , ArregloCadena[16] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
char mur2[16];
int pos_rotor, Cursor = 0;
//============variables automata2========================
char ArregloCifrado[16] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
char ArregloDescifrado[16] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
char cif2[3];
int llave = 0;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Variables
long last_boton1,last_boton2,last_boton3;
//0 para introducir orden de *, 1 para transicion de * ,2 para orden de |, 3 para transicion de| , 4 para cinta , 5 para ejecucion y 6 para parado.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void(* resetFunc) (void) = 0;//<---para resetear
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
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


//==============================================Funciones de automatas============================================
//--------------------AUTOMATA1---------------------------------
void Automata1F(){
  
  //----------posicion del rotor
  pos_rotor = random(10);
  lcd.setCursor(0,1);
  lcd.print("key");
  lcd.setCursor(4,1);
  lcd.print(pos_rotor);
  
  for(int i = 0; i < 3; i++){
    mur2[i] = mur[pos_rotor + i];
  }//llenando mur 2
 
  lcd.setCursor(Cursor,0);
  for(int i = 0; i < 16; i++){
    
    switch(ArregloCadena[i]){
      case 'a':
        ArregloCifrado[i] = mur2[0];
        lcd.setCursor(Cursor,0);
        lcd.print(ArregloCifrado[i]);
        Cursor += 1;
        delay(1000);
        break;
        
      case 'b':
        ArregloCifrado[i] = mur2[1];
        lcd.setCursor(Cursor,0);
        lcd.print(ArregloCifrado[i]);
        Cursor += 1;
        delay(1000);
        break;
        
      case 'c':
        ArregloCifrado[i] = mur2[2];
        lcd.setCursor(Cursor,0);
        lcd.print(ArregloCifrado[i]);
        Cursor += 1;
        delay(1000);
        break;
        
      default:
        //lcd.print(" ");
        lcd.setCursor(Cursor,0);
        Cursor += 1;
        break;
        
    }//switch
  }//for
  
  while(digitalRead(boton3) == LOW){
    //no hacer nada
  }//while
  delay(1000);
  resetFunc();
}//funcion del automata 1

//-----------------automata2-------------------------
void Automata2F1(){
  char Llave[3] = {'a', 'b', 'c'};
  lcd.clear();
  lcd.setCursor(0,0);
  
  for(int i = 0; i < 3; i++){
    cif2[i] = mur[llave + i];
  }//llenando cif2
  
  lcd.setCursor(Cursor,0);
  for(int i = 0; i < 16; i++){
    
    switch(ArregloCifrado[i]){
      case 'm':
        if(cif2[0] == 'm'){ArregloDescifrado[i] = Llave[0];}//si el caracter pertenece a cif2
        if(cif2[1] == 'm'){ArregloDescifrado[i] = Llave[1];}//si el caracter pertenece a cif2
        if(cif2[2] == 'm'){ArregloDescifrado[i] = Llave[2];}//si el caracter pertenece a cif2
        lcd.setCursor(Cursor,0);
        lcd.print(ArregloDescifrado[i]);
        Cursor += 1;
        delay(1000);
        break;
        
      case 'u':
        if(cif2[0] == 'u'){ArregloDescifrado[i] = Llave[0];}//si el caracter pertenece a cif2
        if(cif2[1] == 'u'){ArregloDescifrado[i] = Llave[1];}//si el caracter pertenece a cif2
        if(cif2[2] == 'u'){ArregloDescifrado[i] = Llave[2];}//si el caracter pertenece a cif2
        lcd.setCursor(Cursor,0);
        lcd.print(ArregloDescifrado[i]);
        Cursor += 1;
        delay(1000);
        break;
        
      case 'r':
        if(cif2[0] == 'r'){ArregloDescifrado[i] = Llave[0];}//si el caracter pertenece a cif2
        if(cif2[1] == 'r'){ArregloDescifrado[i] = Llave[1];}//si el caracter pertenece a cif2
        if(cif2[2] == 'r'){ArregloDescifrado[i] = Llave[2];}//si el caracter pertenece a cif2
        lcd.setCursor(Cursor,0);
        lcd.print(ArregloDescifrado[i]);
        Cursor += 1;
        delay(1000);
        break;
        
      case 'c':
        if(cif2[0] == 'c'){ArregloDescifrado[i] = Llave[0];}//si el caracter pertenece a cif2
        if(cif2[1] == 'c'){ArregloDescifrado[i] = Llave[1];}//si el caracter pertenece a cif2
        if(cif2[2] == 'c'){ArregloDescifrado[i] = Llave[2];}//si el caracter pertenece a cif2
        lcd.setCursor(Cursor,0);
        lcd.print(ArregloDescifrado[i]);
        Cursor += 1;
        delay(1000);
        break;
        
      case 'i':
        if(cif2[0] == 'i'){ArregloDescifrado[i] = Llave[0];}//si el caracter pertenece a cif2
        if(cif2[1] == 'i'){ArregloDescifrado[i] = Llave[1];}//si el caracter pertenece a cif2
        if(cif2[2] == 'i'){ArregloDescifrado[i] = Llave[2];}//si el caracter pertenece a cif2
        lcd.setCursor(Cursor,0);
        lcd.print(ArregloDescifrado[i]);
        Cursor += 1;
        delay(1000);
        break;
        
      case 'e':
        if(cif2[0] == 'e'){ArregloDescifrado[i] = Llave[0];}//si el caracter pertenece a cif2
        if(cif2[1] == 'e'){ArregloDescifrado[i] = Llave[1];}//si el caracter pertenece a cif2
        if(cif2[2] == 'e'){ArregloDescifrado[i] = Llave[2];}//si el caracter pertenece a cif2
        lcd.setCursor(Cursor,0);
        lcd.print(ArregloDescifrado[i]);
        Cursor += 1;
        delay(1000);
        break;  
        
      case 'l':
        if(cif2[0] == 'l'){ArregloDescifrado[i] = Llave[0];}//si el caracter pertenece a cif2
        if(cif2[1] == 'l'){ArregloDescifrado[i] = Llave[1];}//si el caracter pertenece a cif2
        if(cif2[2] == 'l'){ArregloDescifrado[i] = Llave[2];}//si el caracter pertenece a cif2
        lcd.setCursor(Cursor,0);
        lcd.print(ArregloDescifrado[i]);
        Cursor += 1;
        delay(1000);
        break;  
        
      case 'a':
        if(cif2[0] == 'a'){ArregloDescifrado[i] = Llave[0];}//si el caracter pertenece a cif2
        if(cif2[1] == 'a'){ArregloDescifrado[i] = Llave[1];}//si el caracter pertenece a cif2
        if(cif2[2] == 'a'){ArregloDescifrado[i] = Llave[2];}//si el caracter pertenece a cif2
        lcd.setCursor(Cursor,0);
        lcd.print(ArregloDescifrado[i]);
        Cursor += 1;
        delay(1000);
        break;  
        
      case 'g':
        if(cif2[0] == 'g'){ArregloDescifrado[i] = Llave[0];}//si el caracter pertenece a cif2
        if(cif2[1] == 'g'){ArregloDescifrado[i] = Llave[1];}//si el caracter pertenece a cif2
        if(cif2[2] == 'g'){ArregloDescifrado[i] = Llave[2];}//si el caracter pertenece a cif2
        lcd.setCursor(Cursor,0);
        lcd.print(ArregloDescifrado[i]);
        Cursor += 1;
        delay(1000);
        break;
        
      case 'o':
        if(cif2[0] == 'o'){ArregloDescifrado[i] = Llave[0];}//si el caracter pertenece a cif2
        if(cif2[1] == 'o'){ArregloDescifrado[i] = Llave[1];}//si el caracter pertenece a cif2
        if(cif2[2] == 'o'){ArregloDescifrado[i] = Llave[2];}//si el caracter pertenece a cif2
        lcd.setCursor(Cursor,0);
        lcd.print(ArregloDescifrado[i]);
        Cursor += 1;
        delay(1000);
        break; 
       
        
      default:
        //lcd.print(" ");
        lcd.setCursor(Cursor,0);
        Cursor += 1;
        break;
        
    }//switch
  }//for
  
  
  
  while(digitalRead(boton3) == LOW){
    //no hacer nada
  }//while
  
  delay(1000);
  resetFunc();//<----reseteo el arduino

}//automata2f1




void Automata2F(){
  int bandera = 0;
  //------pedimos la llave
  lcd.clear();
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
                llave += 1;
                lcd.print(llave);
    
                if(llave >= 10){
                  llave = 0;
                  lcd.clear();
                }//si es mayor que 10
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
                Automata2F1();//<---llamada a la muy funcionalidad del automata
              }//is
            }//else
  }//while
  
}//funcion automata2



//====================================================AUTOMATAS==================================================
//----------------------------------AUTOMATA1------------------------------------
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
                Automata1F();//--------------
                bandera = 1;
              }//is
            }//else
            
    }//while button 3
      Serial.print("me sali del boton 3");
      
  
    //ArregloCadena[posCursor] = Arreglo_boton1[Arreglop_boton1 -1];

}//automata1


//----------------------------------AUTOMATA 2-----------------------
void Automata2(){
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
                lcd.print(mur[Arreglop_boton1]);
                car_final =  Arreglop_boton1;
                Serial.print("bton 1 presionado");
    
                Arreglop_boton1 +=1;
                if(Arreglop_boton1 >= 10){
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
                ArregloCifrado[posCursor] = mur[car_final];
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
                ArregloCifrado[posCursor] = mur[car_final];
                Automata2F();//--------------
                bandera = 1;
              }//is
            }//else
            
    }//while button 3
      Serial.print("me sali del boton 3");
    //ArregloCadena[posCursor] = Arreglo_boton1[Arreglop_boton1 -1];

}//automata2






















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
    Automata2();//f<---uncion automata2
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
