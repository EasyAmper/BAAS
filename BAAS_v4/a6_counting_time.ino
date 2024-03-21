void counting_time() {
  
	if (millis() - t > 1000) {
    
		t = millis();
    
		//Serial.print(h);
		//Serial.print(":");
		//Serial.print(m);
		//Serial.print(":");
		//Serial.print(s);
		//Serial.print(" ");
		//Serial.println(d);
    
		s = s + 1;
		if (s == 60) {              					// Вычисление минут и часов по секундам
			s = 0;                    					// В 1ой минуте 60 сек
			m += 1;
		}
		if (m == 60) {              					// В 1ом часе 60 минут
			m = 0;
			h += 1;
		}
		if (h == 24) {             						// День в среднем равен 24 часа
			h = 0;
			m = 0;
			s = 0;
			d += 1;                   					// Счёт дней
		}
		if (d == 8) {
			d = 1;
		}

	}
  
}
