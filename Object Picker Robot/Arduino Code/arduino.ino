// Grabbing object 

// Motor 1 will rotate (p)

//  Motor 2 will rotate (q)


// Motor 3 will move forward (x)

//  Motor 4 will move forward (y)


// Motor 5 and 6 will release the object (z)

// Motor 4 will move forward (y)

//  Motor 3 will move forward (x)



// Motor 2 will rotate (-p)

//  Motor 1 will rotate (-q)




#include <Servo.h>


int pos=0,mv1=0,mv2=0,mv3=0,grb=0,val=0;


//Initialize servo motors
Servo s1,s2,s3,s4,s5,s6; 

void setup() {

     Serial.begin(9600); // Start serial communication at 9600 bps

  s1.attach(2);
  s2.attach(3);
  s3.attach(4);  
  s4.attach(5);
  s5.attach(6);
  s6.attach(7);

  
  s1.write(30);
  s2.write(60);
 
  s3.write(10);
  s4.write(100);
  s5.write(100);
  s6.write(10);
}





void move1()
{
  //90 rotation
  if(!mv1)
{
//For servo 1 rotation


  for (pos = 30; pos <= 120; pos += 1) { 
    
    s1.write(pos);
    delay(50);                      
  }

  delay(1000);




  
  delay(1000);

  // moving s3 forward
  for (pos = 10; pos <= 50; pos += 1) { 
    s3.write(pos);              
    delay(50);                  
  }


  delay(1000);

  // moving s4 forward
   for (pos = 100; pos <= 150; pos += 1) { 
    
    s4.write(pos);              
    delay(50);                  
  }

 
  
  delay(1000);

  // moving s3 forward
  for (pos = 50; pos <= 60; pos += 1) { 
    s3.write(pos);              
    delay(50);                  
  }

  

  // moving s4 forward
   for (pos = 150; pos >= 70; pos -= 1) { 
    
    s4.write(pos);              
    delay(50);                  
  }


  // moving s3 forward
  for (pos = 60; pos <= 70; pos += 1) { 
    s3.write(pos);              
    delay(50);                  
  }



  //expanding claw

  for (pos = 10; pos <= 100; pos += 1) { 
    
    s6.write(pos);
    s5.write(100-pos);   
    delay(50);                      
  }
  
  delay(1000);

// moving s4 up
   for (pos = 70; pos <=110; pos += 1) { 
    
    s4.write(pos);              
    delay(50);                  
  }

  delay(1000);
  // s3.write(10);
   //delay(500);
  //s4.write(100);


  //s3 initial
  
  // moving s3 forward
  for (pos = 70; pos >= 10; pos -= 1) { 
    s3.write(pos);              
    delay(50);                  
  }
  delay(1000);

  // moving s4 forward
  for (pos = 110; pos >= 100; pos -= 1) { 
    s4.write(pos);              
    delay(50);                  
  }
  delay(1000);



  //For servo 1 rotation


  for (pos = 120; pos >= 30; pos -= 1) { 
    
    s1.write(pos);
    delay(50);                      
  }

  delay(1000);


  // For squeezing claw
  for (pos = 100; pos >= 0; pos -= 1) { 
     s6.write(pos);
    s5.write(100-pos);   
    delay(50);                      
  }
  delay(1000);

  
}  
  mv1=1;
  
}





void move2() {
  // 180 rotation

  
if(!mv2)
{

  //For servo 1 rotation


  for (pos = 30; pos <= 120; pos += 1) { 
    
    s1.write(pos);
    delay(50);                      
  }

  delay(1000);


  //For servo 2 rotation


  for (pos = 60; pos <= 150; pos += 1) { 
    
    s2.write(pos);
    delay(50);                      
  }

  delay(1000);






  
  delay(1000);

  // moving s3 forward
  for (pos = 10; pos <= 50; pos += 1) { 
    s3.write(pos);              
    delay(50);                  
  }


  delay(1000);

  // moving s4 forward
   for (pos = 100; pos <= 150; pos += 1) { 
    
    s4.write(pos);              
    delay(50);                  
  }

 
  
  delay(1000);

  // moving s3 forward
  for (pos = 50; pos <= 60; pos += 1) { 
    s3.write(pos);              
    delay(50);                  
  }

  

  // moving s4 forward
   for (pos = 150; pos >= 70; pos -= 1) { 
    
    s4.write(pos);              
    delay(50);                  
  }


  // moving s3 forward
  for (pos = 60; pos <= 70; pos += 1) { 
    s3.write(pos);              
    delay(50);                  
  }



  //expanding claw

  for (pos = 10; pos <= 100; pos += 1) { 
    
    s6.write(pos);
    s5.write(100-pos);   
    delay(50);                      
  }
  
  delay(1000);

// moving s4 up
   for (pos = 70; pos <=110; pos += 1) { 
    
    s4.write(pos);              
    delay(50);                  
  }

  delay(1000);
  // s3.write(10);
   //delay(500);
  //s4.write(100);


  //s3 initial
  
  // moving s3 forward
  for (pos = 70; pos >= 10; pos -= 1) { 
    s3.write(pos);              
    delay(50);                  
  }
  delay(1000);

  // moving s4 forward
  for (pos = 110; pos >= 100; pos -= 1) { 
    s4.write(pos);              
    delay(50);                  
  }
  delay(1000);






//for moving the base back

  for (pos = 120; pos >= 30; pos -= 1) { 
    
    s1.write(pos);
    delay(50);                      
  }

  delay(1000);

  
  for (pos = 150; pos >= 60; pos -= 1) { 
    
    s2.write(pos);
    delay(50);                      
  }

  delay(1000);





  // For squeezing claw
  for (pos = 100; pos >= 0; pos -= 1) { 
     s6.write(pos);
    s5.write(100-pos);   
    delay(50);                      
  }
  delay(1000);


}  
  mv2=1;

  

}



void move3()
{
    
if(!mv3)
{

  //For servo 1 rotation


  for (pos = 30; pos <= 180; pos += 1) { 
    
    s1.write(pos);
    delay(50);                      
  }

  delay(1000);


  //For servo 2 rotation


  for (pos = 60; pos <= 180; pos += 1) { 
    
    s2.write(pos);
    delay(50);                      
  }

  delay(1000);







  
  delay(1000);

  // moving s3 forward
  for (pos = 10; pos <= 50; pos += 1) { 
    s3.write(pos);              
    delay(50);                  
  }


  delay(1000);

  // moving s4 forward
   for (pos = 100; pos <= 150; pos += 1) { 
    
    s4.write(pos);              
    delay(50);                  
  }

 
  
  delay(1000);

  // moving s3 forward
  for (pos = 50; pos <= 60; pos += 1) { 
    s3.write(pos);              
    delay(50);                  
  }

  

  // moving s4 forward
   for (pos = 150; pos >= 70; pos -= 1) { 
    
    s4.write(pos);              
    delay(50);                  
  }


  // moving s3 forward
  for (pos = 60; pos <= 70; pos += 1) { 
    s3.write(pos);              
    delay(50);                  
  }



  //expanding claw

  for (pos = 10; pos <= 100; pos += 1) { 
    
    s6.write(pos);
    s5.write(100-pos);   
    delay(50);                      
  }
  
  delay(1000);

// moving s4 up
   for (pos = 70; pos <=110; pos += 1) { 
    
    s4.write(pos);              
    delay(50);                  
  }

  delay(1000);
  // s3.write(10);
   //delay(500);
  //s4.write(100);


  //s3 initial
  
  // moving s3 forward
  for (pos = 70; pos >= 10; pos -= 1) { 
    s3.write(pos);              
    delay(50);                  
  }
  delay(1000);

  // moving s4 forward
  for (pos = 110; pos >= 100; pos -= 1) { 
    s4.write(pos);              
    delay(50);                  
  }
  delay(1000);



//for moving the base back

  for (pos = 180; pos >= 30; pos -= 1) { 
    
    s1.write(pos);
    delay(50);                      
  }

  delay(1000);

  
  for (pos = 180; pos >= 60; pos -= 1) { 
    
    s2.write(pos);
    delay(50);                      
  }

  delay(1000);





  // For squeezing claw
  for (pos = 100; pos >= 0; pos -= 1) { 
     s6.write(pos);
    s5.write(100-pos);   
    delay(50);                      
  }
  delay(1000);


}  
  mv3=1;

  
}

void grab()
{

if(!grb)
{

  for (pos = 10; pos <= 100; pos += 1) { 
    
    s6.write(pos);
    s5.write(100-pos);   
    delay(50);                      
  }
  
  delay(1000);

  // moving s3 forward
  for (pos = 10; pos <= 50; pos += 1) { 
    s3.write(pos);              
    delay(50);                  
  }


  delay(1000);

  // moving s4 forward
   for (pos = 100; pos <= 150; pos += 1) { 
    
    s4.write(pos);              
    delay(50);                  
  }

 
  
  delay(1000);

  // moving s3 forward
  for (pos = 50; pos <= 60; pos += 1) { 
    s3.write(pos);              
    delay(50);                  
  }

  

  // moving s4 forward
   for (pos = 150; pos >= 70; pos -= 1) { 
    
    s4.write(pos);              
    delay(50);                  
  }


  // moving s3 forward
  for (pos = 60; pos <= 70; pos += 1) { 
    s3.write(pos);              
    delay(50);                  
  }
  
  // For squeezing claw
  for (pos = 100; pos >= 0; pos -= 1) { 
     s6.write(pos);
    s5.write(100-pos);   
    delay(50);                      
  }
  delay(1000);

  
 
  // moving s4 up
   for (pos = 70; pos <=110; pos += 1) { 
    
    s4.write(pos);              
    delay(50);                  
  }

  delay(1000);
  // s3.write(10);
   //delay(500);
  //s4.write(100);


  //s3 initial
  
  // moving s3 forward
  for (pos = 70; pos >= 10; pos -= 1) { 
    s3.write(pos);              
    delay(50);                  
  }
  delay(1000);

  // moving s4 forward
  for (pos = 110; pos >= 100; pos -= 1) { 
    s4.write(pos);              
    delay(50);                  
  }
  delay(1000);


}
   grb=1;
 
}


void loop() {
  if (Serial.available()) 
   { 
     val = Serial.read(); // read it and store it in val


     if(val=='1')
     {
      grab();
       grb=0;
        move1();
        mv1=0;
        
      
     }

    else if (val=='2')
    {
      grab();
        grb=0;
        move2();
        mv2=0;
        
    }

    else if(val=='3')
    {
     grab();
       grb=0;
        move3();
        mv3=0;
        
    }
  }

} 

 
  


