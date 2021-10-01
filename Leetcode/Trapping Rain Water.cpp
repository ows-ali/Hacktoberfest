
int trap(vector<int>& height) {
        vector<int>left(height.size()),right(height.size());
        left[0]=height[0];
        right[height.size()-1]=height[height.size()-1];
        for(int i=1;i<height.size();i++)
            left[i]=max(left[i-1],height[i]);
        for(int i=height.size()-2;i>=0;i--)
            right[i]=max(right[i+1],height[i]);
        int ans=0;
        for(int i=1;i<height.size()-1;i++){
            if(height[i]>left[i-1] || height[i]>right[i+1])
                continue;
            ans+=min(left[i-1],right[i+1])-height[i];
            cout<<left[i-1]<<"  "<<right[i+1]<<endl;;
        }
        return ans;
        
    }
    
   
