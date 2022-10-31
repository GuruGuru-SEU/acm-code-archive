#include <cstdio>
#include <cctype>
#include <iostream>

using namespace std;

int s[300][300*300], l[300];
int t[300][300*300], p[300];
int cnt, n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			s[i][++l[i]] = ++cnt;
		}
	}
	for (int i = n; i >= 1; --i) {
		while (l[i]) {
			int cur = s[i][l[i]--];
			int times = 0;
			for (int j = i; j >= 1; --j) {
				if (times >= i) break;
				while (l[j]) {
					if (times >= i) break;
					int nxt = s[j][l[j]--];
					t[j - 1][++p[j - 1]] = nxt;
					printf("%d %d\n", cur, nxt);
					times++;
				}
			}
			for (int j = i; j >= 0; --j) {
				while (p[j]) {
					s[j][++l[j]] = t[j][p[j]--];
				}
			}
//			cout << "=========" << endl;
//			for (int j = n; j >= 1; --j) {
//				cout << j << ": ";
//				for (int k = l[j]; k >= 1; --k) {
//					cout << s[j][k] << ' ';
//				}
//				cout << endl;
//			}
		}
		
	}
	return 0;
}

