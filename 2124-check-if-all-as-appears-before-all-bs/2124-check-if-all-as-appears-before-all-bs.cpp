class Solution {
public:
    bool checkString(string s) {
        bool bs=false;
        for(char ch: s){
            if(ch=='a' && bs==true) return false;
            else if(ch=='b') bs=true;
        }
        return true;
    }
};