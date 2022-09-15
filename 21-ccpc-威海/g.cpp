#include <iostream>
#include <vector>

const int N = 1e5 + 5;
const long long MOD = 998244353;

int n, m;
long long inv[N], fac[N], facinv[N];
int a[N], sum_a[N], max_a;
std::vector<std::pair<int, int>> as; // a, times

long long qpow(long long x, int n) {
  long long res = 1;
  while (n) {
    if (n & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

long long C(int n, int k) {
  return fac[n] * facinv[k] % MOD * facinv[n - k] % MOD;
}

long long work(int k) {
  long long res = 1;
  for (auto _ : as) {
    int a = _.first, times = _.second;
    long long cur = C(k, a);
    res = res * qpow(cur, times) % MOD;
  }
  return res;
}

int main() {
  fac[0] = facinv[0] = 1;
  inv[1] = fac[1] = facinv[1] = 1;
  for (int i = 2; i <= 100000; ++i) {
    inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    fac[i] = fac[i - 1] * i % MOD;
    facinv[i] = facinv[i - 1] * inv[i] % MOD;
  }
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum_a[a[i]]++;
    max_a = std::max(max_a, a[i]);
  }
  for (int i = 1; i <= 100000; ++i) {
    if (sum_a[i]) {
      as.push_back({i, sum_a[i]});
    }
  }
  for (int i = 1; i < max_a; ++i) {
    puts("0");
  }
  for (int i = max_a; i <= m; ++i) {
    printf("%lld\n", work(i));
  }
  return 0;
}