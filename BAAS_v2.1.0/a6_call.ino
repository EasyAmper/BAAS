void call() {
  Serial.println("Call !");
  digitalWrite(CALL, LOW);
  delay(duration);
  digitalWrite(CALL, HIGH);
  Serial.println("Call OFF");
}
