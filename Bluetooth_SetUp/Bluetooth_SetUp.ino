int pwrBT= 7;
char numb [16] = "IoT";
char speedo = '4';
char pin[5] = "0000";

void setup() {
  // put your setup code here, to run once:
  pinMode(pwrBT, OUTPUT);

  digitalWrite(pwrBT, HIGH);

  Serial.begin(9600);
  Serial.print("AT");
  delay(1000);
  Serial.print("AT+NAME");
  Serial.print(numb);
  delay(1000);

  Serial.print("AT+BAUD");
  Serial.print(speedo);
  delay(1000);

  Serial.print("AT+PIN");
  Serial.print(pin);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

}
