#include <cstdio>
#include <cctype>
#include <unordered_map>

template<typename tn> void fead(tn &n) {
  tn f = 1, k = 0; char ch = getchar(); while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
  while (isdigit(ch)) {k = k * 10 + ch - '0', ch = getchar();}
  n = k * f;
}

int T, f[100010];

unsigned long long n, x;
long long a, b, c, a0, b0, c0, ans, d;

int main() {
  f[1] = 0; f[2] = 1;
  for (int i = 3; i <= 210; i++) {
    if (i & 1) f[i] = 2 * f[i / 2];
    else f[i] = 1 + f[i / 2] + f[i / 2 - 1];
  }
  fead(T);
  while (T--) {
    fead(n);
    x = n; a = 1ll; b = 0; c = 0; d = 0;
    while (x > 32) {
      if (x % 2) {
        a0 = 2 * a + b; b0 = b + 2 * c; c0 = 0; d += b;
      }
      else {
        a0 = a; b0 = a + 2 * b + c; c0 = c; d += a + c;
      }
      x /= 2; a = a0; b = b0; c = c0;
    }
    {
      ans = f[x] * a + f[x - 1] * b + f[x - 2] * c + d;
      if (ans >= 64) puts("0");
      else { 
        if (ans == 63) puts("9223372036854775808");
        else printf("%lld\n", 1ll << ans);
      }
    }
  }
  return 0;
}