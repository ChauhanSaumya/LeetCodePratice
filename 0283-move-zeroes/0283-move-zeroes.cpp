class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                {
                    j=i;
                    break;
                }
        }
        for(int i=j+1;i<n;i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
        }
     /*   vector<int>temp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
                temp.push_back(nums[i]);
        }
        int sz=temp.size();
        for(int i=0;i<temp.size();i++)
        {
            nums[i]=temp[i];
        }
        for(int i=sz;i<n;i++)
        {
            nums[i]=0;
        }*/
    }
};