#include "bits/stdc++.h"
#include <algorithm>
#include <cstdio>
using namespace std;

constexpr int MX = 17;
const int dx[] = {0, -1, 1, 0, 0};
const int dy[] = {0, 0, 0, -1, 1};
int assist[MX][MX], light[MX][MX], m, n;

void press(int i, int j) {
    for (int idx = 0; idx < 5; ++idx) {
        int x = i + dx[idx];
        int y = j + dy[idx];
        if (0 <= x && x < m && 0 <= y && y < n) {
            light[x][y] ^= 1;
        }
    }
}

int read() {
    int res = 0, c;
    for (; !isdigit(c); c = getchar())
        ;
    for (; isdigit(c); c = getchar())
        res = (res << 3) + (res << 1) + (c ^ 48);
    return res;
}

int main(int argc, char *argv[]) {
    cin >> m >> n;
    int minpress = 256;
    string row;
    for (int i = 0; i < m; ++i) {
        cin >> row;
        for (int j = 0; j < n; ++j) {
            assist[i][j] = row[j] - '0';
        }
    }
    for (int idx = 0; idx < (1 << n); ++idx) {
        int press_cnt = 0;
        memcpy(light, assist, sizeof(assist));

        for (int j = 0; j < n; ++j) {
            if ((idx >> j) & 1) {
                press(0, j);
                press_cnt += 1;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (light[i - 1][j]) {
                    press(i, j);
                    press_cnt += 1;
                }
            }
        }

        bool all_zero = true;

        for (int j = 0; j < n; ++j) {
            if (light[m - 1][j]) {
                all_zero = false;
                break;
            }
        }

        if (all_zero) {
            minpress = min(minpress, press_cnt);
        }
    }
    cout << minpress << endl;

    return 0;
}
