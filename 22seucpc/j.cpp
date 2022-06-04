#include <cstdio>
#include <cctype>
#include <iostream>
#include <queue>

using namespace std;

const int M = 1e4 + 5;
const int INF = 1e8;

struct Edge {
	int v, w, nxt;
} edge[5000005];
int cnt, head[50005];

int n, m, k, q;
int u[M], v[M], w[M];
int mg[105];
int c[101];
int dis[50005];
bool vis[50005];

void addEdge(int u, int v, int w) {
//	cout << "Edge: " << u << ' ' << v << ' ' << w << endl;
	edge[++cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}

void dijkstra() {
	for (int i = 1; i <= n; ++i) {
		dis[i] = INF;
	}
	dis[1] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, 1));
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v, w = edge[i].w;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				q.push(make_pair(-dis[v], v));
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; ++i) 
		scanf("%d", &mg[i]);
	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
		scanf("%d", &c[i]);
	for (int i = 0; i <= q; ++i) {
		int dlt = i * n;
		for (int j = 1; j <= m; ++j) {
			addEdge(u[j] + dlt, v[j] + dlt, w[j]);
			addEdge(v[j] + dlt, u[j] + dlt, w[j]);
		}
	}
	for (int i = 0; i < q; ++i) {
		int dlt = i * n;
		for (int u = 1; u <= k; ++u) {
			for (int v = 1; v <= k; ++v) {
				addEdge(mg[u] + dlt, mg[v] + dlt + n, c[i]);
			}
		}
	}
	n *= (q + 1);
	dijkstra();
	int ans = INF;
	n /= (q + 1);
	for (int i = 0; i <= q; ++i) {
		int dlt = i * n;
		ans = min(ans, dis[n + dlt]);
	}
	printf("%d", ans);
	return 0;
}

