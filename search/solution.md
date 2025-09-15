# Search for Solution

如果你不知道树或者图 那么你应该不知道深度优先搜索**D**epth **F**irst **S**earch和广度优先搜索**B**readth **F**irst **S**earch是什么

一般来说 图就是**点**和**边**构成的东西 我们日常导航从起点通过若干边到达终点 就是在一个图上行进
现实中大多数路没有正反 可以从一头走到另一头 也可以反过来 这叫无向边 没有方向
游戏里破破烂烂的桥 主角走过去就踏了 不能在回头 这个叫有向边 （这个例子不太好 因为有向边也可以重复走 只需要有一条路可以回到该有向边的起点就可以了）

其实边的定义是高于点的 因为边是两点之间的关系 而若干条边组成了图 所以我们如果想要储存图的话 解决怎么储存边的问题就好了

在题目中 一般把所有点给顶一个编号`1-n`或者是`0-n-1` 那么一个边的构成也就是起点编号加上终点编号 如果是一条无向边a<->b 可以视作a->b和b->a同时存在

```c++
#include <vector>
vector<vector<int>> graph(n);
// 顶点集合 这里一共有n个
1      -> 2, 4  //第一个顶点有两个边 分别指向2和4
2      -> 1, 3
3      -> 1
4      -> 2, 3, 5
5      -> 2

// 添加边
void add_edge(int source, int target) {
  graph[source].push_back(target);
}

// 遍历边
for (int i = 0; i < graph[source].size(); ++i) {
  cout << "Edge " << source << " to" << graph[source][i];
}

// DFS 深度优先 实际应用中不一定是void类型 因为我们可能利用dfs去统计树的大小之类的 会返回int
void dfs(int node) {
  for (auto nxt: graph[node])
  	dfs(nxt, node)
  return ;
}

// BFS 广度优先
void bfs(int start) {
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto nxt: graph[node])
      q.push(nxt);
  }
}
// 实际应用中 我们为了避免重复访问 通常需要标记当前节点是否访问 如果访问过了就不重复进行访问了
```

基本就这俩操作吧 有什么其他的接下来再讲

## T21 成语接龙

一个成语就是一条**第一个字指向最后一个字的边** 这就是本题的含义
成语的尾（边的终点）是下一个成语的头（边的起点）所以我们只需要遍历所有的边 只要能到达结尾的成语的头 我们就可以说出这个成语

需要注意 如果初始和末尾成语相同 只算做说了一个 否则初始末尾分别算一个 直接加上特判就好

## T22 绳子切割

二分查找

很简单 我选择一个1-1000的数 每次我会回答“正确”“大了”“小了” 你只需要花几次就能猜出来？比如我选259
如果你一开始是选500 那么除了你直接猜中之外 你会直接排除一半的数 因为比500大的都是“小了”
每次你都能排除掉一半的数 10次以内你就能猜出来

## 网格图

这种图无需用上述方法存储 数组就是天然的载体 上下左右就是相接 直接贴模版代码

```c++
constexpr static pii DIRS[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; // Four direction
queue<pair<pii, int>> q; // Storing point and steps
pii st, en; // Start point and end point
q.emplace(st, 0); // put the start point in the queue
// the queue store all the point that we need handle, but we take one at a time
vis[st.first][st.second] = true; // we have visited the start point
while (!q.empty()) {
  	// handle a point
    auto p = q.front();
    q.pop();
  	// current (x, y) point, we take one to handle
    pii xy = p.first;
  	// current step
    int step = p.second;
  	// if it is the end point
    if (xy == en) {
        cout << step << endl;
        return 0;
    }
    for (pii dir : DIRS) {
      	// the new point
        int x = xy.first + dir.first, y = xy.second + dir.second;
        if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == 'M'/*if it is obstacle*/) 
            // new point is invalid, skip
          	continue;
      	// valid new point
        pii tar = make_pair(x, y);
        if (!vis[x][y]) {
          	// valid and unvisited new point
            vis[x][y] = true;
          	// push into the queue, waiting for handle
            q.emplace(tar, step + 1);
        }
    }
}

```

下面的题都是上面的模版的变形

## T23 地下城与勇士

**变形：vis数组**

地图很容易用二维数组存储 问题是地图是在变化的 这怎么办呢？

思考一个问题 如果你第`1`秒在`(i,j)`处,和 `k+1`秒在`(i,j)`处有什么区别吗？是没有的
这就好比你读取之前进度的存档 周围的事情一成不变 该来的还是会来
这说明我们可以用取模来储存vis 代码注释会比较详细 请大家移步源代码

相同的取模思维你还可以在DP专题的**T28 一道简单背包题**中看到

## T24 有吃的！

**变形：传送点**

又是网格地图 我们用二维数组存储 馒头是障碍物 那么这个题就很简单了 就是在走迷宫的情况下加入了若干一次性传送点 详情请看代码注释

## T25 进圈

**变形：DIRS数组**

又是网格地图 这个题和前几题唯一的不一样在于 我们一次不止能走一步 还能走`1-k`的任意步数
我们只需要更改DIRS的构成就能很轻松的解决这道题