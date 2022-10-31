#include <iostream>

const long long MOD = 1e9 + 7;
const long long INV2 = 500000004;
const int N = 1e5 + 5;

long long qpow(long long x, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

long long calc(long long ssum, long long sum, long long len, long long repeat) {
    long long res = 0;
    res = (res + ssum * repeat % MOD) % MOD;
    long long tmp = 0;
    tmp = (0 + len * (repeat - 1) % MOD) * repeat % MOD * INV2 % MOD;
    tmp = tmp * sum % MOD;
    res = (res + tmp) % MOD;
    return res;
}

long long ssum, sum, len, repeat;
int n, m;
long long b[N];
long long ans = -1;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        sum = (sum + b[i]) % MOD;
        ssum = (ssum + 1ll * (n - i + 1) * b[i]) % MOD;
    }
    len = n;
    repeat = qpow(2, m);
    ans = std::max(ans, calc(ssum, sum, len, repeat));
    for (int i = 1; i <= n; ++i) {
        len = len * 2 % MOD;
        ssum = sum * (1ll * (len + 1)) % MOD;
        sum = sum * 2 % MOD;
        repeat = repeat * INV2 % MOD;
        // std::cout << calc(ssum, sum, len, repeat) << std::endl;
        ans = std::max(ans, calc(ssum, sum, len, repeat));
    }
    printf("%lld", ans);
    return 0;
}