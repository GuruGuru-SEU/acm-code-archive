//Author:rabbyte
#include <cstdio>
#include <cctype>

template <typename tn>void fead(tn &n) {
    tn f = 1, t = 0, r = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch)) t = t * 10 + ch - '0', ch = getchar();
    if (ch == '.') {ch = getchar(); while (isdigit(ch)) r *= 10, t += (ch - '0') / r, ch = getchar();}
    n = f * t;
}
template <typename tn, typename ... T>
void fead(tn &n, T& ... args) {fead(n); fead(args...);}

const long long key = 998244353;

const int N = 1e6 + 10;
long long mul_mod(long long a, long long b, long long p) {
    unsigned long long ans =
        (unsigned long long)a * b - (unsigned)((long double)a / p * b + 0.5L) * p;
    return (ans + p) % p;
}
long long exgcd(long long a, long long b, long long& x, long long& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    long long ans = exgcd(b, a % b, x, y);
    long long tmp = x;
    x = y; y = tmp - a / b * y;
    return ans;
}
long long inv_mod(long long a, long long p) {
    long long x, y;
    long long d = exgcd(a, p, x, y);
    return (d == 1) ? (x + p) % p : -1;
}
long long pow_mod(long long a, long long n, long long p) {
    a %= p;
    long long ans = 1LL;
    while (n) {
        if (n & 1) ans = mul_mod(ans, a, p);
        a = mul_mod(a, a, p);
        n >>= 1;
    }
    return ans;
}
long long inv_12n[N];
void get_inv_12n(int n, long long p) {
    inv_12n[1] = 1;
    for (int i = 2; i <= n; i++)
        inv_12n[i] = mul_mod((long long)(p - p / i), inv_12n[p % i], p);
}
long long factorials[N], inv_factorials[N];
void C_pre(int n, long long p) {
    factorials[0] = 1ll; inv_factorials[0] = 1ll;
    for (int i = 1; i <= n; i++)
        factorials[i] = mul_mod(factorials[i - 1], (long long) i, p);
    inv_factorials[n] = inv_mod(factorials[n], p);
    for (int i = n; i; i--)
        inv_factorials[i - 1] = mul_mod(inv_factorials[i], (long long) i, p);
}
long long C(long long n, long long m, long long p) {
    if (m > n) return 0;
    return mul_mod(factorials[n], mul_mod(inv_factorials[n - m], inv_factorials[m], p), p);
}
long long Lucas(long long n, long long m, long long p) {
    if (m == 0) return 1;
    return (C(n % p, m % p, p) * Lucas(n / p, m / p, p)) % p;
}
void exCRT(int n, long long * b, long long * a) {
    long long A = b[0], m = a[0];
    for (int i = 1; i < n; i++) {
        long long d, x, y, c = (b[i] - A % a[i] + a[i]) % a[i];
        d = exgcd(m, a[i], x, y);
        if (c % d) {
            A = -1;
            break;
        }
        x = mul_mod(x, c / d, a[i] / d);
        A += x * m;
        m *= a[i] / d;
        A = (A % m + m) % m;
    }
}
long long calc_Wilson(long long n, long long p, long long k) {
    if (n <= 1) return 1LL;
    long long ans = 1LL;
    if (n >= k) {
        for (long long i = 2; i < k; i++)
            if (i % p) ans = (ans * i) % k;
        ans = pow_mod(ans, n / k, k);
    }
    for (long long i = 2; i <= n % k; i++)
        if (i % p) ans = (ans * i) % k;
    return ans * calc_Wilson(n / p, p, k) % k;
}
long long Cpk(long long n, long long m, long long p, long long k) {
    long long tmp = 0;
    for (long long i = n; i; i /= p) tmp += i / p;
    for (long long i = m; i; i /= p) tmp -= i / p;
    for (long long i = n - m; i; i /= p) tmp -= i / p;
    return ((calc_Wilson(n, p, k) * inv_mod(calc_Wilson(m, p, k), k) % k)
            * inv_mod(calc_Wilson(n - m, p, k), k) % k) * pow_mod(p, tmp, k) % k;
}

long long n, m, k;

long long calc(long long n, long long m, long long k) {
    int opt = 1;
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = (ans + key + opt * mul_mod(C(n, i, key), C(n + m - 1 - i * k, n - 1, key), key)) % key;
        opt = -opt;
    }
    return ans;
}

int main() {
    fead(n, m, k);
    C_pre(n + m + k, key);
    if (!m) {puts("1"); return 0;}
    if (!n || n < m) {puts("0"); return 0;}
    printf("%lld\n", (calc(n - m + 1, m, k + 1) - calc(n - m + 1, m, k) + key) % key);
    return 0;
}
