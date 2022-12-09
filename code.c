#define sens1_BLUE 8
#define sens1_RED 9
#define sens1_GREEN 10
#define sens1_BUZZER 11

#define sens2_BLUE 4
#define sens2_RED 5
#define sens2_GREEN 6
#define sens2_BUZZER 7

int normalLeak = 420;
int worstleek = 670;

int Value01;
int Value02;

void setup() {
  // put your setup code here, to run once:
    pinMode(sens1_BLUE,OUTPUT);
    pinMode(sens1_RED,OUTPUT);
    pinMode(sens1_GREEN,OUTPUT);
    pinMode(sens1_BUZZER,OUTPUT);

    pinMode(sens2_BLUE,OUTPUT);
    pinMode(sens2_RED,OUTPUT);
    pinMode(sens2_GREEN,OUTPUT);
    pinMode(sens2_BUZZER,OUTPUT);

    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  
        sensorONE();
        sensorTWO();


}

void sensorONE(){


    Value01 = analogRead(A0);
    Serial.print("Sensor one value is : ");    
    Serial.print(Value01);
    Serial.print("      ");
    

    if(Value01 < worstleek  && Value01 >= normalLeak)
    {
        digitalWrite(sens1_BLUE,LOW);
        digitalWrite(sens1_GREEN,LOW);
        digitalWrite(sens1_RED,HIGH);

          int num1 = millis();
          num1 = num1 / 1000;
          if(num1 % 2)
          {
           // Serial.print("|| Sensor one beep is : ");
           // Serial.println(num1);
           // Serial.println("");
            digitalWrite(sens1_BUZZER,HIGH);
          }
          else
          {
            digitalWrite(sens1_BUZZER,LOW);
          }

    }
    else if(Value01 >= worstleek)
    {
        digitalWrite(sens1_BLUE,LOW);
        digitalWrite(sens1_GREEN,LOW);
        digitalWrite(sens1_RED,HIGH);

        digitalWrite(sens1_BUZZER,HIGH);
    }
    else{

        digitalWrite(sens1_BLUE,LOW);;
        digitalWrite(sens1_GREEN,HIGH);
        digitalWrite(sens1_RED,LOW);

        digitalWrite(sens1_BUZZER,LOW);
    }
}


void sensorTWO(){


    Value02 = analogRead(A1);
    Serial.print("Sensor two value is : "); 
    Serial.print(Value02);
    Serial.print(" ");
    
    if(Value02 < worstleek  && Value02 >= normalLeak)
    {
        digitalWrite(sens2_BLUE,LOW);
        digitalWrite(sens2_GREEN,LOW);
        digitalWrite(sens2_RED,HIGH);

          int num = millis();
          num = num / 1000;
          if(num % 2)
          {
           // Serial.print("|| Sensor two beep is : ");
           // Serial.println(num);
           // Serial.println("");
            digitalWrite(sens2_BUZZER,HIGH);
          }
          else
          {
            digitalWrite(sens2_BUZZER,LOW);
          }

    }
    else if(Value02 >= worstleek)
    {
        digitalWrite(sens2_BLUE,LOW);
        digitalWrite(sens2_GREEN,LOW);
        digitalWrite(sens2_RED,HIGH);

        digitalWrite(sens2_BUZZER,HIGH);
    }
    else{

        digitalWrite(sens2_BLUE,LOW);;
        digitalWrite(sens2_GREEN,HIGH);
        digitalWrite(sens2_RED,LOW);

        digitalWrite(sens2_BUZZER,LOW);
    }
    Serial.println("");

}