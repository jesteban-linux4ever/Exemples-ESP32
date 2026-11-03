
#include <Keypad.h>

// Configuracio del teclat 4x4
const byte FILAS = 4;
const byte COLUMNAS = 4;

// Distribucio de les tecles
char teclas[FILAS][COLUMNAS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connexions ESP32 (ordre de dalt a baix)
byte pinesFilas[FILAS] = {18, 5, 17, 16};
byte pinesColumnas[COLUMNAS] = {4, 0, 2, 15};

// Inicialitzacio del KeyPad
Keypad keypad = Keypad(
  makeKeymap(teclas),
  pinesFilas,
  pinesColumnas,
  FILAS,
  COLUMNAS
);

// Contrasenya correcta
String passwordCorrecto = "1234";

// Contrasenya introduida per l'usuari
String passwordIntroducido = "";

void setup() {
  Serial.begin(9600);

  Serial.println("SISTEMA DE VALIDACIO");
  Serial.println("--------------------");
  Serial.println("Introdueix la contrasenya:");
}

void loop() {

  // Llegir la tecla premuda
  char tecla = keypad.getKey();

  if (tecla) {

    // Introduir un digit
    if (tecla >= '0' && tecla <= '9') {

      if (passwordIntroducido.length() < 4) {
        passwordIntroducido += tecla;

        Serial.print("*");
      }
    }

    // Validar contrasenya amb #
    else if (tecla == '#') {

      if (passwordIntroducido.length() == 4) {

        if (passwordIntroducido == passwordCorrecto) {
          Serial.println("\nACCES PERMES!");
        }
        else {
          Serial.println("\nCONTRASENYA INCORRECTA!");
        }

      }
      else {
        Serial.println("\nHas d'introduir 4 digits!");
      }

      // Esborrar la contrasenya introduida
      passwordIntroducido = "";

      Serial.println("Torna a introduir la contrasenya:");
    }

    // Esborrar amb *
    else if (tecla == '*') {

      passwordIntroducido = "";

      Serial.println("\nContrasenya esborrada.");
      Serial.println("Torna a introduir la contrasenya:");
    }
  }
}
