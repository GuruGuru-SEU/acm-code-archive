#include <cstdio>
#include <cctype>
#include <iostream>

using namespace std;

template<typename tn> void fead(tn &n) {
	tn k = 0, f = 1, i = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) k = k * 10 + ch - '0', ch = getchar();
	if (ch == '.') {ch = getchar(); while(isdigit(ch)) i /= 10, k += i * (ch - '0'), ch = getchar();}
	n = k * f;
}

const long long key = 998244353ll;

struct Matrix{
	long long a[5][5];
}A, B, cc;

void mat_mul(Matrix & a, Matrix b) {
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			cc.a[i][j] = 0;
	
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			for (int k = 1; k <= 4; k++)
				cc.a[i][j] = (cc.a[i][j] + a.a[i][k] * b.a[k][j] % key) % key;
				
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			a.a[i][j] = cc.a[i][j];
}

long long n, m, k, a, b, c, d;
int main() {
	
	fead(n); fead(m); fead(k);
	A.a[1][1] = (n + m - 4ll) % key; A.a[1][2] = (m - 1ll) % key; A.a[1][3] = (n - 1ll) % key; A.a[1][4] = 0;
	A.a[2][1] = 1ll; A.a[2][2] = (n - 2ll) % key; A.a[2][3] = 0; A.a[2][4] = (n - 1ll) % key;
	A.a[3][1] = 1ll; A.a[3][2] = 0; A.a[3][3] = (m - 2ll) % key; A.a[3][4] = (m - 1ll) % key;
	A.a[4][1] = 0; A.a[4][2] = 1ll; A.a[4][3] = 1ll; A.a[4][4] = 0;
	B.a[1][1] = B.a[2][2] = B.a[3][3] = B.a[4][4] = 1ll;
	while (k) {
		if (k & 1) mat_mul(B, A);
		mat_mul(A, A);
		k >>= 1;
	}
//	for (int i = 1; i <= k; i++)
//		mat_mul(B, A);
	
	fead(a); fead(b); fead(c); fead(d);
	if (a != c && b != d) printf("%lld\n", B.a[4][1]);
	if (a != c && b == d) printf("%lld\n", B.a[4][2]);
	if (a == c && b != d) printf("%lld\n", B.a[4][3]);
	if (a == c && b == d) printf("%lld\n", B.a[4][4]);
	return 0;
}

