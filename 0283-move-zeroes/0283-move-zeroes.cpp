class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0; // Initialize j to 0, not -1
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) { // Check for non-zero elements
                swap(nums[j], nums[i]);
                j++; // Increment j only when a non-zero element is found
            }
        }
    }
};