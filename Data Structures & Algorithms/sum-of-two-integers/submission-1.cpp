class Solution {
public:
    int getSum(int a, int b) {
        int sum;
        while(b!=0){
            unsigned int carry = (unsigned)(a & b)<<1;
            a=a^b;
            b=carry;
        }
        return a;
        
    }
};
