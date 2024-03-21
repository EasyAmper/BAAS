void call_read() {
	CallFile = SD.open("call.json");
	if (CallFile) {
		Serial.println("call.json найден.");
		byte calls[288] = {};
		String callStr = "";

		// читаем содезжимое
		while (CallFile.available()) {
			Serial.println("Читаю содержимое:");
			callStr = CallFile.readString();
			Serial.println(callStr);
			callStr.replace("]", "");
			callStr.replace("[", "");
		 
			int flag = 0;
			int index = 0;
			for (int i = 0; i < callStr.length(); i++) {
				if (callStr.substring(i, i+1) == ",") {
					calls[index] = callStr.substring(flag+1, i-1).toInt();
					flag = i+1;
					index++;
				}
			}
		}

		for (int i = 0; i < 288; i++) {
			Serial.print(calls[i]);
			Serial.print(",");
		}
		Serial.println("");

		// переносим данные в другой массив чисел
		int flag1 = 0;
		int flag2 = 0;
		int flag3 = 0;
		for (int i = 0; i < 288; i++) {
			timeCall[flag1][flag2][flag3] = calls[i];
			Serial.print(calls[i]);
			Serial.print(",");
			flag3++;
			if (flag3 == 3) {
				flag3 = 0;
				flag2++;
				Serial.println("");
			}
			if (flag2 == 16) {
				flag2 = 0;
				flag1++;
				Serial.println("next day");
			}
		}
		Serial.print("Обновляю EEPROM");
		byte flag = 0;
		for (int i = 0; i < 6; i++) {
			EEPROM.put(0+ flag, timeCall[i][0][0]);
			EEPROM.put(1+ flag, timeCall[i][0][1]);
			EEPROM.put(2+ flag, timeCall[i][0][2]);
			EEPROM.put(3+ flag, timeCall[i][1][0]);
			EEPROM.put(4+ flag, timeCall[i][1][1]);
			EEPROM.put(5+ flag, timeCall[i][1][2]);
			EEPROM.put(6+ flag, timeCall[i][2][0]);
			EEPROM.put(7+ flag, timeCall[i][2][1]);
			EEPROM.put(8+ flag, timeCall[i][2][2]);
			EEPROM.put(9+ flag, timeCall[i][3][0]);
			EEPROM.put(10+ flag, timeCall[i][3][1]);
			EEPROM.put(11+ flag, timeCall[i][3][2]);
			EEPROM.put(12+ flag, timeCall[i][4][0]);
			EEPROM.put(13+ flag, timeCall[i][4][1]);
			EEPROM.put(14+ flag, timeCall[i][4][2]);
			EEPROM.put(15+ flag, timeCall[i][5][0]);
			EEPROM.put(16+ flag, timeCall[i][5][1]);
			EEPROM.put(17+ flag, timeCall[i][5][2]);
			EEPROM.put(18+ flag, timeCall[i][6][0]);
			EEPROM.put(19+ flag, timeCall[i][6][1]);
			EEPROM.put(20+ flag, timeCall[i][6][2]);
			EEPROM.put(21+ flag, timeCall[i][7][0]);
			EEPROM.put(22+ flag, timeCall[i][7][1]);
			EEPROM.put(23+ flag, timeCall[i][7][2]);
			EEPROM.put(24+ flag, timeCall[i][8][0]);
			EEPROM.put(25+ flag, timeCall[i][8][1]);
			EEPROM.put(26+ flag, timeCall[i][8][2]);
			EEPROM.put(27+ flag, timeCall[i][9][0]);
			EEPROM.put(28+ flag, timeCall[i][9][1]);
			EEPROM.put(29+ flag, timeCall[i][9][2]);
			EEPROM.put(30+ flag, timeCall[i][10][0]);
			EEPROM.put(31+ flag, timeCall[i][10][1]);
			EEPROM.put(32+ flag, timeCall[i][10][2]);
			EEPROM.put(33+ flag, timeCall[i][11][0]);
			EEPROM.put(34+ flag, timeCall[i][11][1]);
			EEPROM.put(35+ flag, timeCall[i][11][2]);
			EEPROM.put(36+ flag, timeCall[i][12][0]);
			EEPROM.put(37+ flag, timeCall[i][12][1]);
			EEPROM.put(38+ flag, timeCall[i][12][2]);
			EEPROM.put(39+ flag, timeCall[i][13][0]);
			EEPROM.put(40+ flag, timeCall[i][13][1]);
			EEPROM.put(41+ flag, timeCall[i][13][2]);
			EEPROM.put(42+ flag, timeCall[i][14][0]);
			EEPROM.put(43+ flag, timeCall[i][14][1]);
			EEPROM.put(43+ flag, timeCall[i][14][2]);
			EEPROM.put(44+ flag, timeCall[i][15][0]);
			EEPROM.put(45+ flag, timeCall[i][15][1]);
			EEPROM.put(46+ flag, timeCall[i][15][2]);
			EEPROM.commit();  // принять изменения
			flag += 47;
			Serial.print(".");
		}
		Serial.println(" ОК");
		// закрываем файл
		CallFile.close();
		Serial.println("Успешно");
	} else {
		// сообщаем об ошибке
		Serial.println("call.json отсутствует. Создайте его при помощи инструмента call_page (https://github.com/EasyAmper/BAAS/blob/v2_SDcard/call_page.html) и загрузите на карту памяти");
		EEPROM_read();
	}
}

void EEPROM_read() {
	Serial.println("Читаю EEPROM");
	byte flag = 0;
	for (int i = 0; i < 6; i++) {
		EEPROM.get(0+ flag, timeCall[i][0][0]);
		EEPROM.get(1+ flag, timeCall[i][0][1]);
		EEPROM.get(2+ flag, timeCall[i][0][2]);
		EEPROM.get(3+ flag, timeCall[i][1][0]);
		EEPROM.get(4+ flag, timeCall[i][1][1]);
		EEPROM.get(5+ flag, timeCall[i][1][2]);
		EEPROM.get(6+ flag, timeCall[i][2][0]);
		EEPROM.get(7+ flag, timeCall[i][2][1]);
		EEPROM.get(8+ flag, timeCall[i][2][2]);
		EEPROM.get(9+ flag, timeCall[i][3][0]);
		EEPROM.get(10+ flag, timeCall[i][3][1]);
		EEPROM.get(11+ flag, timeCall[i][3][2]);
		EEPROM.get(12+ flag, timeCall[i][4][0]);
		EEPROM.get(13+ flag, timeCall[i][4][1]);
		EEPROM.get(14+ flag, timeCall[i][4][2]);
		EEPROM.get(15+ flag, timeCall[i][5][0]);
		EEPROM.get(16+ flag, timeCall[i][5][1]);
		EEPROM.get(17+ flag, timeCall[i][5][2]);
		EEPROM.get(18+ flag, timeCall[i][6][0]);
		EEPROM.get(19+ flag, timeCall[i][6][1]);
		EEPROM.get(20+ flag, timeCall[i][6][2]);
		EEPROM.get(21+ flag, timeCall[i][7][0]);
		EEPROM.get(22+ flag, timeCall[i][7][1]);
		EEPROM.get(23+ flag, timeCall[i][7][2]);
		EEPROM.get(24+ flag, timeCall[i][8][0]);
		EEPROM.get(25+ flag, timeCall[i][8][1]);
		EEPROM.get(26+ flag, timeCall[i][8][2]);
		EEPROM.get(27+ flag, timeCall[i][9][0]);
		EEPROM.get(28+ flag, timeCall[i][9][1]);
		EEPROM.get(29+ flag, timeCall[i][9][2]);
		EEPROM.get(30+ flag, timeCall[i][10][0]);
		EEPROM.get(31+ flag, timeCall[i][10][1]);
		EEPROM.get(32+ flag, timeCall[i][10][2]);
		EEPROM.get(33+ flag, timeCall[i][11][0]);
		EEPROM.get(34+ flag, timeCall[i][11][1]);
		EEPROM.get(35+ flag, timeCall[i][11][2]);
		EEPROM.get(36+ flag, timeCall[i][12][0]);
		EEPROM.get(37+ flag, timeCall[i][12][1]);
		EEPROM.get(38+ flag, timeCall[i][12][2]);
		EEPROM.get(39+ flag, timeCall[i][13][0]);
		EEPROM.get(40+ flag, timeCall[i][13][1]);
		EEPROM.get(41+ flag, timeCall[i][13][2]);
		EEPROM.get(42+ flag, timeCall[i][14][0]);
		EEPROM.get(43+ flag, timeCall[i][14][1]);
		EEPROM.get(43+ flag, timeCall[i][14][2]);
		EEPROM.get(44+ flag, timeCall[i][15][0]);
		EEPROM.get(45+ flag, timeCall[i][15][1]);
		EEPROM.get(46+ flag, timeCall[i][15][2]);
		flag += 47;
		Serial.print(".");
	}
    EEPROM.get(299, duration);
	Serial.println(" ОК");
	Serial.println("Успешно");
}
