#include <iostream>

const int N = 1e6 + 5;

int d[N];
int n, maxd;

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    d[u]++;
    d[v]++;
  }
  for (int i = 1; i <= n; ++i)
    maxd = std::max(maxd, d[i]);
  if (maxd > 3) {
    puts("0");
    return 0;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans += d[i] <= 2;
  printf("%d", ans);
  return 0;
}