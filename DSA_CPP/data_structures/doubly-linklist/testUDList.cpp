/**
 Doubly Linked List 
 
 @author Copyright © 2018 Mehmet Sahin. All rights reserved.
 @version 1.1 Created by Mehmet Sahin on 9/8/18.
 */


#include <iostream>
#include "UDList.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    UDList<int> ud;
    ud.insertBack(10);
    ud.insertBack(20);
    ud.insertBack(30);
    ud.printFromFront();
    ud.makeEmpty();
    ud.printFromFront();
    
    return 0;
}