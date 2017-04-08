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

//Initialize servo motors
Servo s1,s2,s3,s4,s5,s6; 

int pos = 0,done=0;    // variable to store the servo position

void setup() {
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

void loop() {

if(!done)
{

  //For servo 1 rotation


  for (pos = 30; pos <= 120; pos += 1) { 
    
    s1.write(pos);
    delay(50);                      
  }

  delay(50);




  
  delay(1000);

  // moving s3 forward
  for (pos = 10; pos <= 50; pos += 1) { 
    s3.write(pos);              
    delay(50);                  
  }


  delay(50);

  // moving s4 forward
   for (pos = 100; pos <= 150; pos += 1) { 
    
    s4.write(pos);              
    delay(50);                  
  }

 
  
delay(50);

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

delay(50);
  // s3.write(10);
   //delay(500);
  //s4.write(100);


  //s3 initial
  
  // moving s3 forward
  for (pos = 70; pos >= 10; pos -= 1) { 
    s3.write(pos);              
    delay(50);                  
  }
delay(50);

  // moving s4 forward
  for (pos = 110; pos >= 100; pos -= 1) { 
    s4.write(pos);              
    delay(50);                  
  }
delay(50);



  //For servo 1 rotation


  for (pos = 120; pos >= 30; pos -= 1) { 
    
    s1.write(pos);
    delay(50);                      
  }

delay(50);


  // For squeezing claw
  for (pos = 100; pos >= 0; pos -= 1) { 
     s6.write(pos);
    s5.write(100-pos);   
    delay(50);                      
  }
delay(50);

  


}  
  done=1;

  
  
}

