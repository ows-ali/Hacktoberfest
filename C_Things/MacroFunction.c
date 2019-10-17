#include "stdio.h"
#define uint unsigned int
#define ZERO 0
#define ONE  1
#define TWO  2

#define ARR_LENGTH(x) (sizeof(x) / sizeof((x)[0]))

#define SUM_2_NUM(a, b) (a + b)


void main()
{
  uint ArrNumber[] = {0, 1, 2};
  uint ResultValue = -99;
  uint count = 0;
  ResultValue = SUM_2_NUM(ONE, TWO);
  printf("Sum of %d and %d is %d\n", ONE, TWO, ResultValue);
  ResultValue = ARR_LENGTH(ArrNumber);
  printf("Length of array [");
  for (count = 0; count < ARR_LENGTH(ArrNumber); count++)
  {
    if (count == (ARR_LENGTH(ArrNumber) - 1))
    {
      printf("%d] is %d\n",ArrNumber[count], ARR_LENGTH(ArrNumber));
    }
    else
    {
      printf("%d, ",ArrNumber[count]);
    }
  }
}