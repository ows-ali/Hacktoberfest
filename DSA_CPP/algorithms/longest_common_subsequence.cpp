#include <iostream>
using namespace std;
   
int lcs(string X, string Y, int m, int n) 
{ 
   int L[m+1][n+1]; 
   int i, j; 
   for (i=0; i<=m; i++) 
   { 
     for (j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
   
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
   
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
   return L[m][n]; 
} 
   
int main() 
{ 
  string X = "AGGTAB"; 
  string Y = "GXTXAYB"; 
   
  int m = X.length(); 
  int n = Y.length(); 
   
  cout<<"Length of LCS is: "<<lcs(X, Y, m, n); 
  
  return 0; 
} 