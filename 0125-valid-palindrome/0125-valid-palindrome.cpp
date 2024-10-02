class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for (char c : s) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                if (c >= 'A' && c <= 'Z') {
                    temp += c + 32; // Convert to lowercase
                } else {
                    temp += c;
                }
            }
        }
        int left = 0;
        int right = temp.size() - 1;
        while (left < right) {
            if (temp[left] != temp[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};