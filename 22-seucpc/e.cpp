#include <cstdio>
#include <cctype>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

template<typename tn> void fead(tn &n) {
	tn k = 0, f = 1, i = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) k = k * 10 + ch - '0', ch = getchar();
	if (ch == '.') {ch = getchar(); while(isdigit(ch)) i /= 10, k += i * (ch - '0'), ch = getchar();}
	n = k * f;
}
long long n, m, k, l, r;
bool check(long long x) {
	long long hal = sqrt(x);
	long long res = 0, tmp;
	if (m < n) swap(n, m);
	for (long long i = 1; i <= min(hal, m); i++) {
		tmp = x / i;
		res += min(tmp, n);
		if (i == hal) {
			res += min(hal, n) * (min((x / hal), m) - min(hal, m));
		}
		else {
			res += min(i, n) * (min(x / i, m) - min(x / (i + 1), m));
		}
	}
	return k <= res;
}
int main() {
	fead(n); fead(m); fead(k);
	l = 0ll; r = 1e12;
	while (l + 1 < r) {
		long long mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid;
	}
	printf("%lld\n", r);
	return 0;
}

