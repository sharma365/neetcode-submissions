class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_map <char,int> mpp;
        int l=0,r=0,max_len=0,len=0;
        while(r<s.size()){
            if(mpp.find(s[r]) != mpp.end()){
                if(mpp[s[r]] >= l)
                    l=mpp[s[r]]+1;
            }
            len=r-l+1;
            max_len=max(len, max_len);
            mpp[s[r]]=r;
            r++;

        } 
        return max_len;

        }

};
