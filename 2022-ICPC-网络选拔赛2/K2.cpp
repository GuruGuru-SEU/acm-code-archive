#include <iostream>
#include <vector>
typedef long long ll;

const ll MOD = 998244353;
const ll INV3 = 332748118;
const ll INV2 = 499122177;

using namespace std;

ll qpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int c[505][505][10], typ[505][505];
int vis[505][505];
int n;
pair<ll, ll> ans;

void paint(int x, int y, const vector<int> &vec) {
    for (auto v : vec)
        c[x + 200][y + 200][v] = 1;
}

void paint_all(int x, int y) {
    paint(x, y, {0, 1, 2, 3, 4, 5, 6, 7, 8});
}

void paint_square(int x, int y) {
    paint(x, y, {0, 1, 2, 3, 4, 5, 6, 7, 8});
    paint(x - 1, y, {0, 1, 2, 3, 4, 5, 6, 7, 8});
    paint(x, y - 1, {0, 1, 2, 3, 4, 5, 6, 7, 8});
    paint(x - 1, y - 1, {0, 1, 2, 3, 4, 5, 6, 7, 8});
}

void paint_circle(int x, int y) {
    paint(x, y, {0, 1, 3, 4, 5, 8});
    paint(x - 1, y, {0, 2, 3, 4, 7, 8});
    paint(x, y - 1, {0, 1, 2, 3, 5, 6});
    paint(x - 1, y - 1, {0, 1, 2, 4, 6, 7});
}

int get_type(int x, int y) {
    int &res = typ[x + 200][y + 200];
    if (res) return res;
    int cnt = 0;
    for (int v = 0; v < 9; ++v)
        cnt += c[x + 200][y + 200][v];
    if (cnt == 0)
        return res = 1;
    else if (cnt == 6) {
        if (!c[x + 200][y + 200][1]) return res = 2;
        if (!c[x + 200][y + 200][2]) return res = 3;
        if (!c[x + 200][y + 200][4]) return res = 4;
        if (!c[x + 200][y + 200][3]) return res = 5;
    } else if (cnt == 8) {
        if (!c[x + 200][y + 200][5]) return res = 6;
        if (!c[x + 200][y + 200][6]) return res = 7;
        if (!c[x + 200][y + 200][7]) return res = 8;
        if (!c[x + 200][y + 200][8]) return res = 9;
    }
    return res = 10;
}

bool can_left(int x, int y) {
    return !c[x + 200][y + 200][5] && !c[x - 1 + 200][y + 200][7];
}

bool can_right(int x, int y) {
    return !c[x + 200][y + 200][7] && !c[x + 1 + 200][y + 200][5];
}

bool can_up(int x, int y) {
    return !c[x + 200][y + 200][6] && !c[x + 200][y + 1 + 200][8];
}

bool can_down(int x, int y) {
    return !c[x + 200][y + 200][8] && !c[x + 200][y - 1 + 200][6];
}

pair<ll, ll> get_inner(int x, int y) {
    int t = get_type(x, y);
    if (t == 1)
        return {0, 0};
    else if (t == 2 || t == 3 || t == 4 || t == 5)
        return {0, INV2};
    else if (t == 10)
        return {0, 0};
    else
        return {0, INV3};
}

void update(pair<ll, ll> x) {
    ans.first = (ans.first + x.first + MOD) % MOD;
    ans.second = (ans.second + x.second + MOD) % MOD;
}

void dfs(int x, int y) {
    //    std::cout << x << ' ' << y << std::endl;
    vis[x + 200][y + 200] = 1;
    update(get_inner(x, y));
    // left
    if (can_left(x, y)) {
        if (!vis[x - 1 + 200][y + 200])
            dfs(x - 1, y);
    } else {
        if (!c[x + 200][y + 200][5])
            update({1, 0}); //, cout << x << ' ' << y << endl;
    }
    // right
    if (can_right(x, y)) {
        if (!vis[x + 1 + 200][y + 200])
            dfs(x + 1, y);
    } else {
        if (!c[x + 200][y + 200][7])
            update({1, 0});
    }
    // up
    if (can_up(x, y)) {
        if (!vis[x + 200][y + 1 + 200])
            dfs(x, y + 1);
    } else {
        if (!c[x + 200][y + 200][6])
            update({1, 0});
    }
    // down
    if (can_down(x, y)) {
        if (!vis[x + 200][y - 1 + 200])
            dfs(x, y - 1);
    } else {
        if (!c[x + 200][y + 200][8])
            update({1, 0});
    }
}

int main() {
    std::cout << 665496238ll * 6 % MOD;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1)
            paint_square(x, y);
        else
            paint_circle(x, y);
    }
    for (int x = -110; x <= 110; ++x) {
        int y = 111;
        paint_all(x, y);
        y = -111;
        paint_all(x, y);
    }
    for (int y = -110; y <= 110; ++y) {
        int x = 111;
        paint_all(x, y);
        x = -111;
        paint_all(x, y);
    }
    for (int x = -105; x <= 105; ++x) {
        for (int y = -105; y <= 105; ++y) {
            if (!vis[x + 200][y + 200] && get_type(x, y) != 10)
                dfs(x, y);
        }
    }
    update({-221 * 4, 0});
    printf("%lld %lld", ans.first, ans.second);
    return 0;
}

// -fno-tree-ch -O2 -Wall -pipe -std=c++17 -lm -Wl,stack=123456789