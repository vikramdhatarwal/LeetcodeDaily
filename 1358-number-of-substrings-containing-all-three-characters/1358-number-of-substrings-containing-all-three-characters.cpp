class Solution {
public:
    int numberOfSubstrings(string s) {
        int last_a=-1;
        int last_b=-1;
        int last_c=-1;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                last_a=i;
            }
            else if(s[i]=='b'){
                last_b=i;
            }
            else{
                last_c=i;
            }
            int mini= min(min(last_a,last_b),last_c);
            if(mini!=-1){
                ans+=mini+1;
            }
        }
        return ans;
    }
};