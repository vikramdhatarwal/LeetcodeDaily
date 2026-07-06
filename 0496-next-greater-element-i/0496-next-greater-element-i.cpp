class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> mp;
        mp[nums2[nums2.size()-1]]=-1;
        s.push(nums2[nums2.size()-1]);
        for(int i=nums2.size()-2;i>=0;i--){
            if(s.top()>nums2[i]){
                mp[nums2[i]]=s.top();
                
            }
            else{
                while(!s.empty() && s.top()<=nums2[i]){
                    s.pop();
                }
                if(!s.empty()){
                    mp[nums2[i]]=s.top();
                }
                else{
                    mp[nums2[i]]=-1;
                }
            }
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};