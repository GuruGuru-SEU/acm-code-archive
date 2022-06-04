#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define ll long long
using namespace std;
const int N=2e6+3;
std::vector<int> a, b, c;

int is_prime[N], T, n, m,tot,prime[N],ub,cnt[N],sum[N],ubb;
int vis[N];

void es(){
  for (int i=2;i<N;i++) is_prime[i]=1;
  for (ll i=2;i<N;i++){
    if (is_prime[i]==0) continue;
    for (ll j=i*i;j<N;j+=i) is_prime[j]=0;
  }
}

int main(){
  es();
  int q=0;
  for (int i=2;i<N;i++) if (is_prime[i]) prime[++q]=i;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    tot=n+m; 
    ubb=0;
    a.clear(); b.clear();c.clear();
    for (int i=1;i<=tot;i++) {
      vis[i]=0,cnt[i]=0,sum[i]=0;
    }
    for (int i=1;i;i++){
      sum[i]=tot/prime[i];
      if (sum[i]<4){
        ub=i;
        break;
      }
    }
    cnt[1]=sum[1];
    for (int i=2;i<ub;i++){
      int tmp=0;
      for (int j=1;j<i;j++){
        tmp+=tot/(prime[i]*prime[j])-1;
      }
      if (tmp<=1) {ubb=i;break;}
    }
    
    for (int i=1;i<ub;i++){
      int k=tot/prime[i]*prime[i];
      if (cnt[i]<2||sum[i]<4) break;
      for (int j=k;j>=prime[i];j-=prime[i]){
        if (vis[j] || j==prime[i]*prime[ubb]) continue;
        a.push_back(j);
        for (int p=i+1;p<ub;p++) if (j%prime[p]==0) cnt[p]++;
        vis[j]=1;
        
      }
    }
    //for (auto x:a) cout<<x<<" ";
    if (a.size()>max(n,m)) {printf("NO\n");continue;}
    printf("YES\n");

    
    
    if (ubb>0){
    for (int i=1;i<=tot;i++){
      if (vis[i]) continue;
      if (i%prime[ubb]==0) {c.push_back(i);vis[i]=1;}
      
    }
    // if (!c.empty()){
    //   vis[c[c.size()-1]]=0;
    //   c.pop_back();
    // }
    if (c.size()>min(m,n)&&c.size()-1+a.size()>max(m,n)) {printf("NO\n");continue;}
    if (c.size()<=min(m,n)){
      for (auto x:c) b.push_back(x);
    }else {
      for (int i=0;i<c.size()-1;i++) a.push_back(c[i]);
      if (!c.empty()) b.push_back(c[c.size()-1]);
    }
    }
    for (int i=1;i<=tot;i++){
      if (vis[i]) continue;
      if (a.size()<max(n,m)) a.push_back(i);
      else b.push_back(i);
    }
    if (n>m){
      for (int i = 0; i < a.size() - 1; ++i) {
        printf("%d ", a[i]);
      }
      printf("%d\n", a[a.size() - 1]);

      for (int i = 0; i < b.size() - 1; ++i) {
        printf("%d ", b[i]);
      }
      printf("%d\n", b[b.size() - 1]);
    }
    else{

      for (int i = 0; i < b.size() - 1; ++i) {
        printf("%d ", b[i]);
      }
      printf("%d\n", b[b.size() - 1]);

      for (int i = 0; i < a.size() - 1; ++i) {
        printf("%d ", a[i]);
      }
      printf("%d\n", a[a.size() - 1]);

    }
    
  }
  return 0;
}