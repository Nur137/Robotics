// Grabbing object 

// Motor 3 will move forward (x)

//  Motor 4 will move forward (y)

// Motor 5 and 6 will squeeze to grab the object (z)


// Motor 4 will move forward (y)

//  Motor 3 will move forward (x)
#include <Servo.h>

//Initialize servo motors
Servo s3,s4,s5,s6; 

int pos = 0,done=0,grb;    // variable to store the servo position

void setup() {
  s3.attach(4);  
  s4.attach(5);
  s5.attach(6);
  s6.attach(7);

  s3.write(10);
  s4.write(100);
  s5.write(100);
  s6.write(10);
}

void loop() {

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

