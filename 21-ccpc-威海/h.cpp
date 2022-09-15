#include <cstring>
#include <iostream>
#include <vector>

const int N = 200 + 5;

int n, w[N], v[N], sel[N], p[N];
int inc[N][N];
std::vector<int> G[N];

void dfs1(int u, int fa, int gl_u, int gl_dis) {
  if (!sel[u]) {
    inc[gl_u][gl_dis] -= w[u];
  }
  for (auto v : G[u]) {
    if (v == fa)
      continue;
    dfs1(v, u, gl_u, gl_dis);
  }
}

void dfs2(int u, int fa, int dep, int tgt_dep) {
  if (dep == tgt_dep) {
    sel[u] = 1;
  }
  for (auto v : G[u]) {
    if (v == fa)
      continue;
    dfs2(v, u, dep + 1, tgt_dep);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    p[i] = -1;
  for (int i = 1; i <= n; ++i)
    scanf("%d", &w[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &v[i]);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int ans = 0;
  while (true) {
    memset(inc, 0, sizeof(inc));
    int max_inc = 0;
    std::pair<int, int> max_pair = {0, 0};
    for (int u = 1; u <= n; ++u) {
      if (p[u] == n - 1)
        continue;
      dfs1(u, 0, u, 0);
      int cur_inc = 0;
      if (p[u] == -1)
        cur_inc = v[0] + inc[u][0];
      else
        cur_inc = v[p[u] + 1] - v[p[u]] + inc[u][p[u] + 1];
      std::pair<int, int> cur_pair = {u, p[u] + 1};
      if (cur_inc > max_inc)
        max_pair = cur_pair;
    }
    if (max_inc == 0)
      break;
    ans += max_inc;
    dfs2(max_pair.first, 0, 0, max_pair.second);
  }
  printf("%d", ans);
  return 0;
}