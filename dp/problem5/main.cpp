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
    for (int i = 0; i < ML; ++i)
        f[i] = -1;
    f[n] = 0;
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        t = read(), w = read();
        for (int i = t; i <= n; ++i) {
            if (f[i] == -1)
                continue;
            f[i - t] = max(f[i - t], f[i] + t * w);
            ans = max(f[i - t], ans);
        }
    }
    cout << ans << endl;
    return 0;
}
