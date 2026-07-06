class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        vector<int> ple(n);
        vector<int> nle(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i] ){
                s.pop();
            }
            if(s.empty()){
                ple[i]=-1;
            }
            else{
                ple[i]=s.top();
            }
            s.push(i);
        }
        s= stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i] ){
                s.pop();
            }
            if(s.empty()){
                nle[i]=n;
            }
            else{
                nle[i]=s.top();
            }
            s.push(i);
        }
        int mod= 1e9+7;
        int sum=0;
        for(int i=0;i<n;i++){
            int left= i-ple[i];
            int right= nle[i]-i;
            long long freq = left*right*1LL;
            int val = (freq*arr[i]*1LL) % mod;
            sum = (sum + val) % mod;

        }
        return sum;
    }
};