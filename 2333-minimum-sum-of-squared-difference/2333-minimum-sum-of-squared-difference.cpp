class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n= nums1.size();
        vector<int> res(n);
        long long sum=0;                        
        for(int i=0;i<n;i++){
            res[i]= abs(nums1[i]-nums2[i]);
            sum+=res[i];
        }
        long long k=(long long)k1+k2;          
        if(sum<=k) return 0;                   
        sort(res.begin(),res.end());

        int i=n-1;
        long long level=res[n-1], r=0;           
        while(i>=0 && k>0){
            while(i>0 && res[i-1]>=level) i--;   
            long long cnt=n-i;
            long long next=(i>0)? res[i-1] : 0;
            long long gap=level-next;
            if(k>=cnt*gap){                    
                k-=cnt*gap;
                level=next;
                if(i==0) break;
            }
            else{                              
                long long q=k/cnt;
                r=k%cnt;                        
                level-=q;
                k=0;
            }
        }

        long long ans=0;
        for(int j=0;j<i;j++) ans+=(long long)res[j]*res[j];   
        long long cnt=n-i;
        ans+=(cnt-r)*level*level + r*(level-1)*(level-1);
        return ans;
    }
};