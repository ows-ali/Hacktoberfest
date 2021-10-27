/******************************************************************************
Alla Konstantinova
https://www.codechef.com/problems/LUCKYNUM
Chef buys a lottery ticket that has a 3
digit code associated with it. He thinks that digit 7
is his lucky digit and brings him good luck. Chef will win some amount in the 
lottery if at least one of the digits of the lottery ticket is 7

Given three digits A, B, and C of the lottery ticket, tell whether Chef wins 
something or not?
*******************************************************************************/

#include <iostream>

using namespace std;
void is_in_bounds(int x)
{
  if (x <= 0 || x >= 9)
  {
    throw "Numbers should be between 0 and 9";
  }
}

int main()
{
  int cases;
  int a, b, c;

  try
  {
    cin >> cases;
    if (cases < 1 || cases > 1001)
      throw "Number of cases should be between 1 and 1000";
    cout << endl;
    string answers[cases];

    for (int i = 0; i < cases; i++)
    {
      cin >> a >> b >> c;
      is_in_bounds(a);
      is_in_bounds(b);
      is_in_bounds(c);

      answers[i] = (a == 7 || b == 7 || c == 7) ? "YES" : "NO";
    }

    for (int i = 0; i < cases; i++)
    {
      cout << answers[i] << endl;
    }
  }
  catch (const char *msg)
  {
    cerr << msg << endl;
  }

  return 0;
}
