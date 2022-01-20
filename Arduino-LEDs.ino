// C code

int buttonPin = 3;
int ledlist[8] = {4,5,6,7,8,9,10,11};
int count = 0 ;
int counter = 0;
int counter3 = 0;
int counter4 = 0;
int i;
int j;
int binlist[8] = {0,0,0,0,0,0,0,0};
int binlist2[8] = {0,0,0,0,0,0,0,0};
int binlist3[8] = {0,0,0,0,0,0,0,0};
int binlist4[8] = {0,0,0,0,0,0,0,0};
int lastState = 0 ;
int terminal = 0;
int mode;
int modecounter = 0;
int potValue =0;
String input;
String input2;
String space=" ";

void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(A0, INPUT);
  Serial.println("Enter: ");
  Serial.println("1 for Automatic up/down counter");
  Serial.println("2 for Serial display mode");
  Serial.println("3 for POT value display");
  Serial.println("4 for programmable mode");
 
}

void loop()
{
  while (Serial.available()== 0){
  }
  int mode = Serial.parseInt();
  
  while (mode == 1)
  {
    int buttonState = digitalRead(buttonPin);
  Serial.println(count);
  if (buttonState == 1) {
    if (buttonState != lastState) {
      count++;
      if (count >255){
        count = 0;
      }
      lastState = buttonState;
    }
    
  } 
  else {
    if (buttonState != lastState) {
      count++;
      if (count >255){
        count = 0;
      }
      lastState = buttonState;
    }
  }
  

  int counter = count;
  
  for (i=0;i<8;i++){
  binlist[i]=counter%2;
  counter=counter/2;
  }
 
  for (i=0;i<8; i++){
    if (binlist[i] == 1) {
      digitalWrite(ledlist[i],HIGH);
  }
    else {
      digitalWrite(ledlist[i], LOW);
    }
  }
    delay(100);
  }
  while(mode == 2)
  {
    Serial.println("Enter the crap number");
  while(Serial.available() == 0) {
  }
    terminal = Serial.parseInt(); 
    if (terminal>255){
      for(i=0; i<8;i++){
        digitalWrite(ledlist[i],HIGH);
      }
          delay(500);
      for(i=0; i<8;i++){
        digitalWrite(ledlist[i],LOW);
      }
      delay(500);
    }
    else {
    int counter2 = terminal;
  for (i=0; i<8 ;i++){
    binlist2[i]=counter2%2;
    counter2=counter2/2;
  }
   
  for (i=0;i<8; i++){
    if (binlist2[i] == 1) {
      digitalWrite(ledlist[i],HIGH);
  }
    else {
      digitalWrite(ledlist[i], LOW);
    }
  }
    }  
    delay(100);
  }
  
  while(mode == 3)
  {
    int potValue = analogRead(A0);
    potValue = map(potValue, 0, 1023, 0, 255);
    int counter3 = potValue;
    Serial.println(potValue);
  
    for(i=0; i<8; i++)
    {
      binlist3[i] = counter3%2;
      counter3 = counter3/2;
    }
  
  
    for(i=0; i<8; i++)
    {
      if (binlist3[i] == 1)
      {
        digitalWrite(ledlist[i], HIGH);
      }
      if (binlist3[i] == 0)
      {
        digitalWrite(ledlist[i], LOW);
      }
    }
    delay(100);
  }
  
  while(mode == 4){
    
    for (i=0; i<512; i++){
      
      int buttonState = digitalRead(buttonPin);
      while(buttonState == 1){
        while(Serial.available()==0){}
         input = Serial.readString();
        
        if (input=="!p:"){
          Serial.print(input);
        Serial.println(" command is executed");
          while(true){
            buttonState = digitalRead(buttonPin);
            if (buttonState == 1) {break;}
          }}
        else if(input=="!c:"){
          Serial.print(input);
        Serial.println(" command is executed");
          break;}
        else {
          Serial.println("oh crap");
          continue;}
          
        buttonState = digitalRead(buttonPin); 
        if (buttonState == 0 ){break;}
        delay(100);
      }
   
      
      
      
      if(i<256){count++;}
      if(i>255){count--;}
    delay(50);
    Serial.println(count);
      int counter4 = count;
       for (j=0;j<8;j++){
     binlist4[j]=counter4%2;
       counter4=counter4/2;
  }
 
  for (j=0;j<8; j++){
    if (binlist4[j] == 1) {
      digitalWrite(ledlist[j],HIGH);
  }
    else {
      digitalWrite(ledlist[j], LOW);
    }
  }
      
      
    }
  }
}
