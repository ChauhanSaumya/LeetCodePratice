class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //using kadanes algorithm
        int n=nums.size();
        int sum=0;
        long long maxi=LONG_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum>maxi)
            {
                maxi=sum;
            }
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxi;
    }
};