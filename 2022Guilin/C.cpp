#include <iostream>

const long long key = 1e9 + 7;

long long qpow(long long x, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1) res = res * x % key;
        x = x * x % key;
        n >>= 1;
    }
    return res;
}

long long n, m, a[1000010], sum, ans, res;

int main() {
    scanf("%lld%lld", &n, &m);
    sum = 0;
    ans = 0;
    res = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        sum = (sum + a[i]) % key;
        res = (res + a[i] * (n + 1 - i) % key) % key;
    }
    ans = ((res * qpow(2, m) % key + (sum * n % key) * ((qpow(2, m) - 1) * qpow(2, m - 1) % key) % key)) % key;
    printf("%lld\n", ans);
    for (long long k = 0; k < m; k++) {
        long long tmp = (qpow(2, k + 1) * n) % key;
        res = ((qpow(2, m - k - 1) * (tmp + 1)) % key + (qpow(2, m + k) * n % key) * (qpow(2, m - k - 1) - 1) % key) % key;
        res = (res * sum) % key;
        printf("%lld\n", res);
        if (res < ans) ans = res;
    }
    printf("%lld\n", ans);
    return 0;
}