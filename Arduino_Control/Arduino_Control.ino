int serialData = 1;

#define POW 12
#define REL 11
#define CLO 9
#define OPE 8
#define BUZ 4

void setup()
{
  Serial.begin(9600);
  pinMode(POW, OUTPUT);
  pinMode(REL, OUTPUT);
  pinMode(CLO, INPUT_PULLUP);
  pinMode(OPE, INPUT_PULLUP);

  while(digitalRead(CLO)==1){ //Make sure gate is shut
      digitalWrite(REL,0);
      digitalWrite(POW,1);
      delay(1);
    }
    digitalWrite(POW,0);
}

void loop()
{
  digitalWrite(POW,0);
  /*if(digitalRead(CLO)==1){
    digitalWrite(BUZ,1);
  }
  else{
    digitalWrite(BUZ,0);
  }*/
  
  if (Serial.available() > 0)
  {
    serialData = Serial.parseInt();
    Serial.println(serialData);
    
    int i=0;
    for(i=0; i<serialData; i++){
      digitalWrite(REL,1);
      digitalWrite(POW,1);
      while(digitalRead(OPE)==1){
        delay(5);
      }
      digitalWrite(POW,0);
      digitalWrite(REL,0);
      delay(500);
      digitalWrite(POW,1);
      while(digitalRead(CLO)==1){
        delay(5);
      }
      digitalWrite(POW,0);

      delay(1000);
    }
    digitalWrite(POW,0);
    digitalWrite(REL,0);

    serialData=0;
    //Serial.flush();
    //Serial.println("One loop");
    }
}
