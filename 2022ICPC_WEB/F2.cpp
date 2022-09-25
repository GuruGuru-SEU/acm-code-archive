#include <iostream>
#include <unordered_set>
typedef long long ll;

bool canMul(ll x, ll y) {
    ll z = x * y;
    return (z / x) == y;
}

ll getAncestor(ll k, ll x) {
    ll sz = 1;
    while (true) {
        if (canMul(sz, k + 1) == 0 || sz * (k + 1) >= x) break;
        sz *= (k + 1);
    }
    x -= sz;
    return (x + k - 1) / k;
}

int t;
ll k, x, y;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld%lld", &k, &x, &y);
        ll cur = x, ans = 0;
        std::unordered_set<ll> ancs;
        ancs.insert(cur);
        while (true) {
            cur = getAncestor(k, cur);
            ancs.insert(cur);
            if (cur == 1) break;
        }
        cur = y;
        if (ancs.find(cur) != ancs.end()) {
            ans = cur;
        }
        while (!ans) {
            cur = getAncestor(k, cur);
            if (ancs.find(cur) != ancs.end()) {
                ans = cur;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}