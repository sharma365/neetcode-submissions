class Solution {
public:
    int climbStairs(int n) {
    static unordered_map<int, int> memo;
    
    if(n < 0) return 0;
    if(n == 0 || n == 1) return 1;
    
    if(memo.find(n) != memo.end()) return memo[n];
    
    memo[n] = climbStairs(n-2) + climbStairs(n-1);
    return memo[n];
}
};
