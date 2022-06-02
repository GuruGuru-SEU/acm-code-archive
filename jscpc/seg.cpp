#include <iostream>
using namespace std;

const int N = 1e5 + 5;

struct SegmentTree {
  struct Node {
    int l, r;
    int sum, tag;
  } node[N << 2];
  int R, cnt;
#define lson(u) node[u].l
#define rson(u) node[u].r
#define sum(u) node[u].sum
#define tag(u) node[u].tag
  void build(int &u, int l, int r) {
    u = ++cnt;
    if (l == r) {
      return;
    }
    int mid = (l + r) >> 1;
    build(lson(u), l, mid);
    build(rson(u), mid + 1, r);
  }
  
  void modify(int u, int l, int r, int p, int x) {
    if (l == r) {
      sum(u) += x;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) modify(lson(u), l, mid, p, x);
    else modify(rson(u), mid + 1, r, p, x);
    sum(u) = sum(lson(u)) + sum(rson(u));
  }

  int query(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) 
      return sum(u);
    int mid = (l + r) >> 1, res = 0;
    if (ql <= mid) res += query(lson(u), l, mid, ql, qr);
    if (mid < qr) res += query(rson(u), mid + 1, r, ql, qr);
    return res;
  }
};

int main() {


  return 0;
}