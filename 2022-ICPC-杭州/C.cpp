#include <algorithm>
#include <iostream>

long long n, k, p[3010], w[3010][11], f[3010][3010], g[3010][3010], ans, sum_p = 0;

int main() {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i];
        sum_p += p[i];
        for (int j = 1; j <= p[i]; j++)
            std::cin >> w[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= 0; j--)
            f[i][j] = f[i - 1][j];
        for (int j = k; j >= 0; j--)
            if (j + p[i] <= k && (f[i - 1][j] || !j) && f[i][j + p[i]] < f[i - 1][j] + w[i][p[i]])
                f[i][j + p[i]] = f[i - 1][j] + w[i][p[i]];
    }
    for (int i = n; i >= 1; i--) {
        for (int j = k; j >= 0; j--)
            g[i][j] = g[i + 1][j];
        for (int j = k; j >= 0; j--)
            if (j + p[i] <= k && (g[i + 1][j] || !j) && g[i][j + p[i]] < g[i + 1][j] + w[i][p[i]])
                g[i][j + p[i]] = g[i + 1][j] + w[i][p[i]];
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p[i]; j++) {
            for (int kk = 0; kk <= k - j; kk++) {
                int kkk = k - j - kk;
                if (!((f[i - 1][kk] || !kk) && (g[i + 1][kkk] || !kkk))) continue;
                if (ans < w[i][j] + f[i - 1][kk] + g[i + 1][kkk]) {
                    ans = w[i][j] + f[i - 1][kk] + g[i + 1][kkk];
                }
            }
        }
    }
    if (k >= sum_p) {
        ans = 0;
        for (int j = 0; j <= k; j++)
            if (ans < f[n][j])
                ans = f[n][j];
    }
    printf("%lld\n", ans);
    return 0;
}