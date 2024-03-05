void action() {        // тут действия на странице
  if (ui.form()) {    
    if (ui.form("/update")) {     
      ZVPass = ui.getInt("num65");  //  получаем вписаный на странице пароль
      if (ZVPass == ZVP) {    // при соответствии пароля
        ZVDEL = ui.getInt("num");    // забираем значения и обновляем переменные
        PNzvH[1] = ui.getInt("num1");   
        PNzvM[1] = ui.getInt("num2");
        PNzvH[2] = ui.getInt("num3");
        PNzvM[2] = ui.getInt("num4");
        PNzvH[3] = ui.getInt("num5");
        PNzvM[3] = ui.getInt("num6");
        PNzvH[4] = ui.getInt("num7");
        PNzvM[4] = ui.getInt("num8");
        PNzvM[5] = ui.getInt("num9");
        PNzvM[5] = ui.getInt("num10");
        PNzvH[6] = ui.getInt("num11");
        PNzvM[6] = ui.getInt("num12");
        PNzvH[7] = ui.getInt("num13");
        PNzvM[7] = ui.getInt("num14");
        PNzvH[8] = ui.getInt("num15");
        PNzvM[8] = ui.getInt("num16");
        PNzvH[9] = ui.getInt("num17");
        PNzvM[9] = ui.getInt("num18");
        PNzvM[10] = ui.getInt("num19");
        PNzvM[10] = ui.getInt("num20");
        PNzvH[11] = ui.getInt("num21");
        PNzvM[11] = ui.getInt("num22");
        PNzvH[12] = ui.getInt("num23");
        PNzvM[12] = ui.getInt("num24");
        PNzvH[13] = ui.getInt("num25");
        PNzvM[13] = ui.getInt("num26");
        PNzvH[14] = ui.getInt("num27");
        PNzvM[14] = ui.getInt("num28");
        PNzvH[15] = ui.getInt("num29");
        PNzvM[15] = ui.getInt("num30");
        PNzvH[16] = ui.getInt("num31");
        PNzvM[16] = ui.getInt("num32");

        OSTzvH[1] = ui.getInt("num33");
        OSTzvM[1] = ui.getInt("num34");
        OSTzvH[2] = ui.getInt("num35");
        OSTzvM[2] = ui.getInt("num36");
        OSTzvH[3] = ui.getInt("num37");
        OSTzvM[3] = ui.getInt("num38");
        OSTzvH[4] = ui.getInt("num39");
        OSTzvM[4] = ui.getInt("num40");
        OSTzvH[5] = ui.getInt("num41");
        OSTzvM[5] = ui.getInt("num42");
        OSTzvH[6] = ui.getInt("num43");
        OSTzvM[6] = ui.getInt("num44");
        OSTzvH[7] = ui.getInt("num45");
        OSTzvM[7] = ui.getInt("num46");
        OSTzvH[8] = ui.getInt("num47");
        OSTzvM[8] = ui.getInt("num48");
        OSTzvH[9] = ui.getInt("num49");
        OSTzvM[9] = ui.getInt("num50");
        OSTzvH[10] = ui.getInt("num51");
        OSTzvM[10] = ui.getInt("num52");
        OSTzvH[11] = ui.getInt("num53");
        OSTzvM[11] = ui.getInt("num54");
        OSTzvH[12] = ui.getInt("num55");
        OSTzvM[12] = ui.getInt("num56");
        OSTzvH[13] = ui.getInt("num57");
        OSTzvM[13] = ui.getInt("num58");
        OSTzvH[14] = ui.getInt("num59");
        OSTzvM[14] = ui.getInt("num60");
        OSTzvH[15] = ui.getInt("num61");
        OSTzvM[15] = ui.getInt("num62");
        OSTzvH[16] = ui.getInt("num63");
        OSTzvM[16] = ui.getInt("num64");

        Serial.println("Get variable OK");  // Запись EEPROM
        Serial.println("Start writing EEPROM...");  // Запись EEPROM
        EEPROM.put(0, ZVDEL);
        EEPROM.put(1, PNzvH[1]);
        EEPROM.put(2, PNzvM[1]);
        EEPROM.put(3, PNzvH[2]);
        EEPROM.put(4, PNzvM[2]);
        EEPROM.put(5, PNzvH[3]);
        EEPROM.put(6, PNzvM[3]);
        EEPROM.put(7, PNzvH[4]);
        EEPROM.put(8, PNzvM[4]);
        EEPROM.put(9, PNzvH[5]);
        EEPROM.put(10, PNzvM[5]);
        EEPROM.put(11, PNzvH[6]);
        EEPROM.put(12, PNzvM[6]);
        EEPROM.put(13, PNzvH[7]);
        EEPROM.put(14, PNzvM[7]);
        EEPROM.put(15, PNzvH[8]);
        EEPROM.put(16, PNzvM[8]);
        EEPROM.put(17, PNzvH[9]);
        EEPROM.put(18, PNzvM[9]);
        EEPROM.put(19, PNzvH[10]);
        EEPROM.put(20, PNzvM[10]);
        EEPROM.put(21, PNzvH[11]);
        EEPROM.put(22, PNzvM[11]);
        EEPROM.put(23, PNzvH[12]);
        EEPROM.put(24, PNzvM[12]);
        EEPROM.put(25, PNzvH[13]);
        EEPROM.put(26, PNzvM[13]);
        EEPROM.put(27, PNzvH[14]);
        EEPROM.put(28, PNzvM[14]);
        EEPROM.put(29, PNzvH[15]);
        EEPROM.put(30, PNzvM[15]);
        EEPROM.put(31, PNzvH[16]);
        EEPROM.put(32, PNzvM[16]);

        EEPROM.put(33, OSTzvH[1]);
        EEPROM.put(34, OSTzvM[1]);
        EEPROM.put(35, OSTzvH[2]);
        EEPROM.put(36, OSTzvM[2]);
        EEPROM.put(37, OSTzvH[3]);
        EEPROM.put(38, OSTzvM[3]);
        EEPROM.put(39, OSTzvH[4]);
        EEPROM.put(40, OSTzvM[4]);
        EEPROM.put(41, OSTzvH[5]);
        EEPROM.put(42, OSTzvM[5]);
        EEPROM.put(43, OSTzvH[6]);
        EEPROM.put(44, OSTzvM[6]);
        EEPROM.put(45, OSTzvH[7]);
        EEPROM.put(46, OSTzvM[7]);
        EEPROM.put(47, OSTzvH[8]);
        EEPROM.put(48, OSTzvM[8]);
        EEPROM.put(49, OSTzvH[9]);
        EEPROM.put(50, OSTzvM[9]);
        EEPROM.put(51, OSTzvH[10]);
        EEPROM.put(52, OSTzvM[10]);
        EEPROM.put(53, OSTzvH[11]);
        EEPROM.put(54, OSTzvM[11]);
        EEPROM.put(55, OSTzvH[12]);
        EEPROM.put(56, OSTzvM[12]);
        EEPROM.put(57, OSTzvH[13]);
        EEPROM.put(58, OSTzvM[13]);
        EEPROM.put(59, OSTzvH[14]);
        EEPROM.put(60, OSTzvM[14]);
        EEPROM.put(61, OSTzvH[15]);
        EEPROM.put(62, OSTzvM[15]);
        EEPROM.put(63, OSTzvH[16]);
        EEPROM.put(64, OSTzvM[16]);
        EEPROM.commit();  // принять изменения
        Serial.println("EEPROM successfully updated");
        ZVPass = 0;  //  сброс введённого пароля 
      }
    }
  }
}
