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
    // mp记录当前栈内每种颜色的数量 cnt记录当前栈内有多少种颜色
    int mp[1000005], cnt = 0;
    memset(mp, 0, sizeof mp);
    for (int i = 0; i < n; ++i) {
        // 把比当前矮的都弹出 保持单调递减
        while (!st.empty() && height[st.top()] <= height[i]) {
            if (--mp[color[st.top()]] == 0) {
                --cnt;
            }
            st.pop();
        }
        st.push(i);
        // 如果当前颜色是新颜色 颜色种类+1
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
    // 神秘小代码 提高cin/cout效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
