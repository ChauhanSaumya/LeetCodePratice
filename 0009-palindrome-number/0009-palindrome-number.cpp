class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;//negative numbers are not allowed
        long rev=0;
        int original=x;
        while(x!=0)
        {
            int lastDigit=x%10;
            rev=(rev*10)+lastDigit;
            x=x/10;
        }
        if(rev > INT_MAX || rev < INT_MIN) return false;
        return rev==original;
    }
};