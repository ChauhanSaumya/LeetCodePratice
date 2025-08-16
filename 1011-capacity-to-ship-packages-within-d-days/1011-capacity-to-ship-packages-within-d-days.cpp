class Solution {
public:
    int req_day(vector<int>& w, int m)
    {   int total=0;
        int day=1;
        for(int i=0;i<w.size();i++)
        {
            if((total+w[i])>m)
            {
                day++;
                total=w[i];
            }
            else
            {
                total+=w[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high)
        {
            int mid=(low+high)/2;
            int rd=req_day(weights,mid);
            if(rd>days)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
};