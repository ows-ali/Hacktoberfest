   /* Here we use the basic concept of multiplication
    * by taking the carry away, and storing the product in array form
    */

#include<iostream>  //Header File

using namespace std;

/* Funtion to multiply the array with a number
 */
void multiply(int arr[200], int* top, int multiplicand){ 
  int product, carry=0;
  
  for(int i = 0; i < *top + 2 ; i++){
    product = (arr[i] * multiplicand) + carry;
    arr[i] = product % 10;
    carry = product / 10;
  }
  
  *top += 2;
}

/* Driver code
 */
int main()
{
  int t;    // Number of testcases
  cin >> t;
  
  while(t--){
    int arr[200], n, top, indexToPrintFrom;
  
    // cout << "Enter a number : ";
    cin >> n;

    for(int ii = 0; ii < 200; ii++)
      arr[ii] = 0;

    /* Initializing first index as 1
     */
    arr[0] = 1;
 
    /* Here variable top will store the maximum index with a non-zero value
     */
    top = 0;

    for(int number = 1; number <= n; number++)
      multiply(arr, &top, number);

    for(indexToPrintFrom = 199; indexToPrintFrom >= 0; indexToPrintFrom--){
      if(arr[indexToPrintFrom] != 0)
        break;
    }

    // cout << "Factorial of " << n << " : ";

    for(int k = indexToPrintFrom ; k >= 0; k--){
      cout << arr[k];
    }
    cout << "\n";
  }
}
