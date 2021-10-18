#include<iostream>
#include<cmath>
using namespace std;

void display(int n, int queen[])
{
	char t;
	for (int i = 0; i < n; ++i)
	{
		cout<<endl;

		for (int j = 0; j <= n; ++j)
		{
			cout << "-------";
		}

		cout<<endl;

		for (int j = 0; j <= n; ++j)
		{
			if( queen[i] == j)
				t = 'Q';
			else
				t = ' ';

			cout << "|"<<t<<"\t";
		}

	}

	cout<<endl;
	for (int j = 0; j <= n; ++j)
		cout << "-------";
	cout<<endl;
	
}


bool place(int x[], int k, int i)
{
	for (int j = 1; j <= k; ++j)
	{
		if( (x[k-j] == i) || abs(k - (k - j)) == abs(x[k-j] - i) )
			return false;
	}

	return true;
}


int queens(int n, int queen[], int k)
{
	static int count = 0;

	if (k == n)
	{

		for (int i = 0; i < n; ++i)
			cout<<queen[i]<<" ";
		cout<<endl;
			display(n, queen);
		cout<<endl;

		//cout<<count<<endl;
		count++;
		return count;
	}

	for (int i = 0; i < n; ++i)
	{

		if(place(queen, k, i) == true)
		{
			queen[k] = i;
			queens(n, queen, k+1);
		} 
		
	}

	return count;

}


int main()
{
	int n;
	cout<<"Problem Statement: There is a n x n board. We have to place n queens on it, such that no two queens face each other horizontally, vertically, diagonally. ";
	cout << "\nEnter n: ";
	cin >> n;
	
	int queen[n];

	for (int i = 0; i < n; ++i)
	{
		queen[i] = -1;
	}

	cout<<"\nNumber of possible ways to place the queens: "<<queens(n, queen, 0);

	cout<<endl;
	
	return 0;
}
