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

// 能不能切出 k 段长度为 l 的绳子
bool check(int l) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        // 这里是整除
        cnt += arr[i] / l;
        if (cnt >= k)
            // 能切出 k 段
            return true;
    }
    // 到最后也没切出 k 段
    return false;
}

int main(int argc, char *argv[]) {
    n = read();
    memset(arr, 0, sizeof arr);
    for (int i = 0; i < n; ++i) {
        arr[i] = read();
    }
    k = read();
    // 二分答案 下届是1 上届是绳子最长的长度
    int l = 1, r = *max_element(arr, arr + n);
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            // 能切出 k 段，尝试更长
            l = mid + 1;
        } else {
            // 不能切出 k 段，尝试更短
            r = mid - 1;
        }
    }
    // r 是最后一个能切出的长度 直接输出 这里是可以输出0的 可以想想为什么
    cout << r << endl;
    return 0;
}
