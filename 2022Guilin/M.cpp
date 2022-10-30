#include <iostream>

const int N = 3e5 + 5;
const int M = 6e5 + 5;

long long c[N];
int p[N];
int n, m;
char ops[M];

void modify(int p, long long val) {
    for (; p <= n; p += p & (-p)) {
        c[p] += val;
    }
}

long long query(int p) {
    int res = 0;
    for (; p > 0; p -= p & (-p)) {
        res += c[p];
    }
    return res;
}

long long cur = 0, all = 0;
int flag = 0;
int q[3000005], l, r;

void shift(int val) {
    cur -= 1ll * (val - 1);
    cur += 1ll * (n - val);
}

int main() {
    scanf("%d%d", &n, &m);
    all = 1ll * n * (n - 1) / 2;
    l = 1000000, r = 1000000 - 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
        q[++r] = p[i];
    }
    for (int i = n; i >= 1; --i) {
        cur += 1ll * query(p[i]);
        modify(p[i], 1);
    }
    scanf("%s", ops + 1);
    printf("%lld\n", cur);
    for (int i = 1; i <= m; ++i) {
        if (ops[i] == 'S') {
            if (flag == 0) {
                shift(q[l]);
                q[++r] = q[l++];
            } else {
                shift(q[r]);
                q[--l] = q[r--];
            }
        } else {
            cur = all - cur;
            flag ^= 1;
        }
        printf("%lld", cur % 10);
    }
    return 0;
}