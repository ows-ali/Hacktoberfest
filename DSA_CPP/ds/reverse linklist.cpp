#include<iostream>
#include<stdlib.h>
using namespace std;

	struct node{
		int data;
		struct node *next;
	};
	struct node *head=NULL;
	void create() {
		int x;
		char ch='Y';
		struct node *cpt;
		while(ch=='Y'||ch=='y') {
		cout<<"Enter the Data to be Entered\n";
		cin>>x;
		struct node *ptr=(struct node *)malloc(sizeof(struct node));
		ptr->data=x;
		if(head==NULL)
		{
		head=ptr;
		ptr->next=NULL;}
		else {
			ptr->next=head;
			head=ptr;
		}
		
		cout<<"Enter more elements?(Y/N)"<<flush;
		cin>>ch;
	}
}
	
	void display() {
		struct node *cpt;
		cpt=head;
		while(cpt->next!=NULL) {
			cout<<cpt->data<<"\t";
			cpt=cpt->next;
		}
		cout<<cpt->data;
	}
     void reverse(struct node *cpt) {
		if(cpt->next==NULL) {
			head=cpt;
			return;
		
		}
		reverse(cpt->next);
		struct node *ptr=cpt->next;;
		ptr->next=cpt;
		cpt->next=NULL;
		
	}
	
	int main() {
		cout<<"Enter the link list\n";
		create();
		cout<<"Entered linked list is:\n";
		display();
		cout<<"\nReversed linked list is:\n";
		reverse(head);
		display();
	}
		
		


