#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1e17;

int p, n, q;
ll a[1000005];
ll ans[1000005], f[1000005];
int pos[1000005], l, r;
ll val[1000005];

int main() {
  scanf("%d%d%d", &n, &q, &p);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int x = 1; x <= n; ++x) {
    ans[x] = -INF;
    for (int i = x; i <= n; i += x) {
      f[i] = -INF;
    }
    f[0] = 0;
    l = r = 0;
    pos[r] = 0, val[r++] = 0;
    for (int i = x; i <= n; i += x) {
      while (i - pos[l] > p) l++;
      if (l < r) f[i] = val[l] + a[i];
      while (l < r && val[r - 1] <= f[i]) r--;
      pos[r] = i, val[r++] = f[i];
      if (n + 1 - i <= p) ans[x] = max(ans[x], f[i]);
    }
  }
  while (q--) {
    int x;
    scanf("%d", &x);
    if (x > p) puts("Noob");
    else printf("%lld\n", ans[x]);
  }

  return 0;
}