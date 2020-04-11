// defines pins numbers

const int dirPin  = 3;

const int stepPin = 4;

const int enPin   = 5;



const int switchOne     = 8;

const int switchTwo     = 9;



int p1buttonState = 0;         // current state of the button

int lastp1buttonState = 0;     // previous state of the button



int p2buttonState = 0;         // current state of the button

int lastp2buttonState = 0;     // previous state of the button

bool bPress = false;



bool isForward = false;

bool isBackward = false;



void setup() {



  Serial.begin(9600);

  pinMode( switchOne, INPUT_PULLUP);

  pinMode( switchTwo, INPUT_PULLUP);



  // Sets the two pins as Outputs

  pinMode(stepPin,OUTPUT);

  pinMode(dirPin,OUTPUT);



  pinMode(enPin,OUTPUT);

  digitalWrite(enPin,LOW);



}

void loop() {



   isForward = false;

   isBackward = false;



   p1buttonState = digitalRead(switchOne);

   p2buttonState = digitalRead(switchTwo);



  if (p1ButtonPress()) {



    digitalWrite(dirPin,HIGH);



    delay(5);

  }



    if (p2ButtonPress()) {



      digitalWrite(dirPin,LOW);



      delay(5);

    }



    if( isForward || isBackward ){



      for(int x = 0; x < 800; x++) {

        digitalWrite(stepPin,HIGH);

        delayMicroseconds(500);

        digitalWrite(stepPin,LOW);

        delayMicroseconds(500);

      }

    }

   

}



bool p1ButtonPress()

{

   bool isPress = false;

   // compare the p1buttonState to its previous state

  if (p1buttonState != lastp1buttonState) {

    // if the state has changed, increment the counter

    if (p1buttonState == LOW) {

      // if the current state is HIGH then the button went from off to on:

      bPress = true;

      isPress = true;

      Serial.println("Plaer One score");

   

    } else {

      // if the current state is LOW then the button went from on to off:

      Serial.println("off");

      isForward = true;

    }

    // Delay a little bit to avoid bouncing

    delay(50);

  }

  // save the current state as the last state, for next time through the loop

  lastp1buttonState = p1buttonState;

  return isPress;

}



bool p2ButtonPress()

{

   bool isPress = false;

   // compare the p1buttonState to its previous state

  if (p2buttonState != lastp2buttonState) {

    // if the state has changed, increment the counter

    if (p2buttonState == LOW) {

      // if the current state is HIGH then the button went from off to on:

      bPress = true;

      isPress = true;

      Serial.println("Plaer Two score");

   

    } else {

      // if the current state is LOW then the button went from on to off:

      Serial.println("off");

      isBackward = true;

    }

    // Delay a little bit to avoid bouncing

    delay(50);

  }

  // save the current state as the last state, for next time through the loop

  lastp2buttonState = p2buttonState;

  return isPress;

}
