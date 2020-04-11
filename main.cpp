/*
Módulo TM1637
https://www.arduinoecia.com.br/como-usar-modulo-tm1637-com-arduino/
acessado em 11/04/2020 as 14:26
*/
#include <Arduino.h>
#include <TM1637Display.h>

//Pinos de controle do modulo
#define CLK 4
#define DIO 5
#define pin_pot A0
//Inicializa o display
TM1637Display display(CLK, DIO);
int valor;

void setup(){  
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void contador(){
  for (int i = 0; i < 10000; i++){
    display.showNumberDec(i, false); 
    Serial.print("Contagem atual: ");
    Serial.println(i);  
    delay(10);
  }
}

void contador_dec(){
  for (int i = 9999; i > 0; i--){
    display.showNumberDec(i, false);  
    Serial.print("Contagem atual: ");
    Serial.println(i);  
    delay(10);
  }
}

void loop(){  
  Serial.println("Aplicação teste quatro displays 7 segmentos");
  Serial.println("Módulo TM1637");
  //Define o brilho do display  
  display.setBrightness(0x0f);    //Le o valor do potenciometro  
  contador();  // contagem crescente
  contador_dec();  // contagem decrescente
  // valor = analogRead(pin_pot);  //Mostra o valor no display 
  delay(10);
}
