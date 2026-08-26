#include <bits/stdc++.h>                                                                                                                                                                                                                                                                                                                                                                                          // https://oj.vnoi.info/problem/interactive_findn
using namespace std;

size_t largest_exponent_under_mil(size_t base) {
  size_t res = base;

  while (true) {
    size_t next = res * res;
    if (next > 1'000'000)
      break;
    res = next;
  }
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

  size_t stuff = 1, some = 1, idx = 0;
  for (size_t i = 2; i <= 1'000'000; i++) {
    if (!primes[i])
      continue;

    size_t exp = largest_exponent_under_mil(i);
    size_t next = some * exp;
    if (((next >> 63) == 1) || next < some || next >= 1'000'000'000'000'000'000ULL) {
      cout << "ucln " << some << endl;
      some = 1;
      cin >> idx;
      stuff *= idx;
    }
    else {
      some = next;
    }
  }

  cout << "traloi " << stuff << endl;
  return 0;
}
