#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

constexpr int thing = 45000;
int squares[thing + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= thing; ++i)
        squares[i] = i * i;

    int t, a;
    cin >> t;
    while (t--) {
        cin >> a;
        if (a < 0) {
            cout << -a << " " << -a << "\n";
            continue;
        }
        int nextsquare = *(upper_bound(squares, squares + thing, a + 1));
        cout << "1 " << nextsquare - a - 1 << "\n";
    }

    return 0;
}
