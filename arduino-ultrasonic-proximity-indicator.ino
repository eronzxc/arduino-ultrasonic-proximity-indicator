// Mga Pins ng Ultrasonic
const int trgPin = 9;     
const int echPin = 10;    

// Mga Pins ng LEDs
const int greenLed = 5;
const int yellowLed = 6;
const int redLed = 7;

void setup() {
  Serial.begin(9600);
  
  // Setup ng I/O
  pinMode(trgPin, OUTPUT);
  pinMode(echPin, INPUT);
  
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  // Direkta agad ang pagkuha ng distansya mula sa scratch function sa ilalim
  long distance = getDistance();
  
  // Siguraduhing may tamang basa ang sensor
  if (distance > 0) {
    
    // 🔴 DANGER ZONE: Mas malapit sa 10cm
    if (distance < 10) {
      digitalWrite(redLed, HIGH);
      digitalWrite(yellowLed, LOW);
      digitalWrite(greenLed, LOW);
      Serial.println("DANGER! Distance: " + String(distance) + "cm");
    } 
    // 🟡 WARNING ZONE: Gitna ng 10cm hanggang 20cm
    else if (distance >= 10 && distance < 20) {
      digitalWrite(redLed, LOW);
      digitalWrite(yellowLed, HIGH);
      digitalWrite(greenLed, LOW);
      Serial.println("WARNING! Distance: " + String(distance) + "cm");
    } 
    // 🟢 SAFE ZONE: Gitna ng 20cm hanggang 35cm
    else if (distance >= 20 && distance <= 35) {
      digitalWrite(redLed, LOW);
      digitalWrite(yellowLed, LOW);
      digitalWrite(greenLed, HIGH);
      Serial.println("SAFE! Distance: " + String(distance) + "cm");
    }
    // Kung sobrang layo na sa 35cm, patayin muna lahat
    else {
      turnAllLedsOff();
    }
  }
  
  delay(150); // Mas mabilis na refresh rate (150ms) para mas ramdam mo ang real-time response!
}

void turnAllLedsOff() {
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, LOW);
}

long getDistance() {
  digitalWrite(trgPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trgPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trgPin, LOW);
  
  long duration = pulseIn(echPin, HIGH);
  long cm = duration / 29.1 / 2;
  
  return cm;
}