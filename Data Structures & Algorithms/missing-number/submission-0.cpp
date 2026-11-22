class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int misnum=nums.size();
        for(int i=0;i<nums.size();i++)
            misnum^=i^nums[i];
        return misnum;
    }
};
