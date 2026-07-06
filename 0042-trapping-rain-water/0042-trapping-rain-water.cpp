class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int lmax=0;
        int rmax=0;
        int ans=0;
        while(l<r){
            if(height[l]>height[r]){
                if(rmax>height[r]){
                    ans+=rmax-height[r];
                    
                }
                else{
                    rmax=height[r];

                }
                r--;
            }
            else{
                if(lmax>height[l]){
                    ans+=lmax-height[l];
                }
                else{
                    lmax=height[l];
                }
                l++;
            }
        }
        return ans;
    }
};