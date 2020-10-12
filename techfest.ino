#define lbmotorP 22
#define lbmotorN 23
#define rbmotorP 24
#define rbmotorN 25
#define lmmotorP 26
#define lmmotorN 27
#define rmmotorP 28
#define rmmotorN 29
#define lfmotorP 30
#define lfmotorN 31
#define rfmotorP 32
#define rfmotorN 33

int ch3,ch1;

void setup() {
  pinMode(lbmotorP, OUTPUT);
  pinMode(lbmotorN, OUTPUT);
  pinMode(rbmotorP, OUTPUT);
  pinMode(rbmotorN, OUTPUT);
  pinMode(lmmotorP, OUTPUT);
  pinMode(lmmotorN, OUTPUT);
  pinMode(rmmotorP, OUTPUT);
  pinMode(rmmotorN, OUTPUT);
  pinMode(lfmotorP, OUTPUT);
  pinMode(lfmotorN, OUTPUT);
  pinMode(rfmotorP, OUTPUT);
  pinMode(rfmotorN, OUTPUT);
  pinMode(11,INPUT); //Ch3 forward/back
  pinMode(10,INPUT); //ch1 left/right                                                                                                                
  Serial.begin(9600);
  motor_stop();

}

void loop() {
  ch3 = pulseIn(11,HIGH); //Ch3
  ch1 = pulseIn(10,HIGH); //Ch1

//  if() auto_attack();
//  else manual_attack();
  
  if(ch3<1600 && ch3>1350) {
    ch1 = pulseIn(10,HIGH); //Ch1
    
    if(ch1<1590 && ch1>1330) {
      motor_stop();
      Serial.println("stop");
    }
    else if(ch1>1590) {
      motor_right();
      Serial.print("Right");
      Serial.print(" ");
      Serial.println(ch1);
    }
    else if(ch1<1350) {
      motor_left();
      Serial.print("Left");
      Serial.print(" ");
      Serial.println(ch1);
      
    }
    else Serial.println("Something is wrong on the turn control");
    
    ch3 = pulseIn(11,HIGH); //Ch2
    
  }
  else if(ch3>1600) {
    motor_forward();
    Serial.print("forward");
    Serial.print(" ");
    Serial.println(ch3);
  }
  else if(ch3<1350) {
    motor_back();
    Serial.print("Back");
    Serial.print(" ");
    Serial.println(ch3);
  }
  else Serial.println("Something is wrong");
}

//void auto_attack(){
//  weapon.write(90);
//  delay(500);
//  weapon.write(170);
//}
//
//void manual_attack(){
//  ch1 = pulseIn(11,HIGH); //Ch1
//  if() weapon.write(90);
//  else weapon.write(170);
//}

void motor_stop(){
  digitalWrite(lbmotorP,LOW);
  digitalWrite(lbmotorN,LOW);
  digitalWrite(rbmotorP,LOW);
  digitalWrite(rbmotorN,LOW);
  digitalWrite(lmmotorP,LOW);
  digitalWrite(lmmotorN,LOW);
  digitalWrite(rmmotorP,LOW);
  digitalWrite(rmmotorN,LOW);
  digitalWrite(lfmotorP,LOW);
  digitalWrite(lfmotorN,LOW);
  digitalWrite(rfmotorP,LOW);
  digitalWrite(rfmotorN,LOW);

}

void motor_forward(){
  digitalWrite(lbmotorP,HIGH);
  digitalWrite(lbmotorN,LOW);
  digitalWrite(rbmotorP,HIGH);
  digitalWrite(rbmotorN,LOW);
  digitalWrite(lmmotorP,HIGH);
  digitalWrite(lmmotorN,LOW);
  digitalWrite(rmmotorP,HIGH);
  digitalWrite(rmmotorN,LOW);
  digitalWrite(lfmotorP,HIGH);
  digitalWrite(lfmotorN,LOW);
  digitalWrite(rfmotorP,HIGH);
  digitalWrite(rfmotorN,LOW);

}

void motor_back(){
  digitalWrite(lbmotorP,LOW);
  digitalWrite(lbmotorN,HIGH);
  digitalWrite(rbmotorP,LOW);
  digitalWrite(rbmotorN,HIGH);
  digitalWrite(lmmotorP,LOW);
  digitalWrite(lmmotorN,HIGH);
  digitalWrite(rmmotorP,LOW);
  digitalWrite(rmmotorN,HIGH);
  digitalWrite(lfmotorP,LOW);
  digitalWrite(lfmotorN,HIGH);
  digitalWrite(rfmotorP,LOW);
  digitalWrite(rfmotorN,HIGH);
}


void motor_right(){
  digitalWrite(lbmotorP,HIGH);
  digitalWrite(lbmotorN,LOW);
  digitalWrite(rbmotorP,LOW);
  digitalWrite(rbmotorN,HIGH);
  digitalWrite(lmmotorP,HIGH);
  digitalWrite(lmmotorN,LOW);
  digitalWrite(rmmotorP,LOW);
  digitalWrite(rmmotorN,HIGH);
  digitalWrite(lfmotorP,HIGH);
  digitalWrite(lfmotorN,LOW);
  digitalWrite(rfmotorP,LOW);
  digitalWrite(rfmotorN,HIGH);
}

void motor_left(){
  digitalWrite(lbmotorP,LOW);
  digitalWrite(lbmotorN,HIGH);
  digitalWrite(rbmotorP,HIGH);
  digitalWrite(rbmotorN,LOW);
  digitalWrite(lmmotorP,LOW);
  digitalWrite(lmmotorN,HIGH);
  digitalWrite(rmmotorP,HIGH);
  digitalWrite(rmmotorN,LOW);
  digitalWrite(lfmotorP,LOW);
  digitalWrite(lfmotorN,HIGH);
  digitalWrite(rfmotorP,HIGH);
  digitalWrite(rfmotorN,LOW);

}

