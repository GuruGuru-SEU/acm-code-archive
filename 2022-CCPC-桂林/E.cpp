#include <iostream>

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

long long T, x_1, y_1, x_2, y_2, a, b, x, y, d;

int main() {
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld%lld%lld", &x_1, &y_1, &x_2, &y_2);
        a = x_2 - x_1;
        b = y_1 - y_2;
        if (a == 0) {
            printf("%lld %lld\n", x_1 + 1, y_1);
            continue;
        }
        if (b == 0) {
            printf("%lld %lld\n", x_1, y_1 + 1);
            continue;
        }
        d = exgcd(a, b, x, y);
        printf("%lld %lld\n", x_1 + y, y_1 + x);
    }
    return 0;
}