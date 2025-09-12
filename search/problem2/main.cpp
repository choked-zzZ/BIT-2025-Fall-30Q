#include "bits/stdc++.h"
#include <algorithm>
using namespace std;

constexpr static int MX = 100005;
int n, k, arr[MX];
int read() {
    int ret = 0, c;
    for (; !isdigit(c); c = getchar())
        ;
    for (; isdigit(c); c = getchar())
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
    return ret;
}

bool check(int l) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += arr[i] / l;
        if (cnt >= k)
            return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    n = read();
    memset(arr, 0, sizeof arr);
    for (int i = 0; i < n; ++i) {
        arr[i] = read();
    }
    k = read();
    int l = 1, r = *max_element(arr, arr + n);
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;
    return 0;
}
