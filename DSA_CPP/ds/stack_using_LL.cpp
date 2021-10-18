class Stack {
    Node *head;
    int size;		// number of elements prsent in stack
    
    public :
    
    Stack() {
        head=NULL;
        size=0;
    }
    
    int getSize() {
        return size;
          
    }
    
    bool isEmpty() {
        if(size==0)
          return true;
        else
          return false;
    }
    
    void push(int element) 
    {
      Node *n=new Node(element);
      size++;
      n->next=head;
      head=n;
      return ;
    }
    
    int pop() 
    {
      if(isEmpty())
        return 0;
     int ans=head->data;
      Node *n1=head;
      head=head->next;
      delete n1;
      size--;
      return ans;
        // Return 0 if stack is empty. Don't display any other message
    }
    
    int top()
    { if(isEmpty())
         return 0;
     return head->data;
        // Return 0 if stack is empty. Don't display any other message
    }
    
    
    
};
