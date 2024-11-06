#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();

        // Step 1: Find the largest index `ind` such that nums[ind] < nums[ind + 1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i; // Store the index, not the value
                break;
            }
        }

        // If no such index exists, the array is in descending order
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return nums;
        }

        // Step 2: Find the largest index `j` greater than `ind` such that nums[ind] < nums[j]
        for (int j = n - 1; j > ind; j--) {
            if (nums[j] > nums[ind]) {
                swap(nums[ind], nums[j]); // Swap the values at indices `ind` and `j`
                break;
            }
        }

        // Step 3: Reverse the sequence from `ind + 1` to the end of the array
        reverse(nums.begin() + ind + 1, nums.end());

        return nums;
    }
};