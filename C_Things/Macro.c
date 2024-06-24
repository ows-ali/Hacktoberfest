#include "stdio.h"
#define uint unsigned int
#define ZERO 0
#define ONE  1
#define TWO  2

uint getDefine()
{
  uint uiRetValue = 0;
  #if defined ZERO
  uiRetValue = uiRetValue + ZERO;
  #endif
  #if defined ONE
  uiRetValue = uiRetValue + ONE;
  #endif
  #if defined TWO
  uiRetValue = uiRetValue + TWO;
  #endif
  #if defined THREE
  uiRetValue = uiRetValue + THREE;
  #endif
  return uiRetValue;
}

void main()
{
    uint value = getDefine();
    printf("%d", value);
}