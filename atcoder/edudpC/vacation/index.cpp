#include <iostream>                                                                                                                                                                                                                                                                                                                                 // https://oj.vnoi.info/problem/atcoder_dp_c
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

int dp[100][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a;
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b;
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c;
    }

    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]);
    return 0;
}



// AC
