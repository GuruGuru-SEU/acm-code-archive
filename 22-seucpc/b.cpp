#include <cstdio>
#include <cctype>
#include <iostream>
typedef long long ll;
using namespace std;

const int N = 1e6 + 5;

int n, m;
ll a[N], d[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= m; ++i) {
		int b, c;
		ll g;
		scanf("%d%d%lld", &b, &c, &g);
		d[b] += g;
		d[b + c] -= g;
	}
	for (int i = 1; i <= n; ++i) {
		d[i] += d[i - 1];
	}
	for (int i = 1; i <= n; ++i) {
		printf("%lld ", a[i] + d[i]);
	}
	return 0;
}

