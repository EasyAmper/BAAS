void build() {      									// Отрисовка страницы
	GP.BUILD_BEGIN(1400);
	GP.THEME(GP_DARK);
	GP.PAGE_TITLE("BAAS_Bell_Set");

    GP.NAV_TABS_LINKS("/,/info,", "Home,Info");

    if (ui.uri() == "/info") {
        GP.BLOCK_BEGIN(GP_TAB, "100%",  "Информация", GP_DEFAULT);
        
            GP.SYSTEM_INFO("BAAS_v4");

        GP.BLOCK_END();
    } else {
        GP.HR();
        GP.FORM_BEGIN("/update");
    
        GP.BLOCK_BEGIN(GP_TAB, "100%",  "Настройка звонков", GP_DEFAULT);
    
            GP.BLOCK_BEGIN(GP_THIN, "60%", "Понедельник", GP_DEFAULT);
    
                GP.BOX_BEGIN();
    
                    GP.LABEL("1 ПАРА");                     // Понедельник 1 пара
                    GP.TIME(
                        "coup0.0.0",
                        GPtime(timeCall[0][0][0], timeCall[0][0][1], timeCall[0][0][2])
                    );
                    GP.TIME(
                        "coup0.0.1",
                        GPtime(timeCall[0][1][0], timeCall[0][1][1], timeCall[0][1][2])
                    );
                    GP.TIME(
                        "coup0.0.2",
                        GPtime(timeCall[0][2][0], timeCall[0][2][1], timeCall[0][2][2])
                    );
                    GP.TIME(
                        "coup0.0.3",
                        GPtime(timeCall[0][3][0], timeCall[0][3][1], timeCall[0][3][2])
                    );
    
                GP.BOX_END();  
                GP.BOX_BEGIN();  
    
                    GP.LABEL("2 ПАРА");                     // Понедельник 2 пара
                    GP.TIME(
                        "coup0.1.0",
                        GPtime(timeCall[0][4][0], timeCall[0][4][1], timeCall[0][4][2])
                    );
                    GP.TIME(
                        "coup0.1.1",
                        GPtime(timeCall[0][5][0], timeCall[0][5][1], timeCall[0][5][2])
                    );
                    GP.TIME(
                        "coup0.1.2",
                        GPtime(timeCall[0][6][0], timeCall[0][6][1], timeCall[0][6][2])
                    );
                    GP.TIME(
                        "coup0.1.3",
                        GPtime(timeCall[0][7][0], timeCall[0][7][1], timeCall[0][7][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();  
    
                    GP.LABEL("3 ПАРА");                     // Понедельник 3 пара
                    GP.TIME(
                        "coup0.2.0",
                        GPtime(timeCall[0][8][0], timeCall[0][8][1], timeCall[0][8][2])
                    );
                    GP.TIME(
                        "coup0.2.1",
                        GPtime(timeCall[0][9][0], timeCall[0][9][1], timeCall[0][9][2])
                    );
                    GP.TIME(
                        "coup0.2.2",
                        GPtime(timeCall[0][10][0], timeCall[0][10][1], timeCall[0][10][2])
                    );
                    GP.TIME(
                        "coup0.2.3",
                        GPtime(timeCall[0][11][0], timeCall[0][11][1], timeCall[0][11][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN(); 
    
                    GP.LABEL("4 ПАРА");                     // Понедельник 4 пара
                    GP.TIME(
                        "coup0.3.0",
                        GPtime(timeCall[0][12][0], timeCall[0][12][1], timeCall[0][12][2])
                    );
                    GP.TIME(
                        "coup0.3.1",
                        GPtime(timeCall[0][13][0], timeCall[0][13][1], timeCall[0][13][2])
                    );
                    GP.TIME(
                        "coup0.3.2",
                        GPtime(timeCall[0][14][0], timeCall[0][14][1], timeCall[0][14][2])
                    );
                    GP.TIME(
                        "coup0.3.3",
                        GPtime(timeCall[0][15][0], timeCall[0][15][1], timeCall[0][15][2])
                    );
    
                GP.BOX_END();
    
            GP.BLOCK_END();
    
            GP.HR();
    
            GP.BLOCK_BEGIN(GP_THIN, "60%", "Вторник", GP_DEFAULT);
    
                GP.BOX_BEGIN();
                
                    GP.LABEL("1 ПАРА");                     // Вторник 1 пара
                    GP.TIME(
                        "coup1.0.0",
                        GPtime(timeCall[1][0][0], timeCall[1][0][1], timeCall[1][0][2])
                    );
                    GP.TIME(
                        "coup1.0.1",
                        GPtime(timeCall[1][1][0], timeCall[1][1][1], timeCall[1][1][2])
                    );
                    GP.TIME(
                        "coup1.0.2",
                        GPtime(timeCall[1][2][0], timeCall[1][2][1], timeCall[1][2][2])
                    );
                    GP.TIME(
                        "coup1.0.3",
                        GPtime(timeCall[1][3][0], timeCall[1][3][1], timeCall[1][3][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();
    
                    GP.LABEL("2 ПАРА");                     // Вторник 2 пара
                    GP.TIME(
                        "coup1.1.0",
                        GPtime(timeCall[1][4][0], timeCall[1][4][1], timeCall[1][4][2])
                    );
                    GP.TIME(
                        "coup1.1.1",
                        GPtime(timeCall[1][5][0], timeCall[1][5][1], timeCall[1][5][2])
                    );
                    GP.TIME(
                        "coup1.1.2",
                        GPtime(timeCall[1][6][0], timeCall[1][6][1], timeCall[1][6][2])
                    );
                    GP.TIME(
                        "coup1.1.3",
                        GPtime(timeCall[1][7][0], timeCall[1][7][1], timeCall[1][7][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();
    
                    GP.LABEL("3 ПАРА");                     // Вторник 3 пара
                    GP.TIME(
                        "coup1.2.0",
                        GPtime(timeCall[1][8][0], timeCall[1][8][1], timeCall[1][8][2])
                    );
                    GP.TIME(
                        "coup1.2.1",
                        GPtime(timeCall[1][9][0], timeCall[1][9][1], timeCall[1][9][2])
                    );
                    GP.TIME(
                        "coup1.2.2",
                        GPtime(timeCall[1][10][0], timeCall[1][10][1], timeCall[1][10][2])
                    );
                    GP.TIME(
                        "coup1.2.3",
                        GPtime(timeCall[1][11][0], timeCall[1][11][1], timeCall[1][11][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();
    
                    GP.LABEL("4 ПАРА");                     // Вторник 4 пара
                    GP.TIME(
                        "coup1.3.0",
                        GPtime(timeCall[1][12][0], timeCall[1][12][1], timeCall[1][12][2])
                    );
                    GP.TIME(
                        "coup1.3.1",
                        GPtime(timeCall[1][13][0], timeCall[1][13][1], timeCall[1][13][2])
                    );
                    GP.TIME(
                        "coup1.3.2",
                        GPtime(timeCall[1][14][0], timeCall[1][14][1], timeCall[1][14][2])
                    );
                    GP.TIME(
                        "coup1.3.3",
                        GPtime(timeCall[1][15][0], timeCall[1][15][1], timeCall[1][15][2])
                    );
    
                GP.BOX_END();
    
            GP.BLOCK_END();
    
            GP.HR();
    
            GP.BLOCK_BEGIN(GP_THIN, "60%", "Среда", GP_DEFAULT);
    
                GP.BOX_BEGIN();
                
                    GP.LABEL("1 ПАРА");                     // Среда 1 пара
                    GP.TIME(
                        "coup2.0.0",
                        GPtime(timeCall[2][0][0], timeCall[2][0][1], timeCall[2][0][2])
                    );
                    GP.TIME(
                        "coup2.0.1",
                        GPtime(timeCall[2][1][0], timeCall[2][1][1], timeCall[2][1][2])
                    );
                    GP.TIME(
                        "coup2.0.2",
                        GPtime(timeCall[2][2][0], timeCall[2][2][1], timeCall[2][2][2])
                    );
                    GP.TIME(
                        "coup2.0.3",
                        GPtime(timeCall[2][3][0], timeCall[2][3][1], timeCall[2][3][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();
    
                    GP.LABEL("2 ПАРА");                     // Среда 2 пара
                    GP.TIME(
                        "coup2.1.0",
                        GPtime(timeCall[2][4][0], timeCall[2][4][1], timeCall[2][4][2])
                    );
                    GP.TIME(
                        "coup2.1.1",
                        GPtime(timeCall[2][5][0], timeCall[2][5][1], timeCall[2][5][2])
                    );
                    GP.TIME(
                        "coup2.1.2",
                        GPtime(timeCall[2][6][0], timeCall[2][6][1], timeCall[2][6][2])
                    );
                    GP.TIME(
                        "coup2.1.3",
                        GPtime(timeCall[2][7][0], timeCall[2][7][1], timeCall[2][7][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();
    
                    GP.LABEL("3 ПАРА");                     // Среда 3 пара
                    GP.TIME(
                        "coup2.2.0",
                        GPtime(timeCall[2][8][0], timeCall[2][8][1], timeCall[2][8][2])
                    );
                    GP.TIME(
                        "coup2.2.1",
                        GPtime(timeCall[2][9][0], timeCall[2][9][1], timeCall[2][9][2])
                    );
                    GP.TIME(
                        "coup2.2.2",
                        GPtime(timeCall[2][10][0], timeCall[2][10][1], timeCall[2][10][2])
                    );
                    GP.TIME(
                        "coup2.2.3",
                        GPtime(timeCall[2][11][0], timeCall[2][11][1], timeCall[2][11][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();
    
                    GP.LABEL("4 ПАРА");                     // Среда 4 пара
                    GP.TIME(
                        "coup2.3.0",
                        GPtime(timeCall[2][12][0], timeCall[2][12][1], timeCall[2][12][2])
                    );
                    GP.TIME(
                        "coup2.3.1",
                        GPtime(timeCall[2][13][0], timeCall[2][13][1], timeCall[2][13][2])
                    );
                    GP.TIME(
                        "coup2.3.2",
                        GPtime(timeCall[2][14][0], timeCall[2][14][1], timeCall[2][14][2])
                    );
                    GP.TIME(
                        "coup2.3.3",
                        GPtime(timeCall[2][15][0], timeCall[2][15][1], timeCall[2][15][2])
                    );
    
                GP.BOX_END();
    
            GP.BLOCK_END();
    
            GP.HR();
    
            GP.BLOCK_BEGIN(GP_THIN, "60%", "Четверг", GP_DEFAULT);
    
                GP.BOX_BEGIN();
                
                    GP.LABEL("1 ПАРА");                     // Четверг 1 пара
                    GP.TIME(
                        "coup3.0.0",
                        GPtime(timeCall[3][0][0], timeCall[3][0][1], timeCall[3][0][2])
                    );
                    GP.TIME(
                        "coup3.0.1",
                        GPtime(timeCall[3][1][0], timeCall[3][1][1], timeCall[3][1][2])
                    );
                    GP.TIME(
                        "coup3.0.2",
                        GPtime(timeCall[3][2][0], timeCall[3][2][1], timeCall[3][2][2])
                    );
                    GP.TIME(
                        "coup3.0.3",
                        GPtime(timeCall[3][3][0], timeCall[3][3][1], timeCall[3][3][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();
    
                    GP.LABEL("2 ПАРА");                     // Четверг 2 пара
                    GP.TIME(
                        "coup3.1.0",
                        GPtime(timeCall[3][4][0], timeCall[3][4][1], timeCall[3][4][2])
                    );
                    GP.TIME(
                        "coup3.1.1",
                        GPtime(timeCall[3][5][0], timeCall[3][5][1], timeCall[3][5][2])
                    );
                    GP.TIME(
                        "coup3.1.2",
                        GPtime(timeCall[3][6][0], timeCall[3][6][1], timeCall[3][6][2])
                    );
                    GP.TIME(
                        "coup3.1.3",
                        GPtime(timeCall[3][7][0], timeCall[3][7][1], timeCall[3][7][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();
    
                    GP.LABEL("3 ПАРА");                     // Четверг 3 пара
                    GP.TIME(
                        "coup3.2.0",
                        GPtime(timeCall[3][8][0], timeCall[3][8][1], timeCall[3][8][2])
                    );
                    GP.TIME(
                        "coup3.2.1",
                        GPtime(timeCall[3][9][0], timeCall[30][9][1], timeCall[3][9][2])
                    );
                    GP.TIME(
                        "coup3.2.2",
                        GPtime(timeCall[3][10][0], timeCall[3][10][1], timeCall[3][10][2])
                    );
                    GP.TIME(
                        "coup3.2.3",
                        GPtime(timeCall[3][11][0], timeCall[3][11][1], timeCall[3][11][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();
    
                    GP.LABEL("4 ПАРА");                     // Четверг 4 пара
                    GP.TIME(
                        "coup3.3.0",
                        GPtime(timeCall[3][12][0], timeCall[3][12][1], timeCall[3][12][2])
                    );
                    GP.TIME(
                        "coup3.3.1",
                        GPtime(timeCall[3][13][0], timeCall[3][13][1], timeCall[3][13][2])
                    );
                    GP.TIME(
                        "coup3.3.2",
                        GPtime(timeCall[3][14][0], timeCall[3][14][1], timeCall[3][14][2])
                    );
                    GP.TIME(
                        "coup3.3.3",
                        GPtime(timeCall[3][15][0], timeCall[3][15][1], timeCall[3][15][2])
                    );
    
                GP.BOX_END();
    
            GP.BLOCK_END();
    
            GP.HR();
    
            GP.BLOCK_BEGIN(GP_THIN, "60%", "Пятница", GP_DEFAULT);
    
                GP.BOX_BEGIN();
                
                    GP.LABEL("1 ПАРА");                     // Пятница 1 пара
                    GP.TIME(
                        "coup4.0.0",
                        GPtime(timeCall[4][0][0], timeCall[4][0][1], timeCall[4][0][2])
                    );
                    GP.TIME(
                        "coup4.0.1",
                        GPtime(timeCall[4][1][0], timeCall[4][1][1], timeCall[4][1][2])
                    );
                    GP.TIME(
                        "coup4.0.2",
                        GPtime(timeCall[4][2][0], timeCall[4][2][1], timeCall[4][2][2])
                    );
                    GP.TIME(
                        "coup4.0.3",
                        GPtime(timeCall[4][3][0], timeCall[4][3][1], timeCall[4][3][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();
    
                    GP.LABEL("2 ПАРА");                     // Пятница 2 пара
                    GP.TIME(
                        "coup4.1.0",
                        GPtime(timeCall[4][4][0], timeCall[4][4][1], timeCall[4][4][2])
                    );
                    GP.TIME(
                        "coup4.1.1",
                        GPtime(timeCall[4][5][0], timeCall[4][5][1], timeCall[4][5][2])
                    );
                    GP.TIME(
                        "coup4.1.2",
                        GPtime(timeCall[4][6][0], timeCall[4][6][1], timeCall[4][6][2])
                    );
                    GP.TIME(
                        "coup4.1.3",
                        GPtime(timeCall[4][7][0], timeCall[4][7][1], timeCall[4][7][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();
    
                    GP.LABEL("3 ПАРА");                     // Пятница 3 пара
                    GP.TIME(
                        "coup4.2.0",
                        GPtime(timeCall[4][8][0], timeCall[4][8][1], timeCall[4][8][2])
                    );
                    GP.TIME(
                        "coup4.2.1",
                        GPtime(timeCall[4][9][0], timeCall[4][9][1], timeCall[4][9][2])
                    );
                    GP.TIME(
                        "coup4.2.2",
                        GPtime(timeCall[4][10][0], timeCall[4][10][1], timeCall[4][10][2])
                    );
                    GP.TIME(
                        "coup4.2.3",
                        GPtime(timeCall[4][11][0], timeCall[4][11][1], timeCall[4][11][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();
    
                    GP.LABEL("4 ПАРА");                     // Пятница 4 пара
                    GP.TIME(
                        "coup4.3.0",
                        GPtime(timeCall[4][12][0], timeCall[4][12][1], timeCall[4][12][2])
                    );
                    GP.TIME(
                        "coup4.3.1",
                        GPtime(timeCall[4][13][0], timeCall[4][13][1], timeCall[4][13][2])
                    );
                    GP.TIME(
                        "coup4.3.2",
                        GPtime(timeCall[4][14][0], timeCall[4][14][1], timeCall[4][14][2])
                    );
                    GP.TIME(
                        "coup4.3.3",
                        GPtime(timeCall[4][15][0], timeCall[4][15][1], timeCall[4][15][2])
                    );
    
                GP.BOX_END();
    
            GP.BLOCK_END();
    
            GP.HR();
    
            GP.BLOCK_BEGIN(GP_THIN, "60%", "Суббота", GP_DEFAULT);
    
                GP.BOX_BEGIN();
                
                    GP.LABEL("1 ПАРА");                     // Суббота 1 пара
                    GP.TIME(
                        "coup5.0.0",
                        GPtime(timeCall[5][0][0], timeCall[5][0][1], timeCall[5][0][2])
                    );
                    GP.TIME(
                        "coup5.0.1",
                        GPtime(timeCall[5][1][0], timeCall[5][1][1], timeCall[5][1][2])
                    );
                    GP.TIME(
                        "coup5.0.2",
                        GPtime(timeCall[5][2][0], timeCall[5][2][1], timeCall[5][2][2])
                    );
                    GP.TIME(
                        "coup5.0.3",
                        GPtime(timeCall[5][3][0], timeCall[5][3][1], timeCall[5][3][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();
    
                    GP.LABEL("2 ПАРА");                     // Суббота 2 пара
                    GP.TIME(
                        "coup5.1.0",
                        GPtime(timeCall[5][4][0], timeCall[5][4][1], timeCall[5][4][2])
                    );
                    GP.TIME(
                        "coup5.1.1",
                        GPtime(timeCall[5][5][0], timeCall[5][5][1], timeCall[5][5][2])
                    );
                    GP.TIME(
                        "coup5.1.2",
                        GPtime(timeCall[5][6][0], timeCall[5][6][1], timeCall[5][6][2])
                    );
                    GP.TIME(
                        "coup5.1.3",
                        GPtime(timeCall[5][7][0], timeCall[5][7][1], timeCall[5][7][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();
    
                    GP.LABEL("3 ПАРА");                     // Суббота 3 пара
                    GP.TIME(
                        "coup5.2.0",
                        GPtime(timeCall[5][8][0], timeCall[5][8][1], timeCall[5][8][2])
                    );
                    GP.TIME(
                        "coup5.2.1",
                        GPtime(timeCall[5][9][0], timeCall[5][9][1], timeCall[5][9][2])
                    );
                    GP.TIME(
                        "coup5.2.2",
                        GPtime(timeCall[5][10][0], timeCall[5][10][1], timeCall[5][10][2])
                    );
                    GP.TIME(
                        "coup5.2.3",
                        GPtime(timeCall[5][11][0], timeCall[5][11][1], timeCall[5][11][2])
                    );
    
                GP.BOX_END();
                GP.BOX_BEGIN();
    
                    GP.LABEL("4 ПАРА");                     // Суббота 4 пара
                    GP.TIME(
                        "coup5.3.0",
                        GPtime(timeCall[5][12][0], timeCall[5][12][1], timeCall[5][12][2])
                    );
                    GP.TIME(
                        "coup5.3.1",
                        GPtime(timeCall[5][13][0], timeCall[5][13][1], timeCall[5][13][2])
                    );
                    GP.TIME(
                        "coup5.3.2",
                        GPtime(timeCall[5][14][0], timeCall[5][14][1], timeCall[5][14][2])
                    );
                    GP.TIME(
                        "coup5.3.3",
                        GPtime(timeCall[5][15][0], timeCall[5][15][1], timeCall[5][15][2])
                    );
    
                GP.BOX_END();
    
            GP.BLOCK_END();
            GP.HR();
    
            GP.LABEL("Длительность подачи звонка, сек");
            GP.NUMBER("time", "Секунды", duration);
            GP.HR();
    
        GP.BLOCK_END();
    
        GP.HR();
        GP.LABEL("Пароль:");                                // ближе к кнопке разместим поле ввода пароля
        GP.NUMBER("password", "Пароль"); GP.BREAK();
        GP.HR();
        GP.SUBMIT("Принять изменения");
        GP.FORM_END();
        GP.HR();
    }
    
	GP.BUILD_END();
     
}
