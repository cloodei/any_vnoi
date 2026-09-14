#include <bits/stdc++.h>                                                                                                                                                                                                                                                                                             // 
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    vector<int> a(n + 1), pref(n + 2);
    pref[0] = 0;

    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      pref[i] = pref[i - 1] + a[i];
    }

    for (int i = 1; i <= n; ++i) {

    }
  }

  return 0;
}
