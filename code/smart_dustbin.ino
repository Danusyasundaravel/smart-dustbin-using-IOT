 #include <ESP8266WiFi.h>
#include <Servo.h>
const int trigPin = D5;
const int echoPin = D6;
long duration;
int distance;
int count=0;
void send_event (const char *event,int count);
float level;
Servo servo;
const char* ssid = "Redmi Note 8 Pro";
const char* password = "danu@0911";
const char *host = "maker.ifttt.com";
const char *privateKey = "bqPwvQF0LCgdnMEyeitfh_";
WiFiServer server(80);
void setup()
{
Serial.begin(9600);
servo.attach(2); //D4
servo.write(0);
delay(2000);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.print("Connecting to Wifi Network: ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("Successfully connected to WiFi.");
server.begin();
Serial.println("Server started");
}
void loop()
{
if(digitalRead(D3)==LOW)
{
Serial.println("Obstacle");
servo.write(180);
servo.write(180);
delay(10000);
servo.write(0);
delay(1000);
}
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.0340 / 2;
Serial.println("Distance");
Serial.println(distance);
level =((25 -distance)/25.0)*100;
Serial.println("level");
Serial.println(level);
delay(1000);
if ( level >= 70)
{
count=count+1;
send_event("dustbin_event",count);
}
else
{
count=0;
}
Serial.println("count:");
Serial.println(count);
delay(100);
}
void send_event(const char *event, int count)
{
if(count==1)
{
Serial.print("Connecting to ");
Serial.println(host);
// Use WiFiClient class to create TCP connections
WiFiClient client;
const int httpPort = 80;
if (!client.connect(host, httpPort))
{
Serial.println("Connection failed");
return;
}
// We now create a URI for the request
String url = "/trigger/";
url += event;
url += "/with/key/";
url += privateKey;
Serial.print("Requesting URL: ");
Serial.println(url);
count+=1;
// This will send the request to the server
client.print(String("GET ") + url + " HTTP/1.1\r\n" +
"Host: " + host + "\r\n" +
"Connection: close\r\n\r\n");
while(client.connected())
{
if(client.available())
{
String line = client.readStringUntil('\r');
Serial.print(line);
}
else
{
// No data yet, wait a bit
delay(50);
}
}
Serial.println();
Serial.println("closing connection");
client.stop();
}
}
