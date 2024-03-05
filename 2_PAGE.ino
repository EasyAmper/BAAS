void build() {      // отрисовка страницы
  GP.BUILD_BEGIN();
  GP.THEME(GP_DARK);
  GP.PAGE_TITLE("BAAS_Bell_Set");
  GP.TITLE("Настройка звонков");
  GP.HR();
  GP.FORM_BEGIN("/update");
  GP.LABEL("Длительность подачи звонка, сек");
  GP.NUMBER("num", "Секунды", ZVDEL);
  GP.HR();
  GP.LABEL("Понедельник Звонок 1");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num1", "Часы", PNzvH[1]);    //  для удобства, массив использую начиная с 1 а не 0 (плохо, но удобно)
  GP.LABEL("Минуты");
  GP.NUMBER("num2", "Минуты", PNzvM[1]);
  GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 2");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num3", "Часы", PNzvH[2]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num4", "Минуты", PNzvM[2]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 3");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num5", "Часы", PNzvH[3]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num6", "Минуты", PNzvM[3]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 4");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num7", "Часы", PNzvH[4]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num8", "Минуты", PNzvM[4]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 5");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num9", "Часы", PNzvH[5]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num10", "Минуты", PNzvM[5]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 6");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num11", "Часы", PNzvH[6]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num12", "Минуты", PNzvM[6]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 7");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num13", "Часы", PNzvH[7]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num14", "Минуты", PNzvM[7]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 8");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num15", "Часы", PNzvH[8]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num16", "Минуты", PNzvM[8]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 9");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num17", "Часы", PNzvH[9]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num18", "Минуты", PNzvM[9]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 10");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num19", "Часы", PNzvH[10]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num20", "Минуты", PNzvM[10]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 11");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num21", "Часы", PNzvH[11]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num22", "Минуты", PNzvM[11]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 12");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num23", "Часы", PNzvH[12]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num24", "Минуты", PNzvM[12]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 13");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num25", "Часы", PNzvH[13]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num26", "Минуты", PNzvM[13]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 14");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num27", "Часы", PNzvH[14]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num28", "Минуты", PNzvM[14]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 15");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num29", "Часы", PNzvH[15]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num30", "Минуты", PNzvM[15]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 16");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num31", "Часы", PNzvH[16]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num32", "Минуты", PNzvM[16]); GP.BREAK();
  GP.HR();

  GP.HR();
  GP.LABEL("Остальные дни Звонок 1");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num33", "Часы", OSTzvH[1]);    //  все аналогично, только переменные другие
  GP.LABEL("Минуты");
  GP.NUMBER("num34", "Минуты", OSTzvM[1]);
  GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 2");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num35", "Часы", OSTzvH[2]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num36", "Минуты", OSTzvM[2]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 3");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num37", "Часы", OSTzvH[3]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num38", "Минуты", OSTzvM[3]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 4");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num39", "Часы", OSTzvH[4]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num40", "Минуты", OSTzvM[4]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 5");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num41", "Часы", OSTzvH[5]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num42", "Минуты", OSTzvM[5]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 6");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num43", "Часы", OSTzvH[6]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num44", "Минуты", OSTzvM[6]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 7");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num45", "Часы", OSTzvH[7]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num46", "Минуты", OSTzvM[7]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 8");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num47", "Часы", OSTzvH[8]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num48", "Минуты", OSTzvM[8]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 9");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num49", "Часы", OSTzvH[9]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num50", "Минуты", OSTzvM[9]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 10");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num51", "Часы", OSTzvH[10]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num52", "Минуты", OSTzvM[10]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 11");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num53", "Часы", OSTzvH[11]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num54", "Минуты", OSTzvM[11]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 12");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num55", "Часы", OSTzvH[12]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num56", "Минуты", OSTzvM[12]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 13");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num57", "Часы", OSTzvH[13]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num58", "Минуты", OSTzvM[13]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 14");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num59", "Часы", OSTzvH[14]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num60", "Минуты", OSTzvM[14]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 15");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num61", "Часы", OSTzvH[15]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num62", "Минуты", OSTzvM[15]); GP.BREAK();
  GP.HR();
  GP.LABEL("Звонок 16");
  GP.BREAK();
  GP.LABEL("Часы");
  GP.NUMBER("num63", "Часы", OSTzvH[16]); GP.BREAK();
  GP.LABEL("Минуты");
  GP.NUMBER("num64", "Минуты", OSTzvM[16]); GP.BREAK();
  GP.HR();
  GP.HR();
  GP.LABEL("Пароль:");      // ближе к кнопке разместим поле ввода пароля
  GP.NUMBER("num65", "Пароль", ZVPass); GP.BREAK();
  GP.HR();
  GP.SUBMIT("Принять изменения");
  GP.FORM_END();
  GP.HR();
  GP.BREAK();
  GP.BREAK();
  GP.TITLE("Информация");
  GP.SYSTEM_INFO("BAAS_v3.5");
  GP.BUILD_END();
}