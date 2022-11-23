#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int p[16], cnt;

void assign(const std::vector<int> &vec) {
    for (int i = 0; i < 4; ++i) {
        int b = i * 3 + 1;
        if (vec[i] <= 9) {
            p[b] = p[b + 1] = p[b + 2] = vec[i];
        } else {
            p[b] = vec[i] - 9, p[b + 1] = vec[i] - 8, p[b + 2] = vec[i] - 7;
        }
    }
    p[13] = p[14] = vec[4];
}

bool check() {
    int cnt[10];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= 14; ++i) {
        cnt[p[i]]++;
        if (cnt[p[i]] > 4) return 0;
    }
    return 1;
}

long long get_hash() {
    std::vector<int> vec;
    for (int i = 1; i <= 14; ++i) {
        if (p[i] == 0) continue;
        vec.push_back(p[i]);
    }
    std::sort(vec.begin(), vec.end());
    long long res = 0;
    for (int x : vec) {
        res = res * 10 + x;
    }
    return res;
}

std::map<long long, int> mp;
std::map<long long, int> used;

int get_cnt(int hash) {
    if (mp[hash])
        return mp[hash];
    else {
        mp[hash] = ++cnt;
        return cnt;
    }
}

long long ans[5000005];
std::set<int> s[5000005];

void work() {
    long long big_hash = get_hash();
    if (used[big_hash]) return;
    used[big_hash] = 1;
    for (int i = 1; i <= 14; ++i) {
        int tmp = p[i];
        p[i] = 0;
        long long hash = get_hash();
        int c = get_cnt(hash);
        ans[c] = hash;
        s[c].insert(tmp);
        p[i] = tmp;
    }
}

std::map<long long, long long> submit;

int main() {
    for (int a = 1; a <= 16; ++a) {
        for (int b = 1; b <= 16; ++b) {
            for (int c = 1; c <= 16; ++c) {
                for (int d = 1; d <= 16; ++d) {
                    for (int e = 1; e <= 9; ++e) {
                        assign({a, b, c, d, e});
                        if (!check()) continue;
                        work();
                    }
                }
            }
        }
    }
    for (int i = 1; i <= cnt; ++i) {
        int ans_hash = 0;
        for (auto x : s[i]) {
            ans_hash = ans_hash * 10 + x;
        }
        submit[ans_hash] = ans[i];
    }
    submit[0] = 3677788889999ll;
    int t;
    scanf("%d", &t);
    while (t--) {
        long long x;
        scanf("%lld", &x);
        long long y = submit[x];
        if (y == 0)
            puts("impossible");
        else
            printf("%lld\n", y);
    }
    return 0;
}