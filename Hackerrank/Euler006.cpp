#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // t -> number of test cases
    // n -> number for the test case
    // sum1 -> sum of the squares of the first n natural numbers
    // sum2 -> square of the sum of the first n natural numbers

    long int t,n,i,diff,sum1,sum2;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        cin >> n;
        sum1=0,sum2=0;
        for(i=1;i<=n;i++)
        {
            sum1 += pow(i,2);
            sum2 += i;
        }
        sum2=pow(sum2,2);
        diff=abs(sum2-sum1);
        cout<<sum2-sum1<<endl;      
    }
    return 0;
}

