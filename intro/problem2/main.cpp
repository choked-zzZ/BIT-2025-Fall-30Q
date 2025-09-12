#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int res = 0, c;
    for (; !isdigit(c); c = getchar()) {
    }
    for (; isdigit(c); c = getchar())
        res = (res << 3) + (res << 1) + (c ^ 48);
    return res;
}

constexpr int MX = 105;

int lawn[MX][MX], col[MX], row[MX], m, n;

int main(int argc, char *argv[]) {
    n = read(), m = read();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            lawn[i][j] = read();
            row[i] = max(row[i], lawn[i][j]);
            col[j] = max(col[j], lawn[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (lawn[i][j] != min(row[i], col[j])) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
