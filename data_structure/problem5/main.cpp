#include <bits/stdc++.h>
using namespace std;

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
        for (int i = 0; i < n; ++i) {
            if (!st.empty() && height[i] == st.top())
                st.pop();
            else {
                if (!st.empty() && st.top() < height[i])
                    break;
                else
                    st.push(height[i]);
            }
        }
        if (!st.size() || st.size() == 1 && st.top() == height[mx_idx])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
