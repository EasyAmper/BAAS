void setup() {
	// Выбор скорости порта
	Serial.begin(115200);
	delay(2000);										// Пауза для корректного вывода информации в порт
  
	// Определяем размер EEPROM
	EEPROM.begin(300);

	// Подключение к WI-FI
	Serial.print("Соединение с ");
	Serial.print(ssid);
	WiFi.begin(ssid, password);
	WiFi.config(ip, gateway, subnet, dns);
	while ( WiFi.status() != WL_CONNECTED ) { 			// Ожидание подключения
		delay(500);
		Serial.print ( "." );
	}
	Serial.println();
	Serial.println("Присоединился");
	Serial.print("IP адресс: ");
	Serial.println(WiFi.localIP());

	// Инициализация ног платы
	pinMode(CALL, OUTPUT); 								// Подключение ноги как выход
	digitalWrite(CALL, HIGH); 							// Реле низкого уровня

	// Получение времени
	timeClient.begin();
	timeClient.update();
	d = (int)floor((timeClient.getEpochTime()/86400+4)-7*(floor((timeClient.getEpochTime()/86400+4)/7)));
	h = timeClient.getHours();
	m = timeClient.getMinutes();
	s = timeClient.getSeconds();

	// Чтение карты
	Serial.print("Инициализация CD карты...");
	if (!SD.begin(SDCARD)) {							// Если что-то пошло не так, завершаем работу:
		Serial.println("Карта не обнарудена. Беру данные из EEPROM.");
		EEPROM_read();
	} else {
		Serial.println("Карта инициализирована. Беру данные с неё.");
		call_read();
	}

	// Инициализация страницы
	Serial.println("Инициализация страницы");
	ui.attachBuild(build);   							// Подключаем и запускаем конструктор страницы
	ui.attach(action);
	ui.start();
	Serial.print("Успешно ");
	Serial.print("адресс страницы: http://");
	Serial.print(WiFi.localIP());
	Serial.println("/");

	// Небольшая пауза
	delay(2000);
}
