/*Code: Queue Using LL

You need to implement a Queue class using linked list.
All the required data members should be private.
Implement the following public functions :
1. Constructor -
Initialises the data members.
2. enqueue :
This function should take one argument of type T and has return type void. This function should insert an element in the queue. Time complexity should be O(1).
3. dequeue :
This function takes no input arguments and has return type T. This should removes the first element which is entered and return that element as an answer. Time complexity should be O(1).
4. front :
This function takes no input arguments and has return type T. This should return the first element which is entered and return that element as an answer. Time complexity should be O(1).
5. size :
Return the size of stack i.e. count of elements which are present ins stack right now. Time complexity should be O(1).
6. isEmpty :
Checks if the queue is empty or not. Return true or false.
*/

/***************
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		Queue<Integer> st = new Queue<Integer>();

		int choice = s.nextInt();
		int input;

		while (choice !=-1) {
			if(choice == 1) {
				input = s.nextInt();
				st.enqueue(input);
			}
			else if(choice == 2) {
				try {
					System.out.println(st.dequeue());
				} catch (QueueEmptyException e) {
					System.out.println(-1);
				}
			}
			else if(choice == 3) {
				try {
					System.out.println(st.front());
				} catch (QueueEmptyException e) {
					System.out.println(-1);
				}
			}
			else if(choice == 4) {
				System.out.println(st.size());
			}
			else if(choice == 5) {
				System.out.println(st.isEmpty());
			}
			choice = s.nextInt();
		}
	}
}

class Node<T> {
	T data;
	Node<T> next;

	public Node(T data) {
		this.data = data;
	}
}


 ***********/
/*****
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		Queue<Integer> st = new Queue<Integer>();

		int choice = s.nextInt();
		int input;

		while (choice !=-1) {
			if(choice == 1) {
				input = s.nextInt();
				st.enqueue(input);
			}
			else if(choice == 2) {
				try {
					System.out.println(st.dequeue());
				} catch (QueueEmptyException e) {
					System.out.println(-1);
				}
			}
			else if(choice == 3) {
				try {
					System.out.println(st.front());
				} catch (QueueEmptyException e) {
					System.out.println(-1);
				}
			}
			else if(choice == 4) {
				System.out.println(st.size());
			}
			else if(choice == 5) {
				System.out.println(st.isEmpty());
			}
			choice = s.nextInt();
		}
	}
}

class Node<T> {
	T data;
	Node<T> next;

	public Node(T data) {
		this.data = data;
	}
}


 *****/
class QueueEmptyException extends Exception {
  
  /**
  *
  **/
  private static final long serialVersionUID = 1L;
}
public class Queue<T> {
   Node<T> front;
   Node<T> rear;
  int size;
	public Queue() {
front =null;
      rear=null;
      size=0;
	}

	public void enqueue(T data) {
Node<T> newNode = new Node<T>(data);
     if(rear==null)
        {front=newNode; 
       rear=newNode;
          }
      else
      {rear.next=newNode;
      rear=rear.next;
     	}
      size++;
    }

	public int size() {
       return size;
	}

	public boolean isEmpty() {
      return (size==0);
	}

	public T dequeue() throws QueueEmptyException {
      if(front==null)
        { QueueEmptyException e =new QueueEmptyException();
           throw e;}
           T temp=front.data;
      front=front.next;
      //if(size == 1){
		//	rear = null;
	//	}
      size--;
      return temp;
	}

	public T front() throws QueueEmptyException {
      if(front==null)
         { QueueEmptyException e =new QueueEmptyException();
           throw e;
          }
      return front.data;
	}
}