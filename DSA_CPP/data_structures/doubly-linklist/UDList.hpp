//
//  UDList.hpp
//
//  Created by Mehmet Sahin on 9/8/18.
//  Copyright © 2018 Mehmet Sahin. All rights reserved.
//

#ifndef UDList_hpp
#define UDList_hpp

#include <iostream>

template <class x>
struct node{
    x info;
    node<x>* prev;
    node<x>* next;
};

template <class x>
class UDList{
private:
    int length;
    node<x>* head; // a pointer to firt node of the list
    node<x>* tail; // a pointer to last node of the list
    
    /**
     * Copy function to help copy constructor and (=) operator
     * @param other is a reference to UDList<x> object
     */
    void copy(const UDList<x> &other);
    
    /**
     * If length of this object is 0, copy other object
     * @param other is a reference to UDList<x> object
     */
    void copyIfLengthIsZero(const UDList<x>& other);
    
    /**
     * If length of this object and other object is the same, copy other object
     * @param other is a reference to UDList<x> object
     */
    void copyIfLengthIsSame(const UDList<x>& other);
    
    /**
     * If length of this object is smaller than other object's length, copy other object
     * @param other is a reference to UDList<x> object
     */
    void copyIfLengthIsSmaller(const UDList<x>& other);
    
    /**
     * If length of this object is bigger than other object's length, copy other object
     * @param other is a reference to UDList<x> object
     */
    void copyIfLengthIsBigger(const UDList<x>& other);
public:
    typedef node<x>* iterator; // iterator interface for client programs.
    
    UDList(); // default constructor
    UDList(const UDList<x> &other); // copy constructor
    ~UDList(); // destructor
    
    /**
     * Makes the list empty
     */
    void makeEmpty();
    
    /**
     * Is the list empty?
     * @return a bool
     */
    bool isEmpty() const;
    
    /**
     * Overloaded assignment operator to copy other object to this object
     * @param other is a reference to UDList<x> object
     */
    void operator= (const UDList<x> &other);
    
    /**
     * Store item to the front of the list
     * @param item is an x data type
     */
    void insertFront(x item);
    
    /**
     * Store item to the back of the list
     * @param item is an x data type
     */
    void insertBack(x item);
    
    /**
     * Getter to get length of this object
     */
    int getLength() const;
    
    /**
     * Return an pointer that points to the beginning of this list
     */
    iterator begin() const;
    
    /**
     * Return an pointer that points to the end of this list
     */
    iterator end() const;
    
    /**
     * Prints the information of nodes of this list from the front to end
     */
    void printFromFront() const;
    
    /**
     * Prints the information of nodes of this list from the back to beginning
     */
    void printFromBack() const;
};

#endif /* UDList_hpp */






























