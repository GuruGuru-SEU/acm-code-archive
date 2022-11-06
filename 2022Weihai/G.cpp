#include <cctype>
#include <cstdio>

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

long long x, k = 1, l, r, n;
long long a[2000010], arr[2000010];

long long my_gcd(long long a, long long b) {
    if (!b) return a;
    return my_gcd(b, a % b);
}

long long calc(long long i) {
    long long kk = i / k;
    return kk * arr[k - 1] + arr[i % k];
}

int main() {
    fead(x, n);
    while (x >= k) k <<= 1;
    for (int i = 0; i <= k; i++) {
        a[i] = (my_gcd((i * x) ^ x, x) == 1);
        arr[i] = a[i];
        if (i) arr[i] += arr[i - 1];
    }
    while (n--) {
        fead(l, r);
        printf("%lld\n", calc(r) - calc(l - 1));
    }
    return 0;
}