#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    deque<string> dq;
    while (n--) {
        string op;
        cin >> op;
        if (op == "Arrive") {
            string name;
            cin >> name;
            dq.push_back(name);
        } else if (op == "Leave") {
            if (!dq.empty())
                dq.pop_front();
        } else if (op == "QueueHead") {
            if (dq.empty()) {
                cout << "Empty queue" << endl;
            } else {
                cout << dq.front() << endl;
            }
        } else if (op == "QueueTail") {
            if (dq.empty()) {
                cout << "Empty queue" << endl;
            } else {
                cout << dq.back() << endl;
            }
        }
    }
    return 0;
}
