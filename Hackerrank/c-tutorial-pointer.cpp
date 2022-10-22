
void update(int *a,int *b) {
    // Complete this function   
     int sum= (*a)+(*b);
     int diff=(*a>*b)?(*a)-(*b): -((*a)-(*b));
    *a=sum;
    *b=diff;
     
}

