#include <iostream>
#include <string>
#include <set>

using namespace std;

int n;
set<string> players;
string a[1005], b[1005], c[1005];
int cnt;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    players.insert(a[i]);
    players.insert(b[i]);
  }
  for (auto p : players) {
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == p) c[++cnt] = b[i];
    }
    for (int i = 5; i <= cnt; ++i) {
      set<string> tmp;
      tmp.insert(c[i-4]);
      tmp.insert(c[i-3]);
      tmp.insert(c[i-2]);
      tmp.insert(c[i-1]);
      tmp.insert(c[i]);
      if(tmp.size()==5){
        return puts("PENTA KILL!"),0;
      }
    }
  }

  puts("SAD:(");
  return 0;
}