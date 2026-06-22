class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // storing frequency of each character in text;
        unordered_map<char,int> freq;
        for(char ch: text){
            freq[ch]++;
        }
        int f_size=freq.size();
        int ans=0;
        string word="balloon";
        while(freq.size()==f_size){
            for(int i=0;i<word.size();i++){
                if(freq[word[i]]==0){
                    f_size--;
                    ans--;
                    break;
                }
                freq[word[i]]--;
            }
            ans++;
        }
        return ans;
    }
};