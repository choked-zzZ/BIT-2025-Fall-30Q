// 首先你得知道怎么用栈来做括号匹配
//
// 任何一个左括号都会等待一个右括号的匹配 任意一个右括号匹配一个最近的未匹配的左括号
// 那么就可以用栈来解决
//
// 那么对于任意一串括号序列 最后会是什么结果呢
//
// 1. 栈内空空 说明这是一个合法的括号序列
// 2. 栈内有若干左括号 说明缺少右括号
// 3. 栈内有若干有括号 说明缺少左括号
// 4. 栈内有若干右括号+若干左括号 说明这个序列前面部分缺左括号 后面部分缺右括号
// 5. ~~不会有若干左括号+若干右括号 这样子能够直接相消~~
//
// 所以一共有四种情况 任意两个第一种情况可以相互组成 一个合法的括号序列
// 第四种情况和任何序列都无法组成合法的序列 对于第二三种情况 如果左括号剩k个 右括号也剩k个
// 那么可以配对
//
// 具体的配对方式见代码

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    int ans = 0;
    // 本意是统计情况1的个数 但是其实放在hashmap里也一样
    int balance = 0;
    while (n--) {
        string tmp;
        cin >> tmp;
        // 先对这个序列进行化简
        stack<char> st;
        for (char chr : tmp) {
            // 右括号的话 需要寻找最近的左括号进行匹配
            // 如果匹配成功就消除
            // 如果匹配不成功直接入栈就好 这个右括号不会再被消除
            if (chr == ')') {
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(chr);
            } else
                // 并非右括号 直接入栈
                st.push(chr);
        }
        if (!st.empty()) {
            char top = st.top();
            // 人为规定左括号为正 右括号为负
            int len = top == '(' ? st.size() : -st.size();
            bool f = true;
            // 检查一下栈内的元素是否全部相同 如果不同就是第四种情况
            // 直接跳过就可以了
            while (!st.empty()) {
                if (st.top() != top) {
                    f = false;
                    break;
                }
                st.pop();
            }
            if (!f)
                continue;
            // 查找相反数配对
            auto it = mp.find(-len);
            if (it != mp.end()) {
                if (--(it->second) == 0)
                    mp.erase(it);
                ++ans;
            } else
                ++mp[len];
        } else
            ++balance;
    }
    cout << ans + (balance >> 1) << endl;
    return 0;
}
