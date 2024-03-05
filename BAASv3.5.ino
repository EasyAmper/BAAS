// BAAS v3.5     23.02.24
// Добавлен ввод пароля, код разделен по вкладкам
// отладочные сообщения в порт минимализированы, немного переработаны комментарии к коду

#define AP_SSID "ASUS111"     // имя сети
#define AP_PASS "Vasiliev111" // пароль
#define ZvPin 5             // пин подключения реле 
#define ZVP 12345           // верный пароль
#define FAIL_TIME 500       // период вывода сообщения об ошибке синхронизации в порт
#define SYN_TIME 50000      // период синхронизации времени
#include <EEPROM.h>       // стандартная библа для работы с памятью 
#include <NTPClient.h>    // время из интернета
#include <GyverPortal.h>  // конструктор веб интерфейса (https://alexgyver.ru/)
#include <UnixTime.h>     // для преобразования UNIX в дату (https://github.com/GyverLibs/UnixTime)
GyverPortal ui;
UnixTime stamp(3);   // часовой пояс
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ru.pool.ntp.org", 10800, 60000);

int ZVPass = 0;    // для пароля
byte h, m, s, WD;  // переменные внутреннего времени (часы, минуты, секунды, дни)
byte ZVDEL;        // длительность подачи звонка
bool zvFlag = 0;   // флаг управления подачей звонка (выкрутас для обхода проблем с Delay)
byte PNzvH[16];    // массив часов подачи звонка в Понедельник
byte PNzvM[16];    // массив минут подачи звонка в Понедельник
byte OSTzvH[16];   // массив часов подачи звонка в остальные дни
byte OSTzvM[16];   // массив минут подачи звонка в остальные дни
unsigned long EP;  // для Unix
unsigned long tic; // таймер часов(для тика секунд)
unsigned long syn; // таймер синхронизации
unsigned long rec; // таймер переподключения
