/*
  Project: Blink configurable
  Description: Fa parpellejar un LED connectat al pin 23.
               El temps d'encesa i el d'apagat es poden canviar
               amb dues variables.
*/

// Definim una constant per al pin on hem connectat el LED
const int LED_PIN = 23;

// Variables per configurar els temps (en mil·lisegons)
long tempsEncès = 1000;   // Temps que el LED està encès (1 segon)
long tempsApagat = 500;   // Temps que el LED està apagat (0,5 segons)

// La funció setup() s'executa un cop quan la placa arrenca
void setup() {
  // Configurem el pin del LED com una SORTIDA (OUTPUT)
  pinMode(LED_PIN, OUTPUT);
}

// La funció loop() s'executa contínuament
void loop() {
  digitalWrite(LED_PIN, HIGH);  // Envia 3.3V al pin (encén el LED)
  delay(tempsEncès);            // Espera el temps d'encesa

  digitalWrite(LED_PIN, LOW);   // Envia 0V al pin (apaga el LED)
  delay(tempsApagat);           // Espera el temps d'apagat
}