#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct node
{
	string name;
	int tot_count;
	int d_flag;
};
typedef node* nodePtr;
class hashtable
{
	node **Arr;
	int entries;
	int hashsize;
	int succesful;
	int unsuccesful;
	public:
		hashtable(int size)
		{
			entries = 0;
			hashsize = size;
			succesful = unsuccesful =0;
			Arr = new node*[hashsize];
			for(int i=0;i<size;i++)
			{
				Arr[i] = new node;
				Arr[i]->name = "";
				Arr[i]->tot_count = 0;
				Arr[i]->d_flag = 0;
			}
		}

		int check_lambda();
		void insert(string name,int tot_count,int method);
		void find(string n,int method);
		void find_collision(string n,int collision_no,int method);
		void insert_collision(string name,int tot_count,int method,int collision_no);
		node** rehash(int method);
		void rehash(int size,int method);
		void size();
		void print_table();
		int check_lambda1();
		void print_lf();
		void delete_(string name,int method);
		void delete_collision(string name,int method,int collision_no);
		void clear_nodes();
		void s_and_u();
};

int hash_func1(string name);
int hash_func2(string name,int collision_no);
int hash_func3(string name,int collision_no);

