class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> D; //declaring a deque of pairs for storing max elements and their indices
        vector<int> ret; // declaring a vector to store the max elements and return them in the end 
        for(int i=0; i<nums.size(); i++) //stating the loop for all elements
        {
            if(!D.empty() && D.front().second<=(i-k)) //removing the elements outside the sliding window by checking indices
                D.pop_front();
            while(!D.empty() && D.back().first<nums[i]) //removing the elements not useful by comparing elements
                D.pop_back();
            D.push_back(make_pair(nums[i], i)); //finally pushing the element in tbe end 
            if(i>=k-1) //checking have we clear the first k elements 
            ret.push_back(D.front().first);        
        }
        return ret;
    }
};
