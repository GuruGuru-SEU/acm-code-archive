#include <iostream>
#include <map>
#include <string>

std::map<std::string, bool> vis;

int t, n;
std::string s;

int main() {
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        bool flag = false;
        for (int i = 1; i <= n; ++i) {
            std::cin >> s;
            if (s.find("bie") != s.npos) {
                flag = true;
                if (vis[s]) continue;
                vis[s] = true;
                std::cout << s << '\n';
            }
        }
        if (flag == false) {
            std::cout
                << "Time to play Genshin Impact, Teacher Rice!\n";
        }
    }

    return 0;
}