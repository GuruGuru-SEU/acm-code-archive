#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int t, n, k;
std::map<int, int> lim;
std::vector<int> br, as;
long long ans = 0;

void work(int l, int r, std::vector<int> &src) {
    int len = src.size();
    std::vector<int> tgt;
    for (int i = l; i <= r; ++i) {
        if (lim[i] == 0) {
            while (tgt.size() < len) {
                tgt.push_back(i);
            }
        } else {
            int rem = lim[i];
            for (int j = 1; j <= rem; ++j) {
                if (tgt.size() < len)
                    tgt.push_back(i);
            }
        }
        if (tgt.size() == len) break;
    }
    // for (auto i : tgt) {
    //     std::cout << i << ' ';
    // }
    // std::cout << std::endl;
    for (int i = 0; i < len; ++i) {
        ans += 1ll * (src[i] - tgt[i]);
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        lim.clear(), as.clear(), br.clear();
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            int a;
            scanf("%d", &a);
            as.push_back(a);
        }
        for (int i = 1; i <= k; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            lim[x] = y;
            if (y == 0) br.push_back(x);
        }
        br.push_back(1e9 + 1);
        std::sort(br.begin(), br.end());
        std::sort(as.begin(), as.end());
        ans = 0;
        int l = 0, r = 0, pos = 0;
        for (auto b : br) {
            r = b - 1;
            std::vector<int> src;
            while (pos < as.size() && as[pos] <= r) {
                src.push_back(as[pos]);
                pos++;
            }
            work(l, r, src);
            l = b + 1;
        }
        if (ans & 1)
            puts("Pico");
        else
            puts("FuuFuu");
        std::cout << ans << std::endl;
    }

    return 0;
}