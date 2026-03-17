#include <bits/stdc++.h>
using namespace std;
bool SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  if (prime[n] == true) {
    return true;
  }
  return false;
}
int factors(int n) {
  int result;
  for (int i = 2; i <= n; i++) {
    if (n % i == 0) {
      result = i;
      break;
    }
  }
  return result;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if (SieveOfEratosthenes(n) && n != 2) {
      n += n;
      k--;
    }
    if (n & 1) {
      int result = factors(n);
      n += result;
      k--;
    }
    n = n + k * 2;
    cout << n << endl;
  }
}
