class Solution {
public:
    int climbStairs(int n) {
        static unordered_map<int,int> mpp;
        if(n<0) return 0;
        if(n==0||n==1) return 1;
        
        if(mpp.find(n)!=mpp.end()) return mpp[n];
        mpp[n]= climbStairs(n-2)+climbStairs(n-1);
        return mpp[n];

    }
};
