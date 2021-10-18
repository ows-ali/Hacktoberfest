int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMax
                cout << pq.getMax() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMax() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}
 #include <vector>
class PriorityQueue {
    vector<int> pq;
  public:
  PriorityQueue(){
    
  }
  int getSize(){
    return pq.size();
  }
  
   bool isEmpty() {
        return pq.size() == 0;
    }
  
    int getMax() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
  
 void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] > pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
 
    
    int removeMax() {
      if(pq.size() == 0)
        return 0;
      int minindex;
      int todel = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
      
      int parentindex  = 0;
      int childindex1 = 1;
      int childindex2 = 2;
      while(childindex1 < pq.size()){
      
        if(pq[childindex1] > pq[parentindex] || pq[childindex2] > pq[parentindex]){
         if(pq[childindex1] > pq[childindex2])
            minindex = childindex1;
          else
            minindex = childindex2;
          
          int temp = pq[parentindex];
          pq[parentindex] = pq[minindex];
          pq[minindex] = temp;
          
          parentindex = minindex;
          childindex1 = 2*parentindex + 1;
          childindex2 = 2*parentindex + 2; 
                                                     
        }else
          break;
      }
       return todel;
    }
    
      
   
};
