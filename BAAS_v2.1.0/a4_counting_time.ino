void counting_time() {
  
  if (millis() - t > 1000) {
    
    t = millis();
    
    
    //Serial.println("time by internal clock");
    Serial.print(h);
    Serial.print(":");
    Serial.print(m);
    Serial.print(":");
    Serial.print(s);
    Serial.print(" ");
    Serial.println(d);
    
    
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
      d += 1;
    }
    if (d == 8) {
      d = 1;
    }

  }
  
}
