#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

ll a[512][512], n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j)
            cin >> a[i][j];

    ll maxsum = -25000000000000000;
    for (ll i = 0; i < m; ++i) {
        vector<ll> temp(n);

        for (ll j = i; j < m; ++j) {
            for (ll k = 0; k < n; ++k)
                temp[k] += a[k][j];

            ll curr = temp[0], sum = temp[0];
            for (ll k = 1; k < n; ++k) {
                curr = max(curr + temp[k], temp[k]);
                sum  = max(sum, curr);
            }

            maxsum = max(maxsum, sum);
        }
    }

    cout << maxsum;
    return 0;
}



// AC
