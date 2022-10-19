//CRISTIAN CADENA - PAULO RIVERA

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long tInicio,tiempo; //Control de tiempo

byte start1 = 8; //Tipo
byte start2 = 9; //Tamaño
byte start3 = 10; //Start


int sensor1 = A0; //Azucar

int evento1 = 6; //Valvula Cafe
int evento2 = 7; //Valvula Leche
int evento3 = 13; //Valvula Azucar
int evento4 = A5; //Bebida Lista

bool stateevento1=0;//CAFE
bool stateevento2=0;//LECHE
bool stateevento3=0;//AZUCAR
bool stateevento4=0;//BEBIDA LISTA

String state_mensaje1;
String state_mensaje2;
String state_mensaje3;

String state_ti;
String state_ta;
String state_az;

int etapa=0;

bool state_rebote1 = false;
bool state_rebote2 = false;
bool state_rebote3 = false;

int contadorti=0;
int contadorta=0;
int contadoraz=0;


void setup()
{
  lcd.begin(16, 2);

  pinMode(start1,INPUT);
  pinMode(start2,INPUT);
  pinMode(start3,INPUT);
  

  pinMode(sensor1,INPUT);  
     
  pinMode(evento1,OUTPUT);
  pinMode(evento2,OUTPUT);
  pinMode(evento3,OUTPUT);
  pinMode(evento4,OUTPUT);
}

void loop()
{
  //ENTRADAS
  byte st1 = digitalRead(start1);//tipo
  byte st2 = digitalRead(start2);//tamaño
  byte st3 = digitalRead(start3);//start
  
  int ss = analogRead(sensor1);
  int css = map(ss,0,1023,10,30);

  String cafe = "CAFE  ";
  String pinta = "PINTA ";
  String cafele = "CAFELE";
  
  String peq = " PEQ";
  String med = " MED";
  String gra = " GRA";
  
  
  //PROCESO
  
  switch(etapa)
  {
    case 0:
      state_mensaje1="Beb: ";
      state_mensaje2="Tam: ";
      state_mensaje3="Azu: ";
      state_mensaje3=state_mensaje3 + css;
      
      if(st1 == HIGH && state_rebote1==false && contadorti==0)
      { 
        state_mensaje1="Beb: "; 
        state_mensaje1=state_mensaje1 + cafe; 
        state_rebote1=true;
        state_ti=cafe; 
        contadorti=1;       
      }
      
      else if(st1==LOW && state_rebote1==true && contadorti==1)
      {        
        state_rebote1=false;            
      }

      else if(st1 == HIGH && state_rebote1==false && contadorti==1)
      { 
        state_mensaje1="Beb: "; 
        state_mensaje1=state_mensaje1 + pinta;  
        state_rebote1=true;
        state_ti=pinta;
        contadorti=2;         
      }
      else if(st1==LOW && state_rebote1==true && contadorti==2)
      {        
        state_rebote1=false;              
      }

      else if(st1 == HIGH && state_rebote1==false && contadorti==2)
      { 
        state_mensaje1="Beb: "; 
        state_mensaje1=state_mensaje1 + cafele;  
        state_rebote1=true;
        state_ti=cafele;
        contadorti=3;        
      }
      else if(st1==LOW && state_rebote1==true && contadorti==3)
      {        
        state_rebote1=false;
        contadorti=0;             
      }

          

////////////////////////////////

      else if(st2 == HIGH && state_rebote2==false && contadorta==0)
      { 
        state_mensaje2="Tam:";
        state_mensaje2=state_mensaje2 + peq;  
        state_rebote2=true; 
        contadorta=1;
        state_ta=peq;        
      }
      else if(st2==LOW && state_rebote2==true && contadorta==1)
      {        
        state_rebote2=false;         
      }

      else if(st2 == HIGH && state_rebote2==false && contadorta==1)
      { 
        state_mensaje2="Tam:";
        state_mensaje2=state_mensaje2 + med;  
        state_rebote2=true;
        contadorta=2; 
        state_ta=med; 
        
      }
      else if(st2==LOW && state_rebote2==true && contadorta==2)
      {        
        state_rebote2=false;        
      }

      else if(st2 == HIGH && state_rebote2==false && contadorta==2)
      { 
        state_mensaje2="Tam:";
        state_mensaje2=state_mensaje2 + gra;  
        state_rebote2=true;
        contadorta=3;
        state_ta=gra;  
        
      }
      else if(st2==LOW && state_rebote2==true && contadorta==3)
      {        
        state_rebote2=false;   
        contadorta=0;     
      }

      else if(st3 == HIGH)
      {
        etapa=1;
        lcd.clear();
      }      

    break;

    case 1:
//CAFE      
      if(state_ti == cafe && state_ta == peq)
      { 
        etapa=2;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }      
      else if(state_ti == cafe && state_ta == med)
      {        
        etapa=3;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();           
      }
      else if(state_ti == cafe && state_ta == gra)
      {        
        etapa=4;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();           
      }

//PINTADO
      else if(state_ti == pinta && state_ta == peq)
      { 
        etapa=11;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }      
      else if(state_ti == pinta && state_ta == med)
      {        
        etapa=12;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();           
      }
      else if(state_ti == pinta && state_ta == gra)
      {        
        etapa=13;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();           
      }

//CAFE EN LECHE
      else if(state_ti == cafele && state_ta == peq)
      { 
        etapa=20;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }      
      else if(state_ti == cafele && state_ta == med)
      {        
        etapa=21;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();           
      }
      else if(state_ti == cafele && state_ta == gra)
      {        
        etapa=22;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();           
      }
    break;
//CAFE PEQUEÑO
    case 2:
      tiempo=millis()-tInicio;
      if(tiempo<=6944)
      {
        state_mensaje1="Sirviendo Cafe";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento1=1;
      }else
      {
        etapa=5;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 5:
      tiempo=millis()-tInicio;
      if(css>=10 && css<=19 && tiempo<=1000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
      }
      else if(css>=20 && css<=30 && tiempo<=2000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
      }      
      else
      {
        etapa=6;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 6:
       state_mensaje1="Bebida Servida";        
       state_mensaje2="Presiona START";
       stateevento3=0;
       stateevento1=0;
       stateevento4=1;
      
      if(st3==HIGH && state_rebote3==false)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=true;
      }else if(st3==LOW && state_rebote3==true)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=false;
        etapa=0;        
      }
    break; 

//CAFE MEDIANO
    case 3:
      tiempo=millis()-tInicio;
      if(tiempo<=15555)
      {
        state_mensaje1="Sirviendo Cafe";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento1=1;
      }else
      {
        etapa=7;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 7:
      tiempo=millis()-tInicio;
      if(css>=10 && css<=19 && tiempo<=1000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
      }
      else if(css>=20 && css<=30 && tiempo<=2000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
      } 
      else
      {
        etapa=8;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 8:
       state_mensaje1="Bebida Servida";        
       state_mensaje2="Presiona START";
       stateevento3=0;
       stateevento1=0;
       stateevento4=1;
      
      if(st3==HIGH && state_rebote3==false)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=true;
      }else if(st3==LOW && state_rebote3==true)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=false;
        etapa=0;        
      }
    break; 

//CAFE GRANDE
    case 4:
      tiempo=millis()-tInicio;
      if(tiempo<=21111)
      {
        state_mensaje1="Sirviendo Cafe";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento1=1;
      }else
      {
        etapa=9;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 9:
      tiempo=millis()-tInicio;
      if(css>=10 && css<=19 && tiempo<=1000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
      }
      else if(css>=20 && css<=30 && tiempo<=2000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
      } 
      else
      {
        etapa=10;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 10:
       state_mensaje1="Bebida Servida";        
       state_mensaje2="Presiona START";
       stateevento3=0;
       stateevento1=0;
       stateevento4=1;
      
      if(st3==HIGH && state_rebote3==false)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=true;
      }else if(st3==LOW && state_rebote3==true)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=false;
        etapa=0;        
      }
    break; 

//PINTADO PEQUEÑO
    case 11:
      tiempo=millis()-tInicio;
      if(tiempo<=5555)
      {
        state_mensaje1="Sirviendo Cafe";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento1=1;
      }else if(tiempo>5555 && tiempo<=6943)
      {
        state_mensaje1="Sirviendo Leche";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento1=0;
        stateevento2=1;
      }      
      else
      {
        etapa=14;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 14:
      tiempo=millis()-tInicio;
      if(css>=10 && css<=19 && tiempo<=1000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
        stateevento2=0;
      }
      else if(css>=20 && css<=30 && tiempo<=2000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
        stateevento2=0;
      }      
      else
      {
        etapa=15;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 15:
       state_mensaje1="Bebida Servida";        
       state_mensaje2="Presiona START";
       stateevento3=0;
       stateevento1=0;
       stateevento2=0;
       stateevento4=1;
      
      if(st3==HIGH && state_rebote3==false)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=true;
      }else if(st3==LOW && state_rebote3==true)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=false;
        etapa=0;        
      }
    break; 

//PINTADO MEDIANO
    case 12:
      tiempo=millis()-tInicio;
      if(tiempo<=12444)
      {
        state_mensaje1="Sirviendo Cafe";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento1=1;
      }else if(tiempo>12444 && tiempo<=15555)
      {
        state_mensaje1="Sirviendo Leche";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento1=0;
        stateevento2=1;
      }      
      else
      {
        etapa=16;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 16:
      tiempo=millis()-tInicio;
      if(css>=10 && css<=19 && tiempo<=1000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
        stateevento2=0;
      }
      else if(css>=20 && css<=30 && tiempo<=2000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
        stateevento2=0;
      }      
      else
      {
        etapa=17;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 17:
       state_mensaje1="Bebida Servida";        
       state_mensaje2="Presiona START";
       stateevento3=0;
       stateevento1=0;
       stateevento2=0;
       stateevento4=1;
      
      if(st3==HIGH && state_rebote3==false)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=true;
      }else if(st3==LOW && state_rebote3==true)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=false;
        etapa=0;        
      }
    break; 

//PINTADO GRANDE
    case 13:
      tiempo=millis()-tInicio;
      if(tiempo<=16888)
      {
        state_mensaje1="Sirviendo Cafe";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento1=1;
      }else if(tiempo>16888 && tiempo<=21111)
      {
        state_mensaje1="Sirviendo Leche";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento1=0;
        stateevento2=1;
      }      
      else
      {
        etapa=18;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 18:
      tiempo=millis()-tInicio;
      if(css>=10 && css<=19 && tiempo<=1000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
        stateevento2=0;
      }
      else if(css>=20 && css<=30 && tiempo<=2000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
        stateevento2=0;
      }      
      else
      {
        etapa=19;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 19:
       state_mensaje1="Bebida Servida";        
       state_mensaje2="Presiona START";
       stateevento3=0;
       stateevento1=0;
       stateevento2=0;
       stateevento4=1;
      
      if(st3==HIGH && state_rebote3==false)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=true;
      }else if(st3==LOW && state_rebote3==true)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=false;
        etapa=0;        
      }
    break; 
//CAFE EN LECHE PEQUEÑO
    case 20:
      tiempo=millis()-tInicio;
      if(tiempo<=3472)
      {
        state_mensaje1="Sirviendo Cafe";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento1=1;
      }else if(tiempo>3472 && tiempo<=6943)
      {
        state_mensaje1="Sirviendo Leche";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento1=0;
        stateevento2=1;
      }      
      else
      {
        etapa=23;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 23:
      tiempo=millis()-tInicio;
      if(css>=10 && css<=19 && tiempo<=1000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
        stateevento2=0;
      }
      else if(css>=20 && css<=30 && tiempo<=2000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
        stateevento2=0;
      }      
      else
      {
        etapa=24;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 24:
       state_mensaje1="Bebida Servida";        
       state_mensaje2="Presiona START";
       stateevento3=0;
       stateevento1=0;
       stateevento2=0;
       stateevento4=1;
      
      if(st3==HIGH && state_rebote3==false)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=true;
      }else if(st3==LOW && state_rebote3==true)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=false;
        etapa=0;        
      }
    break; 

//CAFE EN LECHE MEDIANO
    case 21:
      tiempo=millis()-tInicio;
      if(tiempo<=7777)
      {
        state_mensaje1="Sirviendo Cafe";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento1=1;
      }else if(tiempo>7777 && tiempo<=15555)
      {
        state_mensaje1="Sirviendo Leche";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento1=0;
        stateevento2=1;
      }      
      else
      {
        etapa=25;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 25:
      tiempo=millis()-tInicio;
      if(css>=10 && css<=19 && tiempo<=1000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
        stateevento2=0;
      }
      else if(css>=20 && css<=30 && tiempo<=2000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
        stateevento2=0;
      }      
      else
      {
        etapa=26;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 26:
       state_mensaje1="Bebida Servida";        
       state_mensaje2="Presiona START";
       stateevento3=0;
       stateevento1=0;
       stateevento2=0;
       stateevento4=1;
      
      if(st3==HIGH && state_rebote3==false)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=true;
      }else if(st3==LOW && state_rebote3==true)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=false;
        etapa=0;        
      }
    break; 

//CAFE EN LECHE GRANDE
    case 22:
      tiempo=millis()-tInicio;
      if(tiempo<=10555)
      {
        state_mensaje1="Sirviendo Cafe";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento1=1;
      }else if(tiempo>10555 && tiempo<=21111)
      {
        state_mensaje1="Sirviendo Leche";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento1=0;
        stateevento2=1;
      }      
      else
      {
        etapa=27;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 27:
      tiempo=millis()-tInicio;
      if(css>=10 && css<=19 && tiempo<=1000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
        stateevento2=0;
      }
      else if(css>=20 && css<=30 && tiempo<=2000)
      {
        state_mensaje1="Sirviendo Azucar";        
        state_mensaje2="Tiempo(sg): "; 
        state_mensaje2=state_mensaje2 + (tiempo*0.001);
        stateevento3=1;
        stateevento1=0;
        stateevento2=0;
      }      
      else
      {
        etapa=28;
        tInicio=millis();
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
      }
    break;
    case 28:
       state_mensaje1="Bebida Servida";        
       state_mensaje2="Presiona START";
       stateevento3=0;
       stateevento1=0;
       stateevento2=0;
       stateevento4=1;
      
      if(st3==HIGH && state_rebote3==false)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=true;
      }else if(st3==LOW && state_rebote3==true)
      {
        stateevento4=0;
        state_mensaje1="";   
        state_mensaje2="";                    
        state_mensaje3="";
        lcd.clear();
        state_rebote3=false;
        etapa=0;        
      }
    break; 
        
  }
  
  
  //SALIDAS
  digitalWrite(evento1,stateevento1);
  digitalWrite(evento2,stateevento2);  
  digitalWrite(evento3,stateevento3);
  digitalWrite(evento4,stateevento4);  
  
  String mensaje1 = state_mensaje1;
  lcd.setCursor(0,0);
  lcd.print(mensaje1);

  String mensaje2 = state_mensaje2;
  lcd.setCursor(0,1);
  lcd.print(mensaje2);

  String mensaje3 = state_mensaje3;
  lcd.setCursor(9,1);
  lcd.print(mensaje3);

}