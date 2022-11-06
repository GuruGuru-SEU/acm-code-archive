#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
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
        while (isdigit(ch)) r *= 10, t += (ch - '0') / r, ch = getchar();
    }
    n = f * t;
}

template <typename tn, typename... T>
void fead(tn &n, T &...args) {
    fead(n);
    fead(args...);
}

int T, n, k;
long long a[500010], aa[500010], b[30], bb[30], cc[30], l, r, mid;
bool is_ok;

int main() {
    fead(T);
    while (T--) {
        fead(n, k);
        for (int i = 1; i <= n; i++)
            fead(a[i]);
        r = 1;
        for (int i = 1; i <= k; i++) {
            fead(b[i]);
            r += b[i];
        }
        l = 0;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            is_ok = true;
            for (int i = 1; i <= k; i++)
                bb[i] = b[i];
            for (int i = 1; i <= n; i++)
                aa[i] = mid * a[i];
            std::sort(aa + 1, aa + 1 + n);

            long long sum = b[1], pos = 1, asum = 0, cnt = b[1];
            for (int i = 1; i <= n; i++) {
                asum += a[i];
                while (pos <= k && (a[i] > b[pos] || sum < asum || cnt < i)) {
                    sum += b[pos] * (1ll << (pos - 1));
                    cnt += b[pos];
                    pos++;
                }
                if (pos > k) is_ok = false;
            }

            if (is_ok)
                l = mid;
            else
                r = mid;
        }
        printf("%lld\n", l);
    }
    return 0;
}