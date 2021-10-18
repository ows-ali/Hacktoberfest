#include<iostream>
#define stack_size 25
using namespace std;
struct Stack
{
    char A[100];
    int top;
};
char pop(Stack &a)
{
    if(a.top==-1)
    {
        //cout<<"Stack is empty"<<endl;
        return 0;
    }
    char x=a.A[a.top];
    a.top--;
    return x;
}
void push(Stack &a,char x)
{
    if(a.top==stack_size-1)
        cout<<"Stack is full"<<endl;
    else
    {
        a.top++;
        a.A[a.top]=x;
    }
}
void display(Stack a)
{
    while(a.top!=-1)
    {
        cout<<pop(a)<<" ";
    }
    cout<<endl;
}

void balancedparenthesis(Stack &a,char exp[])
{
    int i=0;
    a.top=-1;
    while(exp[i]!='\0')
    {
        if(exp[i]=='{'||exp[i]=='('||exp[i]=='[')
            push(a,exp[i]);
        else
        {
            if((exp[i]==')'&&a.A[a.top]=='(')||(exp[i]=='}'&&a.A[a.top]=='{')||(exp[i]==']'&&a.A[a.top]=='['))
            {
                pop(a);
            }
        }
        display(a);
        i++;
    }
    if(a.top==-1)
        cout<<"Complete";
    else
        cout<<"Incomplete";
}
int main()
{
    char exp[]="([)]";
    Stack a;
    balancedparenthesis(a,exp);
}
