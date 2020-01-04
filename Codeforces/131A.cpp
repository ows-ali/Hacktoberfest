#include<iostream>
#include<ctype.h>
using namespace std;
 
int main(){
    char s[240];
    cin>>s;
    string t = s;
    int c = 0;
    int d = 0;
    for(int i = 0; t[i] != '\0' ; i++){
        if(islower(s[i])){
            d = 1;
            break;
        }
    }
 
    if(islower(s[0])){
        s[0] = toupper(s[0]);
    }
    else if(isupper(s[0])){
        if(islower(s[1])){
            c = 1;
        }
    }
    
    if (c == 0 )
        for(int i = 1 ; s[i] != '\0' ; i++){
            
            if(isupper(s[i])){
                s[i] = tolower(s[i]);
            }
            else{
                c = 1;
            }
        }
    
    if(d == 0){
        s[0] = tolower(s[0]);
    }  
    if(c == 1){
        cout<<t<<endl;
    }
    else{
        cout<<s<<endl;        
    }
 
    return 0;
}