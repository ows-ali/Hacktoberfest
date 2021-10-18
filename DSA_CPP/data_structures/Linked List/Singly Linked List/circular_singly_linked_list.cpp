#include <bits/stdc++.h>
using namespace std;

typedef struct singly_node{
	int data;
	struct singly_node* next; //self referenced structure
}snode; //just defined how a node looks like

snode * start; //declaring a pointer to first element of the linked list

class single_cllist{
	public:
	single_cllist(){
		start=NULL; 
	}/*This declares a constructor which is executed everytime an object of this class is declared
	i.e. the global pointer start is assigned a value = NULL*/	
	snode* create_node(int data){
		snode* new_node= new snode;
		new_node->data= data;// same as (*new_node).data
		new_node->next=new_node;// same as (*new_node).next
		return new_node;
	}
	int circular_list_length(snode* start){
		if(start==NULL) return 0;
		snode* temp=start;
		int count=0;
		do{
			count++;
			temp=temp->next;
		}while(temp!=start);
		return count;
	}

	void print_list(snode* start){
		if(start==NULL) {cout<<"List is empty\n"; return;}
		snode* temp=start;
		do{
			cout<<temp->data<<" ";
			temp=temp->next;
		}while(temp!=start);
		return;
	}

	void insert_begin(snode** pstart, int data){
		snode* first=create_node(data);
		if(*pstart==NULL){
			*pstart=first;
			return;
		}
		snode* temp= *pstart;
		while(temp->next!=*pstart){
			temp=temp->next;
		}
		first->next=*pstart;
		temp->next=first;
		*pstart=first;
		return;
	}

	void insert_last(snode** pstart,int data){
		snode* last= create_node(data);
		if(*pstart==NULL){
			*pstart=last;
			 return;
		}
		snode* temp= *pstart;
		while(temp->next!=*pstart){
			temp=temp->next;
		}
		last->next=*pstart;
		temp->next=last;
		return;
	}

	void insert_pos(snode* start,int data,int position){
		snode* pos=create_node(data);
		snode* temp=start;
		for(int i=1;i<position-1;i++)
			temp=temp->next;
		pos->next=temp->next;
		temp->next=pos;
		return;
	}

	void delete_begin(snode** pstart){
		if(*pstart==NULL){
			cout<<"List is empty\n";
			return;
		}
		snode* temp=*pstart;
		snode* curr=*pstart;
		while(curr->next!=*pstart) curr=curr->next;
		curr->next=(*pstart)->next;
		*pstart=(*pstart)->next;
		delete temp;
		return;
	}

	void delete_last(snode** pstart){
		if(*pstart==NULL){
			cout<<"List is empty\n";
			return;
		}
		snode* temp=(*pstart)->next;
		snode* prev=*pstart;
		while(temp->next!=*pstart) {
			temp=temp->next;
			prev=prev->next;
		}
		prev->next=*pstart;
		delete temp;
		return;
	}

	void delete_pos(snode * start, int position){
		snode* temp=start->next; 
		snode* prev=start;
		for(int i=1;i<position-1;i++){
			temp=temp->next;
			prev=prev->next;
		}
		prev->next=temp->next;
		//cout<<"Node to be deleted is "<<temp->data<<"\n";
		delete temp;
		return;
	}
};

int main(){
	snode* temp;
	cout<<"No. of elements in linked list?\n";
	int n; cin>>n;
	cout<<"Creating a linked list with "<<n<<" elements\n";
	single_cllist list1;
	start=list1.create_node(1);
	temp=start;
	for(int i=2;i<=n;i++){
		temp->next=list1.create_node(i);
		temp=temp->next;
	}
	temp->next=start;
	list1.print_list(start);
	cout<<"\n";

	cout<<"Inserting a node at beginning\n";
	list1.insert_begin(&start,0);
	list1.print_list(start);
	cout<<"\nlength of the list = "<<list1.circular_list_length(start);
	cout<<"\n";

	cout<<"Inserting a node at the last\n";
	list1.insert_last(&start,9);
	list1.print_list(start);
	cout<<"\nlength of the list = "<<list1.circular_list_length(start);
	cout<<"\n";

	cout<<"Inserting a node at position 4\n";
	list1.insert_pos(start,27,4);
	list1.print_list(start);
	cout<<"\nlength of the list = "<<list1.circular_list_length(start);
	cout<<"\n";

	cout<<"Deleting the node at the beginning\n";
	list1.delete_begin(&start);
	list1.print_list(start);
	cout<<"\nlength of the list = "<<list1.circular_list_length(start);
	cout<<"\n";

	cout<<"Deleting the node at the end\n";
	list1.delete_last(&start);
	list1.print_list(start);
	cout<<"\nlength of the list = "<<list1.circular_list_length(start);
	cout<<"\n";

	cout<<"Deleting the node at position 4\n";
	list1.delete_pos(start,4);
	list1.print_list(start);
	cout<<"\nlength of the list = "<<list1.circular_list_length(start);
	cout<<"\n";
	return 0;
}