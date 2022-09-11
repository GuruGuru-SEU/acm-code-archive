#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
const int N = 5e4 + 5;

using namespace std;

string s[N];
bool is_inf = false;

struct Trie {
    int ch[N][30];
    int val[N], last[N], f[N], vis[N];
    int sz;
    Trie() {
        sz = 1;
        f[0] = 0;
        memset(ch[0], 0, sizeof ch[0]);
    }
    int idx(char c) {
        return c - 'a';
    }

    void insert(string s, int v) {
        int u = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof ch[sz]);
                val[sz] = 0;
                f[sz] = -1;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }
    void getFail() {
        queue<int> q;
        f[0] = 0;
        for (int c = 0; c < 30; c++) {
            int u = ch[0][c];
            if (u) {
                f[u] = 0;
                q.push(u);
                last[u] = 0;
            }
        }
        while (!q.empty()) {
            int r = q.front();
            q.pop();
            for (int c = 0; c < 30; c++) {
                int u = ch[r][c];
                if (!u) continue;
                q.push(u);
                int v = f[r];
                while (v && !ch[v][c]) v = f[v];
                f[u] = ch[v][c];
                last[u] = val[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
    void work(string S) {
        for (int u = 0; u < sz; u++)
            vis[u] = false;
        for (int u = 0; u < sz; u++) {
            int p = 0;
            vis[u] = true;
            if (!vis[u]) break;
            int lenS = S.length();
            for (int i = 0; i < 26; i++)
                if (ch[u][S[p] - 'a'] && !vis[ch[u][S[p] - 'a']]) {
                    if (f[u] >= 0 && f[ch[u][S[p] - 'a']] < f[u] + 1) f[ch[u][S[p] - 'a']] = f[u] + 1;
                    p++;
                    if (p == lenS) {
                        if (val[u]) {
                            is_inf = true;
                            break;
                        }
                        break;
                    }
                    if (val[u]) u = 0;
                    u = ch[u][S[p] - 'a'];
                    vis[u] = true;
                } else
                    break;
        }
    }

    int find(string T) {
        int n = T.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            int c = idx(T[i]);
            while (j && !ch[j][c]) j = f[j];
            j = ch[j][c];
            if (val[j])
                printf("%d %d\n");
            else if (last[j])
                printf("%d %d\n", i, last[j]);
        }
    }
} T;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        T.insert(s[i], 1);
        reverse(s[i].begin(), s[i].end());
    }
    for (int i = 0; i < n; i++)
        T.work(s[i]);
    int ans = 0;
    for (int i = 0; i < T.sz; i++)
        if (ans < T.f[i]) ans = T.f[i];
    if (is_inf)
        puts("INF");
    else
        printf("%d\n", ans);
    return 0;
}