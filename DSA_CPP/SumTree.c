/* This Programm checks that if the given tree is a Sum tree.
 A SumTree is a Binary Tree where the value of a node is equal to sum of the nodes present in its left subtree and right subtree */
 // Author : Sspeedy
 
 #include <stdio.h>
 #include <stdlib.h>
 
/* A binary tree node has data, left child and right child */
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  
/*  sum of values in tree with root 
  as root */
int sum(struct node *root) 
{ 
   if(root == NULL) 
     return 0; 
   return sum(root->left) + root->data + sum(root->right); 
} 

/* returns 1 if sum property holds for the given 
    node and both of its children */
int isSumTree(struct node* node) 
{ 
    int ls, rs; 
  
    /* If node is NULL or it's a leaf node then 
       return true */
    if(node == NULL || 
            (node->left == NULL && node->right == NULL)) 
        return 1; 
  
   /* Get sum of nodes in left and right subtrees */
   ls = sum(node->left); 
   rs = sum(node->right); 
  
   /* if the node and both of its children satisfy the 
       property return 1 else 0*/
    if((node->data == ls + rs)&& 
            isSumTree(node->left) && 
            isSumTree(node->right)) 
        return 1; 
  
   return 0; 
} 
/* Reading Data into the tree */

struct node* newNode(int data) 
{ 
    struct node* node = 
        (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return(node); 
}

int main() 
{ 
    struct node *root  = newNode(26); 
    root->left         = newNode(10); 
    root->right        = newNode(3); 
    root->left->left   = newNode(4); 
    root->left->right  = newNode(6); 
    root->right->right = newNode(3); 
    if(isSumTree(root)) 
        printf("The given tree is a SumTree "); 
    else
        printf("The given tree is not a SumTree "); 
  
    return 0; 
}
