class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int> pse(n);
        vector<int> nse(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                pse[i]=-1;
            }
            else{
                pse[i]=s.top();
            }
            s.push(i);
        }
        s={};
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                nse[i]=n;
            }
            else{
                nse[i]=s.top();
            }
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int len= nse[i]-pse[i]-1;
            ans=max(ans,heights[i]*len );
        }
        return ans;
    }
};