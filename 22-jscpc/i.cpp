#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
  cin >> s;
  int len = s.size();
  for (int i = 1; i < len; ++i) {
    if (s[i] != s[0]) return puts("0"), 0;
  }
  printf("%d", len - 1);

  return 0;
}