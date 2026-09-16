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

    string s;
    cin >> s;

    const int n = s.length();
    vector<int> pi(n), found(n);

    int j = 0;
    for (int i = 1; i < n; ++i) {
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

    ll res = 0;
    found[0] = 1;

    for (int i = 1; i < n; ++i) {
        if (found[pi[i]])
            res += pi[i];
        else
            res += pi[pi[i] - 1];
        found[pi[i]] = 1;
    }

    cout << res;
    return 0;
}
