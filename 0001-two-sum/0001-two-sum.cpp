class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        vector<int> originalNums = nums;
        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                for (int i = 0; i < n; i++) {
                    if (originalNums[i] == nums[left]) {
                        ans.push_back(i);
                        break;
                    }
                }
                for (int i = 0; i < n; i++) {
                    if (originalNums[i] == nums[right] && i != ans[0]) {
                        ans.push_back(i);
                        return ans;
                    }
                }
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};
    }
};