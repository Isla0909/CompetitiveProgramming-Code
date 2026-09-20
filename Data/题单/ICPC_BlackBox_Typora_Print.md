# ICPC 赛场黑盒算法手册

> **定位：** 区域赛最后 30～60 分钟的“算法保险箱”。先用速查表识别题型，再看详细说明完成建模和调用。
>
> **使用环境：** Typora。本文只使用 Typora 可直接渲染的 Markdown、表格、代码块与 LaTeX 数学公式。

[TOC]

---

## 使用顺序

1. **先看第一部分「2 分钟速查」**：根据题目特征快速排查是否命中陌生经典算法。
2. **命中后看第二部分「详细手册」**：只补“识别 → 建模 → 调用 → 坑点”，不临场钻证明。
3. **最后到第三部分复制板子**：结合样例与自己构造的极小数据检查边界。

> 默认约定：模板按原资料保留；下标规则和接口以对应章节说明为准。

---

# 第一部分：赛场 2 分钟速查

先按“看到”定位；只有高度吻合时，再跳到第二部分对应算法的详细章节。

## SG

看到：两人轮流、规则相同、一定结束、不能动者输；多个互不影响的子游戏，每次只动一个。

想到：单状态 `sg[x]=mex(sg[next])`；多个独立游戏 `ans ^= sg[state]`，`ans==0` 先手输。

调用：`calc_sg(next)` / `subtraction_sg(N,moves)`。

复杂度：约为状态数 + 转移数；减法游戏 $O(N|moves|)$。

最大坑：一个状态内部用 mex，多个独立游戏之间才 xor；misère、异规则、有环不能机械套。

## NTT 卷积

看到：`ans[k]=Σa[i]b[k-i]`；两边各选一个且贡献只看 `i+j`；频次数组统计和值；差值问题可反转一边。

想到：卷积。

调用：`auto c=convolution(a,b);`，结果模 `998244353`，`c[k]=Σ_{i+j=k}a[i]b[j]`。

复杂度：$O(L\log L)$，本模板 $L\le2^{23}$。

最大坑：下标偏移、差值忘记反转、目标模数不是 `998244353`。

## 最大流 / Dinic

看到：最多安排/匹配/通过多少；每个人、任务、边或点有次数上限；没有费用。

想到：画成 `S -> 中间层 -> T`，容量就是“最多允许发生多少次”。

调用：`mf.addEdge(u,v,cap); mf.flow(S,T);`

常见建图：`S->人(cap=上限)`，`人->任务(cap=1/INF)`，`任务->T(cap=上限)`。

最大坑：点容量要拆成 `u_in->u_out`；`addEdge` 是有向边；反向边模板自动加。

## 最小费用最大流

看到：容量限制 + 每种选择有 cost/value；最大流量下费用最小，或必须流恰好 $k$ 单位。

想到：MCMF。

调用：`auto [flow,cost]=mf.flow(S,T,need);`

复杂度：初始一次 SPFA，之后每次增广约 $O(E\log V)$。

最大坑：恰好 `need` 要检查 `flow==need`；最大收益令 `cost=-value`，答案取 `-cost`。

## 任意模数卷积

看到：已经确定是卷积，但答案模 `1e9+7` 等非 NTT 友好模数。

想到：三模 NTT + CRT。

调用：`convolution_mod(a,b,mod)`。

复杂度：$O(L\log L)$，约三倍普通 NTT；$L\le2^{21}$。

最大坑：断言检查长度和 CRT 恢复范围，不能删掉硬跑。

## Miller-Rabin

看到：$n\le10^{18}$ / u64，只问是不是质数，$\sqrt n$ 过不了。

想到：确定性 Miller-Rabin。

调用：`isPrime(n)`。

复杂度：常数个 $O(\log n)$ 模幂。

最大坑：0、1 非质数；乘法必须用 `__uint128_t`。

## Pollard Rho

看到：$n\le10^{18}$，要求完整质因数分解，试除过不了。

想到：Pollard Rho + Miller-Rabin。

调用：`auto fac=factor(n);`，包含重复质因子且已排序。

复杂度：随机化，64 位实际通常很快。

最大坑：`factor(1)` 为空；需要不同质因子时再 `unique`。

## Blossom

看到：一般无向图、可能有奇环、每点最多匹配一次、求最大匹配边数。

想到：Blossom。

调用：`Blossom bm(n); bm.addEdge(u,v); int ans=bm.solve();`

复杂度：$O(n^3)$。

最大坑：二分图优先简单匹配；本模板不支持最大权匹配。

## floor_sum

看到：`Σ floor((a*i+b)/m)`；直线下格点；固定 $i$ 时合法 $j$ 数是线性 floor，且 $n$ 很大。

想到：floor_sum，下标固定为 `i=0..n-1`。

调用：`i128 ans=floor_sum(n,m,a,b);`

复杂度：对数级。

最大坑：参数顺序、`1..n` 偏移、合法数量的 `+1`、负区间、答案溢出。

## Hungarian

看到：左右两部分、完整权值矩阵、每个左点必须选择不同右点、总费用最小/价值最大。

想到：Assignment / Hungarian。

调用：`auto [cost,match]=hungarian(a);`，要求 `n<=m`。

复杂度：$O(n^2m)$。

最大坑：允许不匹配时要补虚点；最大价值可令 `cost=-value`；`match` 为 0-based。

## 后缀数组

看到：所有后缀排序、两个后缀 LCP、最长重复子串、本质不同子串、多个子串字典序比较。

想到：`sa + rank + lcp + RMQ`。

调用：`SuffixArray suf(s); suf.get_lcp(i,j);`

复杂度：构造 $O(n\log n)$，查询 $O(1)$。

最大坑：`sa[k]` 是第 k 小后缀起点；`lcp[k]` 对应 `sa[k-1]` 与 `sa[k]`。

## 匹配算法 10 秒选择

| 特征 | 选择 |
| --- | --- |
| 二分图、无权、只问最大数量 | 普通二分图匹配 / Dinic |
| 二分图完整权值矩阵、一一指派 | Hungarian |
| 一般无向图、奇环、无权最大匹配 | Blossom |
| 容量 > 1 / 中间层 / 路径 + 费用 | 最小费用最大流 |

<div style="page-break-after: always;"></div>

# 第二部分：详细识别与使用手册

这不是系统教材，而是一份“以前没学过，但场上可能临时套出模板题”的使用手册。

推荐使用顺序：

1. 先看第一部分“赛场 2 分钟速查”，用题目特征定位算法；
2. 再看第二部分对应章节，只理解识别、建模、接口和坑；
3. 最后到第三部分代码附录复制对应模板，并补上题目输入、建图或状态转移；
4. 先用样例和自己构造的最小边界检查，再提交。

所有模板均为 **0-based**，除非章节另有说明。模板文件本身不带 `main`，本文件中的调用片段就是最小使用示例。

| 算法 | 模板文件 | 最常见触发词 |
| --- | --- | --- |
| SG 函数 | `SG.cpp` | 公平组合游戏、不能动者输、多个独立子游戏 |
| NTT 卷积 | `FFT_NTT.cpp` | $\sum a_i b_{k-i}$、下标和、两边各选一个 |
| 最大流 | `Dinic.cpp` | 最多安排多少、容量上限、二分图匹配 |
| 最小费用最大流 | `MinCostMaxFlow.cpp` | 容量 + 每种选择的费用/收益 |
| 任意模数卷积 | `ArbitraryModConvolution.cpp` | 卷积但答案模数为 $10^9+7$ 等 |
| Miller-Rabin | `MillerRabin.cpp` | 64 位整数判质数 |
| Pollard Rho | `PollardRho.cpp` | 64 位整数质因数分解 |
| Blossom | `Blossom.cpp` | 有奇环的一般图最大匹配 |
| floor_sum | `FloorSum.cpp` | 大量线性下取整、格点计数 |
| Hungarian | `Hungarian.cpp` | 完整权值矩阵、一一指派、最小总代价 |
| 后缀数组 | `SuffixArray.cpp` | 所有后缀排序、后缀 LCP、重复子串 |

---

## 1 SG 函数 / Sprague-Grundy

### 1. 它到底解决什么问题

看到“两个人轮流操作同一个有限游戏，谁不能操作谁输”，需要判断先手胜负；或者有多堆、多个棋子等互不影响的小游戏，每次只能选择其中一个进行操作，应想到 SG。

SG 可以先当成一种递归 DP：每个状态根据它一步能到达的后继状态求一个非负整数。单个游戏看 SG 是否为零；多个独立游戏把各自 SG 异或。

### 2. 赛场识别信号

看到：

- 两个人轮流操作；
- 两个人拥有完全相同的操作规则；
- 当前可选操作只由当前状态决定；
- 没有随机因素，且游戏一定会结束；
- 通常是不能操作的人输；
- 多堆石子、多个棋子、多个互不影响的局面，每步只动一个。

想到：公平组合游戏，尝试 SG。

常见伪装是：题目不提 Nim，只给很多相同的小物件；每个物件能独立改变状态，问先手是否存在必胜策略。

### 3. 它不适合解决什么问题

- 两名玩家可执行的操作不同；
- 有随机事件或隐藏信息；
- 状态可能无限循环；
- 不能操作的人反而获胜（misère，不能直接机械套普通 SG）；
- 操作一个子游戏会改变另一个子游戏，此时不能分别求 SG 再异或。

### 4. 我最少需要知道什么

#### mex

`mex(S)` 是集合中没有出现的最小非负整数，不是 `max + 1`：

- `mex({0,1,3}) = 2`；
- `mex({1,2}) = 0`；
- `mex({0,2}) = 1`；
- `mex({0,1,2}) = 3`。

#### 单个状态内部用 mex

$$
SG(x)=mex\{SG(y)\mid x\text{ 可以一步走到 }y\}.
$$

没有合法后继的终止状态满足 `SG(x)=0`。单个游戏：SG 为零时先手必败，非零时先手必胜。

#### 多个独立游戏之间才用 xor

若每次只操作一个子游戏，且不会影响其他子游戏：
$$
SG_{all}=SG_1\oplus SG_2\oplus\cdots.
$$

总异或为零时先手败，否则先手胜。

> **最重要的区分：一个状态内部是 `mex(后继 SG)`；多个独立游戏合并才是 xor。**

### 5. 板子接口怎么使用

模板：`SG.cpp`。

状态已经建成有向无环图时：

```cpp
vector<vector<int>> next(V);
// next[x].push_back(y)：状态 x 可以一步走到 y
auto sg = calc_sg(next);

int all = 0;
for(int state : games) all ^= sg[state];
cout <<(all ? "First" : "Second") <<'\n';
```

减法游戏（每次从一堆中减去指定数量）：

```cpp
vector<int> moves{1, 3, 4};
auto sg = subtraction_sg(N, moves);

int all = 0;
for(int stones : piles) all ^= sg[stones];
```

如何得到 `next[x]` 完全由题意决定，SG 没有类似 `addEdge` 后便自动理解游戏规则的万能接口。

### 6. 一个极简模板题模型

一堆有 $n$ 个石子，每次拿 $1$ 或 $2$ 个，不能拿的人输：

- `SG(0)=mex({})=0`；
- `SG(1)=mex({SG(0)})=mex({0})=1`；
- `SG(2)=mex({SG(1),SG(0)})=mex({1,0})=2`；
- `SG(3)=mex({SG(2),SG(1)})=mex({2,1})=0`；
- `SG(4)=mex({SG(3),SG(2)})=mex({0,2})=1`；
- `SG(5)=mex({SG(4),SG(3)})=mex({1,0})=2`。

如果有三堆，大小为 $2,3,5$，则总 SG 为 `sg[2] ^ sg[3] ^ sg[5] = 2 ^ 0 ^ 2 = 0`，先手败。

### 7. 复杂度和实际数据范围

- 状态图较小：记忆化 DFS，约为 $O(V+E)$ 再加 mex 开销；
- 状态为 `0..N` 且只向更小状态转移：从小到大 DP；
- 减法集合大小为 $K$：$O(NK)$，通常 $N,K$ 的乘积在几千万内可用；
- 状态巨大时往往需要找周期或数学规律，已经不是这份简单黑盒的覆盖范围。

### 8. 最常见的坑

- mex 不是最大值加一；
- `SG(x)` 是后继 SG 的 mex，不是 xor；
- xor 只用于多个真正独立的子游戏；
- 终止状态 SG 为零；
- 普通 SG 默认不能走的人输；
- misère 规则不能直接套；
- 两个玩家规则不同不能套；
- 状态图有环时不能直接做普通递归 SG；
- 记忆化 DFS 注意递归深度；
- mex 标记数组只需开到“后继数量 + 1”，过大的 SG 不影响当前 mex。

### 9. SG 30 秒判断

看到：轮流操作、规则相同、一定结束、不能动者输、一个操作只改变一个独立子游戏。

想到：单状态 `mex`，多游戏 xor。

调用：`calc_sg(next)` 或 `subtraction_sg(N, moves)`。

复杂度：可直接枚举状态和转移时使用。

最大坑：**mex 与 xor 不要混；多个子游戏必须独立。**

---

## 2 FFT / NTT：只把它当卷积使用

### 1. 它到底解决什么问题

要计算
$$
c[k]=\sum_{i+j=k}a[i]b[j]=\sum_i a[i]b[k-i],
$$
朴素枚举所有 $(i,j)$ 是 $O(nm)$。NTT 能一次算出所有 $c[k]$。

`c[k]` 的含义就是：从 `a` 中选下标 `i`，从 `b` 中选下标 `j`，只要 `i+j=k`，就把 `a[i]*b[j]` 加进答案。

### 2. 赛场识别信号

看到：

- 公式直接出现 `ans[k] = Σ a[i] * b[k-i]`；
- 从 A、B 两边各选一个，贡献只与下标和 `i+j` 有关；
- 两个频次数组组合，统计所有可能的和值；
- 多项式相乘，求每一项系数；
- 统计距离或差值：通常把其中一边反转后变成下标和；
- 原本双重循环，长度约 $10^5$。

想到：卷积。题面通常不会写“卷积”，而会藏成和值、距离、频率配对或组合计数。

### 3. 它不适合解决什么问题

- 贡献依赖 `max(i,j)`、`gcd(i,j)` 等，不能写成固定下标和；
- 只求单个 $k$ 且枚举很小，没必要上 NTT；
- 模数不是 `998244353` 时，不能直接拿本模板输出目标模数答案；
- 需要精确大整数且真实系数超过模数时，单模 NTT 会丢信息。

### 4. 我最少需要知道什么

- 输入是两个系数/频次数组 `a,b`；
- 输出长度为 `a.size()+b.size()-1`；
- 输出 `c[k]` 等于所有 `i+j=k` 的乘积之和；
- 本模板所有结果对 `998244353` 取模；
- 负系数会自动规范到模数范围；
- 不需要理解单位根与蝶形变换才能调用。

### 5. 板子接口怎么使用

模板：`FFT_NTT.cpp`。

```cpp
vector<i64> a{1, 2};
vector<i64> b{3, 4};
auto c = convolution(a, b);
// c = {3, 10, 8}
```

频率计数模型：若 `cntA[x]`、`cntB[y]` 是两组数的出现次数，则卷积结果 `c[s]` 是满足 `x+y=s` 的有序跨组配对数。

差值模型：想统计 `x-y=d` 时，可把 `cntB` 的下标反转，再做卷积；卷积下标与真实差值之间会多一个固定偏移，纸上先写清映射。

### 6. 一个极简模板题模型

从集合 A 选一个重量、从集合 B 选一个重量，问每个总重量有多少种选法。

把 `a[x]` 设为 A 中重量 `x` 的数量，把 `b[y]` 设为 B 中重量 `y` 的数量。调用 `convolution(a,b)`，输出 `c[s]`，它恰好统计所有 `x+y=s` 的方案。

### 7. 复杂度和实际数据范围

复杂度 $O(L\log L)$，其中 $L$ 是不小于结果长度的最小二次幂。普通区域赛中长度 $10^5\sim10^6$ 是常见使用范围。本模板的变换长度必须不超过 $2^{23}$。

### 8. 最常见的坑

- 下标含义和偏移写错；
- 差值统计忘记反转数组；
- 答案是否把 `(x,y)` 与 `(y,x)` 重复计算；
- 同一集合中选两个时，是否允许选到同一个元素；
- 结果模数不是 `998244353`；
- 需要普通整数答案却被单模结果截断；
- 空数组卷积返回空数组。

### 9. NTT 30 秒判断

看到：所有 `i+j=k` 的贡献、两边各选一个、长度约 $10^5$、答案模 `998244353`。

想到：卷积。

调用：`auto c = convolution(a,b);`

复杂度：$O(L\log L)$。

最大坑：下标反转/偏移和目标模数。

---

## 3 网络流 / Dinic

### 1. 它到底解决什么问题

题目只问“最多能成功安排多少、通过多少、匹配多少”，同时每类对象、选择关系或通道都有次数上限，可以把过程画成从源点 `S` 经过若干层流向汇点 `T`，应想到最大流。

### 2. 赛场识别信号

看到：

- 最多安排多少个人、任务、路线或资源；
- 每个人/机器/任务都有使用次数上限；
- “人可以做哪些任务”形成二分关系；
- 一条边或一个点最多被若干条路径使用；
- 从起点向终点输送尽量多的单位资源；
- 最少删除多少条边才能让两点不连通（可转最大流/最小割）。

想到：能否把每次成功方案看成从 `S` 到 `T` 的一单位流。

### 3. 它不适合解决什么问题

- 每种选择有不同费用且还要优化总费用：考虑最小费用最大流；
- 只是普通最短路或生成树；
- 约束无法表达成局部容量，一次选择会产生复杂全局影响；
- 一般图最大匹配有奇环：不要硬套简单的二分图流模型。

### 4. 我最少需要知道什么

| 概念 | 现场理解 |
| --- | --- |
| 源点 `S` | 所有流从这里出发 |
| 汇点 `T` | 所有成功方案最终到这里 |
| `u -> v, cap` | 这条关系最多允许使用 `cap` 次 |
| flow | 最终成功安排/通过/匹配的单位数 |
| 反向边 | `addEdge` 自动添加，调用时不用手工处理 |

#### 题目语言到建图动作

| 题目说法 | 建图动作 |
| --- | --- |
| 每个人最多选择一次 | `S -> person`，`cap=1` |
| 每个人最多做 $k$ 个任务 | `S -> person`，`cap=k` |
| 人 $i$ 可以做任务 $j$ | `person_i -> task_j`，通常 `cap=1` 或足够大 |
| 每个任务最多被一个人完成 | `task -> T`，`cap=1` |
| 任务最多被 $k$ 个人完成 | `task -> T`，`cap=k` |
| 某类资源共有 $k$ 份 | 从资源节点连出/连向资源节点的限制边，`cap=k` |
| 一条有向边最多使用一次 | 该边 `cap=1` |
| 一条有向边最多使用 $k$ 次 | 该边 `cap=k` |
| 最多允许 $k$ 条方案/路径 | 调用 `flow(S,T,k)`，或在源点前加总容量 $k$ |
| 某个点最多经过一次 | 拆点：`u_in -> u_out, cap=1` |
| 某个点最多经过 $k$ 次 | 拆点：`u_in -> u_out, cap=k` |
| 无容量限制的转移关系 | `cap=INF`，但 INF 只需大于可能总流量 |

#### 拆点

当限制的是“点本身能被使用多少次”，普通边容量无法直接约束所有经过该点的路径。把 `u` 拆为 `u_in` 和 `u_out`：

- 所有原本进入 `u` 的边连到 `u_in`；
- 所有原本离开 `u` 的边从 `u_out` 出发；
- 中间连 `u_in -> u_out`，容量就是该点最多允许使用的次数。

看到“城市只能经过一次、节点有容量、站点最多容纳 $k$ 个”就检查拆点。

### 5. 板子接口怎么使用

模板：`Dinic.cpp`。

```cpp
Dinic mf(V);
mf.addEdge(u, v, cap);       // 有向边
i64 ans = mf.flow(S, T);     // 最大流
i64 part = mf.flow(S, T, k); // 最多再发送 k 单位
```

`flow` 会修改残量容量。同一个对象再次调用会在已有流的基础上继续增广；若想从头计算，重新建图。

### 6. 三个极简模板题模型

#### 例 1：普通二分图最大匹配

$n$ 个人、$m$ 个任务，每人最多一个任务，每个任务最多一人；给出哪些人能做哪些任务。

设人员节点为 `[0,n-1]`，任务节点为 `[n,n+m-1]`，`S=n+m`，`T=S+1`：

```cpp
Dinic mf(n + m + 2);
for(int i = 0; i < n; i ++) mf.addEdge(S, i, 1);
for(auto [i, j] : can_do) mf.addEdge(i, n + j, 1);
for(int j = 0; j < m; j ++) mf.addEdge(n + j, T, 1);
cout <<mf.flow(S, T) <<'\n';
```

一单位流 `S -> 人 -> 任务 -> T` 就是一对匹配。

#### 例 2：点只能经过一次

要求从起点到终点最多找多少条内部点不相交路径。每个普通点 `u` 拆成 `in(u),out(u)`，连 `in(u)->out(u),cap=1`；原边 `u->v` 改为 `out(u)->in(v),cap=INF`。源点和汇点通常不限制，拆点边容量设为 INF。

#### 例 3：容量不为 1

有若干员工和机器：员工 $i$ 最多负责 `a[i]` 个项目，机器 $j$ 最多处理 `b[j]` 个项目，给出允许的员工—机器组合。

- `S -> employee_i, cap=a[i]`；
- `employee_i -> machine_j, cap=INF`（或该组合自身上限）；
- `machine_j -> T, cap=b[j]`。

最大流就是最多能安排的项目数量。容量的直觉始终是“这件事最多允许发生多少次”。

### 7. 复杂度和实际数据范围

Dinic 一般上界常写 $O(V^2E)$，但分层图和当前弧优化在常见稀疏网络、二分图单位容量中通常很快。区域赛里数千至数万点、数万到数十万边需要结合图形和时限判断；不要显式建立本可压缩的平方级边数。

### 8. 最常见的坑

- 点数开小或编号冲突；
- 忘记源点、汇点边上的容量限制；
- 点容量题忘记拆点；
- 无向容量边不是一次 `addEdge(u,v,cap)`：那只是有向边；
- `INF` 过小限制了答案，过大又可能造成总流溢出；
- `i64` 容量仍要保证总流不溢出；
- 误把带费用问题当普通最大流；
- 复制模板后手工添加反向边，导致重复。

### 9. Dinic 30 秒判断

看到：最多安排/匹配/通过多少，每个对象有次数上限，没有费用，能画成 `S -> 若干层 -> T`。

想到：最大流；“最多 $k$ 次”就是容量 $k$。

调用：`mf.addEdge(u,v,cap)`，`mf.flow(S,T)`。

复杂度：常见稀疏模型可用，避免平方建边。

最大坑：点容量要拆点，`addEdge` 是有向边。

---

## 4 最小费用最大流

### 1. 它到底解决什么问题

最大流只关心能送多少；如果每次选择还带有费用或收益，并且要在最大流量下让总代价最小，或者必须发送恰好 $k$ 单位且代价最小，应想到最小费用最大流。

### 2. 赛场识别信号

看到：

- 人—任务分配，但不同组合有不同费用；
- 先最大化匹配数量，再最小化总代价；
- 必须完成恰好 $k$ 次选择，求最小成本；
- 网络有容量，流经不同边产生不同费用；
- 选择一次获得价值，需要在容量约束下最大化总价值。

想到：在最大流建图的每条边上再填写单位费用。

### 3. 它不适合解决什么问题

- 完整/稠密的一一指派矩阵：Hungarian 通常更直接、更快；
- 没有费用：用 Dinic；
- 一般图无权最大匹配：用 Blossom；
- 可选任意数量、只挑“有利可图”的流时，普通“尽量增广到最大流”的接口语义不一定符合题意。

### 4. 我最少需要知道什么

- `cap`：这条选择最多使用几次；
- `cost`：每发送一单位流产生多少费用；
- `need`：最多希望发送多少单位；
- 返回 `(flow,cost)`：实际发送量和对应最小费用；
- `addEdge` 自动添加反向边；
- 最大收益可令 `cost=-value`，最后收益为 `-cost`。

若题目要求**恰好**发送 `need` 单位，调用后必须检查 `flow==need`，否则无解。

### 5. 板子接口怎么使用

模板：`MinCostMaxFlow.cpp`。

```cpp
MinCostMaxFlow mf(V);
mf.addEdge(u, v, cap, cost);
auto [flow, cost] = mf.flow(S, T);       // 最大流量下费用最小
auto [flow, cost] = mf.flow(S, T, need); // 最多发送 need 单位
```

模板允许初始负费用边，内部先计算一次初始势能；但不要构造可无限获利的可达负环。总费用必须能放进 `i64`。

### 6. 三个极简模板题模型

#### 例 1：人分配任务，恰好匹配 k 对且费用最小

- `S -> person_i`：`cap=1,cost=0`；
- `person_i -> task_j`：`cap=1,cost=cost[i][j]`；
- `task_j -> T`：`cap=1,cost=0`；
- 调用 `mf.flow(S,T,k)`；
- 若 `flow<k` 则无解，否则返回的 `cost` 就是答案。

#### 例 2：最大收益

若分配 `i -> j` 获得 `value[i][j]`，把中间边费用设为 `-value[i][j]`。若必须选 $k$ 对，发送 $k$ 单位，最终最大收益是 `-cost`。

#### 例 3：容量不为 1

供应点 $i$ 有 `supply[i]` 件货物，需求点 $j$ 最多接收 `demand[j]` 件，运输一件费用为 `c[i][j]`：

- `S -> supply_i, cap=supply[i], cost=0`；
- `supply_i -> demand_j, cap=允许运输上限, cost=c[i][j]`；
- `demand_j -> T, cap=demand[j], cost=0`。

若要运恰好 `need` 件，就调用带 `need` 的版本并检查流量。

### 7. 复杂度和实际数据范围

模板先执行一次 SPFA 处理负边，之后每次增广使用势能 + Dijkstra，单次约 $O(E\log V)$。增广次数取决于网络；若每条路径只能送一单位，最坏会增广很多次。几百至几千点、数万边的常规分配通常可考虑，巨大单位流网络要特别评估。

### 8. 最常见的坑

- 固定流量问题忘记传 `need`；
- 传了 `need` 却不检查实际 `flow`；
- 最大收益忘记费用取负或最终答案取负；
- 把“每次选择的总费用”误写成边费用，单位流经过的所有边费用会相加；
- 总费用 `flow*cost` 溢出；
- 有可达负环；
- 只需普通指派却建出过大的流图。

### 9. 最小费用最大流 30 秒判断

看到：容量限制 + 每种选择还有 cost/value；最大流量下费用最小，或固定流 $k$ 单位。

想到：MCMF。

调用：`mf.flow(S,T,need)`。

复杂度：每次增广约 $O(E\log V)$。

最大坑：检查 `flow==need`；收益用负费用。

---

## 5 任意模数卷积

### 1. 它到底解决什么问题

已经确认题目是卷积，但最终答案模数不是 `998244353`，例如模 `1e9+7`，不能直接使用单模 NTT 时使用。

### 2. 赛场识别信号

看到与 NTT 相同的卷积结构，同时题目指定 `mod=1e9+7`、`1e9+9` 或其他非 NTT 友好模数。

### 3. 它不适合解决什么问题

- 不满足卷积形式；
- 结果本来就模 `998244353`；
- 变换长度超过 $2^{21}$；
- 目标模数、数组长度和系数使真实单项卷积系数超过三个 NTT 模数的乘积。

### 4. 我最少需要知道什么

模板会在三个 NTT 模数下分别卷积，再用 CRT 恢复真实非负系数，最后对目标模数取模。调用者不需要手写 CRT。

当前接口要求目标 `mod` 能放进正 `int`。输入先按目标模数规范到 `[0,mod)`；因此负数也可传入。

### 5. 板子接口怎么使用

模板：`ArbitraryModConvolution.cpp`。

```cpp
int mod = 1'000'000'007;
vector<i64> a{1, 2}, b{3, 4};
auto c = convolution_mod(a, b, mod);
// {3, 10, 8}
```

### 6. 一个极简模板题模型

两个频次数组组合，求每个和值的方案数，答案模 `1e9+7`。建出 `cntA,cntB` 后调用 `convolution_mod(cntA,cntB,1e9+7)`。

### 7. 复杂度和实际数据范围

$O(L\log L)$，但需要三次 NTT，时间和内存常数约为单模版本的三倍。模板限制变换长度不超过 $2^{21}$；常见的两段长度各 $2\times10^5$ 没问题。

### 8. 最常见的坑

- 误以为任意 `i64` 模数、任意长度都能使用；
- CRT 乘积不足以唯一恢复真实卷积系数；
- 明明模 `998244353` 却使用三模版本浪费时间；
- 卷积下标偏移错误。

模板内有断言检查长度和最坏系数上界；断言失败时不能直接删断言硬跑。

### 9. 任意模数卷积 30 秒判断

看到：确定是卷积，但目标模数不是 `998244353`。

想到：三模 NTT + CRT。

调用：`convolution_mod(a,b,mod)`。

复杂度：$O(L\log L)$，约三倍 NTT 常数。

最大坑：长度上限与 CRT 可恢复范围。

---

## 6 Miller-Rabin

### 1. 它到底解决什么问题

可靠判断一个 64 位无符号整数是不是质数，而不枚举到 $\sqrt n$。

### 2. 赛场识别信号

看到：单个或少量整数可到 $10^{18}$，只需要判断质数/合数，普通试除显然过不了。

### 3. 它不适合解决什么问题

- 要求完整质因数分解：配合 Pollard Rho；
- 上界只有 $10^6$ 且询问很多：筛法更合适；
- 需要统计区间内全部质数：考虑筛法或分段筛。

### 4. 我最少需要知道什么

接口使用 `u64`，模乘内部用 `__uint128_t` 防止溢出。模板使用对完整 64 位范围可靠的固定 bases，不需要自己随机选底数。

### 5. 板子接口怎么使用

模板：`MillerRabin.cpp`。

```cpp
u64 n; cin >>n;
cout <<(isPrime(n) ? "prime" : "composite") <<'\n';
```

### 6. 一个极简模板题模型

输入一个 $n\le10^{18}$，判断它是否为质数。读成 `u64`，调用 `isPrime(n)`。

### 7. 复杂度和实际数据范围

常数个 bases，每个做 $O(\log n)$ 次 128 位模乘。对单个或很多个 64 位数通常都足够快。

### 8. 最常见的坑

- `0`、`1` 不是质数；
- `2` 是质数，其余偶数是合数；
- 用有符号乘法导致溢出；
- 换成一组不覆盖 64 位范围的 bases；
- 输入可能超过 `long long` 时仍使用有符号类型读取。

### 9. Miller-Rabin 30 秒判断

看到：$n\le10^{18}$ 或 u64，要求判质数。

想到：Miller-Rabin。

调用：`isPrime(n)`。

复杂度：常数个 $O(\log n)$ 模幂。

最大坑：1 不是质数，模乘必须用 128 位。

---

## 7 Pollard Rho

### 1. 它到底解决什么问题

把一个 64 位整数分解成全部质因子。当 $n$ 到 $10^{18}$，试除到 $\sqrt n$ 不可能完成时使用。

### 2. 赛场识别信号

看到：大整数、质因数分解、求最大质因子/质因子个数/由分解计算欧拉函数或约数，而 $n$ 远超筛法和试除范围。

### 3. 它不适合解决什么问题

- $n\le10^{12}$ 且数据很少时，试除有时更短更稳；
- 大量数都不超过固定较小上界时，用最小质因子筛；
- 只问是否为质数，直接 Miller-Rabin。

### 4. 我最少需要知道什么

Pollard Rho 先用 Miller-Rabin 判断当前数是否已经是质数，否则随机找到一个非平凡因子并递归分解。它是随机化算法；极少数运行慢时会自动换参数重试。

### 5. 板子接口怎么使用

模板：`PollardRho.cpp`，已经内置 Miller-Rabin。

```cpp
u64 n; cin >>n;
auto fac = factor(n);
for(u64 p : fac) cout <<p <<' ';
```

`factor(12)` 返回 `{2,2,3}`；`factor(1)` 返回空数组。

### 6. 一个极简模板题模型

输入 $n\le10^{18}$，输出最大质因子。调用 `factor(n)`，若 `n>1`，答案是排序后数组的最后一个元素。

### 7. 复杂度和实际数据范围

没有简单的确定最坏上界；64 位整数实际通常很快，适合少量到中等数量的大整数。大量对抗性数据仍需关注时限。

### 8. 最常见的坑

- 忘记包含重复质因子；
- `n=1` 时数组为空；
- 自己删除 128 位模乘导致溢出；
- 随机过程偶尔慢，不要改成固定且糟糕的常数；
- 要统计不同质因子时记得 `sort + unique`。

### 9. Pollard Rho 30 秒判断

看到：64 位大整数 + 完整质因数分解。

想到：Pollard Rho + Miller-Rabin。

调用：`auto fac=factor(n);`

复杂度：随机化，64 位实际通常很快。

最大坑：1 无质因子；返回结果包含重复。

---

## 8 一般图最大匹配 Blossom

### 1. 它到底解决什么问题

在一般无向图中选择尽量多的边，使任意两条被选边不共享端点。图可能存在奇环，无法自然分成左右两部分。

### 2. 赛场识别信号

看到：两两配对、每个对象最多出现一次、只问最多配多少对；任意两个对象之间可能兼容，关系图存在三角形等奇环。

### 3. 它不适合解决什么问题

- 图明确是二分图：优先二分图匹配、Hopcroft-Karp 或 Dinic；
- 边有权值并要求最大权匹配：本模板不支持；
- 要完美匹配数量或计数：不是无权最大匹配；
- 要匹配两侧完整权值矩阵：考虑 Hungarian。

### 4. 我最少需要知道什么

把每个对象建成一个点，允许组成一对就在两点之间连无向边。模板内部自动处理奇环收缩，不需要理解缩花过程。

### 5. 板子接口怎么使用

模板：`Blossom.cpp`。

```cpp
Blossom bm(n);
for(auto [u,v] : edges) bm.addEdge(u,v);
int pairs = bm.solve();
// bm.match[u] == -1 表示未匹配，否则是匹配点编号
```

### 6. 一个极简模板题模型

有 $n$ 个人，某些两人可以组队，每人最多加入一个队，求最多组成几队。人是点，兼容关系是无向边，调用 `solve()`。

### 7. 复杂度和实际数据范围

$O(n^3)$。通常数百点较稳；接近上千点要结合边数和时限谨慎判断。模板使用邻接表，但核心仍是三次级算法。

### 8. 最常见的坑

- 把二分图问题无脑上 Blossom；
- 忘记是 0-based；
- 把有向关系直接当无向兼容关系；
- 题目要求最大权而模板只有最大 cardinality；
- `solve()` 返回匹配边数，不是已匹配点数。

### 9. Blossom 30 秒判断

看到：一般无向图、可能有奇环、每点最多匹配一次、最大匹配数。

想到：Blossom。

调用：`bm.addEdge(u,v); bm.solve();`

复杂度：$O(n^3)$。

最大坑：有权匹配不能套；二分图优先更简单算法。

---

## 9 floor_sum

### 1. 它到底解决什么问题

快速计算
$$
\sum_{i=0}^{n-1}\left\lfloor\frac{ai+b}{m}\right\rfloor.
$$

当逐个枚举 $i$ 太慢，但分子是关于 $i$ 的一次式时使用。

### 2. 赛场识别信号

看到：

- 大量 `floor((a*i+b)/m)` 求和；
- 对每个 $i$，合法整数 $j$ 的数量恰好是某个下取整；
- 统计直线下方格点；
- 线性不等式 `m*j <= a*i+b` 的整数解数量；
- 周期很大，不能按 $i$ 枚举。

想到：把答案明确写成 `i=0..n-1` 的 floor_sum。

### 3. 它不适合解决什么问题

- 分子含 $i^2$、指数或其他非线性项；
- 分母随 $i$ 变化；
- $n$ 很小，直接循环更不易错；
- 式子中有额外区间截断，尚未拆成若干标准 floor_sum。

### 4. 我最少需要知道什么

- 下标固定为 `0..n-1`；
- 参数顺序是 `(n,m,a,b)`；
- 计算的是 `floor((a*i+b)/m)`；
- 本模板要求 `n>=0,m>0`，支持 `a,b` 为负；
- 返回 `i128`，因为总和可能超过 `i64`。

### 5. 板子接口怎么使用

模板：`FloorSum.cpp`。

```cpp
i128 ans = floor_sum(n, m, a, b);
print_i128(ans);
cout <<'\n';
```

若题目枚举 `i=1..n`，可改写为 `j=i-1`：
$$
ai+b=a(j+1)+b=aj+(a+b),
$$
所以调用 `floor_sum(n,m,a,a+b)`，但注意 `a+b` 的溢出。

### 6. 一个极简模板题模型

统计整数点 $(i,j)$ 满足 `0<=i<n`、`0<=j`、`m*j<=a*i+b`。对固定 $i$，合法非负 $j$ 数量通常是 `floor((a*i+b)/m)+1`，但当右侧为负时需先处理无解区间。把合法区间切好后，floor 部分交给 `floor_sum`。

### 7. 复杂度和实际数据范围

类似欧几里得算法，$O(\log\max(|a|,m))$。即使 $n$ 达到 $10^{18}$，只要参数和答案能放入 `i128` 也可使用。

### 8. 最常见的坑

- 把下标误认为 `1..n`；
- 参数 `m,a` 顺序写反；
- “合法 j 数量”常常比最大合法 j 多 1；
- 还有 `max(0,...)` 时没有先切掉负数区间；
- 返回值用 `long long` 溢出；
- C++ 的负数除法向零截断，不能自己机械代替数学 floor。

### 9. floor_sum 30 秒判断

看到：对巨大范围的 $i$，累加一次式除固定正数后的 floor；或直线下格点。

想到：floor_sum。

调用：`floor_sum(n,m,a,b)`，下标 `0..n-1`。

复杂度：对数级。

最大坑：下标偏移、`+1` 和负数区间。

---

## 10 Hungarian / Assignment Problem

### 1. 它到底解决什么问题

有 $n$ 个左侧对象、$m$ 个右侧对象，每个左侧对象必须选择一个互不重复的右侧对象，匹配 `i->j` 的费用为 `a[i][j]`，求总费用最小。

### 2. 赛场识别信号

看到：左右两组、一一指派、每种配对都有权值；输入通常直接给出完整或接近完整的权值矩阵；要求总代价最小或总价值最大。

### 3. 它不适合解决什么问题

- 只关心最多能匹配多少，没有权值：普通二分图匹配；
- 有容量大于 1、中间层或路径结构：MCMF；
- 一般图有奇环：Blossom；
- 不是所有左点都必须匹配，且“选多少”本身也是决策：需要补虚点或换模型。

### 4. 我最少需要知道什么

本模板语义是：**每个左点恰好匹配一个不同右点**，要求 `n<=m`。`match[i]` 返回左点 $i$ 选择的右点。

- 若 `n>m` 且每个左点都必须匹配：无解；
- 若题意对两侧完全对称，只需匹配较小一侧：可以转置矩阵，再把答案映射回来；
- 若允许“不匹配”：添加费用为“不匹配代价”的虚拟右点；
- 求最大价值：直接令 `cost=-value`，返回价值为 `-cost`，注意溢出。

### 5. 板子接口怎么使用

模板：`Hungarian.cpp`。

```cpp
vector<vector<i64>> a(n, vector<i64>(m)); // n <= m
auto [cost, match] = hungarian(a);
for(int i = 0; i < n; i ++)
	cout <<i <<" -> " <<match[i] <<'\n';
```

### 6. 一个极简模板题模型

三名工人完成三个不同任务，`a[i][j]` 是工人 $i$ 完成任务 $j$ 的时间。每人恰好一个任务且任务不能重复，调用 `hungarian(a)`，返回最小总时间和分配方案。

### 7. 复杂度和实际数据范围

矩形版本复杂度 $O(n^2m)$（$n\le m$），空间 $O(n+m)$ 外加输入矩阵。数百到约一两千规模要结合时限判断；稠密矩阵通常比建 MCMF 更合适。

### 8. 最常见的坑

- `n>m` 仍直接调用触发断言；
- 题目允许不匹配，却强制每个左点匹配；
- 最大价值转换后忘记取负；
- 用 `C-value` 转换时，答案要按实际匹配数还原 `n*C-cost`；
- 极大正负费用使势变量或总和溢出；
- `match` 是左点到右点，均为 0-based。

### 9. Hungarian 30 秒判断

看到：完整权值矩阵、左右一一指派、每个左点必须匹配、优化总权值。

想到：Hungarian。

调用：`hungarian(a)`，要求 `n<=m`。

复杂度：$O(n^2m)$。

最大坑：是否允许不匹配，以及最大值/最小值转换。

---

## 11 后缀数组

### 1. 它到底解决什么问题

一次性把一个字符串的所有后缀按字典序排序，并支持查询任意两个后缀的最长公共前缀。很多重复子串、后缀字典序和子串比较问题都能转到这两个能力。

### 2. 赛场识别信号

看到：

- 所有后缀排序或第 $k$ 小后缀；
- 比较两个后缀/多个子串的字典序；
- 任意两个后缀的 LCP；
- 最长重复子串；
- 本质不同子串数量；
- 重复结构、多个字符串的公共片段（常用分隔符拼接）。

想到：后缀数组 `sa + rank + lcp`。

### 3. 它不适合解决什么问题

- 只匹配一个模式串：KMP/Z 通常更短；
- 只求回文：Manacher；
- 在线插入、删除字符串：静态后缀数组不适合；
- 只需字符串哈希能简单解决的少量比较。

### 4. 我最少需要知道什么

- `sa[k]`：字典序第 $k$ 小的后缀在原串中的起点；
- `rank[i]`：从位置 $i$ 开始的后缀排第几；
- `lcp[k]`：`suffix(sa[k-1])` 与 `suffix(sa[k])` 的 LCP，`lcp[0]=0`；
- `get_lcp(i,j)`：原串位置 $i,j$ 开始的两个后缀 LCP。

#### `banana` 示例

| 排名 k | `sa[k]` | 后缀 | `lcp[k]`（与上一行） |
| --- | ---: | --- | ---: |
| 0 | 5 | `a` | 0 |
| 1 | 3 | `ana` | 1 |
| 2 | 1 | `anana` | 3 |
| 3 | 0 | `banana` | 0 |
| 4 | 4 | `na` | 0 |
| 5 | 2 | `nana` | 2 |

因此：

```text
sa   = [5,3,1,0,4,2]
rank = [3,2,5,1,4,0]
lcp  = [0,1,3,0,0,2]
```

例如 `get_lcp(1,3)=3`，因为 `anana` 与 `ana` 的公共前缀是 `ana`。

### 5. 板子接口怎么使用

模板：`SuffixArray.cpp`。

```cpp
string s; cin >>s;
SuffixArray suf(s);
cout <<suf.sa[k] <<'\n';
cout <<suf.rank[i] <<'\n';
cout <<suf.get_lcp(i, j) <<'\n';
```

最长重复子串长度是 `max(lcp)`。本质不同子串数量：
$$
\frac{n(n+1)}2-\sum_{k=0}^{n-1}lcp[k].
$$

比较两个等长子串 `s[i..i+len-1]`、`s[j..j+len-1]`：先求 `x=get_lcp(i,j)`；若 `x>=len` 则相等，否则比较 `s[i+x]` 与 `s[j+x]`。

### 6. 一个极简模板题模型

求最长重复子串长度。构造 `SuffixArray suf(s)`，答案为 `*max_element(suf.lcp.begin(),suf.lcp.end())`；空串需要单独处理。

### 7. 复杂度和实际数据范围

倍增 + 计数排序构造 $O(n\log n)$，LCP $O(n)$，RMQ 预处理 $O(n\log n)$，单次 `get_lcp` 为 $O(1)$。$n$ 在几万到数十万时常用，内存主要由稀疏表的 $O(n\log n)$ 占用。

### 8. 最常见的坑

- `sa` 与 `rank` 含义写反；
- 本模板的 `lcp[k]` 是与前一个后缀的 LCP；
- 子串比较时 LCP 不能超过待比较长度；
- 多字符串拼接时分隔符必须互异且不出现在原串；
- 普通竞赛字符串不能含字节值 `0`，模板内部把它当最小哨兵；
- 空串上取 `max_element`；
- RMQ 稀疏表内存较大。

### 9. 后缀数组 30 秒判断

看到：所有后缀字典序、任意后缀 LCP、最长重复或本质不同子串。

想到：Suffix Array。

调用：`SuffixArray suf(s)`，`suf.get_lcp(i,j)`。

复杂度：构造 $O(n\log n)$，LCP 查询 $O(1)$。

最大坑：`lcp[k]` 对应 `sa[k-1],sa[k]`，以及子串长度截断。

---

## 匹配与网络流算法选择表

| 题目结构 | 有无权值 | 容量/中间层 | 优先算法 |
| --- | --- | --- | --- |
| 明显左右两部，只问最多匹配多少 | 无 | 一对一 | 二分图匹配或 Dinic |
| 左右两部，完整权值矩阵，每个左点必须分配 | 有 | 一对一 | Hungarian |
| 一般无向图，不能二分，可能有奇环 | 无 | 一对一 | Blossom |
| 分配还有容量大于 1、中间层、路径或固定流量 | 有 | 复杂 | 最小费用最大流 |
| 只问网络最多通过多少 | 无 | 可有复杂容量 | Dinic |

最后检查一句：**能用更专门、更简单的算法时，不要因为手里有黑盒就强行上最重的模板。**

<div style="page-break-after: always;"></div>

# 第三部分：C++23 模板代码附录

> 下面代码按原资料汇总，方便直接复制。教学说明以前两部分为准。

## SG 函数 — `SG.cpp`

```cpp
/*
用途：公平组合游戏的 SG 值与减法游戏
什么时候用：两人规则相同、轮流操作、不能操作者输、状态一定结束
复杂度：通用 DAG 为 O(V+E+总 mex 空间)，减法游戏为 O(N*|moves|)
接口：auto sg = calc_sg(next); / auto sg = subtraction_sg(N, moves);
*/
#include <bits/stdc++.h>
using namespace std;

int mex(const vector<int> &a)
{
	vector<char> vis(a.size() + 1);
	for(int x : a)
		if(0 <= x && x < (int)vis.size()) vis[x] = 1;
	for(int i = 0; i < (int)vis.size(); i ++)
		if(!vis[i]) return i;
	return (int)vis.size();
}

// next[x]：状态 x 一步能到达的所有状态；要求状态图无环。
vector<int> calc_sg(const vector<vector<int>> &next)
{
	int n = next.size();
	vector<int> sg(n, -1), in_stk(n);

	auto dfs = [&](this auto &&self, int x) -> int
	{
		if(sg[x] != -1) return sg[x];
		assert(!in_stk[x]);
		in_stk[x] = 1;

		vector<int> value;
		value.reserve(next[x].size());
		for(int y : next[x]) value.push_back(self(y));

		in_stk[x] = 0;
		return sg[x] = mex(value);
	};

	for(int i = 0; i < n; i ++) dfs(i);
	return sg;
}

// 一堆有 0..N 个物品，每次可以减去 moves 中的一个数。
vector<int> subtraction_sg(int N, const vector<int> &moves)
{
	vector<int> sg(N + 1);
	for(int x = 1; x <= N; x ++)
	{
		vector<int> value;
		for(int d : moves)
			if(d <= x) value.push_back(sg[x - d]);
		sg[x] = mex(value);
	}
	return sg;
}
```

---

## FFT / NTT（998244353 卷积） — `FFT_NTT.cpp`

```cpp
/*
用途：模 998244353 的整数卷积
什么时候用：c[k] = sum(a[i] * b[k-i])，长度约 1e5，O(n^2) 过不了
复杂度：O((n+m) log(n+m))
接口：auto c = convolution(a, b);
*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int MOD = 998244353;
constexpr int G = 3;

int qpow(int a, int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = 1LL * res * a % MOD;
		a = 1LL * a * a % MOD;
		b >>= 1;
	}
	return res;
}

void ntt(vector<int> &a, bool invert)
{
	int n = a.size();
	for(int i = 1, j = 0; i < n; i ++)
	{
		int bit = n >> 1;
		for(; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if(i < j) swap(a[i], a[j]);
	}

	for(int len = 2; len <= n; len <<= 1)
	{
		int wlen = qpow(G, (MOD - 1) / len);
		if(invert) wlen = qpow(wlen, MOD - 2);

		for(int i = 0; i < n; i += len)
		{
			int w = 1;
			for(int j = 0; j < len / 2; j ++)
			{
				int u = a[i + j];
				int v = 1LL * a[i + j + len / 2] * w % MOD;
				a[i + j] = u + v;
				if(a[i + j] >= MOD) a[i + j] -= MOD;
				a[i + j + len / 2] = u - v;
				if(a[i + j + len / 2] < 0) a[i + j + len / 2] += MOD;
				w = 1LL * w * wlen % MOD;
			}
		}
	}

	if(invert)
	{
		int inv_n = qpow(n, MOD - 2);
		for(int &x : a) x = 1LL * x * inv_n % MOD;
	}
}

vector<i64> convolution(const vector<i64> &a, const vector<i64> &b)
{
	if(a.empty() || b.empty()) return {};
	int need = a.size() + b.size() - 1;
	int n = 1;
	while(n < need) n <<= 1;
	assert(n <= (1 << 23));

	vector<int> fa(n), fb(n);
	for(int i = 0; i < (int)a.size(); i ++)
		fa[i] = (a[i] % MOD + MOD) % MOD;
	for(int i = 0; i < (int)b.size(); i ++)
		fb[i] = (b[i] % MOD + MOD) % MOD;

	ntt(fa, false);
	ntt(fb, false);
	for(int i = 0; i < n; i ++) fa[i] = 1LL * fa[i] * fb[i] % MOD;
	ntt(fa, true);

	vector<i64> c(need);
	for(int i = 0; i < need; i ++) c[i] = fa[i];
	return c;
}
```

---

## 任意模数卷积 — `ArbitraryModConvolution.cpp`

```cpp
/*
用途：模数不是 NTT 友好质数时做卷积（三模 NTT + CRT）
什么时候用：例如结果要求模 1e9+7，且出现 c[k] = sum(a[i] * b[k-i])
复杂度：O((n+m) log(n+m))，常数约为普通 NTT 的 3 倍
接口：auto c = convolution_mod(a, b, mod);
*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;

template<int P>
int power_mod(int a, int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = 1LL * res * a % P;
		a = 1LL * a * a % P;
		b >>= 1;
	}
	return res;
}

template<int P, int G>
void ntt(vector<int> &a, bool invert)
{
	int n = a.size();
	for(int i = 1, j = 0; i < n; i ++)
	{
		int bit = n >> 1;
		for(; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if(i < j) swap(a[i], a[j]);
	}

	for(int len = 2; len <= n; len <<= 1)
	{
		int wlen = power_mod<P>(G, (P - 1) / len);
		if(invert) wlen = power_mod<P>(wlen, P - 2);
		for(int i = 0; i < n; i += len)
		{
			int w = 1;
			for(int j = 0; j < len / 2; j ++)
			{
				int u = a[i + j];
				int v = 1LL * a[i + j + len / 2] * w % P;
				a[i + j] = u + v;
				if(a[i + j] >= P) a[i + j] -= P;
				a[i + j + len / 2] = u - v;
				if(a[i + j + len / 2] < 0) a[i + j + len / 2] += P;
				w = 1LL * w * wlen % P;
			}
		}
	}

	if(invert)
	{
		int inv_n = power_mod<P>(n, P - 2);
		for(int &x : a) x = 1LL * x * inv_n % P;
	}
}

template<int P, int G>
vector<int> convolution_prime(const vector<i64> &a, const vector<i64> &b, int n, int need)
{
	vector<int> fa(n), fb(n);
	for(int i = 0; i < (int)a.size(); i ++) fa[i] = a[i] % P;
	for(int i = 0; i < (int)b.size(); i ++) fb[i] = b[i] % P;
	ntt<P, G>(fa, false);
	ntt<P, G>(fb, false);
	for(int i = 0; i < n; i ++) fa[i] = 1LL * fa[i] * fb[i] % P;
	ntt<P, G>(fa, true);
	fa.resize(need);
	return fa;
}

vector<i64> convolution_mod(const vector<i64> &a, const vector<i64> &b, int mod)
{
	if(a.empty() || b.empty()) return {};
	assert(mod >= 1);
	int need = a.size() + b.size() - 1;
	if(mod == 1) return vector<i64>(need);

	constexpr int P1 = 998244353, G1 = 3;
	constexpr int P2 = 1004535809, G2 = 3;
	constexpr int P3 = 469762049, G3 = 3;

	int n = 1;
	while(n < need) n <<= 1;
	assert(n <= (1 << 21));

	vector<i64> x(a.size()), y(b.size());
	for(int i = 0; i < (int)a.size(); i ++) x[i] = (a[i] % mod + mod) % mod;
	for(int i = 0; i < (int)b.size(); i ++) y[i] = (b[i] % mod + mod) % mod;

	const i128 all_mod = (i128)P1 * P2 * P3;
	const i128 max_coef = (i128)min(a.size(), b.size()) * (mod - 1LL) * (mod - 1LL);
	assert(max_coef < all_mod);

	auto r1 = convolution_prime<P1, G1>(x, y, n, need);
	auto r2 = convolution_prime<P2, G2>(x, y, n, need);
	auto r3 = convolution_prime<P3, G3>(x, y, n, need);

	const i64 inv_p1_mod_p2 = power_mod<P2>(P1 % P2, P2 - 2);
	const i64 p12_mod_p3 = (i128)P1 * P2 % P3;
	const i64 inv_p12_mod_p3 = power_mod<P3>(p12_mod_p3, P3 - 2);

	vector<i64> c(need);
	for(int i = 0; i < need; i ++)
	{
		i128 value = r1[i];
		i64 t = (r2[i] - (i64)(value % P2) + P2) % P2;
		t = t * inv_p1_mod_p2 % P2;
		value += (i128)P1 * t;

		i64 t2 = (r3[i] - (i64)(value % P3) + P3) % P3;
		t2 = t2 * inv_p12_mod_p3 % P3;
		value += (i128)P1 * P2 * t2;
		c[i] = value % mod;
	}
	return c;
}
```

---

## Miller-Rabin — `MillerRabin.cpp`

```cpp
/*
用途：确定性判断一个 64 位无符号整数是否为质数
什么时候用：n 可到 1e18 或 u64 范围，sqrt(n) 试除过不了
复杂度：O(log n) 次模运算乘上常数个 bases
接口：bool isPrime(u64 n);
*/
#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;
using u128 = __uint128_t;

u64 mul_mod(u64 a, u64 b, u64 mod)
{
	return (u128)a * b % mod;
}

u64 pow_mod(u64 a, u64 b, u64 mod)
{
	u64 res = 1;
	while(b)
	{
		if(b & 1) res = mul_mod(res, a, mod);
		a = mul_mod(a, a, mod);
		b >>= 1;
	}
	return res;
}

bool isPrime(u64 n)
{
	if(n < 2) return false;
	for(u64 p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL})
	{
		if(n == p) return true;
		if(n % p == 0) return false;
	}

	u64 d = n - 1, s = 0;
	while((d & 1) == 0) d >>= 1, s ++;

	for(u64 a : {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL})
	{
		if(a % n == 0) continue;
		u64 x = pow_mod(a % n, d, n);
		if(x == 1 || x == n - 1) continue;

		bool composite = true;
		for(u64 r = 1; r < s; r ++)
		{
			x = mul_mod(x, x, n);
			if(x == n - 1)
			{
				composite = false;
				break;
			}
		}
		if(composite) return false;
	}
	return true;
}
```

---

## Pollard Rho — `PollardRho.cpp`

```cpp
/*
用途：64 位无符号整数质因数分解
什么时候用：n 可到 1e18，要求完整质因数分解，sqrt(n) 试除过不了
复杂度：随机化算法，64 位整数实际通常很快
接口：auto fac = factor(n); // 包含重复质因子，已排序
*/
#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;
using u128 = __uint128_t;

namespace PollardRho
{
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

	u64 mul_mod(u64 a, u64 b, u64 mod)
	{
		return (u128)a * b % mod;
	}

	u64 pow_mod(u64 a, u64 b, u64 mod)
	{
		u64 res = 1;
		while(b)
		{
			if(b & 1) res = mul_mod(res, a, mod);
			a = mul_mod(a, a, mod);
			b >>= 1;
		}
		return res;
	}

	bool isPrime(u64 n)
	{
		if(n < 2) return false;
		for(u64 p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL})
		{
			if(n == p) return true;
			if(n % p == 0) return false;
		}

		u64 d = n - 1, s = 0;
		while((d & 1) == 0) d >>= 1, s ++;
		for(u64 a : {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL})
		{
			if(a % n == 0) continue;
			u64 x = pow_mod(a % n, d, n);
			if(x == 1 || x == n - 1) continue;

			bool composite = true;
			for(u64 r = 1; r < s; r ++)
			{
				x = mul_mod(x, x, n);
				if(x == n - 1)
				{
					composite = false;
					break;
				}
			}
			if(composite) return false;
		}
		return true;
	}

	u64 find_factor(u64 n)
	{
		if(n % 2 == 0) return 2;
		if(n % 3 == 0) return 3;

		while(true)
		{
			u64 c = uniform_int_distribution<u64>(1, n - 1)(rng);
			u64 x = uniform_int_distribution<u64>(0, n - 1)(rng);
			u64 y = x, d = 1;

			auto f = [&](u64 v)
			{
				return (u64)(((u128)mul_mod(v, v, n) + c) % n);
			};

			while(d == 1)
			{
				x = f(x);
				y = f(f(y));
				u64 diff = x > y ? x - y : y - x;
				d = gcd(diff, n);
			}
			if(d != n) return d;
		}
	}

	void split(u64 n, vector<u64> &fac)
	{
		if(n == 1) return;
		if(isPrime(n))
		{
			fac.push_back(n);
			return;
		}
		u64 d = find_factor(n);
		split(d, fac);
		split(n / d, fac);
	}
}

vector<u64> factor(u64 n)
{
	vector<u64> fac;
	PollardRho::split(n, fac);
	sort(fac.begin(), fac.end());
	return fac;
}
```

---

## Dinic 最大流 — `Dinic.cpp`

```cpp
/*
用途：有向图最大流
什么时候用：只问最多能安排/匹配/通过多少，且每条关系有容量上限
复杂度：一般图常用 O(V^2 E) 上界；二分图单位容量通常很快
接口：Dinic mf(n); mf.addEdge(u,v,cap); auto flow = mf.flow(S,T);
*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Dinic
{
	struct Edge
	{
		int to, rev;
		i64 cap;
	};

	int n;
	vector<vector<Edge>> g;
	vector<int> level, cur;

	Dinic(int n_) : n(n_), g(n_), level(n_), cur(n_) {}

	void addEdge(int u, int v, i64 cap)
	{
		assert(cap >= 0);
		Edge a{v, (int)g[v].size(), cap};
		Edge b{u, (int)g[u].size(), 0};
		g[u].push_back(a);
		g[v].push_back(b);
	}

	bool bfs(int s, int t)
	{
		fill(level.begin(), level.end(), -1);
		queue<int> q;
		level[s] = 0;
		q.push(s);
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			for(auto &e : g[u])
				if(e.cap > 0 && level[e.to] == -1)
				{
					level[e.to] = level[u] + 1;
					q.push(e.to);
				}
		}
		return level[t] != -1;
	}

	i64 dfs(int u, int t, i64 f)
	{
		if(u == t) return f;
		for(int &i = cur[u]; i < (int)g[u].size(); i ++)
		{
			Edge &e = g[u][i];
			if(e.cap == 0 || level[e.to] != level[u] + 1) continue;
			i64 got = dfs(e.to, t, min(f, e.cap));
			if(got == 0) continue;
			e.cap -= got;
			g[e.to][e.rev].cap += got;
			return got;
		}
		return 0;
	}

	i64 flow(int s, int t, i64 limit = numeric_limits<i64>::max())
	{
		if(s == t) return 0;
		i64 ans = 0;
		while(ans < limit && bfs(s, t))
		{
			fill(cur.begin(), cur.end(), 0);
			while(ans < limit)
			{
				i64 got = dfs(s, t, limit - ans);
				if(got == 0) break;
				ans += got;
			}
		}
		return ans;
	}
};
```

---

## 最小费用最大流 — `MinCostMaxFlow.cpp`

```cpp
/*
用途：在容量限制下求最大流，并让该流量的总费用最小
什么时候用：分配/路径除了次数上限，每种选择还有 cost 或 value
复杂度：一次初始 SPFA，之后每次增广 O(E log V)
接口：mf.addEdge(u,v,cap,cost); auto [flow,cost] = mf.flow(S,T,need);
*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct MinCostMaxFlow
{
	struct Edge
	{
		int to, rev;
		i64 cap, cost;
	};

	static constexpr i64 INF = numeric_limits<i64>::max() / 4;
	int n;
	vector<vector<Edge>> g;

	MinCostMaxFlow(int n_) : n(n_), g(n_) {}

	void addEdge(int u, int v, i64 cap, i64 cost)
	{
		assert(cap >= 0);
		Edge a{v, (int)g[v].size(), cap, cost};
		Edge b{u, (int)g[u].size(), 0, -cost};
		g[u].push_back(a);
		g[v].push_back(b);
	}

	pair<i64, i64> flow(int s, int t, i64 limit = INF)
	{
		if(s == t) return {0, 0};
		vector<i64> pot(n), dist(n);
		vector<int> pv(n), pe(n), inq(n);

		// 只执行一次，允许原图中存在负费用边。
		fill(dist.begin(), dist.end(), INF);
		queue<int> q;
		dist[s] = 0;
		q.push(s);
		inq[s] = 1;
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			inq[u] = 0;
			for(auto &e : g[u])
				if(e.cap > 0 && dist[e.to] > dist[u] + e.cost)
				{
					dist[e.to] = dist[u] + e.cost;
					if(!inq[e.to])
					{
						inq[e.to] = 1;
						q.push(e.to);
					}
				}
		}
		for(int i = 0; i < n; i ++)
			if(dist[i] < INF) pot[i] = dist[i];

		i64 total_flow = 0, total_cost = 0;
		while(total_flow < limit)
		{
			fill(dist.begin(), dist.end(), INF);
			priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> pq;
			dist[s] = 0;
			pq.emplace(0, s);

			while(!pq.empty())
			{
				auto [du, u] = pq.top(); pq.pop();
				if(du != dist[u]) continue;
				for(int i = 0; i < (int)g[u].size(); i ++)
				{
					auto &e = g[u][i];
					if(e.cap == 0) continue;
					i64 nd = du + e.cost + pot[u] - pot[e.to];
					if(nd < dist[e.to])
					{
						dist[e.to] = nd;
						pv[e.to] = u;
						pe[e.to] = i;
						pq.emplace(nd, e.to);
					}
				}
			}

			if(dist[t] == INF) break;
			for(int i = 0; i < n; i ++)
				if(dist[i] < INF) pot[i] += dist[i];

			i64 add = limit - total_flow;
			for(int v = t; v != s; v = pv[v])
				add = min(add, g[pv[v]][pe[v]].cap);

			for(int v = t; v != s; v = pv[v])
			{
				Edge &e = g[pv[v]][pe[v]];
				total_cost += add * e.cost;
				e.cap -= add;
				g[v][e.rev].cap += add;
			}
			total_flow += add;
		}
		return {total_flow, total_cost};
	}
};
```

---

## 一般图最大匹配 Blossom — `Blossom.cpp`

```cpp
/*
用途：无权一般无向图最大匹配
什么时候用：图没有自然左右部、可能有奇环，要求最多选多少条互不共享端点的边
复杂度：O(n^3)
接口：Blossom bm(n); bm.addEdge(u,v); int ans=bm.solve(); bm.match[u]
*/
#include <bits/stdc++.h>
using namespace std;

struct Blossom
{
	int n;
	vector<vector<int>> g;
	vector<int> match, p, base, q;
	vector<char> used, blossom;

	Blossom(int n_) : n(n_), g(n_), match(n_, -1), p(n_), base(n_), used(n_), blossom(n_) {}

	void addEdge(int u, int v)
	{
		if(u == v) return;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int lca(int a, int b)
	{
		vector<char> vis(n);
		while(true)
		{
			a = base[a];
			vis[a] = 1;
			if(match[a] == -1) break;
			a = p[match[a]];
		}
		while(true)
		{
			b = base[b];
			if(vis[b]) return b;
			b = p[match[b]];
		}
	}

	void markPath(int v, int b, int child)
	{
		while(base[v] != b)
		{
			blossom[base[v]] = blossom[base[match[v]]] = 1;
			p[v] = child;
			child = match[v];
			v = p[match[v]];
		}
	}

	int findPath(int root)
	{
		fill(used.begin(), used.end(), 0);
		fill(p.begin(), p.end(), -1);
		iota(base.begin(), base.end(), 0);
		q.clear();
		q.push_back(root);
		used[root] = 1;

		for(int head = 0; head < (int)q.size(); head ++)
		{
			int v = q[head];
			for(int u : g[v])
			{
				if(base[v] == base[u] || match[v] == u) continue;
				if(u == root || (match[u] != -1 && p[match[u]] != -1))
				{
					int cur = lca(v, u);
					fill(blossom.begin(), blossom.end(), 0);
					markPath(v, cur, u);
					markPath(u, cur, v);
					for(int i = 0; i < n; i ++)
						if(blossom[base[i]])
						{
							base[i] = cur;
							if(!used[i])
							{
								used[i] = 1;
								q.push_back(i);
							}
						}
				}
				else if(p[u] == -1)
				{
					p[u] = v;
					if(match[u] == -1) return u;
					u = match[u];
					used[u] = 1;
					q.push_back(u);
				}
			}
		}
		return -1;
	}

	int solve()
	{
		fill(match.begin(), match.end(), -1);
		int ans = 0;
		for(int i = 0; i < n; i ++)
			if(match[i] == -1)
			{
				int v = findPath(i);
				if(v == -1) continue;
				ans ++;
				while(v != -1)
				{
					int pv = p[v];
					int nv = pv == -1 ? -1 : match[pv];
					if(pv != -1)
					{
						match[v] = pv;
						match[pv] = v;
					}
					v = nv;
				}
			}
		return ans;
	}
};
```

---

## floor_sum — `FloorSum.cpp`

```cpp
/*
用途：计算 sum_{i=0}^{n-1} floor((a*i+b)/m)，支持 a、b 为负
什么时候用：格点计数、线性不等式整数解、巨大线性 floor 求和
复杂度：O(log(max(a,m)))
接口：i128 ans = floor_sum(n,m,a,b); print_i128(ans);
*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;

i128 floor_sum(i64 n, i64 m, i64 a, i64 b)
{
	assert(n >= 0 && m > 0);
	i128 aa = (i128)a % m;
	i128 bb = (i128)b % m;
	if(aa < 0) aa += m;
	if(bb < 0) bb += m;

	i128 ans = ((i128)a - aa) / m * n * (n - 1) / 2;
	ans += ((i128)b - bb) / m * n;
	a = aa;
	b = bb;

	while(true)
	{
		if(a >= m)
		{
			ans += (i128)(n - 1) * n * (a / m) / 2;
			a %= m;
		}
		if(b >= m)
		{
			ans += (i128)n * (b / m);
			b %= m;
		}

		i128 y = (i128)a * n + b;
		if(y < m) break;
		n = y / m;
		b = y % m;
		swap(a, m);
	}
	return ans;
}

void print_i128(i128 x)
{
	if(x < 0) cout <<'-', x = -x;
	if(x >= 10) print_i128(x / 10);
	cout <<char('0' + x % 10);
}
```

---

## Hungarian / Assignment — `Hungarian.cpp`

```cpp
/*
用途：矩形权值矩阵的最小费用一一指派
什么时候用：n 个左侧对象都要匹配不同右侧对象，每对都有 cost，且 n <= m
复杂度：O(n^2 m)
接口：auto [cost, match] = hungarian(a); // match[i] 是左点 i 的右点
*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

pair<i64, vector<int>> hungarian(const vector<vector<i64>> &a)
{
	int n = a.size();
	if(n == 0) return {0, {}};
	int m = a[0].size();
	assert(n <= m);
	for(auto &row : a) assert((int)row.size() == m);

	const i64 INF = numeric_limits<i64>::max() / 4;
	vector<i64> u(n + 1), v(m + 1);
	vector<int> p(m + 1), way(m + 1);

	for(int i = 1; i <= n; i ++)
	{
		p[0] = i;
		int j0 = 0;
		vector<i64> minv(m + 1, INF);
		vector<char> used(m + 1);
		do
		{
			used[j0] = 1;
			int i0 = p[j0], j1 = 0;
			i64 delta = INF;
			for(int j = 1; j <= m; j ++)
				if(!used[j])
				{
					i64 cur = a[i0 - 1][j - 1] - u[i0] - v[j];
					if(cur < minv[j]) minv[j] = cur, way[j] = j0;
					if(minv[j] < delta) delta = minv[j], j1 = j;
				}

			for(int j = 0; j <= m; j ++)
				if(used[j]) u[p[j]] += delta, v[j] -= delta;
				else minv[j] -= delta;
			j0 = j1;
		}while(p[j0] != 0);

		do
		{
			int j1 = way[j0];
			p[j0] = p[j1];
			j0 = j1;
		}while(j0 != 0);
	}

	vector<int> match(n, -1);
	for(int j = 1; j <= m; j ++)
		if(p[j] != 0) match[p[j] - 1] = j - 1;

	i64 cost = 0;
	for(int i = 0; i < n; i ++) cost += a[i][match[i]];
	return {cost, match};
}
```

---

## 后缀数组 — `SuffixArray.cpp`

```cpp
/*
用途：后缀排序、相邻后缀 LCP、任意两个后缀的最长公共前缀
什么时候用：所有后缀字典序、最长重复子串、本质不同子串、子串比较
复杂度：构造 O(n log n)，get_lcp O(1)
接口：SuffixArray suf(s); suf.sa / suf.rank / suf.lcp / suf.get_lcp(i,j)
*/
#include <bits/stdc++.h>
using namespace std;

struct SuffixArray
{
	string s;
	int n;
	vector<int> sa, rank, lcp, lg;
	vector<vector<int>> st;

	SuffixArray(const string &s_) : s(s_), n(s_.size())
	{
		build_sa();
		build_lcp();
		build_rmq();
	}

	void build_sa()
	{
		if(n == 0) return;
		string t = s;
		t.push_back(char(0));
		int N = t.size();
		vector<int> p(N), c(N), cnt(max(N, 256));

		for(unsigned char ch : t) cnt[ch] ++;
		for(int i = 1; i < 256; i ++) cnt[i] += cnt[i - 1];
		for(int i = 0; i < N; i ++) p[--cnt[(unsigned char)t[i]]] = i;
		c[p[0]] = 0;
		for(int i = 1; i < N; i ++)
			c[p[i]] = c[p[i - 1]] + (t[p[i]] != t[p[i - 1]]);

		vector<int> pn(N), cn(N);
		for(int len = 1; len < N; len <<= 1)
		{
			for(int i = 0; i < N; i ++)
			{
				pn[i] = p[i] - len;
				if(pn[i] < 0) pn[i] += N;
			}

			int classes = c[p.back()] + 1;
			fill(cnt.begin(), cnt.begin() + classes, 0);
			for(int x : pn) cnt[c[x]] ++;
			for(int i = 1; i < classes; i ++) cnt[i] += cnt[i - 1];
			for(int i = N - 1; i >= 0; i --) p[--cnt[c[pn[i]]]] = pn[i];

			cn[p[0]] = 0;
			for(int i = 1; i < N; i ++)
			{
				pair<int, int> now{c[p[i]], c[(p[i] + len) % N]};
				pair<int, int> pre{c[p[i - 1]], c[(p[i - 1] + len) % N]};
				cn[p[i]] = cn[p[i - 1]] + (now != pre);
			}
			c.swap(cn);
		}

		p.erase(p.begin());
		sa = move(p);
		rank.resize(n);
		for(int i = 0; i < n; i ++) rank[sa[i]] = i;
	}

	void build_lcp()
	{
		lcp.assign(n, 0);
		int h = 0;
		for(int i = 0; i < n; i ++)
		{
			int k = rank[i];
			if(k == 0) continue;
			int j = sa[k - 1];
			while(i + h < n && j + h < n && s[i + h] == s[j + h]) h ++;
			lcp[k] = h;
			if(h) h --;
		}
	}

	void build_rmq()
	{
		if(n == 0) return;
		lg.assign(n + 1, 0);
		for(int i = 2; i <= n; i ++) lg[i] = lg[i / 2] + 1;
		st.assign(lg[n] + 1, vector<int>(n));
		st[0] = lcp;
		for(int k = 1; k < (int)st.size(); k ++)
			for(int i = 0; i + (1 << k) <= n; i ++)
				st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
	}

	int get_lcp(int i, int j) const
	{
		assert(0 <= i && i < n && 0 <= j && j < n);
		if(i == j) return n - i;
		int l = rank[i], r = rank[j];
		if(l > r) swap(l, r);
		l ++;
		int k = lg[r - l + 1];
		return min(st[k][l], st[k][r - (1 << k) + 1]);
	}
};
```

---
