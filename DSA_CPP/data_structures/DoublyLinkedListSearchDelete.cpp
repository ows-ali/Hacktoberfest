#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
using namespace std;

struct Node
{
    int info;

    Node *next;
    Node *prec;
};

///Prototipes -----------------
void InsertionHead(Node *&Head, Node *&Tail);
void PrintList(Node *Head);
Node *FindItem(Node *Head);
void DeleteItem(Node *&Item, Node *&Head, Node *&Tail);
///---------------------------

int main()
{
    srand(time(NULL));

    Node *head = NULL;
    Node *tail = NULL;


    head = NULL;
    tail = NULL;

    cout << endl << "List:" << endl << endl;
    InsertionHead(head, tail);
    PrintList(head);

    cout << endl << endl;
    cout << "Research node: " << endl;
    Node *ptrFind = FindItem(head);
    if(ptrFind!=NULL)
    {
         cout << "Find!!! now this node will be deleted";
         DeleteItem(ptrFind, head, tail);
         PrintList(head);
    }

    else
    {
        cout << endl << endl << "Node not found";
    }



}

void InsertionHead(Node *&Head, Node *&Tail)
{
    int N = 9;         ///Quantità di elementi da inserire
    Node *newNode;

    if(Head == NULL)
    {

        newNode = new Node;
        newNode->info = rand()%50;

        cout << endl << "Node 1 created: " << newNode->info;
        Sleep(500);
        newNode->next = Head;
        newNode->prec = NULL;
        Head = Tail = newNode;      ///L'elemento è unico, quindi sia la testa che la coda puntano a newNode

        for(int i=2; i<=N; i++)
        {
            newNode = new Node;
            newNode->info = rand()%50;

            cout << endl << "Node " << i << " Created: " << newNode->info;
            Sleep(500);
            newNode->next = Head;
            Head->prec = newNode;
            newNode->prec = NULL;
            Head = newNode;
        }
    }

}

void PrintList(Node *Head)
{
    cout << endl << endl << "Print list:" << endl;

    if(Head == NULL)
        cout << endl << "Empty list!";
    else
    {
        int i = 1;
        for(Node *flow=Head; flow != NULL; flow=flow->next)
        {
            cout << endl << i << "^ Node: " << flow->info;
            i++;
        }
    }

    cout << endl << endl;
}

Node *FindItem(Node *Head)
{
    int searchInfo;

    cout << endl << "Insert the info for the research: ";
    cin >> searchInfo;

    for(Node *flow = Head; flow != NULL; flow = flow->next)
    {
        if(flow->info == searchInfo)
            return flow;
    }
}

void DeleteItem(Node *&Item, Node *&Head, Node *&Tail)
{
    if(Item == Head)
    {
        Item->next->prec = NULL;
        Head = Item->next;
        delete Item;
    }
    else
        if(Item == Tail)
        {
            Item->prec->next = NULL;
            Tail = Item->prec;
            delete Item;
        }
        else
        {
            Item->prec->next = Item->next;
            Item->next->prec = Item->prec;
            delete Item;
        }
}

