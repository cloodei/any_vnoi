#include <bits/stdc++.h>                                                                                                                                                                                                                                                                                                                                                                                  // https://oj.vnoi.info/problem/prefixsum_diff_b
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<long long>> a(n), sum(n + 1, vector<long long>(m + 1));

  for (int i = 1; i <= n; ++i) {
    a[i].reserve(m + 1);
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }

  return 0;
}
