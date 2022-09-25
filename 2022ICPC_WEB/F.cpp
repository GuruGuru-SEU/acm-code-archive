#include <iostream>
#include <unordered_set>
#include <vector>
typedef long long ll;

bool canMul(ll x, ll y) {
    long double xx = x, yy = y;
    if (xx * yy > 1e18) return false;
    return true;
}

ll getSz(ll k, ll x) {
    ll sz = 1;
    while (true) {
        if (canMul(sz, k + 1) == 0 || sz * (k + 1) >= x) break;
        sz *= (k + 1);
    }
    return sz;
}

ll getAncestor(ll k, ll x, ll sz) {
    x -= sz;
    return (x + k - 1) / k;
}

int t;
ll k, x, y;
std::vector<ll> a1, a2;

int main() {
    scanf("%d", &t);
    while (t--) {
        a1.clear(), a2.clear();
        scanf("%lld%lld%lld", &k, &x, &y);
        ll cur = x, cur_sz = getSz(k, x), ans = 0;
        a1.push_back(cur);
        while (true) {
            //   std::cout << cur << ' ' << cur_sz << std::endl;
            cur = getAncestor(k, cur, cur_sz);
            a1.push_back(cur);
            if (cur == 1) break;
            while (cur_sz >= cur)
                cur_sz /= (k + 1);
        }
        cur = y, cur_sz = getSz(k, y);
        a2.push_back(cur);
        while (true) {
            cur = getAncestor(k, cur, cur_sz);
            a2.push_back(cur);
            if (cur == 1) break;
            while (cur_sz >= cur)
                cur_sz /= (k + 1);
        }
        int p1 = 0, p2 = 0;
        while (true) {
            if (a1[p1] == a2[p2]) {
                ans = a1[p1];
                break;
            }
            if (a1[p1] > a2[p2])
                p1++;
            else
                p2++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*

1
10000000000000000 20000000000000000 30000000000000000

*/