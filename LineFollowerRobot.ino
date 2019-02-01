// LINE FOLLOWER ROBOT PROGRAM
// By: Shubham Kumar

int S1=0,S2=0,S3=0,S4=0,S5=0;
char mem;
void setup() {
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
pinMode(A5,INPUT);

//RIGHT Wheel
pinMode(2,OUTPUT);//MA1
pinMode(3,OUTPUT);//MA2
pinMode(9,OUTPUT);//ENA
//LEFT Wheel
pinMode(6,OUTPUT);//MB1
pinMode(7,OUTPUT);//MB2
pinMode(10,OUTPUT);//ENB
}

void loop() {
  S1=digitalRead(A1);
  S2=digitalRead(A2);
  S3=digitalRead(A3);
  S4=digitalRead(A4);
  S5=digitalRead(A5);
    
    
    if(S1+S2+S3+S4+S5==5)
    {
      if(mem='l')//last seen by Left sensor
      {//spin left
    //left wheel back
      analogWrite(10,255);
      digitalWrite(6,1);
      digitalWrite(7,0);
    //right wheel forward
      analogWrite(9,255);
      digitalWrite(2,0);
      digitalWrite(3,1);        
        }
        else if(mem='r')//last seen by Right sensor
        {//spin right
    //left wheel forward
         analogWrite(10,255);
         digitalWrite(6,0);
         digitalWrite(7,1);
    //right wheel back
          analogWrite(9,255);
          digitalWrite(2,1);
          digitalWrite(3,0);
          }
      }
       
     else if(S1+S2+S3+S4==4)//left to cental sensors detecting
  {//spin left
  //left wheel STOP
    analogWrite(10,0);
    digitalWrite(6,0);
    digitalWrite(7,0);
  //right wheel forward
    analogWrite(9,255);
    digitalWrite(2,0);
    digitalWrite(3,1);
    }
    
    else if(S2+S3+S4+S5==4)//right to central sensor detecting
  {//spin right
  //left wheel forward
    analogWrite(10,255);
    digitalWrite(6,0);
    digitalWrite(7,1);
  //right wheel STOP
    analogWrite(9,0);
    digitalWrite(2,0);
    digitalWrite(3,0);
    }
    
    else if(S2+S3+S4==3)//CENTRAL sensors detecting
  {//go forward
    analogWrite(10,255);
    digitalWrite(6,0);
    digitalWrite(7,1);
    analogWrite(9,255);
    digitalWrite(2,0);
    digitalWrite(3,1);
    }
    
    else if(S1+S2+S3==3)//left to cental sensors detecting
  {//spin left
  //left wheel back
    analogWrite(10,255);
    digitalWrite(6,1);
    digitalWrite(7,0);
  //right wheel forward
    analogWrite(9,255);
    digitalWrite(2,0);
    digitalWrite(3,1);
    }
    
    else if(S3+S4+S5==3)//right to central sensor detecting
  {//spin right
  //left wheel forward
    analogWrite(10,255);
    digitalWrite(6,0);
    digitalWrite(7,1);
  //right wheel back
    analogWrite(9,255);
    digitalWrite(2,1);
    digitalWrite(3,0);
    }

    else if(S2+S3==2)//left & central sensors detecting
  {//spin left
  //left wheel back
    analogWrite(10,255);
    digitalWrite(6,1);
    digitalWrite(7,0);
  //right wheel forward
    analogWrite(9,255);
    digitalWrite(2,0);
    digitalWrite(3,1);
    }
    
    else if(S3+S4==2)//right sensor detecting
  {//spin right
  //left wheel forward
    analogWrite(10,255);
    digitalWrite(6,0);
    digitalWrite(7,1);
  //right wheel back
    analogWrite(9,255);
    digitalWrite(2,1);
    digitalWrite(3,0);
    }
    
    else if(S1==1||S2==1)//left sensor(s) detecting
  { mem='l';
    //spin left
  //left wheel back
    analogWrite(10,255);
    digitalWrite(6,1);
    digitalWrite(7,0);
  //right wheel forward
    analogWrite(9,255);
    digitalWrite(2,0);
    digitalWrite(3,1);
    }
    
    else if(S4==1||S5==1)//right sensor(s) detecting
  { mem='r';
    //spin right
  //left wheel forward
    analogWrite(10,255);
    digitalWrite(6,0);
    digitalWrite(7,1);
  //right wheel back
    analogWrite(9,255);
    digitalWrite(2,1);
    digitalWrite(3,0);
    }

    else if(S3==1)//CENTRAL sensor detecting
  {//go forward
    analogWrite(10,255);
    digitalWrite(6,0);
    digitalWrite(7,1);
    analogWrite(9,255);
    digitalWrite(2,0);
    digitalWrite(3,1);
    }
    
    else
    {//STOP
      delay(1000);
      analogWrite(9,0);
      digitalWrite(2,0);
      digitalWrite(3,0);
      analogWrite(10,0);
      digitalWrite(6,0);
      digitalWrite(7,0);
      }
}
