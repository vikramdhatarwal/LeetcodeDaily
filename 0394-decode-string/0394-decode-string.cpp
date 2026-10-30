class Solution {
public:
    string decodeString(string s) {
        vector<pair<string, int>> st;   // each entry: (text before bracket, repeat count)
        string cur = "";
        int num = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            else if (ch == '[') {
                st.push_back({cur, num});
                cur = "";
                num = 0;
            }
            else if (ch == ']') {
                string prev = st.back().first;
                int k = st.back().second;
                st.pop_back();

                string expanded = prev;
                for (int j = 0; j < k; j++) {
                    expanded += cur;
                }
                cur = expanded;
            }
            else {
                cur += ch;
            }
        }
        return cur;
    }
};