#include <Servo.h>

// Define the pins for the ultrasonic sensor and servo motor
#define trigPin 9
#define echoPin 10
#define servoPin 11

// Define variables for the ultrasonic sensor
long duration;
int distance;
const int numReadings = 5; // Number of readings to average
int readings[numReadings]; // Array to store the distance readings
int readIndex = 0; // the index of the current reading
int total = 0; // the running total
int averageDistance = 0; // the average distance

Servo myServo;  // Create a servo object to control a servo motor

void setup() {
    // Initialize the ultrasonic sensor pins as outputs or inputs
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    // Initialize the servo motor pin and attach the servo
    myServo.attach(servoPin);

    // Initialize the serial communication for debugging
    Serial.begin(9600);

    // Initialize all the readings to 0
    for (int thisReading = 0; thisReading < numReadings; thisReading++) {
        readings[thisReading] = 0;
    }

    closeLid(); // Start with the lid closed
}



    // If the average distance is less than 20 cm, open the lid of the trash can
    if (averageDistance < 20) {
        openLid();
        delay(3000); // Keep the lid open for 3 seconds
        closeLid();
    }

    // Wait for 50 ms before taking another measurement
    delay(50);
}

void openLid() {
    myServo.write(90); // Adjust this value to match the angle that fully opens your trash can lid
    delay(1000); // Wait for the lid to open
}

void closeLid() {
    myServo.write(0); // Adjust this value to match the angle that fully closes your trash can lid
    delay(1000); // Wait for the lid to close
}
