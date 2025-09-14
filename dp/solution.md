# Dynamic Programming Solution

## 写在所有题前面

动态规划，也就是DP是一种非常特殊的题，他的难点在于思考，重点在于优化。而这种题的训练靠这五道题是远远不够的，之前借着灵茶山艾府的题单训练DP时看到他说的话：DP至少要写100道题才算入门

做动态规划的核心是什么？那就是状态的定义和状态的转移了，对于非算法竞赛的DP题，一般来说是不会在状态定义上有所考查的，但是仍然需要注意DP的状态定义需要满足无后效性，也就是之后的状态是不会对之前的状态产生影响的，就像Fibonacci数列的每一个数只由**前**两个数决定，而不是后面的数。

状态的转移 对于初学者来说并不是靠想的 你需要拿出纸笔来算 自己画出来各种情况才可以。另外一种比较好同时确定状态定义和转移的方法是**确定子问题** 比如要求Fibonacci数列的第五个数 那么就需要知道第四个数和第三个数 要知道第四个数那么就需要知道第三个数和第二个数…… 以此逐渐类推 达到我们人为给定的**初始条件** 也就是第一个数是1 第二个数也是1 写出来也就是这个样子的
$f(i)=\left\{\begin{matrix}f(i-1)+f(i-2)&\text{if }i>3\\1&\text{otherwise}\end{matrix}\right. $

他能够很好的翻译成递归，代码如下
```C++
// Recursive Function without memo
int fib(int i) {
  if (i > 3)
    return fib(i-1) + fib(i-2);
 	else
    return 1;
}
```

但是很遗憾这个代码是十分低效的 ![Will Rosenbaum | How Slow is Recursive Fibonacci?](https://willrosenbaum.com/assets/img/recursive-fibonacci/tree.png)
从图中可以看出来 计算`fib(6)`的时候 我们计算了`fib(3)`3次 而实际上我们只需要算一次就知道`fib(3)`是多少了所以我们需要储存起来 让函数知道 我们算过了！别再去算了！

```c++
// Recursive Functionn with memo
// MX is the maximum number we want to solve
constexpr int MX = 20;
int memo[MX];

// initialize every value to -1, representing we don't know the exact value
// why we choose -1? because never will -1 appear in the fibonacci number.
// you can choose 0 either, but sometime people define the first number to be 0.
void init() {
  for (int i = 0; i < MX; ++i)
    memo[i] = -1;
}

int fib(int i) {
  if (memo[i] != -1) 
    // meaning fib(i) has been calculated before, return it without computing again.
    return memo[i];
  // if we go here, it means we don't know how much fib(i) is, then calculate.
  // and we should store the value in the memo
  if (i > 3)
  	memo[i] = fib(i - 1) + fib(i - 2);
  else
    memo[i] = 1;
  return memo[i];
}
```

进一步的 我们可以用循环来代替函数递归
```c++
constexpr int MX = 21;
int dp[MX];
//dp[i] is the i-th Fibonacci number.

int main() {
  dp[1] = 1;
  dp[2] = 1;
  for (int i = 3; i < MX; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
}
```

注意到计算`fib(n)`只需要`fib(n-1)`和`fib(n-2)`就可以了 所以我们可以这样改
```c++
int fib(n) {
  if (i <= 2)
    return 1;
  // a, b and c represent the continuous three number.
  int a = 1, b = 1, c;
  for (int i = 0; i < n - 2; ++i) {
    // calculate the third.
    c = a + b;
    // doing replace to be ready to caculate next.
 		a = b;
    b = c;
  }
  return c;
}
```

这就是一般的动态规划过程了 从确定子问题 到确定状态 再到确定状态转移 最后才是逐步的优化

## T26 篮球练习

在没有障碍的情况下 到达***与出发点在同一列同一行的点***只有唯一*1*种方法 也就是直线前进 而其他点可以由他们的上方和左方到达 根据加法原理 到达这一点的方法是左和上两个方法总数只和
由于只能向右和向下走 我们无法经过同一格 那么这个状态就是没有后效性的

在有障碍的情况下 人为定义到达那一个点的方法数为0 这个定义很明显是符合题目的

实际编写代码可以把所有的点初始为-1 把第0行和列设为1 把障碍设置为0 遇到0就跳过 然后一次便利得出答案

## T27 双塔问题

这类问题叫**LCS**(Longest Common Subsequent)最长公共子序列 没有做过的人很难想状态定义 不过转化为子问题还是比较容易的 **如果没有思路可以直接看题解学习状态定义**

**提示**：观看以下内容，需要自备一个简短例子 同时画图自己理解 比如 `[1,3,4,2,4,2]`与`[4,2,3,1,4]`

设我们要求a和b的LCS，设m和n为a和b的长度
定义`f(i,j)`表示`a[0..i]`与`b[0..j]`能形成的LCS 这里的`a[0..i]`表示数组a中下标为$[0,i)$的内容
那么我们需要求的就是`f(m,n)`
状态转移方程就是$f(i,j)=\left\{\begin{matrix}\max(f(i-1,j),f(i,j-1))&\text{if }a[i]!=b[j]\\1+f(i-1,j-1)&\text{otherwise}\end{matrix}\right. $

- 如果`a[i] != b[j]`说明不能增长最长子序列 那么所形成的LCS应该由`f(i-1,j)`与`f(i,j-1)`中的较大者提供
- 反之 `f(i,j)`则在`a[0..i-1]`与`b[0..j-1]`的最长公共子序列`f(i-1,j-1)`上增加1

这就是完整的状态转移了

## T28 一道简单背包题

是简单背包 但不是最简单的背包 **如果没有了解掌握下文*“介绍一下背包问题”和T30*的同学 不是特别推荐直接观看这个题解** 

~~**你已经被警告过了**~~

介绍一下背包问题：有一个容积为$v$的背包，同时有$n$个物品，每个物品的体积为$v_i$，价值为$w_i$，在不超过背包容量的前提下，选择若干个物品，使得这些物品的价值和最大。

状态定义：定义`f(i,j)`代表 还剩下`j`的容积时 从前`i`个物品中选出的最大价值总和
下一个子问题：分类讨论 

- 选第`i`个 那么还剩下`j-w[i]`的容积，从`i-1`个物品中选择
- 不选第`i`个 那么剩下`j`的容积，从`i-1`个物品中选择

`dfs(i, j) = max(  dfs(i - 1, j),  w[i] + dfs(i - 1, j - w[i])  )`
当`j`小于0是不合法的情况 返回0（最小价值）即可 最终的答案就是`dfs(n-1, v)`

这里的函数有两个参数，难道我们数组也要开两个维度吗？
注意到`dfs(i, j)`的结果只和`dfs(i - 1, ..?)`有关, `i -2`以及更少的维度都用不到 所以我们只需要两个数组，一个记录已经求得的`i - 1`一个用来储存`i`的计算 之后再调换就可以了 这被称作**滚动数组**

这就是背包的经典定义 接下来你可以去完成T30了



对于本题 由于背包可以被视作无限大 怎么装都装不满 我们没办法开一个无限长的维度记录容量 但是其实我们最后只需要求得一个容量的整数倍就可以了 所以我们需要考虑取模 请看以下例子

如果背包容量要求是5的整数倍 当前物品的大小为2 那么我们之前的背包不管是3,8,13,18... 只要加上这个2 都会变成5的整数倍 而这些状态的特点是当前装下的物品大小除以5余3，所以我们会发现 所有余数相同的状态是可以一起考虑的

看到这里如果明白的话可以去看代码了 代码中采用了滚动数组优化 会附上注释解释。

## T29 Treats for the Cows

怎么还有英文题面，，

意思就是有一排零食 FJ每天可以从一排的最左端和最右端取出一个零食售卖 赚得的钱是零食本身的价格`v[i]`与今天的天数`t`的乘积 那么给定若干零食和价格 求最多能够卖出去多少钱

这道题我自己感觉用递归反倒能够很轻松的理解

状态定义：定义`f(i, j)`为从左边拿到第`i`个，从右边拿到第`j`个的情况下 能够卖出去的最多的钱
这种情况下应该是第`t = i + n - j`天 
`dfs(i, j) = max(t * v[i] + dfs(i + 1, j), t * v[j] + dfs(i, j - 1))`这两种情况
答案和初始情况就是`dfs(0, n-1)`

使用记忆化搜索的方式编写

## T30 考试

这才是真正的背包题 总时间就是背包容量 每道题所需时间就是物品的大小 在此之上乘以性价比就是物品价值这个背包比T28简单多了 建议先做这道题再看T28