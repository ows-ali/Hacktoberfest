#include<iostream>
#include<string>
using namespace std;
template <class t>
struct node
{
    t val;
    node<t>* l;
    node<t>* r;

};
template<class t>
class bst
{
private:
     void search_pos(node<t>* temp,node<t>* root)
    {
        if ((temp->val > root->val) && (root->r != NULL))
            search_pos(temp,root->r);
        if ((temp->val > root->val) && (root->r == NULL))
            root->r = temp;
        if ((temp->val < root->val) && (root->l != NULL))
            search_pos(temp,root->l);
        if ((temp->val < root->val) && (root->l == NULL))
            root->l = temp;
    }
public:
   node<t>* root=NULL;
    void insertnode()
    {
        node<t>* temp =new node<t>;
        t n;
        cin>>n;
        temp->val= n;
        temp->l = temp->r = NULL;
        if (root == NULL)
            root = temp;
        else
            search_pos(temp , root);
    }

    void inorder(node<t>*root)
    {
        if(root!=NULL)
        {

            inorder(root->l);
            t n = root->val;
            cout<<"\t"<<n;
            inorder(root->r);
        }
    }

};
int main()
{

    int n;
    cout<<"\n 1...Integer\n 2... Character\n 3...Double\n 4... String";
    cout<<"\nEnter your choice:- ";
    cin>>n;
    switch(n)
    {
    case 1:
       {
            bst<int>obj;
            do
            {
                cout<<"Enter value to be inserted:- ";
                obj.insertnode();
                cout<<"\nDo u want to insert more ?? if yes enter 1 else 0:- ";
                cin >> n;
            }while(n!=0);
            obj.inorder(obj.root);
            break;
        }

    case 2:
        {

            bst<char>obj;
            do
            {
                cout<<"Enter value to be inserted:- ";
                obj.insertnode();
                cout<<"\nDo u want to insert more ?? if yes enter 1 else 0:- ";
                cin >> n;
            }while(n!=0);
            obj.inorder(obj.root);
            break;
        }

    case 3:
        {
            bst<float>obj;
            do
            {
                cout<<"Enter value to be inserted:- ";
                obj.insertnode();
                cout<<"\nDo u want to insert more ?? if yes enter 1 else 0:- ";
                cin >> n;
            }while(n!=0);
            obj.inorder(obj.root);
            break;
        }

    case 4:
        {
            bst<string>obj;
            do
            {
                cout<<"Enter value to be inserted:- ";
                obj.insertnode();
                cout<<"\nDo u want to insert more ?? if yes enter 1 else 0:- ";
                cin >> n;
            }while(n!=0);
            obj.inorder(obj.root);
            break;
        }
    default:
        cout<<"\nWrong choice";
        break;
    }
    return 0;
}
