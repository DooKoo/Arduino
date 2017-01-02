int anodPins[] = {A1, A2, A3, A4}; // Задаем пины для кажого разряда
int segmentsPins[] = {5, 6, 7, 8, 9, 10, 11, 12}; //Задаем пины для каждого сегмента (из 7 + 1(точка))

#define SYMBOLS_NUM 23

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(anodPins[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) {
    pinMode(segmentsPins[i], OUTPUT);
  }
}
//p,G,F,E,D,C,B,A
byte name[23] = {
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00110000,
  0b00111000,
  0b00111000,
  0b01101110,
  0b01110111,
  0b00000000,
  0b01101101,
  0b01110100,
  0b01111001,
  0b00011100,
  0b00111001,
  0b01110100,
  0b00111110,
  0b01110110,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
};
byte year[4] = {
  0b01011011,
  0b00111111,
  0b00000110,
  0b00100111
};

int miliSec = 0;

int first_rank_index = 0;
int second_rank_index = 1;
int third_rank_index = 2;
int fourth_rank_index = 3;

void loop() {
  setNumber(0, name[first_rank_index]);
  setNumber(1, name[second_rank_index]);
  setNumber(2, name[third_rank_index]);
  setNumber(3, name[fourth_rank_index]);

  if(miliSec % 50 == 0)
  {
    first_rank_index += 1;
    second_rank_index += 1;
    third_rank_index += 1;
    fourth_rank_index += 1;
  }

  miliSec++;
  if(miliSec == 50 * SYMBOLS_NUM - 200)
  {
    miliSec = 0;
    
    first_rank_index = 0;
    second_rank_index = 1;
    third_rank_index = 2;
    fourth_rank_index = 3;
  }  
}

void setNumber(int numNumber, byte number)
{
  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentsPins[i], bitRead(number,i));
  }

  for(int j = 0; j < 4; j++)
  {
    digitalWrite(anodPins[j], HIGH);
  }      
  
  digitalWrite(anodPins[numNumber], LOW);
  delay(5);
}

