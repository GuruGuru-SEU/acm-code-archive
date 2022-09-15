#include <cstdio>
#include <cctype>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename tn> void fead(tn &n) {
	tn k = 0, f = 1, i = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) k = k * 10 + ch - '0', ch = getchar();
	if (ch == '.') {ch = getchar(); while(isdigit(ch)) i /= 10, k += i * (ch - '0'), ch = getchar();}
	n = k * f;
}
int n,m,t[200010];
int main() {
	cin>>n>>m;
	int mn=0x3f3f3f3f;
	for (int i=1;i<=m;i++) scanf("%d",&t[i]);
	sort(t+1,t+m+1);
	for (int i=1;i+n<=m;i++) mn=min(mn,t[i+n]-t[i]);
	cout<<mn;
	return 0;
}

