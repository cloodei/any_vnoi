#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    if (n < 5) {
      cout << -1 << '\n';
      continue;
    }
    for (int x = 6; x <= n; x += 2) cout << x << ' ';
    cout << 2 << ' ' << 4 << ' ' << 5 << ' ' << 1 << ' ' << 3;
    for (int x = 7; x <= n; x += 2) cout << ' ' << x;
    cout << '\n';
  }

  return 0;
}


// RESULTS
// Batch #1 (500/500 points)
// Case #1:	Accepted	[0.009s,	2.31 MB]
// Case #2:	Accepted	[0.045s,	2.31 MB]
// Case #3:	Accepted	[0.042s,	2.31 MB]
// Case #4:	Accepted	[0.049s,	2.22 MB]
// Case #5:	Accepted	[0.053s,	2.22 MB]
// Case #6:	Accepted	[0.055s,	2.21 MB]
// Case #7:	Accepted	[0.011s,	2.21 MB]
// Case #8:	Accepted	[0.053s,	2.21 MB]
// Case #9:	Accepted	[0.041s,	2.23 MB]
// Case #10:	Accepted	[0.044s,	2.23 MB]
// Case #11:	Accepted	[0.052s,	2.23 MB]
// Case #12:	Accepted	[0.046s,	2.23 MB]
// Case #13:	Accepted	[0.051s,	2.21 MB]
// Case #14:	Accepted	[0.046s,	2.32 MB]


// Resources: 0.055s, 2.32 MB
// Final score: 500/500 (0.200/0.200 points)
