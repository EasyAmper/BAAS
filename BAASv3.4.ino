// BAAS v3.4     08.02.24
// Усовершенствована подача звонков(delay больше нет), для настройки создан простой веб интерфейс, расписание хранится в энергонезависимой памяти
// последнее редактирование 11.02.2024

#define AP_SSID "ASUS111"    // имя сети
#define AP_PASS "Vasiliev111"   // пароль
#define ZvPin 5     // пин подключения реле 
#define FAIL_TIME 500  // период вывода сообщения об ошибке синхронизации в порт
#define SYN_TIME 30000   // период синхронизации времени
#include <EEPROM.h>  // стандартная библа для работы с памятью 
#include <NTPClient.h>  // время из интернета
#include <GyverPortal.h>   // конструктор веб интерфейса (https://alexgyver.ru/)
#include <UnixTime.h>  // для преобразования UNIX в дату (https://github.com/GyverLibs/UnixTime)
GyverPortal ui;
UnixTime stamp(3);   // часовой пояс
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ru.pool.ntp.org", 10800, 60000);

byte h, m, s, WD;      // переменные внутреннего времени (часы, минуты, секунды, дни)
byte ZVDEL;        // длительность подачи звонка
bool zvFlag = 0;     // флаг управления подачей звонка (выкрутас для обхода проблем с Delay)
byte PNzvH[16];    // массив часов подачи звонка в Понедельник
byte PNzvM[16];    // массив минут подачи звонка в Понедельник
byte OSTzvH[16];   // массив часов подачи звонка в остальные дни
byte OSTzvM[16];   // массив минут подачи звонка в остальные дни
unsigned long EP;  // для Unix
unsigned long tic; //  таймер часов(для тика секунд)
unsigned long syn; // таймер синхронизации
unsigned long rec; // таймер переподключения

void build() {      // отрисовка страницы
  GP.BUILD_BEGIN();
  GP.THEME(GP_DARK);
  GP.PAGE_TITLE("BAAS_Bell_Set");
  GP.TITLE("Настройка звонков");
  GP.HR();
  GP.FORM_BEGIN("/update");
  GP.LABEL("Длительность подачи звонка");
  GP.NUMBER("num", "Секунды", ZVDEL);
  GP.HR();
  GP.LABEL("Понедельник Звонок 1");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num1", "Часы", PNzvH[1]);    //  для удобства, массив использую начиная с 1 а не 0 (плохо, но удобно)
  GP.LABEL("Минуты");
  GP.NUMBER("num2", "Минуты", PNzvM[1]);
  GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 2");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num3", "Часы", PNzvH[2]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num4", "Минуты", PNzvM[2]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 3");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num5", "Часы", PNzvH[3]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num6", "Минуты", PNzvM[3]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 4");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num7", "Часы", PNzvH[4]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num8", "Минуты", PNzvM[4]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 5");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num9", "Часы", PNzvH[5]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num10", "Минуты", PNzvM[5]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 6");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num11", "Часы", PNzvH[6]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num12", "Минуты", PNzvM[6]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 7");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num13", "Часы", PNzvH[7]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num14", "Минуты", PNzvM[7]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 8");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num15", "Часы", PNzvH[8]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num16", "Минуты", PNzvM[8]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 9");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num17", "Часы", PNzvH[9]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num18", "Минуты", PNzvM[9]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 10");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num19", "Часы", PNzvH[10]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num20", "Минуты", PNzvM[10]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 11");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num21", "Часы", PNzvH[11]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num22", "Минуты", PNzvM[11]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 12");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num23", "Часы", PNzvH[12]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num24", "Минуты", PNzvM[12]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 13");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num25", "Часы", PNzvH[13]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num26", "Минуты", PNzvM[13]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 14");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num27", "Часы", PNzvH[14]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num28", "Минуты", PNzvM[14]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 15");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num29", "Часы", PNzvH[15]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num30", "Минуты", PNzvM[15]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 16");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num31", "Часы", PNzvH[16]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num32", "Минуты", PNzvM[16]); GP.BREAK();
  GP.HR();

  GP.HR();
  GP.LABEL("Остальные дни Звонок 1");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num33", "Часы", OSTzvH[1]);    //  все аналогично, только переменные другие
  GP.LABEL("Минуты");
  GP.NUMBER("num34", "Минуты", OSTzvM[1]);
  GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 2");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num35", "Часы", OSTzvH[2]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num36", "Минуты", OSTzvM[2]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 3");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num37", "Часы", OSTzvH[3]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num38", "Минуты", OSTzvM[3]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 4");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num39", "Часы", OSTzvH[4]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num40", "Минуты", OSTzvM[4]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 5");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num41", "Часы", OSTzvH[5]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num42", "Минуты", OSTzvM[5]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 6");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num43", "Часы", OSTzvH[6]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num44", "Минуты", OSTzvM[6]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 7");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num45", "Часы", OSTzvH[7]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num46", "Минуты", OSTzvM[7]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 8");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num47", "Часы", OSTzvH[8]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num48", "Минуты", OSTzvM[8]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 9");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num49", "Часы", OSTzvH[9]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num50", "Минуты", OSTzvM[9]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 10");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num51", "Часы", OSTzvH[10]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num52", "Минуты", OSTzvM[10]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 11");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num53", "Часы", OSTzvH[11]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num54", "Минуты", OSTzvM[11]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 12");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num55", "Часы", OSTzvH[12]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num56", "Минуты", OSTzvM[12]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 13");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num57", "Часы", OSTzvH[13]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num58", "Минуты", OSTzvM[13]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 14");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num59", "Часы", OSTzvH[14]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num60", "Минуты", OSTzvM[14]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 15");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num61", "Часы", OSTzvH[15]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num62", "Минуты", OSTzvM[15]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 16");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num63", "Часы", OSTzvH[16]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num64", "Минуты", OSTzvM[16]); GP.BREAK();
  GP.HR();
  GP.HR();
  GP.SUBMIT("Принять изменения");
  GP.FORM_END();
  GP.HR();
  GP.BREAK();
  GP.BREAK();
  GP.TITLE("Информация");
  GP.SYSTEM_INFO("BAAS_v3.4");
  GP.BUILD_END();
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_SSID, AP_PASS);
  EEPROM.begin(70);    //  организуем работу с памятью(отличается от обычной, только для ESP плат)

  while (WiFi.status() != WL_CONNECTED) {   // если не подключились
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());    // в случае подключения пишем IP

  ui.attachBuild(build);   // подключаем и запускаем конструктор страницы
  ui.attach(action);
  ui.start();

  timeClient.begin();
  timeClient.update();    // получаем время, обновляем переменные
  h = timeClient.getHours();
  m = timeClient.getMinutes();
  s = timeClient.getSeconds();
  stamp.getDateTime(timeClient.getEpochTime());
  WD = stamp.dayOfWeek;

  Serial.println("Reading EEPROM...");  // Чтение расписания из EEPROM
  EEPROM.get(0, ZVDEL);
  EEPROM.get(1, PNzvH[1]);
  EEPROM.get(2, PNzvM[1]);
  EEPROM.get(3, PNzvH[2]);
  EEPROM.get(4, PNzvM[2]);
  EEPROM.get(5, PNzvH[3]);
  EEPROM.get(6, PNzvM[3]);
  EEPROM.get(7, PNzvH[4]);
  EEPROM.get(8, PNzvM[4]);
  EEPROM.get(9, PNzvH[5]);
  EEPROM.get(10, PNzvM[5]);
  EEPROM.get(11, PNzvH[6]);
  EEPROM.get(12, PNzvM[6]);
  EEPROM.get(13, PNzvH[7]);
  EEPROM.get(14, PNzvM[7]);
  EEPROM.get(15, PNzvH[8]);
  EEPROM.get(16, PNzvM[8]);
  EEPROM.get(17, PNzvH[9]);
  EEPROM.get(18, PNzvM[9]);
  EEPROM.get(19, PNzvH[10]);
  EEPROM.get(20, PNzvM[10]);
  EEPROM.get(21, PNzvH[11]);
  EEPROM.get(22, PNzvM[11]);
  EEPROM.get(23, PNzvH[12]);
  EEPROM.get(24, PNzvM[12]);
  EEPROM.get(25, PNzvH[13]);
  EEPROM.get(26, PNzvM[13]);
  EEPROM.get(27, PNzvH[14]);
  EEPROM.get(28, PNzvM[14]);
  EEPROM.get(29, PNzvH[15]);
  EEPROM.get(30, PNzvM[15]);
  EEPROM.get(31, PNzvH[16]);
  EEPROM.get(32, PNzvM[16]);

  EEPROM.get(33, OSTzvH[1]);
  EEPROM.get(34, OSTzvM[1]);
  EEPROM.get(35, OSTzvH[2]);
  EEPROM.get(36, OSTzvM[2]);
  EEPROM.get(37, OSTzvH[3]);
  EEPROM.get(38, OSTzvM[3]);
  EEPROM.get(39, OSTzvH[4]);
  EEPROM.get(40, OSTzvM[4]);
  EEPROM.get(41, OSTzvH[5]);
  EEPROM.get(42, OSTzvM[5]);
  EEPROM.get(43, OSTzvH[6]);
  EEPROM.get(44, OSTzvM[6]);
  EEPROM.get(45, OSTzvH[7]);
  EEPROM.get(46, OSTzvM[7]);
  EEPROM.get(47, OSTzvH[8]);
  EEPROM.get(48, OSTzvM[8]);
  EEPROM.get(49, OSTzvH[9]);
  EEPROM.get(50, OSTzvM[9]);
  EEPROM.get(51, OSTzvH[10]);
  EEPROM.get(52, OSTzvM[10]);
  EEPROM.get(53, OSTzvH[11]);
  EEPROM.get(54, OSTzvM[11]);
  EEPROM.get(55, OSTzvH[12]);
  EEPROM.get(56, OSTzvM[12]);
  EEPROM.get(57, OSTzvH[13]);
  EEPROM.get(58, OSTzvM[13]);
  EEPROM.get(59, OSTzvH[14]);
  EEPROM.get(60, OSTzvM[14]);
  EEPROM.get(61, OSTzvH[15]);
  EEPROM.get(62, OSTzvM[15]);
  EEPROM.get(63, OSTzvH[16]);
  EEPROM.get(64, OSTzvM[16]);

  Serial.println("...OK");
  Serial.println(PNzvH[5]);
  Serial.println(PNzvH[6]);
  Serial.println(PNzvH[7]);
  Serial.println(PNzvH[8]);
  Serial.println(PNzvH[9]);
}

void action() {
  if (ui.form()) {    //  при клике на кнопку ПРИНЯТЬ ИЗМЕНЕНИЯ проверим условия
    if (ui.form("/update")) {     // забираем значения и обновляем переменные
      ZVDEL = ui.getInt("num");
      PNzvH[1] = ui.getInt("num1");
      PNzvM[1] = ui.getInt("num2");
      PNzvH[2] = ui.getInt("num3");
      PNzvM[2] = ui.getInt("num4");
      PNzvH[3] = ui.getInt("num5");
      PNzvM[3] = ui.getInt("num6");
      PNzvH[4] = ui.getInt("num7");
      PNzvM[4] = ui.getInt("num8");
      PNzvM[5] = ui.getInt("num9");
      PNzvM[5] = ui.getInt("num10");
      PNzvH[6] = ui.getInt("num11");
      PNzvM[6] = ui.getInt("num12");
      PNzvH[7] = ui.getInt("num13");
      PNzvM[7] = ui.getInt("num14");
      PNzvH[8] = ui.getInt("num15");
      PNzvM[8] = ui.getInt("num16");
      PNzvH[9] = ui.getInt("num17");
      PNzvM[9] = ui.getInt("num18");
      PNzvM[10] = ui.getInt("num19");
      PNzvM[10] = ui.getInt("num20");
      PNzvH[11] = ui.getInt("num21");
      PNzvM[11] = ui.getInt("num22");
      PNzvH[12] = ui.getInt("num23");
      PNzvM[12] = ui.getInt("num24");
      PNzvH[13] = ui.getInt("num25");
      PNzvM[13] = ui.getInt("num26");
      PNzvH[14] = ui.getInt("num27");
      PNzvM[14] = ui.getInt("num28");
      PNzvH[15] = ui.getInt("num29");
      PNzvM[15] = ui.getInt("num30");
      PNzvH[16] = ui.getInt("num31");
      PNzvM[16] = ui.getInt("num32");

      OSTzvH[1] = ui.getInt("num33");
      OSTzvM[1] = ui.getInt("num34");
      OSTzvH[2] = ui.getInt("num35");
      OSTzvM[2] = ui.getInt("num36");
      OSTzvH[3] = ui.getInt("num37");
      OSTzvM[3] = ui.getInt("num38");
      OSTzvH[4] = ui.getInt("num39");
      OSTzvM[4] = ui.getInt("num40");
      OSTzvH[5] = ui.getInt("num41");
      OSTzvM[5] = ui.getInt("num42");
      OSTzvH[6] = ui.getInt("num43");
      OSTzvM[6] = ui.getInt("num44");
      OSTzvH[7] = ui.getInt("num45");
      OSTzvM[7] = ui.getInt("num46");
      OSTzvH[8] = ui.getInt("num47");
      OSTzvM[8] = ui.getInt("num48");
      OSTzvH[9] = ui.getInt("num49");
      OSTzvM[9] = ui.getInt("num50");
      OSTzvH[10] = ui.getInt("num51");
      OSTzvM[10] = ui.getInt("num52");
      OSTzvH[11] = ui.getInt("num53");
      OSTzvM[11] = ui.getInt("num54");
      OSTzvH[12] = ui.getInt("num55");
      OSTzvM[12] = ui.getInt("num56");
      OSTzvH[13] = ui.getInt("num57");
      OSTzvM[13] = ui.getInt("num58");
      OSTzvH[14] = ui.getInt("num59");
      OSTzvM[14] = ui.getInt("num60");
      OSTzvH[15] = ui.getInt("num61");
      OSTzvM[15] = ui.getInt("num62");
      OSTzvH[16] = ui.getInt("num63");
      OSTzvM[16] = ui.getInt("num64");
      Serial.println("PAGE FORM update -OK");
      Serial.println("Start writing EEPROM");  // Запись EEPROM
      EEPROM.put(0, ZVDEL);
      EEPROM.put(1, PNzvH[1]);
      EEPROM.put(2, PNzvM[1]);
      EEPROM.put(3, PNzvH[2]);
      EEPROM.put(4, PNzvM[2]);
      EEPROM.put(5, PNzvH[3]);
      EEPROM.put(6, PNzvM[3]);
      EEPROM.put(7, PNzvH[4]);
      EEPROM.put(8, PNzvM[4]);
      EEPROM.put(9, PNzvH[5]);
      EEPROM.put(10, PNzvM[5]);
      EEPROM.put(11, PNzvH[6]);
      EEPROM.put(12, PNzvM[6]);
      EEPROM.put(13, PNzvH[7]);
      EEPROM.put(14, PNzvM[7]);
      EEPROM.put(15, PNzvH[8]);
      EEPROM.put(16, PNzvM[8]);
      EEPROM.put(17, PNzvH[9]);
      EEPROM.put(18, PNzvM[9]);
      EEPROM.put(19, PNzvH[10]);
      EEPROM.put(20, PNzvM[10]);
      EEPROM.put(21, PNzvH[11]);
      EEPROM.put(22, PNzvM[11]);
      EEPROM.put(23, PNzvH[12]);
      EEPROM.put(24, PNzvM[12]);
      EEPROM.put(25, PNzvH[13]);
      EEPROM.put(26, PNzvM[13]);
      EEPROM.put(27, PNzvH[14]);
      EEPROM.put(28, PNzvM[14]);
      EEPROM.put(29, PNzvH[15]);
      EEPROM.put(30, PNzvM[15]);
      EEPROM.put(31, PNzvH[16]);
      EEPROM.put(32, PNzvM[16]);

      EEPROM.put(33, OSTzvH[1]);
      EEPROM.put(34, OSTzvM[1]);
      EEPROM.put(35, OSTzvH[2]);
      EEPROM.put(36, OSTzvM[2]);
      EEPROM.put(37, OSTzvH[3]);
      EEPROM.put(38, OSTzvM[3]);
      EEPROM.put(39, OSTzvH[4]);
      EEPROM.put(40, OSTzvM[4]);
      EEPROM.put(41, OSTzvH[5]);
      EEPROM.put(42, OSTzvM[5]);
      EEPROM.put(43, OSTzvH[6]);
      EEPROM.put(44, OSTzvM[6]);
      EEPROM.put(45, OSTzvH[7]);
      EEPROM.put(46, OSTzvM[7]);
      EEPROM.put(47, OSTzvH[8]);
      EEPROM.put(48, OSTzvM[8]);
      EEPROM.put(49, OSTzvH[9]);
      EEPROM.put(50, OSTzvM[9]);
      EEPROM.put(51, OSTzvH[10]);
      EEPROM.put(52, OSTzvM[10]);
      EEPROM.put(53, OSTzvH[11]);
      EEPROM.put(54, OSTzvM[11]);
      EEPROM.put(55, OSTzvH[12]);
      EEPROM.put(56, OSTzvM[12]);
      EEPROM.put(57, OSTzvH[13]);
      EEPROM.put(58, OSTzvM[13]);
      EEPROM.put(59, OSTzvH[14]);
      EEPROM.put(60, OSTzvM[14]);
      EEPROM.put(61, OSTzvH[15]);
      EEPROM.put(62, OSTzvM[15]);
      EEPROM.put(63, OSTzvH[16]);
      EEPROM.put(64, OSTzvM[16]);
      EEPROM.commit();
      Serial.println("...OK");

    }
  }
}

void loop() {
  ui.tick();
  if (millis() - tic > 1000) {
    tic = millis();
    Serial.println("------------------------------------------");
    Serial.println("time by internal clock");
    Serial.print(h);
    Serial.print(":");
    Serial.print(m);
    Serial.print(":");
    Serial.println(s);
    Serial.println("-----decode unix time----");
    Serial.print("WeekDAY UNIX= ");
    Serial.println(stamp.dayOfWeek);  // 1 понедельник, 7 воскресенье
    Serial.print("WeekDAY internal clock= ");
    Serial.print(WD);

    s++;
    if (s == 60) {              // вычисление минут и часов по секундам
      s = 0;                    // в 1ой минуте 60 сек
      m++;
    }
    if (m == 60) {              // в 1ом часе 60 минут
      m = 0;
      h++;
    }
    if (h == 24) {             // день в среднем равен 24 часа
      h = 0;
      m = 0;                   //   сброс счётчика
      s = 0;
      WD++;             // прибавление дня(для аварийного отсчета времени без интернета)
      if (WD > 7)WD = 1;       // на всякий случай защита от перебора
    }
  }

  if ( WiFi.status() != WL_CONNECTED ) {   // блок обновления времени
    if (millis() - rec > FAIL_TIME) {
      rec = millis();
      Serial.println("time synchronization failed");
      //  WiFi.begin(ssid, password);
    }
  } else {
    if (millis() - syn > SYN_TIME) {
      syn = millis();
      timeClient.update();
      h = timeClient.getHours();
      m = timeClient.getMinutes();
      s = timeClient.getSeconds();
      stamp.getDateTime(timeClient.getEpochTime());
      WD = stamp.dayOfWeek;
      Serial.println("successful time synchronization");
    }
  }

  if (WD == 1 && s == 0) { //  учитываем день недели
    if (h == PNzvH[1] && m == PNzvM[1])zvFlag = 1; // ищем совпадение и подаем звонок(дергаем флаг)
    if (h == PNzvH[2] && m == PNzvM[2])zvFlag = 1;
    if (h == PNzvH[3] && m == PNzvM[3])zvFlag = 1;
    if (h == PNzvH[4] && m == PNzvM[4])zvFlag = 1;
    if (h == PNzvH[5] && m == PNzvM[5])zvFlag = 1;
    if (h == PNzvH[6] && m == PNzvM[6])zvFlag = 1;
    if (h == PNzvH[7] && m == PNzvM[7])zvFlag = 1;
    if (h == PNzvH[8] && m == PNzvM[8])zvFlag = 1;
    if (h == PNzvH[9] && m == PNzvM[9])zvFlag = 1;
    if (h == PNzvH[10] && m == PNzvM[10])zvFlag = 1;
    if (h == PNzvH[11] && m == PNzvM[11])zvFlag = 1;
    if (h == PNzvH[12] && m == PNzvM[12])zvFlag = 1;
    if (h == PNzvH[13] && m == PNzvM[13])zvFlag = 1;
    if (h == PNzvH[14] && m == PNzvM[14])zvFlag = 1;
    if (h == PNzvH[15] && m == PNzvM[15])zvFlag = 1;
    if (h == PNzvH[16] && m == PNzvM[16])zvFlag = 1;
  } else if (WD == 7) {      //  воскресенье - нет звонков
  } else if (WD != 1 && s == 0){        //  остальные дни работаем по основному расписанию
    if (h == OSTzvH[1] && m == OSTzvM[1])zvFlag = 1;
    if (h == OSTzvH[2] && m == OSTzvM[2])zvFlag = 1;
    if (h == OSTzvH[3] && m == OSTzvM[3])zvFlag = 1;
    if (h == OSTzvH[4] && m == OSTzvM[4])zvFlag = 1;
    if (h == OSTzvH[5] && m == OSTzvM[5])zvFlag = 1;
    if (h == OSTzvH[6] && m == OSTzvM[6])zvFlag = 1;
    if (h == OSTzvH[7] && m == OSTzvM[7])zvFlag = 1;
    if (h == OSTzvH[8] && m == OSTzvM[8])zvFlag = 1;
    if (h == OSTzvH[9] && m == OSTzvM[9])zvFlag = 1;
    if (h == OSTzvH[10] && m == OSTzvM[10])zvFlag = 1;
    if (h == OSTzvH[11] && m == OSTzvM[11])zvFlag = 1;
    if (h == OSTzvH[12] && m == OSTzvM[12])zvFlag = 1;
    if (h == OSTzvH[13] && m == OSTzvM[13])zvFlag = 1;
    if (h == OSTzvH[14] && m == OSTzvM[14])zvFlag = 1;
    if (h == OSTzvH[15] && m == OSTzvM[15])zvFlag = 1;
    if (h == OSTzvH[16] && m == OSTzvM[16])zvFlag = 1;
  }

  if (zvFlag == 1) { //  когда флаг дернули
    digitalWrite(ZvPin, HIGH);  //  врубаем звонок,
    Serial.println("ZVONOK ACTIVE");
    if (s > ZVDEL) { // когда подошло заданное время(а звонок как раз начался в 0сек)
      zvFlag = 0; //  затем гасим флаг(чтоб звонок больше не включался сам по условию)
      digitalWrite(ZvPin, LOW);  //  вырубаем сам звонок
      Serial.println("ZVONOK OFF");
    }
  }
}
