#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        int counta = 0, countb = 0;
        for (int i = 0; i < n; ++i) {
            counta += (i & 1 ? a[i] - '0' : '0' - a[i]);
            countb += (i & 1 ? b[i] - '0' : '0' - b[i]);
        }

        if (counta == countb)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
