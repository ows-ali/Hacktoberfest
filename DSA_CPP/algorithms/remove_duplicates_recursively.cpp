
#include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input) {

  if(input[0] == '\0')
    return;
  
  int len = 0;
  for(; input[len] != '\0'; ++len);
  
  if(input[0] == input[1])
  {
    int j = 1;
    while(j+1 <= len)
    {
      input[j] = input[j+1]; 
      ++j;
    }
    removeConsecutiveDuplicates(input);
  }
  else
 	removeConsecutiveDuplicates(input + 1);

}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
