#define ch2 11
#define ch4 10
#define ch6 9

int val2,val4,val6;
void setup() {
  pinMode(ch2,INPUT);
  pinMode(ch4,INPUT);
  pinMode(ch6,INPUT);
  Serial.begin(9600);
}

void loop() {
  val2 = pulseIn(ch2,HIGH);
  val4 = pulseIn(ch4,HIGH);
  val6 = pulseIn(ch6,HIGH);
  Serial.print("ch2 --- ");
  Serial.println(val2);
  Serial.print("ch4 --- ");
  Serial.println(val4);
  Serial.print("ch6 --- ");
  Serial.println(val6);
  Serial.println();     
}

