#include "bits/stdc++.h"
using namespace std;

int t;

int main(int argc, char *argv[]) {
    cin >> t;
    while (t--) {
        string a, b, c;
        cin >> a >> b;
        int i = a.length() - 1, j = b.length() - 1, carri = 0;
        c.clear();
        while (i >= 0 && j >= 0) {
            int res = (a[i] - '0') + (b[j] - '0') + carri;
            carri = res >> 1;
            c.push_back((res & 1) + '0');
            --i;
            --j;
        }
        while (i >= 0) {
            int res = (a[i] - '0') + carri;
            carri = res >> 1;
            c.push_back((res & 1) + '0');
            --i;
        }
        while (j >= 0) {
            int res = (b[j] - '0') + carri;
            carri = res >> 1;
            c.push_back((res & 1) + '0');
            --j;
        }
        if (carri)
            c.push_back('1');
        int mxlen = c.length() + 2;
        for (int i = 0; i < mxlen - a.length(); ++i)
            cout << " ";
        cout << a << endl;
        cout << "+";
        for (int i = 0; i < mxlen - b.length() - 1; ++i)
            cout << " ";
        cout << b << endl;
        for (int i = 0; i < mxlen; ++i)
            cout << "-";
        cout << endl;
        for (int i = 0; i < mxlen - c.length(); ++i)
            cout << " ";
        for (int i = c.length() - 1; ~i; --i) {
            cout << c[i];
        }
        cout << endl;
    }
    return 0;
}
