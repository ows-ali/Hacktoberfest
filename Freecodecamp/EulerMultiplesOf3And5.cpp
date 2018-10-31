include <iostream>
using namespace std;
 int main()
{
  int multiples = 0;
  for (int i = 0; i < 1000; i++)
  {
    if ((i % 3 == 0) || (i % 5 == 0))
    {
      multiples++;
    }
  }
  cout << "The amount of numbers between 0 and 1000 that have multiples of both 3 and 5 is " << multiples << endl;
   system("pause");
  return 0;
}
