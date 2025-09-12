#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MX = 200005;
int n, height[MX];

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while (cin >> n) {
        stack<int> st;
        memset(height, 0, sizeof height);
        int mx_idx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> height[i];
            if (height[mx_idx] < height[i])
                mx_idx = i;
        }
        int bit;
        for (int i = 0; i < n; ++i) {
            bit = (height[mx_idx] - height[i]) & 1 ? 0 : 1;
            if (!st.empty() && bit == st.top())
                st.pop();
            else
                st.push(bit);
        }

        cout << (st.size() > 1 ? "NO" : "YES") << endl;
    }
    return 0;
}
