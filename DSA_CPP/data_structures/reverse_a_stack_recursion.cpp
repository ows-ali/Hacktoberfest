#include <stack>

void reverseStack(stack<int> &input, stack<int> &extra) {
    if(input.size()==0 || input.size()==1){
        return ;
    }
    
    int topValue = input.top();
    input.pop();
    
    reverseStack(input,extra);
    
    while(!input.empty()){
        int toPush = input.top();
        input.pop();
        extra.push(toPush);
    }
    
    input.push(topValue);
    
    while(!extra.empty()){
        int toPush = extra.top();
        extra.pop();
        input.push(toPush);
    }
}