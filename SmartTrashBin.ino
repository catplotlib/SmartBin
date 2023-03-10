// Define the pins for the ultrasonic sensor and servo motor
#define trigPin 9
#define echoPin 10
#define servoPin 11

// Define variables for the ultrasonic sensor
long duration;
int distance;

void setup()
{
    // Initialize the ultrasonic sensor pins as inputs
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    // Initialize the servo motor pin as an output
    pinMode(servoPin, OUTPUT);

    // Initialize the serial communication for debugging
    Serial.begin(9600);
}

void loop()
{
    // Send a pulse to the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure the duration of the pulse
    duration = pulseIn(echoPin, HIGH);

    // Calculate the distance based on the duration of the pulse
    distance = duration * 0.034 / 2;

    // Debugging output
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // If the distance is less than 20 cm, open the lid of the trash can
    if (distance < 20)
    {
        digitalWrite(servoPin, HIGH);
        delay(1000);
        digitalWrite(servoPin, LOW);
    }

    // Wait for 500 ms before taking another measurement
    delay(500);
}
