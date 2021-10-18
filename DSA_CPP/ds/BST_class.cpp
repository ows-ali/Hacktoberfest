#include<iostream>
using namespace std;
 template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
 
 
int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }
}
 class BST {
    int input;
   public: 
 
    BinaryTreeNode<int>* root = NULL;
  
  
  bool hasData(int input){
    return hasData(root,input); 
  }
  
  BinaryTreeNode<int>* insert(int input){
    root = insert(root,input);
    return root;
  }
  
  BinaryTreeNode<int>* deleteData(int input){
    return deleteData(root,input);
    
  }
  
  void printTree(){
         printTree(root);
    
  }
  
   
  
  
  
  BinaryTreeNode<int>* printTree(BinaryTreeNode<int> *root){
     if(root==NULL){
        return root;
      }
      cout << root->data << ":";
      if(root->left!=NULL){
        cout << "L:" <<root->left->data <<",";
      }
      if(root->right!=NULL){
        cout << "R:" << root->right->data;
      }
      cout << endl;
      printTree(root->left);
      printTree(root->right);
    }
    
  
   BinaryTreeNode<int>* minvalue(BinaryTreeNode<int> *root){
     if(root == NULL)
       return root;
    
    BinaryTreeNode<int>* current = root;
   while(current->left != NULL)
     current = current->left;
    
    return current;
  }
   bool hasData(BinaryTreeNode<int> *root,int input){
   if(root == NULL)
   return false;
  
  if(root->data == input)
     return true;
  
    bool ans;
  
   if(input < root->data){
    ans = hasData(root->left,input);
    }
 else   
   ans = hasData(root->right,input);
    
     if(ans == true)
      return ans;
   
  }
  
   
   BinaryTreeNode<int>* insert(BinaryTreeNode<int> *root,int input) {
    
    BinaryTreeNode<int>* newnode = new BinaryTreeNode<int>(input);
    if(root == NULL)
    {
      root=newnode;
    //  cout << root -> data<< "A" << endl;
		return root;
    }
   // BinaryTreeNode<int>* currnode;
    
    if(input > root->data)
      root->right = insert(root->right,input);
    if(input < root->data)
      root->left = insert(root->left,input);
    
      return root;   
  }
   
  BinaryTreeNode<int> *deleteData(BinaryTreeNode<int> *root,int input){
    
     BinaryTreeNode<int>* delnode = new BinaryTreeNode<int>(input);
     if(root == NULL)
       return root;
    
    if(input < root->data)
      root->left = deleteData(root->left,input);
    else if(input > root->data)
      root->right = deleteData(root->right,input);
    else
    {
      if(root->left == NULL)
      {
        BinaryTreeNode<int>* temp = root->right;
        free(root);
        return temp;
      }
      else if(root->right == NULL)
      {
        BinaryTreeNode<int> *temp = root->left;
        free(root);
        return temp;
      }
      else {
        BinaryTreeNode<int> *temp = minvalue(root->right);
        root->data = temp->data;
        
        root->right = deleteData(root->right,temp->data);
      }
    }
     return root;
  }	
};
