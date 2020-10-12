#define right_f 2
#define right_b 3
#define left_f 4
#define left_b 5
#define ch2 11
#define ch4 10

int val2,val4;

void setup() {
  pinMode(right_f, OUTPUT);
  pinMode(right_b, OUTPUT);
  pinMode(left_f, OUTPUT);
  pinMode(left_b, OUTPUT);
  pinMode(ch2,INPUT);
  pinMode(ch4,INPUT);
  motor_stop();
  Serial.begin(9600);

}

void loop() {
  val2 = pulseIn(ch2,HIGH);
  val4 = pulseIn(ch4,HIGH);
  Serial.print("ch2 --- ");
  Serial.println(val2);
  Serial.print("ch4 --- ");
  Serial.println(val4);
  Serial.println(); 
  if(val2<1600 && val2>1200){
    if(val4<1600 && val4>1200){
      Serial.println("---------Stop---------");
      motor_stop();
    }
    else if(val4>1600){
      Serial.println("---------right---------");
      motor_turn_right();
    }
    else if(val4<1200){
      Serial.println("---------left---------");
      motor_turn_left();
    }
    else
      Serial.println("bandwidth lost");
   }
  else if(val2>1600){
    Serial.println("---------forward---------");
    motor_forward();
  }
  else if(val2<1200){
    Serial.println("---------back---------");
    motor_back();
  }
  else
    Serial.println("bandwidth lost");
}

void motor_stop(){
  digitalWrite(right_f,HIGH);
  digitalWrite(right_b,HIGH);
  digitalWrite(left_f,HIGH);
  digitalWrite(left_b,HIGH);
}

void motor_forward(){
  digitalWrite(right_f,HIGH);
  digitalWrite(right_b,LOW);
  digitalWrite(left_f,HIGH);
  digitalWrite(left_b,LOW);
}

void motor_back(){
  digitalWrite(right_f,LOW);
  digitalWrite(right_b,HIGH);
  digitalWrite(left_f,LOW);
  digitalWrite(left_b,HIGH);
}

void motor_turn_right(){
  digitalWrite(right_f,HIGH);
  digitalWrite(right_b,LOW);
  digitalWrite(left_f,LOW);
  digitalWrite(left_b,HIGH);
}
void motor_turn_left(){
  digitalWrite(right_f,LOW);
  digitalWrite(right_b,HIGH);
  digitalWrite(left_f,HIGH);
  digitalWrite(left_b,LOW);
}

