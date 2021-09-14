/*
            Problem URL: https://codeforces.com/problemsets/acmsguru/problem/99999/486
            
             486. "Bulls and Cows"
Time limit per test: 0.25 second(s)
Memory limit: 262144 kilobytes
input: standard
output: standard



You probably know the game "bulls and cows". Just in case, we explain the rules. The first player picks a four-digit number with all digits distinct (leading zero is allowed) and keeps it secret. The second player tries to guess the secret number. For each guess, the first player issues a response in the form "n bulls, m cows". A "bull" is a digit that is present in both the secret and the guess and occurs in the same position in both. A "cow" is a digit that is present in both numbers, but occurs in different positions.

For example, if the first player picked 5071, and the second guessed 6012, the response would be "one bull, one cow". Here the "bull" is the digit 0, as it is in the second position in both numbers, and the "cow" is the digit 1, as it is in the fourth position in the secret, but in the third position in the guess.

Write a program to count the number of cows and bulls for the given the secret and guess.

Input
The first line of the input file contains four digits, the number picked by the first player. The second line contains the number guessed by the second player in the same format.

Output
The first and only line of the output file should contain two integers separated by a space, the number of "bulls" and the number of "cows".


*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod=1000000007;

ll pow(ll base, ll expo)
{
    ll res=1;
    while(expo>0)
    {
    if(expo&1LL==1){
        res=(res*base);
    }
    base= base *base;
    expo>>=1;
    }
    return res;
}

int checkBull(int a, int b)
{
    int t1, t2;
    int bull=0;
    for(int i=0; i<4; i++)
    {
        t1=a%10;
        a=a/10;
        t2=b%10;
        b=b/10;
        if(t1==t2) bull++;
    }
    //bull--;
    return bull;
}

int checkCows(int a, int b)
{
    int arr1[4]={0};
    int arr2[4]={0};
    int cow=0;
    for(int i=0; i<4; i++)
    {
        arr1[i]=a%10;
        arr2[i]=b%10;
        a=a/10;
        b=b/10;
    }
    for(int i=0; i<4; i++)
    {
        int tmp=arr1[i];
        for(int j=0; j<4; j++)
        {
            if(tmp==arr2[j] && i!=j)    cow++;
        }
    }
    return cow;
    
}

int main()
{
   int a, b;
   cin>>a>>b;
   int bull=checkBull(a, b);
   int cow= checkCows(a, b);
  
   cout<<bull<<" "<<cow;
   
   return 0;
    
}
