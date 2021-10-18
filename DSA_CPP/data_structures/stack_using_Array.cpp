#include <iostream>
#define MAXARRSIZE 10
using namespace std;
const string Empty_Stack = "stack is empty.";
const string Full_Stack = "Unable to insert object, stack is full.";

int ARRstack[MAXARRSIZE];

int top = -1;

void pop()
{
    try
    {
        if(top == -1){throw Empty_Stack;}
        top--;
    }
    catch(string w)
    {
        cerr<<"Unable to eject object, "<<w<<endl;
    }
}
void push(int val)
{
    try
    {
        if(top == MAXARRSIZE-1){throw Full_Stack;}
        top++;
        ARRstack[top] = val;
    }
    catch(string w)
    {
        cerr<<w<<endl;
    }
}
void display()
{
    try
    {
        if(top == -1){throw Empty_Stack;}
        for(int i = 0; i <= top; i++)
            {
                cout<<ARRstack[i]<< " ";
            }
    }
    catch(string w)
    {
        cerr<<"Unable to display, "<<w<<endl;
    }
}
