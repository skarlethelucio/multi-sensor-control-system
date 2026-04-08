// --- PINES ---
const int releLuz = 2;       // Relé de la luz
const int releTemp = 12;     // Relé de temperatura
const int releAplauso = 3;   // Relé de aplausos
const int ldrPin = A1;       // Sensor de luz (LDR)
const int tempPin = A0;      // Sensor de temperatura (LM35)
const int micPin = 4;        // Sensor de sonido

// --- VARIABLES ---
int valorLuz = 0;
int umbralLuz = 300;   // Ajustado a un rango realista (0–1023)
int countAplauso = 0;
float grad;

void setup() {
  pinMode(releLuz, OUTPUT);
  pinMode(releTemp, OUTPUT);
  pinMode(releAplauso, OUTPUT);
  pinMode(micPin, INPUT);
  pinMode(ldrPin, INPUT);
  
  Serial.begin(9600);

  // Estado inicial del relé de aplauso
  digitalWrite(releAplauso, HIGH);
}

void loop() {

  // --- 1. LÓGICA DE LUZ ---
  valorLuz = analogRead(ldrPin);
  if (valorLuz > umbralLuz) {
    digitalWrite(releLuz, HIGH);
  } else {
    digitalWrite(releLuz, LOW);
  }

  // --- 2. LÓGICA DE TEMPERATURA ---
  int lecturaTemp = analogRead(tempPin);
  grad = (lecturaTemp / 1023.0) * 5.0 * 100.0; // LM35

  if (grad > 30) {
    digitalWrite(releTemp, HIGH);
  } else {
    digitalWrite(releTemp, LOW);
  }

  // --- 3. LÓGICA DE APLAUSOS ---
  int detector = digitalRead(micPin);

  if (detector == LOW) {
    Serial.println("Aplauso detectado");
    countAplauso++;
    delay(300); // Anti-rebote simple
  }

  if (countAplauso == 1) {
    digitalWrite(releAplauso, LOW);
  } 
  else if (countAplauso == 3) {
    digitalWrite(releAplauso, HIGH);
    countAplauso = 0;
  }

  // --- MONITOREO ---
  Serial.print("Luz: "); 
  Serial.print(valorLuz);
  Serial.print(" | Temp: "); 
  Serial.print(grad);
  Serial.print(" °C | Aplausos: "); 
  Serial.println(countAplauso);

  delay(100); // Estabilidad general
}