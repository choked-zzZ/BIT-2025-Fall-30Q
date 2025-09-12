#include <bits/stdc++.h>
#include <cstring>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> color(n);
    vector<int> height(n);
    for (int i = 0; i < n; ++i)
        cin >> color[i];
    for (int i = 0; i < n; ++i)
        cin >> height[i];
    stack<int> st;
    int mp[1000005], cnt = 0;
    memset(mp, 0, sizeof mp);
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && height[st.top()] <= height[i]) {
            if (--mp[color[st.top()]] == 0) {
                --cnt;
            }
            st.pop();
        }
        st.push(i);
        if (mp[color[i]]++ == 0) {
            ++cnt;
        }
        cout << cnt;
        if (i != n - 1)
            cout << " ";
        else
            cout << endl;
    }
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
