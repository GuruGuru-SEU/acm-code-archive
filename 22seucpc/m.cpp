#pragma GCC optimize(3)
#include <cstdio>
#include <cctype>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int i, d;
};

int n;
Node a[1000005], b[1000005];

int cnt = 0;

int main() {	
	scanf("%d", &n);
	for (int i = n; i >= 1; --i) {
		for (int j = 1; j <= i; ++j) {
			cnt++;
			a[cnt] = (Node){cnt, i};
		}
	}
	while (true) {
		if (a[1].d == 0) break;
		int d = a[1].d;
		for (int i = 2; i <= d + 1; ++i) {
			printf("%d %d\n", a[1].i, a[i].i);
			a[i].d--;
		}
		a[1].d = 0;
		int p1 = 2, up1 = d + 1;
		int p2 = d + 2, up2 = cnt;
		int tmp = 0;
		for (int i = 1; i <= cnt - 1; ++i) {
			if (p1 > up1) {
				if (a[p2].d == 0) break;
				b[++tmp] = a[p2++];
				continue;
			}
			if (p2 > up2) {
				if (a[p1].d == 0) break;
				b[++tmp] = a[p1++];
				continue;
			}
			if (a[p1].d == 0 && a[p2].d == 0) break;
			if (a[p1].d > a[p2].d) {
				b[++tmp] = a[p1++];
			} else {
				b[++tmp] = a[p2++];
			}
		}
		for (int i = 1; i <= tmp; ++i) {
			a[i] = b[i];
		}
		cnt = tmp;
	}
	return 0;
}

