#include <cstring>
#include <iostream>

const int N = 1e6 + 5;

char s[N];
int q, next[N], f[N];

void exKMP_pre(char *T) {
  int n = strlen(T);
  next[0] = n;
  int p = 0;
  while (p + 1 < n && T[p] == T[p + 1])
    p++;
  next[1] = p;
  int k = 1;
  for (int x = 2; x < n; ++x) {
    p = k + next[k] - 1;
    int l = next[x - k];
    if (x + l <= p)
      next[x] = l;
    else {
      int j = p - x + 1;
      if (j < 0)
        j = 0;
      while (x + j < n && T[x + j] == T[j])
        j++;
      next[x] = j;
      k = x;
    }
  }
}

int main() {
  scanf("%s", s);
  scanf("%d", &q);
  int n = strlen(s);
  exKMP_pre(s);
  for (int i = n - 1; i >= 0; --i) {
    f[i] = f[i + 1] + (next[i] == n - i);
  }
  while (q--) {
    int i;
    scanf("%d", &i);
    i--;
    printf("%d\n", f[std::max(i + 1, n - i)]);
  }
  return 0;
}