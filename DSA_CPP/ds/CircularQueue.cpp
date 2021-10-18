#include <iostream>
#include <limits.h>
using namespace std;

#define MAX 50

class cQueue {
	int cq[MAX];
	int front, rear;
public:
	cQueue()
	{
		front = rear = -1;
	}
	void enQueue(int x);
	int deQueue();
	void Display();
	bool isFull();
	bool isEmpty();
	int size();
};

bool cQueue::isFull()
{
	if(front == 0 && rear == 10 - 1)
	{
		return true ;
	}
	if (front == rear + 1)
	{
		return true;
	}
	return false;
}

bool cQueue::isEmpty()
{
	if(front == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void cQueue::enQueue(int x)
{
	if (isFull())
	{
		cout<<"\nOverflow\n";
		return;
	}
	else
	{
		if(front == -1)
		{
			front = 0;
		}
		rear = (rear+1)%MAX;
		cq[rear] = x;
		cout<<endl<<"Inserted: "<<x<<endl;
	}
}

int cQueue::deQueue()
{
	int y;
	if(isEmpty())
	{
		cout<<"\nUnderflow\n";
		return INT_MIN;
	}
	else
	{
		y = cq[front];
		if(front == rear)
		{
			front = rear = -1;
		}
		else
		{
			front = (front+1)%MAX;
		}
		return y;

	}
}

void cQueue::Display()
{
	int i;
	if(isEmpty())
	{
		cout << endl << "Empty Queue" << endl;
	}
	else
	{
		cout << endl << "Front -> " << front;
		cout << endl << "Elements -> ";
		for(i = front; i != rear; i= (i+1)%10)
		{
			cout << cq[i] << "\t";
		}
		cout << cq[i];
		cout << endl << "Rear -> " << rear;
	}
}

int cQueue :: size()
{
	if(rear >= front)
	{
		return (rear - front) + 1;
	}
	else
	{
		return (10 - (front - rear) + 1);
	}
}

int main()
{
	cQueue cq;
	cq.enQueue(10);
	cq.enQueue(100);
	cq.enQueue(1000);

	cout << endl << "Size of queue: " << cq.size();

	cout << endl << "Removed element: " << cq.deQueue();

	cq.Display();

	return 0;
}