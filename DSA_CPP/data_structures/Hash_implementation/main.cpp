#include<iostream>
#include<fstream>
#include "hash.h"
using namespace std;
int main(int argc,char* argv[])
{
    if(argc==3)
    {
        int size = atoi(argv[1]);                    //enter prime size for QP for more effective hashing. 
        string m = argv[2];
        int method;
        if(m == "LP")
        {
            method = 1;
        }
        else if(m == "QP")
        {
            method = 2;
        }
    	ifstream f("dataset_random_10k.txt");		//file name.
        int i;
        int tot_count;
        string n;
        int count = 0;
        hashtable h(100);
        while(f>>i)
        {
        	count++;
            f>>tot_count;
            f>>i;
            f>>i;
            f>>n;
            h.insert(n,tot_count,method);
            //cout<<count<<endl;
        }
        f.close();
        cout<<"enter 2 key to find the key\nenter 3 key frequency to insert the key with frequency\nenter 4 key to delete the key\nenter 5 for load factor\nenter 6 size to rehash to a given size\nenter 7 for succesful and unsuccesful probes and load factor\nenter -1 to exit\n";
        int select;
        cin>>select;
        while(select!=-1)                                       //according to option specified ot does the operations.
        {
            if(select == 2)
            {
                string find_name;
                cin>>find_name;
                h.find(find_name,method);
            }
            
            else if(select == 3)
            {
                string ins_name;
                int tot;

                cin>>ins_name;
                cin>>tot;
                h.insert(ins_name,tot,method);
            }
            else if(select == 4)
            {
                string del_name;
                cin>>del_name;
                h.delete_(del_name,method);
            }
            else if(select == 5)
            {
                h.print_lf();
            }
            else if(select == 6)
            {
                int size;
                cin>>size;
                h.rehash(size,method);
            }
            else if(select == 7)
            {
                h.s_and_u();
            }
            cin>>select;
        }
    }
    
    else
    {
        cout<<"Enter ./nameht [size_of_ht] [probing_method]";
    }
}
