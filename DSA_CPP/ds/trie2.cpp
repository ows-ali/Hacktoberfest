#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        char ch;
        map<char,node*> h;
        bool isTerminal;

        node(char ch){
            this->ch = ch;
            isTerminal = 0;
        }
};

class trie{
    node* root;
    public:
        trie(){
            root = new node('\0');
        }

        void addWord(string s){
            node* temp = root;
            for(int i=0;s[i]!='\0';i++){
                if(temp->h.find(s[i])!=NULL){
                    temp = temp->h[s[i]];
                }
                else{
                    node* child = new node(s[i]);
                    temp->h[s[i]] = child;
                    temp = child;
                }
            }
            temp->isTerminal = 1;
        }

        bool search(string s){
            node* temp = root;
            for(int i=0;s[i]!='\0';i++){
                if(temp->h.find(s[i])!=NULL){
                    temp = temp->h[s[i]];
                }
                else return false;
            }
            return temp->isTerminal;
        }
};

int main() {
    cout<<"Hello World!";
}
