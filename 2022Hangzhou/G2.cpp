#include <algorithm>
#include <iostream>
#include <vector>

const int N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long SEED = 13337;
const unsigned long long SEED2 = 1333337;

bool vis[N], oncirc[N];
std::vector<int> G[N];
int x[N], cnt;
int siz[N];
long long f[N];
unsigned long long g[N];
int circ[N], circ_cnt;

bool dfs1(int u, int fa) {
    x[++cnt] = u;
    for (int v : G[u]) {
        if (v == fa) continue;
        if (vis[v]) {
            for (int i = cnt; x[i] != v; --i) {
                oncirc[x[i]] = true;
                circ[++circ_cnt] = x[i];
            }
            oncirc[v] = true;
            circ[++circ_cnt] = v;
            return true;
        }
        vis[v] = true;
        if (dfs1(v, u)) return true;
    }
    --cnt;
    return false;
}

void dfs2(int u, int fa) {
    siz[u] = 1;
    long long seed = 1;
    bool has_son = false;
    std::vector<std::pair<long long, int>> vec;
    for (int v : G[u]) {
        if (v == fa) continue;
        if (oncirc[v]) continue;
        has_son = true;
        dfs2(v, u);
        siz[u] += siz[v];
        vec.push_back({f[v], v});
        g[u] ^= (g[v] * SEED2 + siz[v]);
    }
    std::sort(vec.begin(), vec.end());
    for (auto i : vec) {
        int v = i.second;
        f[u] = (f[u] + f[v] * seed % MOD) % MOD;
        seed = seed * SEED % MOD;
    }
    f[u] = f[u] * 1ll * siz[u] % MOD;
    if (!has_son) f[u] = 1;
}

int t, n, m;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            G[i].clear(), oncirc[i] = false, vis[i] = false, siz[i] = 0, f[i] = 0, g[i] = 0;
        for (int i = 1; i <= m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v), G[v].push_back(u);
        }
        if (m < n) {
            puts("YES");
            continue;
        }
        if (m > n) {
            puts("NO");
            continue;
        }
        cnt = 0, circ_cnt = 0;
        vis[1] = true;
        dfs1(1, 0);
        bool no = false;
        for (int i = 1; i <= circ_cnt; ++i) {
            dfs2(circ[i], 0);
        }
        if (circ_cnt & 1) {
            for (int i = 2; i <= circ_cnt; ++i) {
                if (siz[circ[i]] != siz[circ[i - 1]]) no = true;
                if (f[circ[i]] != f[circ[i - 1]]) no = true;
                if (g[circ[i]] != g[circ[i - 1]]) no = true;
            }
        } else {
            for (int i = 3; i <= circ_cnt; ++i) {
                if (siz[circ[i]] != siz[circ[i - 2]]) no = true;
                if (f[circ[i]] != f[circ[i - 2]]) no = true;
                if (g[circ[i]] != g[circ[i - 2]]) no = true;
            }
        }
        if (no)
            puts("NO");
        else
            puts("YES");
    }

    return 0;
}

/*

233
12 12
1 2
1 3
2 3
1 4
4 5
4 6
3 7
7 8
7 9
2 10
10 11
10 12


*/