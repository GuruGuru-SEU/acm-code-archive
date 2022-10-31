#include <cstdio>
#include <cctype>
#include <iostream>

using namespace std;

const int N = 2e4 + 5;
const int INF = 1e8;

const long long key = 998244353ll;

struct Edge {
	int v, nxt;
} edge[N << 2];
int cnt, head[N];

void addEdge(int u, int v) {
	edge[++cnt].v = v;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}

int n, root, root_val;
int siz[N], dep[N];
bool vis[N];
long long a[N], b[N], s[N], ans;

long long pow_mod(long long x, long long n, long long p) {
	if (n == 0) return 1ll;
	if (n == 1) return x;
	long long res = pow_mod(x, n / 2, key);
	res = (res * res) % key;
	if (n & 1) res = (res * x) %key;
	return res;
}

// calc size
void dfs1(int u, int fa) {
	siz[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if (v == fa) continue;
		if (vis[v]) continue;
		dfs1(v, u);
		siz[u] += siz[v];
	}
}

// calc root
void dfs2(int u, int fa, int tot_size) {
	int val = 0;
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if (v == fa) continue;
		if (vis[v]) continue;
		dfs2(v, u, tot_size);
		val = max(val, siz[v]);
	}
	val = max(val, tot_size - siz[u]);
	if (val < root_val) {
		root = u;
		root_val = val;
	}
}

void dfs3(int u, int fa) {
	dep[u] = dep[fa] + 1;
	for (int i = 1; i <= n; ++i) {
		if (dep[u] + i > n) continue;
		a[dep[u] + i] += b[i];
	}
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if (v == fa) continue;
		if (vis[v]) continue;
		dfs3(v, u);
	}
}

void dfs4(int u, int fa) {
	dep[u] = dep[fa] + 1;
	b[dep[u] + 1]++;
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if (v == fa) continue;
		if (vis[v]) continue;
		dfs4(v, u);
	}
}

void calc_ans(int u) {
	a[1]++;
	for (int i = 1; i <= n; ++i)
		b[i] = 0;
	b[1] = 1;
	dep[u] = 0;
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if (vis[v]) continue;
		dfs3(v, u);
	}
}

void dfs(int u) {
	calc_ans(u);
	vis[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if (vis[v]) continue;
		dfs1(v, 0);
		root_val = INF;
		dfs2(v, 0, siz[v]);
		dfs(v);
	}
}




int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	dfs(1);
	
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << ' ';
	}
	
	
	ans = 0;
	ans = (a[1] * a[1]) % key; s[1] = a[1];
	for (int i = 2; i <= n; i++) {
		s[i] += 2 * a[i] + s[i - 1];
		ans = (ans + 2ll * (s[i] * a[i] % key) * i) % key;
	}
	printf("%lld\n", ans);
	printf("%lld\n", ans * pow_mod(pow_mod(n, 4ll, key) , key - 2ll, key) % key);
	return 0;
}

