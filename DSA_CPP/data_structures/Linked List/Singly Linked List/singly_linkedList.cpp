#include<iostream>
using namespace std;

template <class T>
struct Node{

	T data;
	Node* next;

	Node(T val){
		this->data = val;
		this->next = NULL;
	}
};

template <class T>
class LinkedList{

	Node<T> *head;
	
	public:
	
	LinkedList(){
		head = NULL;
	}
	
	void insert(T data){

		if(head == NULL){
			head = new Node<T>(data);
		}else{
			Node<T>* curr = head;
			while(curr->next != NULL)curr = curr->next;
			curr->next = new Node<T>(data);
		}

	}	
	
	T remove(int index){
	
		Node<T> *prev = NULL, *curr = head;
		int i = 0;
		T data;
		
		while(i != index && curr != NULL){
			prev = curr;
			curr = curr->next;
			i++;
		}
		
		if(curr == NULL){
			data = NULL;
		}
		else{
			if(prev == NULL){
				head = curr->next;
			}else{
				prev->next = curr->next;
			}
			data = curr->data;
			delete curr;
		}
		
		return data;		
	
	}
	
	void display(){

		Node<T>* curr = head;
		
		cout << endl;
		while(curr != NULL){
			cout << curr->data << " ";
			curr = curr->next; 
		}
		cout << endl;

	}
	
};

int main(){

	LinkedList<int> lst;
	
	lst.insert(1);
	lst.insert(2);
	lst.insert(3);
	lst.insert(4);
	lst.insert(5);
	
	lst.display();
	
	lst.remove(0);
	lst.remove(6);
	
	lst.insert(1);
	
	lst.display();
			
	return 0;

}
