//This is a sample program to implement Trie Data Structure. It includes insertion, deletion and searching in Trie.

#include<bits/stdc++.h>
#define loop(a, b) for(int i=a; i<b;i++) //macros
#define num_of_strings 8
using namespace std;

struct TrieNode{ //trie node defined as a structure
struct TrieNode* alpha[26];
int TerminateCount;
};

struct TrieNode* NewNode() //function to create a new node and initialize
{
    struct TrieNode* node = new TrieNode;
    loop(0, 26)
    {
        node->alpha[i] = NULL;
    }
    node->TerminateCount = 0;
    return node;
}

void insert(struct TrieNode* root, string s) //function to insert in a Trie
{
    int len = s.size();
    struct TrieNode* temp = root;
    loop(0, len)
    {
        int index = s[i] - 'a';
        if(!temp->alpha[index])
        {
            temp->alpha[index] = NewNode();
        }
        temp = temp -> alpha[index];

    }
    temp->TerminateCount = 1;
     cout<<"inserted "<<s<<endl;
}

bool search(struct TrieNode* root, string s) //function to search a given string in Trie
{
        int len = s.size();
    struct TrieNode* temp = root;
    loop(0, len)
    {
        int index = s[i] - 'a';
        if(!temp->alpha[index])
        {
            return false;
        }
        temp = temp->alpha[index];
    }
    return (temp->TerminateCount && temp!=NULL);
}

int main()
{
    string arr[8] = {"hello", "he", "where", "when", "number", "elder", "search", "their" };
    struct TrieNode* root = NewNode();
    loop(0, num_of_strings)
    {
        insert(root, arr[i]);
    }
    cout<<"\n\n";
    string s = "elder";
    if(search(root, s))
        cout<<"Found\n";
    else
        cout<<"Not Found\n";

    string s2 = "nbdh";
    if(search(root, s2))
        cout<<"Found\n";
    else
        cout<<"Not Found\n";
    return 0;
}
