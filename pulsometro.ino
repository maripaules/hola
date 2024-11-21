#include <Wire.h>

void setup() {
    Serial.begin(115200);
    delay(1000); // Esperar para inicializar el monitor serie

    // Configura los pines SDA y SCL personalizados si no son los predeterminados
    Wire.begin(21, 22); // Cambia 4 (SDA) y 5 (SCL) por los pines que estés usando

    Serial.println("Iniciando escáner I2C...");
}

void loop() {
    byte count = 0;

    Serial.println("Escaneando dispositivos I2C...");

    for (byte address = 1; address < 127; address++) {
        Wire.beginTransmission(address);
        byte error = Wire.endTransmission();

        if (error == 0) {
            Serial.print("Dispositivo encontrado en la dirección 0x");
            Serial.println(address, HEX);
            count++;
        }
    }

    if (count == 0) {
        Serial.println("No se encontraron dispositivos I2C.");
    } else {
        Serial.print("Se encontraron ");
        Serial.print(count);
        Serial.println(" dispositivo(s) I2C.");
    }

    delay(5000); // Escanea cada 5 segundos
}
