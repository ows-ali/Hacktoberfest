#include<iostream>
#define stack_size 5
using namespace std;
struct Stack
{
    int A[100];
    int top;
};
int pop(Stack &a)
{
    if(a.top==-1)
    {
        //cout<<"Stack is empty"<<endl;
        return -1;
    }
    int x=a.A[a.top];
    a.top--;
    return x;
}
void push(Stack &a,int x)
{
    if(a.top==stack_size-1)
        return;
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
void queuepush(Stack &a1,int x)
{
    if(a1.top==stack_size-1)
        return;
    else
    {
        a1.top++;
        a1.A[a1.top]=x;
    }
}
int queuepop(Stack &a1,Stack &a2)
{
    if(a2.top==-1)
    {
        int x=pop(a1);
        while(x!=-1)
        {
            push(a2,x);
            x=pop(a1);
        }
    }
    return pop(a2);
}
void dispqueue(Stack a1,Stack a2)
{
    int x=queuepop(a1,a2);
    while(x!=-1)
    {
        cout<<x<<" ";
        x=queuepop(a1,a2);
    }
    cout<<endl;
}
int main()
{
    Stack a1,a2;
    int x;
    a1.top=-1;
    a2.top=-1;
    char choice;
    do
    {
        int x;
        cout<<"Enter the operation you want to perform in queue:"<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case '1':cin>>x;
                     queuepush(a1,x);
            break;
            case '2':cout<<"Element popped is :"<<queuepop(a1,a2)<<endl;
            break;
            case '3':dispqueue(a1,a2);
            break;
            case '4':choice='n';
            break;
        }
    }while(choice!='n');
    return 0;
}
