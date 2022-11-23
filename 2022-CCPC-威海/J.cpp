#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>

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

const int N = 1e5 + 5;

int T, n, k, x[N], a[N], b[N << 1], cnt, L, c[N], s[N];
long long lim[N], y[N];
long long ans;

int main() {
    fead(T);
    while (T--) {
        cnt = 0;
        fead(n, k);
        for (int i = 1; i <= n; ++i) {
            fead(a[i]);
            b[++cnt] = a[i];
        }
        for (int i = 1; i <= k; ++i) {
            fead(x[i], y[i]);
            b[++cnt] = x[i];
        }
        std::sort(b + 1, b + cnt + 1);
        L = std::unique(b + 1, b + cnt + 1) - b - 1;
        for (int i = 0; i <= L; ++i) {
            lim[i] = -1;
            c[i] = s[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            a[i] = std::lower_bound(b + 1, b + L + 1, a[i]) - b;
        }
        for (int i = 1; i <= k; ++i) {
            x[i] = std::lower_bound(b + 1, b + L + 1, x[i]) - b;
        }

        lim[0] = n - 1;
        ans = 0;
    }
    return 0;
}