#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

std::vector<int> edges[200010];
std::vector<std::pair<long long, int>> max_1, max_2;
long long a[200010], f[200010][4];
int n, fa[200010];

void work(int u) {
    f[u][0] = a[u];
    f[u][1] = a[u];
    f[u][2] = a[u];
    f[u][3] = a[u];
    for (int v : edges[u]) {
        if (v == fa[u]) continue;
        fa[v] = u;
        work(v);
        if (f[v][1] > f[u][1])
            f[u][1] = f[v][1];
        if (a[u] + f[v][0] > f[u][0])
            f[u][0] = a[u] + f[v][0];
        if (a[u] + f[v][2] > f[u][2])
            f[u][2] = a[u] + f[v][2];
        if (f[v][3] > f[u][3])
            f[u][3] = f[v][3];
    }
    max_1.clear();
    max_2.clear();
    for (int v : edges[u]) {
        if (v == fa[u]) continue;
        max_1.push_back(std::make_pair(f[v][0], v));
        max_2.push_back(std::make_pair(f[v][1], v));
    }
    std::sort(max_1.begin(), max_1.end(), std::greater<std::pair<long long, int>>());
    std::sort(max_2.begin(), max_2.end(), std::greater<std::pair<long long, int>>());
    long long tmp1 = a[u], tmp3 = 0, tmp4 = 0, tmp5 = 0;
    for (int i = 0; i < max_1.size(); i++) {
        if (i < 2) tmp1 += max_1[i].first;
        if (i < 2) tmp5 += max_2[i].first;
        if (i < 3) tmp4 += max_1[i].first;
        if (i < 4) tmp3 += max_1[i].first;
    }
    if (tmp1 > f[u][1]) f[u][1] = tmp1;
    if (tmp3 > f[u][3]) f[u][3] = tmp3;
    if (tmp4 + a[u] > f[u][3]) f[u][3] = tmp4 + a[u];
    if (tmp4 > f[u][2]) f[u][2] = tmp4;
    if (tmp5 > f[u][3]) f[u][3] = tmp5;
    if (f[u][1] > f[u][2]) f[u][2] = f[u][1];
    for (int v : edges[u]) {
        if (v == fa[u]) continue;
        if (v == max_1[0].second) {
            if (max_1.size() > 1) {
                if (f[v][1] + max_1[1].first + a[u] > f[u][2])
                    f[u][2] = f[v][1] + max_1[1].first + a[u];
            } else {
                if (f[v][1] + a[u] > f[u][2])
                    f[u][2] = f[v][1] + a[u];
            }
        } else {
            if (f[v][1] + max_1[0].first + a[u] > f[u][2])
                f[u][2] = f[v][1] + max_1[0].first + a[u];
        }
    }
    if (f[u][2] > f[u][3]) f[u][3] = f[u][2];
    for (int v : edges[u]) {
        if (v == fa[u]) continue;
        if (v == max_1[0].second) {
            if (max_1.size() > 1) {
                if (f[v][2] + max_1[1].first + a[u] > f[u][3])
                    f[u][3] = f[v][2] + max_1[1].first + a[u];
            } else {
                if (f[v][2] + a[u] > f[u][3])
                    f[u][3] = f[v][2] + a[u];
            }
        } else {
            if (f[v][2] + max_1[0].first + a[u] > f[u][3])
                f[u][3] = f[v][2] + max_1[0].first + a[u];
        }
    }
    for (int v : edges[u]) {
        if (v == fa[u]) continue;
        int p = 0;
        long long tmp33 = 0;
        for (int j = 0; j < 2; j++) {
            while (p < max_1.size() && max_1[p].second == v) p++;
            if (p == max_1.size()) break;
            tmp33 += max_1[p].first;
            p++;
        }
        if (tmp33 + f[v][1] + a[u] > f[u][3])
            f[u][3] = tmp33 + f[v][1] + a[u];
    }
    // printf("%d %lld %lld %lld %lld\n", u, f[u][0], f[u][1], f[u][2], f[u][3]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    fa[1] = 0;
    work(1);
    if (n == 1) f[1][3] = 0;
    printf("%lld\n", f[1][3]);
    return 0;
}
// 9
// 2 6 1 5 1 1 2 2 1
// 1 2
// 1 3
// 3 4
// 4 5
// 5 6
// 5 7
// 5 8
// 4 9