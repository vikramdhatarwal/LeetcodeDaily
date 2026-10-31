class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=1;
        int n= points.size();
        for(int i=0;i<n;i++){
            map<pair<int,int>,int> mp;
            for(int j=i+1;j<n;j++){
                int dx= points[j][0]-points[i][0];
                int dy= points[j][1]-points[i][1];
                if(dx==0){
                    mp[{1,0}]++;
                    ans=max(ans,mp[{1,0}]+1);
                }
                else if(dy==0){
                    mp[{0,1}]++;
                    ans=max(ans,mp[{0,1}]+1);
                }
                else{
                    int g= gcd(dy,dx);
                    dx/=g;
                    dy/=g;
                    if(dx<0){
                        dy=-dy;
                        dx=-dx;
                    }
                    mp[{dy,dx}]++;
                    ans=max(ans,mp[{dy,dx}]+1);
                }
            }
        }
        return ans;
    }
};