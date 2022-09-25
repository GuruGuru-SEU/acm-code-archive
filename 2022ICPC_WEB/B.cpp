#include <iostream>
typedef long long ll;

const int N = 105;

int n;
ll a[N];
ll f[N][N];

ll dis(ll x, ll y) {
    return (x - y) * (x - y);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    f[1][1] = 0;
    f[2][2] = dis(a[2], a[1]);
    for (int i = 3; i <= n; ++i) {
        for (int j = 2; j <= i; ++j) {
            int k = j - 1;
            for (int ii = 1; ii < i; ++ii) {
                if (ii == 1 && k != 1) continue;
                if (ii > 1 && k < 2) continue;
                if (k > ii) continue;
                f[i][j] = std::max(f[i][j], f[ii][k] + dis(a[i], a[ii]));
                // if (i == 4 && j == 4) {
                //     std::cout << ii << ' ' << k << std::endl;
                // }
            }
        }
    }

    // for (int i = 3; i <= n; ++i) {
    //     for (int j = 2; j <= i; ++j) {
    //         std::cout << f[i][j] << ' ';
    //     }
    //     std::cout << std::endl;
    // }

    ll ans = 0;
    for (int k = 1; k <= 2 * n; k += 2) {
        if (n - k >= 2)
            ans = std::max(ans, f[n][n - k]);
        if (n - k - 1 >= 2)
            ans = std::max(ans, f[n][n - k - 1]);
        printf("%lld\n", ans);
    }

    return 0;
}