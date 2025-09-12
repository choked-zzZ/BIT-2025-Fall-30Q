#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = 0;
    cin >> n;
    while (n--) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    int ans = 0;
    while (pq.size() >= 2) {
        int t1 = pq.top();
        pq.pop();
        int t2 = pq.top() + t1;
        pq.pop();
        ans += t2;
        pq.push(t2);
    }
    cout << ans << endl;
    return 0;
}
