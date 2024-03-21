void action() {
	if (ui.form()) {
		if (ui.form("/update")) {
			ifpass = ui.getInt("password");  			// Получаем вписаный на странице пароль
			if(ifpass == pagepass or ifpass == pageadpass) {
                Serial.print(h);
                Serial.print(":");
                Serial.print(m);
                Serial.print(":");
                Serial.print(s);
				Serial.println(" | Пароль введен верно.");
				for (int i = 0; i < 6; i++) {
					for (int i1 = 0; i1 < 16; i1++) {
						GPtime t = ui.getTime("coup" + String(i) + "." + String(i1/4) + "." + String( int( i1-4*floor( i1/4 ) ) ) );
						timeCall[i][i1][0] = byte(t.hour);
						timeCall[i][i1][1] = byte(t.minute);
						timeCall[i][i1][2] = byte(t.second);
					}
				}
                duration = byte( ui.getInt("time") );
                Serial.print(h);
                Serial.print(":");
                Serial.print(m);
                Serial.print(":");
                Serial.print(s);
				Serial.print(" | Записываю в EEPROM.");
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
					EEPROM.commit();  					// Принять изменения
					Serial.print(".");
					flag += 47;
				}
                EEPROM.put(299, duration);
                EEPROM.commit();                        // Принять изменения
				Serial.println(" OK");
				Serial.println("Успешно");
			} else {
                Serial.print(h);
                Serial.print(":");
                Serial.print(m);
                Serial.print(":");
                Serial.print(s);
				Serial.println(" | Пароль введен неверно.");
			}
		}
	}
}
