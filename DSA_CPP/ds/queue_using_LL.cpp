template<typename T>
class Queue {
  	
    Node<T> *head;
    Node<T> *tail;
    T size;
	public :


	Queue() 
    {
       head=NULL;
       tail=NULL;
       size=0;
	}

	void enqueue(T data) 
    {
      Node<T> *temp=new Node<T>(data);
      if(head==NULL)
      { head=temp; 
       tail=temp;}
      else
      {
        tail->next=temp;
        tail=temp;
      }
      size++;

	}
	int getSize() 
    {
     return size;
	}
	bool isEmpty() {
		if(head==NULL)
          return true;
        else
          return false;
	}
	T dequeue()
    { 
      if(isEmpty())
        return 0;
    //  else
     // {
       Node <T> *temp = head;
       head=head->next;
       T dta=temp->data;
        delete temp;
   //   }
      size--;
      
      return dta;
	}

	T front()
    {
      return head->data;       
	}
};
