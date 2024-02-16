#define PIN_LEN 8

class Light {
  uint8_t pins[PIN_LEN] = { 2, 3, 4, 5, 6, 7, 8, 9 };
  bool one[PIN_LEN] = { 0, 1, 0, 0, 1, 0, 0, 0 };
  bool two[PIN_LEN] = { 0, 0, 1, 1, 1, 1, 0, 1 };

public:
  void Flush() {
    for (uint8_t &i : pins) {
      digitalWrite(i, HIGH);
    }
  }

  Light() {
    for (uint8_t &i : pins) {
      pinMode(i, OUTPUT);
    }
    Flush();
  }

  void LightAll() {
    for (uint8_t &i : pins) {
      digitalWrite(i, LOW);  // anode
    }
  }

  void LightFromBitset(bool bitset[]) {
    for (uint8_t i = 0; i < PIN_LEN; i++) {
      if (bitset[i]) {
        digitalWrite(pins[i], LOW);
      }
    }
  }

  void FloatingPoint() {
    digitalWrite(pins[0], LOW);
  }

  void One() {
    LightFromBitset(one);
  }

  void Two() {
    LightFromBitset(two);
  }
};

Light light;

void setup() {
}

void loop() {
  light.One();
  delay(500);
  light.Flush();
  light.Two();
  delay(500);
  light.Flush();
}
