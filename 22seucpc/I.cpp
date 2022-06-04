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
const int N=1e6+3;
const int inf=0x3f3f3f3f;
int cnt=0;
struct node{
	int a,b;
	bool operator <(const node &c)const{
		if (a==c.a) return b<c.b;
		return a<c.a;
	}
};
node ini[N],p[N],g[N];
int d[N],n,m,mn=0;
int main() {
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		int x,y;
		fead(x);fead(y);
		ini[cnt].a=x,ini[cnt].b=y;
		cnt++;
	}
	sort(ini,ini+cnt);
	for (int i=0;i<cnt;i++){
		p[i]={ini[i].b,i};
	}
	for (int i=1;i<=n;i++) g[i]={inf,inf};
	for (int i=0;i<n;i++){
		int k=lower_bound(g+1,g+n+1,p[i])-g;
		d[i]=k;
		g[k]=p[i];
	} 
	for (int i=0;i<n;i++) mn=max(mn,d[i]);
	cout<<n-mn;
	
	return 0;
}

