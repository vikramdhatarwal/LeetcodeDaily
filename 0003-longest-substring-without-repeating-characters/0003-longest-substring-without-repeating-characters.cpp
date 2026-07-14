class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        unordered_set<char> st;
        int l=0, r=0;
        while(r<s.size()){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                r++;
            }
            else{
                ans=max(ans,r-l);
                while(s[l]!=s[r]){
                    st.erase(s[l]);
                    l++;
                }
                st.erase(s[l]);
                l++;
            }
        }
        ans=max(ans,r-l);
        return ans;
        
    }
};