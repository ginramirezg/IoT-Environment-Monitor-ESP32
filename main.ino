#include <Adafruit_NeoPixel.h>

#define LIGHT_SENSOR_PIN 15 // Pin analógico para el sensor de luz
#define THERMISTOR_PIN 17   // Pin analógico para el termoresistor
#define BUZZER_PIN 4        // Pin del buzzer
#define LED_PIN 48          // Pin del LED RGB integrado
#define BUTTON_PIN 16       // Pin para el botón de reinicio
#define NUMPIXELS 1         // Número de LEDs

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

// Umbrales (ajustar según calibración)
#define TEMPERATURE_THRESHOLD 2010
#define LIGHT_THRESHOLD_DIM 2500
#define LIGHT_THRESHOLD_LIGHT 3000
#define LIGHT_THRESHOLD_BRIGHT 3600

void setup() {
  // Inicializar comunicación serial
  Serial.begin(9600);

  // Configurar la atenuación del ADC
  analogSetAttenuation(ADC_11db);

  // Configurar pines como salida y entrada
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Configurar el botón con resistencia pull-up
  digitalWrite(BUZZER_PIN, LOW);     // Apagar el buzzer inicialmente

  // Inicializar el LED RGB
  pixels.begin();
  pixels.clear(); // Apagar LED al inicio
  pixels.show();

  // Mostrar mensaje de reinicio
  Serial.println("Sistema inicializado. Listo para comenzar.");
}

void loop() {
  static unsigned long lastReadTime = 0; // Tiempo de la última lectura
  static unsigned long debounceTime = 0; // Tiempo para manejar el rebote del botón

  // Leer el estado del botón
  if (digitalRead(BUTTON_PIN) == LOW && millis() - debounceTime > 100) { // Botón presionado y sin rebote
    debounceTime = millis(); // Actualizar el tiempo del último rebote
    Serial.println("Botón presionado: entrando en sueño profundo por 10 segundos...");
    detenerPor10Segundos();
  }

  // Leer sensores cada 500 ms
  if (millis() - lastReadTime >= 500) {
    lastReadTime = millis();

    // Leer el valor del sensor de luz
    int lightValue = analogRead(LIGHT_SENSOR_PIN);
    Serial.print("Light Sensor Value: ");
    Serial.println(lightValue);

    // Leer el valor del termoresistor
    int thermistorValue = analogRead(THERMISTOR_PIN);
    Serial.print("Thermistor Value: ");
    Serial.println(thermistorValue);

    // Comprobar si hay alta temperatura (llama detectada)
    if w
      Serial.println("=> High temperature detected (Flame)");
      digitalWrite(BUZZER_PIN, HIGH); // Activar el buzzer
      setLEDColor(150, 0, 0);         // Encender LED en rojo
    } else {
      // Comprobar la intensidad de luz
      if (lightValue < LIGHT_THRESHOLD_DIM) {
        Serial.println("=> Dark");
        digitalWrite(BUZZER_PIN, LOW); // Apagar el buzzer
        setLEDColor(0, 150, 0);        // LED verde
      } else if (lightValue < LIGHT_THRESHOLD_BRIGHT) {
        Serial.println("=> Light");
        digitalWrite(BUZZER_PIN, LOW); // Apagar el buzzer
        setLEDColor(150, 150, 0);      // LED amarillo
      }
    }
  }
}

// Función para configurar el color del LED RGB
void setLEDColor(int red, int green, int blue) {
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(red, green, blue));
  pixels.show();
}

// Función para activar el modo de sueño profundo con temporizador
void detenerPor10Segundos() {
  setLEDColor(0, 0, 150);   
  Serial.println("Entrando en modo de sueño profundo por 10 segundos...");

  // Configurar el temporizador para 10 segundos (10,000,000 microsegundos)
  esp_sleep_enable_timer_wakeup(10 * 1000000);

  // Entrar en modo de sueño profundo
  esp_deep_sleep_start();
}