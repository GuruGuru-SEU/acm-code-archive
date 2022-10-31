#include <algorithm>
#include <cstdio>

long long t, n, p, q, b[110][110], mult[110][110], ans;

int main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        for (int i = 1; i <= std::min(100ll, n); i++) {
            for (int j = 1; j <= i; j++)
                scanf("%lld", &(b[i][j]));
        }
        scanf("%lld", &q);
        while (q--) {
            scanf("%lld", &p);
            ans = 0;
            for (int i = 1; i <= 100; i++) {
                mult[i][0] = 1;
                for (int j = 1; j <= 100; j++)
                    mult[i][j] = (mult[i][j - 1] * i) % p;
            }
            if (p >= n) {
                for (int i = 0; i < n; i++)
                    ans = (ans + mult[10][i] * b[n][n - i] % p) % p;
            } else {
                for (int i = 1; i < p; i++)
                    ans = (ans + mult[10][(n - i) % (p - 1)] * b[p - 1][i] % p) % p;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}