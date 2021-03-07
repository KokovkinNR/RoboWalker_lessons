#include <Blinker.h>

Blinker::Blinker()
{
  ledPin = 13;
  ledBlink = 100;
  tSys = 0;
  tPre = 0;
  ledFlag = true;
}

Blinker::~Blinker() {}

void Blinker::begin(int ledPin = 13)
{
  pinMode(ledPin, OUTPUT);
}

void Blinker::ledBlinker(unsigned long tSys)
{
  if (tSys - tPre >= ledBlink)
  {
    tPre = tSys;
    ledFlag = !ledFlag;
    digitalWrite(ledPin, ledFlag);
  }
}

void Blinker::setTime(unsigned long tSys)
{
  ledBlinker(tSys);
}