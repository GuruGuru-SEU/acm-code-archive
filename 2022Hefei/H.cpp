#include <cstdio>

const long long key = 1e9 + 7;
long long T, n, k, a[2010], sum;

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

long long inv_mod(long long a, long long p) {
    long long x, y;
    long long d = exgcd(a, p, x, y);
    return (d == 1) ? (x + p) % p : -1;
}

int main() {
    a[1] = 1;
    sum = 1;
    for (int i = 2; i <= 2000; i++) {
        long long inv_i = inv_mod(i, key);
        a[i] = inv_i * (sum + i) % key;
        sum = (sum + a[i]) % key;
    }
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld", &n, &k);
        printf("%lld\n", (n * a[k]) % key);
    }
    return 0;
}