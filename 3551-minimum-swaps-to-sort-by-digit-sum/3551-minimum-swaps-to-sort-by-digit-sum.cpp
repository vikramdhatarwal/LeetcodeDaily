class Solution {
public:
    int sum_of_dig(int x){
        int sum=0;
        while(x>0){
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        map<int,vector<int>> mp;
        for(int el:nums){
            mp[sum_of_dig(el)].push_back(el);
        }
        vector<int> ans;
        for(auto& [key,val]:mp){
            sort(val.begin(),val.end());
            ans.insert(ans.end(), val.begin(),val.end());
        }
        unordered_map<int, int> target_idx;
        for (int i = 0; i < ans.size(); i++) {
            target_idx[ans[i]] = i;
        }
        int sw = 0;
        vector<bool> visited(nums.size(), false);

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || target_idx[nums[i]] == i) {
                continue;
            }
            int cycle_size = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = target_idx[nums[curr]];
                cycle_size++;
            }
            if (cycle_size > 1) {
                sw += (cycle_size - 1);
            }
        }

        return sw;
    }
};