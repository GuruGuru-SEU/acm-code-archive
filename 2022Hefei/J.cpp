#include <cstdio>
#include <iostream>

long long n, a, b, c[1000010], d[1000010], p = 0, q = 0, tp, tq, sumd, sumc;
bool is_ans = true;

bool in_seg(long long a, long long b, long long x) {
    return a <= x && x <= b;
}

int main() {
    scanf("%lld%lld%lld", &n, &a, &b);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", d + i);
        sumd += d[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", c + i);
        sumc += c[i];
    }
    if (a && b) {
        for (int i = 1; i <= n; i++) {
            tp = p;
            p = -1;
            tq = q;
            q = -1;
            long long dr = d[i];
            long long dl = (dr + a - 1ll) / a;
            long long cr = c[i];
            long long cl = (cr + b - 1ll) / b;
            // C .. D
            long long gp = std::min(dr, cr);
            long long pd, qc;
            if (in_seg(dl, dr, gp) && in_seg(cl, cr, gp)) {
                if ((gp - 1) * a + 1 >= d[i])
                    pd = 1;
                else
                    pd = d[i] - (gp - 1) * a;
                if ((gp - 1) * b + 1 >= c[i])
                    qc = 1;
                else
                    qc = c[i] - (gp - 1) * b;
                if (tp >= 0 && (p == -1 || p > pd)) p = pd;
                if (tq >= 0 && (q == -1 || q > qc)) q = qc;
                if (tp >= 0 && tp + pd <= a && (q == -1 || q > qc)) q = qc;
                if (tq >= 0 && tq + qc <= b && (p == -1 || p > pd)) p = pd;
            }
            // D .. D
            gp = std::min(dr, cr + 1);
            if (in_seg(dl, dr, gp) && in_seg(cl + 1, cr + 1, gp)) {
                if ((gp - 2) * a + 2 >= d[i])
                    pd = 2;
                else
                    pd = d[i] - (gp - 2) * a;
                if (tp >= 0 && tp + pd - a <= a && (p == -1 || std::max(tp + pd - a, 1ll) < p)) p = std::max(tp + pd - a, 1ll);
                if (tq >= 0 && (p == -1 || std::max(pd - a, 1ll) < p)) p = std::max(pd - a, 1ll);
            }
            // C .. C
            gp = std::min(dr + 1, cr);
            if (in_seg(dl + 1, dr + 1, gp) && in_seg(cl, cr, gp)) {
                if ((gp - 2) * b + 2 >= c[i])
                    qc = 2;
                else
                    qc = c[i] - (gp - 2) * b;
                if (tq >= 0 && tq + qc - b <= b && (q == -1 || std::max(tq + qc - b, 1ll) < q)) q = std::max(tq + qc - b, 1ll);
                if (tq >= 0 && (q == -1 || std::max(qc - b, 1ll) < q)) q = std::max(qc - b, 1ll);
            }
            if (p < 0 && q < 0) is_ans = false;
        }
    } else {
        if (sumd > a || sumc > b) is_ans = false;
    }
    puts(is_ans ? "1" : "0");
    return 0;
}