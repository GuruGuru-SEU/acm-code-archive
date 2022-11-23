#include <algorithm>
#include <iostream>
#include <set>
#include <string>

std::set<std::string> s[6], ss[6], sss[6];
std::string A, B, C, D, E;
int n, m, cnt = 0, ans = 0;

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> A >> B >> C >> D >> E;
        s[1].insert(A);
        s[2].insert(B);
        s[3].insert(C);
        s[4].insert(D);
        s[5].insert(E);
    }

    std::cin >> m;
    for (int i = 1; i <= m; i++) {
        int tmp;
        std::cin >> A >> tmp;
        if (tmp == 1) {
            if (s[1].find(A) == s[1].end())
                ss[1].insert(A);
            else
                sss[1].insert(A);
        }
        if (tmp == 2) {
            if (s[2].find(A) == s[2].end())
                ss[2].insert(A);
            else
                sss[2].insert(A);
        }
        if (tmp == 3) {
            if (s[3].find(A) == s[3].end())
                ss[3].insert(A);
            else
                sss[3].insert(A);
        }
        if (tmp == 4) {
            if (s[4].find(A) == s[4].end())
                ss[4].insert(A);
            else
                sss[4].insert(A);
        }
        if (tmp == 5) {
            if (s[5].find(A) == s[5].end())
                ss[5].insert(A);
            else
                sss[5].insert(A);
        }
    }

    for (int i = 1; i <= 5; i++) {
        ans += sss[i].size();
    }

    for (int i = 1; i <= 5; i++) {
        if (ans > sss[i].size() + ss[i].size()) ans = sss[i].size() + ss[i].size();
    }

    std::cout << ans << std::endl;

    return 0;
}