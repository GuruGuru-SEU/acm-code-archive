#include <iostream>

using namespace std;

int d[100010];
int n, m;
bool check() {
    for (int i = 1; i <= n; i++)
        if (d[i] != 2) return false;
    return true;
}
int main() {
    int tt;
    cin >> tt;
    while (tt--) {

        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) d[i] = 0;
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            d[u]++, d[v]++;
        }
        if (m == n - 1) puts("YES");
        if (m > n) puts("NO");
        if (m == n) {
            if (check())
                puts("YES");
            else
                puts("NO");
        }
    }

    return 0;
}