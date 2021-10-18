#include <iostream>
using namespace std;

class Queue
{
    int head;
    int tail;

  public:
    Queue() : tail(-1), head(-1) {}
    int a[10];
    void enQ(int x);
    int deQ();
    bool isEmpty();
};

class Stack
{
  public:
    Queue q1;
    Queue q2;
    Stack()
    {
        Queue q1;
        Queue q2;
    }
    void push(int x);
    int pop();
};

void Queue::enQ(int x)
{
    if (isEmpty())
    {
        a[++head] = x;
        ++tail;
    }
    else
    {
        a[++tail] = x;
    }
}

int Queue::deQ()
{
    if (isEmpty())
    {
        cout << "Underflow!" << endl;
        return 0;
    }
    else
    {
        if (head == tail)
        {
            int d = a[head];
            head = tail = -1;
            return d;
        }
        return a[head++];
    }
}

bool Queue::isEmpty()
{
    return (head == -1) ? true : false;
}

void Stack::push(int x)
{
    q1.enQ(x);
}

int Stack::pop()
{
    if (!q2.isEmpty())
    {
        return q2.deQ();
    }
    else
    {
        while (!q1.isEmpty())
        {
            q2.enQ(q1.deQ());
        }
        return q2.deQ();
    }
}

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    s.push(5);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

}