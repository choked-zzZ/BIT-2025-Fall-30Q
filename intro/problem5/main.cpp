#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

inline int read() {
    int res = 0, c;
    for (; !isdigit(c); c = getchar()) {
    }
    for (; isdigit(c); c = getchar())
        res = (res << 3) + (res << 1) + (c ^ 48);
    return res;
}

constexpr int MX = 100005;
int lake[MX], t, n;
ull ans;

int main(int argc, char *argv[]) {
    t = read();
    while (t--) {
        stack<int> st;
        ans = 0;
        n = read();
        for (int i = 0; i < n; ++i) {
            lake[i] = read();
            while (!st.empty() && lake[i] > lake[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int mx = min(lake[i], lake[st.top()]);
                ans += (ull)(mx - lake[top]) * (i - st.top() - 1);
            }
            st.push(i);
        }
        cout << ans << endl;
    }
    return 0;
}
