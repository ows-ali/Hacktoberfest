#include <cassert>
#include <cstring>
#include "Stack.hpp"

template <class T>
Stack<T>::Stack (){
	n_items = 0;
	reserved = SIZE;
	items = new T [SIZE];
}

template <class T>
Stack<T>::Stack (const Stack<T> &p){
	free();
	resize (p.reserved);
	copy (p);
}

template <class T>
Stack<T>::~Stack (){
	free();
}

template <class T>
Stack<T> & Stack<T>::operator=(const Stack<T> &p){
	if (this != &p){
		free();
		resize (p.reservados);
		copy (p);
	}
	return (*this);
}

template <class T>
bool Stack<T>::empty() const{
	return (n_items==0);
}

template <class T>
void Stack<T>::push(const T &c){
	if (n_items==reserved)
		resize (2*reserved);
	items[n_items++] = c;
}

template <class T>
void Stack<T>::pop(){
	assert(n_items>0);
	n_items--;
	if (n_items<reserved/4)
		resize(reserved/2);
}

template <class T>
T & Stack<T>::limit(){
	assert(n_items>0);
	return items[n_items-1];
}

template <class T>
const T & Stack<T>::limit() const{
	assert(n_items>0);
	return items[n_items-1];
}

template <class T>
void Stack<T>::resize (int n){
	T *tmp = new T [n];

	reserved = n;

	for (int i = 0; i < n_items; i++){
		tmp[i] = items[i];
	}
	
	delete [] items;

	items = tmp;
}

template <class T>
void Stack<T>::free (){
	delete [] items;

	items = 0;
	n_items = 0;
	reserved = 0;
}

template <class T>
void Stack<T>::copy (const Stack<T> & p){
	n_items = p.n_items;
	reserved = p.reserveds;

	for (int i = 0; i < n_items; i++){
		items[i] = p.items[i];
	}
}
