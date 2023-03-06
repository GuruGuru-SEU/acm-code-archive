#include <cstdio>

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    long long ans = exgcd(b, a % b, x, y);
    long long tmp = x;
    x = y;
    y = tmp - a / b * y;
    return ans;
}

long long sum = 0, n, m, a, b, s, d;

int main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a);
        sum = (sum + a) % m;
    }
    a = exgcd(n, (n * (n + 1) / 2), s, d);
    a = (n * s + (n * (n + 1) / 2) * d);
    if (a < 0) {
        a *= -1;
        s *= -1;
        d *= -1;
    }
    a %= m;
    if (d < 0) {
        d += ((-d) / m + 1) * m;
        d %= m;
    }
    if (s < 0) {
        s += ((-s) / m + 1) * m;
        s %= m;
    }
    if (a) {
        long long z, xx, yy;
        z = exgcd(a, m, xx, yy);
        xx = (xx + m) % m;
        b = ((m - sum) % m + z - 1) / z;
        b = (b * xx) % m;
    } else
        b = 0;
    printf("%lld\n", (b * a + sum) % m);
    printf("%lld %lld\n", b * s % m, b * d % m);
    return 0;
}