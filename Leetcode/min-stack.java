class MinStack {

    /** initialize your data structure here. */
    int top = -1,min=2147483647;
    int max=10000000,p;
    int stk[] = new int[max];
    
    public void push(int x) {
        if(top==-1){
            min=2147483647;
        }
        if(x<min){
            min=x;
        }
        stk[++top]=x;
    }
    
    public void pop() {
        System.out.println(stk[top]);
        if(stk[top]==min){
            top--;
            min=stk[0];
            for(int i=1;i<=top;i++){
                if(stk[i]<=min){
                    min=stk[i];
                }
            }
        }
        else
            top--;
    }
    
    public int top() {
        p = stk[top];
        return p;
    }
    
    public int getMin() {
        return min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
