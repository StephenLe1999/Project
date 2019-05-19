int trigPin = A0;
int echoPin = A1;
char DistanceM[10];
int led = D0;

long duration;
int distance;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(led, OUTPUT);
    
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    Particle.variable("distance", distance);
    sprintf(DistanceM, "%d", distance);
    Particle.publish("distance", DistanceM, PRIVATE);
    
    delay(5000);
    
    if (distance <= 6) {
        digitalWrite(led, HIGH);
    }
    
    else if (distance >= 6) {
        digitalWrite(led, LOW);
    }
}