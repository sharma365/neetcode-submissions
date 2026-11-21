class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxi=0, pro=0;
        int n=static_cast<int>(nums.size());
        int minprice=nums[0];
        for(int i=0;i<n;i++)
        {
            if(nums[i]<minprice)
                minprice=nums[i];
            pro=nums[i]-minprice;
            maxi=max(maxi,pro);
        }
        return maxi;
    }
};