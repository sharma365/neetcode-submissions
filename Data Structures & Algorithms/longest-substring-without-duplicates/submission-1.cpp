class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")
        return 0;
        int maxlen=0;
        int n=static_cast<int>(s.size());
        int freq[256]={0};
        int l=0;
        for(int r=0;r<n;r++){
            freq[s[r]]++;
            while(freq[s[r]]>1){
                freq[s[l]]--;
                l++;
            }
            maxlen=max(maxlen, r-l+1);
        }
        return maxlen;
    }
};