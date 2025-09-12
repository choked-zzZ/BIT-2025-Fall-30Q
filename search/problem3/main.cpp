#include <bits/stdc++.h>
#include <cstdio>
#include <utility>
using namespace std;
using pii = pair<int, int>;

constexpr static pii DIRS[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
constexpr static int MX = 101;
constexpr static int TIME = 51;

char mp[MX][MX];

bool vis[MX][MX][TIME];

int n, m, k;

inline int p2i(pii p) {
    return p.first * m + p.second;
}

inline pii i2p(int f) {
    return make_pair(f / n, f % n);
}

void init() {
    memset(vis, 0, sizeof vis);
    memset(mp, 0, sizeof mp);
}

inline int read() {
    int ret = 0, c;
    for (; !isdigit(c); c = getchar())
        ;
    for (; isdigit(c); c = getchar())
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
    return ret;
}

void solve() {
    n = read(), m = read(), k = read();
    pii st, en;
    queue<pair<pii, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char tmp = getchar();
            if (tmp == 'S') {
                st = make_pair(i, j);
                vis[i][j][0] = true;
                q.emplace(st, 0);
            } else if (tmp == 'E') {
                en = make_pair(i, j);
            }
            mp[i][j] = tmp;
        }
        getchar();
    }
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        pii xy = p.first;
        int step = p.second;
        if (xy == en) {
            cout << step << endl;
            return;
        }
        ++step;
        for (pii dir : DIRS) {
            auto x = xy.first + dir.first;
            auto y = xy.second + dir.second;
            if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '#' ||
                (mp[x][y] == '*' && (step % k))) {
                continue;
            }
            pii tar = make_pair(x, y);
            if (!vis[tar.first][tar.second][step % k]) {
                vis[tar.first][tar.second][step % k] = true;
                q.emplace(tar, step);
            }
        }
    }
    cout << -1 << endl;
    return;
}

int main(int argc, char *argv[]) {
    int t = read();
    while (t--) {
        init();
        solve();
    }
    return 0;
}
