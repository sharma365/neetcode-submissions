class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(string &s:strs){
            encoded+=to_string(s.size())+"#"+s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        for(int i=0;i<static_cast<int>(s.size());){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));
            decoded.push_back(s.substr(j+1,len));
            i=j+len+1;
        }
        return decoded;
        
    }
};
