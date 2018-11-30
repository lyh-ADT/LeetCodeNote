class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> repeat;
        int max=0,minus=0;
        for(int i=0; i<s.size(); ++i){
            try{
                int t=repeat.at(s[i]);
                while(minus<=t){
                    repeat.erase(s[minus++]);
                }
                i--;
            }
            catch(const std::out_of_range &e){
                repeat[s[i]]=i;
                max=max>i+1-minus?max:i+1-minus;
            }
        }
        return max>s.size()-minus?max:s.size()-minus;
    }
};
