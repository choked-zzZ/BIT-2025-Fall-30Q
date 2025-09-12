#include <bits/stdc++.h>
using namespace std;

string s;
int mn, mx, num;

int main(int argc, char *argv[]) {
    while (1) {
        mx = 11;
        mn = 0;
        while (1) {
            cin >> num;
            if (num == 0) {
                return 0;
            }
            cin >> s;
            cin >> s;
            if (s == "low") {
                mn = max(mn, num);
            } else if (s == "high") {
                mx = min(mx, num);
            } else {
                if (mn < num && num < mx) {
                    cout << "Tom may be honest" << endl;
                } else {
                    cout << "Tom is dishonest" << endl;
                }
                break;
            }
        }
    }
    return 0;
}
