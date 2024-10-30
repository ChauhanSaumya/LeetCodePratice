class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector <int> arr(n,0);
        int posindex=0;
        int negindex=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                arr[negindex]=nums[i];
                negindex+=2;
            }
            else{
              arr[posindex]=nums[i];
                posindex+=2;
            }
        }
        return arr;
         }
};