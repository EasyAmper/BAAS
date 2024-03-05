void loop() {
  ui.tick();
  if (millis() - tic > 1000) {   // часики тикают тик так
    tic = millis();
    s++;   
    if (s == 60) {     // вычисление минут по секундам
      s = 0;           // сброс секунд
      m++;             
    }
    if (m == 60) {     // вычисление часов по минутам         
      m = 0;           
      h++;
    }
    if (h == 24) {     // ...аналогично
      h = 0;
      m = 0;               //   сброс счётчика
      s = 0;
      WD++;                // прибавление дня (для аварийного отсчета времени без интернета)
      if (WD > 7)WD = 1;   // на всякий случай защита от перебора
    }
  }

  if ( WiFi.status() != WL_CONNECTED ) {   // блок обновления времени
    if (millis() - rec > FAIL_TIME) {
      rec = millis();
      Serial.println("synchronization failed !");
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
  // далее перейдем к самой подаче звонков
  if (WD == 1 && s == 0) {   //  учитываем день недели
    if (h == PNzvH[1] && m == PNzvM[1])zvFlag = 1; // ищем совпадение и подаем звонок(дергаем флаг)
    if (h == PNzvH[2] && m == PNzvM[2])zvFlag = 1;  // Все условия проверяются только когда секунды = 0
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
  } else if (WD != 7 && s == 0) {    //  воскресенье - нет звонков
    if (h == OSTzvH[1] && m == OSTzvM[1])zvFlag = 1;   //  остальные дни работаем по основному расписанию
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
