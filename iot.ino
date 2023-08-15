abc

#include <MakerKit.h>
#include <ESP32Servo.h>

#define BLYNK_TEMPLATE_ID           "TMPL6FQgF-y2Z"
#define BLYNK_DEVICE_NAME           "Iot"
#define BLYNK_AUTH_TOKEN            "9qsMEq30jIDQNn4Hcw_E6jLV55w_98_g"


#define BLYNK_PRINT Serial
dalam main main main


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "GRANADA";
char pass[] = "";
#include <Adafruit_NeoPixel.h>
 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(5, 4, NEO_GRB + NEO_KHZ800);

BLYNK_WRITE(V0)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0xff0000);
    pixels.setPixelColor(1, 0xff0000);
    pixels.setPixelColor(2, 0xff0000);
    pixels.setPixelColor(3, 0xff0000);
    pixels.setPixelColor(4, 0xff0000);
    pixels.show();
    pixels.show();

  }
}

Servo x;

Servo servo_5;
BlynkTimer Timer1;

void Timer1_TimerEvent()
{
  Blynk.virtualWrite(V20, ultrasonic(12,27));
  Blynk.virtualWrite(V21, analogRead(36));
  if (ultrasonic(12,27) < 10) {
    servo_5.write(90);

  } else {
    servo_5.write(0);

  }
}


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pixels.begin();

  pinMode(36, INPUT);
  servo_5.attach(5);

}

void loop() {
  Blynk.run();
  Timer1.run();
}