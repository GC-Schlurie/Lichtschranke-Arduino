
#include <Servo.h>
#include <SoftwareSerial.h>
#include <JQ6500_Serial.h>

Servo myservo;  // create servo object to control a servo
JQ6500_Serial mp3(5,6);


int SensorAnalog=A1; // Das Sensormodul wird mit dem analogen Ausgang an Pin A1 des Arduino angeschlossen
int Wert1; // Erstellen einer Variablen mit dem Namen "Wert1", unter dem die Messwerte gespeichert werden.





void setup() {
 
  Serial.begin(9600);
  
  mp3.begin(9600);
  mp3.reset();
  mp3.setVolume(20);
  //mp3.setLoopMode(MP3_LOOP_NONE);
 // mp3.setEqualizer(MP3_EQ_BASS);
  
 
  
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
  
myservo.write(1);

}

void loop() {
    Wert1=analogRead(SensorAnalog); // check if photo sensor <=50, the buttonState is LOW:
    Serial.println(Wert1);             // Der Wert wird an den Serial Monitor gesendet.
    if (Wert1<=500)  {
        
        mp3.playFileByIndexNumber(1);  
        delay (1000);
        myservo.write(100);
        delay (800);
        myservo.write(1);   
        
     }
     
}
