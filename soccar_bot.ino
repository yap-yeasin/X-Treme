#define lbmotorP 2
#define lbmotorN 3
#define rbmotorP 4
#define rbmotorN 5

int ch3,ch1;

void setup() {
  pinMode(lbmotorP, OUTPUT);
  pinMode(lbmotorN, OUTPUT);
  pinMode(rbmotorP, OUTPUT);
  pinMode(rbmotorN, OUTPUT);
  pinMode(11,INPUT); //Ch3 forward/back
  pinMode(10,INPUT); //ch1 left/right                                                                                                                
  Serial.begin(9600);
  motor_stop();

}

void motor_stop(){
  digitalWrite(lbmotorP,LOW);
  digitalWrite(lbmotorN,LOW);
  digitalWrite(rbmotorP,LOW);
  digitalWrite(rbmotorN,LOW);
}

void motor_forward(){
  digitalWrite(lbmotorP,HIGH);
  digitalWrite(lbmotorN,LOW);
  digitalWrite(rbmotorP,HIGH);
  digitalWrite(rbmotorN,LOW);
}

void motor_back(){
  digitalWrite(lbmotorP,LOW);
  digitalWrite(lbmotorN,HIGH);
  digitalWrite(rbmotorP,LOW);
  digitalWrite(rbmotorN,HIGH);
}


void motor_right(){
  digitalWrite(lbmotorP,HIGH);
  digitalWrite(lbmotorN,LOW);
  digitalWrite(rbmotorP,LOW);
  digitalWrite(rbmotorN,HIGH);

}

void motor_forward_right(){
  digitalWrite(lbmotorP,HIGH);
  digitalWrite(lbmotorN,LOW);
  digitalWrite(rbmotorP,LOW);
  digitalWrite(rbmotorN,LOW);
}

void motor_left(){
  digitalWrite(lbmotorP,LOW);
  digitalWrite(lbmotorN,HIGH);
  digitalWrite(rbmotorP,HIGH);
  digitalWrite(rbmotorN,LOW);
}

void motor_forward_left(){
  digitalWrite(lbmotorP,LOW);
  digitalWrite(lbmotorN,LOW);
  digitalWrite(rbmotorP,HIGH);
  digitalWrite(rbmotorN,LOW);
}


void loop() {
  ch3 = pulseIn(11,HIGH); //Ch3
  ch1 = pulseIn(10,HIGH); //Ch1

  if((ch1<1700 && ch1>1330) && (ch3<1600 && ch3>1350)){
    motor_stop();
  }
  else if(ch3>1600){
    if(ch1<1700 && ch1>1330)
      motor_forward();
    else if(ch1>1700) 
      motor_forward_right();
    else if(ch1<1350) 
      motor_forward_left();
  }
  else if(ch3<1350){
    if(ch1<1700 && ch1>1330)
      motor_back();
    else if(ch1>1700) 
      motor_forward_right();
    else if(ch1<1350) 
      motor_forward_left();
  }
  else if(ch1>1700) 
    motor_right();
  else if(ch1<1350) 
    motor_left();
  else Serial.println("Something is wrong");

  
//  if(ch3<1600 && ch3>1350) {
//    ch1 = pulseIn(10,HIGH); //Ch1
//    
//    if(ch1<1700 && ch1>1330) {
//      motor_stop();
//    }
//    else if(ch1>1700) {
//      motor_right();
//    }
//    else if(ch1<1350) {
//      motor_left();    
//    }
//    else Serial.println("Something is wrong on the turn control");
//    
//    ch3 = pulseIn(11,HIGH); //Ch2
//    
//  }
//  else if(ch3>1600) {
//    motor_forward();
//  }
//  else if(ch3<1350) {
//    motor_back();
//  }
//  else Serial.println("Something is wrong");
//

}
