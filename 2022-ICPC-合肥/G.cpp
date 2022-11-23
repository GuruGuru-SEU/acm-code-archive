#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
const int N = 1e6 + 3;
using namespace std;

set<int> s;
queue<int> q;
vector<int> G[2 * N];
int n, t, up_lim, a[N], b[N], d[2 * N], d_cur[2 * N];
bool vis[2 * N];
bool cmp(const int &x, const int &y) {
    return (x > y);
}
void get_lim() {
    up_lim = n;
    for (int i = 1; i <= n; i++) {
        if (s.find(i) == s.end()) {
            up_lim = i - 1;
            break;
        }
    }
}
bool check(int k) {

    while (!q.empty()) q.pop();
    for (int i = 1; i <= k; i++) {
        vis[i] = 0;
        d_cur[i] = d[i];
        if (d_cur[i] <= 1) q.push(i);
    }
    while (!q.empty()) {
        int head = q.front();
        vis[head] = 1;
        q.pop();
        if (d_cur[head] == 0) return false;
        for (auto v : G[head]) {
            if (v > k) break;
            if (vis[v]) continue;
            d_cur[v]--;
            if (d_cur[v] <= 1) {
                q.push(v);
            }
            break;
        }
    }
    return true;
}

int main() {
    cin >> n >> t;

    for (int i = 1; i <= t; i++) {
        scanf("%d%d", &a[i], &b[i]);
        s.insert(a[i]);
        s.insert(b[i]);
    }
    get_lim();
    // cout << "ok";
    for (int i = 1; i <= t; i++) {
        if (a[i] <= up_lim) {
            G[a[i]].push_back(b[i]);
            d[a[i]]++;
        }
        if (b[i] <= up_lim) {
            G[b[i]].push_back(a[i]);
            d[b[i]]++;
        }
    }
    for (int i = 1; i <= up_lim; i++) sort(G[i].begin(), G[i].end(), cmp);
    // cout << "ok";
    int lb = -1, ub = n + 2;
    // cout << check(5) << endl;
    // cout << d[3]
    //    << endl;
    while (lb + 1 < ub) {
        int mid = (lb + ub) >> 1;

        if (mid <= up_lim && check(mid))
            lb = mid;
        else
            ub = mid;
    }
    printf("%d\n", min(ub, n + 1));
    return 0;
}