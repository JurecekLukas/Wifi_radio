 #include "Arduino.h"
  
 int CLK = 14;  // Pin 9 na CLK 
 int DT = 12;  // Pin 8 na DT

 int pozice = 0; 
 int rotace;  
 int pom;
 int hlasitost = 0;
 boolean ZlevaDoprava;
 
 void setup() { 
   Serial.begin (115200);
   pinMode (CLK,INPUT);
   pinMode (DT,INPUT);
   rotace = digitalRead(CLK);   
 } 
 void loop() { 
   pom = digitalRead(CLK);
     if (pom != rotace){ //pomocí pinu DT zjišťujeme otočení
       if (digitalRead(DT) != pom) {  
          //otočení doprava
         pozice ++;
         ZlevaDoprava = true;
       } else { 
        //otočení doleva
         ZlevaDoprava = false;
         pozice--;
       }
       
       if (ZlevaDoprava){ // otáčení doprava
        if (hlasitost >20){ //pokud hlasitost bude vyšší než 20 nastavíme na 21 (MAX)
          hlasitost =21;
          Serial.println ("Vase hlasitost je na urovni = ");
          Serial.println (hlasitost);
          Serial.println ("   Maximum");
         }
         else{ //pokud nebude ještě na hodnotě 20 přičítáme o 1
          hlasitost++;
          Serial.println ("Vase hlasitost je na urovni = ");
          Serial.println (hlasitost);
         }     
         
  
       }else{        // otáčení doleva 
        if (hlasitost <1){ //pokud hlasitost bude nižší než 1 nastavíme na 0 (MIN)
          hlasitost =0;
          Serial.println ("Vase hlasitost je na urovni = ");
          Serial.println (hlasitost);
          Serial.println ("   Minimum");
         }
         else{//pokud nebude ještě na hodnotě 0 odečítáme o 1
          hlasitost--;
          Serial.println ("Vase hlasitost je na urovni = ");
          Serial.println (hlasitost);
         } 
       }
       //Výpis pozice encodéru
       Serial.print("Pozice encoderu: ");
       Serial.println(pozice);
       
     } 
   rotace = pom;
 } 
