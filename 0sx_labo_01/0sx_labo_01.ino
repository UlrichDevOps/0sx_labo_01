const int LED_PIN = LED_BUILTIN;
const int DELAY_ALLUME = 2000;
const int DELAY_ETEINT = 2000;
const int CLIGNOTEMENTS = 4;
const int DELAY_CLIGNOTEMENT = 250;
const int BRIGHTNESS_MAX = 255;
const int DELAY_VARIATION = 2048 / BRIGHTNESS_MAX;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // État allumé
  allumer();
  // État clignotement
  clignotement();
  // État variation d'intensité
  variation();
  // État éteint
  eteint();
}

void allumer() {
Serial.println("Allume-2372368");
  digitalWrite(LED_PIN, HIGH);
  delay(DELAY_ALLUME);
}

void clignotement() {
Serial.println("Clignotement-2372368");
  for (int i = 0; i < CLIGNOTEMENTS; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(DELAY_CLIGNOTEMENT);
    digitalWrite(LED_PIN, LOW);
    delay(DELAY_CLIGNOTEMENT);
  }
}

void variation() {
  Serial.println("Variation-2372368");
  for (int brightness = 0; brightness <= BRIGHTNESS_MAX; brightness++) {
    analogWrite(LED_PIN, brightness);
    delay(DELAY_VARIATION);
  }
}

void eteint() {
Serial.println("Éteint-2372368");
  digitalWrite(LED_PIN, LOW);
  delay(DELAY_ETEINT);
}
