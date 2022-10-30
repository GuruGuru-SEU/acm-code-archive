#include <iostream>
#include <queue>
#include <vector>
const int MAXN = 2E5 + 3;
int vis[MAXN], dfn1[MAXN], dfn2[MAXN];
std::vector<int> G[MAXN];
std::vector<int> inv_G[MAXN];
std::queue<int> q;
int ind[MAXN], inv_ind[MAXN];

void topo() {
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0)
    }
}
int main() {
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) vis[i] = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            vis[x] = 1;
            ind[i] = inv_ind[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            ind[v]++;
            inv_G[v].push_back(u);
            inv_ind[u]++;
        }
    }

    return 0;
}