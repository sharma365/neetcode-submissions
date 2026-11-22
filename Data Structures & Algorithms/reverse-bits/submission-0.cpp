class Solution {
public:
    int reverseBits(int n) {
        unsigned int rb=0;
        unsigned int un =static_cast<unsigned int>(n);
        for(int i=0;i<32;i++){
            rb=rb<<1;
            rb=rb|(un&1);
            un=un>>1;
        }
        return rb;
    }
};