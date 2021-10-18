#include<iostream>
#include<queue>
#include<complex>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d):data(d),left(NULL),right(NULL){}//if any data member is const then using this list is compulsory
};

node* insertinbst(node* &root,int data)
{
    if(root==NULL)
    {
        root=new node(data);
        return root;
    }
    if(data<root->data)
    {
        root->left=insertinbst(root->left,data);
    }
    else
    {
        root->right=insertinbst(root->right,data);
    }
    return root;
}
node* takeInput()
{
    node* root;
    int data;
    cin>>data;
    while(data!=-1)
    {
        root=insertinbst(root,data);
        cin>>data;
    }
    return root;
}

node* Search(node* root,int key)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data==key)
        return root;
    else if(root->data>key)
    {
        return Search(root->left,key);
    }
    else
        return Search(root->right,key);
}

void preorderTraversal(node* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}


void inorderTraversal(node* root)
{
    if(root!=NULL)
    {
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
}


void postorderTraversal(node* root)
{
    if(root!=NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->data<<" ";
    }
}

void printlevel(node* root)
{
    queue<node*> q;
    cout<<root->data<<" ";
    q.push(root);
    while(!q.empty())
    {
        node* f=q.front();
        q.pop();
        if(f->left!=NULL)
        {
            cout<<f->left->data<<" ";
            q.push(f->left);
        }
        if(f->right!=NULL)
        {
            cout<<f->right->data<<" ";
            q.push(f->right);
        }
    }
}

void printpatternlevel(node* root)
{
    queue<node*> q;
   // cout<<root->data;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* f=q.front();
        q.pop();
        if(f==NULL)
        {
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
            continue;
        }
        cout<<f->data<<" ";
        if(f->left!=NULL)
        {
            //cout<<f->left->data<<" ";
            q.push(f->left);
        }
        if(f->right!=NULL)
        {
            //cout<<f->right->data<<" ";
            q.push(f->right);
        }
    }
}

void normal_print(node* root)
{
    if(root!=NULL)
        cout<<root->data;
    else
        cout<<"tree is empty";
}

void printlist(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->right;
    }
    cout<<endl;
}
istream& operator>>(istream& is,node* &r)
{
    r=takeInput();
    return is;
}
ostream& operator<<(ostream& os,node* &r)
{
    printpatternlevel(r);
    return os;
}

pair<node*,node*> bst_linkedlist(node* root)
{
    if(root==NULL||(root->left==NULL&&root->right==NULL))
    {
        return make_pair(root,root);
    }
    pair<node*,node*> left,right;
    left=bst_linkedlist(root->left);
    right=bst_linkedlist(root->right);
    //root->left=NULL;//left ke faltu ghinone links todne ke liye
    if(root->left!=NULL&&root->right==NULL)
    {
        root->left=NULL;
        left.second->right=root;
        return make_pair(left.first,root);
    }
    else if(root->left==NULL&&root->right!=NULL)
    {
        root->right=right.first;
        return make_pair(root,right.first);
    }
    else
    {
        root->left=NULL;
        left.second->right=root;
        root->right=right.first;
        return make_pair(left.first,right.second);
    }
}
node* arrtotree(int a[],int start,int endi)
{
    node* root=NULL;
    if(start>endi)
        return root;
    int mid=(start+endi)/2;
    root=new node(a[mid]);
    root->left=arrtotree(a,start,mid-1);
    root->right=arrtotree(a,mid+1,endi);
    return root;
}

bool ifbst(node* root ,int min_v=INT_MIN,int max_v=INT_MAX)
{
    if(root==NULL)
        return true;
    bool l,r;
    l=ifbst(root->left,min_v,root->data);
    r=ifbst(root->right,root->data,max_v);
    return (root->data>=min_v&&root->data<=max_v)&&l&&r;
}

bool treeident(node* root1,node* root2)
{
    if(root1==NULL||root2==NULL)
        return root1==root2;
    bool l,r;
    cout<<"hello";
    l=treeident(root1->left,root2->left);
    r=treeident(root1->right,root2->right);
    return (root1->data==root2->data)&&l&&r;
}

node* findMin(node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

node* remove_bst(node* root,int data)
{
    if(root==NULL)
        return root;
    if(root->data==data)
    {
     //1.leaf node
        if(root->left==NULL&&root->right==NULL)
        {
            delete root;
            root=NULL;
            return root;
        }
    //2. one child
        if(root->left!=NULL&&root->right==NULL)
        {
            node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL&&root->right!=NULL)
        {
            node* temp=root->right;
            delete root;
            return temp;
        }
    //3. two child
        if(root->left!=NULL&&root->right!=NULL)
        {
            node* temp=findMin(root->right);
            root->data=temp->data;
            root->right=remove_bst(root->right,temp->data);
            return root;
        }
    }
    else if(root->data>data)
    {
        root->left=remove_bst(root->left,data);
    }
    else
    {
        root->right=remove_bst(root->right,data);
    }
    return root;
}
int main()
{
    node* root=NULL;
    cin>>root;
    cout<<root;
    remove_bst(root,7);
    cout<<root;
    //printlist(bst_linkedlist(root).first);
    //normal_print(Search(root,4));
    /*int a[]={1,2,3,4,5,6,7,8,9};
    int n=((char*)(&a+1)-(char*)(&a))/4;
    cout<<n<<endl;
    node* ar_root=arrtotree(a,0,n-1);
    if(ifbst(ar_root))
        cout<<"bst hai"<<endl;
    else
        cout<<"bst ni hai"<<endl;
    cout<<ar_root;*/
    return 0;
}

