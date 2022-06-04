#include <cstdio>
#include <cctype>
#include <iostream>
#include <set>

using namespace std;

int a[20][20];

bool vali_block(int x, int y) {
	set<int> s;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int cur = a[x + i][y + j];
			if (cur == 0) continue;
			if (s.find(cur) != s.end()) return false;
			s.insert(cur);
		}
	}
	return true;
}

bool vali_row(int x) {
	set<int> s;
	for (int j = 1; j <= 9; ++j) {
		int cur = a[x][j];
		if (cur == 0) continue;
		if (s.find(cur) != s.end()) return false;
		s.insert(cur);
	}
	return true;
}

bool vali_col(int y) {
	set<int> s;
	for (int i = 1; i <= 9; ++i) {
		int cur = a[i][y];
		if (cur == 0) continue;
		if (s.find(cur) != s.end()) return false;
		s.insert(cur);
	}
	return true;
}

bool vali() {
	for (int i = 1; i <= 9; i += 3) {
		for (int j = 1; j <= 9; j += 3) {
			if (!vali_block(i, j)) return false;
		}
	}
	for (int i = 1; i <= 9; ++i) {
		if (!vali_row(i)) return false;
		if (!vali_col(i)) return false;
	}
	return true;
}

bool dfs(int x, int y) {
	if (y > 9) return dfs(x + 1, 1);
	if (x > 9) return true;
	int& cur = a[x][y];
	if (cur) return dfs(x, y + 1);
	for (int i = 1; i <= 9; ++i) {
		cur = i;
		if (vali() && dfs(x, y + 1)) return true;
	}
	cur = 0;
	return false;
}

int main() {
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			cin >> a[i][j];
		}
	}
	dfs(1, 1);
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}

