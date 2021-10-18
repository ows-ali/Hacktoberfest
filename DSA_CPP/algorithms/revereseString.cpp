#include<iostream>
#include<String>
using namespace std;

string reverseString1(string str){

 string reversedStr = "";

    for(int i=str.size()-1; i>=0; i--){

        reversedStr += str[i];
    }
return reversedStr;
}

string reverseString2(string str){

int start =0;
int last = str.size() -1;

char tmp;

while(last>start){
    tmp = str[last];
    str[last] = str[start];
    str[start] = tmp;
    start++;
    last--;
}

return str;

}



char* reverseString3(char* str){

    char *ptrStart, *ptrEnd;
    char tmp;

    ptrStart = str;
    ptrEnd = ptrStart + sizeof(str)-1;

    while (ptrEnd > ptrStart ){
        tmp = *ptrStart; 
        *ptrStart = *ptrEnd;
        *ptrEnd = tmp;

        ptrStart++;
        ptrEnd--;

    }

return str;
}
int main(){
string message;
char str[20];
cout<<"** R e v e r s i n g  S t r i n g N 1 ***";
cout<<endl<<"enter a string: ";
cin>>message;



cout<<"** R e v e r s i n g  S t r i n g N 1 ***"<<endl;
cout<<reverseString1(message);
cout<<endl<<"** R e v e r s i n g  S t r i n g N 2 ***"<<endl;
cout<<endl<<"enter a string: ";
cin>>message;
cout<<endl<<reverseString2(message);
cout<<endl<<"** R e v e r s i n g  S t r i n g N 3 ***"<<endl;
cout<<endl<<"enter a string: ";
cin>>str;
cout<<endl<<reverseString3(str);


}
