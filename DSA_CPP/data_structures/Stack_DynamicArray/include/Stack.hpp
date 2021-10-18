#ifndef __STACK_H__
#define __STACK_H__

const int SIZE = 10;
template <class T>

class Stack{
private:
	T *items;
	int reserved;
	int n_items;

public:
	Stack();
	Stack(const Stack<T> & p);
	~Stack();
	Stack<T> & operator=(const Stack &p);
	bool empty () const;
	void push (const T &c);
	void pop();
	T & limit();
	const T & limit () const;

private:
	void resize(int n);
	void copy(const Stack &p);
	void free();
};

#endif
