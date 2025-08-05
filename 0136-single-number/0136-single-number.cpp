class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]+=1;
        }
        for(auto it:mpp)
        {
            if(it.second==1)
            return it.first;
        }
        return -1;
    }
};