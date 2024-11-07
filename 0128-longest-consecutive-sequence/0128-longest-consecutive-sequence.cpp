class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int longest=1;
        int cnt=0;
        int lastsmaller=INT_MIN;
        int n=nums.size();
        if(nums.empty())return 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]-1  ==lastsmaller)
            {
                cnt=cnt+1;
                lastsmaller=nums[i];
            }
            else if(nums[i]!=lastsmaller)
            {
                cnt=1;
                lastsmaller=nums[i];
            }
            longest=max(longest,cnt);
        }
        return longest;
    }
};