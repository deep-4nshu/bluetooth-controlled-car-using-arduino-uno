
int lm1 = 8;
int lm2 = 9;
int rm1 = 10;
int rm2 = 11;
int Front_LED=2;
int Back_LED =4;
int Reverse_LED=3;

void setup()
{
   pinMode(lm1,OUTPUT);
   pinMode(lm2,OUTPUT);
   pinMode(rm1,OUTPUT);
   pinMode(rm2,OUTPUT);
   pinMode(13,OUTPUT);
   digitalWrite(13,HIGH);
   pinMode(Front_LED,OUTPUT);
   pinMode(Back_LED,OUTPUT);
   pinMode(Reverse_LED,OUTPUT);
     
   pinMode(Front_LED,LOW);
   pinMode(Back_LED,LOW);
   pinMode(Reverse_LED,LOW);
   
   Serial.begin(9600);
   Serial.println("hi");
   digitalWrite(Back_LED,HIGH);
   digitalWrite(lm2,LOW);      digitalWrite(rm2,LOW);
   digitalWrite(lm1,LOW);       digitalWrite(rm1,LOW);
   
   delay(250);
   digitalWrite(Back_LED,LOW);
   delay(250);
   digitalWrite(Back_LED,HIGH);
  
}



void loop()

{

 
  while(Serial.available() == 0);
   Serial.println("loop");
  char val = Serial.read() ;//reads the signal
  Serial.println(val);
   /****For Forward motion****/
  
  if (val == 'F')
  {
    Serial.println("FORWARD");
    digitalWrite(lm1,HIGH);  digitalWrite(rm1,HIGH);
    digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
   digitalWrite(Back_LED,LOW);
  digitalWrite(Reverse_LED,LOW);
   
  }

 
    /****For Backward Motion****/
  else if(val == 'B')
  {
  Serial.println("BACK");
  digitalWrite(lm2,HIGH);      digitalWrite(rm2,HIGH);
  digitalWrite(lm1,LOW);       digitalWrite(rm1,LOW);
  digitalWrite(Back_LED,LOW);
  delay(10);
  digitalWrite(Reverse_LED,HIGH);
  //
  
  }
   /****Right****/
  else if(val == 'R')
  {
  Serial.println("RIGHT");
  digitalWrite(lm1,HIGH);      digitalWrite(rm2,LOW);
  digitalWrite(lm2,LOW);       digitalWrite(rm1,LOW);
  digitalWrite(Back_LED,LOW);
  digitalWrite(Reverse_LED,LOW);
  
  }
   /****Left****/
  else if(val == 'L')
  {
   Serial.println("LEFT");
     digitalWrite(lm2,LOW);     digitalWrite(rm1,HIGH);
    digitalWrite(lm1,LOW);       digitalWrite(rm2,LOW);
  digitalWrite(Back_LED,LOW);
  digitalWrite(Reverse_LED,LOW);
  
  }
  /****STOP****/
  else if(val == 'S')
  
  {
  digitalWrite(Back_LED,HIGH);
  Serial.println("Brake!!!");
  Serial.println("Brake Lights ON");
  digitalWrite(lm1,LOW);       digitalWrite(rm1,LOW);
  digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
  digitalWrite(Reverse_LED,LOW);
  
  }
 else if(val == 'K')
  {
  digitalWrite(Front_LED,HIGH);
  Serial.println("Head Lights ON");
  }
  else if (val=='M')
  {
    digitalWrite(Front_LED,LOW);
    Serial.println("Head lights OFF");
  }
  
  }
 
