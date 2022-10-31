#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
using namespace std;
const ll INF = 1E18;
ll ans;
int a[100];
vector<vector<int>> v;
void solve(int *a, int n) {
    set<int> s;
    vector<int> temp, ttt;
    for (int i = 0; i < n; i++) s.insert((a[i] - a[(i + 1) % n]));
    for (int i = 0; i < n; i++) temp.push_back(a[i]);
    for (auto i : s) ttt.push_back(i);
    if (s.size() == ans) {
        v.push_back(temp);
        v.push_back(ttt);
    }
    if (s.size() < ans) {
        v.clear();
        v.push_back(temp);
        v.push_back(ttt);
        ans = s.size();
    }
}
int main() {
    int tt;
    ll n, m, s, t;
    cin >> tt;
    while (tt--) {
        ans = INF;
        scanf("%lld %lld %lld %lld", &n, &m, &s, &t);
        for (int i = 0; i < n; i++) a[i] = i + 1;
        do {
            if (a[0] != s || a[m - 1] != t) continue;
            solve(a, n);
        } while (next_permutation(a, a + n));
        cout << "min S:" << ans << "tot available: " << v.size() / 2 << endl;
        for (auto cur : v) {
            for (auto i : cur) printf("%d ", i);
            printf("\n");
        }
    }
}