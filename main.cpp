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

#define Rojo PF_1
#define Verde PF_3 
#define Azul PF_2

#define Boton1 PF_0
#define Boton2 PF_4

//*****************************************************************************
// Prototipos de función
//*****************************************************************************
void Contador(void);

void Impresion(void);

//*****************************************************************************
// Variables Globales
//*****************************************************************************
int ContadorBoton1 = 0; //Contador Boton en entero
int Potenciometro = 0;
int V1= 0; 

long LastTime;
long SampleTime = 250;

long LastTime2;
long SampleTime2 = 250;

long LastTime3; 
long SampleTime3=2; 
