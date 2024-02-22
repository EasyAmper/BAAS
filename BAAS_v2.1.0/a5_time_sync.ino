void time_sync() {
  if ( WiFi.status() != WL_CONNECTED ) {
    if (millis() - rec > 500) {
      rec = millis();
      Serial.println("synchronization failed");
      WiFi.begin(ssid, password);
    }
  } else {
    if (millis() - syn > timeSyn) {
      syn = millis();
      timeClient.update();
      d = (int)floor((timeClient.getEpochTime()/86400+4)-7*(floor((timeClient.getEpochTime()/86400+4)/7)));
      h = timeClient.getHours();
      m = timeClient.getMinutes();
      s = timeClient.getSeconds();
      Serial.println("successful synchronization");

    }
  }
}
