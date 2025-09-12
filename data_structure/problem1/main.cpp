#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    int ans = 0;
    int balance = 0;
    while (n--) {
        string tmp;
        cin >> tmp;
        stack<char> st;
        for (char chr : tmp) {
            if (chr == ')') {
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(chr);
            } else
                st.push(chr);
        }
        if (!st.empty()) {
            char top = st.top();
            int len = top == '(' ? st.size() : -st.size();
            bool f = true;
            while (!st.empty()) {
                if (st.top() != top) {
                    f = false;
                    break;
                }
                st.pop();
            }
            if (!f)
                continue;
            auto it = mp.find(-len);
            if (it != mp.end()) {
                if (--(it->second) == 0)
                    mp.erase(it);
                ++ans;
            } else
                ++mp[len];
        } else
            ++balance;
    }
    cout << ans + (balance >> 1) << endl;
    return 0;
}
