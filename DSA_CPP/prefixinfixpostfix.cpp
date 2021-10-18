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

int prec(char c)
{
    switch(c)
    {
        case '$':return 0;
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
    }
}

int operand(char c)
{
    if(c>='a'&&c<='z')
        return 1;
    return 0;
}

int operat(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='$')
        return 1;
    return 0;
}
char* postfixconv(Stack &a,char infix[])
{
    char *postfix=new char[stack_size];
    a.top=-1;
    push(a,'$');
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        if(operand(infix[i]))//if we encounter an alphabet
            postfix[j++]=infix[i++];
        else if(operat(infix[i]))//if we encounter an operator
        {
            while((prec(infix[i])<=prec(a.A[a.top]))&&a.top>0&&a.A[a.top]!='(')
            /* if precedence of current operator in infix is less than or equal to
            precedence of operator on top of stack, pop it from stack and insert in output*/
            {
                //cout<<a.top;
                postfix[j++]=pop(a);
            }
            //Insert the current infix operator in stack
            push(a,infix[i++]);
        }
        else if(infix[i]=='(')//if opening bracket simply push in stack
        {
             push(a,infix[i++]);
        }
        else if(infix[i]==')')//pop and push in output until an opening bracket is encountered
        {
            char c=pop(a);
            while(c!='(')
            {
                postfix[j++]=c;
                c=pop(a);
            }
            i++;
        }
        postfix[j]='\0';
       // cout<<postfix<<"     ";
        display(a);//checking the status of stack after every iteration
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
    Stack a;
    char input[]="((a+b)-((c-d)*e)/f)*g$";
    char* postfix;
    postfix=postfixconv(a,input);
    cout<<postfix[12]<<endl;
    cout<<postfix;
    return 0;
}
