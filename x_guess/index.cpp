#include <bits/stdc++.h>                                                                                                                                                                                                                                                                                                                                                                                          // https://oj.vnoi.info/problem/interactive_findn
using namespace std;

size_t largest_exponent_under_mil(size_t base) {
  size_t res = base;
  while (true) {
    size_t next = res * base;
    if (next > 1'000'000)
      break;
    res = next;
  }
  
  return res;
}

bool primes[1'000'001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(primes, true, 1'000'001);
  
  for (size_t i = 2; i <= 1'000'000; i++)
    if (primes[i])
      for (size_t j = i * i; j <= 1'000'000; j += i)
        primes[j] = false;

  size_t res = 1, some = 1, idx = 0;
  for (size_t i = 2; i <= 1'000'000; i++) {
    if (!primes[i])
      continue;

    size_t exp = largest_exponent_under_mil(i);
    if (some > 1'000'000'000'000'000'000ULL / exp) {
      cout << "ucln " << some << endl;
      cin >> idx;
      res *= idx;
      some = 1;
    }
    some *= exp;
  }

  if (some > 1) {
    cout << "ucln " << some << endl;
    cin >> idx;
    res *= idx;
  }
  cout << "traloi " << res << endl;
  return 0;
}




/// RESULTS
// Execution Results
//  ×50
// Test case #1:	Accepted	[0.702s,	4.23 MB]	(2/2)
// Judge feedback
// ok OK
// Test case #2:	Accepted	[0.759s,	4.28 MB]	(2/2)
// Judge feedback
// ok OK
// Test case #3:	Accepted	[0.642s,	4.36 MB]	(2/2)
// Judge feedback
// ok OK
// Test case #4:	Accepted	[0.666s,	4.31 MB]	(2/2)
// Test case #5:	Accepted	[0.654s,	4.27 MB]	(2/2)
// Test case #6:	Accepted	[0.613s,	4.32 MB]	(2/2)
// Test case #7:	Accepted	[0.639s,	4.21 MB]	(2/2)
// Test case #8:	Accepted	[0.670s,	4.21 MB]	(2/2)
// Test case #9:	Accepted	[0.654s,	4.24 MB]	(2/2)
// Test case #10:	Accepted	[0.847s,	4.34 MB]	(2/2)
// Test case #11:	Accepted	[0.663s,	4.21 MB]	(2/2)
// Test case #12:	Accepted	[0.642s,	4.30 MB]	(2/2)
// Test case #13:	Accepted	[0.861s,	4.21 MB]	(2/2)
// Test case #14:	Accepted	[0.955s,	4.27 MB]	(2/2)
// Test case #15:	Accepted	[0.936s,	4.32 MB]	(2/2)
// Test case #16:	Accepted	[0.637s,	4.34 MB]	(2/2)
// Test case #17:	Accepted	[0.705s,	4.31 MB]	(2/2)
// Test case #18:	Accepted	[0.674s,	4.29 MB]	(2/2)
// Test case #19:	Accepted	[0.611s,	4.27 MB]	(2/2)
// Test case #20:	Accepted	[0.623s,	4.32 MB]	(2/2)
// Test case #21:	Accepted	[0.674s,	4.25 MB]	(2/2)
// Test case #22:	Accepted	[0.718s,	4.27 MB]	(2/2)
// Test case #23:	Accepted	[0.641s,	4.19 MB]	(2/2)
// Test case #24:	Accepted	[0.655s,	4.31 MB]	(2/2)
// Test case #25:	Accepted	[0.758s,	4.27 MB]	(2/2)
// Test case #26:	Accepted	[0.621s,	4.29 MB]	(2/2)
// Test case #27:	Accepted	[0.685s,	4.27 MB]	(2/2)
// Test case #28:	Accepted	[0.674s,	4.28 MB]	(2/2)
// Test case #29:	Accepted	[0.597s,	4.24 MB]	(2/2)
// Test case #30:	Accepted	[0.849s,	4.21 MB]	(2/2)
// Test case #31:	Accepted	[0.804s,	4.24 MB]	(2/2)
// Test case #32:	Accepted	[0.702s,	4.20 MB]	(2/2)
// Test case #33:	Accepted	[0.689s,	4.21 MB]	(2/2)
// Test case #34:	Accepted	[0.687s,	4.29 MB]	(2/2)
// Test case #35:	Accepted	[0.712s,	4.28 MB]	(2/2)
// Test case #36:	Accepted	[0.660s,	4.28 MB]	(2/2)
// Test case #37:	Accepted	[0.740s,	4.24 MB]	(2/2)
// Test case #38:	Accepted	[0.630s,	4.34 MB]	(2/2)
// Test case #39:	Accepted	[0.670s,	4.21 MB]	(2/2)
// Test case #40:	Accepted	[0.660s,	4.27 MB]	(2/2)
// Test case #41:	Accepted	[0.993s,	4.24 MB]	(2/2)
// Test case #42:	Accepted	[0.995s,	4.22 MB]	(2/2)
// Test case #43:	Accepted	[0.929s,	4.34 MB]	(2/2)
// Test case #44:	Accepted	[0.619s,	4.27 MB]	(2/2)
// Test case #45:	Accepted	[0.737s,	4.23 MB]	(2/2)
// Test case #46:	Accepted	[0.833s,	4.31 MB]	(2/2)
// Test case #47:	Accepted	[0.854s,	4.32 MB]	(2/2)
// Test case #48:	Accepted	[0.810s,	4.37 MB]	(2/2)
// Test case #49:	Accepted	[0.806s,	4.27 MB]	(2/2)
// Test case #50:	Accepted	[0.782s,	4.25 MB]	(2/2)


// Resources: 0.995s, 4.37 MB
// Final score: 100/100 (0.620/0.620 points)
