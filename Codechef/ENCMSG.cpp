//https://www.codechef.com/COOK96B/problems/ENCMSG

#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		//int cha=219;
		//char j;
		char arr[MAX],ch;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];

		for(int i=0;i<n-1;i+=2)
		{
			ch=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=ch;
		}

		

		for(int i=0;i<n;i++)
		{
			switch(arr[i])
			{
				case 'a' :
					arr[i]='z';
					break;
				case 'b' :
					arr[i]='y';
					break;
				case 'c' :
					arr[i]='x';
					break;
				case 'd' :
					arr[i]='w';
					break;
				case 'e' :
					arr[i]='v';
					break;
				case 'f' :
					arr[i]='u';
					break;
				case 'g' :
					arr[i]='t';
					break;
				case 'h' :
					arr[i]='s';
					break;
				case 'i' :
					arr[i]='r';
					break;
				case 'j' :
					arr[i]='q';
					break;
				case 'k' :
					arr[i]='p';
					break;
				case 'l' :
					arr[i]='o';
					break;
				case 'm' :
					arr[i]='n';
					break;
				case 'n' :
					arr[i]='m';
					break;
				case 'o' :
					arr[i]='l';
					break;
				case 'p' :
					arr[i]='k';
					break;
				case 'q' :
					arr[i]='j';
					break;
				case 'r' :
					arr[i]='i';
					break;
				case 's' :
					arr[i]='h';
					break;
				case 't' :
					arr[i]='g';
					break;
				case 'u' :
					arr[i]='f';
					break;
				case 'v' :
					arr[i]='e';
					break;
				case 'w' :
					arr[i]='d';
					break;
				case 'x' :
					arr[i]='c';
					break;
				case 'y' :
					arr[i]='b';
					break;
				case 'z' :
					arr[i]='a';
					break;

			}



			/*for(j=97;j<=122;j++)
			{
				if((int)arr[i]==j)
				{
					//cout<<arr[i]<<" ";
					arr[i]=cha-(int)arr[i];
				}
			}*/
		}
		for(int i=0;i<n;i++)
		{
			cout<<arr[i];
		}
		cout<<endl;

	}
	return 0;
}