//  Declarando pines para los dispositivos de salida
const int pinLED = 2;
const int pinBuzzer = 4;

//  Declarando pines para los dispositivos de entrada
const int pinButton = 3;

unsigned long previousTime = 0;

const int timeDelay = 1000;

void setup() {
  //Configuramos pines de Entrada y Salida
  pinMode(pinLED, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);  // Pines de Salida

  pinMode(pinButton, INPUT_PULLUP); // Pin de Entrada
}

void loop() {
  // Hacemos que un LED parpadee
  unsigned long currentTime = millis();
  if (currentTime - previousTime >= timeDelay)
  {
    previousTime = currentTime;
    if (digitalRead(pinLED) == HIGH)
    {
      digitalWrite(pinLED, LOW);
    }
    else
    {
      digitalWrite(pinLED, HIGH);
    }
  }
  // Presionamos un boton y en funcion de eso sonara un buzzer
  if (digitalRead(pinButton) == LOW) // Preguntamos si el boton esta siendo presionado o no
  {
    digitalWrite(pinBuzzer, HIGH); // Si esta presionado suena el Buzzer
  }
  else
  {
    digitalWrite(pinBuzzer, LOW); //  Si no esta presionado o se deja de presionar el Buzzer deja de sonar
  }
}
