#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1e8;

char s[300005];
int n;
int f[300005][3][2];
int mx1[300005], mx0[300005];

int max3(int a, int b, int c) {
  return max(a, max(b, c));
}

int main() {
  cin >> s + 3;
  s[1] = s[2] = 'C';
  n = strlen(s + 1);
  if (n < 3) return puts("0"), 0;
  n += 2;
  s[n] = s[n - 1] = 'A';

  for (int j = 0; j < 3; ++j)
    for (int k = 0; k < 2; ++k)
      f[1][j][k] = f[2][j][k] = -INF;
  f[2][2][0] = f[1][2][1] = 0;

  for (int i = 3; i <= n; ++i) {
    for (int j = 0; j < 3; ++j)
      for (int k = 0; k < 2; ++k) {
        if (s[i - 1] == 'B' && s[i] == 'C') {
          f[i][j][k] = max3(f[i - 2][0][k], f[i - 2][1][k], f[i - 2][2][k]);
          if (j == 1 && k == 1)
            f[i][j][k] = max(f[i][j][k], mx1[i - 2] + 1);
          if (j == 2 && k == 1)
            f[i][j][k] = max(f[i][j][k], mx0[i - 2] + 1);
        } else {
          f[i][j][k] = max3(f[i - 2][0][k], f[i - 2][1][k], f[i - 2][2][k]);
        }
      }
    mx0[i] = max(mx0[i - 1], f[i][0][0]);
    mx1[i] = max(mx1[i - 1], f[i][0][1]);
  }

  int ans = -INF;

  for (int j = 0; j < 3; ++j)
    for (int k = 0; k < 2; ++k)
      ans = max(ans, f[n][j][k]);
  cout << ans;
  return 0;
}