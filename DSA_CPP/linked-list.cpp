//github ::https : //github.com/Khawoat6

#include <stdio.h>
#include <iostream>

using namespace std;

struct rec
{
    int data;
    struct rec *next;
    struct rec *prev;

} *head = NULL, *tail = NULL;

/* ======================= MENU ============================*/

void ShowMenu()
{
    cout << "========================\n";
    cout << "          MENU          \n";
    cout << "========================\n";
    cout << "1) Insert \n";
    cout << "2) Delete \n";
    cout << "3) Find \n";
    cout << "4) Print MAX to MIN \n"; // print back to front
    cout << "5) Print Min to MAX \n"; // print front to back
    cout << "6) Count \n";
    cout << "   Please choose > ";
}

/*======================= INSERT ===========================*/
void Insert()
{
    int datain;
    cout << "Input Data :";
    cin >> datain;
    if (head == NULL)
    {
        head = new rec;
        head->data = datain;
        head->prev = NULL;
        head->next = NULL;
        tail = head;
    }
    struct rec *node;
    node = new rec;
    node->data = datain;
    node->prev = NULL;
    node->next = NULL;
    if (node->data < head->data)
    {
        node->next = head;
        head->prev = node;
        head = node;
        return;
    }
    struct rec *temp;
    temp = head;
    while (temp)
    {
        if (temp->next == NULL && temp->data < datain)
        {
            temp->next = node;
            node->prev = temp;
            node->next = NULL;
            tail = node;
        }
        temp = temp->next;
    }
}

/*======================= DELETED ===========================*/
void Deleted()
{
    int datain;
    cout << "Please input : ";
    cin >> datain;
    struct rec *temp;
    temp = head;
    struct rec *tempfree;
    tempfree = head;
    while (temp != NULL)
    {
        if (head->data == datain)
        {
            temp = head;
            head = temp->next;
            delete (temp);
            cout << "Success"
                 << "\n";
            break;
        }
        else if (temp->next->next == NULL && temp->data == datain)
        {
            tempfree = temp->next;
            delete (tempfree);
            temp->next = NULL;
            cout << "Success "
                 << "\n";
            break;
        }
        else if (temp->next->data == datain)
        {
            tempfree = temp->next;
            temp->next = tempfree->next;
            delete (tempfree);
            cout << "\nSuccess "
                 << "\n";
            break;
        }
        temp = temp->next;
        cout << "Not Found"
             << "\n";
        break;
    }
}

/*======================= PRINT MIN TO MAX ===========================*/
void PrintMinToMax()
{
    struct rec *temp;
    temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

/*======================= PRINT MAX TO MIN ===========================*/
void PrintMaxToMin()
{
    struct rec *temp;
    temp = tail;
    if (temp == NULL)
    {
        cout << "Empty";
    }
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << "\n";
}

/*======================= FIND ===========================*/
void Find()
{
    int num;
    int count = 1;
    cout << "What you want to find : ";
    cin >> num;
    struct rec *temp;
    temp = head;
    while (temp != NULL)
    {
        if (num == temp->data)
        {
            cout << "Position = " << count << "\n";
            return;
        }
        count++;
        temp = temp->next;
    }
    cout << " Not found."
         << "\n";
}

/*======================= COUNT ===========================*/
void Count()
{
    //int num;
    int count = 1;

    struct rec *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            cout << "Number = " << count << "\n";
            return;
        }
        count++;
        temp = temp->next;
    }
    cout << " Empty"
         << "\n";
}

/*========================================================*/
/*======================= MAIN ===========================*/
/*========================================================*/

int main()
{
    int choice;
    while (true)
    {
        ShowMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            Insert();
            break;
        case 2:
            Deleted();
            break;
        case 3:
            Find();
            break;
        case 4:
            PrintMaxToMin();
            break;
        case 5:
            PrintMinToMax();
            break;
        case 6:
            Count();
            break;
        }
    }
}
