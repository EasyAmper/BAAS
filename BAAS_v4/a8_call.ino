void call() {
	if (callFlag == 1) {
		if (millis() - calltime > 1000) {
			digitalWrite(CALL, LOW);          // Подаем звонок
            Serial.print(h);
            Serial.print(":");
            Serial.print(m);
            Serial.print(":");
            Serial.print(s);
            Serial.println(" | CALL!");
			calltime = millis();
			callsec++;
			if (callsec-1 >= duration) {
				digitalWrite(CALL, HIGH);       // Выключаем звонок
                Serial.print(h);
                Serial.print(":");
                Serial.print(m);
                Serial.print(":");
                Serial.print(s);
                Serial.println(" | CALL off!");
				callFlag = 0;                   // Меняем флаг на ноль
			}
		}
	} 
}
