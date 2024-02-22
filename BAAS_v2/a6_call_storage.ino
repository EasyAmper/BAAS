void call_read() {
  CallFile = SD.open("call.json");
  if (CallFile) {
    Serial.println("call.json");
    int calls[288] = {};

    // читаем содезжимое
    while (CallFile.available()) {
      callStr = CallFile.readString();
      Serial.println(callStr);
      callStr.replace("]", "");
      callStr.replace("[", "");
      // 
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

    
    // закрываем файл
    CallFile.close();
  } else {
    // сообщаем об ошибке
    Serial.println("error opening call.json");
  }
}
