#include <iostream>

long long x[28][28];

struct Trie {
    struct Node {
        int sum;
        int ch[28];
    } node[9000005];
#define sum(u) node[u].sum
#define ch(u, i) node[u].ch[i]
    int R, cnt;
    void build() {
        R = ++cnt;
    }
    void insert(std::string s) {
        int u = R;
        sum(u)++;
        s = s + "#";
        for (char c : s) {
            int d = c - 'a' + 1;
            if (c == '#') d = 0;
            if (!ch(u, d)) ch(u, d) = ++cnt;
            for (int i = 0; i <= 26; ++i) {
                if (i == d) continue;
                if (!ch(u, i)) continue;
                x[i][d] += 1ll * sum(ch(u, i));
            }
            u = ch(u, d);
            sum(u)++;
        }
    }
} T;

int n, q;
std::string s;
int a[30];

int main() {
    std::cin.tie(0);
    std::cin >> n >> q;
    T.build();
    for (int i = 1; i <= n; ++i) {
        std::cin >> s;
        T.insert(s);
    }
    while (q--) {
        std::cin >> s;
        a[1] = 0;
        for (int i = 2; i <= 27; ++i)
            a[i] = s[i - 2] - 'a' + 1;
        long long tot = 0;
        for (int i = 27; i >= 2; i--)
            for (int j = i - 1; j; j--)
                tot += x[a[i]][a[j]];
        std::cout << tot << '\n';
    }

    return 0;
}