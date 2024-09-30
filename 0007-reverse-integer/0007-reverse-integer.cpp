class Solution {
public:
    int reverse(int x) {
    long revN=0;//using long to avoid overflow
     while(x!=0)
     {
        int lastDigit=x%10;
        revN=(revN*10)+lastDigit;
        x=x/10;
     }
     if(revN > INT_MAX || revN < INT_MIN )
     {
       return 0; // overflow,return 0;
     }
     return revN;
        
    }
};