
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Pantalla OLED
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin del LED
const int LED = 25;

// Variables
int comptador = 0;
bool ledEncès = false;

void setup() {
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Error OLED");
    while (1);
  }

  actualitzarPantalla();
}

void loop() {

  // Encendre LED
  ledEncès = true;
  digitalWrite(LED, HIGH);

  comptador++;

  actualitzarPantalla();

  Serial.print("Encesos: ");
  Serial.println(comptador);

  delay(1000);

  // Apagar LED
  ledEncès = false;
  digitalWrite(LED, LOW);

  actualitzarPantalla();

  delay(1000);
}

void actualitzarPantalla() {

  oled.clearDisplay();

  // Titol
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(25, 5);
  oled.println("ROBOTRONIX");

  oled.drawLine(0, 18, 128, 18, WHITE);

  // Estat del LED
  oled.setCursor(10, 27);

  if (ledEncès) {
    oled.println("LED: ENCES");
  } else {
    oled.println("LED: APAGAT");
  }

  // Comptador
  oled.setCursor(10, 45);
  oled.print("Encesos: ");
  oled.println(comptador);

  oled.display();
}
