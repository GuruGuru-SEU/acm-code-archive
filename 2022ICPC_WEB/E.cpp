#include <iostream>

long long n, k, i, ans = 0;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    scanf("%lld%lld", &n, &k);
    ans = k;
    n--;
    while (n && k > 2) {
        n--;
        for (i = 2; i < k; i++)
            if (gcd(k, i) == 1) break;
        k = i;
        ans += k;
    }
    if (n) {
        ans += (n / 2) * 5 + (n % 2) * 3;
    }
    printf("%lld\n", ans);
    return 0;
}