void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_SSID, AP_PASS);
  EEPROM.begin(65);    //  организуем работу с памятью(отличается от обычной, только для ESP плат)

  while (WiFi.status() != WL_CONNECTED) {   // если не подключились
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());    // в случае подключения пишем IP

  ui.attachBuild(build);   // подключаем и запускаем конструктор страницы
  ui.attach(action);
  ui.start();

  timeClient.begin();         // инициализируем работу с клиентом
  timeClient.update();        // получаем время, 
  h = timeClient.getHours();  // обновляем переменные
  m = timeClient.getMinutes();
  s = timeClient.getSeconds();
  stamp.getDateTime(timeClient.getEpochTime());   // получаем время UNIX, скармливаем библиотеке
  WD = stamp.dayOfWeek;    // забираем из нее дни недели

  Serial.println("Reading EEPROM...");  // Чтение расписания из EEPROM
  EEPROM.get(0, ZVDEL);   // достаем из ячейки значение и сразу заносим в переменную
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
  Serial.println("-OK");
}
