class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<pair<int, int>> pairs;
        for(auto it:mpp){
            pairs.push_back({it.first, it.second});
        }
        sort(pairs.begin(), pairs.end(), [](pair<int, int>&a, pair<int, int> &b){
            return a.second>b.second;
        });
        for(int i=0;i<k;i++){
            result.push_back(pairs[i].first);
            }
        return result;
    }
};
