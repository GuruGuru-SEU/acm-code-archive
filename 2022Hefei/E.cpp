#include <algorithm>
#include <iostream>
#include <queue>

const int N = 1e4 + 5;
const int MM = 1e6 + 5;
const long long INF = 1e16;

struct Edge {
    int v, nxt;
    long long w;
} edge[MM << 1];
int cnt, head[N];

void add_edge(int u, int v, long long w) {
    edge[++cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
}

int n, m, s;
long long C, M;
long long a[N], b[N], dis[N];
bool vis[N];

void dijkstra() {
    std::priority_queue<std::pair<long long, int>> q;
    for (int i = 1; i <= n; ++i)
        dis[i] = INF;
    dis[s] = 0;
    q.push(std::make_pair(0, s));
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = edge[i].nxt) {
            int v = edge[i].v;
            long long w = edge[i].w;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push(std::make_pair(-dis[v], v));
            }
        }
    }
}

long long dp[2][10005], cur;

int main() {
    bool yes = 0;
    scanf("%d%d%d%lld%lld", &n, &m, &s, &C, &M);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld", &a[i], &b[i]);
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        long long w;
        scanf("%d%d%lld", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    dijkstra();
    for (int i = 1; i <= n; ++i) {
        a[i] *= dis[i];
    }

    for (int j = 0; j <= C; j++)
        dp[0][j] = INF;
    dp[0][0] = 0;
    cur = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= C; j++) {
            if (dp[cur ^ 1][j] + a[i] <= M && j + b[i] >= C) {
                yes = 1;
            }
            if (j < b[i])
                dp[cur][j] = dp[cur ^ 1][j];
            else
                dp[cur][j] = std::min(dp[cur ^ 1][j], dp[cur ^ 1][j - b[i]] + a[i]);
        }
        cur ^= 1;
    }
    long long res = 0;
    for (int i = 0; i <= C; i++)
        if (dp[cur ^ 1][i] <= M) res = i;
    if (res >= C || yes)
        puts("Yes");
    else
        puts("No");
    return 0;
}