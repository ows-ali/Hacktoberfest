#include<iostream>
#include<fstream>
#include<string>
#include "hash.h"
using namespace std;

void hashtable :: s_and_u()
{
	cout<<succesful<<" "<<unsuccesful<<" ";
	print_lf();
}

void hashtable :: print_lf()
{
	float i = (entries*(1.0))/(hashsize*(1.0));
	cout<<i<<endl;
}

void hashtable :: clear_nodes()
{
	for(int i=0;i<hashsize;i++)
	{
		delete Arr[i];
	}
	delete[] Arr;
}

void hashtable :: print_table()
{
	for(int i=0;i<hashsize;i++)
	{
		cout<<Arr[i]->name<<endl;
	}
} 

int hash_func1(string name)
{
	int sum =0;
	for(int i=0;i<name.length();i++)
	{
		sum+=name[i]-'0';
	}
	return sum;
}

int hash_func2(string name,int collision_no)
{
	int sum =0;
	for(int i=0;i<name.length();i++)
	{
		sum+=name[i]-'0';
	}
	return (sum+collision_no);
}

int hash_func3(string name,int collision_no)
{
	int sum =0;
	for(int i=0;i<name.length();i++)
	{
		sum+=name[i]-'0';
	}
	return (sum+(collision_no * collision_no));
}

void hashtable :: size()
{
	cout << hashsize << endl;
	
}

// node** hashtable :: rehash(int method)         //rehash iteratively
// {
// 	int collision_no1 = 0;
// 	node** Arr2 = new node*[2*hashsize];
// 	int hashsize1 = 2*hashsize;
// 	for(int i=0;i<hashsize1;i++)
// 	{
// 		Arr2[i] = new node;
// 		Arr2[i]->name ="";
// 		Arr2[i]->tot_count=0;
// 		Arr2[i]->d_flag=0;
// 	}
// 	for(int i=0;i<hashsize;i++)
// 	{
// 		if(method == 1)
// 		{
// 			int pos = hash_func1(Arr[i]->name)%hashsize1;
// 			if(Arr2[pos]->name=="")
// 			{
// 				Arr2[pos]->name = Arr[i]->name;
// 				Arr2[pos]->tot_count = Arr[i]->tot_count;
// 				Arr2[pos]->d_flag = Arr[i]->d_flag;
// 			}
// 			else
// 			{
// 				collision_no1++;
// 				int pos = hash_func2(Arr[i]->name,collision_no1)%hashsize1;
// 				while(Arr2[pos]->name!="")
// 				{
// 					collision_no1++;
// 					pos = hash_func2(Arr[i]->name,collision_no1)%hashsize1;
// 				}
// 				Arr2[pos]->name = Arr[i]->name; 
// 				Arr2[pos]->tot_count = Arr[i]->tot_count;
// 				Arr2[pos]->d_flag = Arr[i]->d_flag;
// 			}
// 		}
// 		else if(method == 2)
// 		{
// 			int pos = hash_func1(Arr[i]->name)%hashsize1;
// 			if(Arr2[pos]->name=="")
// 			{
// 				Arr2[pos]->name = Arr[i]->name;
// 				Arr2[pos]->tot_count = Arr[i]->tot_count;
// 				Arr2[pos]->d_flag = Arr[i]->d_flag;
// 			}
// 			else
// 			{
// 				collision_no1++;
// 				int pos = hash_func3(Arr[i]->name,collision_no1)%hashsize1;
// 				while(Arr2[pos]->name!="")
// 				{
// 					collision_no1++;
// 					pos = hash_func3(Arr[i]->name,collision_no1)%hashsize1;
// 				}
// 				Arr2[pos]->name = Arr[i]->name; 
// 				Arr2[pos]->tot_count = Arr[i]->tot_count;
// 				Arr2[pos]->d_flag = Arr[i]->d_flag;
// 			}
// 		}
// 	}
// 	delete[] Arr;
// 	hashsize = hashsize1;
// 	return Arr2;
// }

void hashtable :: rehash(int size,int method)          //rehash with given size
{
	int hashsize1 = size;
	hashtable h2(hashsize1);
	for(int i=0;i<hashsize;i++)
	{
		if(Arr[i]->name!="")
		{
			if(method==1)
				{
					h2.insert(Arr[i]->name , Arr[i]->tot_count , 1);
				}
			else
			{
				h2.insert(Arr[i]->name , Arr[i]->tot_count , 2);
			}

		}
	}
	for(int i=0;i<hashsize;i++)
	{
		delete Arr[i];
	}
	delete[] Arr;
	hashsize = hashsize1;
	Arr =  h2.Arr;
}

node** hashtable :: rehash(int method)
{
	int hashsize1 = 2*hashsize;
	hashtable h2(hashsize1);
	for(int i=0;i<hashsize;i++)
	{
		if(Arr[i]->name!="")
		{
			if(method==1)
				{
					h2.insert(Arr[i]->name , Arr[i]->tot_count , 1);
				}
			else
			{
				h2.insert(Arr[i]->name , Arr[i]->tot_count , 2);
			}

		}
	}
	for(int i=0;i<hashsize;i++)
	{
		delete Arr[i];
	}
	delete[] Arr;
	hashsize = hashsize1;
	return h2.Arr;
}

int hashtable :: check_lambda()
{
	float i = (entries*(1.0))/(hashsize*(1.0));
	if(i>0.75) return 0;
	else return 1;
}

int hashtable :: check_lambda1()	
{
	float i = (entries*(1.0))/(hashsize*(1.0));
	if(i>0.75) return 0;
	else return 1;	
}

void hashtable :: insert_collision(string name,int tot_count,int method,int collision_no)  //insert with collision
{
	if(method==1)
	{
		int pos = hash_func2(name,collision_no)%hashsize;
		if(Arr[pos]->name=="")
		{
			Arr[pos]->name = name;
			Arr[pos]->tot_count = tot_count;
			Arr[pos]->d_flag=0;
			entries++;
			//cout<<"inserted"<<endl;
			if(check_lambda()==0)
			{
				Arr = rehash(method);
				//cout<<"re-hash1"<<hashsize<<" "<<entries<<endl;
			}
		}
		else if(Arr[pos]->name==name)
		{
			(Arr[pos]->tot_count)+=tot_count;
			//cout<<"inserted"<<endl;
		}
		else
		{
			collision_no++;
			if(collision_no > hashsize)
			{
				Arr = rehash(method);
				//cout<<"re-hash2 "<<hashsize<<" "<<entries<<endl;
			}
			// pos = hash_func2(name,collision_no)%hashsize;
			// while(Arr[pos]->name!="" || Arr[pos]->name == name)
			// {
			// 	collision_no++;
			// 	if(collision_no > hashsize)
			// 	{
			// 		Arr = rehash(method);
			// 		cout<<"re-hash2 "<<hashsize<<" "<<entries<<endl;
			// 	}
			// 	pos = hash_func2(name,collision_no)%hashsize;
			// }
			// Arr[pos]->name = name;
			// Arr[pos]->tot_count += tot_count;
			// entries++;
			// if(collision_no > hashsize)
			// {
			// 	Arr = rehash(method);
			// 	cout<<"re-hash2 "<<hashsize<<" "<<entries<<endl;
			// }
			insert_collision(name,tot_count,1,collision_no);

		}
	}

	else if(method == 2)
	{
		int pos = hash_func3(name,collision_no)%hashsize;
		if(Arr[pos]->name=="")
		{
			Arr[pos]->name = name;
			Arr[pos]->tot_count = tot_count;
			Arr[pos]->d_flag=0;
			entries++;
			//cout<<"inserted"<<endl;
			if(check_lambda1()==0)
			{
				Arr = rehash(method);
				//cout<<"re-hash1"<<hashsize<<" "<<entries<<endl;
				//cout<<Arr[0]->name<<Arr[1]->name;
			}
		}
		else if(Arr[pos]->name==name)
		{
			(Arr[pos]->tot_count)+=tot_count;
			//cout<<"inserted"<<endl;
		}
		else
		{
			collision_no++;
			if(method == 2 && collision_no > hashsize)
			{
				Arr = rehash(method);
				//cout<<"re-hash2"<<hashsize<<" "<<entries<<endl;
			}
			insert_collision(name,tot_count,method,collision_no);
		}
	}
}

void hashtable :: insert(string name,int tot_count,int method)
{
	int collision_no=0;
	if(method == 1 || method ==2)
	{
		int pos = hash_func1(name)%hashsize;
		if(Arr[pos]->name=="")
		{
			Arr[pos]->name = name;
			Arr[pos]->tot_count = tot_count;
			entries++;
			//cout<<"inserted"<<endl;
			if(method == 1)
			{
				if(check_lambda()==0)
				{
					Arr = rehash(method);
					//cout<<"re-hash2"<<hashsize<<" "<<entries<<endl;
					//cout<<Arr[0]->name<<Arr[1]->name;
				}
			}
			else if(method == 2)
			{
				if(check_lambda1()==0)
				{
					Arr = rehash(method);
					//cout<<"re-hash1"<<hashsize<<" "<<entries<<endl;
					//cout<<Arr[0]->name<<Arr[1]->name;
				}
			}
		}
		else if(Arr[pos]->name==name)
		{
			(Arr[pos]->tot_count)+=tot_count;
			//cout<<"inserted"<<endl;
		}
		else
		{
			collision_no++;
			if(method == 2 && collision_no > hashsize)
			{
				Arr = rehash(method);
			}
			else if(method == 1 && collision_no > hashsize)
			{
				Arr = rehash(method);
				//cout<<"re-hash2"<<hashsize<<" "<<entries<<endl;
			}
			insert_collision(name,tot_count,method,collision_no);
		}	
	}
}

void hashtable :: find(string name,int method)
{
	if(method==1 || method ==2)
	{
		int pos = hash_func1(name)%hashsize;
		int collision_no=0;
		if(Arr[pos]->name==name && Arr[pos]->d_flag==0)
		{
			cout<<name<<" ";
			cout<<Arr[pos]->tot_count<<endl;
			succesful++;
		}
		else if(Arr[pos]->name=="")
		{
			cout<<"not found\n";
		}
		else
		{
			collision_no++;
			unsuccesful++;
			find_collision(name,collision_no,method);
		}
	}
}

void hashtable :: find_collision(string name,int collision_no,int method)
{
	if(method == 1)
	{
		int pos = hash_func2(name,collision_no)%hashsize;
		if(Arr[pos]->name == "" && Arr[pos]->d_flag==0)
		{
			cout<<"not found"<<endl;
		}
		else if(Arr[pos]->name == name)
		{
			cout<<name<<" ";
			cout<<Arr[pos]->tot_count<<endl;
		}
		else
		{
			collision_no++;
			
			find_collision(name,collision_no,method);
		}
	}
	if(method == 2)
	{
		int pos = hash_func3(name,collision_no)%hashsize;
		if(Arr[pos]->name == "" && Arr[pos]->d_flag==0)
		{
			cout<<"not found"<<endl;
		}
		else if(Arr[pos]->name == name)
		{
			cout<<name<<" ";
			cout<<Arr[pos]->tot_count<<endl;
		}
		else
		{
			collision_no++;
			
			find_collision(name,collision_no,method);
		}
	}
}

void hashtable :: delete_collision(string name,int collision_no,int method)
{
	if(method == 1)
	{
		int pos = hash_func2(name,collision_no)%hashsize;
		if(Arr[pos]->name == "" && Arr[pos]->d_flag==0)
		{
			cout<<"not found"<<endl;
		}
		else if(Arr[pos]->name == name)
		{
			Arr[pos]->name="";
			Arr[pos]->d_flag=1;
			Arr[pos]->tot_count = 0;
		}
		else
		{
			collision_no++;
			delete_collision(name,collision_no,method);
		}
	}
	if(method == 2)
	{
		int pos = hash_func3(name,collision_no)%hashsize;
		if(Arr[pos]->name == "" && Arr[pos]->d_flag==0)
		{
			cout<<"not found"<<endl;
		}
		else if(Arr[pos]->name == name)
		{
			Arr[pos]->name="";
			Arr[pos]->d_flag=1;
			Arr[pos]->tot_count = 0;
		}
		else
		{
			collision_no++;
			delete_collision(name,collision_no,method);
		}
	}
}

void hashtable :: delete_(string name,int method)
{
	if(method==1 || method ==2)
	{
		int pos = hash_func1(name)%hashsize;
		int collision_no=0;
		if(Arr[pos]->name==name && Arr[pos]->d_flag==0)
		{
			Arr[pos]->name="";
			Arr[pos]->d_flag=1;
			Arr[pos]->tot_count = 0;
		}
		else if(Arr[pos]->name=="")
		{
			cout<<"not found1\n";
		}
		else
		{
			collision_no++;
			delete_collision(name,collision_no,method);
		}
	}
}

