#define in1 8
#define in2 9
#define in3 10
#define in4 11
#define enA 6
#define enB 5


 int M1_Speed = 55; // speed of motor 1
 int M2_Speed = 55; // speed of motor 2
 int LeftRotationSpeed = 250;  // Left Rotation Speed
 int RightRotationSpeed = 250; // Right Rotation Speed


 void setup() {

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

    pinMode(enA,OUTPUT);
    pinMode(enB,OUTPUT);

      pinMode(A0, INPUT); // initialize Left sensor as an input
      pinMode(A1, INPUT); // initialize Right sensor as an input

}

void loop() {

  int LEFT_SENSOR = digitalRead(A1);
  int RIGHT_SENSOR = digitalRead(A0);

if(RIGHT_SENSOR==0 && LEFT_SENSOR==0) {
    forward(); //FORWARD
}

  else if(RIGHT_SENSOR==0 && LEFT_SENSOR==1) {
    right(); //Move Right
 }

  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==0) {
    left(); //Move Left
}

  while(RIGHT_SENSOR==1 && LEFT_SENSOR==1) {
    Stop();
    delay(500);
 }
}



void forward()
{
                  analogWrite(enA, M1_Speed);
                analogWrite(enB, M2_Speed);
            digitalWrite(in4, HIGH);
            digitalWrite(in3, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in1, LOW);
}

void right()
{
  analogWrite(enA, LeftRotationSpeed);
  analogWrite(enB, RightRotationSpeed);
            digitalWrite(in4, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in2, HIGH);
            digitalWrite(in1, LOW);
}

void left()
{
  analogWrite(enA, LeftRotationSpeed);
  analogWrite(enB, RightRotationSpeed);
            digitalWrite(in4, HIGH);
            digitalWrite(in3, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in1, HIGH);
}

void Stop()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, LOW);
}
