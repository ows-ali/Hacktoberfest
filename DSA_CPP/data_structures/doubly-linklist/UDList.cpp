//
//  UDList.cpp
//  csc311Project1
//
//  Created by Mehmet Sahin on 9/8/18.
//  Copyright © 2018 Mehmet Sahin. All rights reserved.
//

#include "UDList.hpp"

template <class x>
UDList<x>:: UDList()
{
    length = 0;
    head = nullptr;
    tail = nullptr;
};


template <class x>
UDList<x>:: UDList(const UDList<x> &other)
{
    if (other.length > 0){
        length = 0;
        copy(other);
    }
    else{
        std::cout << "List is empty!" << std::endl;
    }
}

template <class x>
UDList<x>:: ~UDList()
{
    makeEmpty();
}

template <class x>
void UDList<x>:: makeEmpty()
{
    if (length > 0){
        node<x>* p;
        while (head != nullptr){
            p = head;
            head = head->next;
            delete p;
        }
        length = 0;
    }
}

template <class x>
bool UDList<x>:: isEmpty() const
{
    return (head == nullptr);
}

template <class x>
void UDList<x>:: operator=(const UDList<x> &other)
{
    copy(other);
}

template <class x>
void UDList<x>:: copy(const UDList<x> &other)
{
    if (other.length > 0) {
        if (length == 0) {                  // if this length = 0
            copyIfLengthIsZero(other);
        } if (length == other.length) {     // if this length == other length
            copyIfLengthIsSame(other);
        } else if (length < other.length) { // if this length < other length
            copyIfLengthIsSmaller(other);
        } else {                            // if this length > other length
            copyIfLengthIsBigger(other);
        }
    } else {
        std::cout << "Other list is empty!" << std::endl;
    }
}

template <class x>
void UDList<x>:: copyIfLengthIsZero(const UDList<x> &other)
{
    node<x>* pother = other.head;
    node<x>* pthis = nullptr;
    node<x>* current = nullptr;
    
    while (pother != nullptr){
        pthis = new node<x>;
        pthis->info = pother->info;
        pthis->next = nullptr;
        if (length == 0){
            head = pthis;
            pthis->prev = nullptr;
            current = head;
        }else{
            pthis->prev = current;
            current->next = pthis;
            current = current->next;
        }
        tail = pthis;
        pother = pother->next;
        ++length;
    }
}

template <class x>
void UDList<x>:: copyIfLengthIsSame(const UDList<x> &other)
{
    node<x>* pthis = head;
    node<x>* pother = other.head;
    while (pthis != nullptr && pother != nullptr){
        pthis->info = pother->info;
        tail = pthis;
        pthis = pthis->next;
        pother = pother->next;
    }
}

template <class x>
void UDList<x>:: copyIfLengthIsSmaller(const UDList<x> &other)
{
    node<x>* pthis = head;
    node<x>* pother = other.head;
    node<x>* current = head;
    while (pthis != nullptr && pother != nullptr){
        pthis->info = pother->info;
        tail = pthis;
        pthis = pthis->next;
        pother = pother->next;
        if (pthis != nullptr)
            current = current->next;
    }
    while (pother != nullptr){
        pthis = new node<x>;
        pthis->info = pother->info;
        current->next = pthis;
        pthis->prev = current;
        tail = pthis;
        
        current = current->next;
        pother = pother->next;
        ++length;
    }
    current->next = nullptr;
}

template <class x>
void UDList<x>:: copyIfLengthIsBigger(const UDList<x> &other)
{
    node<x>* pthis = head;
    node<x>* pother = other.head;
    node<x>* current = head;
    while (pthis != nullptr && pother != nullptr){
        pthis->info = pother->info;
        tail = pthis;
        pthis = pthis->next;
        pother = pother->next;
        if (pother != nullptr)
            current = current->next;
    }
    while (pthis != nullptr){
        current->next = pthis->next;
        delete pthis;
        pthis = current->next;
        --length;
    }
}



template <class x>
void UDList<x>:: insertFront(x item)
{
    node<x>* temp = new node<x>;
    temp->info = item;
    temp->prev = nullptr;

    if (length == 0){
        temp->next = nullptr;
        tail = temp;
    }else{
        head->prev = temp;
        temp->next = head;
    }

    head = temp;
    ++length;
}

template <class x>
void UDList<x>:: insertBack(x item)
{
    node<x>* temp = new node<x>;
    temp->info = item;
    temp->next = nullptr;
    
    if (length == 0){
        temp->prev = nullptr;
        head = temp;
    }else{
        tail->next = temp;
        temp->prev = tail;
    }
    
    tail = temp;
    ++length;
}

template <class x>
int UDList<x>:: getLength() const
{
    return length;
}

template <class x>
node<x>* UDList<x>:: begin() const
{
    return head;
}

template <class x>
node<x>* UDList<x>:: end() const
{
    return tail;
}

template <class x>
void UDList<x>:: printFromFront() const
{
    if (length > 0){
        node<x>* p = head;
        while (p != nullptr){
            std::cout << p->info;
            p = p->next;
        }
        std::cout << std::endl;
    }else{
        std::cout << " List is empty " << std::endl;
    }
}

template <class x>
void UDList<x>:: printFromBack() const
{
    if (length > 0){
        node<x>* p = tail;
        
        while (p != nullptr){
            std::cout << p->info;
            p = p->prev;
        }
        
        std::cout << std::endl;
    }else{
        std::cout << " List is empty " << std::endl;
    }
}




















