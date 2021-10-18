//
// Created by MohabMohamed on 06/10/18.
//

#include <stdexcept>

template <class T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node();
    Node(T data);
    ~Node();
};

template <class T>
class DoublyLinkedList
{
private:
    int size;
    Node<T>* head;
    Node<T>* tail;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    int Length();
    void PushFront(T data);
    void PushBack(T data);
    T At(int pos);
    void InsertAt(int pos, T data);
    T DeleteAt(int pos);
    void Clear();



};

template <class T>
Node<T>::Node()
{
    next=prev= nullptr;
}

template <class T>
Node<T>::Node(T data)
{
    this->data=data;
    next=prev= nullptr;
}

template <class T>
Node<T>::~Node()
{
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head=tail= nullptr;
    size=0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Clear();
}


template <class T>
int DoublyLinkedList<T>::Length() {
    return size;
}

template <class T>
void DoublyLinkedList<T>::PushFront(T data)
{
    Node<T>* tmp = new Node<T>(data);

    if(head== nullptr)
    {
        head=tail=tmp;
    }
    else
    {
        tmp->next=head;
        head->prev=tmp;
        head=tmp;
    }

    size++;
}

template <class T>
void DoublyLinkedList<T>::PushBack(T data)
{
    Node<T>* tmp = new Node<T>(data);

    if(head== nullptr)
    {
        head=tail=tmp;
    }
    else
    {
        tmp->prev=tail;
        tail->next=tmp;
        tail=tmp;
    }

    size++;
}


template <class T>
T DoublyLinkedList<T>::At(int pos)
{
    if(pos>=size)
        throw std::out_of_range("DoublyLinkedList<T>::At() : index is out of range");

    Node<T>* tmp;
    if(pos<size/2)
    {
        tmp=head;
        int cur=0;

        while(cur<pos)
        {
            tmp=tmp->next;
            cur++;
        }

    }
    else
    {
        tmp=tail;
        int cur=size-1;

        while(cur>pos)
        {
            tmp=tmp->prev;
            cur--;
        }
    }


    return tmp->data;
}

template <class T>
void DoublyLinkedList<T>::InsertAt(int pos, T data)
{
    if(pos>size)
        throw std::out_of_range("DoublyLinkedList<T>::InsertAt() : index is out of range");

    if(pos==0)
    {
        PushFront(data);
        return;
    }

    if(pos==size)
    {
        PushBack(data);
        return;
    }

    Node<T>* newNode=new Node<T>(data);
    Node<T>* tmp;
    if(pos<size/2)
    {
        tmp=head;
        int cur=0;

        while(cur<pos-1)
        {
            tmp=tmp->next;
            cur++;
        }

        newNode->prev=tmp;
        newNode->next=tmp->next;
        tmp->next=newNode;
        newNode->next->prev=newNode;

    }
    else
    {
        tmp=tail;
        int cur=size-1;

        while(cur>pos-1)
        {
            tmp=tmp->prev;
            cur--;
        }

        newNode->prev=tmp;
        newNode->next=tmp->next;
        tmp->next=newNode;
        newNode->next->prev=newNode;

    }
    size++;
}

template <class T>
T DoublyLinkedList<T>::DeleteAt(int pos) {
    if(pos>=size)
        throw std::out_of_range("DoublyLinkedList<T>::InsertAt() : index is out of range");

    T val;
    Node<T>* tmp;
    int cur=0;

    if(pos==0)
    {
        tmp=head;
        val=head->data;
        head=head->next;
        head->prev= nullptr;
        delete tmp;
    }
    else if(pos==size-1)
    {
        tmp=tail;
        val=tail->data;
        tail=tail->prev;
        tail->prev= nullptr;
        delete tmp;
    }
    else
    {
        if(pos<size/2)
        {
            tmp=head;
            int cur=0;

            while(cur<pos)
            {
                tmp=tmp->next;
                cur++;
            }

        }
        else
        {
            tmp=tail;
            int cur=size-1;

            while(cur>pos)
            {
                tmp=tmp->prev;
                cur--;
            }
        }

        tmp->prev->next=tmp->next;
        tmp->next->prev=tmp->prev;
        delete tmp;
    }

    size--;
    return val;
}

template <class T>
void DoublyLinkedList<T>::Clear()
{
    if(size==0)
        return;
    Node<T>* tmp=head->next;
    while(tmp->next != nullptr)
    {
        delete head;
        head = tmp;
        tmp = tmp->next;
    }

    delete head;
    head = tail = nullptr;
    size=0;
}



