#include <iostream>
#include <malloc.h>
#include <string.h>
using namespace std;

int main()
{
	int tests = 0;
	cin >> tests;
	while(tests--)
	{
		int N = 0 , P = 0 , mid = 0;
		cin >> N >> P;
		if( 3 > P || 3 > N )
		{
			cout << "impossible" << endl;
		}
		else
		{
			char * p_str = (char *) malloc (P+1);
			char * n_str = (char *) malloc (N+1);
			if(0 != P%2)
			{
				mid = 1 + (P/2);
			}
			else
			{
				mid = P/2;
			}
			for(int i = 0 ; i < mid ; ++i)
			{
				if(0 != i%2)
				{
					p_str[i] = 'a';
					p_str[P-1-i] = p_str[i];
				}
				else
				{
					p_str[i] = 'b';
					p_str[P-1-i] = p_str[i];
				}
			}
			strcpy(n_str , p_str);
			for(int i = 1 ; i < N/P ; ++i)
			{
				strcat(n_str , p_str);
			}
			cout << n_str << endl;

		}
	}
	return 0;
}

