//*****************************************************************************
// Universidad del Valle de Guatemala
// BE3015 - Electrónica Digital 2
// Gunther Dietmar Menzel - 19106
// LAB6
//*****************************************************************************

//*****************************************************************************
// Librerías
//*****************************************************************************
#include <Arduino.h>

//*****************************************************************************
// Definición de pines
//*****************************************************************************
//Definición del pin para el potenciómetro
#define pot2 PD_1
//Definición de los pines para las LEDs
#define Rojo PF_1
#define Verde PF_3 
#define Azul PF_2
//Definición de los pines para los botones
#define Boton1 PF_0
#define Boton2 PF_4

//*****************************************************************************
// Prototipos de función
//*****************************************************************************
void Contador(void); //Variable para el contador

void Impresion(void); //Variable para la impresion de datos

//*****************************************************************************
// Variables Globales
//*****************************************************************************
int ContadorBoton1 = 0; //Contador Boton en entero
int Potenciometro = 0; //Potenciometro
int V1= 0; //Voltaje del pot
//Tiempos de muestra para los colores
long LastTime;
long SampleTime = 250;

long LastTime2;
long SampleTime2 = 250;

long LastTime3; 
long SampleTime3=2; 

//*****************************************************************************
// Configuración
//*****************************************************************************
void setup() {
  //Iniciando la comunicación
  Serial3.begin(115200);
  Serial.begin(115200);
  //Estados de los botones
  pinMode(Boton1, INPUT_PULLUP); 
  pinMode(Boton2, INPUT_PULLUP);
  //Tiempos de muestra
  LastTime = millis(); 
  LastTime2 = millis();
  LastTime3 =millis();
}

//*****************************************************************************
// Loop Principal
//*****************************************************************************
void loop() {
  //Configurando los tiempos de muestra
  if (millis()-LastTime >= SampleTime){
    
    Potenciometro = analogRead(pot2); //Voltaje para el potenciómetro 
    Potenciometro = map(Potenciometro, 0,4095,0,255); //Convirtiendo los valores del potenciómetro

    //Comunicación con ESP32
    Serial3.write(Potenciometro);
    Serial3.print('\t');
    Serial3.write(ContadorBoton1);
    Serial3.print('\n');
  
    //Comunicación con ESP32
    if (Serial3.available()>0){
      V1 = Serial3.read(); 
    }
      
    LastTime = millis();
  }
    //Configurando los tiempos de muestra
    if (millis()-LastTime2 >= SampleTime2){
    Impresion();
    LastTime2 = millis();
  }
  //Configurando los tiempos de muestra
  if (millis()-LastTime3 >= SampleTime3){
    analogWrite(Rojo, V1);
    analogWrite(Azul,Potenciometro);
    analogWrite(Verde, ContadorBoton1);
    Contador();
    LastTime3 = millis();
  }
}
//Iniciando el contador
void Contador(void){
  if (digitalRead(Boton1)== LOW){ //Estado del boton
    if (ContadorBoton1<255){ //Parámetros del contador
      ContadorBoton1 = ContadorBoton1+15;

    }

    else if(ContadorBoton1 >=255){ //Parámetros del contador
      ContadorBoton1=0;
    }
  }
if (digitalRead(Boton2)== LOW){ //Estado del boton
    if (ContadorBoton1>0){
      ContadorBoton1 = ContadorBoton1-15;

          }

    else if(ContadorBoton1 <=0){ //Parámetros del contador
      ContadorBoton1=255;
    }
    }
}
//Asignando lo que quiero que diga la LCD y qué valores quiero que expulse
void Impresion(void){
  Serial.print("Rojo: ");
  Serial.print(" ");
  Serial.print(V1);
  Serial.print(" ");
  Serial.print("Azul");
  Serial.print(" ");
  Serial.print(Potenciometro);
  Serial.print(" ");
  Serial.print("Verde");
  Serial.print(" ");
  Serial.println(ContadorBoton1);

}