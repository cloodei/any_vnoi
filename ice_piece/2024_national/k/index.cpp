#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;
        if (a == b) {
            for (int i = 0; i < n - a + 1; ++i)
                if (s[i] == '0')
                    for (int j = i; j < i + a; ++j)
                        s[j] = (s[j] == '0' ? '1' : '0');
            
            bool go = true;
            for (int i = n - a; i < n; ++i) {
                if (s[i] == '0') {
                    go = false;
                    break;
                }
            }
            cout << (go ? "YES\n" : "NO\n");
            continue;
        }

        if (a * 2 <= n) {
            cout << "YES\n";
            continue;
        }

        bool go = true;
        for (int i = n - a; i < a - 1; ++i) {
            if (s[i] != s[i + 1]) {
                go = false;
                break;
            }
        }
        cout << (go ? "YES\n" : "NO\n");
    }


    return 0;
}
