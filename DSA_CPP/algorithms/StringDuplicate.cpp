#include <iostream>

using namespace std;
void removestr( char str[])
{ int i;
    if ( str[0]=='\0'|| str[1]=='\0')
      {
    return;
         }

if (str[0]==str[1])
{
    for(  i=0; str[i]!='\0';i++)
       {

       str[i]=str[i+1]; }
       str[i]=str[i+1];
       removestr(str);

}
else
    removestr(str+1);

}

int main()
{
    char str[100];
    cin>>str;
    removestr(str);
    cout<<str;

    return 0;
}
