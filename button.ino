
#define BUTTON_PIN 13
#define DEBOUNCE_TIME 50

// Variables del botó
int lastSteadyState = HIGH;
int lastFlickerableState = HIGH;
int currentState;

// Variable del comptador
int comptador = 0;

unsigned long lastDebounceTime = 0;

void setup() {
  // Inicialitzar comunicació sèrie
  Serial.begin(9600);

  // Configurar el botó amb resistència pull-up
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.println("Comptador de pulsacions iniciat");
  Serial.println("Pulsacions: 0");
}

void loop() {

  // Llegir l'estat del botó
  currentState = digitalRead(BUTTON_PIN);

  // Detectar canvis en el botó
  if (currentState != lastFlickerableState) {
    lastDebounceTime = millis();
    lastFlickerableState = currentState;
  }

  // Aplicar el sistema antirebots (debounce)
  if ((millis() - lastDebounceTime) > DEBOUNCE_TIME) {

    // Detectar una nova pulsació
    if (lastSteadyState == HIGH && currentState == LOW) {

      comptador++;

      Serial.print("Pulsacions: ");
      Serial.println(comptador);
    }

    // Actualitzar l'estat estable
    lastSteadyState = currentState;
  }
}
