//    BAAS - Bell Automatic Activation System      !!!Отладочная версия!!!
//    скетч для проекта BAAS/УАПЗ
//    разработан для платы NodeMcu/ Lolin
//    by EASYAMPER


#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>


byte h, m, s;
unsigned long zv;
int del = 3000;         //   длительность звонка (мс)
unsigned long t;
unsigned long syn;
unsigned long rec;



const char *ssid     = "ASUS111";
const char *password = "Vasiliev111";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ru.pool.ntp.org", 10800, 60000);

void setup() {
  Serial.begin(115200);
  
  
 
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
  timeClient.update();
  h = timeClient.getHours();
  m = timeClient.getMinutes();
  s = timeClient.getSeconds();
 
}

void loop() {
  // блок вывода и самостоятельного счёта времени
  if (millis() - t > 1000) {
    t = millis();
   

    Serial.println("time by internal clock");
    Serial.print(h);
    Serial.print(":");
    Serial.print(m);
    Serial.print(":");
    Serial.println(s);

    s = s + 1;
    if (s == 60) {              // вычисление минут и часов по секундам
      s = 0;                    // в 1ой минуте 60 сек
      m = m + 1;
    }
    if (m == 60) {              // в 1ом часе 60 минут
      m = 0;
      h = h + 1;
    }
    if (h == 24) {             // день в среднем равен 24 часа
      h = 0;
      m = 0;                   //   сброс счётчика , можно добавить
      s = 0;                   //   счёт дней, добавив переменную
    }
  }
  // блок синхронизации (обновление времени)
  if ( WiFi.status() != WL_CONNECTED ) {
    if (millis() - rec > 500) {
      rec = millis();
      Serial.println("synchronization failed");
      //  WiFi.begin(ssid, password);
    }
  } else {
    if (millis() - syn > 30000) {
      syn = millis();
      timeClient.update();
      h = timeClient.getHours();
      m = timeClient.getMinutes();
      s = timeClient.getSeconds();
      Serial.println("successful synchronization");

    }
  }
  // блок подачи звонков
  if (h == 8 && m == 30 && s == 0)zvonok();
  if (h == 9 && m == 15 && s == 0)zvonok();
  if (h == 9 && m == 20 && s == 0)zvonok();
  if (h == 10 && m == 5 && s == 0)zvonok();
  
  if (h == 10 && m == 15 && s == 0)zvonok();
  if (h == 11 && m == 0 && s == 0)zvonok();
  if (h == 11 && m == 5 && s == 0)zvonok();
  if (h == 11 && m == 50 && s == 0)zvonok();
  
  if (h == 12 && m == 30 && s == 0)zvonok();
  if (h == 13 && m == 15 && s == 0)zvonok();
  if (h == 13 && m == 20 && s == 0)zvonok();
  if (h == 14 && m == 5 && s == 0)zvonok();

  if (h == 14 && m == 15 && s == 0)zvonok();
  if (h == 15 && m == 0 && s == 0)zvonok();
  if (h == 15 && m == 5 && s == 0)zvonok();
  if (h == 15 && m == 50 && s == 0)zvonok();
  
}
void zvonok() {
  Serial.println("zvonok !");
  digitalWrite(5, HIGH);

  delay(4000);
  digitalWrite(5, LOW);
  Serial.println("zvonok OFF");
  
}
