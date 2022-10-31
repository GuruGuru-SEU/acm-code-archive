#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

int t;
ll L, R, K;

ll func(ll x, ll n) {
    ll p1 = (R / x - n + 1);
    ll p2 = (L + x - 1) / x;
    return p1 - p2;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        vector<ll> tot_ans;
        scanf("%lld%lld%lld", &L, &R, &K);
        for (int n = 1; n <= 50; ++n) {
            ll C = (1ll << (n - 1)) * n;
            if (2 * K % C != 0) continue;
            if (C > 2 * K) break;
            ll B = 2 * K / C;
            ll A = n - 1;
            ll l = 1, r = R, ans = -1;
            while (l <= r) {
                ll mid = (l + r) >> 1;
                if (func(mid, n) <= 0)
                    ans = mid, r = mid - 1;
                else
                    l = mid + 1;
            }
            if (n == 1) {
                cout << "ANS: " << ans << endl;
            }
            if (ans == -1) continue;
            for (ll x = ans;; x++) {
                if (func(x, n) != 0) break;
                if (tot_ans.size() == 100001) break;
                ll k = (L + x - 1) / x;
                if ((2 * k + A) * x == B) {
                    tot_ans.push_back(x);
                }
            }
        }
        sort(tot_ans.begin(), tot_ans.end());
        if (tot_ans.size() > 100000) {
            puts("Too Many!");
        } else if (tot_ans.size() == 0) {
            puts("No Solution");
        } else {
            printf("%d\n", (int)tot_ans.size());
            for (auto x : tot_ans) {
                printf("%lld ", x);
            }
            puts("");
        }
    }
    return 0;
}