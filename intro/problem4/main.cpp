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

int n, h, pre, tmp;
unsigned long long ans = 0;

int main(int argc, char *argv[]) {
    n = read(), h = read();
    pre = h;
    for (int i = 0; i < n; ++i) {
        tmp = read();
        if (tmp < pre)
            ans += pre - tmp;
        pre = tmp;
    }
    cout << ans << endl;
    return 0;
}
