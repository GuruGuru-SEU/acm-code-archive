#include <iostream>
using namespace std;
typedef long long ll;

int t;
ll n,n0;
int cnt[33],loc=0;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n0);
    loc=0;

    for (int i=32;i>=1;i--){
      ll cur = 1ll << i;
      cur--;
      if (n0/cur>=1) {
        loc=i;
        n=n0-cur;
        break;
      }
    }
    for (int i = 32; i >= 1; --i) {
      cnt[i] = 0;
      ll cur = 1ll << i;
      cur -= 1;
      cnt[i] = n / cur;
      n %= cur;
    }
    
    for (int i = 32; i >= 1; --i) {
      if (loc==i) printf("nunhehheh");
      for (int j = 1; j <= cnt[i]; ++j) {
        printf("h");
      }
      printf("a");
    }
    if (t) puts("");
  }

  return 0;
}