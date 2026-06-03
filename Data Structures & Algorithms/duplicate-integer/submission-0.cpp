class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for (size_t i = 0; i < nums.size(); ++i) {
            mpp[nums[i]]++;
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            if (mpp[nums[i]] > 1) return true;
        }
        return false;
    }
};