#include <cstdio>
#include <cctype>
#include <iostream>
using namespace std;

int t, n;
char s[20][20];

bool canWin(char p) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j + 4 <= n; ++j) {
			if (s[i][j] == p && s[i][j + 1] == p && s[i][j + 2] == p && s[i][j + 3] == p && s[i][j + 4] == p) {
				return true;
			}
				
		}
	}
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i + 4 <= n; ++i) {
			if (s[i][j] == p && s[i + 1][j] == p && s[i + 2][j] == p && s[i + 3][j] == p && s[i + 4][j] == p)
				return true;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i + 4 > n || j + 4 > n) continue;
			if (s[i][j] == p && s[i + 1][j + 1] == p && s[i + 2][j + 2] == p && s[i + 3][j + 3] == p && s[i + 4][j + 4] == p)
				return true;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i - 4 < 1 || j + 4 > n) continue;
			if (s[i][j] == p && s[i - 1][j + 1] == p && s[i - 2][j + 2] == p && s[i - 3][j + 3] == p && s[i - 4][j + 4] == p)
				return true;
		}
	}
	return false;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> (s[i] + 1);
		bool isBad = true;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (s[i][j] != '0') continue;
				s[i][j] = '1';
				if (canWin('1')) {
					isBad = false;
				}
				bool otherCanWin = false;
				for (int k = 1; k <= n; ++k) {
					for (int l = 1; l <= n; ++l) {
						if (s[k][l] != '0') continue;
						s[k][l] = '2';
						if (canWin('2')) {
							otherCanWin = true;
						}
						s[k][l] = '0';
					}
				} 
				if (otherCanWin == false) {
					isBad = false;
				}
				s[i][j] = '0';
			}
		}
		if (isBad) puts("1");
		else puts("0");
	}
	return 0;
}

