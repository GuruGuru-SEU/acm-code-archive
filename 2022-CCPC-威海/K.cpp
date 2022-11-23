#include <iostream>

typedef long long ll;

const ll INF = 1e18;

ll lmax, rmin;
ll lmin, rmax;
int t, n;
ll ans;
bool is_inf;

int main() {
    scanf("%d", &t);
    while (t--) {
        lmax = rmax = INF;
        lmin = rmin = -INF;
        ans = 0, is_inf = false;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            int op;
            ll k, x;
            scanf("%d%lld%lld", &op, &k, &x);
            ll delta = k * (k - 1) / 2;
            if (op == 1) {
                lmax = std::min(lmax, (x - delta) / k);
                rmin = std::max(rmin, (x + delta + k - 1) / k);
            } else {
                lmin = std::max(lmin, (x - delta) / k + 1);
                rmax = std::min(rmax, (x + delta + k - 1) / k - 1);
            }
        }
        // std::cout << lmin << ' ' << rmax << std::endl;
        ll lans, rans;
        bool lis_inf, ris_inf;

        lis_inf = (lmax == INF);
        lans = std::max(lmax, 0ll);
        ris_inf = (rmax == INF || rmin == -INF);
        rans = std::max(rmax - rmin + 1, 0ll);
        is_inf |= (lans * rans) && (lis_inf || ris_inf);
        ans += lans * rans;

        lis_inf = (lmin == -INF || lmax == INF);
        lans = std::max(lmax - lmin + 1, 0ll);
        ris_inf = 1;
        rans = 1;
        is_inf |= (lans * rans) && (lis_inf || ris_inf);
        ans += lans * rans;

        printf("%lld\n", is_inf ? -1ll : ans);
    }

    return 0;
}