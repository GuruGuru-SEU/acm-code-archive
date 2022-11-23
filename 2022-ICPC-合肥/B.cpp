#include <cstdio>
#include <iostream>

int T, x, y, z, k, r, p;
long double ans;

long double qpow(double x, int n) {
    if (n == 0) return 1.0f;
    if (n == 1) return x;
    long double res = qpow(x, n / 2);
    res *= res;
    if (n & 1) res *= x;
    return res;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &x, &y, &p);
        k = x / y;
        r = x % y;
        ans = (double(r) / double(y)) / double(p) * qpow(1.0f - 1.0f / double(p), k) + (1.0f - qpow(1.0f - 1.0f / double(p), k));
        printf("%.15Lf\n", ans);
    }

    return 0;
}