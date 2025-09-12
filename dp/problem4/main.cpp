#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MX = 2005;

int n, val[MX];
ll memo[MX][MX];

ll dfs(int i, int j) {
    if (memo[i][j] != -1)
        return memo[i][j];
    if (i > j)
        return 0;
    int age = i + n - j;
    memo[i][j] = max(age * val[i] + dfs(i + 1, j), age * val[j] + dfs(i, j - 1));
    return memo[i][j];
}

void init() {
    memset(val, 0, sizeof val);
    for (int i = 0; i < MX; ++i) {
        for (int j = 0; j < MX; ++j) {
            memo[i][j] = -1;
        }
    }
}

int read() {
    int ret = 0, c;
    for (; !isdigit(c); c = getchar())
        ;
    for (; isdigit(c); c = getchar())
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
    return ret;
}

int main(int argc, char *argv[]) {
    init();
    n = read();
    for (int i = 0; i < n; ++i)
        val[i] = read();
    cout << dfs(0, n - 1) << endl;
    return 0;
}
