#include <iostream>                                                                                                                                                                                                                                                                                       // https://oj.vnoi.info/problem/interactive_guessarray
#include <vector>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;

  long long rounds = 16, l = 1, r = n;
  while (rounds--) {
    string res;
    long long id = (l + r) >> 1;

    cout << id << endl;
    cin >> res;

    if (res == "HOLA")
      return 0;

    if (res == "BIGGER")
      l = id + 1;
    else
      r = id - 1;
  }
}


/// RESULTS
// Execution Results

// Test case #1:	Accepted	[0.022s,	2.24 MB]	(1/1)
// Judge feedback
// Number of used guesses: 14
// Test case #2:	Accepted	[0.019s,	2.21 MB]	(1/1)
// Judge feedback
// Number of used guesses: 11
// Test case #3:	Accepted	[0.013s,	2.27 MB]	(1/1)
// Judge feedback
// Number of used guesses: 14
// Test case #4:	Accepted	[0.030s,	2.23 MB]	(1/1)
// Test case #5:	Accepted	[0.010s,	2.29 MB]	(1/1)
// Test case #6:	Accepted	[0.014s,	2.23 MB]	(1/1)
// Test case #7:	Accepted	[0.022s,	2.24 MB]	(1/1)
// Test case #8:	Accepted	[0.026s,	2.29 MB]	(1/1)
// Test case #9:	Accepted	[0.022s,	2.24 MB]	(1/1)
// Test case #10:	Accepted	[0.020s,	2.23 MB]	(1/1)


// Resources: 0.030s, 2.29 MB
// Final score: 10/10 (0.480/0.480 points)
