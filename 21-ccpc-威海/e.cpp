#include <algorithm>
#include <cmath>
#include <iostream>

const int N = 1e5 + 5;

int n, q, k;
double a[N], b[N], s[N], f[105], selections;

int main() {
  scanf("%d%d%d", &n, &k, &q);
  selections = 1.0 * n * (n - 1) / 2;
  for (int i = 1; i <= n; ++i)
    scanf("%lf", &a[i]), b[i] = a[i];
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i)
    s[i] = s[i - 1] + a[i];
  for (int i = 1; i <= n; ++i)
    f[0] += a[i] * 2;
  f[0] /= 1.0 * n;
  for (int j = 1; j <= k; ++j) {
    for (int i = n; i >= 2; --i) {
      int l = 1, r = i - 1, ans = i;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] + a[i] >= f[j - 1])
          ans = mid, r = mid - 1;
        else
          l = mid + 1;
      }
      f[j] += 1.0 * (ans - 1) * f[j - 1];
      f[j] += 1.0 * (i - ans) * a[i] + 1.0 * (s[i - 1] - s[ans - 1]);
    }
    f[j] /= selections;
  }
  printf("%.10lf\n", f[k]);
  while (q--) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    if (c == 0) {
      puts("accept");
      continue;
    }
    double acc_ans = b[x] + b[y];
    double res_ans = f[c - 1];
    if (fabs(acc_ans - res_ans) <= 1e-4) {
      puts("both");
      continue;
    }
    if (acc_ans > res_ans) {
      puts("accept");
    } else {
      puts("reselect");
    }
  }
  return 0;
}