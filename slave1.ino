#include <Stepper.h>
#include <string.h>

const int ledPin = 8;
Stepper upStepper1(360, 0, 1, 2, 3);
Stepper upStepper2(360, 0, 1, 2, 3);
Stepper horizontalStepper(360, 0, 1, 2, 3);

Stepper motionStepperLeft(360, 0, 1, 2, 3);
Stepper motionStepperRight(360, 0, 1, 2, 3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
  upStepper1.setSpeed(60);
  upStepper2.setSpeed(60);
  horizontalStepper.setSpeed(60);
  motionStepperLeft.setSpeed(60);
  motionStepperRight.setSpeed(60);
}

char buffer[255];

void blink() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}

void move_forward() {
  
}

void move_backward() {
  
}

void paint() {
  
}

void lift_up_pen() {
  
}

int i = 0;
void loop() {
    if(Serial.available() > 0) {
        char c = Serial.read();
        if(c == '\n') {
          buffer[i] = '\0';

          String message(buffer);

          if(message == "BLINK") {
              blink();
          } else if(message == "MOVE_FORWARD") {
              move_forward();
          } else if(message == "MOVE_BACKWARD") {
              move_backward();
          } else if(message == "PAINT") {
              paint();
          } else if(message == "LIFT_UP_PEN") {
            lift_up_pen();
          } else {
            char* command;
            int displacement;
            i  = 0;

            char *message_c = (char *)message.c_str();
            String space = " ";
            const char *space_c = space.c_str();
            space.c_str();
            command =  strtok (message_c, space_c);
            displacement = atoi(strtok(NULL, space_c));

            Serial.println(command);
            itoa(displacement, buffer, 10);
            Serial.println(buffer);
            
            if(command == "MOVE_UP") {
              upStepper1.step(-1000);
              delay(5000);
            }

            memset (buffer,'0', 255);
              
          }
        } else {
          buffer[i] = c;
          i++;
        }
      }
}
