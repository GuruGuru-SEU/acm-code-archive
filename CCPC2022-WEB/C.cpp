#include <cctype>
#include <cstdio>

template <typename tn>
void fead(tn &n) {
    tn f = 1, t = 0, r = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) t = t * 10 + ch - '0', ch = getchar();
    if (ch == '.') {
        ch = getchar();
        while (isdigit(ch)) r *= 10;
        t += (ch - '0') / r, ch = getchar();
    }
    n = f * t;
}

template <typename tn, typename... T>
void fead(tn &n, T &...args) {
    fead(n);
    fead(args...);
}

int T, x, y, z;
long long a, b;
int main() {
    fead(T);
    while (T--) {
        fead(a);
        fead(b);
        x = 0;
        y = 0;
        while (a % 2 == 0) {
            x++;
            a /= 2;
        }
        while (b % 2 == 0) {
            y++;
            b /= 2;
        }
        if (x > y)
            z = x;
        else
            z = y;
        if (z % 2) {
            if (x < y)
                z++;
        } else {
            if (x > y)
                z++;
        }
        z++;
        printf("%d %d\n", z / 2, z % 2);
    }
    return 0;
}