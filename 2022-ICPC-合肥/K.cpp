#include <iostream>
#include <tuple>

const int M = 1e5 + 5;

struct my_tuple {
    int mx0, mxl, mxr;
};

struct SegmentTree {
    struct Node {
        int l, r;
        int mx0, mxl, mxr;
        int sum;
        int tag;
    } node[5000000 + 5];
#define lson(u) node[u].l
#define rson(u) node[u].r
#define mx0(u) node[u].mx0
#define mxl(u) node[u].mxl
#define mxr(u) node[u].mxr
#define sum(u) node[u].sum
#define tag(u) node[u].tag
    int R, cnt;
    void build(int &u) {
        u = ++cnt;
        mx0(u) = mxl(u) = mxr(u) = sum(u) = 0;
        tag(u) = -1;
    }
    void pushdown(int u, int l, int r) {
        if (tag(u) == -1) return;
        int mid = (l + r) >> 1;
        int llen = mid - l + 1, rlen = r - mid;
        if (lson(u) == 0) lson(u) = ++cnt;
        if (rson(u) == 0) rson(u) = ++cnt;
        if (tag(u) == 1) {
            mx0(lson(u)) = mxl(lson(u)) = mxr(lson(u)) = sum(lson(u)) = llen;
            tag(lson(u)) = tag(u);
            mx0(rson(u)) = mxl(rson(u)) = mxr(rson(u)) = sum(rson(u)) = rlen;
            tag(rson(u)) = tag(u);
        } else {
            mx0(lson(u)) = mxl(lson(u)) = mxr(lson(u)) = sum(lson(u)) = 0;
            tag(lson(u)) = tag(u);
            mx0(rson(u)) = mxl(rson(u)) = mxr(rson(u)) = sum(rson(u)) = 0;
            tag(rson(u)) = tag(u);
        }
        tag(u) = -1;
    }
    void pushup(int u, int l, int r) {
        int mid = (l + r) >> 1;
        int llen = mid - l + 1, rlen = r - mid;
        if (lson(u) == 0 && rson(u) == 0) return;
        if (lson(u) == 0) {
            mx0(u) = mx0(rson(u));
            mxl(u) = 0;
            mxr(u) = mxr(rson(u));
            sum(u) = sum(rson(u));
        } else if (rson(u) == 0) {
            mx0(u) = mx0(lson(u));
            mxl(u) = mxl(lson(u));
            mxr(u) = 0;
            sum(u) = sum(lson(u));
        } else {
            mx0(u) = std::max(std::max(mx0(lson(u)), mx0(rson(u))), mxr(lson(u)) + mxl(rson(u)));
            mxl(u) = sum(lson(u)) == llen ? llen + mxl(rson(u)) : mxl(lson(u));
            mxr(u) = sum(rson(u)) == rlen ? rlen + mxr(lson(u)) : mxr(rson(u));
            sum(u) = sum(lson(u)) + sum(rson(u));
        }
    }
    void modify(int &u, int l, int r, int ql, int qr, int val) {
        if (u == 0) {
            u = ++cnt;
            mx0(u) = mxl(u) = mxr(u) = sum(u) = 0;
            tag(u) = -1;
        }
        if (ql <= l && r <= qr) {
            if (val == 1) {
                mx0(u) = mxl(u) = mxr(u) = sum(u) = r - l + 1;
                tag(u) = 1;
            } else {
                mx0(u) = mxl(u) = mxr(u) = sum(u) = 0;
                tag(u) = 0;
            }
            return;
        }
        pushdown(u, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) modify(lson(u), l, mid, ql, qr, val);
        if (mid < qr) modify(rson(u), mid + 1, r, ql, qr, val);
        pushup(u, l, r);
    }
    int query_sum(int &u, int l, int r, int ql, int qr) {
        if (u == 0) {
            u = ++cnt;
            mx0(u) = mxl(u) = mxr(u) = sum(u) = 0;
            tag(u) = -1;
        }
        if (ql <= l && r <= qr) {
            return sum(u);
        }
        pushdown(u, l, r);
        int mid = (l + r) >> 1, res = 0;
        if (ql <= mid) res += query_sum(lson(u), l, mid, ql, qr);
        if (mid < qr) res += query_sum(rson(u), mid + 1, r, ql, qr);
        return res;
    }
    my_tuple query_conseq(int &u, int l, int r, int ql, int qr) {
        if (u == 0) {
            u = ++cnt;
            mx0(u) = mxl(u) = mxr(u) = sum(u) = 0;
            tag(u) = -1;
        }
        if (ql <= l && r <= qr) {
            return {mx0(u), mxl(u), mxr(u)};
        }
        pushdown(u, l, r);
        int mid = (l + r) >> 1;
        int llen = mid - l + 1, rlen = r - mid;
        my_tuple lres{0, 0, 0}, rres{0, 0, 0}, res{0, 0, 0};
        if (ql <= mid) lres = query_conseq(lson(u), l, mid, ql, qr);
        if (mid < qr) rres = query_conseq(rson(u), mid + 1, r, ql, qr);
        res.mx0 = std::max(std::max(lres.mx0, rres.mx0), lres.mxr + rres.mxl);
        res.mxl = lres.mx0 == llen ? llen + rres.mxl : lres.mxl;
        res.mxr = rres.mx0 == rlen ? rlen + lres.mxr : rres.mxr;
        return res;
    }

} TV, TQ;

int n, m;
int op, l, r, p, A;

int main() {
    scanf("%d%d", &n, &m);
    TV.build(TV.R), TQ.build(TQ.R);
    while (m--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d", &l, &r);
            l = std::max(l - A, 1);
            r = std::min(r + A, n);
            TV.modify(TV.R, 1, n, l, r, 1);
        } else if (op == 2) {
            scanf("%d%d%d", &l, &r, &p);
            l = std::max(l - A, 1);
            r = std::min(r + A, n);
            auto res = TV.query_conseq(TV.R, 1, n, l, r);
            if (res.mx0 >= p) {
                TQ.modify(TQ.R, 1, n, l, r, 1);
            }
        } else if (op == 3) {
            scanf("%d%d", &l, &r);
            l = std::max(l - A, 1);
            r = std::min(r + A, n);
            TV.modify(TV.R, 1, n, l, r, 0);
            TQ.modify(TQ.R, 1, n, l, r, 0);
        } else {
            scanf("%d%d", &l, &r);
            l = std::max(l - A, 1);
            r = std::min(r + A, n);
            int ans = TQ.query_sum(TQ.R, 1, n, l, r);
            printf("%d\n", ans);
            A = ans;
        }
    }
    return 0;
}