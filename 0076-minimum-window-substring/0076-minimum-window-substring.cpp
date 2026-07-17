class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        unordered_map<char,int> fq;
        for(int i=0;i<t.size();i++){
            fq[t[i]]++;
        }
        int sz= fq.size();
        int l=0,r=0;
        int cnt=0;
        int len=INT_MAX;
        int s_idx=-1;
        while(r<s.size()){
            if(fq.count(s[r])){
                fq[s[r]]--;
                if(fq[s[r]]==0){
                    cnt++;
                }
            }
            while (cnt == sz) {
                if(r-l+1<len){
                    s_idx=l;
                    len=r-l+1;
                }
                if (fq.count(s[l])) {
                    fq[s[l]]++;
                    if (fq[s[l]] > 0)
                        cnt--;
                }
                l++;
            }
            r++;
        }
        if(s_idx == -1)
            return "";
        return s.substr(s_idx, len);
    }
};