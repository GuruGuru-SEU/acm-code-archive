#include <cstdio>
#include <cstring>

const long long key = 998244353ll;

long long f[2000010][10], n, q, x, a, b, p, u[2000010], v[2000010], ans = 0;
char st[2000010];

long long calc_pc(int u, int v) {
    return (f[v][6] - f[u - 1][6] - f[u - 1][2] * (f[v][3] - f[u - 1][3]) % key + key) % key;
}

long long calc_cpc(int u, int v) {
    return ((f[v][8] - f[u - 1][8] - f[u - 1][5] * (f[v][3] - f[u - 1][3]) % key - f[u - 1][1] * calc_pc(u, v) % key) % key + key) % key;
}

long long calc_4(int u, int v) {
    return ((f[v][9] - f[u - 1][9] - f[u - 1][7] * (f[v][3] - f[u - 1][3]) % key - f[u - 1][4] * calc_pc(u, v) % key - f[u - 1][0] * calc_cpc(u, v) % key) % key + key) % key;
}

int main() {
    scanf("%lld%lld", &n, &q);
    scanf("%s", st + 1);
    for (int i = 1; i <= n; i++) {
        f[i][0] = (f[i - 1][0] + (st[i] == 'I' ? 1 : 0)) % key;
        f[i][1] = (f[i - 1][1] + (st[i] == 'C' ? 1 : 0)) % key;
        f[i][2] = (f[i - 1][2] + (st[i] == 'P' ? 1 : 0)) % key;
        f[i][3] = (f[i - 1][3] + (st[i] == 'C' ? 1 : 0)) % key;
        f[i][4] = (f[i - 1][4] + (st[i] == 'C' ? 1 : 0) * f[i - 1][0]) % key;
        f[i][5] = (f[i - 1][5] + (st[i] == 'P' ? 1 : 0) * f[i - 1][1]) % key;
        f[i][6] = (f[i - 1][6] + (st[i] == 'C' ? 1 : 0) * f[i - 1][2]) % key;
        f[i][7] = (f[i - 1][7] + (st[i] == 'P' ? 1 : 0) * f[i - 1][4]) % key;
        f[i][8] = (f[i - 1][8] + (st[i] == 'C' ? 1 : 0) * f[i - 1][5]) % key;
        f[i][9] = (f[i - 1][9] + (st[i] == 'C' ? 1 : 0) * f[i - 1][7]) % key;
    }
    scanf("%lld%lld%lld%lld", &x, &a, &b, &p);
    for (int i = 1; i <= q; i++) {
        x = (a * x + b) % p;
        u[i] = (x % n) + 1;
    }
    for (int i = 1; i <= q; i++) {
        x = (a * x + b) % p;
        v[i] = (x % n) + 1;
    }
    for (int i = 1; i <= q; i++) {
        if (u[i] > v[i])
            ans = (ans + calc_4(v[i], u[i])) % key;
        else
            ans = (ans + calc_4(u[i], v[i])) % key;
    }
    printf("%lld\n", ans);
    return 0;
}