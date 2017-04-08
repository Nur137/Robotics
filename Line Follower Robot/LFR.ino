int enableA = 11;
int enableB = 12;
int inpA1 = 5;
int inpB1 = 6;
int inpA2 = 8;
int inpB2 = 9;
int Sensor[8] = {A1, A2, A3, A4, A5, A6, A7, A8};
int ReadSensor[8];
int x = 0;
int y = 0;
int trigPin = 22;
int echoPin = 24;
int fortrigPin = 26;
int forechoPin = 28;
int distanceCm;
long duration;
int speed = 50;
int distanceCm2;
long duration2;

int q = 0;

int z = 0;
int cw = 0;
int prev[8];
int pres[8];
int tot = 0;
void setup()
{
  Serial.begin(9600);
  int i;
  for (i = 0; i < 8; i++)
  {
    pinMode(Sensor[i], INPUT);
  }
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(inpA1, OUTPUT);
  pinMode(inpB1, OUTPUT);
  pinMode(inpA2, OUTPUT);
  pinMode(inpB2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(fortrigPin, OUTPUT);
  pinMode(forechoPin, INPUT);


}



void FILLARRAY()
{
  //taking values from Sensor Array and write in ReadSensor
  int i, x;
  for (i = 0; i < 8; i++)
  {
    x = analogRead(Sensor[i]);
    //ReadSensor[i] = x;

    if (x < 400)
      ReadSensor[i] = 0;
    if (x > 400)
      ReadSensor[i] = 1;

  }

}

void MOVEFORWARD()
{

  Serial.println("Straight");
  digitalWrite(inpA1, HIGH);
  digitalWrite(inpB1, LOW);
  analogWrite(enableA, speed);

  digitalWrite(inpA2, LOW);
  digitalWrite(inpB2, HIGH);
  analogWrite(enableB, speed);
  if (q == 0 && speed <= 60)
    speed++;
  delay(10);
}


void BACK()
{
  FILLARRAY();
  if (BLACK() <= 2)
    cw++;
  else cw = 0;
  Serial.println("BACK");
  digitalWrite(inpA1, LOW);
  digitalWrite(inpB1, HIGH);
  analogWrite(enableA, 60);

  digitalWrite(inpA2, HIGH);
  digitalWrite(inpB2, LOW);
  analogWrite(enableB, 60);
  delay(20);
}

void MOVELEFT()
{
  Serial.println("left");
  digitalWrite(inpA1, LOW);
  digitalWrite(inpB1, HIGH);
  analogWrite(enableA, 25);

  digitalWrite(inpA2, LOW);
  digitalWrite(inpB2, HIGH);
  analogWrite(enableB, 70);

  delay(10);

}

void MOVERIGHT()
{
  Serial.println("Right");
  digitalWrite(inpA1, HIGH);
  digitalWrite(inpB1, LOW);
  analogWrite(enableA, 70);

  digitalWrite(inpA2, HIGH);
  digitalWrite(inpB2, LOW);
  analogWrite(enableB, 25);

  delay(10);

}



void SHARPLEFT()
{

  Serial.println("Sharp left");
  digitalWrite(inpA1, LOW);
  digitalWrite(inpB1, HIGH);
  analogWrite(enableA, 65);

  digitalWrite(inpA2, LOW);
  digitalWrite(inpB2, HIGH);
  analogWrite(enableB, 65);
  delay(100);
}

void SHARPRIGHT()
{

  Serial.println("Sharp Right");
  digitalWrite(inpA1, HIGH);
  digitalWrite(inpB1, LOW);
  analogWrite(enableA, 65);

  digitalWrite(inpA2, HIGH);
  digitalWrite(inpB2, LOW);
  analogWrite(enableB, 65);
  delay(100);
}

void STOP()
{
  Serial.println("STOP");
  digitalWrite(inpA1, LOW);
  digitalWrite(inpB1, LOW);


  digitalWrite(inpA2, LOW);
  digitalWrite(inpB2, LOW);

  delay(300);

}

int LEFTWHITE()
{
  int i, count = 0;
  for (i = 0; i < 8; i++)
  {
    if (ReadSensor[i] == 1)break;
    else count++;
  }
  return count;
}

int RIGHTWHITE()
{
  int i, count = 0;
  for (i = 7; i >= 0; i--)
  {
    if (ReadSensor[i] == 1)break;
    else count++;
  }
  return count;
}

int LEFTBLACK()
{
  int i, count = 0;
  for (i = 0; i < 8; i++)
  {
    if (ReadSensor[i] == 0)break;
    else count++;
  }
  return count;
}


int RIGHTBLACK()
{
  int i, count = 0;
  for (i = 7; i >= 0; i--)
  {
    if (ReadSensor[i] == 0)break;
    else count++;
  }

  return count;
}

int BLACK()
{
  int i, count = 0;
  for (i = 0; i < 8; i++)
  {
    if (ReadSensor[i] == 1)
      count++;
  }
  return count;
}

int WHITE()
{
  int i, count = 0;
  for (i = 0; i < 8; i++)
  {
    if (ReadSensor[i] == 0)
      count++;
  }
  return count;
}


int MTL()
{
  int i, count = 0;
  for (i = 3; i >= 0; i--)
  {
    if (ReadSensor[i] == 0)break;
    else count++;
  }
  return count;
}


int MTR()
{
  int i, count = 0;
  for (i = 4; i < 8; i++)
  {
    if (ReadSensor[i] == 0)break;
    else count++;
  }
  return count;
}




void BITBACK()
{
  Serial.println("BACK");
  digitalWrite(inpA1, LOW);
  digitalWrite(inpB1, HIGH);
  analogWrite(enableA, 30);

  digitalWrite(inpA2, HIGH);
  digitalWrite(inpB2, LOW);
  analogWrite(enableB, 30);
  delay(20);
}

void ENDFOR() {

  Serial.println("Straighted");
  digitalWrite(inpA1, HIGH);
  digitalWrite(inpB1, LOW);
  analogWrite(enableA, 60);

  digitalWrite(inpA2, LOW);
  digitalWrite(inpB2, HIGH);
  analogWrite(enableB, 60);
  delay(500);
}
void LN()
{
  Serial.println("left");
  digitalWrite(inpA1, LOW);
  digitalWrite(inpB1, HIGH);
  analogWrite(enableA, 65);

  digitalWrite(inpA2, LOW);
  digitalWrite(inpB2, HIGH);
  analogWrite(enableB, 65);

  delay(10);


}
void RN()
{
  Serial.println("Right");
  digitalWrite(inpA1, HIGH);
  digitalWrite(inpB1, LOW);
  analogWrite(enableA, 65);

  digitalWrite(inpA2, HIGH);
  digitalWrite(inpB2, LOW);
  analogWrite(enableB, 65);

  delay(10);



}


void loop()
{
  FILLARRAY();
  Serial.print(q);
  Serial.print("  ");
  
  //Serial.println(distanceCm);
  tot = 0;
  int i;
  for (i = 0; i < 8; i++)
    prev[i] = ReadSensor[i];


  for (i = 0; i < 8; i++)
    pres[i] = ReadSensor[i];

  for (i = 0; i < 8; i++)
    tot += (prev[i] || pres[i]);

 // Serial.print("BACK: ");

  //Serial.println(cw);



  for (int i = 0; i < 8; i++)
  {
    Serial.print(ReadSensor[i]);
    Serial.print(" ");
  }
  /*
  Serial.print("speed: ");

  Serial.println(speed);


  //}
  //Serial.println(BLACK());
  //forward condition
  //Serial.println(LEFTWHITE());
*/
  if (q!=0) {
    
   if(q==1)
   {
    STOP();
        delay(100);
        MOVEFORWARD();
        delay(270);
        RN();
        delay(600);
        q=0;
   }
   else if(q==2)
   {
    STOP();
        delay(100);
        MOVEFORWARD();
        delay(270);
        LN();
        delay(600);
    q=0;
   }
   else if(q==3)
   {
    STOP();
    delay(300);
   }

  }
  else {

  

    if (LEFTBLACK() == 3 && (RIGHTBLACK() == 3  || RIGHTBLACK() == 4))
    {

      STOP();
      delay(300);
      q=3;
    }
    

    else if (RIGHTBLACK() == 3 && (LEFTBLACK() == 3  || LEFTBLACK() == 4))
    {
      STOP();
      delay(300);
      q=3;
    }
    

//if((LEFTBLACK()>=3 && LEFTBLACK()<=4)||(RIGHTBLACK()>=3 && RIGHTBLACK()<=4)){q=3;STOP();delay(300);}
    else if (LEFTWHITE() == 3 && (RIGHTWHITE() == 3  || RIGHTWHITE() == 4))
    {

      MOVEFORWARD();
    }

    else if (RIGHTWHITE() == 3 && (LEFTWHITE() == 3  || LEFTWHITE() == 4))
    {

      MOVEFORWARD();
    }


    else if (BLACK() == 1 || BLACK() == 2)
    {

      if (LEFTWHITE() < 3)MOVELEFT();
      else if (RIGHTWHITE() < 3)MOVERIGHT();
    }


    else if (BLACK() > 2)
    {
      speed = 55;
      cw = 0;
      //Serial.print("f");
      if (LEFTBLACK() >= 7) {
        MOVEFORWARD();
        delay(200);
      }
      else if (RIGHTBLACK() <= 2 && RIGHTBLACK() >= 1) {
        q=1;
        STOP();
        delay(100);
       
      }
      else if (LEFTBLACK() <= 2 && LEFTBLACK() >= 1) {
        q=2;
        STOP();
       }

      else if (MTL() >= 2) {
        int f = BLACK();
        int h = 0;
        for (int i = 0; i < 12; i++)
        {
          MOVELEFT();
          delay(5);
          FILLARRAY();
          int g = BLACK();
          if (g > h)h = g;
        }


        if (h > f)
          MOVEFORWARD();
        else
          MOVELEFT();

      }
      else if (MTR() >= 2) {
        int f = BLACK();
        int h = 0;
        for (int i = 0; i < 12; i++)
        {
          MOVERIGHT();
          delay(5);
          FILLARRAY();
          int g = BLACK();
          if (g > h)h = g;
        }


        if (h > f)
          MOVEFORWARD();

        else

          MOVERIGHT();

      }
      else if (tot >= 7 || LEFTBLACK() >= 7 || RIGHTBLACK() >= 7 || (LEFTBLACK() != BLACK()) || (RIGHTBLACK() != BLACK()) || (BLACK() >= 5 && (ReadSensor[0] == 0 && ReadSensor[7] == 0 ))) {
        Serial.print(tot);
        MOVEFORWARD();
      }

      else if (LEFTBLACK() > 2) {
        int f = BLACK();
        int h = 0;
        for (int i = 0; i < 12; i++)
        {
          MOVELEFT();
          delay(5);
          FILLARRAY();
          int g = BLACK();
          if (g > h)h = g;
        }


        if (h > f)
          MOVEFORWARD();
        else
          MOVELEFT();

      }
      else if (RIGHTBLACK() > 2) {
        int f = BLACK();
        int h = 0;
        for (int i = 0; i < 12; i++)
        {
          MOVERIGHT();
          delay(5);
          FILLARRAY();
          int g = BLACK();
          if (g > h)h = g;
        }


        if (h > f)
          MOVEFORWARD();

        MOVERIGHT();

      }

    }
    else if (WHITE() == 8) {
     
        BACK();
      
    }


  }
}







void loop()
{
  FILLARRAY();
  Serial.print(q);
  Serial.print("  ");
  
  //Serial.println(distanceCm);
  tot = 0;
  int i;
  for (i = 0; i < 8; i++)
    prev[i] = ReadSensor[i];


  for (i = 0; i < 8; i++)
    pres[i] = ReadSensor[i];

  for (i = 0; i < 8; i++)
    tot += (prev[i] || pres[i]);

 // Serial.print("BACK: ");

  //Serial.println(cw);



  for (int i = 0; i < 8; i++)
  {
    Serial.print(ReadSensor[i]);
    Serial.print(" ");
  }
  /*
  Serial.print("speed: ");

  Serial.println(speed);


  //}
  //Serial.println(BLACK());
  //forward condition
  //Serial.println(LEFTWHITE());
*/
  if (q!=0) {
    
   if(q==1)
   {
    STOP();
        delay(100);
        MOVEFORWARD();
        delay(270);
        RN();
        delay(600);
        q=0;
   }
   else if(q==2)
   {
    STOP();
        delay(100);
        MOVEFORWARD();
        delay(270);
        LN();
        delay(600);
    q=0;
   }
   else if(q==3)
   {
    STOP();
    delay(300);
   }

  }
  else {
    if (LEFTBLACK() == 3 && (RIGHTBLACK() == 3  || RIGHTBLACK() == 4))
    {

      STOP();
      delay(300);
      q=3;
    }
    

    else if (RIGHTBLACK() == 3 && (LEFTBLACK() == 3  || LEFTBLACK() == 4))
    {
      STOP();
      delay(300);
      q=3;
    }
//if((LEFTBLACK()>=3 && LEFTBLACK()<=4)||(RIGHTBLACK()>=3 && RIGHTBLACK()<=4)){q=3;STOP();delay(300);}
    else if (LEFTWHITE() == 3 && (RIGHTWHITE() == 3  || RIGHTWHITE() == 4))
    {

      MOVEFORWARD();
    }
    else if (RIGHTWHITE() == 3 && (LEFTWHITE() == 3  || LEFTWHITE() == 4))
    {

      MOVEFORWARD();
    }
    else if (BLACK() == 1 || BLACK() == 2)
    {
      if (LEFTWHITE() < 3)MOVELEFT();
      else if (RIGHTWHITE() < 3)MOVERIGHT();
    }
    else if (BLACK() > 2)
    {
      speed = 55;
      cw = 0;
      //Serial.print("f");
      if (LEFTBLACK() >= 7) {
        MOVEFORWARD();
        delay(200);
      }
      else if (RIGHTBLACK() <= 2 && RIGHTBLACK() >= 1) {
        q=1;
        STOP();
        delay(100);
      }
      else if (LEFTBLACK() <= 2 && LEFTBLACK() >= 1) {
        q=2;
        STOP();
       }
      else if (MTL() >= 2) {
        int f = BLACK();
        int h = 0;
        for (int i = 0; i < 12; i++)
        {
          MOVELEFT();
          delay(5);
          FILLARRAY();
          int g = BLACK();
          if (g > h)h = g;
        }
        if (h > f)
          MOVEFORWARD();
        else
          MOVELEFT();
      }
      else if (MTR() >= 2) {
        int f = BLACK();
        int h = 0;
        for (int i = 0; i < 12; i++)
        {
          MOVERIGHT();
          delay(5);
          FILLARRAY();
          int g = BLACK();
          if (g > h)h = g;
        }
        if (h > f)
          MOVEFORWARD();
        else
          MOVERIGHT();
      }
      else if (tot >= 7 || LEFTBLACK() >= 7 || RIGHTBLACK() >= 7 || (LEFTBLACK() != BLACK()) || (RIGHTBLACK() != BLACK()) || (BLACK() >= 5 && (ReadSensor[0] == 0 && ReadSensor[7] == 0 ))) {
        Serial.print(tot);
        MOVEFORWARD();
      }
      else if (LEFTBLACK() > 2) {
        int f = BLACK();
        int h = 0;
        for (int i = 0; i < 12; i++)
        {
          MOVELEFT();
          delay(5);
          FILLARRAY();
          int g = BLACK();
          if (g > h)h = g;
        }
        if (h > f)
          MOVEFORWARD();
        else
          MOVELEFT();
      }
      else if (RIGHTBLACK() > 2) {
        int f = BLACK();
        int h = 0;
        for (int i = 0; i < 12; i++)
        {
          MOVERIGHT();
          delay(5);
          FILLARRAY();
          int g = BLACK();
          if (g > h)h = g;
        }
        if (h > f)
          MOVEFORWARD();
        MOVERIGHT();
      }
    }
    else if (WHITE() == 8) {
        BACK(); 
    }
  }
}








