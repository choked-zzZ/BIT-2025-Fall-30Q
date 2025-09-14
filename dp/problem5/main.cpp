#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ull = unsigned long long;
using ll = long long;

constexpr int ML = 30005;

int n, m, t, w;
ll f[ML];

int read() {
    int ret = 0, c;
    for (; !isdigit(c); c = getchar())
        ;
    for (; isdigit(c); c = getchar())
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
    return ret;
}

int main(int argc, char *argv[]) {
    n = read(), m = read();
    // 初始化为-1 表示不可达
    for (int i = 0; i < ML; ++i)
        f[i] = -1;
    // 花费为0时收益为0
    f[n] = 0;
    ll ans = 0;

    // 背包问题
    for (int i = 0; i < m; ++i) {
        t = read(), w = read();
        for (int i = t; i <= n; ++i) {
            // 当前位置不可达
            if (f[i] == -1)
                continue;
            // 状态转移
            f[i - t] = max(f[i - t], f[i] + t * w);
            // 维护最大值
            ans = max(f[i - t], ans);
        }
    }
    cout << ans << endl;
    return 0;
}
