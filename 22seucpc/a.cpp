#include <cstdio>
#include <cctype>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

template<typename tn> void fead(tn &n) {
	tn k = 0, f = 1, i = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) k = k * 10 + ch - '0', ch = getchar();
	if (ch == '.') {ch = getchar(); while(isdigit(ch)) i /= 10, k += i * (ch - '0'), ch = getchar();}
	n = k * f;
}

int h, w, a[1010][1010], s[1010][1010], ans = 0;

vector<pair<int, int> > ul, lr;

bool check(pair<int, int> a, pair<int, int> b) {
	if ((s[a.first][b.second] - s[a.first - 1][b.second]) - (s[a.first][a.second - 1] - s[a.first - 1][a.second - 1]) < b.second + 1 - a.second)
		return false;
	if ((s[b.first][b.second] - s[b.first - 1][b.second]) - (s[b.first][a.second - 1] - s[b.first - 1][a.second - 1]) < b.second + 1 - a.second)
		return false;
	if ((s[b.first][a.second] - s[b.first][a.second - 1]) - (s[a.first - 1][a.second] - s[a.first - 1][a.second - 1]) < b.first + 1 - a.first)
		return false;
	if ((s[b.first][b.second] - s[b.first][b.second - 1]) - (s[a.first - 1][b.second] - s[a.first - 1][b.second - 1]) < b.first + 1 - a.first)
		return false;
	return true;
}
int main() {
	fead(h); fead(w);
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			fead(a[i][j]);
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	for (int i = 1; i <= h; i++)
		s[i][w + 1] = s[i][w];
	for (int j = 1; j <= w + 1; j++)
		s[h + 1][j] = s[h][j]; 
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			if (a[i][j] && a[i][j + 1] && a[i + 1][j])
				ul.push_back(make_pair(i, j));
			if (a[i][j] && a[i][j - 1] && a[i - 1][j])
				lr.push_back(make_pair(i, j));
		}
	for (auto v : lr) {
		for (auto u : ul)
			if (u.first < v.first - 1 && u.second < v.second - 1 && check(u, v))
				ans++;
	}
	printf("%d\n", ans);
	return 0;
}

