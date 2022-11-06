#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

struct Point {
    int x, y;
    bool operator<(const Point &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
    bool operator!=(const Point &rhs) const {
        return *this < rhs || rhs < *this;
    }
    bool operator==(const Point &rhs) const {
        return !(*this != rhs);
    }
    void print() {
        printf("%d %d\n", x, y);
    }
};

Point operator-(Point A, Point B) {
    return {A.x - B.x, A.y - B.y};
}

int t, n;
Point p[100005];
bool tag[100005];

void print_ans(int a, int b, int c, int d, int e) {
    p[a].print();
    p[b].print();
    p[c].print();
    p[d].print();
    p[e].print();
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void uni(Point &a) {
    int g = gcd(std::abs(a.x), std::abs(a.y));
    a.x /= g;
    a.y /= g;
}

bool is_unique(Point a, Point b, Point c, Point d) {
    return a != b && a != c && a != d && b != c && b != d && c != d;
}

void work1() {
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= n; ++b) {
            for (int c = b + 1; c <= n; ++c) {
                for (int d = c + 1; d <= n; ++d) {
                    for (int e = d + 1; e <= n; ++e) {
                        if (b == a) continue;
                        if (c == a) continue;
                        if (d == a) continue;
                        if (e == a) continue;
                        Point v1 = p[b] - p[a];
                        uni(v1);
                        Point v2 = p[c] - p[a];
                        uni(v2);
                        Point v3 = p[d] - p[a];
                        uni(v3);
                        Point v4 = p[e] - p[a];
                        uni(v4);
                        if (is_unique(v1, v2, v3, v4)) {
                            puts("YES");
                            print_ans(a, b, c, d, e);
                            return;
                        }
                    }
                }
            }
        }
    }
    puts("NO");
}

void work2() {
    std::sort(p + 1, p + n + 1);
    std::map<Point, int> cnt;
    std::vector<int> ans;
    Point mxv = {0, 0};
    int dirs = 0;
    for (int i = 2; i <= n; ++i) {
        Point v = p[i] - p[1];
        uni(v);
        if (cnt[v] == 0) {
            ++dirs;
            ans.push_back(i);
        }
        cnt[v] += 1;
        if (cnt[v] > cnt[mxv]) mxv = v;
    }
    if (dirs == 1) {
        puts("NO");
        return;
    } else if (dirs < 4) {
        tag[1] = true;
        for (int i = 2; i <= n; ++i) {
            Point v = p[i] - p[1];
            uni(v);
            if (v == mxv) tag[i] = true;
        }
        puts("YES");
        for (int i = 1; i <= n; ++i) {
            if (tag[i] == false) {
                p[i].print();
                break;
            }
        }
        int len = 0;
        for (int i = 1; i <= n; ++i) {
            if (tag[i] == true) {
                p[i].print();
                len++;
                if (len == 4) break;
            }
        }
    } else {
        puts("YES");
        print_ans(1, ans[0], ans[1], ans[2], ans[3]);
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &p[i].x, &p[i].y);
            tag[i] = false;
        }
        if (n < 5) {
            puts("NO");
        } else if (n <= 20) {
            work1();
        } else {
            work2();
        }
    }
    return 0;
}