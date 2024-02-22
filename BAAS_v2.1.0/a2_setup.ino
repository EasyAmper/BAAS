void setup() {
  
  // Выбор скорости порта
  Serial.begin(115200);
  
  // Подключение к WI-FI
  Serial.print("Connection to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  WiFi.config(ip, gateway, subnet, dns);
  while ( WiFi.status() != WL_CONNECTED ) { // Ожидание подключения
    delay(500);
    Serial.print ( "." );
  }
  Serial.println();
  Serial.println("Connecting");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  if (mdns.begin("BAAS", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
  
  // Инициализация ног платы
  pinMode(CALL, OUTPUT); // Подключение ноги как выход
  digitalWrite(CALL, HIGH); // Реле низкого уровня
  
  // Получение времени
  timeClient.begin();
  timeClient.update();
  d = (int)floor((timeClient.getEpochTime()/86400+4)-7*(floor((timeClient.getEpochTime()/86400+4)/7)));
  h = timeClient.getHours();
  m = timeClient.getMinutes();
  s = timeClient.getSeconds();
  
  // Чтение карты
  Serial.print("Initializing SD card...");

  if (!SD.begin(SDCARD)) {
    Serial.println("Card failed, or not present");
    // Если что-то пошло не так, завершаем работу:
    //return;
  } else {
    Serial.println("card initialized.");
    call_read();
  }

  // Небольшая пауза
  delay(2000);
}
