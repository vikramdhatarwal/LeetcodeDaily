class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0;
        int rsum=0;
        int max_sum=0;
        int n=cardPoints.size();
        int r=n-1;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        max_sum=lsum;
        for(int i=k-1;i>=0;i--){
            rsum+=cardPoints[r];
            lsum-=cardPoints[i];
            max_sum=max(max_sum,rsum+lsum);
            r--;
        }
        return max_sum;
        
        
    }
};