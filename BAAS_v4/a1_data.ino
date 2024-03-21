// Подключаем модули к контроллеру
#define CALL D0 			 	  	// Подключаем реле к ноге D0
#define SDCARD 15 				  	// SD card
// Библиотеки
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <SPI.h>
#include <SD.h>
#include <GyverPortal.h>          	// конструктор веб интерфейса (https://alexgyver.ru/)
#include <EEPROM.h>               	// стандартная библа для работы с памятью 

// Переменные
bool callFlag = 0;
byte callsec = 0;
byte d, h, m, s;                 	// День недели, часы, минуты, секунды
byte timeCall[6][16][3] = {};    	// Расписание звонков
byte duration;               	// Длительность звонка (мс)
int timeSyn = 30000;             	// Период синхранихации (мс)
unsigned long t;                 	// Переменная для millis() счета времени
unsigned long syn;               	// Переменная для millis() синхранизации
unsigned long rec;               	// Переменная для millis() переподключения
unsigned long calltime;          	// Переменная для millis() подачи звонка
const char *ssid     = "Keenetic-2290";		// Логин к вашему WI-FI
const char *password = "19822111";          // Пароль от WI-FI
byte arduino_mac[] = { 0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
int pagepass = 12345;
int pageadpass = 31122003;
int ifpass = 0;
IPAddress ip(192,168,1,44);			//адрес подключения к плате
IPAddress gateway(192,168,1,1); 	//шлюз(узнать)
IPAddress subnet(255,255,255,0);	//маска подсети
IPAddress dns(1,1,1,1);//днс
File CallFile;

// Инициализация библиотек
GyverPortal ui;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ru.pool.ntp.org", 10800, 60000);
MDNSResponder mdns;
