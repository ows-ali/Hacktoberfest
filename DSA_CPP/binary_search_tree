using namespace std;

   static bool c = false;
struct node
{
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
    //struct node *temp =  (struct node *)malloc(sizeof(struct node));
    struct node *temp = new node();
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
} ;

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root == NULL)
        return;
        inorder(root->left);
        //printf("%d \n", root->key);
        cout<<root->key<<"  ";
        inorder(root->right);
}
void preorder(struct node *root)
{
    if(root==NULL)
        return;
    cout<<root->key<<"  ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<"  ";
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
} ;

   node* findMin(node*root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
bool Search(node*root,int value)
{
	if(root==NULL)
    {
		return false;
    }
	else if(root->key == value)
	{
		return true;
	}
	else if(value < root-> key)
    {
		Search(root->left,value);
    }
	else if(value > root->key)
    {
		Search(root->right,value);
    }
    return c;
}
node* Delete( node* root,int value)
{
	//c=Search(root,value);
	if(root==NULL)
		return root;
	else if(value< root->key)
	{
		root->left= Delete(root->left,value);
	}
	else if(value> root->key)
	{
		root->right= Delete(root->right,value);
	}

	// Node deletion
	else
	{
		//case 1: Leaf Node
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			root=NULL;
			return root;
		}
		//case 2: one child
		else if(root->left==NULL)
		{
			struct node* temp=root;
			root=root->right;
			delete temp;
			return root;
		}
		else if(root->right==NULL)
		{
			struct node* temp=root;
			root=root->left;
			delete temp;
			return root;
		}
		//case 3: 2 child
		else
		{
			struct node*temp=findMin(root->right);
			root->key=temp->key;
			root->right=Delete(root->right,temp->key);
		}
	}
	return root;

}
int main()
{
    int num,temp,choice;
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    cout<<"Enter No. of Elements to enter : ";
    cin>>num;
    cout<<"Enter Number's :\n";
    for(int i=0 ; i<num ; i++)
    {
        cin>>temp;
        if(root == NULL)
        {
            root = insert(root,temp);
        }
        else
        {
            insert(root,temp);
        }
    }
    // print inoder traversal of the BST
    label:
    cout<<"Enter Choice To Display :1.Inorder 2.PreOrder 3.PostOrder 4.Delete 5.Exit ";
    cin>>choice;
    cout<<"Display :\n";
    switch(choice)
    {
        case 1:inorder(root);
        break;
        case 2:preorder(root);
        break;
        case 3:postorder(root);
        break;
        case 4:cout<<"Enter The Value to delete :";
                cin>>num;
                //if(Search(root,num))
                    Delete(root,num);
                //else
                 //cout<<"No. not Exist \n";
        break;
        case 5: return 0;
        break;
        default : cout<<"Enter A valid Choice \n";
    }
    goto label;
   cout<<endl;
    return 0;
}
