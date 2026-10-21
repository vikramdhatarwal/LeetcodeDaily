class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(n==0 || n==1 || is_sorted(s.begin(),s.end())) return 0;
        if(n==2 && !is_sorted(s.begin(),s.end())) return -1;
        int min_idx=0;
        int max_idx=0;
        for(int i=1;i<n;i++){
            // use >= to decide max_idx because if max element appears twice and if last occurence is at position n-1 then it is a special case and always return 1
            if(s[i]>=s[max_idx]) max_idx=i;
            if(s[i]<s[min_idx]) min_idx=i;
        }
        if(min_idx==0) return 1;
        if(max_idx==n-1) return 1;
        if(min_idx==n-1 && max_idx==0) return 3;
        return 2;
    }
};