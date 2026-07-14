class Solution {
public:
    int maxFrequency(vector<int> &fq){
        int ans=0;
        for(int i=0;i<26;i++){
            ans=max(ans,fq[i]);
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int ans=0;
        int mx_fq=0;
        vector<int> fq(26,0);
        while(r<s.size()){
            fq[s[r]-'A']++;
            mx_fq=max(mx_fq,fq[s[r]-'A']);
            if(r-l+1-mx_fq<=k){
                r++;
            }
            else{
                ans=max(ans,r-l);
                while(r-l+1-mx_fq>k){
                    fq[s[l]-'A']--;
                    mx_fq=maxFrequency(fq);
                    l++;
                }
                r++;
            }
        }
        ans=max(ans,r-l);
        return ans;
    }
};