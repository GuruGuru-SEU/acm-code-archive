#include <iostream>
#include <cstring>
using namespace std;

char s[300005];
int a[300005], cnt, n, ans;

int main() {
  cin >> (s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    if (s[i] != 'B') continue;
    int a1 = 0, a2 = 0;
    for (int j = i - 1; j >= 1; --j) {
      if (s[j] != 'A') break;
      a1++;
    }
    for (int j = i + 1; j <= n; ++j) {
      if (s[j] != 'C') break;
      a2++;
    }
    if (i % 2 == 0) {
      if (a1 && a2) a1--, a2--, ans++;
    }
    if (min(a1, a2) == 0) continue;
    a[++cnt] = min(a1, a2);
  }
  for (int i = 1; i <= cnt; i++) {
    if (!a[i]) continue;
    ans++;
    for (int j = i + 1; j <= cnt; j++) {
      if (a[j]) {a[j]--;ans++;}
    }
  }
  printf("%d\n", ans);
  return 0;
}