class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int xor_all=0;
        for(int i=0;i<nums.size();i++){
            xor_all^=nums[i];
        }
        uint32_t diff=1;
        while((xor_all&diff)==0){
            diff=(diff<<1U);
        }
        int xor1=0,xor2=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i]&diff)==0){
                xor1^=nums[i];
            }
            else{
                xor2^=nums[i];
            }
    }
    return {xor1,xor2};
    }
};