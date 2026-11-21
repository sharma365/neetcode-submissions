class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        int left=0, right=n-1;
        while(left<right){
            if(nums[left]+nums[right]<target){
                left++;
            }
            else if(nums[left]+nums[right]>target){
                right--;
            }
            else return{left+1,right+1};
        }
        return {};
    }
};