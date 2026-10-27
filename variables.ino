/*
  ACTIVITAT: Tipus de variables a l'ESP32
  Aquest codi explica, amb comentaris i exemples, els tipus de variables
  que es fan servir en C/C++.

  Sintaxi per declarar una variable:
  [Tipus_de_Dada] [Nom_de_la_Variable] = [Valor_Inicial];
*/

// ---------------------------------------------------------------
// 1. const -> NO és un tipus, és un qualificador.
//    Serveix per dir que el valor NO canviarà mai.
//    S'usa molt per definir els pins del hardware.
// ---------------------------------------------------------------
const int LED_INTERN = 2;      // El LED està connectat al pin GPIO 2
const int PIN_SENSOR = 34;     // Pin on connectem un sensor analògic

// ---------------------------------------------------------------
// 2. int (Integer) -> nombres enters (sense decimals).
//    Ús habitual: comptadors, índexs, números de pin GPIO.
// ---------------------------------------------------------------
int contador = 0;              // Comptador per saber quantes voltes porta el bucle
int lecturaSensor = 0;         // Aquí guardarem el valor llegit del sensor

// ---------------------------------------------------------------
// 3. long (Long Integer) -> nombres enters molt grans.
//    Ús habitual: guardar el temps (millis()) i comptadors molt grans.
// ---------------------------------------------------------------
long tempsEspera = 500;        // Temps d'espera en mil·lisegons (0,5 segons)
long tempsAnterior = 0;        // Per guardar el temps que retorna millis()

// ---------------------------------------------------------------
// 4. float -> nombres amb decimals.
//    Ús habitual: càlculs i valors de sensors (temperatura, voltatge).
// ---------------------------------------------------------------
float temperatura = 23.5;      // Temperatura en graus
float voltatge = 0.0;          // Voltatge calculat a partir de la lectura

// ---------------------------------------------------------------
// 5. char (Character) -> un sol caràcter (lletra o símbol).
//    Va entre cometes simples ' '.
//    Ús habitual: guardar parts d'un text (string).
// ---------------------------------------------------------------
char lletra = 'A';             // Guardem només una lletra
char simbol = '#';             // També pot ser un símbol

// ---------------------------------------------------------------
// 6. bool (Boolean) -> només pot valer true (veritable) o false (fals).
//    Ús habitual: guardar estats (encès/apagat, connectat/desconnectat).
// ---------------------------------------------------------------
bool ledEncens = false;        // Al principi el LED està apagat
bool wifiConnectat = false;    // Encara no estem connectats a la Wi-Fi

void setup() {
  // Iniciem el monitor sèrie per poder veure els valors de les variables
  Serial.begin(115200);

  // pinMode fa servir la variable const del pin
  pinMode(LED_INTERN, OUTPUT);

  // Mostrem cada variable pel monitor sèrie
  Serial.println("--- TIPUS DE VARIABLES ---");

  Serial.print("const int LED_INTERN = ");
  Serial.println(LED_INTERN);

  Serial.print("int contador = ");
  Serial.println(contador);

  Serial.print("long tempsEspera = ");
  Serial.println(tempsEspera);

  Serial.print("float temperatura = ");
  Serial.println(temperatura);

  Serial.print("char lletra = ");
  Serial.println(lletra);

  Serial.print("bool wifiConnectat = ");
  Serial.println(wifiConnectat);
}

void loop() {
  // Variable int: llegim el sensor i ho guardem
  lecturaSensor = analogRead(PIN_SENSOR);

  // Variable float: calculem el voltatge (l'ESP32 llegeix de 0 a 4095 per a 3,3 V)
  voltatge = lecturaSensor * (3.3 / 4095.0);

  // Variable long: guardem el temps en ms des que s'ha encès la placa
  tempsAnterior = millis();

  // Variable bool: canviem l'estat del LED (si era false passa a true i al revés)
  ledEncens = !ledEncens;

  // Fem servir el bool per encendre o apagar el LED
  if (ledEncens) {
    digitalWrite(LED_INTERN, HIGH);   // LED encès
  } else {
    digitalWrite(LED_INTERN, LOW);    // LED apagat
  }

  // Variable int: cada volta del loop sumem 1 al comptador
  contador++;                         // és el mateix que contador = contador + 1;

  // Mostrem els valors que van canviant
  Serial.print("Volta nº: ");
  Serial.print(contador);
  Serial.print(" | Temps (ms): ");
  Serial.print(tempsAnterior);
  Serial.print(" | Voltatge: ");
  Serial.print(voltatge);
  Serial.print(" V | LED: ");
  Serial.println(ledEncens);

  // Variable long dins del delay(): si volem canviar el temps,
  // només cal canviar el valor de dalt, no cada delay().
  delay(tempsEspera);
}