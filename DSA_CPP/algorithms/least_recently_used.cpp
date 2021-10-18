#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int cache_size;
list<int> cache;
unordered_map<int, list<int>::iterator> element_address;


void lru(int element)
{
	// element not found
	if(find(cache.begin(),cache.end(),element) == cache.end())
	{
		if(cache.size() == cache_size)
		{
			int lru_element = cache.back();
			cache.pop_back();
			element_address.erase(lru_element);
		}
	}

	// element found
	else
		cache.erase(element_address[element]);

	cache.push_front(element);
	element_address[element] = cache.begin();

}

void view_cache()
{
	for(auto& it:cache)
		cout<<it<<endl;
}

int main()
{
	
	cout<<"Enter cache size (no of frames):\n";
	cin>>cache_size;

	lru(1);
	lru(2);
	lru(3);
	lru(1);
	lru(4);
	lru(5);
	view_cache();

	return 0;
}