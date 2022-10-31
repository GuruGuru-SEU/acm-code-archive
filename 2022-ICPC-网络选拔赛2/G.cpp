#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;

const ll MOD = 1000000000 + 7;

ll fac[1000005];

int n, m;
std::pair<int, int> a[1000005];

std::vector<int> children[1000005];
int fa[1000005];

bool isChild(std::pair<int, int> x, std::pair<int, int> f) {
    return f.first <= x.first && x.second <= f.second;
}

bool cmp(std::pair<int, int> x, std::pair<int, int> y) {
    if (x.first != y.first)
        return x.first < y.first;
    if (x.second != y.second)
        return x.second > y.second;
    return false;
}

ll dfs(int u) {

    ll x = a[u].second - a[u].first + 1;
    ll k = 1;
    for (auto v : children[u]) {
        ll tmp = dfs(v);
        k = k * tmp % MOD;
        x -= a[v].second - a[v].first;
    }
    // std::cout << a[u].first << ' ' << a[u].second << std::endl;
    // std::cout << k * fac[x] << std::endl
    //           << std::endl;
    return k * fac[x] % MOD;
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= 1000000; ++i)
        fac[i] = fac[i - 1] * i % MOD;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &a[i].first, &a[i].second);
    a[++m] = {1, n};
    std::sort(a + 1, a + m + 1, cmp);
    int cur = 1;
    for (int i = 2; i <= m; ++i) {
        while (!isChild(a[i], a[cur])) {
            cur = fa[cur];
        }
        fa[i] = cur;
        // std::cout << "fa[" << i << "] = " << cur << std::endl;
        children[cur].push_back(i);
        cur = i;
    }
    ll ans = dfs(1);
    printf("%lld", ans);
    return 0;
}