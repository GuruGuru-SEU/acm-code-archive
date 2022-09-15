#include <algorithm>
#include <cmath>
#include <iostream>

int t;
long long a, b;

long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  std::cin >> t;
  while (t--) {
    std::cin >> a >> b;
    long long g = gcd(a, 180ll * b);
    std::cout << 180ll * b / g - 1 << std::endl;
  }
  return 0;
}