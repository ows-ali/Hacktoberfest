#include <bits/stdc++.h>
using namespace std;

typedef struct doubly_node{
	int data;
	struct doubly_node* next;
	struct doubly_node* prev;
}dnode;

dnode* start;

class double_llist{
	public:
	double_llist(){
		start=NULL;
	}/*This declares a constructor which is executed everytime an object of this class is declared
	i.e. the global pointer start is assigned a value = NULL*/	
	dnode* create_node(int data){
		dnode* new_node= new dnode;
		new_node->data=data;
		new_node->next=NULL;
		new_node->prev=NULL;
		return new_node;
	}

	void insert_begin(dnode** pstart, int data){
		dnode* first=create_node(data);
		first->next=(*pstart);
		(*pstart)->prev=first;
		(*pstart)=first;
		return;
	}

	void insert_last(dnode* start, int data){
		dnode* last=create_node(data);
		dnode* temp=start;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		last->prev=temp;
		temp->next=last;
		return;
	}

	void insert_pos(dnode* start,int data,int position){
		dnode* new_node=create_node(data);
		dnode* pos=start;
		for(int i=1;i<position-1;i++)
			pos=pos->next;
		new_node->next=pos->next;
		new_node->prev=pos;
		(pos->next)->prev=new_node;
		pos->next=new_node;
		return;
	}

	void delete_begin(dnode** pstart){
		dnode* temp=(*pstart);
		(*pstart)=(*pstart)->next;
		(*pstart)->prev=NULL;
		//temp->next=NULL;
		delete temp;
		return;
	}

	void delete_last(dnode* start){
		dnode* temp=start;
		while(temp->next!=NULL) temp=temp->next;
		(temp->prev)->next=NULL;
		delete temp;
		return;
	}

	void delete_pos(dnode* start,int position){
		if(start==NULL)
			cout<<"List is empty\n";
		else{
			dnode* temp1=start; dnode* temp2=start->next;
			for(int i=1;i<position-1;i++){
				temp2=temp2->next;
				temp1=temp1->next;
			}
			temp1->next=temp2->next;
			(temp2->next)->prev=temp1;
			delete temp2;
		}
		return;
	}

	void print_list(dnode* start){
		if(start==NULL)
			cout<<"List is empty\n";
		else
		{
			dnode* temp=start;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
		return;
	}

	int length_of_list_I(dnode* start){//iterative
		if(start==NULL){
			return 0;
		}
		else{
			int length=0;
			dnode* temp=start;
			while(temp!=NULL){
				length++;
				temp=temp->next;
			}
			return length;
		}
	}
};

int main(){
	double_llist list1;
	dnode* temp;
	cout<<"No. of elements in linked list?\n";
	int n; cin>>n;
	cout<<"Creating a linked list with "<<n<<" elements\n";
	start=list1.create_node(1);
	temp=start;
	for(int i=2;i<=n;i++){
		temp->next=list1.create_node(i);
		temp=temp->next;
	}
	list1.print_list(start);
	cout<<"\n";

	cout<<"Inserting a node at beginning\n";
	list1.insert_begin(&start,0);
	list1.print_list(start);
	cout<<"\nlength of the list = "<<list1.length_of_list_I(start);
	cout<<"\n";

	cout<<"Inserting a node at the last\n";
	list1.insert_last(start,9);
	list1.print_list(start);
	cout<<"\nlength of the list = "<<list1.length_of_list_I(start);
	cout<<"\n";

	cout<<"Inserting a node at position 4\n";
	list1.insert_pos(start,27,4);
	list1.print_list(start);
	cout<<"\nlength of the list = "<<list1.length_of_list_I(start);
	cout<<"\n";

	cout<<"Deleting the node at the beginning\n";
	list1.delete_begin(&start);
	list1.print_list(start);
	cout<<"\nlength of the list = "<<list1.length_of_list_I(start);
	cout<<"\n";

	cout<<"Deleting the node at the end\n";
	list1.delete_last(start);
	list1.print_list(start);
	cout<<"\nlength of the list = "<<list1.length_of_list_I(start);
	cout<<"\n";

	cout<<"Deleting the node at position 4\n";
	list1.delete_pos(start,4);
	list1.print_list(start);
	cout<<"\nlength of the list = "<<list1.length_of_list_I(start);
	cout<<"\n";
	return 0;
}