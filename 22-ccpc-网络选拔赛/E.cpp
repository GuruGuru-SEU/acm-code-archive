#include <cctype>
#include <iostream>
#include <vector>

int T, lenS, lenT;
std::string s, t, tmp;
std::vector<std::string> v;
int f[200010], g[200010], nxt[200010];

int main() {
    std::cin >> T;
    while (T--) {
        std::cin >> s >> t;
        lenS = s.length();
        lenT = t.length();
        v.clear();
        tmp.clear();
        for (int i = 0; i < lenS; i++) f[i] = 0;
        for (char ch : t) {
            if (isupper(ch)) {
                if (!tmp.empty()) {
                    v.push_back(tmp);
                    tmp.clear();
                }
                tmp = ch;
                v.push_back(tmp);
                tmp.clear();
            } else
                tmp += ch;
        }
        if (!tmp.empty()) {
            v.push_back(tmp);
            tmp.clear();
        }
        bool first_case = true;
        for (auto ss : v)
            if (isupper(ss[0])) {
                int len = 0;
                for (int i = 0; i < lenS; i++) g[i] = f[i];
                for (int i = 0; i < lenS; i++) {
                    if (s[i] == tolower(ss[0])) {
                        if ((i && g[i - 1]) || first_case) {
                            if (i)
                                len = g[i - 1] + 1;
                            else
                                len = 1;
                        }
                    } else
                        len = 0;
                    if (len > g[i]) g[i] = len;
                }
                for (int i = 0; i < lenS; i++) f[i] = g[i];
            } else {
                nxt[0] = -1;
                int lenSS = ss.length(), p = -1;
                for (int i = 0; i < lenS; i++) g[i] = 0;
                for (int i = 1; i < lenSS; i++) {
                    while (p == lenSS - 1 || (p >= 0 && ss[p + 1] != ss[i])) p = nxt[p];
                    if (ss[p + 1] == ss[i]) p++;
                    nxt[i] = p;
                }

                p = -1;
                for (int i = 0; i < lenS; i++) {
                    while (p >= 0 && ss[p + 1] != s[i]) p = nxt[p];
                    if (ss[p + 1] == s[i]) p++;
                    if (p == lenSS - 1) {
                        if (i >= lenSS && f[i - lenSS] && f[i - lenSS] + lenSS > g[i])
                            g[i] = f[i - lenSS] + lenSS;
                        if (first_case && g[i] < lenSS) g[i] = lenSS;
                        p = nxt[p];
                    }
                }
                first_case = false;
                for (int i = 0; i < lenS; i++) f[i] = g[i];
            }
        int ans = 0;
        for (int i = 0; i < lenS; i++)
            if (ans < f[i]) ans = f[i];
        printf("%d\n", ans);
    }
    return 0;
}