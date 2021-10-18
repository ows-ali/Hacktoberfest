#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vi vector<int>


struct node
{
	int data;
	node* left;
	node* right;
};

node* newNode(int n){
	node* temp = new node();
	temp->left = NULL;
	temp->right = NULL;
	temp->data = n;
	return temp;
}

void reverseLevelOrder(node* root){
	queue<node*> q;
	stack<node*> s;
	q.push(root);
	while(!q.empty()){
		node* temp = q.front();
		s.push(temp);
		q.pop();
		if(temp->right){
			q.push(temp->right);
		}
		if(temp->left){
			q.push(temp->left);
		}
	}
	while(!s.empty()){
		cout << s.top()->data << " ";
		s.pop();
	}
}

int main(){
	node* root = newNode(12);
	root->left = newNode(9);
	root->left->right = newNode(10);
	root->left->left = newNode(8);
	root->right = newNode(13);
	root->right->right = newNode(14);
	reverseLevelOrder(root);
	return 0;
}