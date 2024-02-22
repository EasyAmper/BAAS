void loop() {

  // Блок вывода и самостоятельного счёта времени
  counting_time();
  // Блок синхронизации (обновление времени)
  time_sync();
  // Блок плдачи звонков
  switch (d) {
    case 1:
      for(int i = 0; i < 16; i++) {
        if (h == timeCall[0][i][0] && m == timeCall[0][i][1] && s == timeCall[0][i][2])call();
      }
      break;
    case 2:
      for(int i = 0; i < 16; i++) {
        if (h == timeCall[1][i][0] && m == timeCall[1][i][1] && s == timeCall[1][i][2])call();
      }
      break;
    case 3:
      for(int i = 0; i < 16; i++) {
        if (h == timeCall[2][i][0] && m == timeCall[2][i][1] && s == timeCall[2][i][2])call();
      }
      break;
    case 4:
      for(int i = 0; i < 16; i++) {
        if (h == timeCall[3][i][0] && m == timeCall[3][i][1] && s == timeCall[3][i][2])call();
      }
      break;
    case 5:
      for(int i = 0; i < 16; i++) {
        if (h == timeCall[4][i][0] && m == timeCall[4][i][1] && s == timeCall[4][i][2])call();
      }
      break;
    case 6:
      for(int i = 0; i < 16; i++) {
        if (h == timeCall[5][i][0] && m == timeCall[5][i][1] && s == timeCall[5][i][2])call();
      }
      break;
    case 7:

      break;
  }

}
