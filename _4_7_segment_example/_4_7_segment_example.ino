int anodPins[] = {A1, A2, A3, A4}; // Задаем пины для кажого разряда
int segmentsPins[] = {5, 6, 7, 8, 9, 10, 11, 12}; //Задаем пины для каждого сегмента (из 7 + 1(точка))

void setup() {
  // Все выходы программируем как OUTPUT
  for (int i = 0; i < 4; i++) {
    pinMode(anodPins[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) {
    pinMode(segmentsPins[i], OUTPUT);
  }
  //Serial.begin(9600);
}
//p,G,F,E,D,C,B,A
byte name[4] = {
  0b00111000,
  0b00111110,
  0b00111001,
  0b01101110
};

void loop() {
  for(int i = 0; i < 4; i++)
  {
    setNumber(i,name[i]); 
  } 
}

void setNumber(int numNumber, byte number)
{
  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentsPins[i], bitRead(number,i));
  }

  for(int j = 0; j < 4; j++)
  {
    digitalWrite(anodPins[j], HIGH); // Подали напряжение на анод - все индикаторы загорелись
  }      
  
  digitalWrite(anodPins[numNumber], LOW); // Сняли напряжение с анода, чтобы переключение катодов не вызывали мерцание      
  delay(5); // Дали паузу глазу воспринять
}

