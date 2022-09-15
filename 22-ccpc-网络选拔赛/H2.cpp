#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>

template <typename tn>
void fead(tn &n) {
    tn f = 1, t = 0, r = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) t = t * 10 + ch - '0', ch = getchar();
    if (ch == '.') {
        ch = getchar();
        while (isdigit(ch)) r *= 10;
        t += (ch - '0') / r, ch = getchar();
    }
    n = f * t;
}

template <typename tn, typename... T>
void fead(tn &n, T &...args) {
    fead(n);
    fead(args...);
}

long long T, L, R, K, Y, y, yb;
std::vector<long long> ans;
int a[20010];
std::vector<std::pair<long long, int>> facs;

void fac_bk_dn(long long x) {
    facs.clear();
    for (long long i = 2; i * i <= x; i++) {
        int cnt = 0;
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
        if (cnt) facs.push_back(std::make_pair(i, cnt));
    }
    if (x > 1) facs.push_back(std::make_pair(x, 1));
}

void work(int dep, long long x) {
    if (dep == facs.size()) {
        long long z = Y / x;
        if ((y + z) % 2 == 0) return;
        long long r = (y + z - 1) / 2;
        long long l = r - y;
        if (l * x < L && (l + 1) * x >= L && r * x <= R && (r + 1) * x > R)
            ans.push_back(x);
        return;
    }
    for (int i = 0; i <= facs[dep].second; i++) {
        work(dep + 1, x);
        x *= facs[dep].first;
    }
}

int main() {
    fead(T);
    while (T--) {
        fead(L, R, K);
        ans.clear();
        for (y = 1, yb = 2; y * yb <= 4 * K; y++, yb *= 2ll) {
            if ((4 * K) % (y * yb)) continue;
            Y = (4 * K) / (y * yb);
            if (Y > L + 2 * R) continue;
            fac_bk_dn(Y);
            work(0, 1ll);
        }
        if (!ans.size()) {
            puts("No Solution");
            continue;
        }
        if (ans.size() > 1e5) {
            puts("Too Many!");
            continue;
        }
        printf("%d\n", ans.size());
        std::sort(ans.begin(), ans.end());
        for (long long xx : ans)
            printf("%lld ", xx);
        putchar('\n');
    }
    return 0;
}