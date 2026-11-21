class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // int smallest = INT_MIN;
        int n = static_cast<int>(nums.size());
        if(n==0)
        return 0;
        int curr_max=1, maxi=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])
                continue;
            else if(nums[i]==nums[i-1]+1){
                curr_max++;
            }
            else{
                curr_max=1;
            }
            maxi=max(maxi,curr_max);
        }
        return maxi;
    }
};