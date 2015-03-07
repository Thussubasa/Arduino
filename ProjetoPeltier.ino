#include <LiquidCrystal.h>
#include <Limits.h>

const int sensorTemp= 0;

int peltier = 13;
int tempPin = 0;
int valorSensorTemp = 0;
int valorTemp = INT_MAX;

LiquidCrystal lcd(9,8,5,4,3,2);

void setup(){
  pinMode(peltier, OUTPUT);
  lcd.begin(16,2);
}
void loop(){
  valorTemp = INT_MAX;
  for(int i=1; i<=6; i++){
    valorSensorTemp = analogRead(sensorTemp);
    valorSensorTemp *= 0.54;
    if (valorSensorTemp < valorTemp){
      valorTemp = valorSensorTemp;
    }
    delay(100);
  }
  if (valorTemp > 35){
    lcd.setCursor(0,1);
    lcd.write("Ligado");
    digitalWrite(peltier, HIGH);
  }
  else{
    lcd.setCursor(0,1);
    lcd.write("Desligado");
    digitalWrite(peltier, LOW);
  }
  delay(100);
  
  lcd.clear();
  lcd.print("Temperatura:");
  lcd.print(valorTemp);
  lcd.write(B11011111);
  lcd.print("C");
  
  delay(2000);
}
