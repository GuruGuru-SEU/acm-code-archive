#include <cstring>
#include <iostream>

int lx[] = {2, 1, 0, 1, 2};
int rx[] = {6, 7, 8, 7, 6};

int dx[] = {1, 2, 1, -1, -2, -1};
int dy[] = {1, 0, -1, -1, 0, 1};

void int_to_map(int s, int mp[][5]) {
    int cnt = 0;
    for (int y = 0; y < 5; ++y) {
        for (int x = lx[y]; x <= rx[y]; x += 2) {
            mp[x][y] = (s & (1 << cnt)) ? 1 : 0;
            cnt++;
        }
    }
}

void flip(int mp[][5], int x, int y) {
    mp[x][y] ^= 1;
}

int map_to_int(int mp[][5]) {
    int cnt = 0, res = 0;
    for (int y = 0; y < 5; ++y) {
        for (int x = lx[y]; x <= rx[y]; x += 2) {
            if (mp[x][y])
                res |= (1 << cnt);
            cnt++;
        }
    }
    return res;
}

bool in_range(int x, int y) {
    if (y < 0 || y > 4) return false;
    return lx[y] <= x && x <= rx[y];
}

int f[5000005], w[9][5];

int dfs(int s) {
    if (s == 0) return 0;
    int &res = f[s];
    if (res != -1) return res;
    res = 0;
    int mp[9][5];
    int_to_map(s, mp);
    for (int y = 0; y < 5; ++y) {
        for (int x = lx[y]; x <= rx[y]; x += 2) {
            if (mp[x][y] == 0) continue;
            for (int i = 0; i < 6; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                int nnx = x + 2 * dx[i], nny = y + 2 * dy[i];
                if (!in_range(nnx, nny)) continue;
                if (mp[nx][ny] == 0) continue;
                if (mp[nnx][nny] == 1) continue;
                flip(mp, x, y), flip(mp, nx, ny), flip(mp, nnx, nny);
                res = std::max(res, dfs(map_to_int(mp)) + w[nx][ny]);
                flip(mp, x, y), flip(mp, nx, ny), flip(mp, nnx, nny);
            }
            flip(mp, x, y);
            res = std::max(res, dfs(map_to_int(mp)));
            flip(mp, x, y);
        }
    }
    return res;
}

int main() {
    memset(f, -1, sizeof(f));
    for (int y = 4; y >= 0; --y) {
        for (int x = lx[y]; x <= rx[y]; x += 2) {
            scanf("%d", &w[x][y]);
        }
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int mp[9][5];
        for (int y = 4; y >= 0; --y) {
            getchar();
            for (int x = lx[y]; x <= rx[y]; x += 2) {
                char c;
                scanf("%c", &c);
                mp[x][y] = c == '.' ? 0 : 1;
                // std::cout << x << ' ' << y << std::endl;
            }
        }
        printf("%d\n", dfs(map_to_int(mp)));
    }
    return 0;
}