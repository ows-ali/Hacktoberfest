#include <bits/stdc++.h>
using namespace std;
bool isInterleaved(char* A, char* B, char* C)
{
    // Find lengths of the two strings
    int M = strlen(A), N = strlen(B);
     bool IL[M+1][N+1];

   for(int x=0;x<M;x++)
   {
       for(int y=0;y<N;y++)
        IL[x][y]=0;
   }
    if ((M+N) != strlen(C))
       return false;
    for (int i=0; i<=M; ++i)
    {
        for (int j=0; j<=N; ++j)
        {
            // two empty strings have an empty string
            // as interleaving
            if (i==0 && j==0)
                IL[i][j] = true;
            else if (i==0 && B[j-1]==C[j-1])
                IL[i][j] = IL[i][j-1];
            else if (j==0 && A[i-1]==C[i-1])
                IL[i][j] = IL[i-1][j];
            else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1])
                IL[i][j] = IL[i-1][j];
            else if (A[i-1]!=C[i+j-1] && B[j-1]==C[i+j-1])
                IL[i][j] = IL[i][j-1];
            else if (A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1])
                IL[i][j]=(IL[i-1][j] || IL[i][j-1]) ;
        }
    }

    return IL[M][N];
}
void findi( char *A, char *B, char *C)
{
    if (isInterleaved(A, B, C))
        cout << C <<" is interleaving of " << A <<" and " << B << endl;
    else
        cout << C <<" is not interleaving of " << A <<" and " << B << endl;
}


int main()
{
    findi("XXY", "XXZ", "XXZXXXY");
    return 0;
}
