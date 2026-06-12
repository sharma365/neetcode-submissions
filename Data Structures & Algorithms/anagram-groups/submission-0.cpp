class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map <string, vector<string>> group;
        for(string key : strs){
            string k=key;
            sort(key.begin(),key.end());
            group[key].push_back(k);
        } 
        for(auto s:group){
            ans.push_back(s.second);
        }
        return ans;
    }
};
