#include <bits/stdc++.h>
#include <cstdio>
#include <utility>
using namespace std;
using pii = pair<int, int>;

// 上下左右四个方向
constexpr static pii DIRS[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// 地图最大尺寸
constexpr static int MX = 101;
// 地图变化最大周期
constexpr static int TIME = 51;

// 地图
char mp[MX][MX];

// 记录是否访问 避免重复访问
bool vis[MX][MX][TIME];

int n, m, k;

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
    // 读入数据 地图尺寸和变化周期
    n = read(), m = read(), k = read();
    // 起点终点
    pii st, en;
    // 队列 存储当前坐标和步数
    queue<pair<pii, int>> q;
    // 处理输入
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
        // 当前坐标和步数
        pii xy = p.first;
        int step = p.second;
        // 到达终点
        if (xy == en) {
            cout << step << endl;
            return;
        }
        // 步数加一
        ++step;
        for (pii dir : DIRS) {
            // 计算下一个坐标
            auto x = xy.first + dir.first;
            auto y = xy.second + dir.second;
            // 越界或者障碍物不能通过 如果不是在k的倍数步就不能通过怪物
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
