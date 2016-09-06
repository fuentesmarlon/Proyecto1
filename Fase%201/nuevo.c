/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simpletools header
#include "abdrive.h"                          // Include abdrive header
#include "ping.h"                             // Include ping header

int main()                                    // Main function
{
  low(26);
  low(27);
  
	// Add startup code here.
	while(1)
	{
	 	if(revisarDerecha()==1 && revisarAdelante()==1){
        derecha();
      }     
		while(revisarAdelante()==1&&revisarDerecha()==0){
        recto();    
	   }
    if(revisarAdelante()==0&&revisarDerecha()==1){
        derecha();    
	   }
    if(revisarAdelante()==0&&revisarDerecha()==0){
        izquierda();    
	   }
  }
}  

     
 void derecha(){
   for(int n = 1; n <= 65; n++){                // Count to hundred
    drive_rampStep(35,35);                   // move not too fast
    pause(10);                               // 50 ms between reps
    } 
		drive_speed(0,0);
     pause(500);
     drive_goto(25,-25); //giro a la derecha
     pause(500);
     
     for(int n = 1; n <= 65; n++){                // Count to hundred
    drive_rampStep(35,35);                   // move not too fast
    pause(10);                               // 50 ms between reps
    } 
	
	}   
 
  
	void izquierda(){
	  drive_speed(0,0);
     pause(500);
     drive_goto(-25,25); //giro a la derecha
     pause(500);
	} 
 
  
	void recto(){
	  drive_rampStep(50,50);
	}
 
	 
	int distanciaAdelante() {
    return ping_cm(8);
  }  
  
    
	int distanciaDerecha() {
    return ping_cm(9);
  } 
  
         
	int revisarAdelante(){
   if (distanciaAdelante()>10){
      return 1;
   }   
   else {
      return 0;
   }       
  }
  
  int revisarDerecha(){
  freqout(1,1,38000);
  return (input(2));
  }
    
  
 // int revisarDerecha(){
   //if (distanciaDerecha()>5){
     // return 1;
   //}   
   //else {
     // return 0;
   //}       
  //}
  
 
 
