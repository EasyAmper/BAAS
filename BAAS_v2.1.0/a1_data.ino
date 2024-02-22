// Подключаем модули к контроллеру
#define CALL D0 // Подключаем реле к ноге D0
#define SDCARD 15 // SD card
// Библиотеки
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <SPI.h>
#include <SD.h>

// Переменные
byte d, h, m, s; // День недели, часы, минуты, секунды
String callStr = "";
int timeCall[6][16][3] = {};// Расписание звонков
int duration = 3000; // Длительность звонка (мс)
int timeSyn = 30000; // Период синхранихации (мс)
unsigned long t; // Переменная для millis() счета времени
unsigned long syn; // Переменная для millis() синхранизации
unsigned long rec; // Переменная для millis() переподключения
const char *ssid     = "Keenetic-2290"; // Логин к вашему WI-FI
const char *password = "19822111"; // Пароль от WI-FI
byte arduino_mac[] = { 0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress ip(192,168,1,44);//адрес подключения к плате
IPAddress gateway(192,168,1,1); //шлюз(узнать)
IPAddress subnet(255,255,255,0);//маска подсети
IPAddress dns(1,1,1,1);//днс
File CallFile;

// Инициализация библиотек
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ru.pool.ntp.org", 10800, 60000);
//NTPClient timeClient(ntpUDP, "ru.pool.ntp.org", 10800+86400+86400, 60000);
MDNSResponder mdns;
